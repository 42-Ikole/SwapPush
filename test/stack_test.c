
#include "../includes/libps.h"
#include <stdio.h>

void print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("[%d]\n", stack->nb);
		stack = stack->prev;
	}
	printf("\n");
}

int main(void)
{
	t_stack *a = NULL;
	t_stack *b = NULL;

	a = stack_push(a, 1);
	a = stack_push(a, 14);
	a = stack_push(a, 89);
	print_stack(a);
	print_stack(a);
	stack_swap(a);
	printf("swapped top 2\n----------------------------\n");
	print_stack(a);
	stack_rotate(a);
	printf("rotated stack\n----------------------------\n");
	print_stack(a);
	stack_reverse_rotate(a);
	printf("rev rotate\n----------------------------\n");
	print_stack(a);
	stack_switch(&a, &b);
	printf("switcheroo stack a\n----------------------------\n");
	print_stack(a);
	printf("after switcheroo stack b\n----------------------------\n");
	print_stack(b);
	stack_switch(&a, &b);
	stack_switch(&a, &b);
	printf("switcheroo stack a\n----------------------------\n");
	print_stack(a);
	printf("after switcheroo stack b\n----------------------------\n");
	print_stack(b);
	stack_swap(a);
	stack_pop(a);
}
