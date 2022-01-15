/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:41:43 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 20:33:08 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_outils.h"

void	ft_lstiter(t_node *lst, void (*f)(void *))
{
	t_node	*tmp;
	t_node	*next;

	if (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			f(tmp->data->flags);
			f(tmp->data->final_value);
			next = tmp->next;
			f(tmp);
			tmp = next;
		}
		f(lst->data->flags);
		f(lst->data->final_value);
		//f(lst);
	}
}
