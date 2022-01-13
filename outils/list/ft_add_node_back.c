/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:25:33 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 01:51:34 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

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
