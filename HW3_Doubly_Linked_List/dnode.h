//The node class for a doubly linked list typically looks something like this:
#ifndef MAIN_SAVITCH_DNODE_H  
#define MAIN_SAVITCH_DNODE_H
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t

class dnode {
    public: 
        typedef double value_type;
        dnode( const value_type& init_data = value_type(), dnode* init_next = NULL, dnode* init_previous = NULL )
        {
            data_field = init_data; 
            next_link = init_next; 
            prev_link = init_previous;
        }
        // Member functions to set the data and link fields:
        void set_data(const value_type& new_data) { data_field = new_data; }
        void set_next(dnode* new_next) { next_link = new_next; }
        void set_previous(dnode* new_previous) { prev_link = new_previous; }
        // Const member function to retrieve the current data:
        value_type data() const { return data_field; }
        // Two slightly different member functions to retrieve each current link:
        const dnode* next() const { return next_link; }
        dnode* next() { return next_link; }
        const dnode* previous() const { return prev_link; }
        dnode* previous() { return prev_link; }
    private:
        value_type data_field;
        dnode *next_link;
        dnode *prev_link;

};
#endif
//prev link points to the prev node. next pointer points to next node. 





/*
node1.setData()
node1.setNext(ptr to next node)
node1.setPrev(ptr to prev node)
node1.getData() - to get data to node1

node2.next() - return addr of next node (node 3)
node2.prev() - return addr of prev node (node 1)
*/
