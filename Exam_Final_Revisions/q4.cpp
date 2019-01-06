/*
Harold is a kidnapper who wrote a ransom note, but now he is worried it will be traced back to him through his handwriting. 
He found a magazine and wants to know if he can cut out whole words from it and use them to create an untraceable replica of his ransom note. 
The words in his note are case-sensitive and he must use only whole words available in the magazine. 
He cannot use substrings or concatenation to create the words he needs.
Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his ransom note exactly using whole words from the magazine; otherwise, print No.
Note: The input can be treated as a list of already seperated/parsed words.
*/
#include <iostream>
#include <string>
using namespace std;

void checkMagazine(string magazine[], string note[]){
    const int i = 30000;
    int m,n;
    magazine[i];
    note[i];
    cin>>m;
    cin>>n;
    char hash[@*i]; //hash table (open address implementation)

    //put all the chars in the magazine array in the hash table
    for (int j =0; j<= m-1){
        
        int hash = toHash(magazine[i]) //getting hash code. toHash() will do some computation to the character and get a hash code
        int index = toIndex(hash); //will do some computation to the hash code of this charto find where it will store the key
        hash[index] = magazine[i];

    }
    //loop thru the note array and try to put each character in the array into the hash table.
    //if there is a collision, see if the keys matches, if the keys dont match go to the next index until you find the same char.
    //if you cant find the same char and u end up comming back to the same index value, that means the letter isnt in the hash array
    //return no bec the note char isnt in the magazine

}