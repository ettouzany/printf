/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: net-touz <net-touz@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/11/24 17:03:44 by net-touz		  #+#	#+#			 */
/*   Updated: 2021/11/24 17:04:25 by net-touz		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int	count(int nb)
{
	int	count;

	count = 0;
	if (nb < 1)
	{
		nb *= -1;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static void	fill_array(char *array, int n, int len)
{
	int	a;

	a = n;
	if (n < 0)
	{
		n *= -1;
	}
	array[len] = '\0';
	while (len)
	{
		array[--len] = (n % 10 + 48);
		n = n / 10;
		if (a < 0)
			array[0] = '-';
	}
}

char	*ft_itoa(int n)
{
	char	*array;
	int		len;

	len = count(n);
	array = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	array = malloc(len + 1);
	if (!array)
		return (NULL);
	fill_array(array, n, len);
	return (array);
}
