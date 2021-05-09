/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 13:58:26 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/09 18:21:38 by ingmar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libps.h"
#include "../includes/helpers.h"
#include <stdlib.h>

void	stack_push(t_stack **stack, int data)
{
	t_stack *new;
	
	new = better_malloc(sizeof(t_stack));
	new->nb = data;
	new->prev = NULL;
	if (stack != NULL)
		new->prev = *stack;
	*stack = new;
}

void	stack_pop(t_stack **stack)
{
	t_stack *ret;

	if (*stack == NULL)
	{
		error("Cannot pop from empty stack\n", HARMLESS);
		return (stack);
	}
	ret = (*stack)->prev;
	free(stack);
	*stack = ret;
}

void	stack_swap(t_stack *stack)
{
	int tmp;

	if (!stack || !stack->prev)
		return ;
	tmp = stack->nb;
	stack->nb = stack->prev->nb;
	stack->prev->nb = tmp;
}

void	stack_rotate(t_stack *stack)
{
	int		head;

	if (!stack || !stack->prev)
		return ;
	head = stack->nb;
	while (stack->prev != NULL)
	{
		stack->nb = stack->prev->nb;
		stack = stack->prev;
	}
	stack->nb = head;
}

void	stack_reverse_rotate(t_stack *stack)
{
	int		prev;
	int		cur;
	t_stack	*head;

	if (!stack || !stack->prev)
		return ;
	head = stack;
	cur = stack->nb;
	while (stack->prev != NULL)
	{
		prev = stack->prev->nb;
		stack->prev->nb = cur;
		stack = stack->prev;
		cur = prev;
	}
	head->nb = prev;
}

void	stack_switch(t_stack **stack_left, t_stack **stack_right)
{
	if (stack_left && *stack_left)
		stack_push(*stack_right, (*stack_left)->nb);
	stack_pop(*stack_left);
}
