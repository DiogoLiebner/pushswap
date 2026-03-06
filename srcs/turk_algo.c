/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:10:37 by dlima-li          #+#    #+#             */
/*   Updated: 2026/03/06 19:15:40 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_pos(t_stack *stack_a, int value)
{
	// t_stack	*temp;
	// int		target_pos;
	// int		target_value;
	// int		pos;

	// target_value = INT_MAX;
	// target_pos = 0;
	// pos = 0;
	// temp = stack_a;
	// while (temp)
	// {
	// 	if (temp->value > value && temp->value < target_value)
	// 	{
	// 		target_value = temp->value;
	// 		target_pos = pos;
	// 	}
	// 	pos++;
	// 	temp = temp->next;
	// }
	// printf("find_target_pos: value=%d target_value=%d target_pos=%d\n",
    //     value, target_value, target_pos);
	// if (target_value == INT_MAX)
	// 	target_pos = find_position(stack_a, find_min(stack_a));
	// return (target_pos);
	t_stack	*temp;
	int		pos;
	int		size;

	size = stack_size(stack_a);
	if (size == 0)
		return (0);
	temp = stack_a;
	pos = 0;
	while (temp->next)
	{
		if (temp->value < temp->next->value)
		{
			if (value > temp->value && value < temp->next->value)
				return (pos + 1);
		}
		else
		{
			if (value > temp->value || value < temp->next->value)
				return (pos + 1);
		}
		temp = temp->next;
		pos++;
	}
	return (0);
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

void	find_cheap(t_stack *stack_a, t_stack *stack_b,
		int *bestp_b, int *besttarg_a)
{
	t_stack	*temp;
	int		pos_b;
	int		target_pos_a;
	int		cost;
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
			*bestp_b = pos_b;
			*besttarg_a = target_pos_a;
		}
		pos_b++;
		temp = temp->next;
	}
}

void	rot_both(t_stack **stack_a, t_stack **stack_b, int *pos_a, int *pos_b)
{
	while (*pos_a > 0 && *pos_b > 0)
	{
		rr(stack_a, stack_b, 1);
		(*pos_a)--;
		(*pos_b)--;
	}
}

void	rrot_both(t_stack **stack_a, t_stack **stack_b, int *pos_a, int *pos_b)
{
	while (*pos_a > 0 && *pos_b > 0)
	{
		rrr(stack_a, stack_b, 1);
		(*pos_a)--;
		(*pos_b)--;
	}
}
