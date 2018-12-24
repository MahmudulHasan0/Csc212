//The node class for a doubly linked list typically looks something like this:
class dnode {
public: // TYPEDEF
    typedef double value_type;
    // CONSTRUCTOR
    dnode( const value_type& init_data = value_type(), dnode* init_next = NULL, dnode* init_previous = NULL )
    {
        data_field = init_data; 
        next = init_next; 
        previous = init_previous;
    }
    // Member functions to set the data and link fields:
    void set_data(const value_type& new_data) { data_field = new_data; }
    void set_next(dnode* new_next) { next = new_next; }
    void set_previous(dnode* new_previous) { previous = new_previous; }
    // Const member function to retrieve the current data:
    value_type data() const { return data_field; }
    // Two slightly different member functions to retrieve each current link:
    const dnode* next() const { return next; }
    dnode* next() { return next; }
    const dnode* previous() const { return previous; }
    dnode* previous() { return previous; }
private:
    value_type data_field;
    dnode *next;
    dnode *previous;
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
