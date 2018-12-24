
//Implement the Doubly Linked List as a class with the following methods from the linked list toolkit:

       std::size_t length( const dnode* head_ptr);
        void head_insert(dnode*& head_ptr, const dnode::value_type& entry);
        void insert(dnode* previous_ptr, const dnode::value_type& entry);
        dnode* search(dnode* head_ptr, const dnode::value_type& target);
        const dnode* search(const dnode* head_ptr, const dnode::value_type& target); dnode* locate(dnode* head_ptr, std::size_t position);
        const dnode* locate(const dnode* head_ptr, std::size_t position);
        void list_head_remove(dnode*& head_ptr);
        void list_remove(dnode* previous_ptr);
        void list_clear(dnode*& head_ptr);
        void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr);


//not in toolkit: implement these methods that are not in the toolkit:
value_type operator[](std::size_t position)//same as locate, return data at position
bool has_cycle(dnode*& head_ptr) //return true if there's a cycle
dnode* find_cycle(dnode*& head_ptr)//return dnode in cycle
//Find more information on finding cycles at: https://blog.ostermiller.org/find-loop-singly-linked-list