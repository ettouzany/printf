/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:14:35 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/14 01:44:32 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_final_value(t_node *node)
{
	if (node->data->specifier == 's')
		node->data->final_value = ft_s_specifier(node->data);
	else if (node->data->specifier == 'd'
		|| node->data->specifier == 'i' || node->data->specifier == 'u')
		node->data->final_value = ft_d_specifier(node->data);
	else if (node->data->specifier == 'c' || node->data->specifier == '%')
		node->data->final_value = ft_c_specifier(node->data);
	else if (node->data->specifier == 'p')
		node->data->final_value = ft_p_specifier(node->data->o_value,
				node->data->flags, node->data->width);
	else if (node->data->specifier == 'x' || node->data->specifier == 'X')
		node->data->final_value = ft_x_specifier(node->data);
}

char	*add_it_to_last_string(char *last_string, char *adding, int position)
{
	char	*output;

	if (!adding)
		adding = ft_strdup("(null)", 0);
	output = malloc(sizeof(char) * ft_strlen(last_string)
			+ ft_strlen(adding) + 1);
	ft_strlcpy(output, last_string, position + 1);
	ft_strlcat(output, adding, ft_strlen(output)+ft_strlen(adding)+1);
	ft_strlcat(output, last_string + position,
		ft_strlen(last_string)+ft_strlen(adding) + 1);
	return (free(last_string), output);
}

//this function will take a string and return a case from it
// - she will allocate a case and return it
// - if not free return NULL

//! leaks free
t_case	*create_case_from_string(char *str, int place)
{
	t_case		*c;
	int			i;

	c = (t_case *)malloc(sizeof(t_case));
	i = (c->position = 0, c->flags = 0, c->final_value = 0, c->width = 0, -1);
	c->position = (c->o_value = 0, c->specifier = 0, c->precision = 0, place);
	while (is_flag(str[++i]))
		c->flags = ft_join_flags(c->flags, i, str[i]);
	c->width = ft_atoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		c->flags = ft_join_flags(c->flags, ft_strlen(c->flags), str[i]);
		i++;
		c->precision = ft_atoi(str + i);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (is_specifier(str[i]))
		c->specifier = str[i];
	else
		return (free(c), NULL);
	return (c);
}

//this func will fill all the data on start: 
// - last string(striped from cases
// - create a case if she find one by calling create_case_from_string
// - return the number of parameters
//! leaks free
int	ft_fill_data(const char *str, t_node *nodes, char **last_sring)
{
	int		output;
	char	*str_output;
	int		i;
	int		ok;

	output = ((str_output = NULL), i = 0, ok = 1, 0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!ft_add_case(nodes, create_case_from_string((char *)(str + ++i),
					ft_strlen(str_output))))
				return (free(str_output), -1);
			while (!is_specifier(str[i]) && str[i])
				i++;
			output++;
			i += !!str[i];
		}
		else
			str_output = ft_strjoinl(str_output, (char *) &str[i++], 1, 1);
	}
	*last_sring = str_output;
	return (output);
}

void	ft_fill_params(int n_of_pars, t_node **nodes, char **l_s, va_list args)
{
	int		i;
	int		add;
	t_node	*for_storing;

	add = 0;
	i = 0;
	while (i < n_of_pars)
	{
		for_storing = ft_get_node_by_id(nodes, i);
		if (for_storing->data->specifier != '%')
			for_storing->data->o_value = va_arg(args, void *);
		fill_final_value(for_storing);
		*l_s = add_it_to_last_string(*l_s,
				for_storing->data->final_value,
				for_storing->data->position + add);
		add += ft_strlen(for_storing->data->final_value);
		i++;
	}
}
