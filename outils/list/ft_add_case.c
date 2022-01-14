/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:13:19 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 21:16:20 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_outils.h"

int	ft_add_case(t_node	*nodes, t_case *acase)
{
	if (acase)
	{
		if (!nodes->data)
			nodes->data = acase;
		else
			ft_add_node_back(&nodes, ft_creat_node(acase));
		return (1);
	}
	return (0);
}
