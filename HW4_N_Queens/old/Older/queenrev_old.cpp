/*
    N Queens on N-N board Algorithm
    Have to put all N queens in a NxN grid in a way that no two queens occupy the same column
    No two Queen can be diagonal from each other
    Bascially put Queens so that no queen can kill each other in chess

 STEP:
 //r1: start first row in 1...pushed
    prev = 1
    next = 1


 //r2
    CHECK VIOLATIONS: (stackNmae, bool usedCol [], prevPos, next){
        next to 1 - violation go next (same row)
        next to 2 - violation go next (diagonal)
        next to 3 - ok........pushed
    PUSHED: r2
        prev = r2_pos
        next = 1
 //r3:
    CHECK VIOLATIONS:
        next to 1 - violation(same row as r1)
        next to 2 - violation go next (diagonal of r2)
        next to 3 - violation go next (same row of r2)
        next to 4 - violation go next (diagonal of r2)
    need to pop r2.
 //back to r2:
    POPPED: r2
        prev = r1_pos
        next = r2_pos


*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;


void pushIt(stack<int>& s, int &N, bool*& usedCol, int &prevPos, int &nextPos){
    //pushIt(queenPos, N, usedCol, prevPos, nextPos);
    s.push(nextPos);
    usedCol[nextPos] = true;
    prevPos = nextPos;
    nextPos = 1;
    N--;
}
void popIt(stack<int>& s, int &N, bool*& usedCol, int &prevPos, int &nextPos){
    //popIt(queenPos, N, usedCol, prevPos, nextPos);
    int lastQueen = s.top();  //[1,4] lastQuen = 4
    s.pop();           //[1]
    usedCol[lastQueen] = false; //resetting the column (popped) 
    N++;
    int secLastQueen = s.top(); //secLastQuen = 1
    
}
// int findNextPos(stack<int> s, int gridSize, bool* usedCol, int testPos)
    // {
    //     const int prevPos = s.top();
    //     for (&testPos; testPos<=gridSize; testPos++)
    //     {
    //         if (testPos!=prevPos && testPos!=prevPos  && testPos!=prevPos-1 && !usedCol[testPos])
    //             return testPos;
    //         else
    //             return 0;
    //     }
// }
void findNextPos_PushPop(stack<int>& s, const int& QUEEN, int &N, bool*& usedCol, int &prevPos, int &testPos) 
{
    int counter = 0;
    for (&testPos; testPos<=QUEEN; testPos++)
    {
        if (testPos!=prevPos && testPos!=prevPos  && testPos!=prevPos-1 && !usedCol[testPos])
        {
            cout<<"\nRow: "<<s.size()+1<<" Col: "<<testPos<<" found position, pushing it";
            pushIt(s, N, usedCol, prevPos, testPos);           cout<< "     TEST: "<<(testPos!=prevPos) <<"  "<< (testPos!=prevPos) <<"  "<<(testPos!=prevPos-1) <<"  "<<(!usedCol[testPos]);
            cout<<"..................."<<testPos;
        }
        else
            cout<<"\nRow: "<<s.size()+1<<" Col: "<<testPos<<" no good pos found, going to next col: "<<testPos+1;
            //popIt(s, N, usedCol, prevPos, testPos);

    }
}
void print(stack<int> s, const int size)
{
    cout<<endl;
    int arr [size];
    int i = size;
    while(!s.empty())
    {    
        arr[i] = s.top();
        s.pop();   
        
        for (int j = 1; j<=size; j++)
        {
            if (j==arr[i])
                cout<<"x";
            else
                cout<<".";
            cout<<" ";
        }cout<<"                     ..."<<arr[i]<<endl; 
        cout<<endl;
    }
}




int main()
{ 
    //Possible Positions: 1,2,3,4. Out Of Zones: 0 and 5
    stack <int> queenPos;  
    const int QUEEN = 4;    //QUEEN is the number of queens. Board is also QUEENxQUEEN  
    int N = QUEEN;          //Number of queens left to do in board
    int nextPos = 1;
    int prevPos = 1; 
    

    //Setting column Array to avoid putting 2 queens in same column
    bool *usedCol;               //using an dynamic array because passing an static array by reference is a headache
    usedCol = new bool(QUEEN+6); 
    for (int i = 0; i<=QUEEN+1; i++)
        usedCol[i] = false;

    pushIt(queenPos, N, usedCol, prevPos, nextPos);

    cout<<"\nN: "<<N<<"    pn: "<<prevPos<<"  "<<nextPos<<"        tst: "<<(prevPos==nextPos)<<"   "<<(prevPos==nextPos+1)<<"   "<<(prevPos==nextPos-1)<<"   "<< (usedCol[nextPos])<<"       ";
    cout<<"        true: "<<(prevPos==nextPos || prevPos==nextPos+1 || prevPos==nextPos-1 || usedCol[prevPos])<<"       nextPos: "<<nextPos;
    cout<<"    UsedCol:";
    for (int i = 1; i<=QUEEN; i++)
        cout<<usedCol[i]<<" ";
    cout<<endl;
    while(N>=0)  //Already did one queen. 3 queens left. stop when N=0 because all quens are in board
    { 
        findNextPos_PushPop(queenPos, QUEEN, N, usedCol, prevPos, nextPos);

    }
    cout<<endl;
    print(queenPos, QUEEN);
    return 0;
}




