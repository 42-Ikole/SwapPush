/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 14:39:36 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/12 12:33:38 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"
#include "../includes/libps.h"
#include "../includes/push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	print_instructions(t_stack **a, t_stack **b, int amt, char *ins)
{
	int i;

	i = 0;
	while (i < amt)
	{
		write(STDOUT_FILENO, ins, ft_strlen(ins));
		write(STDOUT_FILENO, "\n", 1);
		exec_instruction(a, b, ins);
		i++;
	}
}

void	push_pos(t_stack **a, t_stack **b, int pos)
{
	if (pos > stack_size(*a) >> 1)
	{
		print_instructions(a, b, stack_size(*a) - pos, "rra");
		print_instructions(a, b, 1, "pb");
	}
	else
	{
		print_instructions(a, b, pos, "ra");
		print_instructions(a, b, 1, "pb");
	}
}

void	push_elem_b(t_stack **a, t_stack **b, int nb)
{
	if (stack_find(*b, nb) > stack_size(*b) >> 1)
	{
		print_instructions(a, b, stack_size(*b) - stack_find(*b, nb), "rrb");
		print_instructions(a, b, 1, "pa");
	}
	else
	{
		print_instructions(a, b, stack_find(*b, nb), "rb");
		print_instructions(a, b, 1, "pa");
	}
}

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack *sorted;

	if (argc < 2)
		error("Wrong number of arguments amigo!\n", FATAL); //display nothing?
	a = stack_init(argc, argv);
	b = NULL;
	sorted = pre_sort(a);
	if (stack_size(a) >= 50)
		big_ol_sorter(a, b, sorted);
	// else
	// 	smol_sorty(a, b, sorted);
	return (0);
}
