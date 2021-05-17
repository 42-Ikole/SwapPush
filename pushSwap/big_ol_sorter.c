/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_ol_sorter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <ikole@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/12 11:45:16 by ikole         #+#    #+#                 */
/*   Updated: 2021/05/17 19:03:43 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"
#include "../includes/libps.h"
#include "../includes/push_swap.h"

void	print_instructions(t_data *data, int amt, char *ins)
{
	int i;

	i = 0;
	while (i < amt)
	{
		write(STDOUT_FILENO, ins, ft_strlen(ins));
		write(STDOUT_FILENO, "\n", 1);
		exec_instruction(&data->a, &data->b, ins);
		i++;
	}
}

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
	while (s && i < (section * (range + 1)) - 1)
	{
		s = s->prev;
		i++;
	}
	return (s->nb);
}

void	push_pos(t_data *data, int pos)
{
	if (pos > stack_size(data->a) >> 1)
	{
		print_instructions(&data->a, &data->b, stack_size(data->a) - pos, "rra");
		print_instructions(&data->a, &data->b, 1, "pb");
	}
	else
	{
		print_instructions(&data->a, &data->b, pos, "ra");
		print_instructions(&data->a, &data->b, 1, "pb");
	}
}

int			get_closest(int min, int max, t_data *data)
{

}

void		push_section(int section, int range, t_data *data)
{
	int	min;
	int	max;
	
	min = get_sec_min(section, range, stack_size(data->sorted));
	max = get_sec_max(section, range, stack_size(data->sorted));
	
}

void		big_ol_sorter(t_data *data)
{
	int range;
	int	half;

	if (stack_sorted(data->a, data->b) == true)
		return ;
	data->sections = ((stack_size(data->a) % 3) + (stack_size(data->a) / 11));
	range = stack_size(data->a) / sections;
	half = sections / 2;
	push_section(half, range, data);
}
