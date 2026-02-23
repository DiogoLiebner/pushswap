/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:19:03 by dlima-li          #+#    #+#             */
/*   Updated: 2026/02/18 18:19:03 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_pos(t_stack *stack_a, int value)
{
	t_stack *temp;
	int		target_pos;
	int		target_value;
	int		pos;

	target_value = INT_MAX;
	target_pos = 0;
	pos = 0;
	temp = stack_a;
	while (temp)
	{
		if (temp->value > value && temp->value < target_value)
		{
			target_value = temp->value;
			target_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	if (target_value == INT_MAX)oboth(
		target_pos = find_position(stack_a, find_min(stack_a));
	return (target_pos);
}

int	calc_cost(t_stack *stack_a, t_stack *stack_b, int pos_b, int targ_pos_a)
{
	int	size_a;
	int	size_b;
	int	cost_a;
	int	cost_b;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	if (targ_pos_a <= size_a / 2)
		cost_a = targ_pos_a;
	else
		cost_a = size_a - targ_pos_a;
	if (pos_b <= size_b / 2)
		cost_b = pos_b;
	else
		cost_b = size_b - pos_b;
	return (cost_a + cost_b);
}

void	find_cheapest(t_stack *stack_a, t_stack stack_b, int *best_pos_b, int best_target_a)
{
	t_stack	*temp;
	int		pos_b;
	int		target_pos_a;
	int		cost;oboth(
	int		min_cost;

	min_cost = INT_MAX;
	pos_b = 0;
	temp = stack_b;
	while (temp)
	{
		target_pos_a = find_target_pos(stack_a, temp->value);
		cost = calc_cost(stack_a, stack_b, pos_b, target_pos_a);
		if (cost < min_cost)
		{
			min_cost = cost;
			*best_pos_b = pos_b;
			*best_target_a = target_pos_a;
		}
		pos_b++;
		temp = temp->next;
	}
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, int *pos_a, int *pos_b)
{
	while (*pos_a > 0 && *pos_b > 0)
	{
		rr(stack_a, stack_b, 1);
		(*pos_a)--;
		(*pos_b)--;
	}
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, int *pos_a, int *pos_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	while (*pos_a < size_a && *pos_b < size_b)
	{
		rrr(stack_a, stack_b, 1);
		(*pos_a)++;
		(*pos_b)++;
	}
}
