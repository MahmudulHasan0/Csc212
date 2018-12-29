//works for
//N Queens on N-N board Algorithm
//Have to put all N queens in a NxN grid in a way that no two queens occupy the same column
//No two Queen can be diagonal from each other
//Bascially put Queens so that no queen can kill each other in chess

#include <iostream>
#include <stack>
#include <string>
using namespace std;

void print(stack<int> s, const int size)
{
    int check;
    while(!s.empty())
    {    
        check = s.top();
        s.pop();   
        
        for (int j = 1; j<=size; j++)
        {
            if (j == check)
                cout<<"Q";
            else
                cout<<".";
            cout<<" ";
        } 
        cout<<endl;
    }
}


int main()
{ 
    //Possible Positions: 1,2,3,4. Out Of Zones: 0 and 5
    stack <int> queenPos;  
    int x;
    cin >> x;
    const int QUEEN = x;    //QUEEN is the number of queens. Board is also QUEENxQUEEN  

    int N = QUEEN;          //Number of queens left to do in board
    int curr = 1;           //the column position of the current queen (will iterate through 1 to QUEEN)
    int prev = 1;           //the column position where the queen was just placed in the board

    //Setting column Array to avoid putting 2 queens in same column
    bool usedCol [QUEEN+2]; //QUEEN=5: 0, 1,2,3,4,5, 6. 0 and 6 are outofzone columns
    for (int i = 0; i<=QUEEN+2; i++)
        usedCol[i] = false;

    queenPos.push(curr);
    usedCol[curr] = true;
    prev = curr;
    curr = 1;
    N--;
    int counter = 0; //How many times did we increment the curr position? Did we finish the row?

    while(N>0)  //Already did one queen. 3 queens left. stop when N=0 because all quens are in board
    { 
    //DOING SOME BOARD WARPINGS:
        if (curr > QUEEN) //WARPING: if curr queen's position is QUEEN+1, bring back the pos to 1 
            curr = 1; 
        if (curr == 0)   //WARPING: if the curr pos is in the 0 zone, bring it to 1.
            curr = 1; 

    //IF current POS VIOLATE RULES, SHIFT IT BY 1
        if (usedCol[curr] || prev==curr || prev==curr+1 || prev==curr-1) 
        {
            curr++;
            counter++;
            //IF U CANT DO ANYTHING, SHIFT THE LAST QUEEN
            if (counter >= QUEEN)
            { //ex: [1,4,2,cantdo]
                int lastQueen = queenPos.top(); 
                queenPos.pop();             //[1,4]
                int secLastQueen = queenPos.top();
                N--;
                usedCol[lastQueen] = false; //resetting the column (popped)
                lastQueen++;                //moving up the 1nd queen to 2th position  
                usedCol[lastQueen] = true;  //pretendign as if this postion is filled for testing, will be false if it cant work
             //CAN I SHIFT THE LAST QUEEN WITHOUT ISSE?: (3)
             //(1) TEST TO SEE IF ITS NEAR ANY OTHER QUEENS OR IS IN THE SAME COLUMN OR IS IN THE FORBIDEN ZONE
                if (secLastQueen!=lastQueen && secLastQueen+1!=lastQueen && secLastQueen-1!=lastQueen && !usedCol[lastQueen] && lastQueen!=0 && lastQueen!=QUEEN+1)
                {   //ex: Original: [1,3, cant do] --> pop: [1] --> increment: 3-->4 
                    queenPos.push(lastQueen); //now stack is: [1,4] now can search for 3rd queen
                    N++;
                    prev = lastQueen;
                    curr = 1; //resettinG search 
                    counter = 0;
                }
             //(2) TEST EASY PASS: ONLY ONE QUEEN IS LEFT:  no need to test, just shift:
                else if (queenPos.size()==0) 
                {   //ex: Original: [2] --> pop: [] --> increment: 2-->3 
                    queenPos.push(lastQueen); //now stack is: [2] now cna search for 3rd queen
                    prev = lastQueen;
                    curr = 1; //resettinG search 
                    counter = 0;
                }
             //(3) CANT MOVE THE LAST QUEEN, POP THE QUEEN BEFORE THAT
                //do nothing because it will redo the loop  
                else
                {
                    usedCol[lastQueen] = false; //since i used this for test an didnt push anythign to this location, put this back to 0;   
                    lastQueen = queenPos.top();
                    queenPos.pop();
                    usedCol[lastQueen]=false;
                    N++;

                    lastQueen++;
                    queenPos.push(lastQueen);
                    usedCol[lastQueen] = true;
                    prev = lastQueen;
                    curr = 1; //resettinG search 
                    N--;
                    counter = 0;
                }   
                    //break; 
            } 
            cout<<"-------------------------------------------------------------"<<N<<endl;      
        print(queenPos, QUEEN);
        }
     //IF NO VIOLATION, SET THE curr QUEEN ON THE BOARD
        else
        {
            queenPos.push(curr);
            usedCol[curr] = true;
            prev = curr;
            curr = 1; //RESETTING CURR POSITION SO WE CAN START FROM THE START OF THE NEW ROW.
            N--;
            counter = 0;
        }  
        cout<<"-------------------------------------------------------------"<<N<<endl;      
        print(queenPos, QUEEN);
    }
   // print(queenPos, QUEEN);
    return 0;
}




