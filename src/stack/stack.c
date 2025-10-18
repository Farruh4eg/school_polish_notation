#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void init_stack(Stack *stack) {
  stack->top = NULL;
  stack->size = 0;
}

void push(Stack *stack, double value) {
  int success = 1;
  Node *new_node = malloc(sizeof(Node));

  if (new_node == NULL) {
    printf("Couldn't malloc a stack node\n");
    success = 0;
  }

  if (success) {
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
  }
}

double pop(Stack *stack) {
  double value;
  if (stack->top == NULL) {
    // TODO: handle the error properly
    printf("Stack has no elements\n");
    value = 0.0;
  } else {
    value = stack->top->value;

    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
  }

  return value;
}

double peek(Stack *stack) {
  double value;
  if (stack->top == NULL) {
    printf("Stack has no elements\n");
    value = 0.0;
  } else {
    value = stack->top->value;
  }

  return value;
}
