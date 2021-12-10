/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:38:28 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/24 17:47:40 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*output;

	i = 0;
	output = (char *)str;
	while (i < n)
	{
		output[i++] = c;
	}
	return (str);
}
