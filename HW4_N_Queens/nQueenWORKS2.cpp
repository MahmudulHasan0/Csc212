//This is the version with the push_Queen and setup_usedCol and dynamic array 

//N Queens on N-N board Algorithm
//Have to put all N queens in a NxN grid in a way that no two queens occupy the same column
//No two Queen can be diagonal from each other
//Bascially put Queens so that no queen can kill each other in chess

#include <iostream>
#include <stack>
#include <string>
using namespace std;

void print(stack<int> s, const int QUEEN)
{
    while(!s.empty())
    {    
        int q = s.top(); 
        s.pop();   
        for (int j = 1; j<=QUEEN; ++j)
        {
            if (j == q)
                cout<<"Q";
            else
                cout<<".";
            cout<<" ";
        } 
        cout<<endl;
    }
}
void push_Queen(stack <int>& q, bool *&usedCol, int& N, int& prev, int& curr){
    q.push(curr);         //1) Push the queen
    N--;                  //2) Got one less queen to put n the board
    usedCol[curr] = true; //3) Mark the column where u placed the queen so that no other queen can be placed here
    prev = curr;          //4) Mark the position of the last queen, so that the next queen wouldnt be close to it.
    curr = 1;             //5) reset the next queens position to 1 so that we can go go through all the positions of the row. 
}
void setup_usedCol(bool *&usedCol, int const &QUEEN){
    for (int i = 0; i<=QUEEN+2; i++)
        usedCol[i] = false;
    usedCol[0]=true;       //Cant put queen in this column bec im considering this col as a "no zone"
    usedCol[QUEEN+1]=true; //Cant put queen in this column bec im considering this col as a "no zone"
}

int main()
{ 
    //A) SETUP - POSSIBLE POSITIONS ROW AND COLUMN: 1,2,3...QUEEN. Out Of Zones: 0 and QUEEN+1
    stack <int> queenPos;  
    int x;
    cin >> x;
    const int QUEEN = x;    //QUEEN is the number of queens. Board is also QUEENxQUEEN  
    int N = QUEEN;          //Number of queens left to do in board
    int curr = 1;           //the column position of the current queen (will iterate through 1 to QUEEN)
    int prev = 1;           //the column position where the queen was just placed in the board

    //B) SETTING COLUMN ARRAY TO AVOID PUTTING 2 QUEENS IN SAME COLUMN
    bool *usedCol = new bool[QUEEN+2]; //ex: QUEEN=5: 0,1,2,3,4,5,6. 0 and 6 are outofzone columns
    setup_usedCol(usedCol, QUEEN);
    
    //C) PUT THE FIRST QUEEN IN THE FIRST COLUMN OF THE FIRST ROW
    push_Queen(queenPos, usedCol, N, prev, curr);

    //D) ALGORITHM TO PUT QUEENS IN THE RIGHT PLACE
    while(N>0)            //Already did one queen. N queens left. stop when N=0 because all queens are in board
    { 
        //DOING SOME BOARD WARPINGS:
        if (curr > QUEEN) //WARPING: if curr queen's position is QUEEN+1, bring back the pos to 1 
            curr = 1; 
        if (curr == 0)    //WARPING: if the curr pos is in the 0 zone, bring it to 1.
            curr = 1; 
        //E) IF THE CURRENT POS VIOLATE RULES, SHIFT IT BY 1
        if (usedCol[curr] || prev==curr || prev==curr+1 || prev==curr-1) 
        {
            curr++;
            //A*) REACHED THE END OF THE ROAD. IF U CANT DO ANYTHING, POP THE LAST QUEEN AND SHIFT IT AND REDO 
            if (curr > QUEEN) 
            { 
                bool needToMove = true; 
                while (needToMove == true)
                {
                    //A*) RECORD THEN POP AND INCREMENT LAST QUEEN 
                    int poppedQueen = queenPos.top(); //1) Record last queen then pop it
                    queenPos.pop();                
                    N++;                              //2) Got one more queen to do sinc eu popped
                    usedCol[poppedQueen] = false;     //3) resetting the column (popped)
                    poppedQueen++;                    //4) Moving up the last queen to next position
                    //B*) DOESNT VIOLATE RULES, PUT THE QUEEN ON BOARD AND SEARCH FOR NEXT QUEEN
                    if (!usedCol[poppedQueen] && (poppedQueen!=0) && (poppedQueen!=QUEEN+1) && (queenPos.top()!=poppedQueen) && queenPos.top()!=poppedQueen+1 && queenPos.top()!=poppedQueen-1 )
                    {  
                        //5) now push the new position:
                        curr = poppedQueen;     //to use the the function:
                        push_Queen(queenPos, usedCol, N, prev, curr);
                        needToMove = false;
                    }
                }
            } 
        }
        //F) IF NO VIOLATION, PUT THE QUEEN ON THE BOARD
        else
        {
            push_Queen(queenPos, usedCol, N, prev, curr);
        }  
    }
    print(queenPos, QUEEN);
    return 0;
}




