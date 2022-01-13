/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:17:46 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 01:51:20 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

t_node		*ft_creat_node(t_case *data)
{
	t_node		*new;

	new = malloc(sizeof(t_node));
	if(!new)
		return NULL;
	new->data = data;
	new->next = NULL;
	return (new);
}
