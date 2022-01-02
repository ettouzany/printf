/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:23:32 by net-touz          #+#    #+#             */
/*   Updated: 2022/01/02 19:02:20 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int	is_specifier(char c)
{
	if (
		c == 'c'
		|| c == 's'
		|| c == 'p'
		|| c == 'd'
		|| c == 'i'
		|| c == 'u'
		|| c == 'x'
		|| c == 'X'
		|| c == '%')
		return (1);
	return (0);
}

char	*final_precision(char *str, int precision)
{
	return (ft_substr(str, ft_strlen(str) - 8, 8 + precision));
}

int	is_flag(char c)
{
	if (
		c == '#'
		|| c == ' '
		|| c == '0'
		|| c == '+'
		|| c == '-'
	)
		return (1);
	return (0);
}

char	*my_strjoin(char *s1, char *s2, int lenght)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if(!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	output = malloc(sizeof(char) * ft_strlen(s1) + lenght + 1);
	if (!output)
		return (NULL);
	while (s1[i])
		output[i] = s1[i++];
	while (j < lenght)
	{
		output[i++] = s2[j++];
	}
	output[i] = '\0';
	return (free(s1), output);
}

char	*join_flags(char *s, int lenght, char c)
{
	char	*output;
	int		i;

	i = 0;
	output = (char *)malloc(sizeof(char) * lenght + 2);
	if(!output)
		return(NULL);
	while (s && i < lenght)
	{
		output[i] = s[i];
		i++;
	}
	output[i++] = c;
	output[i] = '\0';
	return (free(s), output);
}



t_node		*creat_t_node(t_case *data)
{
	t_node		*new;

	new = malloc(sizeof(t_node));
	if(!new)
		return NULL;
	new->data = data;
	new->next = NULL;
	return (new);
}

t_node		*get_node_by_id(t_node **lst, int index)
{
	int	i;

	i = 0;
	if ((*lst))
	{
		while ((*lst)->next && i != index)
		{
			lst = &(*lst)->next;
			i++;
		}
		return ((*lst));
	}
	return (*lst);
}

void	add_t_node_back(t_node **lst, t_node *new)
{
	if ((*lst))
	{
		while ((*lst)->next)
		{
			lst = &(*lst)->next;
		}
		(*lst)->next = new;
	}
	else
		(*lst) = new;
}






char * write_ptr(void *p) {
	unsigned long x = (unsigned long)p;
	char *buf;
	size_t i;
	buf = malloc(sizeof(char) * 3);

	buf[0] = '0';
	buf[1] = 'x';
	buf[2] = '\0';
	i =0;
	while (i < sizeof(x) * 2)
	{
		ft_strlcat(buf, &"0123456789abcdef"[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf], ft_strlen(buf)+2);
		i++;
	}
	return buf;
}
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

char * hexa_converter(void *p, int is_upper) {
	unsigned long x = (unsigned long)p;
	char *buf = malloc(sizeof(char) * 1);
	char *hexa_base;
	buf[0]='\0';
	size_t i;
	i = 0;
	if(!is_upper)
		hexa_base = ft_strdup("0123456789abcdef");
	else
		hexa_base = ft_strdup("0123456789ABCDEF");

	while (i < sizeof(x) * 2)
	{
		if(hexa_base[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf] != '0')
		{
			while (i < sizeof(x) * 2)
			{
				ft_strlcat(buf, &hexa_base[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf],strlen(buf)+2);
				i++;
			}
		}
		i++;
	}
	return buf;
}

char * short_hexa_converter(void *p, int is_upper,int dakchi_libaghi) {
	unsigned long x = (unsigned long)p;
	char *buf = malloc(sizeof(char) * 1);
	char *hexa_base;
	buf[0]='\0';
	size_t i;
	i = 0;
	if(!is_upper)
		hexa_base = ft_strdup("0123456789abcdef");
	else
		hexa_base = ft_strdup("0123456789ABCDEF");

	while (i < sizeof(x) * 2)
	{
		if((hexa_base[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf] != '0' && i>=(unsigned long)dakchi_libaghi) || i == 15)
		{
			while (i < sizeof(x) * 2)
			{
				ft_strlcat(buf, &hexa_base[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf],strlen(buf)+2);
				i++;
			}
		}
		i++;
	}
	return buf;
}
char *for_hash_flag(char* str, int specifier)
{
	if(!specifier)
		return(ft_strjoin("0x",str));
	else
		return(ft_strjoin("0X",str));	
	return NULL;	
}



char *for_d_specifier(void* number_in_hexa, int width, char *flags, int precision, int is_long)
{
	char *output;
	long num;

	if(is_long)
		num = (unsigned int)number_in_hexa;
	else
		num = (int)number_in_hexa;
	if(num==0 && flags  && ft_strchr(flags, '.'))
		output = ft_strdup("");
	else
		output = ft_strdup(itoa(num));
	if(num<0)
		output = ft_substr(output,1,ft_strlen(output)-1);
		
	while ((int)ft_strlen(output) < precision && ft_strchr(flags, '.'))
		output = ft_strjoin("0",output);
	if(flags && ft_strchr(flags, '0') && !ft_strchr(flags, '.'))
		while ((int)ft_strlen(output) < width-((ft_strchr(flags, '+') && !is_long  && num>=0) || num<0))
			output = ft_strjoin("0",output);


	if(num < 0)
		output = ft_strjoin("-",output);
	if(flags && ft_strchr(flags, '+') && num>=0 && !is_long)
		output = ft_strjoin("+", output);

	if(flags && ft_strchr(flags, '-'))
		while ((int)ft_strlen(output) < width)
			output = ft_strjoin(output," ");
	while ((int)ft_strlen(output) < width)
		output = ft_strjoin(" ",output);


	return output;
}
char *for_s_specifier(void* str, char *flags, int width, int presision)
{
	char *output;
	if(!str)
		output = ft_strdup("(null)");
	else
		output = ft_strdup(str);
	int i = (int)ft_strlen(output);
	if(flags && ft_strchr(flags, '.') && i > presision)
	{
		output[presision] = '\0';
	}
	if(flags && ft_strchr(flags, '-'))
		while ((int)ft_strlen(output) < width)
			output = ft_strjoin(output," ");
	while ((int)ft_strlen(output) < width)
		output = ft_strjoin(" ",output);

	return output;
}
char *for_c_specifier(void* c, char *flags, int width, int is_precentage)
{
	char *output;
	output = malloc(sizeof(char) * 1);
	if(!output)
		return NULL;
	output[0] = (char)c;
	if(is_precentage)
		output[0] = '%';
	if(flags && ft_strchr(flags, '-'))
		while ((int)ft_strlen(output) < width)
			output = ft_strjoin(output," ");
	if(flags && ft_strchr(flags, '0'))
		while ((int)ft_strlen(output) < width)
			output = ft_strjoin("0",output);
	while ((int)ft_strlen(output) < width)
		output = ft_strjoin(" ",output);
	return output;
}
char *for_p_specifier(void* p,char *flags, int width)
{
	char *output;
	output = short_hexa_converter(p,0,4);
	if(flags && ft_strchr(flags, '0'))
		while ((int)ft_strlen(output) < width-2)
			output = ft_strjoin("0",output);
	output = for_hash_flag(output, 0);

	if(flags && ft_strchr(flags, '-'))
		while ((int)ft_strlen(output) < width)
			output = ft_strjoin(output," ");
	while ((int)ft_strlen(output) < width)
		output = ft_strjoin(" ",output);
	return output;
}
char *for_xX_specifier(void* number_in_hexa, int width, char *flags, int is_Upper)
{
	char *output;

	output = short_hexa_converter(number_in_hexa, is_Upper,8);
	//output = final_precision(output,8);
	if(flags && ft_strchr(flags, '0'))
		while ((int)ft_strlen(output) < width-((number_in_hexa && flags && ft_strchr(flags, '#'))*2))
			output = ft_strjoin("0",output);
	if(number_in_hexa && flags && ft_strchr(flags, '#'))
	{
		output = for_hash_flag(output, is_Upper);
	}
	if((flags && !ft_strchr(flags, '0') && !ft_strchr(flags, '-')) || !flags)
		while ((int)ft_strlen(output) < width-((number_in_hexa && flags && ft_strchr(flags, '#'))*2))
			output = ft_strjoin(" ",output);
	while ((int)ft_strlen(output) < width-((number_in_hexa && flags && ft_strchr(flags, '#'))*2))
			output = ft_strjoin(output, " ");
	//output = for_width(output,width,flags && ft_strchr(flags, '0'));
	return (output);
}

#define NDO t_node	->data->original_value 

void fill_final_value(t_node	 *t_node	)
{
	if(t_node	->data->specifier == 's')
		t_node	->data->final_value = for_s_specifier((char *)NDO,t_node	->data->flags, t_node	->data->width,t_node	->data->precision);
	else if(t_node	->data->specifier == 'd' || t_node	->data->specifier == 'i'  || t_node	->data->specifier == 'u')
		t_node	->data->final_value = for_d_specifier(NDO, t_node	->data->width, t_node	->data->flags,t_node	->data->precision,t_node	->data->specifier == 'u');
	else if(t_node	->data->specifier == 'c' || t_node	->data->specifier == '%')
		t_node	->data->final_value = for_c_specifier(NDO, t_node	->data->flags, t_node	->data->width, t_node	->data->specifier == '%');
	else if(t_node	->data->specifier == 'p')
		t_node	->data->final_value = for_p_specifier(NDO,t_node	->data->flags , t_node	->data->width);
	else if(t_node	->data->specifier == 'x' || t_node	->data->specifier == 'X')
		t_node	->data->final_value = for_xX_specifier(NDO, t_node	->data->width, t_node	->data->flags,t_node	->data->specifier == 'X');
}

char *add_it_to_last_string(char *last_string, char *adding,int position)
{
	char* output;

	if(!adding)
		adding = ft_strdup("(null)");
	output = malloc(sizeof(char) * ft_strlen(last_string)+ft_strlen(adding) + 1);
	ft_strlcpy(output,last_string,position+1);
	ft_strlcat(output,adding,ft_strlen(output)+ft_strlen(adding)+1);
	ft_strlcat(output,last_string+position,ft_strlen(last_string)+ft_strlen(adding)+1);
	return(output);
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
		acase->flags = join_flags(acase->flags, i, str[i]);
		i++;
	}
	acase->width = ft_atoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		acase->flags = join_flags(acase->flags, ft_strlen(acase->flags), str[i]);
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


int		add_case(t_node	* nodes,t_case	 *acase)
{
	if(acase)
	{
		if(!nodes->data)
			nodes->data = acase;
		else
			add_t_node_back(&nodes,creat_t_node(acase));
		return (1);
	}
	return 0;
}

//this func will fill all the data on start: 
// - last string(striped from cases
// - create a case if she find one by calling create_case_from_string
// - return the number of parameters
int		ft_fill_data(const char *str, t_node *nodes,char **last_sring)
{
	int output = 0;
	char *str_output;
	str_output = NULL;
	int i = 0;
	int j = 0;
	while (str[i])
	{
		if(str[i] == '%')
		{
			i++;
			j=0;
			if(add_case(nodes,create_case_from_string((char *)(str+i),ft_strlen(str_output))))
			{
				while (!is_specifier(str[i]))
					i++;
				output++;
				if(str[i])
					i++;
			} else
			{
				return (-1);
			}
		}
		else
			str_output = my_strjoin(str_output, &str[i++],1);
	}
	*last_sring = str_output;
	if(!str_output)
		return(-1);
	return (output);
}

int		ft_printf(const char *str, ...)
{
	t_node	*nodes;
	t_node	 *for_storing;
	char* last_string;
	int number_of_parameters;

	nodes = creat_t_node(NULL);
	last_string = NULL;
	int i = 0;
	int add = 0;
	number_of_parameters = ft_fill_data(str, nodes, &last_string);
	va_list args;
	va_start(args, str);
	if(!last_string)
		last_string = ft_strdup("");
	while (i<number_of_parameters)
	{
		for_storing = get_node_by_id(&nodes,i);
		for_storing->data->original_value = va_arg(args, void*);
		fill_final_value(for_storing);
		last_string = add_it_to_last_string(last_string,for_storing->data->final_value,for_storing->data->position+add);
		add += ft_strlen(for_storing->data->final_value);
		i++;
	}
	ft_putstr_fd((char *)last_string,1);
	va_end(args);
	return (0);
}
// #include <stddef.h>
// int main()
// {
// 	size_t Gb = 1<<30;
// 	char *a = (char *)malloc(2 * Gb * sizeof(char));
// 	ft_printf("%5u!\n",33);
// 	printf("%5u!\n",33);

// 	ft_printf("------------------------\n");



// 	ft_printf("%05%!\n");
// 	printf("%05%!\n" );
// 	ft_printf("%-p!\n", &a);
// 	printf("%-p!\n", &a);
// 	ft_printf("%p!\n", NULL);
// 	printf("%p!\n", NULL);
// 	ft_printf("%-05c!\n", '0');
// 	printf("%-05c!\n", '0');
// 	ft_printf("%-50p!\n", (void*)ULONG_MAX);
// 	printf("%-50p!\n", (void*)ULONG_MAX);


// 	ft_printf("------------------------\n");
// 	//printf("%05.5d...",5);
// 	//write_ptr("void *p");
// 	//char *a = (char *)malloc(2 * Gb * sizeof(char));
// 	ft_printf("%%!\n");
// 	printf("%%!\n");
// 	ft_printf("%5%!\n");
// 	printf("%5%!\n");
// 	ft_printf("%-5%!\n");
// 	printf("%-5%!\n");
// 	ft_printf("%32s!\n",NULL);
// 	printf("%32s!\n",NULL);
// 	ft_printf("%32s!\n","NULL");
// 	printf("%32s!\n","NULL");
// 	ft_printf("%-20d!\n", -1024);
// 	printf("%-20d!", -1024);
// 	// ft_printf("%d ",4294967295);
// 	// ft_printf("%u ",4294967295);
// 	// ft_printf("%u ",4294967295);
// 	return 0;
// }


// int main(){
// ft_printf("%7i!\n", 33);
// printf("%7i!\n", 33);
// ft_printf("%3i!\n", 0);
// printf("%3i!\n", 0);
// ft_printf("%5i!\n", 52625);
// printf("%5i!\n", 52625);
// ft_printf("%-7i!\n", 33);
// printf("%-7i!\n", 33);
// ft_printf("%-3i!\n", 0);
// printf("%-3i!\n", 0);
// ft_printf("%-5i!\n", 52625);
// printf("%-5i!\n", 52625);
// }


// int main()
// {
// 	// ft_printf("%.s!!!!\n", NULL);
// 	// printf("%.s!!!!\n", NULL);
// 	// ft_printf("%-32s!!!!\n", "abc");
// 	// printf("%-32s!!!!\n", "abc");
// 	// ft_printf("%-16s!!!!\n", "nark nark");
// 	// printf("%-16s!!!!\n", "nark nark");

// 	ft_printf("%.7s!!!!\n", "hello");
// 	printf("%.7s!!!!\n", "hello");
// 	ft_printf("%.3s!!!!\n", "hello");
// 	printf("%.3s!!!!\n", "hello");
// 	ft_printf("%.s!!!!\n", "hello");
// 	printf("%.s!!!!\n", "hello");
// 	ft_printf("%.0s!!!!\n", "hello");
// 	printf("%.0s!!!!\n", "hello");
// 	ft_printf("%.3s%.2s!!!!\n", "holla", "bitch");
// 	printf("%.3s%.2s!!!!\n", "holla", "bitch");
// 	ft_printf("%.2s%.7s!!!!\n", "hello", "world");
// 	printf("%.2s%.7s!!!!\n", "hello", "world");
// 	ft_printf("%.7s%.2s!!!!\n", "hello", "world");
// 	printf("%.7s%.2s!!!!\n", "hello", "world");
// }


// int main()
// {

// 	// 	ft_printf("%7.5s|\n", "yolo");
// 	// 	printf("%7.5s|\n", "yolo");
// 	// ft_printf("%7.5s|\n", "bombastic");
// 	// printf("%7.5s|\n", "bombastic");
// 	ft_printf("%-7.5s|\n", "tubular");
// 	printf("%-7.5s|\n", "tubular");
// }

void	check_leaks();
int main()
{
	ft_printf("%8.5d|\n", 34);
	printf("%8.5d|\n", 34);
	ft_printf("%10.5d|\n", -216);
	printf("%10.5d|\n", -216);
	ft_printf("%8.5d|\n", 0);
	printf("%8.5d|\n", 0);
	ft_printf("%-7i!\n", -33);
	printf("%-7i!\n", -33);
	ft_printf("%-3i!\n", -0);
	printf("%-3i!\n", -0);
	printf("-------------------------------\n");


	ft_printf("%.5i\n", 2);
	printf("%.5i\n", 2);
	ft_printf("%.6i\n", -3);
	printf("%.6i\n", -3);
	ft_printf("%.3i\n", 0);
	printf("%.3i\n", 0);

	ft_printf("%3.7i\n", 3267);
	printf("%3.7i\n", 3267);
	ft_printf("%3.7i\n", -2375);
	printf("%3.7i\n", -2375);

	printf("-------------------------------\n");
	
	ft_printf("%05i\n", 43);
	printf("%05i\n", 43);
	ft_printf("%07i\n", -54);
	printf("%07i\n", -54);
	ft_printf("%03i\n", 0);
	printf("%03i\n", 0);
	
	ft_printf("%-8.5i\n", 34);
	printf("%-8.5i\n", 34);
	
	ft_printf("%-10.5i\n", -216);
	printf("%-10.5i\n", -216);
	
	ft_printf("%-8.5i\n", 0);
	printf("%-8.5i\n", 0);
	
	ft_printf("%-3.7i\n", 3267);
	printf("%-3.7i\n", 3267);
	
	ft_printf("%-3.7i\n", -2375);
	printf("%-3.7i\n", -2375);
	
	ft_printf("%08.5i\n", 34);
	printf("%08.5i\n", 34);
	
	ft_printf("%010.5i\n", -216);
	printf("%010.5i\n", -216);

	printf("======\n");
	ft_printf("%.0i|\n", 0);
	printf("%.0i|\n", 0);
	ft_printf("%.i|\n", 0);
	printf("%.i|\n", 0);
	ft_printf("%5.0i|\n", 0);
	printf("%5.0i|\n", 0);
	ft_printf("%5.i|\n", 0);
	printf("%5.i|\n", 0);
	ft_printf("%-5.0i|\n", 0);
	printf("%-5.0i|\n", 0);
	ft_printf("%-5.i|\n", 0);
	printf("%-5.i|\n", 0);
	ft_printf("%.0d|\n", 0);
	printf("%.0d|\n", 0);
	ft_printf("%.d|\n", 0);
	printf("%.d|\n", 0);
	ft_printf("%5.0d|\n", 0);
	printf("%5.0d|\n", 0);
	ft_printf("%5.d|\n", 0);
	printf("%5.d|\n", 0);
	ft_printf("%-5.0d|\n", 0);
	printf("%-5.0d|\n", 0);
	ft_printf("%-5.d|\n", 0);
	printf("%-5.d|\n", 0);
	return (check_leaks(), 0);
 }