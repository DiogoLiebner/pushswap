/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:29:46 by dlima-li          #+#    #+#             */
/*   Updated: 2026/02/09 17:29:46 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	while (i < nmemb * size)
		dest[i++] = '\0';
	return (dest);
}
