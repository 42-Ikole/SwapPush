/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 14:39:36 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/10 19:45:42 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"
#include "../includes/libps.h"
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

void	push_elem(t_stack **a, t_stack **b, int nb)
{
	if (stack_find(*a, nb) > stack_size(*a) >> 1)
	{
		print_instructions(a, b, stack_size(*a) - stack_find(*a, nb), "rra");
		print_instructions(a, b, 1, "pb");
	}
	else
	{
		print_instructions(a, b, stack_find(*a, nb), "ra");
		print_instructions(a, b, 1, "pb");
	}
}

void	push_range(t_stack **a, t_stack **b, int range)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp)
	{
		if ((tmp)->nb < range)
		{
			push_elem(a, b, (tmp->nb));
			if ((*b)->nb < (*b)->prev->nb)
				print_instructions(a, b, 1, "sb");
		}
		tmp = tmp->prev;
	}
}

void	sort_range(t_stack **a, t_stack **b, int min)
{
	t_stack *tmp;
	int		rot;
	int		pos;

	tmp = *b;
	rot = 0;
	pos = 0;
	while (tmp->nb != min)
	{
		if (tmp->nb > tmp->prev->nb)
		{
			pos = stack_find(*b, tmp->nb);
			if (pos != 0)
			{
				print_instructions(a, b, pos, "rb");
				rot += pos;
			}
			print_instructions(a, b, 1, "sb");
		}
		tmp = tmp->prev;
	}
	print_instructions(a, b, rot, "rrb");
}

void	do_sort_stuff(t_stack *a, t_stack *b)
{
	int	min;
	int max;
	int	sections;

	sections = (stack_size(a) / 10) + 1;
	// print_stack(a, b);
	while (stack_size(a) > 0)
	{
		stack_min_max(a, &min, &max);
		push_elem(&a, &b, min);
		push_range(&a, &b, min + ((min - max) / sections));
		sort_range(&a, &b, min);
	}
	print_instructions(&a, &b, stack_size(b), "pa");
}

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		error("Wrong number of arguments amigo!\n", FATAL); //display nothing?
	a = stack_init(argc, argv);
	b = NULL;
	do_sort_stuff(a, b);
	return (0);
}
