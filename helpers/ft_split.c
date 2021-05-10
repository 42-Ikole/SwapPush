/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 12:58:41 by ikole         #+#    #+#                 */
/*   Updated: 2019/11/05 12:58:42 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		ft_tocharlen(char const *str, char c)
{
	int i;
	int j;

	j = 0;
	while (str[j] == c)
		j++;
	i = j;
	while (str[i] != c && str[i])
		i++;
	return (i - j);
}

static	int		ft_size(char const *str, char c)
{
	int i;
	int size;

	i = 0;
	size = 1;
	while (str[i])
	{
		if (((str[i] == c && str[i + 1] != c) ||
			(i == 0 && str[i] != c)) && str[i + 1] != '\0')
			size++;
		i++;
	}
	return (size);
}

static	void	ft_freeshee(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

static	void	ft_split_too(char **str, char c, char const *s, int *i)
{
	int k;
	int j;

	k = 0;
	while (s[k] == c && c != '\0')
		k++;
	while (s[k])
	{
		j = 0;
		str[i[0]] = malloc(sizeof(char) * ft_tocharlen(&s[k], c) + 1);
		if (!str[i[0]])
			return ;
		while (s[k] == c && c != '\0')
			k++;
		while (s[k] != c && s[k])
		{
			str[i[0]][j] = s[k];
			j++;
			k++;
		}
		str[i[0]][j] = '\0';
		i[0]++;
		while (s[k] == c && c != '\0')
			k++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	int		i[1];

	i[0] = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char*) * ft_size(s, c));
	if (!str)
		return (NULL);
	ft_split_too(str, c, s, i);
	if (!str)
	{
		ft_freeshee(str, i[0] - 1);
		return (NULL);
	}
	else
		str[i[0]] = NULL;
	return (str);
}
