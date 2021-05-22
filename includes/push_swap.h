/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 14:43:56 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/22 20:44:17 by ingmar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libps.h"

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*sorted;
	int			sections;
}	t_data;

/*
**  PUSH_SWAP.C
*/

void	sort_range(t_data *data);
void	print_instructions(t_data *data, int amt, char *ins);
void	push_pos(t_data *data, int pos, int top);
void	push_elem_b(t_data *data, int nb);
t_stack *pre_sort(t_stack *a);

/*
**  SORTING FUNCTIONS
*/

void	big_ol_sorter(t_data *data);
void	smol_sorty(t_data *data);

#endif
