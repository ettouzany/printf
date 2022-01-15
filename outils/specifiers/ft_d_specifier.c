/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:02:27 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 23:03:51 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_outils.h"

long	ft_unsined(void *p, int s)
{
	if (s)
		return ((unsigned int)p);
	else
		return ((int)p);
}

//! leaks free
char	*ft_d_specifier(t_case *acas)
{
	char	*output;
	long	num;

	num = ft_unsined(acas->o_value, acas->specifier == 'u');
	if (num == 0 && acas->flags && ft_strchr(acas->flags, '.'))
		output = ft_strdup("", 0);
	else
		output = ft_strdup(ft_itoa(num), 1);
	if (num < 0)
		output = ft_substr(output, 1, ft_strlen(output) - 1, 1);
	while (ft_strlen(output) < acas->precision && ft_strchr(acas->flags, '.'))
		output = ft_strjoin("0", output, 2);
	if (ft_strchr(acas->flags, '0') && !ft_strchr(acas->flags, '.'))
		while (ft_strlen(output) < acas->width - ((ft_strchr(acas->flags, '+')
					&& !(acas->specifier == 'u') && num >= 0) || num < 0))
			output = ft_strjoin("0", output, 2);
	if (num < 0)
		output = ft_strjoin("-", output, 2);
	if (ft_strchr(acas->flags, '+') && num >= 0 && !(acas->specifier == 'u'))
		output = ft_strjoin("+", output, 2);
	if (ft_strchr(acas->flags, ' ') && !ft_strchr(acas->flags, '+')
		&& num >= 0 && !(acas->specifier == 'u'))
		output = ft_strjoin(" ", output, 2);
	output = ft_fill(output, acas->width, (int)ft_strchr(acas->flags, '-'), 0);
	return (output);
}
