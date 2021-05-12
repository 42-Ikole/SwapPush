/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_ol_sorter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <ikole@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/12 11:45:16 by ikole         #+#    #+#                 */
/*   Updated: 2021/05/12 12:41:47 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"
#include "../includes/libps.h"
#include "../includes/push_swap.h"

static int	find_elem_range(t_stack *stack, int range)
{
	t_stack *tmp;
	int		pos_first;
	int		pos_last;
	int		pos;

	tmp = stack;
	pos_first = -1;
	pos_last = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->nb <= range)
		{
			if (pos_first == -1)
				pos_first = pos;
			pos_last = pos;
		}
		tmp = tmp->prev;
		pos++;
	}
	if (diff(pos_first, 0) > diff(pos_last, stack_size(stack)))
		return (pos_last);
	return (pos_first);
}

static void	push_range(t_stack **a, t_stack **b, int range)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp)
	{
		if ((tmp)->nb <= range)
		{
			push_pos(a, b, find_elem_range(*a, range));
			if ((*b) && (*b)->prev && (*b)->nb < (*b)->prev->nb &&
				(*a) && (*a)->prev && (*a)->nb > (*a)->prev->nb)
				print_instructions(a, b, 1, "ss");
			tmp = *a;
		}
		else
			tmp = tmp->prev;
	}
}

static void	sort_range(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int		min;
	int		max;

	tmp = *b;
	while (tmp)
	{
		stack_min_max(*b, &min, &max);
		push_elem_b(a, b, max);
		tmp = tmp->prev;
	}
}

static int	get_range(int min, int section, t_stack *sorted)
{
	int i;

	while (sorted && sorted->nb < min)
		sorted = sorted->prev;
	i = 0;
	while (sorted && i < section)
	{
		sorted = sorted->prev;
		i++;
	}
	if (sorted)
		return (sorted->nb);
	return (min);
}

void		big_ol_sorter(t_stack *a, t_stack *b, t_stack *sorted)
{
	int	min;
	int max;
	int	sections;
	int	range;

	if (stack_sorted(a, b) == true)
		return ;
	sections = ((stack_size(a) % 3) + (stack_size(a) / 11));
	while (stack_size(a) > 0)
	{
		stack_min_max(a, &min, &max);
		range = get_range(min, sections, sorted);
		if (range == min)
			range = max;
		push_range(&a, &b, range);
	}
	sort_range(&a, &b);
}
