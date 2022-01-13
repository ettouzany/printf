/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:41:34 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 01:09:43 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_strjoin(char *s1, char *s2, int fre)
{
	char	*output;
	size_t	i;

	i = 0;
	output = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!output)
		return (NULL);
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}	
	while (s2[i - ft_strlen(s1)])
	{
		output[i] = s2[i - ft_strlen(s1)];
		i++;
	}	
	output[i] = '\0';
	if (fre == 1 && s1)
		free(s1);
	else if (fre == 2 && s2)
		free(s2);
	return (output);
}
