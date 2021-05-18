/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_ol_sorter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <ikole@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/12 11:45:16 by ikole         #+#    #+#                 */
/*   Updated: 2021/05/18 13:25:43 by ikole         ########   odam.nl         */
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

void		big_ol_sorter(t_data *data)
{
	int range;
	int mid;
	int i;

	if (stack_sorted(data->a, data->b) == true)
		return ;
	data->sections = ((stack_size(data->a) % 3) + (stack_size(data->a) / 11));
	range = stack_size(data->a) / data->sections;
	mid = data->sections / 2;
	push_section(data->sections / 2, range, data, 1);
	i = mid;
	while (i >= 0)
	{
		push_section(i, range, data, -1);
		if (mid + diff(i, mid) < data->sections)
			push_section(mid + diff(i, mid), range, data, 1);
		i--;
	}
}
