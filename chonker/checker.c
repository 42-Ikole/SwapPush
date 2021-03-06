/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 14:40:11 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/24 18:01:21 by ingmar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"
#include "../includes/libps.h"
#include "../includes/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

void			read_instructions(t_stack *a, t_stack *b)
{
	char	*line;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret > 0)
			exec_instruction(&a, &b, line);
		if (ret <= 0) //misschien ret > 0
			free(line);
		print_stack(a, b);
	}
	if (ret < 0)
		error("Something went wrong whilst reading a line!\n", FATAL);
	if (stack_sorted(a, b) == true)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}

int				main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		error("Wrong number of arguments amigo!\n", FATAL); //display nothing?
	a = stack_init(argc, argv);
	b = NULL;
	read_instructions(a, b);
	return (0);
}
