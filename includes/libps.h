/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libps.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 13:57:01 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/09 18:16:07 by ingmar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

typedef struct s_stack
{
	int				nb;
	struct s_stack	*prev;
}	t_stack;

/*
** STACK FUNCTIONALITY
*/

void	stack_push(t_stack **stack, int data);
void	stack_pop(t_stack **stack);
void	stack_swap(t_stack *stack);
void	stack_rotate(t_stack *stack);
void	stack_reverse_rotate(t_stack *stack);
void	stack_switch(t_stack **stack_left, t_stack **stack_right);

/*
** PUSH SWAP DOUBLE INSTRUCTIONS
*/

void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	exec_instruction(t_stack **a, t_stack **b, char *ins);

#endif
