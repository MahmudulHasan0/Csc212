//The node class for a doubly linked list typically looks something like this:
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t

class dnode {
    public: 
        typedef double value_type;
        dnode( const value_type& init_data = value_type(), dnode* init_next = NULL, dnode* init_prev = NULL );
        // Member functions to set the data and link fields:
        void set_data(const value_type& new_data) { data_field = new_data; }
        void set_next(dnode* new_next) { next_link = new_next; }
        void set_prev(dnode* new_prev) { prev_link = new_prev; }
        // Const member function to retrieve the current data:
        value_type data() const { return data_field; }
        // Two slightly different member functions to retrieve each current link:
        const dnode* next() const { return next_link; }
        dnode* next() { return next_link; }
        const dnode* prev() const { return prev_link; }
        dnode* prev() { return prev_link; }

        std::size_t length( const dnode* head_ptr);
        void head_insert(dnode*& head_ptr, const dnode::value_type& entry);
        void insert(dnode* prev_ptr, const dnode::value_type& entry);
        dnode* search(dnode* head_ptr, const dnode::value_type& target);
        const dnode* search(const dnode* head_ptr, const dnode::value_type& target); dnode* locate(dnode* head_ptr, std::size_t position);
        const dnode* locate(const dnode* head_ptr, std::size_t position);
        void list_head_remove(dnode*& head_ptr);
        void list_remove(dnode* prev_ptr);
        void list_clear(dnode*& head_ptr);
        void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr);

        //not in toolkit: implement these methods that are not in the toolkit:
        value_type operator[](std::size_t position)//same as locate, return data at position
        bool has_cycle(dnode*& head_ptr) //return true if there's a cycle
        dnode* find_cycle(dnode*& head_ptr)//return dnode in cycle
        //Find more information on finding cycles at: https://blog.ostermiller.org/find-loop-singly-linked-list
    private:
        value_type data_field;
        dnode *next_link;
        dnode *prev_link;

};

//prev link points to the prev node. next pointer points to next node. 





/*
node1.setData()
node1.setNext(ptr to next node)
node1.setPrev(ptr to prev node)
node1.getData() - to get data to node1

node2.next() - return addr of next node (node 3)
node2.prev() - return addr of prev node (node 1)
*/
