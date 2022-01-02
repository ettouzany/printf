/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:31:52 by net-touz          #+#    #+#             */
/*   Updated: 2021/12/29 15:25:20 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
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
	void	*original_value;
	char	*final_value;
}	t_case;

typedef struct s_node
{
	t_case			*data;
	struct s_node	*next;
}	t_node;

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
void	ft_putstr_fd(char *s, int fd);
char	*itoa(long n);
#endif
