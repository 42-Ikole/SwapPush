/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 13:41:18 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/09 15:07:16 by ingmar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"
#include <unistd.h>
#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		error(char *msg, int is_fatal)
{
	write(2, msg, ft_strlen(msg));
	if (is_fatal == FATAL)
		exit (1);
}

void		*better_malloc(int size)
{
	void *ret;

	ret = malloc(size);
	if (ret == NULL)
		error("Real unfortunate malloc fail!\n", FATAL);
	return (ret);
}
