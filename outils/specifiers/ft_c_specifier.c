/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:55:32 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 23:03:51 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_outils.h"

char	*ft_c_specifier(t_case *acase)
{
	char	*output;

	output = malloc(sizeof(char) * 2);
	if (!output)
		return (NULL);
	output[0] = (char)acase->o_value;
	output[1] = '\0';
	if (acase->specifier == '%')
		output[0] = '%';
	output = ft_fill(output, acase->width - !output[0],
			(int)ft_strchr(acase->flags, '-'),
			(int)ft_strchr(acase->flags, '0'));
	return (output);
}
