#ifndef __STACK_H__
#define __STACK_H__
#include "node.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    Node* top;
} Stack;

Stack *stack_create();
void stack_push(Stack*, Data);
Data stack_pop(Stack*);
bool stack_is_empty(Stack* );
void stack_delete(Stack *);
void stack_empty(Stack*);
void stack_print(Stack *);

#endif // __STACK_H__