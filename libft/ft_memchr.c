/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:12:12 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/25 12:24:57 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	size_t	find;
	char	*str;

	i = 0;
	find = 0;
	str = (char *)s;
	while (str[i] != (char)c && i < n)
		i++;
	if (str[i] == (char)c && n != i)
		return (str + i);
	else
		return (NULL);
}
