/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:25:33 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 20:33:08 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_outils.h"

void	ft_add_node_back(t_node **lst, t_node *new)
{
	if ((*lst))
	{
		while ((*lst)->next)
		{
			lst = &(*lst)->next;
		}
		(*lst)->next = new;
	}
	else
		(*lst) = new;
}
