#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
  int content;
  struct stack *next;
  int mov;
  unsigned int mov_orientation;
  int index;
} t_stack;

void print_list(t_stack **head)
{
    t_stack *cur = *head;
    while(cur != 0)
    {
        printf("| Content: %d      Index:%d     Mov:%d      Orient:%d |\n", cur->content, cur->index, cur->mov, cur->mov_orientation);
        cur = cur->next;
    }
    if(cur == 0)
        printf("|-------------------------------------------------|\n");
}

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

void	pb(t_stack **b, t_stack **a)
{
	push(&(*b),&(*a));
}

void	sb(t_stack **b)
{
	swap(&(*b));
}

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

t_stack *find_place(t_stack *src, t_stack **dest)
{ 
    t_stack *node = ft_check_new_min_max(src, dest);
    t_stack *cur = *dest;

    while(cur)
    {
        if(cur->content > src->content)
            cur = cur->next;
        else
        {
            if(cur->content > node->content)
                node = cur;
            cur = cur->next;
        }   
    }
    return(node);
}

void ft_put_mov_and_orientation(int i, t_stack **stack);

int ft_put_index_and_return_size(t_stack **stack)
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
    return(i);
}

void ft_put_mov_and_orientation(int i, t_stack **stack)
{
    t_stack *cur;
    cur = *stack;
    while(cur)
    {
        if(cur->index <= i/2)
        {
            cur->mov = cur->index;
            cur->mov_orientation = 0;
        }
        else
        {
            cur->mov = (i - (cur->index));
            cur->mov_orientation = 1;
        }
        cur = cur->next;
    }
}

int main(int ac, char** av)
{
    if(ac < 2)
    {
        printf("Mensagem de Erro\n");
        //________FUNCAO DE ERROR________//
        return(0);
    }
    else if(ac == 2)
    {
        printf("Ft_split rodara aqui\n");
        //________FUNCAO SPLIT________//
        return(0);
    }
    else if(ac > 2)
    {
        //________FUNCAO CRIACAO DA STACK A________
        t_stack *head_a;
        head_a = ft_lstnew(atoi(av[1]));
        
        int i;
        i = 2;
        int numb;
        while(i < ac)
        {
            numb = atoi(av[i]);
            ft_lstadd_back(&head_a, ft_lstnew(numb));
            i++;
        }
        //________FIM STACK A__________________________

        //----------------------------->FUNCAO VERIFICAR REPETIDOS
        //----------------------------->FUNCAO VERIFICAR ORDEM

        //________FUNCAO CRIACAO DA STACK B___________
        t_stack *head_b;

        head_b = NULL;
        //________FIM STACK B_________________________

        //printf("Lista Original A:\n");
        //print_list(head_a);

        int size_list_a = ft_put_index_and_return_size(&head_a);
        printf("\nO tamanho da Lista A:%d\n", size_list_a);
        printf("\n|---------------------LIST A----------------------|\n");
        print_list(&head_a);
        
        int size_list_b = ft_put_index_and_return_size(&head_b);
        printf("\nO tamanho da Lista B:%d\n", size_list_b);
        printf("\n|---------------------LIST B----------------------|\n");
        print_list(&head_b);
        
        
        pb(&head_b, &head_a);
        pb(&head_b, &head_a);
        sb(&head_b);
        pb(&head_b, &head_a);
        pb(&head_b, &head_a);
        pb(&head_b, &head_a);

        size_list_a = ft_put_index_and_return_size(&head_a);
        printf("\nO tamanho da Lista A:%d\n", size_list_a);
        printf("\n|---------------------LIST A----------------------\n");
        print_list(&head_a);
        
        size_list_b = ft_put_index_and_return_size(&head_b);
        printf("\nO tamanho da Lista B:%d\n", size_list_b);
        printf("\n|---------------------LIST B----------------------|\n");
        print_list(&head_b);
        
        t_stack *place = find_place(head_a, &head_b);
        printf("Lugar de A em B esta acima do: %d\n", place->content);

        //TESTE COM AS ENTRADAS: 5 2 7 1 6 3 9 4 8
    }
}