/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_hexa_converter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:05:32 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 01:11:39 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_short_hexa_converter(void *p, int is_upper, int dakchi_libaghi)
{
	unsigned long	x;
	char			*buf;
	char			*hexa_base;
	size_t			i;

	x = (unsigned long)p;
	buf = malloc(sizeof(char) * 1);
	if (!buf)
		return (NULL);
	buf[0] = ((i = 0), '\0');
	if (!is_upper)
		hexa_base = ft_strdup("0123456789abcdef", 0);
	else
		hexa_base = ft_strdup("0123456789ABCDEF", 0);
	while (i < sizeof(x) * 2)
	{
		if ((hexa_base[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf] != '0'
				&& i >= (unsigned long)dakchi_libaghi) || i == 15)
		{
			while (i < sizeof(x) * 2)
			{
				ft_strlcat(buf, &hexa_base[(x >> ((sizeof(x)
								* 2 - 1 - i) * 4)) & 0xf], strlen(buf) + 2);
				i++;
			}
		}
		i++;
	}
	return (free(hexa_base), buf);
}
