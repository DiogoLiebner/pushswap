/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:35:09 by dlima-li          #+#    #+#             */
/*   Updated: 2026/02/09 15:35:09 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (!*stack || !(*stack)->next)
	return ;
	fist = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack_a, int print)
{
	swap(stack_a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b, int print)
{
	swap (stack_a);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		fd_putstr_fd("ss\n", 1);
}
