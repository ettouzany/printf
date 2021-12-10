/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:52:32 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/26 05:10:17 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	size_t	words;
	size_t	i;

	i = 0;
	words = ft_words(s, c);
	output = (char **)malloc(sizeof(char *) * (words + 1));
	if (!output)
		return (NULL);
	while (i < words)
	{
		while (*s == c)
			s++;
		output[i] = malloc(ft_strlen(s) - ft_strlen(ft_strchr(s, c)) + 1);
		if (!output[i])
		{
			while (i >= 0)
				free(output[i--]);
			return (free(output), NULL);
		}
		ft_strlcpy(output[i], s, ft_strlen(s) - ft_strlen(ft_strchr(s, c)) + 1);
		i++;
		s = ft_strchr(s, c) + 1;
	}
	return ((output[i] = (NULL)), output);
}
