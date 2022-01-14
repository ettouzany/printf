/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:58:56 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 22:39:57 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_outils.h"

char	*ft_substr(char *s, unsigned int start, size_t len, int fre)
{
	char	*output;
	size_t	i;
	size_t	lenght;

	i = ((lenght = 0), 0);
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
	if (fre && s)
		free(s);
	return (output);
}
