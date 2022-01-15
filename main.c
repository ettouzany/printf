/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:33:50 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/14 01:43:09 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_leaks(void);

int	main(void)
{
int t;
	char c;

	c = 'a';
	t = 50;
	ft_printf("%d", ft_printf(" xzcxzcxzc%", &t,0  ),0  );
	return (check_leaks(),0);
}
