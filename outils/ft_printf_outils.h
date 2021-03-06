/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_outils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:31:52 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/13 23:04:50 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_OUTILS_H
# define FT_PRINTF_OUTILS_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_case
{
	char	*flags;
	char	specifier;
	int		width;
	int		precision;
	int		position;
	void	*o_value;
	char	*final_value;
}	t_case;

typedef struct s_node
{
	t_case			*data;
	struct s_node	*next;
}	t_node;

char	*ft_fill(char *output, int width, int space, int zero);
char	*ft_join_flags(char *s, int lenght, char c);
char	*ft_short_hexa_converter(void *p, int is_upper, int dakchi_libaghi);
char	*ft_for_hash_flag(char *str, int specifier);

int		is_flag(char c);
int		is_specifier(char c);

char	*ft_c_specifier(t_case *acase);
char	*ft_d_specifier(t_case *acase);
char	*ft_p_specifier(void *p, char *flags, int width);
char	*ft_s_specifier(t_case *acase);
char	*ft_x_specifier(t_case *acase);

void	ft_lstiter(t_node *lst, void (*f)(void *));
t_node	*ft_get_node_by_id(t_node **lst, int index);
t_node	*ft_creat_node(t_case *data);
void	ft_add_node_back(t_node **lst, t_node *new);
int		ft_add_case(t_node	*nodes, t_case *acase);

char	*ft_strjoinl(char *s1, char *s2, int lenght, int fre);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen(const char *s);
char	*ft_strdup(char *s1, int fre);
char	*ft_substr(char *s, unsigned int start, size_t len, int fre);
int		ft_atoi(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2, int fre);
char	*ft_strchr(const char *str, int c);
char	*ft_itoa(long n);

#endif
