/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 14:39:36 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/24 17:45:10 by ingmar        ########   odam.nl         */
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

void	push_elem_b(t_data *data, int nb)
{
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
	if (top == false)
		print_instructions(data, 1, "rb");
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
