/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 13:41:12 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/10 15:01:25 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# define HARMLESS	0
# define FATAL		1

typedef enum
{
	false,
	true
}	e_bool;

void	error(char *msg, e_bool is_fatal);
void	*better_malloc(int size);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);

#endif
