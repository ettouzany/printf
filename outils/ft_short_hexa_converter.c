/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_hexa_converter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:05:32 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/14 01:49:08 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_strlcats(char *dest, char zap)
{
	char *output = dest;
	int i = 0;
	dest = malloc(sizeof(char) * ft_strlen(dest)+2);
	while (output[i])
	{
		dest[i] = output[i];
		i++;
	}
	dest[i++] = zap;
	dest[i] = '\0';
}



char	*ft_short_hexa_converter(void *p, int is_upper, int dakchi_libaghi)
{
	unsigned long	x;
	char			*buf;
	char			*hexa_base;
	size_t			i;

	char hexa_zapi;
	buf = malloc(sizeof(char) * 1);
	if (!buf)
		return (NULL);
	buf[0] = ((i = -1), x = (unsigned long)p, '\0');
	if (!is_upper && (unsigned long)dakchi_libaghi)
		hexa_base = ft_strdup("0123456789abcdef", 0);
	else
		hexa_base = ft_strdup("0123456789ABCDEF", 0);
	while (++i < sizeof(x) * 2)
	{
		hexa_zapi = hexa_base[(x >> ((sizeof(x) * 2 - 1 - i) * dakchi_libaghi)) & 0xf];
		printf("%c",hexa_zapi);
		if ((hexa_zapi != '0' && i >= (unsigned long)dakchi_libaghi) || i == 15)
		{
			while (i < sizeof(x) * 2)
			{
				ft_strlcats(buf, hexa_base[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf]);
				i++;
			}
		}
	}
	printf("\n");

	return (free(hexa_base), buf);
}
