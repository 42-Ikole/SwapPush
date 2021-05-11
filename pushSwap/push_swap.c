/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 14:39:36 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/11 11:34:12 by ingmar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"
#include "../includes/libps.h"
#include <stdlib.h>
#include <unistd.h>

long		diff(int a, int b)
{
	if (a < 0 || b < 0)
		return ((-a) + b);
    else
        return (b - a);
}

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

int		find_elem_range(t_stack *stack, int range)
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

void	push_range(t_stack **a, t_stack **b, int range)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp)
	{
		// printf("%d\n", range);
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

void	sort_range(t_stack **a, t_stack **b)
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

void	do_sort_stuff(t_stack *a, t_stack *b)
{
	int	min;
	int max;
	int	sections;
	int	range;

	sections = (stack_size(a) / 10) + 1;
	while (stack_size(a) > 0)
	{
		stack_min_max(a, &min, &max);
		range = min + (diff(min, max) / sections);
		if (range == min)
			range = max;
		push_range(&a, &b, range);
	}
	sort_range(&a, &b);
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
