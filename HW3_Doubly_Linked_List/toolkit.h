
//Implement the Doubly Linked List as a class with the following methods from the linked list toolkit:

std::size_t length( const node* head_ptr);
void head_insert(node*& head_ptr, const node::value_type& entry);
void insert(node* previous_ptr, const node::value_type& entry);
node* search(node* head_ptr, const node::value_type& target);
const node* search(const node* head_ptr, const node::value_type& target); node* locate(node* head_ptr, std::size_t position);
const node* locate(const node* head_ptr, std::size_t position);
void list_head_remove(node*& head_ptr);
void list_remove(node* previous_ptr);
void list_clear(node*& head_ptr);
void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);



//not in toolkit: implement these methods that are not in the toolkit:
value_type operator[](std::size_t position)//same as locate, return data at position
bool has_cycle(node*& head_ptr) //return true if there's a cycle
node* find_cycle(node*& head_ptr)//return node in cycle
//Find more information on finding cycles at: https://blog.ostermiller.org/find-loop-singly-linked-list