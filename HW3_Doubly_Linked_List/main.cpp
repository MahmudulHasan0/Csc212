#include <iostream>
#include <cstdlib>
#include "dnode.h"
using namespace std;
int main(){
    dnode *head_ptr, *tail_ptr;
    dnode *p, *q, *r, *s;  
    p = new dnode(1.0, NULL, NULL);
    q = new dnode(2.0, NULL, p);
    p -> set_next(q);
    r = new dnode(3.0, NULL, q);
    q -> set_next(r);
    s = new dnode(4.0, NULL, r);
    r->set_next(s);
    head_ptr = p;
    tail_ptr = s;
    dnode *l = tail_ptr->prev();

    // cout<<p<<endl;
    // cout<<p->next()        <<endl;
    //  dnode* t = p->next();
    // cout<<t       <<endl;
    //cout<<p->next()->next()->next()->prev()->data()<<endl;

    // cout<<length(head_ptr)<<endl;
    // list_head_remove(head_ptr);
    // cout<<length(head_ptr)<<endl<<endl;

    cout<<length(head_ptr)<<endl;
    list_clear(head_ptr);
   // cout<<length(head_ptr)<<endl;
    
    //  cout<<"data of "<<p->next()<<endl; //member selection operator: (*p).data() is the same as p->data()
    // // cout<<"what p point to (link): "<< p->next()<<endl;

    // // //testing length of node function
    // // head_ptr = s; //changign this point changes how much stuff in the link
    // // cout<<"length of link: "<<length(head_ptr)<<endl;

    // //testing list_head_insert function
    // //node *entry = new node(67.9); no need to mkae a node :)
    // head_insert(head_ptr, 67.9);
    // cout<<"\nentry: "<<head_ptr->data()<<endl;
    // cout<<"s: "<<s<<"   head: "<<head_ptr->next()<<endl;
}