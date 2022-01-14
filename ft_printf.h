/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:31:52 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/14 01:34:25 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "outils/ft_printf_outils.h"
# include <stdarg.h>
# include <stdio.h>

int		ft_add_case(t_node	*nodes, t_case *acase);
void	fill_final_value(t_node *t_node);
char	*add_it_to_last_string(char *last_string, char *adding, int position);
t_case	*create_case_from_string(char *str, int place);
int		ft_fill_data(const char *str, t_node *nodes, char **last_sring);
void	ft_fill_params(int n_of_pars, t_node **nodes, char **l_s, va_list args);
int		ft_printf(const char *str, ...);

#endif
