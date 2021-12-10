/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:21:14 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/24 18:21:27 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < n)
		{
			if (s2[j] == '\0')
				break ;
			j++;
		}
		if (s2[j] == '\0')
		{
			return ((char *)s1 + i);
		}
		i++;
	}
	if (!s1[0] && !s2[0])
		return ((char *)s1);
	return (NULL);
}
