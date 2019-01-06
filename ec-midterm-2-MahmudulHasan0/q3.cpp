/*
GAME OF TWO STACKS
n = stack a
m= stack b
x
*/
//#include <stack>
//#include <queue>
#include <iostream>
#include <queue>
#include <string>
#include "stack1.h"
using namespace std;

int main(){
    stack<int> A;
    stack<int> B;
    queue<int> Aa;
    queue<int> Bb;

    int sum = 0;
    int count = 0;
    int g, n, m, x,z;
//My plan for for g=1: n,m,x will be arrays;
//for g=1:
    //get the first integer from line 2 and equal it to n;
    //get the second integer from line 2 and equal it to m;
    //get the third integer from line 2 and equal it to x;
    // cin>> g;
    // cin>> n;
    // cin>> m;
    // cin>> x;
    //get and then push each integer from the 3nd line to queue Aa and then use the front() function to push to stack A. then pop from Aa to save space;
    A.push(1);
    A.push(6);
    A.push(4);
    A.push(2);
    A.push(4);
    //get and then push each integer from the 4th line to queue Bb and then use the front() function to push to stack B then pop from Bb to save space;
    B.push(5);
    B.push(8);
    B.push(1);
    B.push(2);

    while(sum<x){
        cout<<"pick to take from 'a' or 'b'? ";
        char s;
        cin>>s;
        if (s='a'){
            //cout<<"a\n";
            sum = sum+A.top();
            A.pop();
            ++count;
        }
        else if (s='b'){
            //cout<<"b\n";
            sum = sum+B.top();
            B.pop();
            ++count;
        }
        if (sum>10){
             return;
        }
    }
    //cout<<"LegalMoves: "<<count<<"     Sum: "<<sum;  
    cout<<count<<endl;;
    if (sum>x){
       cout<<"\ndisqualified!";
    }





   
    
        
}