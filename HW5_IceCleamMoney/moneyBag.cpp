#include "moneyBag.h"
#include <iostream>
using namespace std;

moneyBag::moneyBag()
{
    oneDollar_Count = 0;
    fiveDollar_Count = 0;
    tenDollar_Count = 0;
    twentyDollar_Count = 0;
    revenue = 0;
}
void moneyBag::putInBag(int clientMoney)
{
    int many20 = 0;   //how many 20s does the client have? will put this many into Xaviers bag
    int many10 = 0;   //how many 10s does the client have? will put this many into Xaviers bag
    int many5 = 0;    //how many 5s does the client have? will put this many into Xaviers bag
    while(clientMoney-20>=0){
        ++many20;
        clientMoney = clientMoney-20; 
        //cout<<"clientNow: $"<<clientMoney<<"     20: "<<many20<<endl;
    }        
    putInTwenty(many20);

    while(clientMoney-10>=0){
        ++many10;
        clientMoney = clientMoney-10; 
        //cout<<"clientNow: $"<<clientMoney<<"     10: "<<many10<<endl;
    }        
    putInTen(many10);

    while(clientMoney-5>=0){
        ++many5;
        clientMoney = clientMoney-5; 
        //cout<<"clientNow: $"<<clientMoney<<"     5: "<<many5<<endl;
    }        
    putInFive(many5);
    putInOne(clientMoney);//rest of the money is put into oneDollar_Count place 
}
void moneyBag::takeOutBag(int change)
{
    int many20 = 0;   //how many 20s does the client have? will take this out of Xaviers bag
    int many10 = 0;   //how many 10s does the client have? will take this out of Xaviers bag
    int many5 = 0;    //how many 5s does the client have? will take this out of Xaviers bag
    if (change == 0)
        return;
    while(change-20>=0){
        ++many20;
        change = change-20; 
    }
    takeOutTwenty(many20);
    while(change-10>=0){
        ++many10;
        change = change-10; 
    }
    takeOutTen(many10);
    while(change-5 >= 0){
        ++many5;
        change = change-5; 
    }
    takeOutFive(many5);
    takeOutOne(change); 
}
void moneyBag::printEach(){
    cout<<"\nOnes:    "<<oneDollar_Count  <<"     Money: $"<<oneDollar_Count<<endl;
    cout<<"Five:    "<<fiveDollar_Count<<"     Money: $"<<5*fiveDollar_Count<<endl;
    cout<<"Ten:     "<<tenDollar_Count <<"     Money: $"<<10*tenDollar_Count<<endl;
    cout<<"Twenty:  "<<twentyDollar_Count <<"     Money: $"<<20*twentyDollar_Count<<endl;
    cout<<"Xavier's Revenue = $"<<total()<<endl;
}


