/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:29:59 by dlima-li          #+#    #+#             */
/*   Updated: 2026/02/09 15:29:59 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
if (!is_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sa(&stack_a, 1);
		else if (stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else if (stack_size(stack_a) <= 5)
			sort_small(&stack_a, &stack_b);
		else
			sort_large(&stack_a, &stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		return (0);
	}
	initstack(&stack_a, argc, argv);
	if (!stack_a || has_duplicates(stack_a))
	{
		free_stack(&stack_a);
		error_exit();
	}
	sort_stack(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
