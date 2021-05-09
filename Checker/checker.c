/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 14:40:11 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/09 19:29:02 by ingmar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"
#include "../includes/libps.h"
#include "../includes/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static int		is_sorted(t_stack *a, t_stack *b)
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

static t_stack	*init_stack(int length, char **ints)
{
	t_stack *new;

	new = NULL;
	while (length > 0)
	{
		stack_push(&new, ft_atoi(ints[length]));
		length--;
	}
	return (new);
}

void			read_instructions(t_stack *a, t_stack *b)
{
	char	*line;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		exec_instruction(&a, &b, line);
		if (is_sorted(a, b) == true)
			write(STDOUT_FILENO, "OK\n", 3);
		else
			write(STDOUT_FILENO, "KO\n", 3);
		if (line) //misschien ret > 0
			free(line);
	}
	if (ret < 0)
		error("Something went wrong whilst reading a line!\n", FATAL);
}

int				main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		error("Wrong number of arguments amigo!\n", FATAL); //display nothing?
	a = init_stack(argv);
	b = NULL;
	read_instructions(a, b);
	return (0);
}
