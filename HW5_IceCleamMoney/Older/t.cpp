#include <iostream>
#include <iostream>
#include <queue>
#include "moneyBag.h"
#include <cstdlib> //size_t
#include <map>
using namespace std;
#include <ctime> //for the time()



int randRange (int low, int high)
{
    return rand() % (high - low) + low;
}

int main()
{
    srand(time(NULL));
    for(int i=1;i<=5;++i)
    {
        cout<<rand() % 20+ 1<<endl ;
        
    }

}