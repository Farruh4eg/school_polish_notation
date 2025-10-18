#ifndef STACK_H
#define STACK_H

typedef struct Node {
  double value;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *top;
  int size;
} Stack;

void init_stack(Stack *stack);
void push(Stack *stack, double value);
double pop(Stack *stack);
double peek(Stack *stack);

#endif // STACK_
