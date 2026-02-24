/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:10:52 by dlima-li          #+#    #+#             */
/*   Updated: 2026/02/10 15:10:52 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack *last;
	t_stack *second_last;

	if (!*stack || !(*stack)->next)
		return ;
	second_last = NULL;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack;
	second_last->next = NULL;
	*stack = last;
}

void	rra(t_stack **stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print);
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b, int print)
{
	reverse_rotate(stack_b);
	if (print);
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
