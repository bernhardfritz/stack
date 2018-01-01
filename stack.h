#ifndef STACK_H
#define STACK_H

#define INITIAL_PHYSICAL_SIZE 10

typedef struct {
	void** elements;
	int physical_size;
	int logical_size;
} Stack;

typedef enum {
	SUCCESS = 0,
	FAILURE = -1,
} StatusCode;

StatusCode stack_new(Stack**);
StatusCode stack_push(Stack*, void*);
StatusCode stack_pop(Stack*, void**);
StatusCode stack_peek(Stack*, void**);
int stack_size(Stack*);
void stack_destroy(Stack*);

#endif /* STACK_H */