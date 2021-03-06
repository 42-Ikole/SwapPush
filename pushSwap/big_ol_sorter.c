/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_ol_sorter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <ikole@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/12 11:45:16 by ikole         #+#    #+#                 */
/*   Updated: 2021/05/27 13:40:44 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"
#include "../includes/libps.h"
#include "../includes/push_swap.h"
#include <limits.h>
#include <stdlib.h> //

int			get_range_min(t_data * data, int min_id, int range)
{
	int i;
	t_stack *tmp;

	i = 0;
	tmp = data->sorted;
	while (tmp && i < min_id - range)
	{
		tmp = tmp->prev;
		i++;
	}
	if (tmp)
		return (tmp->nb);
	return (INT_MIN);
}

int			get_range_max(t_data * data, int max_id, int range)
{
	int i;
	t_stack *tmp;

	i = 0;
	tmp = data->sorted;
	while (tmp && i < max_id + range)
	{
		tmp = tmp->prev;
		i++;
	}
	if (tmp)
		return (tmp->nb);
	return (INT_MAX);
}

int			get_sorted_number(t_data *data, int idx)
{
	t_stack *tmp;
	int i;

	i = 0;
	tmp = data->sorted;
	while (tmp && i < idx)
	{
		i++;
		tmp = tmp->prev;
	}
	if (tmp)
		return (tmp->nb);
	return (INT_MAX);
}

int			get_next_lowest(t_data *data, int idx)
{
	while (idx >= 0)
	{
		if (stack_find(data->a, get_sorted_number(data, idx), 0) >= 0)
			return (idx);
		idx--;
	}
	return (0);
}

int			get_next_highest(t_data *data, int idx)
{
	int size;

	size = stack_size(data->sorted);
	while (idx < size)
	{
		if (stack_find(data->a, get_sorted_number(data, idx), 0) >= 0)
			return (idx);
		idx++;
	}
	return (size);
}

void		push_section(int mid, int range, t_data *data)
{
	int		min[2];
	int		max[2];
	t_stack	*tmp;
	int		i;

	tmp = data->a;
	i = 0;
	min[1] = mid;
	max[1] = mid;
	while (tmp)
	{
		min[0] = get_range_min(data, min[1], range);
		max[0] = get_range_max(data, max[1], range);
		if (tmp->nb >= min[0] && tmp->nb <= max[0])
		{
			if (tmp->nb >= get_sorted_number(data, max[1]))
				push_pos(data, i, true);
			else
			{
				push_pos(data, i, false);
				if (data->a && (data->a->nb < min[0] || data->a->nb > max[0]))
					print_instructions(data, 1, "rr");
				else
					print_instructions(data, 1, "rb");
			}
			tmp = data->a;
			i = 0;
			if (stack_find(data->a, get_sorted_number(data, min[1]), 0) == -1)
				min[1] = get_next_lowest(data, min[1]);
			if (stack_find(data->a, get_sorted_number(data, max[1]), 0) == -1)
				max[1] = get_next_highest(data, max[1]);
			continue ;
		}
		i++;
		tmp = tmp->prev;
	}
}

void	sort_range(t_data *data)
{
	int		min;
	int		max;

	while (data->b)
	{
		stack_min_max(data->b, &min, &max);
		push_elem_b(data, max);
	}
}

void		big_ol_sorter(t_data *data)
{
	int range;

	if (stack_sorted(data->a, data->b) == true)
		return ;
	if (stack_size(data->a) >= 250)
		data->sections = 23;
	else
		data->sections = 11;
	range = stack_size(data->a) / data->sections;
	push_section(stack_size(data->a) >> 1, range, data);
	sort_range(data);
}
