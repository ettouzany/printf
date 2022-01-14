/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:02:35 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 23:03:51 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_outils.h"

char	*ft_s_specifier(t_case *acase)
{
	char	*output;
	int		i;

	if (!acase->o_value)
		output = ft_strdup("(null)", 0);
	else
		output = ft_strdup((char *)acase->o_value, 0);
	i = (int)ft_strlen(output);
	if (ft_strchr(acase->flags, '.') && i > acase->precision)
	{
		output[acase->precision] = '\0';
	}
	output = ft_fill(output, acase->width,
			(int)ft_strchr(acase->flags, '-'), 0);
	return (output);
}
