/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smol_sorty.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <ikole@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/12 11:54:37 by ikole         #+#    #+#                 */
/*   Updated: 2021/05/12 12:53:00 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libps.h"
#include "../includes/helpers.h"
#include "../includes/push_swap.h"

void	smol_sorty(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	stack_min_max(a, &min, &max);
	while (stack_sorted(a, b) == false)
	{
		if (a && a->prev && a->nb > a->prev->nb)
			exec_instruction(&a, &b, "sa");
		if (stack_sorted(a, b) == true)
			break ;
		if (a)
			exec_instruction(&a, &b, "pb");
		if (!a)
			sort_range(&a, &b);
	}
}