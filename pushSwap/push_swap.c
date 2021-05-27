/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 14:39:36 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/27 13:20:02 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"
#include "../includes/libps.h"
#include "../includes/push_swap.h"
#include <stdlib.h>
#include <unistd.h>

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

int get_next_value(t_stack *s, int nb)
{
	while (s && s->prev)
	{
		if (s->prev->nb == nb)
			return (s->nb);
		s = s->prev;
	}
	return (__INT_MAX__);
}

static int	swap_sb(t_data *v)
{
	print_instructions(v, 1, "sb");
	print_instructions(v, 1, "pa");
	return (1);
}
static int	swap_sa(t_data *v)
{
	print_instructions(v, 2, "pa");
	print_instructions(v, 1, "sa");
	return (1);
}
static int	swap_ss(t_data *v)
{
	print_instructions(v, 2, "pa");
	print_instructions(v, 1, "ss");
	print_instructions(v, 2, "pa");
	return (1);
}

int	stack_get_pos(t_stack *s, int pos)
{
	int i;

	i = 0;
	while (s && i != pos)
	{
		s = s->prev;
		i++;
	}
	return (s->nb);
}

int	swap_routine_check(t_data *data, int nb)
{
	int	rank[4];
	int top[4];

	if (!data->b->prev)
		return (0);
	rank[0] = data->b->nb;
	top[0] = nb;
	rank[1] = data->b->prev->nb;
	top[1] = stack_get_pos(data->sorted, stack_find(data->sorted, nb, -1));
	if (rank[1] == top[0])
	{
		if (rank[0] == top[1])
		{
			if (data->b->prev->prev && data->b->prev->prev->prev)
			{
				rank[2] = data->b->prev->prev->nb;
				top[2] = stack_get_pos(data->sorted, stack_find(data->sorted, nb, -2));
				rank[3] = data->b->prev->prev->prev->nb;
				top[3] = stack_get_pos(data->sorted, stack_find(data->sorted, nb, -3));
				if (rank[2] == top[3] && rank[3] == top[2])
					return (swap_ss(data));
			}
			return (swap_sa(data));
		}
		return (swap_sb(data));
	}
	return (0);
}

void	push_elem_b(t_data *data, int nb)
{
	if (data->b->nb != nb && swap_routine_check(data, nb) == 1)
		return ;
	if (stack_find(data->b, nb, 0) > stack_size(data->b) >> 1)
	{
		print_instructions(data, stack_size(data->b) - stack_find(data->b, nb, 0), "rrb");
		print_instructions(data, 1, "pa");
	}
	else
	{
		print_instructions(data, stack_find(data->b, nb, 0), "rb");
		print_instructions(data, 1, "pa");
	}
}

void	push_pos(t_data *data, int pos, int top)
{
	print_instructions(data, pos, "ra");
	print_instructions(data, 1, "pb");
	(void)top;
	// if (top == false)
	// 	print_instructions(data, 1, "rb");
}


int main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		error("Wrong number of arguments amigo!\n", FATAL); //display nothing?
	data.a = stack_init(argc, argv);
	data.b = NULL;
	data.sorted = pre_sort(data.a);
	if (stack_size(data.a) >= 50)
		big_ol_sorter(&data);
	// else
	// 	smol_sorty(&data);
	return (0);
}
