/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 14:39:36 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/10 14:51:24 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"
#include "../includes/libps.h"
#include <stdlib.h>
#include <unistd.h>

void	do_sort_stuff(t_stack *a, t_stack *b)
{
	while (stack_sorted(a, b) == false)
	{
		stack_switch(&a, &b);
		write(1, "pa\n", 3);
		while (a->nb >= b->nb)
		{
			stack_switch(&a, &b);
			write(1, "pa\n", 3);
		}
		while (b)
		{
			stack_switch(&b, &a);
			write(1, "pb\n", 3);
			stack_swap(a);
			write(1, "sa\n", 3);
		}
	}
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
