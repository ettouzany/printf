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

typedef struct Case
{
    char* flags;
    char specifier;
    int width;
    //int precision;
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
	size_t	i;
	size_t	j;

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
	Case acase;
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

int fill_final_value(Node *node)
{
	if(node->data->specifier == 's')
		node->data->final_value = (char *)node->data->original_value;
	if(node->data->specifier == 'd')
		node->data->final_value = ft_strdup(ft_itoa((int)node->data->original_value));

	return(ft_strlen(node->data->final_value));
}

char *add_it_to_last_string(char *last_string, char *adding,int position)
{
	char* output;
	char* first_part;
	char* second_part;

	first_part = malloc(position + 1);

	output = malloc(ft_strlen(last_string)+ft_strlen(adding) + 1);
	ft_strlcpy(output,last_string,position);
	ft_strlcat(output,adding,ft_strlen(output)+ft_strlen(adding)+1);
	//ft_strlcat(output,last_string,ft_strlen(output)+ft_strlen(adding));
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
		add += fill_final_value(for_storing);
		last_string = add_it_to_last_string(last_string,for_storing->data->final_value,for_storing->data->position+add);
		i++;
	}
	
	//printf("\nnumber of parameters:%d", 2);

	//int fd = va_arg(args, int);
	//ft_putstr_fd((char *)str,fd);
	va_end(args);
	return (0);
}

int main(int argc, char const *argv[])
{
	//printf("%d...",printf("500sad%011bsasa",1));
	ft_printf( "test:%-0+500s%d", "1hjjhj", 5000);
	return 0;
}
