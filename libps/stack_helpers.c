/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_helpers.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <ikole@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/10 17:24:08 by ikole         #+#    #+#                 */
/*   Updated: 2021/05/11 11:57:46 by ingmar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libps.h"
#include "../includes/helpers.h"
#include <limits.h>
#include <stdlib.h>

t_stack	*stack_init(int length, char **ints)
{
	t_stack *new;
	char	**splt;
	int		i;

	new = NULL;
	while (length > 1)
	{
		length--;
		i = 0;
		splt = ft_split(ints[length], ' ');
		while (splt[i])
			i++;
		while (i > 0)
		{
			i--;
			stack_push(&new, ft_atoi(splt[i]));
			free(splt[i]);
		}
		free(splt);
	}
	return (new);
}

int		stack_sorted(t_stack *a, t_stack *b)
{
	if (b != NULL)
		return (false);
	while (a->prev)
	{
		if (a->prev->nb < a->nb)
			return (false);
		a = a->prev;
	}
	return (true);
}

#include <stdio.h> //
#include <unistd.h> //
void	print_stack(t_stack *a, t_stack *b)
{
printf("-------------------------------------------\n");
	while (a || b)
	{
		printf("%d	||	%d\n", (a) ? a->nb : 0, (b) ? b->nb : 0);
		if (a)
			a = a->prev;
		if (b)
			b = b->prev;
	}
	// usleep(600000);
	// system("clear");
}

int		stack_size(t_stack *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		stack = stack->prev;
		i++;
	}
	return (i);
}

void	stack_min_max(t_stack *stack, int *min, int *max)
{
	*min = INT_MAX;
	*max = INT_MIN;
	while (stack)
	{
		if (stack->nb < *min)
			*min = stack->nb;
		if (stack->nb > *max)
			*max = stack->nb;
		stack = stack->prev;
	}
}

int		stack_find(t_stack *a, int nb)
{
	int i;

	i = 0;
	while (a && a->nb != nb)
	{
		a = a->prev;
		i++;
	}
	if (!a)
		return (-1);
	return (i);
}
