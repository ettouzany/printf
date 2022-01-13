/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:02:35 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 01:21:57 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_s_specifier(void *str, char *flags, int width, int presision)
{
	char	*output;
	int		i;

	if (!str)
		output = ft_strdup("(null)", 0);
	else
		output = ft_strdup(str, 0);
	i = (int)ft_strlen(output);
	if (ft_strchr(flags, '.') && i > presision)
	{
		output[presision] = '\0';
	}
	output = ft_fill_flags_width(output, width, (int)ft_strchr(flags, '-'), 0);
	return (output);
}
