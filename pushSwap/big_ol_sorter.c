/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_ol_sorter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <ikole@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/12 11:45:16 by ikole         #+#    #+#                 */
/*   Updated: 2021/05/22 12:56:56 by ingmar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"
#include "../includes/libps.h"
#include "../includes/push_swap.h"
#include <stdlib.h> //

int			get_sec_min(int section, int range, t_stack *s)
{
	int i;

	i = 0;
	while (s && i < section * range)
	{
		s = s->prev;
		i++;
	}
	return (s->nb);
}

int			get_sec_max(int section, int range, t_stack *s)
{
		int i;

	i = 0;
	while (s->prev && i < (section * range) + range - 1)
	{
		s = s->prev;
		i++;
	}
	return (s->nb);
}

// int			get_closest(int min, int max, t_data *data)
// {
// 	int		pos_min;
// 	int		pos_max;
// 	t_stack	*tmp;
// 	int		i;

// 	tmp = data->a;
// 	while (tmp)
// 	{
// 		tmp = tmp->prev;
// 	}
// }

void		push_mul_section(int sec1, int sec2, int range, t_data *data)
{
	int		min[2];
	int		max[2];
	t_stack	*tmp;
	int		i;

	min[0] = get_sec_min(sec1, range, data->sorted);
	max[0] = get_sec_max(sec1, range, data->sorted);
	min[1] = get_sec_min(sec2, range, data->sorted);
	max[1] = get_sec_max(sec2, range, data->sorted);
	tmp = data->a;
	i = 0;
	while (tmp)
	{
		if (tmp->nb >= min[0] && tmp->nb <= max[0])
			push_pos(data, i, false);
		else if (tmp->nb >= min[1] && tmp->nb <= max[1])
			push_pos(data, i, true);
		else
		{
			i++;
			tmp = tmp->prev;
			continue ;
		}
		tmp = data->a;
		i = 0;
	}
}

void		push_section(int section, int range, t_data *data, int top)
{
	int		min;
	int		max;
	t_stack	*tmp;
	int		i;

	min = get_sec_min(section, range, data->sorted);
	max = get_sec_max(section, range, data->sorted);
	tmp = data->a;
	i = 0;
	while (tmp)
	{
		if (tmp->nb >= min && tmp->nb <= max)
		{
			push_pos(data, i, top);
			tmp = data->a;
			i = 0;
			continue ;
		}
		i++;
		tmp = tmp->prev;
	}
}

void	sort_range(t_data *data)
{
	t_stack *tmp;
	int		min;
	int		max;

	tmp = data->b;
	while (tmp)
	{
		stack_min_max(data->b, &min, &max);
		push_elem_b(data, max);
		tmp = tmp->prev;
	}
}

void		big_ol_sorter(t_data *data)
{
	int range;
	int mid;
	int i;

	if (stack_sorted(data->a, data->b) == true)
		return ;
	// data->sections = ((stack_size(data->a) % 3) + (stack_size(data->a) / 11));
	data->sections = 11;
	range = stack_size(data->a) / data->sections;
	mid = data->sections / 2;
	push_section(mid, range, data, true);
	i = mid;
	while (i >= 0)
	{
		push_mul_section(i, mid + diff(i, mid), range, data);
		i--;
	}
	sort_range(data);
}
