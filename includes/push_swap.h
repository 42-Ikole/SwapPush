/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 14:43:56 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/12 11:49:04 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libps.h"

/*
**  PUSH_SWAP.C
*/

void	print_instructions(t_stack **a, t_stack **b, int amt, char *ins);
void	push_pos(t_stack **a, t_stack **b, int pos);
void	push_elem_b(t_stack **a, t_stack **b, int nb);
t_stack *pre_sort(t_stack *a);

/*
**  BIG_OL_SORTER.C
*/

void	big_ol_sorter(t_stack *a, t_stack *b, t_stack *sorted);

#endif
