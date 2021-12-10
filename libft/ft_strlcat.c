/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:14:57 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/28 04:53:58 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	char	*s;
	size_t	slen;
	size_t	dlen;

	s = (char *)src;
	slen = ft_strlen(s);
	dlen = ft_strlen(dest);
	if (n < dlen)
		return (slen + n);
	else
	{
		dest = dest + dlen;
		ft_strlcpy(dest, s, n - dlen);
		return (slen + dlen);
	}
}
