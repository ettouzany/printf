/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:14:35 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/12 23:33:15 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char	*final_precision(char *str, int precision)
// {
// 	return (ft_substr(str, ft_strlen(str) - 8, 8 + precision, 0));
// }

// char * write_ptr(void *p) {
// 	unsigned long x = (unsigned long)p;
// 	char *buf;
// 	size_t i;
// 	buf = malloc(sizeof(char) * 3);

// 	buf[0] = '0';
// 	buf[1] = 'x';
// 	buf[2] = '\0';
// 	i =0;
// 	while (i < sizeof(x) * 2)
// 	{
// 		ft_strlcat(buf, &"0123456789abcdef"
// [(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf], ft_strlen(buf)+2);
// 		i++;
// 	}
// 	return buf;
// }

// char *for_width(char *str, int width, int is_zero)
// {
// 	char *output;
// 	output = str;
// 	if(is_zero)
// 		while ((int)ft_strlen(output) < width)
// 			output = ft_strjoin("0",output);
// 	if(!is_zero)
// 		while ((int)ft_strlen(output) < width)
// 			output = ft_strjoin(" ",output);
// 	return (output);
// }
// char *handel_width(char* str, )
// {
// }

// char * hexa_converter(void *p, int is_upper) {
// 	unsigned long x = (unsigned long)p;
// 	char *buf = malloc(sizeof(char) * 1);
// 	char *hexa_base;
// 	buf[0]='\0';
// 	size_t i;
// 	i = 0;
// 	if(!is_upper)
// 		hexa_base = ft_strdup("0123456789abcdef",0);
// 	else
// 		hexa_base = ft_strdup("0123456789ABCDEF",0);

// 	while (i < sizeof(x) * 2)
// 	{
// 		if(hexa_base[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf] != '0')
// 		{
// 			while (i < sizeof(x) * 2)
// 			{
// 				ft_strlcat(buf, &hexa_base[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) 
//                  & 0xf],strlen(buf)+2);
// 				i++;
// 			}
// 		}
// 		i++;
// 	}
// 	return buf;
// }
