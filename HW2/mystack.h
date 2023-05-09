// =================== Support Code =================
// Stack
//
//
//
// - Implement each of the functions to create a working stack.
// - Do not change any of the function declarations
//   - (i.e. my_my_stack_t* create_stack() should not have additional arguments)
// - You should not have any 'printf' statements in your stack functions. 
//   - (You may consider using these printf statements to debug, 
//      but they should be removed from your final version)
// ==================================================
#ifndef MYSTACK_H
#define MYSTACK_H
#include <stdlib.h>
#include <stddef.h>



// Stores the maximum 'depth' of our stack.
// Our implementation enforces a maximum depth of our stack.
// (i.e. capacity cannot exceed MAX_DEPTH for any stack)
# define MAX_DEPTH 32

// Create a node data structure to store data within
// our stack. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* next;
}node_t;

// Create a stack data structure
// Our stack holds a single pointer to a node, which
// is a linked list of nodes.
typedef struct my_stack{
	int count;		// count keeps track of how many items
				// are in the stack.
	unsigned int capacity;	// Stores the maximum size of our stack
	node_t* head;		// head points to a node on the top of our stack.
}my_stack_t;

// Creates a stack
// Returns a pointer to a newly created stack.
// The stack should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The stacks fields should also be initialized to default values.
my_stack_t* create_stack(unsigned int capacity){
	// Modify the body of this function as needed.
	 my_stack_t* s = (my_stack_t*)malloc(sizeof(my_stack_t));
    if(s == NULL){
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(1);
    }

    // Initialize the fields of the stack
    s->count = 0;
    s->capacity = capacity;
    s->head = NULL;

    return s;
}

// Stack Empty
//cd "/Users/jiangchaoyi/Desktop/5008/Project/" && gcc mystack.c -o mystack && "/Users/jiangchaoyi/Desktop/5008/Project/"mystack
//cd "/Users/jiangchaoyi/Desktop/5008/Project/" && gcc mystack.c -o mystack && "/Users/jiangchaoyi/Desktop/5008/Project/"mystack
//Check if the stack is empty
// Returns 1 if true (The stack is completely empty)
// Returns 0 if false (the stack has at least one element enqueued)
int stack_empty(my_stack_t* s){
            return (s->count == 0);

}

// Stack Full
// Check if the stack is full
// Returns 1 if true (The Stack is completely full, i.e. equal to capacity)
// Returns 0 if false (the Stack has more space available to enqueue items)
int stack_full(my_stack_t* s){
	// Stacks in linked list do not have a fixed size, so it can never be full.
         return (s->count == s->capacity);

}

// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. if the Stack is full that is an error, but does not crash the program).
int stack_enqueue(my_stack_t* s, int item){
	if(stack_full(s)){
        return -1;
    }

    // Create a new node and set its data
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if(new_node == NULL){
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = item;

    // Add the new node to the top of the stack
    new_node->next = s->head;
    s->head = new_node;
    s->count++;

    return 0;
}

//int pop(struct Stack* stack) {
	//if (isStackEmpty(stack)) {
		//printf("Error: Stack is empty\n");
		//exit(1);
	//}
	//struct Node* node = stack->top;
	//int item = node->data;
	//stack->top = node->next;
	//stack->size--;
	//free(node);
	//return item;
//}

// Dequeue an item
// Returns the item at the front of the stack and
// removes an item from the stack.
// Removing from an empty stack should crash the program, call exit(1).
int stack_dequeue(my_stack_t* s){
	if(stack_empty(s)){
        fprintf(stderr, "Error: Cannot dequeue from an empty stack.\n");
        exit(1);
    }

    // Remove the top node and return its data
    node_t* temp = s->head;
    int item = temp->data;
    s->head = temp->next;
    s->count--;
    free(temp);

    return item; // Note: This line is a 'filler' so the code compiles.
}

// Stack Size
// Queries the current size of a stack
// A stack that has not been previously created will crash the program.
// (i.e. A NULL stack cannot return the size)
unsigned int stack_size(my_stack_t* s){
	    return s->count;

}

// Free stack
// Removes a stack and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_stack(my_stack_t* s){
	while(!stack_empty(s)){
        stack_dequeue(s);
    }

    // Free the stack
    free(s);
	
}

#endif
