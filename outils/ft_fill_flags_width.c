/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_flags_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:05:46 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/12 23:14:29 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_fill_flags_width(char *output, int width, int space, int zero)
{
	if (space)
		while ((int)ft_strlen(output) < width)
			output = ft_strjoin(output, " ", 1);
	if (zero)
		while ((int)ft_strlen(output) < width)
			output = ft_strjoin("0", output, 2);
	while ((int)ft_strlen(output) < width)
		output = ft_strjoin(" ", output, 2);
	return (output);
}
