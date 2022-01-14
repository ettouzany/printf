/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:50:03 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 22:39:07 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_outils.h"

char	*ft_strjoinl(char *s1, char *s2, int lenght, int fre)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	output = malloc(sizeof(char) * ft_strlen(s1) + lenght + 1);
	if (!output)
		return (NULL);
	while (s1 && s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (j < lenght)
		output[i++] = s2[j++];
	output[i] = '\0';
	if (fre == 1 && s1)
		free(s1);
	else if (fre == 2 && s2)
		free(s2);
	return (output);
}
