//Precondition: a pointer to a node called 'head' points to a certian node in graph. each node has a key. can get the key via a memebr fucntion called key()

int detect_cycles (node* head){
    bool cycle; //sees if there is a 
    node hash[]; //hahs table
    //go into the head node and get the key of the node via: head->key()
    hash = toHash(head->key();) //getting hash code. toHash() will do some computation to the key and get a hash code
    index = toIndex(hash); //will do some computation to the hash code of this key to find where it will store the key
    if(nothing is in the index called index){
        hash[index] = head->key();
    }
    if(the index here is filled){
        node* temp = hash[index]; //making a pointer to the first ndoe in the linkedlist in thisindex
        //traverse through the linkedlist in this index and see if you can find the same key
        //if you cant find the same key, there isnt a loop, just add that new key to the linked lsit at this index. the cycle is false
        //if there is a node with this key in the linked list in this node, the cycle is true so return cycle and end fucntion
    }
    head -> link();//go to the next node in the graph 
}
