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
	while (i<lenght)
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

	if(str[i] == '%')
		return NULL;
	while (is_flag(str[i]))
	{
		//momory leak
		acase->flags = join_flags(acase->flags,i,str[i]);
		i++;
	}

	acase->width = ft_atoi(str+i);
	
	while (str[i]>='0' && str[i]<='9')
		i++;
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
	char *str_output = 0;
	int i = 0;
	int j = 0;
	while (str[i])
	{
		if(str[i] == '%')
		{
			i++;
			j=0;
			if(str[i] != '%')
			{
				if(add_case(nodes,create_case_from_string((char *)(str+i),ft_strlen(str_output))))
				{
					while (!is_specifier(str[i]))
					{
						i++;
					}
					output++;
				}
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



char *for_d_specifier(void* number_in_hexa, int width, char *flags, int is_long)
{
	char *output;
	long num;

	if(is_long)
		num = (unsigned int)number_in_hexa;
	else
		num = (int)number_in_hexa;
	output = ft_strdup(itoa(num));
	if(flags && ft_strchr(flags, '+') && num>=0)
		output = ft_strjoin("+", output);
	while ((int)ft_strlen(output) < width)
	{
		output = ft_strjoin(" ",output);
	}
	return output;
}
char *for_s_specifier(void* str, int width, int presision)
{
	char *output;
	output = str;
	while ((int)ft_strlen(output) < width && !presision)
	{
		output = ft_strjoin(" ",output);
	}
	return output;
}
char *for_c_specifier(void* c, int width)
{
	char *output;
	output = malloc(1);
	if(!output)
		return NULL;
	output[0] = (char)c;
	while ((int)ft_strlen(output) < width)
	{
		output = ft_strjoin(" ",output);
	}
	return output;
}
char *for_p_specifier(void* p, int width)
{
	char *output;
	output = write_ptr(p);
	while ((int)ft_strlen(output) < width)
	{
		output = ft_strjoin(" ",output);
	}
	return output;
}
char *for_xX_specifier(void* number_in_hexa, int width, char *flags, int is_Upper)
{
	char *output;
	flags = NULL;
	output = hexa_converter(number_in_hexa, is_Upper);

	while ((int)ft_strlen(output) < width)
	{
		output = ft_strjoin(" ",output);
	}
	return (output);
}
void fill_final_value(Node *node)
{
	if(node->data->specifier == 's')
		node->data->final_value = for_s_specifier((char *)node->data->original_value, node->data->width,0);
	else if(node->data->specifier == 'd' || node->data->specifier == 'i'  || node->data->specifier == 'u')
		node->data->final_value = for_d_specifier(node->data->original_value, node->data->width, node->data->flags,node->data->specifier == 'u');
	else if(node->data->specifier == 'c')
		node->data->final_value = for_c_specifier(node->data->original_value, node->data->width);
	else if(node->data->specifier == 'p')
		node->data->final_value = for_p_specifier(node->data->original_value, node->data->width);
	else if(node->data->specifier == 'x' || node->data->specifier == 'X')
		node->data->final_value = for_xX_specifier(node->data->original_value, node->data->width, node->data->flags,node->data->specifier == 'X');
}

char *add_it_to_last_string(char *last_string, char *adding,int position)
{
	char* output;


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
    nodes = creat_node(NULL);
	int number_of_parameters;
	int i = 0;
	int add = 0;
	Node *for_storing;
	number_of_parameters = get_number_of_parameters(str, nodes, &last_string);
	
	va_list args;
	va_start(args, str);

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

int main()
{
	size_t Gb = 1024*1024*1024;

	//printf("%05.5d...",5);
	//write_ptr("void *p");
	char *a = (char *)malloc(2 * Gb * sizeof(char));

	ft_printf("%x ", a);
	// ft_printf("%d ",4294967295);
	// ft_printf("%u ",4294967295);
	// ft_printf("%u ",4294967295);
	return 0;
}
