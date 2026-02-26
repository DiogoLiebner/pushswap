/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:58:49 by dlima-li          #+#    #+#             */
/*   Updated: 2026/02/26 22:33:28 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

void	input_errorcheck(char *args)
{
	long	num;

	if (!is_valid_number(args))
	{
		free(args);
		error_exit();
	}
	num = ft_atol(args);
	if (num > INT_MAX || num < INT_MIN)
	{
		free(args);
		error_exit();
	}
}

void	init_stack(t_stack **stack, int argc, char **argv)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		j = 0;
		while (args[j])
		{
			input_errorcheck(args[j]);
			stack_addback(stack, stack_new(ft_atol(args[j])));
			j++;
		}
		j = 0;
		while (args[j])
			free(args[j++]);
		free(args);
		i++;
	}
}
