/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:51:25 by dlima-li          #+#    #+#             */
/*   Updated: 2026/02/10 15:51:25 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	*stack_addfront(t_stack **stack, t_stack *new)
{
	if (!new)
		return (NULL);
	new->next = *stack;
	*stack = new;
	return (*stack);
}

void	*stack_addback(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return (NULL);
	if (!*stack)
	{
		*stack = new;
		return (NULL);
	}
	last = stack_last(*stack);
	last->next = new;
	return (*stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
