/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:10:53 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/26 05:14:04 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*output;
	t_list	*new;

	output = NULL;
	while (lst && f)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			return (ft_lstclear(&output, del), NULL);
		ft_lstadd_back(&output, new);
		lst = lst->next;
	}
	return (output);
}
