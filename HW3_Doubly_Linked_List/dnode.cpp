#include "dnode.h"
using namespace std;

dnode::dnode( const value_type& init_data = value_type(), dnode* init_next = NULL, dnode* init_prev = NULL )
{
    data_field = init_data; 
    next_link = init_next; 
    prev_link = init_prev;
}
size_t dnode::length( const dnode* head_ptr)
{
    const dnode *cursor;
    size_t answer = 0;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->next())
        ++answer;
    return answer;
}
void dnode::head_insert(dnode*& head_ptr, const dnode::value_type& entry)
{ 
    dnode *new_ptr;
    new_ptr = new dnode(entry, head_ptr, NULL); //making new node, back points to NULL (since its new head) and next points to current nex tnode
    head_ptr -> set_prev(new_ptr); //linking the old head to the new head
    head_ptr = new_ptr; //setting the head_ptr
}
void dnode::insert(dnode* prev_ptr, const dnode::value_type& entry)
{
    dnode *insert_ptr;
    insert_ptr = new dnode(entry, prev_ptr->next(), prev_ptr ); //new node linked to back and front nodes
    prev_ptr->next()->set_prev(insert_ptr); //linking front node to new node
    prev_ptr->set_next(insert_ptr);//linking back node to new node
}
dnode* dnode::search(dnode* head_ptr, const dnode::value_type& target)
{
	dnode *cursor;
	for (cursor = head_ptr; cursor->next() != head_ptr; cursor = cursor->next())
	    if (target == cursor->data())
		    return cursor;
	return NULL;
}
const dnode* dnode::search(const dnode* head_ptr, const dnode::value_type& target)
{
	const dnode *cursor;
	for (cursor = head_ptr; cursor->next() != head_ptr; cursor = cursor->next())
	    if (target == cursor->data())
		    return cursor;
	return NULL;
}
dnode* dnode::locate(dnode* head_ptr, std::size_t position)
{
		dnode *cursor;
		size_t i;
		assert (0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor->next() != head_ptr); i++)
			cursor = cursor->next();
		return cursor;
}
const dnode* dnode::locate(const dnode* head_ptr, std::size_t position)
{
		const dnode *cursor;
		size_t i;
		assert (0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor->next() != head_ptr); i++)
			cursor = cursor->next();
		return cursor;
}
void dnode::list_head_remove(dnode*& head_ptr){
    dnode *remove_ptr;
    remove_ptr = head_ptr; //mark the head node for deletion
    head_ptr = head_ptr->next(); //move the head_ptr to the new head node
    head_ptr->set_prev(NULL); //setting the new head prev link to NULL
    delete remove_ptr; //deleted the old head dnode
}

void dnode::list_remove(dnode* prev_ptr){
    dnode *remove_ptr;
    remove_ptr = prev_ptr->next(); //marking node for deletion
    remove_ptr->next()->set_prev(prev_ptr);//linking front node to back node
    prev_ptr->set_next( remove_ptr->next() );//linking back node to front node
    delete remove_ptr; //deleting the node
}
void dnode::list_clear(dnode*& head_ptr){
	while (head_ptr != NULL)	
	    list_head_remove(head_ptr);
}
void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr){//finish
	
}
