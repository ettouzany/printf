/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_node_by_id.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:39:45 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 20:33:08 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_outils.h"

t_node	*ft_get_node_by_id(t_node **lst, int index)
{
	int	i;

	i = 0;
	if ((*lst))
	{
		while ((*lst)->next && i != index)
		{
			lst = &(*lst)->next;
			i++;
		}
		return ((*lst));
	}
	return (*lst);
}
