// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions.
//   - (You may consider using these printf statements to debug,
//     but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node
{
	int data;
	struct node *next;
	struct node *previous;
} node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL
{
	int count;	  // count keeps track of how many items are in the DLL.
	node_t *head; // head points to the first node in our DLL.
	node_t *tail; // tail points to the last node in our DLL.
} dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
dll_t *create_dll()
{
	// Modify the body of this function as needed.

	// TODO: Implement me!!
	dll_t *myDLL = malloc(sizeof(dll_t));
	if (myDLL == NULL)
	{
		return NULL;
	}
	myDLL->count = 0;
	myDLL->head = NULL;
	myDLL->tail = NULL;
	return myDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns -1 if the dll is NULL.
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
int dll_empty(dll_t *t)
{
	// TODO: Implement me!!
	if (t == NULL)
	{
		return -1;
	}
	if (t->count == 0)
	{
		return 1;
	}
	return 0;
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t *t, int item)
{

	// TODO: Implement me!!
	if (t == NULL)
	{
		return -1;
	}
	node_t *new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
	{
		return -1;
	}
	new_node->data = item;
	new_node->previous = NULL;
	new_node->next = t->head;
	if (t->head != NULL)
	{
		t->head->previous = new_node;
	}
	t->head = new_node;
	if (t->tail == NULL)
	{
		t->tail = new_node;
	}
	t->count++;
	return 0;
}

// push a new item to the end of the DLL (after the last node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t *t, int item)
{

	// TODO: Implement me!!
	if (t == NULL)
	{
		return -1;
	}
	node_t *new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
	{
		return -1;
	}
	new_node->data = item;
	new_node->next = NULL;
	new_node->previous = t->tail;
	if (t->tail != NULL)
	{
		t->tail->next = new_node;
	}
	t->tail = new_node;
	if (t->head == NULL)
	{
		t->head = new_node;
	}
	t->count++;
	return 0;
}
// Returns the first item in the DLL and also removes it from the list.
// Returns -1 if the DLL is NULL.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_front(dll_t *t)
{
	// TODO: Implement me!!
	if (t == NULL || t->head == NULL)
	{
		return -1;
	}
	node_t *node = t->head;
	int value = node->data;
	t->head = node->next;
	if (t->head != NULL)
	{
		t->head->previous = NULL;
	}
	else
	{
		t->tail = NULL;
	}
	free(node);
	t->count--;
	return value;
	// Note: This line is a 'filler' so the code compiles.
}

// Returns the last item in the DLL, and also removes it from the list.
// Returns a -1 if the DLL is NULL.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_back(dll_t *t)
{
	// TODO: Implement me!!
	if (t == NULL || t->tail == NULL)
	{
		return -1;
	}
	node_t *node = t->tail;
	int value = node->data;
	t->tail = node->previous;
	if (t->tail != NULL)
	{
		t->tail->next = NULL;
	}
	else
	{
		t->head = NULL;
	}
	free(node);
	t->count--;
	return value;
	// Note: This line is a 'filler' so the code compiles.
}

// Inserts a new node before the node at the specified position.
// Returns -1 if the list is NULL
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
int dll_insert(dll_t *t, int pos, int item)
{
	if (t == NULL || pos < 0 || pos > t->count)
	{
		return -1;
	}

	if (pos == 0)
	{
		return dll_push_front(t, item);
	}

	if (pos == t->count)
	{
		return dll_push_back(t, item);
	}

	node_t *current = t->head;

	for (int i = 0; i < pos - 1; i++)
	{
		current = current->next;
	}

	node_t *node = malloc(sizeof(node_t));
	if (node == NULL)
	{
		return -1;
	}

	node->data = item;
	node->next = current->next;
	node->previous = current;
	current->next->previous = node;
	current->next = node;

	t->count++;
	return 0;
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
//  (does not remove the item)
// Returns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Assume no negative numbers in the list or the number zero.
int dll_get(dll_t *t, int pos)
{
	// TODO: Implement me!!

    if (t == NULL)
    {
        return -1;
    }

    // Check if the position is out of bounds
    if (pos < 0 || pos >= t->count)
    {
        return -1;
    }

    // Traverse the DLL to find the node at the specified position
    node_t *curr = t->head;
    for (int i = 0; i < pos; i++)
    {
        curr = curr->next;
    }

    // Return the value of the node at the specified position
    return curr->data;
}

	// Removes the item at position pos starting at 0 ( 0 being the first item )
	// Returns -1 if the list is NULL
	// Returns 0 on failure:
	//  * we tried to remove at a negative location.
	//  * we tried to remove get past the size of the list
	// Assume no negative numbers in the list or the number zero.
	int dll_remove(dll_t * t, int pos)
{
    // Check if the DLL is NULL
    if (t == NULL)
    {
        return -1;
    }

    // Check if the position is out of bounds
    if (pos < 0 || pos >= t->count)
    {
        return -1;
    }

    // Special case for removing the head node
    if (pos == 0)
    {
        node_t *node = t->head;
        t->head = node->next;
        if (t->head == NULL)
        {
            t->tail = NULL;
        }
        else
        {
            t->head->previous = NULL;
        }
        int value = node->data;
        free(node);
        t->count--;
        return value;
    }

    // Traverse the DLL to find the node at the specified position
    node_t *curr = t->head;
    for (int i = 0; i < pos; i++)
    {
        curr = curr->next;
    }

    // Remove the node
    curr->previous->next = curr->next;
    if (curr->next == NULL)
    {
        t->tail = curr->previous;
    }
    else
    {
        curr->next->previous = curr->previous;
    }
    int value = curr->data;
    free(curr);
    t->count--;
    return value;
}

	// DLL Size
	// Returns -1 if the DLL is NULL.
	// Queries the current size of a DLL
	int dll_size(dll_t * t)
	{
		// TODO: Implement me!!
		if (t == NULL)
		{
			return -1;
		}

		return t->count;
	}

	// Free DLL
	// Removes a DLL and all of its elements from memory.
	// This should be called before the proram terminates.
	void free_dll(dll_t * t)
	{
		// TODO: Implement me!!

		// Traverse the DLL and free each node
		node_t *curr = t->head;
		while (curr != NULL)
		{
			node_t *next = curr->next;
			free(curr);
			curr = next;
		}

		// Free the DLL itself
		free(t);
	}

#endif
