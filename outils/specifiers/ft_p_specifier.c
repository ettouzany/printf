/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:02:31 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 21:43:10 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_outils.h"

char	*ft_p_specifier(void *p, char *flags, int width)
{
	char	*output;

	output = ft_short_hexa_converter(p, 0, 4);
	if (ft_strchr(flags, '0'))
		while ((int)ft_strlen(output) < width - 2)
			output = ft_strjoin("0", output, 2);
	output = ft_for_hash_flag(output, 0);
	output = ft_fill(output, width, (int)ft_strchr(flags, '-'), 0);
	return (output);
}
