/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:24:00 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/24 18:24:04 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	output = NULL;
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	while (ft_strchr(set, *(s1 + ft_strlen(s1) - i - 1)) && *s1)
		i++;
	output = malloc(ft_strlen(s1) - i + 1);
	if (!output)
		return (NULL);
	while (&s1[j] != &s1[ft_strlen(s1) - i])
	{
		output[j] = s1[j];
		j++;
	}
	output[j] = '\0';
	return (output);
}
