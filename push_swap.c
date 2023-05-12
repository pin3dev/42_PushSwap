/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:59:53 by ivbatist          #+#    #+#             */
/*   Updated: 2023/05/11 10:59:59 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
//////////////////////////////////////////////////ESTRUTURA
typedef struct stack
{
  int content;
  struct stack *next;
  int mov;
  int mov_orientation;
  int total_mov;
  int index;
} t_stack;
//////////////////////////////////////////////////FT GERAIS
void    ft_error(void)
{
    write(2, "Error!\n", 7);
    exit(1);
}
void print_list(t_stack **head)
{
    t_stack *cur = *head;
    while(cur != 0)
    {
        printf("| Content: %d      Index:%d     Mov:%d      Orient:%d   Total_Mov:%d |\n", cur->content, cur->index, cur->mov, cur->mov_orientation, cur->total_mov);
        cur = cur->next;
    }
    if(cur == 0)
        printf("|---------------------------------------------------------------|\n");
}
int	ft_isdigit(int c)
{		
	if ((c >= '0') && (c <= '9'))
	{
		return (2048);
	}
	else
	{
		return (0);
	}
}
//////////////////////////////////////////////////FT GERAIS LISTA
t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	if (new)
	{
		new->content = content;
		new->next = NULL;
	}
	return (new);
}
void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (lst && *lst && new)
	{
		current = *lst;
		while (current->next != 0)
		{
			current = current->next;
		}
		current->next = new;
	}
}
t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	else
		return (NULL);
	return (lst);
}
//////////////////////////////////////////////////FT VERIFICA MAIN
int	ft_atoi(const char *str)
{
	long long int	ret;
	int			sign;

	ret = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || \
*str == '\f' || *str == '\r' || *str == ' ')
		++str;
	if(*str == '\0')
		exit(1);
	if (*str && (*str == 43 || *str == 45))
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		ret *= 10;
		ret += (sign * (*(str++) - 48));
	}
	if (ret > 2147483647 || ret < -2147483648)
			ft_error();
	return (ret);
}
static int	count_words(char const *str, char c)
{
	int	words;
	int	flag;

	words = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			words++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (words);
}
static int	count_letters(char const *str, char c, int i)
{
	int	size;

	size = 0;
	while (str[i] != c && str[i])
	{
		size++;
		i++;
	}
	return (size);
}
size_t	ft_strlen(const char *str)
{
	size_t	cont;

	cont = 0;
	while (str[cont] != '\0')
	{
		cont++;
	}
	return (cont);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*string;
	unsigned int		i;
	unsigned int		a;

	i = start;
	a = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		string = malloc(1 * sizeof(char));
		if (string == NULL)
			return (NULL);
		string[0] = '\0';
		return (string);
	}
	string = malloc((len + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	while (i < ft_strlen(s) && len-- > 0)
		string[a++] = s[i++];
	string[a] = '\0';
	return (string);
}
char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	j = -1;
	word = count_words(s, c);
	str = (char **)malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		str[j] = ft_substr(s, i, count_letters(s, c, i));
		if (!str)
			return (NULL);
		i += count_letters(s, c, i);
	}
	str[j] = 0;
	return (str);
}
void    ft_create_node(t_stack **head, char *str)
{
    int numb = ft_atoi(str);
    ft_lstadd_back(head, ft_lstnew(numb));
}
void	ft_freesplit(char **str)
{
	char	*s1;

	if (!str)
		return ;
	while (*str)
	{
		s1 = *str;
		str++;
		free(s1);
	}
	*str = NULL;
}
t_stack *ft_check_arg_and_create_stack_a(int ac, char **av)
{
    t_stack *head_a;
    head_a = NULL;

    if(ac == 2)
    {
        char **split = ft_split(av[1], 32);
        int i = 0;
        while(split[i])
        {
            ft_create_node(&head_a, split[i]);
            i++;
        }
        ft_freesplit(split);
        free(split);
    }
    else
    {
        int i = 1;
        while(i < ac)
        {
            ft_create_node(&head_a, av[i]);
            i++;
        }
    }
    return(head_a);
}
int		ft_check_doubles(t_stack **stack_a)
{
    t_stack *i = *stack_a;
    t_stack *j = i->next;
	
    while(i && j)
    {
        while(j)
        {
            if(i->content == j->content)
                return(1);
            j = j->next;
        }
        i = i->next;
        j = i->next;
    }
    return(0);
}
int ft_check_sorted(t_stack **stack)
{
    t_stack *cmp = *stack;
    t_stack *i = cmp->next;
	
    while(cmp && i)
    {
		while(i)
       	{
           	if(cmp->content > i->content)
               	return(0);
           	i = i->next;
       	}
        cmp = cmp->next;
        i = cmp->next;
    }
    return(1);
}
//////////////////////////////////////////////////FT MOVIMENTO
void    swap(t_stack **stack)
{
	t_stack	*tmp;
	if (!*stack || !((*stack)->next))
		return ;
	tmp = *stack; 
	*stack = (*stack)->next; 
	tmp->next = (*stack)->next; 
	(*stack)->next = tmp; 
}
void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
}
void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	tmp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
}
void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = tmp;
}
void	sa(t_stack **a)
{
	swap(&(*a));
}
void	ss(t_stack **a, t_stack **b)
{
	swap(&(*a));
	swap(&(*b));
}
void	sb(t_stack **b)
{
	swap(&(*b));
}
void	ra(t_stack **a)
{
	rotate(&(*a));
}
void	rb(t_stack **b)
{
	rotate(&(*b));
}
void	rr(t_stack **a, t_stack **b)
{
	rotate(&(*a));
	rotate(&(*b));
}
void	rra(t_stack **a)
{
	reverse_rotate(&(*a));
}
void	rrb(t_stack **b)
{
	reverse_rotate(&(*b));
}
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(&(*a));
	reverse_rotate(&(*b));
}
void	pa(t_stack **a, t_stack **b)
{
	push(&(*a),&(*b));
}
void	pb(t_stack **b, t_stack **a)
{
	push(&(*b),&(*a));
}
//////////////////////////////////////////////////FT ALGORITMO
t_stack	*ft_max(t_stack **stack)
{
    t_stack *cur = *stack;
	t_stack *max = cur;

	while(cur)
	{
		if(cur->content > max->content)
			max = cur;
		cur = cur->next;
	}
	return(max);
}
t_stack	*ft_min(t_stack **stack)
{
    t_stack *cur = *stack;
	t_stack *min = cur;

	while(cur)
	{
		if(cur->content < min->content)
			min = cur;
		cur = cur->next;
	}
	return(min);
}
t_stack *ft_check_new_min_max(t_stack *node_a, t_stack **stack_b)
{
    t_stack *node_min;
    node_min = ft_min(stack_b);

    t_stack *node_max;
    node_max = ft_max(stack_b);

    if(node_a->content > node_max->content || node_a->content < node_min->content)
        return(node_max);
    else
        return(node_min);
}
void    ft_put_total_mov(t_stack *src, t_stack *dest);
/*t_stack *ft_return_dest_place(t_stack *src, t_stack **dest)
{ 
    t_stack *place = ft_check_new_min_max(src, dest);
    t_stack *cur = *dest;

    while(cur)
    {
        if(cur->content > src->content)
            cur = cur->next;
        else
        {
            if(cur->content > place->content)
                place = cur;
            cur = cur->next;
        }
    }
    return(place);
}*/
void	ft_find_place_n_def_total_mov(t_stack **src, t_stack **dest)
{ 
    t_stack	*cur_src = *src;
	t_stack *place = ft_check_new_min_max(cur_src, dest);
    t_stack *cur_dest = *dest;

	while(cur_src)
	{
		while(cur_dest)
		{
			if(cur_dest->content > cur_src->content)
				cur_dest = cur_dest->next;
			else
			{
				if(cur_dest->content > place->content)
					place = cur_dest;
				cur_dest = cur_dest->next;
			}
		}
		ft_put_total_mov(cur_src, place);
		cur_dest = *dest;
		cur_src = cur_src->next;
	}
}
void ft_put_mov_and_orientation(int i, t_stack **stack);
void ft_put_index_n_def_mov_n_orient(t_stack **stack)
{
    t_stack *cur;
    cur = *stack;
    
    int i;
    i = 0;

    while(cur)
    {
        cur->index = i;
        cur = cur->next;
        i++;
    }
    cur = *stack;

    ft_put_mov_and_orientation(i, stack);
}
void ft_put_mov_and_orientation(int size, t_stack **stack)
{
    t_stack *cur;
    cur = *stack;
    while(cur)
    {
        if(cur->index <= (size)/2)
        {
            cur->mov = cur->index;
            cur->mov_orientation = 0;
        }
        else
        {
            cur->mov = (size - (cur->index));
            cur->mov_orientation = 1;
        }
        cur = cur->next;
    }
}
void    ft_put_total_mov(t_stack *src, t_stack *dest)
{
    if(src->mov_orientation == dest->mov_orientation)
    {
        if(src->mov > dest->mov)
            src->total_mov = src->mov;
        else
            src->total_mov = dest->mov;
    }
    else
        src->total_mov = src->mov + dest->mov;
}
t_stack *ft_find_best_case(t_stack **src)
{
    t_stack *cur = *src;
    t_stack *best_case = cur;
    
    int less_mov = cur->total_mov;

    while(cur)
    {
        if(cur->total_mov < less_mov)
        {
            less_mov = cur->total_mov;
            best_case = cur;
        }
        cur = cur->next;
    }
    return(best_case);
}
void	ft_move_best_case_to_top(t_stack *src, t_stack**stack)
{
	if(src->mov_orientation == 0)
	{
		while(src->mov > 0)
		{
			rotate(stack);
			src->mov--;
		}
	}
	else if(src->mov_orientation == 1)
	{
		while(src->mov > 0)
		{
			reverse_rotate(stack);
			src->mov--;
		}
	}
}
int main(int ac, char **av)
{
    if(ac < 2)
        ft_error();
    
    else
    {
        t_stack *head_a;
        t_stack *head_b;

		head_a = ft_check_arg_and_create_stack_a(ac,av);
		if(ft_check_doubles(&head_a) == 1)
			ft_error();
		/*if(!ft_check_sorted(&head_a))
			ft_case_sort();*/
		
        pb(&head_b, &head_a);
        pb(&head_b, &head_a);
        pb(&head_b, &head_a);
        rrb(&head_b);
        pb(&head_b, &head_a);
        rrb(&head_b);
        pb(&head_b, &head_a);
        pb(&head_b, &head_a);
        pb(&head_b, &head_a);
        rrb(&head_b);
        pb(&head_b, &head_a);
        rb(&head_b);
        pb(&head_b, &head_a);
        rb(&head_b);
        pb(&head_b, &head_a);
        rrb(&head_b);
        pb(&head_b, &head_a);

		t_stack *cur = head_a;

        ft_put_index_n_def_mov_n_orient(&head_a);
		ft_put_index_n_def_mov_n_orient(&head_b);
		ft_find_place_n_def_total_mov(&head_a, &head_b);

        printf("\n|----------------------------LIST A-----------------------------|\n");
        print_list(&head_a);
        
        ft_put_index_n_def_mov_n_orient(&head_b);
        printf("\n|----------------------------LIST B-----------------------------|\n");
        print_list(&head_b);
        
        cur = head_a;

        while(cur)
        {
            if(ft_find_best_case(&head_a) == cur)
            {
				printf("O melhor node para movimentar em A: %d\n", cur->content);
				ft_move_best_case_to_top(cur, &head_a);
			}
            cur = cur->next;
        }

		ft_put_index_n_def_mov_n_orient(&head_a);
        ft_put_index_n_def_mov_n_orient(&head_b);

        printf("\n|----------------------------LIST A-----------------------------|\n");
        print_list(&head_a);
        
        ft_put_index_n_def_mov_n_orient(&head_b);
        printf("\n|----------------------------LIST B-----------------------------|\n");
        print_list(&head_b);
    }
}

//teste com : 2 7 15 3 8 9 10 100 37 28 42 32 6 1 29 30 55 80

//proximo passo: corrigir o SPLIT, que esta com problemas quando passado apenas um arguento com espacos