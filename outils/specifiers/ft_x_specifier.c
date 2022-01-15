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

char	*ft_x_specifier(t_case *acase)
{
	char	*output;

	output = ft_short_hexa_converter(acase->o_value,
			acase->specifier == 'X', 8);
	if (output[0] == '0' && (ft_strchr(acase->flags, '0')
			|| ft_strchr(acase->flags, '.')) && acase->width == 0)
		output = (free(output), ft_strdup("", 0));
	output = ft_fill(output, acase->width, (int)ft_strchr(acase->flags, '-'),
			(int)ft_strchr(acase->flags, '0'));
	return (output);
}
