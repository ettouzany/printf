/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:28:55 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/24 17:54:28 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*output;

	output = (char *)str;
	c = (unsigned char)c;
	if (!c)
		return (output + ft_strlen(output));
	while (*output != '\0')
		if (*output++ == c)
			return (--output);
	return (NULL);
}
