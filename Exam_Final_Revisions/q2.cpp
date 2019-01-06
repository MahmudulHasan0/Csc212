bool has_cycle(dnode*& head_ptr){ 
    if (head_ptr==NULL)
        return false;
    dnode *fast, *slow;
    fast = head_ptr->next(); //fast ptr starts on next node
    slow = head_ptr;//slow ptr starts one node behind
    while(fast!=NULL && slow!=NULL)
    {
        if (fast == slow) //they meet up, then there is a loop
            return true;
        fast = fast->next()->next();//fast increments by 2 nodes
        slow = slow->next(); //slow increments by one node
    }
    return false; //if i found no loops, return false
}

                                  