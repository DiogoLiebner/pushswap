/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:17:01 by dlima-li          #+#    #+#             */
/*   Updated: 2026/04/21 16:22:23 by dlima-li         ###   ########.fr       */
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
		rotate_to_top(stack_a, best_target_a, 1);
		rotate_to_top(stack_b, best_pos_b, 0);
		pa(stack_a, stack_b, 1);
	}
	final_rotation(stack_a);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(*stack_a))
	{
		if (stack_size(*stack_a) == 2)
			sa(stack_a, 1);
		else if (stack_size(*stack_a) == 3)
			sort_three(stack_a);
		else if (stack_size(*stack_a) <= 5)
			sort_small(stack_a, stack_b);
		else
			turk_sort(stack_a, stack_b);
	}
}
