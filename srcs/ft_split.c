/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:17:32 by dlima-li          #+#    #+#             */
/*   Updated: 2026/04/21 16:23:01 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_delimcheck(char s, char delim)
{
	return (s == delim);
}

void	*ft_free(char **strs, int count)
{
	while (count > 0)
		free(strs[--count]);
	if (strs[0])
		free(strs[0]);
	free(strs);
	return (NULL);
}

char	*ft_strndup(const char *src, char delim)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!src)
		return (NULL);
	while (src[len] && !(ft_delimcheck(src[len], delim)))
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_wordcount(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_delimcheck(*str, c))
			str++;
		if (*str)
		{
			count++;
			while (*str && !ft_delimcheck(*str, c))
				str++;
		}
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**arrres;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	arrres = ft_calloc(ft_wordcount(s, c) + 1, sizeof(char *));
	if (!arrres)
		return (NULL);
	while (*s)
	{
		while (*s && ft_delimcheck(*s, c))
			s++;
		if (*s)
		{
			arrres[i] = ft_strndup(s, c);
			if (!(arrres[i]))
				return (ft_free(arrres, i - 1));
			i++;
			while (*s && !ft_delimcheck(*s, c))
				s++;
		}
	}
	arrres[i] = NULL;
	return (arrres);
}
