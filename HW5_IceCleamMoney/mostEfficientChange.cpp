//This is not part of ice cream problem, but kinda like it:
#include <iostream>
using namespace std;

int main(){
    double money;
    int y;
    cout<<"Enter a money quantity "<<endl;
    cin>>money;
    y = money*100; //turns money from $10.65 to $1065 whole number



    int quarters = y/25; // 1065/25 = 42.6. So 42 quarters
    y = y%25;            // remainder of 1056/25: 15/25. So its y=15 
    
    int dimes = y/10;    // 15/10 = 1.5. So 1 dime
    y = y%10;            // remainder of 15/10: 5/10. So y=5

    int nickels = y/5;  // 5/5 = 1. So 1 nickel
    y = y%5;            // remainder of 5/5: 0/5. So y=0

    int pennies = y/1;  //0/1=0. so 0 pennies



    cout<<"Will need: "<< quarters << " quarters,"<<endl;
    cout<<"Will need: "<< dimes << " dimes,"<<endl;
    cout<<"Will need: "<< nickels << " nickels,"<<endl;
    cout<<"Will need: "<< pennies << " pennies,"<<endl;

}