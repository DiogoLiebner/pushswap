/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:55:30 by dlima-li          #+#    #+#             */
/*   Updated: 2026/02/24 17:50:31 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	pos;
	int	size;

	min = find_min(*stack_a);
	pos = find_position(*stack_a, min);
	size = stack_size(*stack_a);
	if (pos <= size / 2)
	{
		while ((*stack_a)->value != min)
			ra(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->value != min)
			rra(stack_a, 1);
	}
	pb(stack_a, stack_b, 1);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		push_min_to_b(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
