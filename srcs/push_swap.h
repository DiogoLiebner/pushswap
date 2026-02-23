/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:23:11 by dlima-li          #+#    #+#             */
/*   Updated: 2026/02/09 15:23:11 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
    int				value;
	int				index;
	struct s_stack	*next;
} t_stack;

void	push(t_stack **dest, t_stack **src);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, int print);
void 	pa(t_stack **stack_a, t_stack **stack_b, int print);
void	pb(t_stack **stack_a, t_stack **stack_b, int print);
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);

int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);
void	*stack_addfront(t_stack **stack, t_stack *new);
void	*stack_addback(t_stack **stack, t_stack *new);
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);

int			has_duplicates(t_stack *stack);
int			is_sorted(t_stack *stack);
int			ft_strcmp(char *str1, char *str2);
void		error_exit(void);
void		ft_putstr_fd(char *str, int fd);
void		*ft_calloc(size_t nmemb, size_t size);
char		**ft_split(char const *s, char c);
static int		ft_delimcheck(char s, char delim);
static void		*ft_free(char **strs, int count);
static char		*ft_strndup(const char *src, char delim);
static int		*ft_wordcount(const char *str, char c);

int		is_valid_number(char *str);
long	ft_atol(char *str);
void	input_errorcheck(char *args);
void	init_stack(t_stack **stack, int argc, char **argv);

void	sort_three(t_stack **stack);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
int		find_target_pos(t_stack *stack_a, int value);
int		calc_cost(t_stack *stack_a, t_stack *stack_b, int pos_b, int targ_pos_a);
void	find_cheapest(t_stack *stack_a, t_stack *stack_b, int *best_pos_b, int *best_target_a);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_small(t_stack **stack_a, t_stack **stack_b);
static void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)

#endif