/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pre_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <ikole@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/12 10:34:59 by ikole         #+#    #+#                 */
/*   Updated: 2021/05/12 11:09:45 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/libps.h"

static t_stack	*copy_sort(t_stack *stack, int min, int max, t_stack *new)
{
	int		last;
	t_stack	*head;

	head = stack;
	stack_push(&new, min);
	while (min != max)
	{
		last = __INT_MAX__;
		stack = head;
		while (stack)
		{
			if (stack->nb > min && stack->nb < last)	
				last = stack->nb;
			stack = stack->prev;
		}
		stack_push(&new, last);
		min = last;
	}
	return (new);
}

static t_stack	*reverse_list(t_stack *old)
{
	t_stack	*ret;

	ret = NULL;
	while (old)
		stack_switch(&old, &ret);
	return (ret);
}

t_stack *pre_sort(t_stack *a)
{
	t_stack	*ret;
	int		min;
	int		max;

	ret = NULL;
	stack_min_max(a, &min, &max);
	ret = copy_sort(a, min, max, ret);
	ret = reverse_list(ret);
	return (ret);
}
