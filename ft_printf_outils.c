/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:14:35 by net-touz          #+#    #+#             */
/*   Updated: 2021/12/29 15:41:32 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_lenght;
	size_t	i;

	i = 0;
	src_lenght = 0;
	while (src[src_lenght])
		src_lenght++;
	if (!dstsize)
		return (src_lenght);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (src_lenght);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	while (*s++ != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*output;

	i = 0;
	while (s1[i])
		i++;
	output = (char *)malloc(i + 1);
	if (!output)
	{
		return (NULL);
	}
	i = 0;
	while (*s1)
	{
		output[i++] = *s1++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	i;
	size_t	lenght;

	i = 0;
	lenght = 0;
	while (s[lenght])
		lenght++;
	if (lenght <= start)
		i = start;
	if (lenght >= start)
		output = malloc(lenght - start + 1);
	else
		output = malloc(1);
	if (!output)
		return (NULL);
	i = 0;
	while (start < lenght && i < len && s[start + i])
	{
		output[i] = s[start + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

int	ft_atoi(const char *str)
{
	int	out;
	int	sign;

	out = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		out = out * 10 + *str++ - '0';
	return (sign * out);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	char	*s;
	size_t	slen;
	size_t	dlen;

	s = (char *)src;
	slen = ft_strlen(s);
	dlen = ft_strlen(dest);
	if (n < dlen)
		return (slen + n);
	else
	{
		dest = dest + dlen;
		ft_strlcpy(dest, s, n - dlen);
		return (slen + dlen);
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	i;

	i = 0;
	output = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!output)
		return (NULL);
	while (*s1)
		output[i++] = *s1++;
	while (*s2)
		output[i++] = *s2++;
	output[i] = '\0';
	return (output);
}

char	*ft_strchr(const char *str, int c)
{
	char	*output;

	output = (char *)str;
	c = (unsigned char)c;
	if (!c)
		return (output + ft_strlen(output));
	while (*output != '\0')
		if (*output++ == c)
			return (--output);
	return (NULL);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}


//itoa
static int	count(long nb)
{
	long	count;

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

//itoa
static void	fill_array(char *array, long n, int len)
{
	long	a;

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

char	*itoa(long n)
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
