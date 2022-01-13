/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:02:27 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 01:22:16 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"
//! leaks free

char	*ft_d_specifier(void *number_in_hexa, int width, char *f, int p, int l)
{
	char	*output;
	long	num;

	if (l)
		num = (unsigned int)number_in_hexa;
	else
		num = (int)number_in_hexa;
	if (num == 0 && f && ft_strchr(f, '.'))
		output = ft_strdup("", 0);
	else
		output = ft_strdup(ft_itoa(num), 1);
	if (num < 0)
		output = ft_substr(output, 1, ft_strlen(output) - 1, 1);
	while ((int)ft_strlen(output) < p && ft_strchr(f, '.'))
		output = ft_strjoin("0", output, 2);
	if (ft_strchr(f, '0') && !ft_strchr(f, '.'))
		while ((int)ft_strlen(output) < width - ((ft_strchr(f, '+')
					&& !l && num >= 0) || num < 0))
			output = ft_strjoin("0", output, 2);
	if (num < 0)
		output = ft_strjoin("-", output, 2);
	if (ft_strchr(f, '+') && num >= 0 && !l)
		output = ft_strjoin("+", output, 2);
	output = ft_fill_flags_width(output, width, (int)ft_strchr(f, '-'), 0);
	return (output);
}
