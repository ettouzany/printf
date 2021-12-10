/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:18:45 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/24 18:19:40 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = s1[i] - s2[i];
	if (!n)
		return (0);
	while (i < n)
	{
		j = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (j);
}
