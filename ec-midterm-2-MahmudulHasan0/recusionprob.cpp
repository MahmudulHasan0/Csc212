// Precondition: All parameters are non-negative integers.
// Postcondition: The method has determined whether it is possible to reach the goal in the
// following Teddy Bear game. In the game, your friend gives you a certain number of bears.
// The number of bears is called initial, and your goal is to end up with a particular number of
// bears, called the goal number. At any point in the game, you have two choices: (a) You can
// ask for (and receive) increment more bears, or (b) if you have an even number of bears,
// then you can give half of them back to your friend. Each time you do (a) or (b), that is called
// a step in the game.
// The return value is true if and only if the goal can be reached in n steps or fewer.
#include <iostream>
using namespace std;
bool bears(int initial, int goal, int increment, int n)    
{
    if (initial == goal)
        return true;
    else if (n == 0)
        return false;
    else if (bears(initial+increment, goal, increment, n-1))
        return true;
    else if ((initial % 2 == 0) && bears(initial/2, goal, increment, n-1))
        return true;
    else
        return false;
}
int main(){
    cout<<bears(4,39,3,7);
}