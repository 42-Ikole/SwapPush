/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smol_sorty.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ikole <ikole@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/12 11:54:37 by ikole         #+#    #+#                 */
/*   Updated: 2021/05/18 10:50:18 by ikole         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libps.h"
#include "../includes/helpers.h"
#include "../includes/push_swap.h"

// void	smol_sorty(t_data *data)
// {
// 	int	min;
// 	int	max;

// 	stack_min_max(data->a, &min, &max);
// 	while (stack_sorted(data->a, data->b) == false)
// 	{
// 		if (data->a && data->a->prev && data->a->nb > data->a->prev->nb)
// 			exec_instruction(&a, &b, "sa");
// 		if (stack_sorted(data->a, data->b) == true)
// 			break ;
// 		if (data->a)
// 			exec_instruction(&a, &b, "pb");
// 		if (!data->a)
// 			sort_range(&a, &b);
// 	}
// }