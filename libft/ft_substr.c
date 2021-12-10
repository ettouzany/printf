/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:24:15 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/24 18:25:09 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	i;
	size_t	lenght;

	i = 0;
	lenght = 0;
	while (s[lenght])
		lenght++;
	if (lenght <= start)
		i = start;
	if (lenght >= start)
		output = malloc(lenght - start + 1);
	else
		output = malloc(1);
	if (!output)
		return (NULL);
	i = 0;
	while (start < lenght && i < len && s[start + i])
	{
		output[i] = s[start + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
