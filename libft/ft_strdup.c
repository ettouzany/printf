/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:55:18 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/24 17:55:42 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*output;

	i = 0;
	while (s1[i])
		i++;
	output = (char *)malloc(i + 1);
	if (!output)
	{
		return (NULL);
	}
	i = 0;
	while (*s1)
	{
		output[i++] = *s1++;
	}
	output[i] = '\0';
	return (output);
}
