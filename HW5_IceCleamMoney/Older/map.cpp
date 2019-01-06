#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    pair<int, int> x;
    map<int, int> m;
    
    x.first = 1; //money that the customer gives
    x.second = 3;//index in line
    m.insert(x);
    
    map<int,int>::iterator it = m.begin();
//    for (it = m.begin();it!=m.end();++it){
//        cout<<(*it).first;
//     }
    it=m.find(4);
    cout<<it->second; //3
    return 0;
}