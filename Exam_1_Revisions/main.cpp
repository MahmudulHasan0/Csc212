#include <iostream>
#include <cstdlib>
#include "node.h"

double percentile(node* head_ptr, const node::value_type& target)
{
    // if (head_ptr == NULL){
    //     throw std::runtime_error("wrong!");
    // }

    //find the size of list
    //find how many are below target = nbelow
    //nbelow/list  need the percentage
    node *cursor;
    cursor = head_ptr;
    int below = 0;
    int size = 0;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
    {
        size++;
        if (cursor->data() < target){
            below++;
        }
    }
    double answer = (double(below))/size * 100 ;
    return answer;


}
void shift(node* head_ptr, const node::value_type& target, int offset){

}
void shift_entry(node* head_ptr, const node::value_type& target, int offset)
{
   //plan: find first target, mark the prev and next nodes, 
    int size = list_length(head_ptr);
    //array will hold posiiton of target nodes
    node *targArray = new node[size-1]; 
    node *prev, *targ, *next, *cursor;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link()){
        //find the prev node's location:
        if (cursor->link()->data() == target)
            prev = cursor->link();
        //mark the target node's location:
        if (cursor->data() == target)
            targ = cursor;
        //mark the next node's location:
        

    }


    for (cursor = prev; cursor != NULL; cursor = cursor->link( )){//get the previous 
        if (target == cursor->link()->data())
        prev = cursor->link();

    }
    //make the previous node's link point to the node the next pointer points to
    //make target node point to the next node. if offset is greater than 2

   
   // return NULL;
}
int main(){
    //test list:
    // node *ix09(7, NULL);
    // node *ix08(6, ix09);
    // node *ix07(5, ix08);
    // node *ix06(4, ix07);
    // node *ix05(4, ix06);
    // node *ix04(3, ix05);
    // node *ix03(3, ix04);
    // node *ix02(2, ix03);
    // node *ix01(1, ix02);
    // node *ix00(0, ix01);
    // node *head_ptr = ix00;
 
    
    node *head_ptr;
    node *tail_ptr;
    node *a, *b, *c, *d, *e, *f;       
    f = new node(4, NULL);
    e = new node(2, f);
    d = new node(3, e);
    c = new node(3, d);
    b = new node(2, c);
    a = new node(1, b);
    
    
   
    
    
    tail_ptr = f;
    head_ptr = a;
    std::cout<<percentile(head_ptr, 3);


    /**write code to test what percentile computes:
     *  empty list case
     * 100th percentile
     * 0 th percentile
     * arbitrary input
    percentile(head_ptr, 4);
    **/
   /**write code to test that list is shifted:
    * positive shift
    * negative shift
    * roll over positive shift
    * roll over negative shift
    * non-duplicate elements
    * adjacent duplicate elements
    * non adjacent duplicate elements
    * list is empty
    * entry is not in list
    //shift_entry(head_ptr, 3, 2);
    **/
}

   