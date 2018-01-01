#include <stdlib.h>
#include "stack.h"

StatusCode stack_new(Stack** out) {
	Stack* stack = (Stack*) malloc(sizeof(Stack));
	if (!stack) {
		return FAILURE;
	}
	stack->physical_size = INITIAL_PHYSICAL_SIZE;
	stack->elements = (void**) malloc(stack->physical_size * sizeof(void*));
	stack->logical_size = 0;
	if (!stack->elements) {
		return FAILURE;
	}
	*out = stack;
	return SUCCESS;
}

StatusCode stack_push(Stack* stack, void* element) {
	if (stack->logical_size == stack->physical_size) {
		stack->physical_size *= 2;
		void** p = (void**) realloc(stack->elements, stack->physical_size * sizeof(void*));
		if (!p) {
			return FAILURE;
		}
		stack->elements = p;
	}
	stack->elements[stack->logical_size++] = element;
	return SUCCESS;
}

StatusCode stack_pop(Stack* stack, void** out) {
	if (stack->logical_size == 0) {
		return FAILURE;
	}
	*out = stack->elements[--stack->logical_size];
	if (stack->physical_size >= 4 * INITIAL_PHYSICAL_SIZE
		&& stack->logical_size <= stack->physical_size / 4) {
		stack->physical_size /= 2;
		void** p = (void**) realloc(stack->elements, stack->physical_size * sizeof(void*));
		if (!p) {
			return FAILURE;
		}
		stack->elements = p;
	}
	return SUCCESS;
}

StatusCode stack_peek(Stack* stack, void** out) {
	if (stack->logical_size == 0) {
		return -1;
	}
	*out = stack->elements[stack->logical_size - 1];
	return 1;
}

int stack_size(Stack* stack) {
	return stack->logical_size;
}

void stack_destroy(Stack* stack) {
	free(stack->elements);
  stack->elements = NULL;
	free(stack);
	stack = NULL;
}
