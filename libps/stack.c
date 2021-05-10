/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 13:58:26 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/10 16:26:33 by ikole         ########   odam.nl         */
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
		return ;
	}
	ret = (*stack)->prev;
	free(*stack);
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
	t_stack *tmp;

	if (!stack || !stack->prev)
		return ;
	tmp = stack;
	tmp->prev = NULL;
	while (stack->prev != NULL)
		stack = stack->prev;
	stack->prev = tmp;
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
		stack_push(stack_right, (*stack_left)->nb);
	stack_pop(stack_left);
}

t_stack	*stack_init(int length, char **ints)
{
	t_stack *new;
	char	**splt;
	int		i;

	new = NULL;
	while (length > 1)
	{
		length--;
		i = 0;
		splt = ft_split(ints[length], ' ');
		while (splt[i])
		{
			stack_push(&new, ft_atoi(splt[i]));
			free(splt[i]);
			i++;
		}
		free(splt);
	}
	return (new);
}

int		stack_sorted(t_stack *a, t_stack *b)
{
	if (b != NULL)
		return (false);
	while (a->prev)
	{
		if (a->prev->nb < a->nb)
			return (false);
		a = a->prev;
	}
	return (true);
}

#include <stdio.h>
#include <unistd.h>
void	print_stack(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		printf("%d		%d\n", (a) ? a->nb : 0, (b) ? b->nb : 0);
		if (a)
			a = a->prev;
		if (b)
			b = b->prev;
	}
	usleep(200000);
	printf("-------------------------------------------\n");
	// system("clear");
}
