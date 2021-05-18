/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 14:39:36 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/18 13:22:57 by ikole         ########   odam.nl         */
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

void	push_pos(t_data *data, int pos, int top)
{
	if (pos > stack_size(data->a) >> 1)
	{
		print_instructions(data, stack_size(data->a) - pos, "rra");
		print_instructions(data, 1, "pb");
	}
	else
	{
		print_instructions(data, pos, "ra");
		print_instructions(data, 1, "pb");
	}
	if (top < 0)
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
