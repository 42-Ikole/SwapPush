/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 13:41:18 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/10 18:38:53 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"
#include <unistd.h>
#include <stdlib.h>

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void		error(char *msg, e_bool is_fatal)
{
	write(STDERR_FILENO, "\e[0;31mError\e[0m\n\e[0;33m", 25);
	write(STDERR_FILENO, msg, ft_strlen(msg));
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

int			ft_atoi(char *str)
{
	long long res;
	long long sgn;

	res = 0;
	sgn = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sgn = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((res * 10 + (*str - '0')) < res)
			return (((sgn * -1) - 1) / 2);
		res = res * 10 + *str - '0';
		str++;
	}
	if (*str)
		error("YARR, These integers invalid matey!\n", FATAL);
	return ((int)(res * sgn));
}
