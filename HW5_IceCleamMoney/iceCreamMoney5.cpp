/*Mahmudul Hasan
Queue Applications: Scheduling/Resource allocatioN
Check if Xavier can give change to every person in the queue

Customers are standing in a queue waiting to buy an ice-cream from Xavier which costs 2. 
The possible currencies are $1, $5, $10, and $20. 
Initially, Xavier has no money. 
Check if Xavier will be able to provide change to every person waiting to buy an ice-cream.

queue of customers, each buying one $2 ice cream
queue stores how much the customer pays
print out:
    - the index of the customer Xavier can't refund and Xavier's revenue
    - "Every customer refunded" + Xavier's revenue, did he make and money
Modification: also let customers buy more than one ice cream, Xavier has 100 in stock
    - the index of the customer Xavier is sold out at
    - how many Xavier has left after there are no more customers
Modification two: average
    - ice creames sold
    - revenue
*/

#include <iostream>
#include <iostream>
#include <queue>
#include "moneyBag.h"
#include <cstdlib> //size_t
#include <map>     //map and pair
using namespace std;

int main(){
    //SETTING UP SOME STUFF
    moneyBag Xavier;           //Xaviers money bag
    queue<int> clientMoney;    //Clients in the line
    queue<int> notPaid;        //Clients that i had to temporaraly reject since i couldnt pay them the change
    pair<int, int> person;     //I needed a way to keep track of a person's position in the line. Used how much they paid as they key and their position in the line as the value
    map<int, int> waitlist;    //This is a list of the rejected customer (will accept them onc ei have enough money depending on the order they entered this list.)
    map<int,int>::iterator it; //will use this to search through the waitlist to find the key (not really needed since im using the notPaid queue for the key.)
    int lineLength;            //Number of people on line. User Input. 1st person has the index of 1
    int stock = 100;           //stock of 100 icecreams
    cout<<"XAVIER HAS A STOCK OF 100 ICECREAMS. EACH PERSON CAN ONLY BUY ONE ICECREAM\nHow many customers are on the line?\n";
    cin>>lineLength;

    //GIVING XAVIER SOME FIRST CUSTOMERS SO HER CAN PAY FOR STUFF 
    clientMoney.push(2); //the first customer so that Xavier some money to play with. With this, Xavier has a hard time selling
    //MAKING THE LIST OF CUSTOMERS:
    for(int i=1;i<lineLength;++i){
        clientMoney.push(rand() % 20+ 1); //random numbers $1 to $20
    }
    int size = clientMoney.size();

    //ALGORITHM FOR THE SHOP:
    for (int i=1;i<=size+1;++i)
    {
        //GET THE CHANGE. CAN YOU PAY THE GUY BACK IF HE BUYS AN ICECREAM?
        int change = clientMoney.front() - 2;
        //cout<<"i: "<<i<<"    money: $"<<clientMoney.front()<<"     Xavier: $"<<Xavier.total()<<"      change: $"<<change<<"   SIZE:"<<size<<endl;
        //CONDITIONS TO STOP LOOP IF I CANT GO FURTHER
        if (i==size+1){
            cout<<"REACHED END OF THE LINE. I HAVE "<<stock<<" MORE ICECREAMS LEFT :( I ALSO HAVE "<<notPaid.size()<<" PEOPLE WAITING TO BUY BUT I CAN'T PAY THEM CHANGE \n"<<endl;
            break;
        }
        else if (stock == 0){
            cout<<"GOT NO MORE ICE CREAM, NEED TO CLOSE DOWN FOR THE DAY!\n"<<endl;
            break;
        }
        //THERE WAS A GUY I COULDNT GIVE CHANGE TO, I PUSHED HIM TO THE SIDE, I CAN NOW HAVE ENOUGH MONEY TO PAY HIM HIS CHANGE. SO I ACCEPT HIM:
        else if (Xavier.total() >= notPaid.front()-2){
            Xavier.putInBag(notPaid.front());
            int change = clientMoney.front() - 2;
            Xavier.takeOutBag(change);
            it = waitlist.begin();
            it=waitlist.find(notPaid.front());
            cout<<"Paid Customer #"<<it->second<<"  Xavier's Revenue: $"<<Xavier.total()<<endl;
            notPaid.pop();
            stock--;
        }
        //I GOT ENOUGH MONEY TO GIVE CHANGE:
        else if (Xavier.total() >= change){
            Xavier.putInBag(clientMoney.front());
            Xavier.takeOutBag(change);
            stock--;
        }
        //I CANT GIVE THIS GUY CHANGE, PUSH HIM TO THE SIDE SO THAT I CAN PAY HIM HIS CHANGE WHEN I HAVE ENOUGH MONEY
        else{
            notPaid.push(clientMoney.front());  //pushing the money of the denied customer to front of queue. will use this as a key to the customer's index
            person.first = notPaid.front();     //money that the denied customer has
            person.second = i;                  //index in line of the denied person
            waitlist.insert(person);            //put the person in the waitlist map
            cout<<"Didnt pay customer #"<<i<<" He had: $"<<clientMoney.front()<<endl;
        }

        clientMoney.pop();
    }
    cout<<"ICECREAM SOLD: "<<100-stock;
    Xavier.printEach();
}


