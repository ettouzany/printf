/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:07:49 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 01:06:45 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_join_flags(char *s, int lenght, char c)
{
	char	*output;
	int		i;

	i = 0;
	output = (char *)malloc(sizeof(char) * lenght + 2);
	if (!output)
		return (NULL);
	while (s && i < lenght)
	{
		output[i] = s[i];
		i++;
	}
	output[i++] = c;
	output[i] = '\0';
	return (free(s), output);
}
