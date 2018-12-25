// FILE: dnode.cpp
// IMPLEMENTS: The functions  of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
// The data of a node is stored in data_field, and the link in link_field.
// src: //source: http://www.cs.colorado.edu/~main/chapter5/

#include "dnode.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;


size_t length(const dnode* head_ptr) //DONE
 // Library facilities used: cstdlib
    {
	const dnode *cursor;
	size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor->fore() != head_ptr ; cursor = cursor->fore())
	    ++answer;
	return answer;
    }
    
void head_insert(dnode*& head_ptr, const dnode::value_type& entry) //DONE but still need to check
    { 
		dnode *last = head_ptr->back();
		//dnode *newdnode = new dnode();
		//newdnode->set_data(entry);
		//newdnode->set_back(last);
		//newdnode->set_fore(last->fore());
		head_ptr= new dnode (entry,head_ptr,last);
		last->set_fore(head_ptr);
		(head_ptr->fore())->set_back(head_ptr);
		//head_ptr->set_back(newdnode)=
		//head_ptr = new dnode(entry, head_ptr,(*head_ptr)->back());
    }

void insert(dnode* previous_ptr, const dnode::value_type& entry) //DONE
    {
	dnode *insert_ptr;
	dnode *next_ptr = previous_ptr->fore();
	insert_ptr = new dnode(entry, previous_ptr->fore( ),next_ptr->back());
	previous_ptr->set_fore(insert_ptr);
	next_ptr->set_back(insert_ptr);
    }

dnode* search(dnode* head_ptr, const dnode::value_type& target) //DONE
 // Library facilities used: cstdlib
    {
	dnode *cursor;
	for (cursor = head_ptr; cursor->fore() != head_ptr; cursor = cursor->fore( ))
	    if (target == cursor->data( ))
		return cursor;
	return NULL;
    }

const dnode* search(const dnode* head_ptr, const dnode::value_type& target) //DONE
 	// Library facilities used: cstdlib
    {
		const dnode *cursor;
		for (cursor = head_ptr; cursor->fore() != NULL; cursor = cursor->fore( ))
			if (target == cursor->data( ))
			return cursor;
		return NULL;
    }

dnode* locate(dnode* head_ptr, size_t position) //DONE
    // Library facilities used: cassert, cstdlib
    {
		dnode *cursor;
		size_t i;
		assert (0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor->fore() != head_ptr); i++)
			cursor = cursor->fore( );
		return cursor;
    }

const dnode* locate(const dnode* head_ptr, size_t position) //DONE
    // Library facilities used: cassert, cstdlib
    {
	const dnode *cursor;
	size_t i;
	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor->fore() != head_ptr); i++)
	    cursor = cursor->fore( );
	return cursor;
    }

void list_head_remove(dnode*& head_ptr) //DONE
    {
	dnode *remove_ptr;
	delete head_ptr->back();
	//dnode *next_ptr = head_ptr->fore()
	remove_ptr = head_ptr;
	head_ptr = head_ptr->fore( );
	(head_ptr->fore())->set_fore(head_ptr);
	(head_ptr->back())->set_back(head_ptr->fore());
	delete remove_ptr;
    }

void list_remove(dnode* previous_ptr) //DONE
    {
	dnode *remove_ptr;
	remove_ptr = previous_ptr->fore( );
	previous_ptr->set_fore(remove_ptr->fore( ));
	(previous_ptr->fore())->set_back(previous_ptr);
	delete remove_ptr;
    }

void list_clear(dnode*& head_ptr) //Might be DONE // Library facilities used: cstdlib
    {
	while (head_ptr != NULL)	
	    list_head_remove(head_ptr);
    }

void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr) // THIS IS HARD // Library facilities used: cstdlib
{
	head_ptr = NULL;
	tail_ptr = NULL;

	// Handle the case of the empty list.
	if (source_ptr == NULL)
		return;
	// Make the head node for the newly created list, and put data in it.
	head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;

	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	const dnode* start_ptr = source_ptr;
	source_ptr = source_ptr->fore(); 
	while (source_ptr  != start_ptr)
	{
		insert(tail_ptr, source_ptr->data());
		tail_ptr = tail_ptr->fore();
		source_ptr = source_ptr->fore();
	}
}
// Make the head node for the newly created list, and put data in it.
bool has_cycled(dnode*& head_ptr){} //return true if there's a cycle
dnode* find_cycle(dnode*& head_ptr){}//return node in cycle

