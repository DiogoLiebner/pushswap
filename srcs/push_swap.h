/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:23:27 by dlima-li          #+#    #+#             */
/*   Updated: 2026/04/21 16:23:31 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	push(t_stack **dest, t_stack **src);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);
void	pa(t_stack **stack_a, t_stack **stack_b, int print);
void	pb(t_stack **stack_a, t_stack **stack_b, int print);
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);

int		stack_size(t_stack *stack);
void	*stack_addfront(t_stack **stack, t_stack *new);
void	*stack_addback(t_stack **stack, t_stack *new);
void	free_stack(t_stack **stack);
t_stack	*stack_new(long value);
t_stack	*stack_last(t_stack *stack);

int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_position(t_stack *stack, int value);

int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
int		ft_strcmp(char *str1, char *str2);
void	error_exit(void);
void	ft_putstr_fd(char *str, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
int		ft_delimcheck(char s, char delim);
void	*ft_free(char **strs, int count);
char	*ft_strndup(const char *src, char delim);
int		ft_wordcount(const char *str, char c);

int		is_valid_number(char *str);
long	ft_atol(char *str);
int		input_errorcheck(char *args);
void	free_error(t_stack **stack, char **args);
void	init_stack(t_stack **stack, int argc, char **argv);

void	sort_three(t_stack **stack_a);
void	push_min_to_b(t_stack **stack_a, t_stack **stack_b);
void	sort_small(t_stack **stack_a, t_stack **stack_b);
int		find_target_pos(t_stack *stack_a, int value);
int		calc_cost(t_stack *stack_a, t_stack *stack_b,
			int pos_b, int targ_pos_a);
void	find_cheap(t_stack *stack_a, t_stack *stack_b,
			int *bestp_b, int *besttarg_a);
void	rot_both(t_stack **stack_a, t_stack **stack_b,
			int *pos_a, int *pos_b);
void	rrot_both(t_stack **stack_a, t_stack **stack_b,
			int *pos_a, int *pos_b);

void	rotate_to_top(t_stack **stack, int pos, int is_a);
void	push_to_b(t_stack **stack_a, t_stack **stack_b);
void	final_rotation(t_stack **stack_a);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

#endif
