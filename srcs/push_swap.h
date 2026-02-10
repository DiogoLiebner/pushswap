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

static void	push(t_stack **dest, t_stack **src);
static void	swap(t_stack **stack);
static void	rotate(t_stack **stack);
static void	reverse_rotate(t_stack **stack);

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

int			has_duplicates(t_stack *stack);
int			is_sorted(t_stack *stack);
int			ft_strcmp(char *str1, char *str2);
void		error_exit(void);
void		ft_putstr_fd(char *str, int fd);
void		*ft_calloc(size_t nmemb, size_t size);
char		**ft_split(char const *s, char c);
static int	ft_delimcheck(char s, char delim);
static void	ft_free(char **strs, int count);
static char	*ft_strndup(const char *src, char delim);
static int	*ft_wordcount(const char *str, char c);


#endif