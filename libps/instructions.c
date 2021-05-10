/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 16:20:26 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/10 19:45:55 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libps.h"
#include "../includes/helpers.h"

void	ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
}

void	rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	stack_reverse_rotate(a);
	stack_reverse_rotate(b);
}

#include <stdio.h>
void	exec_instruction(t_stack **a, t_stack **b, char *ins)
{
	// printf("%s      |\n---------\n", ins);
	if (!ft_strcmp(ins, "sa"))
		stack_swap(*a);
	else if (!ft_strcmp(ins, "sb"))
		stack_swap(*b);
	else if (!ft_strcmp(ins, "ss"))
		ss(*a, *b);
	else if (!ft_strcmp(ins, "pa"))
		stack_switch(b, a);
	else if (!ft_strcmp(ins, "pb"))
		stack_switch(a, b);
	else if (!ft_strcmp(ins, "ra"))
		stack_rotate(*a);
	else if (!ft_strcmp(ins, "rb"))
		stack_rotate(*b);
	else if (!ft_strcmp(ins, "rr"))
		rr(*a, *b);
	else if (!ft_strcmp(ins, "rra"))
		stack_reverse_rotate(*a);
	else if (!ft_strcmp(ins, "rrb"))
		stack_reverse_rotate(*b);
	else if (!ft_strcmp(ins, "rrr"))
		rrr(*a, *b);
	else
		error("WHOA that command does not exist\n", FATAL); //maybe not exit yes?
	// print_stack(*a, *b);
}
