/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:23:32 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 01:44:07 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

#define NDO t_node->data->original_value 

int	ft_add_case(t_node	*nodes, t_case *acase)
{
	if (acase)
	{
		if (!nodes->data)
			nodes->data = acase;
		else
			ft_add_node_back(&nodes, ft_creat_node(acase));
		return (1);
	}
	return (0);
}

void	fill_final_value(t_node *t_node)
{
	if(t_node->data->specifier == 's')
		t_node->data->final_value = ft_s_specifier((char *)NDO,t_node->data->flags, t_node->data->width,t_node->data->precision);
	else if(t_node->data->specifier == 'd' || t_node->data->specifier == 'i'  || t_node->data->specifier == 'u')
		t_node->data->final_value = ft_d_specifier(NDO, t_node->data->width, t_node->data->flags,t_node->data->precision,t_node->data->specifier == 'u');
	else if(t_node->data->specifier == 'c' || t_node->data->specifier == '%')
		t_node->data->final_value = ft_c_specifier(NDO, t_node->data->flags, t_node->data->width, t_node->data->specifier == '%');
	else if(t_node->data->specifier == 'p')
		t_node->data->final_value = ft_p_specifier(NDO,t_node->data->flags , t_node->data->width);
	else if(t_node->data->specifier == 'x' || t_node->data->specifier == 'X')
		t_node->data->final_value = ft_x_specifier(NDO, t_node->data->width, t_node->data->flags,t_node->data->specifier == 'X');
}

char	*add_it_to_last_string(char *last_string, char *adding, int position)
{
	char	*output;

	if (!adding)
		adding = ft_strdup("(null)", 0);
	output = malloc(sizeof(char) * ft_strlen(last_string) + ft_strlen(adding) + 1);
	ft_strlcpy(output, last_string, position + 1);
	ft_strlcat(output, adding, ft_strlen(output)+ft_strlen(adding)+1);
	ft_strlcat(output, last_string + position, ft_strlen(last_string)+ft_strlen(adding) + 1);
	return (free(last_string), output);
}

//this function will take a string and return a case from it
// - she will allocate a case and return it
// - if not free return NULL

//! leaks free
t_case	*create_case_from_string(char *str, int place)
{
	t_case		*acase;
	int			i;

	i = 0;
	acase = (t_case *)malloc(sizeof(t_case));
	acase->position = place;
	acase->flags = 0;
	acase->final_value = 0;
	acase->original_value = 0;
	acase->specifier = 0;
	acase->width = 0;
	acase->precision = 0;
	while (is_flag(str[i]))
	{
		acase->flags = ft_join_flags(acase->flags, i, str[i]);
		i++;
	}
	acase->width = ft_atoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		acase->flags = ft_join_flags(acase->flags, ft_strlen(acase->flags), str[i]);
		i++;
		acase->precision = ft_atoi(str + i);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (is_specifier(str[i]))
		acase->specifier = str[i];
	else
		return (free(acase), NULL);
	return (acase);
}

//this func will fill all the data on start: 
// - last string(striped from cases
// - create a case if she find one by calling create_case_from_string
// - return the number of parameters
//! leaks free
int		ft_fill_data(const char *str, t_node *nodes,char **last_sring)
{
	int		output;
	char	*str_output;
	int		i;
	int		j;

	output = 0;
	str_output = NULL;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			j = 0;
			if (ft_add_case(nodes, create_case_from_string((char *)(str + i), ft_strlen(str_output))))
			{
				while (!is_specifier(str[i]))
					i++;
				output++;
				if (str[i])
					i++;
			}
			else
			{
				return (-1);
			}
		}
		else
			str_output = ft_strjoin_with_lenght(str_output, (char *) &str[i++], 1, 1);
	}
	*last_sring = str_output;
	if (!str_output)
		return (-1);
	return (output);
}

int	ft_printf(const char *str, ...)
{
	t_node	*nodes;
	t_node	*for_storing;
	char	*last_string;
	int		number_of_parameters;
	int		i;
	int		add;
	va_list	args;

	nodes = ft_creat_node(NULL);
	last_string = NULL;
	i = 0;
	add = 0;
	number_of_parameters = ft_fill_data(str, nodes, &last_string);
	if (number_of_parameters == -1)
		return (free(nodes), -1);
	va_start(args, str);
	if (!last_string)
		last_string = ft_strdup("", 0);
	while (i < number_of_parameters)
	{
		for_storing = ft_get_node_by_id(&nodes, i);
		if (for_storing->data->specifier != '%')
			for_storing->data->original_value = va_arg(args, void *);
		fill_final_value(for_storing);
		last_string = add_it_to_last_string(last_string, for_storing->data->final_value, for_storing->data->position + add);
		add += ft_strlen(for_storing->data->final_value);
		i++;
	}
	ft_putstr((char *)last_string);
	free(last_string);
	if (number_of_parameters)
		ft_lstiter(nodes, free);
	// free(nodes);
	va_end(args);
	return (0);
}
