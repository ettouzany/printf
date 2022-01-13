/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_hash_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:08:36 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 01:10:14 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_for_hash_flag(char *str, int specifier)
{
	if (!specifier)
		return (ft_strjoin("0x", str, 2));
	else
		return (ft_strjoin("0X", str, 2));
	return (NULL);
}
