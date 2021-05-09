/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libps.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ingmar <ingmar@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 13:57:01 by ingmar        #+#    #+#                 */
/*   Updated: 2021/05/09 15:31:05 by ingmar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

typedef struct s_stack
{
	int				nb;
	struct s_stack	*prev;
}	t_stack;

t_stack	*stack_push(t_stack *stack, int data);
t_stack	*stack_pop(t_stack *stack);
void	stack_swap(t_stack *stack);
void	stack_rotate(t_stack *stack);
void	stack_reverse_rotate(t_stack *stack);
void	stack_switch(t_stack **stack_left, t_stack **stack_right);

#endif
