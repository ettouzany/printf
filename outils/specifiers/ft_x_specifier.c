/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:02:38 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 20:33:08 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_outils.h"

char	*ft_x_specifier(void *number_in_hexa, int width, char *flags, int upr)
{
	char	*output;

	output = ft_short_hexa_converter(number_in_hexa, upr, 8);
	if (ft_strchr(flags, '0'))
		while ((int)ft_strlen(output) < width - ((number_in_hexa
					&& flags && ft_strchr(flags, '#')) * 2))
			output = ft_strjoin("0", output, 2);
	if (number_in_hexa && flags && ft_strchr(flags, '#'))
	{
		output = ft_for_hash_flag(output, upr);
	}
	if ((flags && !ft_strchr(flags, '0') && !ft_strchr(flags, '-')) || !flags)
		while ((int)ft_strlen(output) < width - ((number_in_hexa
					&& flags && ft_strchr(flags, '#')) * 2))
			output = ft_strjoin(" ", output, 2);
	while ((int)ft_strlen(output) < width - ((number_in_hexa
				&& flags && ft_strchr(flags, '#')) * 2))
			output = ft_strjoin(output, " ", 1);
	return (output);
}
