#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

enum specifier 
{   
	c,
	s,
	p,
	d,
	i,
	u,
	x,
	X,
};
#define ULONG_MAX 0xFFFFFFFFUL

typedef struct Case
{
    char* flags;
    char specifier;
    int width;
	int precision;
	int position;
	void* original_value;
    char* final_value;
} Case;

typedef struct Node {
    Case* data;
    struct Node* next;
} Node;

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


int		is_specifier(char c){
	if(
		c == 'c' ||
		c == 's' ||
		c == 'p' ||
		c == 'd' ||
		c == 'i' ||
		c == 'u' ||
		c == 'x' ||
		c == 'X' ||
		c == '%' 
	 )
	 return (1);
	 return (0);
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

char	*final_precision(char *str, int precision)
{
	return ft_substr(str,ft_strlen(str)-8,8+precision);
}

int		is_flag(char c){
	if(
		c == '#' ||
		c == ' ' ||
		c == '0' ||
		c == '+' ||
		c == '-'
	 )
	 return (1);
	 return (0);
}
char	*my_strjoin(char const *s1, char const *s2, int lenght)
{
	char	*output;
	int	i;
	int	j;

	i = 0;
	j = 0;
	output = malloc(ft_strlen(s1) + lenght + 1);
	if (!output)
		return (NULL);
	while (s1 && *s1)
		output[i++] = *s1++;
	while (j<lenght)
	{
		output[i++] = s2[j++];
	}
	output[i] = '\0';
	return (output);
}
char	*join_flags(const char *s, int lenght, char c)
{
	char *output;
	int i = 0;
	output = (char *)malloc(lenght+2);
	while (s && i<lenght)
	{
		output[i] = s[i];
		i++;
	}
	output[i++]= c;
	output[i]= '\0';

	return(output);
}

Case	*create_case_from_string(char *str,int place)
{
	Case	*acase;
	int i = 0;

	acase = (Case*)malloc(sizeof(Case));
	acase->position = place;
	acase->flags = 0;
	acase->final_value = 0;
	acase->original_value = 0;
	acase->specifier = 0;
	acase->width = 0;
	acase->precision = 0;
	while (is_flag(str[i]))
	{
		//momory leak
		acase->flags = join_flags(acase->flags,i,str[i]);
		i++;
	}
	
	acase->width = ft_atoi(str+i);
	
	while (str[i]>='0' && str[i]<='9')
		i++;
	if(str[i] == '.')
	{
		acase->flags = join_flags(acase->flags,ft_strlen(acase->flags),str[i]);
		i++;
		acase->precision = ft_atoi(str+i);
		while (str[i]>='0' && str[i]<='9')
			i++;
	}
	if(is_specifier(str[i]))
	acase->specifier = str[i];
	else return(NULL);
	return (acase);
}

Node	*creat_node(Case *data)
{
	Node	*new;

	new = malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;
	return (new);
}
Node	*get_node_by_id(Node **lst, int index)
{
	int i = 0;
	if ((*lst))
	{
		while ((*lst)->next && i != index)
		{
			lst = &(*lst)->next;
			i++;
		}
		return((*lst));
	}
	return (*lst);
}

void	add_node_back(Node **lst, Node *new)
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

int		add_case(Node* nodes,Case *acase)
{
	if(acase)
	{
		if(!nodes->data)
			nodes->data = acase;
		else
			add_node_back(&nodes,creat_node(acase));
		return (1);
	}
	return 0;
}

int		get_number_of_parameters(const char *str, Node* nodes,char **last_sring)
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
				{
					i++;
				}
				output++;
				if(str[i])
					i++;
			}
		}
		else{
		str_output = my_strjoin(str_output,&str[i],1);
		i++;
		}
		//momory leak

	}
		*last_sring = str_output;
	return output;
}


char * write_ptr(void *p) {
    unsigned long x = (unsigned long)p;
    char *buf;
    size_t i;
	buf = malloc(3);

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
    char *buf = malloc(1);
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
    char *buf = malloc(1);
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
	output = ft_strdup(itoa(num));
	if(num<0)
		output = ft_substr(output,1,ft_strlen(output)-1);
	if(flags && (ft_strchr(flags, '0') || ft_strchr(flags, '.')) && !ft_strchr(flags, '-'))
		while (((int)ft_strlen(output) < width-((flags && ft_strchr(flags, '+') && !is_long  && num>=0) || num<0))
			|| ((int)ft_strlen(output) < precision)
		 )
			output = ft_strjoin("0",output);
	if(num < 0)
		output = ft_strjoin("-",output);
	
	if(flags && ft_strchr(flags, '+') && num>=0 && !is_long)
		output = ft_strjoin("+", output);
	if(flags && ft_strchr(flags, '-'))
		while ((int)ft_strlen(output) < width-(num<0))
		{
			output = ft_strjoin(output," ");
		}
	
	while ((int)ft_strlen(output) < width && ((flags && !ft_strchr(flags, '0') && !ft_strchr(flags, '-')) || !flags))
	{
		output = ft_strjoin(" ",output);
	}


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
	output = malloc(1);
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

#define NDO node->data->original_value 

void fill_final_value(Node *node)
{
	if(node->data->specifier == 's')
		node->data->final_value = for_s_specifier((char *)NDO,node->data->flags, node->data->width,node->data->precision);
	else if(node->data->specifier == 'd' || node->data->specifier == 'i'  || node->data->specifier == 'u')
		node->data->final_value = for_d_specifier(NDO, node->data->width, node->data->flags,node->data->precision,node->data->specifier == 'u');
	else if(node->data->specifier == 'c' || node->data->specifier == '%')
		node->data->final_value = for_c_specifier(NDO, node->data->flags, node->data->width, node->data->specifier == '%');
	else if(node->data->specifier == 'p')
		node->data->final_value = for_p_specifier(NDO,node->data->flags , node->data->width);
	else if(node->data->specifier == 'x' || node->data->specifier == 'X')
		node->data->final_value = for_xX_specifier(NDO, node->data->width, node->data->flags,node->data->specifier == 'X');
}

char *add_it_to_last_string(char *last_string, char *adding,int position)
{
	char* output;

	if(!adding)
		adding = ft_strdup("(null)");
	output = malloc(ft_strlen(last_string)+ft_strlen(adding) + 1);
	ft_strlcpy(output,last_string,position+1);
	ft_strlcat(output,adding,ft_strlen(output)+ft_strlen(adding)+1);
	ft_strlcat(output,last_string+position,ft_strlen(last_string)+ft_strlen(adding)+1);
	return(output);
}

int		ft_printf(const char *str, ...)
{
    Node* nodes = NULL;
	char* last_string;
	last_string = NULL;

    nodes = creat_node(NULL);
	int number_of_parameters;
	int i = 0;
	int add = 0;
	Node *for_storing;
	number_of_parameters = get_number_of_parameters(str, nodes, &last_string);
	
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
	
	//printf("\nnumber of parameters:%d", 2);
	//int fd = va_arg(args, int);
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

int main()
{
	ft_printf("%8.5d|\n", 34);
	printf("%8.5d|\n", 34);
	ft_printf("%10.5d|\n", -216);
	printf("%10.5d|\n", -216);
	ft_printf("%8.5d|\n", 0);
	printf("%8.5d|\n", 0);
}