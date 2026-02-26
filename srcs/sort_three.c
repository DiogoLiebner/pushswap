/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:02:10 by dlima-li          #+#    #+#             */
/*   Updated: 2026/02/20 16:11:22 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	max;

	if (is_sorted(*stack_a))
		return ;
	max = find_max(*stack_a);
	if ((*stack_a)->value == max)
		ra(stack_a, 1);
	else if ((*stack_a)->next->value == max)
		rra(stack_a, 1);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, 1);
}
