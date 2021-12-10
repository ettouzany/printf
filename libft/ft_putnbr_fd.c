/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:48:38 by net-touz          #+#    #+#             */
/*   Updated: 2021/11/26 18:52:15 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// int	ft_numtobyte(int n)
// {
// 	int	i;

// 	i = 1;
// 	while (n >= 10)
// 	{
// 		n = n / 10;
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_mypow(int numtobyte)
// {
// 	int	i;

// 	i = 1;
// 	while (--numtobyte)
// 	{
// 		i *= 10;
// 	}
// 	return (i);
// }

// void	ft_putnbr_fd(int n, int fd)
// {
// 	int		is_negative;
// 	int		numtobyte;
// 	int		i;
// 	char	c;
// 	int		is_maxint;

// 	c = 0;
// 	is_negative = 0;
// 	is_maxint = 0;
// 	i = 0;
// 	if (n < 0)
// 	{
// 		is_negative = 1;
// 		if (n == -2147483648 && n++)
// 			is_maxint = 1;
// 		n *= -1;
// 		numtobyte = ft_numtobyte(n);
// 	}
// 	else
// 		numtobyte = ft_numtobyte(n);
// 	if (is_negative)
// 		write(fd, "-", 1);
// 	while (n >= 10)
// 	{
// 		c = n / ft_mypow(numtobyte) + 48;
// 		write(fd, &c, 1);
// 		n = n % ft_mypow(numtobyte--);
// 	}
// 	c = n % 10 + 48 + is_maxint;
// 	write(fd, &c, 1);
// }

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == (-2147483648) || n == 0)
	{
		if (n)
			write(fd, "-2147483648", 11);
		else
			write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", (n *= -1, 1));
	}
	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	else
	{
		c = (n % 10) + 48;
		ft_putnbr_fd(n / 10, fd);
		write(fd, &c, 1);
	}
}
