/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:11:44 by dlima-li          #+#    #+#             */
/*   Updated: 2026/03/06 19:17:50 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_stack **stack, int pos, int is_a)
{
	int	size;

	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			if (is_a)
				ra(stack, 1);
			else
				rb(stack, 1);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			if (is_a)
				rra(stack, 1);
			else
				rrb(stack, 1);
			pos++;
		}
	}
}

void	exec_cheap_move(t_stack **stack_a, t_stack **stack_b,
			int pos_b, int tarpos_a)
{
// 	int	size_a;
// 	int	size_b;

// 	size_a = stack_size(*stack_a);
// 	size_b = stack_size(*stack_b);
// 	if (pos_b <= size_b / 2 && tarpos_a <= size_a / 2)
// 		rot_both(stack_a, stack_b, &tarpos_a, &pos_b);
// 	else if (pos_b > size_b / 2 && tarpos_a > size_a / 2)
// 	{
// 		tarpos_a = size_a - tarpos_a;
// 		pos_b = size_b - pos_b;
// 		rrot_both(stack_a, stack_b, &tarpos_a, &pos_b);
// 	}
	rotate_to_top(stack_a, tarpos_a, 1);
	rotate_to_top(stack_b, pos_b, 0);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;

	size = stack_size(*stack_a);
	pushed = 0;
	while (size > 3)
	{
		pb(stack_a, stack_b, 1);
		pushed++;
		size--;
		if (pushed > 1 && (*stack_b)->value < (*stack_b)->next->value)
			rb(stack_b, 1);
	}
}

void	final_rotation(t_stack **stack_a)
{
	int	min_pos;
	int	size;

	min_pos = find_position(*stack_a, find_min(*stack_a));
	size = stack_size(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(stack_a, 1);
			min_pos++;
		}
	}
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	best_pos_b;
	int	best_target_a;

	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		find_cheap(*stack_a, *stack_b, &best_pos_b, &best_target_a);
		exec_cheap_move(stack_a, stack_b, best_pos_b, best_target_a);
		pa(stack_a, stack_b, 1);
	}
	final_rotation(stack_a);
}
