/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:47:15 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/25 08:06:14 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	dist_lenght;
	size_t	src_lenght;
	size_t	i;

	i = 0;
	s = (char *)src;
	d = (char *)dst;
	dist_lenght = 0;
	src_lenght = 0;
	if ((size_t)(dst - src) < n && (size_t)(dst - src) > 0)
	{
		s = s + n;
		while (n > 0)
			d[--n] = *--s;
	}
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)dst);
}
