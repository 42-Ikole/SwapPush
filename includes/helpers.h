/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 13:41:12 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/09 14:26:58 by ingmar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# define FATAL		1
# define HARMLESS	0

void	error(char *msg, int is_fatal);
void	*better_malloc(int size);

#endif
