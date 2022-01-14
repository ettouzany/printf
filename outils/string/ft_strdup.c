/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:58:26 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 20:33:08 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_outils.h"

char	*ft_strdup(char *s1, int fre)
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
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = '\0';
	if (fre && s1)
		free(s1);
	return (output);
}
