/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:21:44 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/24 18:23:00 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*output;
	unsigned char	a;

	output = NULL;
	a = (unsigned char)c;
	if (!a)
		return ((char *)s + ft_strlen(s));
	while (*s != '\0')
		if (*s++ == a)
			output = (char *)(s - 1);
	return (output);
}
