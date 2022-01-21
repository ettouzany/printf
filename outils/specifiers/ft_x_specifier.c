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
	int		ori;

	ori = 0;
	output = ft_short_hexa_converter(acase->o_value,
			acase->specifier == 'X', 8);
	if (output[0] == '0' && (ft_strchr(acase->flags, '0')
			|| ft_strchr(acase->flags, '.')))
		output = (free(output), ft_strdup("", 0));
	else
			ori = ft_strlen(output);
	while (ft_strlen(output) < acase->precision && ft_strchr(acase->flags, '.'))
		output = ft_strjoin("0", output, 2);
	output = ft_fill(output, acase->width, (int)ft_strchr(acase->flags, '-'),
			(int)ft_strchr(acase->flags, '0')
			&& !(int)ft_strchr(acase->flags, '.'));
	return (output);
}
