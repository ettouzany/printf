/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_with_lenght.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:50:03 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/12 21:54:20 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_strjoin_with_lenght(char *s1, char *s2, int lenght, int fre)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	output = malloc(sizeof(char) * ft_strlen(s1) + lenght + 1);
	if (!output)
		return (NULL);
	while (s1[i]){

		output[i] = s1[i];
		i++;
}
	while (j < lenght)
	{
		output[i++] = s2[j++];
	}
	output[i] = '\0';
		if(fre==1 && s1)
	{
		free(s1);
	}else if(fre==2 && s2)
		free(s2);
	return ( output);
}