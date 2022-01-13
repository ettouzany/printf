/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:49:54 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/12 23:25:08 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	char	*output;

	output = (char *)str;
	if (!output)
		return (NULL);
	c = (unsigned char)c;
	if (!c)
		return (output + ft_strlen(output));
	while (*output != '\0')
		if (*output++ == c)
			return (--output);
	return (NULL);
}
