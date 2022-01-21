/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:23:32 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/14 01:43:48 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_node	*nodes;
	char	*last_string;
	int		number_of_parameters;
	va_list	args;
	int		rtrn;

	rtrn = 0;
	nodes = ((last_string = NULL), ft_creat_node(NULL));
	number_of_parameters = ft_fill_data(str, nodes, &last_string);
	if (number_of_parameters == -1)
		return (free(nodes), -1);
	va_start(args, str);
	if (!last_string)
		last_string = ft_strdup("", 0);
	rtrn += ft_fill_params(number_of_parameters, &nodes, &last_string, args);
	if (number_of_parameters)
		ft_lstiter(nodes, free);
	free(nodes);
	rtrn += ft_strlen(last_string);
	free(last_string);
	return (va_end(args), rtrn);
}
