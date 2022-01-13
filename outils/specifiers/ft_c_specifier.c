/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:55:32 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 01:22:18 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_c_specifier(void *c, char *flags, int width, int is_precentage)
{
	char	*output;

	output = malloc(sizeof(char) * 2);
	if (!output)
		return (NULL);
	output[0] = (char)c;
	output[1] = '\0';
	if (is_precentage)
		output[0] = '%';
	output = ft_fill_flags_width(output, width, (int)ft_strchr(flags, '-'),
			(int)ft_strchr(flags, '0'));
	return (output);
}
