#include <stdio.h>
#include <stdlib.h>
#include "../includes/push_swap.h"

typedef struct s_stack
{
    int *array;
    int top;
    int size;
} t_stack;

t_stack *init_stack(int size);
void free_stack(t_stack *stack);

int main(void)
{
    int size = 5;
    t_stack *stack = init_stack(size);

    if (!stack)
    {
        printf("Failed to initialize stack\n");
        return 1;
    }

    printf("Stack initialized with size %d\n", size);

    // Test pushing elements onto the stack
    for (int i = 0; i < size; i++)
    {
        stack->array[++stack->top] = i;
        printf("Pushed %d onto the stack\n", i);
    }

    // Test popping elements from the stack
    while (stack->top >= 0)
    {
        printf("Popped %d from the stack\n", stack->array[stack->top--]);
    }

    free_stack(stack);
    return 0;
}