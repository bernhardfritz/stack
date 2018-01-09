#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
	Stack* stack;

	stack_new(&stack);
	int a = 0;
	int b = 1;
	int c = 2;
	stack_push(stack, &a);
	stack_push(stack, &b);
	stack_push(stack, &c);
	while (stack_size(stack)) {
		int* p;
		stack_pop(stack, (void*) &p);
		printf("%d\n", *p);
	}
	stack_destroy(stack);

	stack_new(&stack);
	char* foo = "foo";
	char* bar = "bar";
	char* baz = "baz";
	stack_push(stack, &foo);
	stack_push(stack, &bar);
	stack_push(stack, &baz);
	while (stack_size(stack)) {
		char** p;
		stack_pop(stack, (void*) &p);
		printf("%s\n", *p);
	}
	stack_destroy(stack);
	
	return EXIT_SUCCESS;
}
