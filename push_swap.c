#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
  int content;
  struct stack *next;
  int mov;
  int mov_orientation;
  int total_mov;
  int index;
} t_stack;

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
//-------------->GENERAL MOVIMENTS----------------
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

//-------------->SWAP MOVIMENTS----------------
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


//-------------->ROTATE MOVIMENTS----------------
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
//-------------->REVERSE ROTATE MOVIMENTS----------------
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
//-------------->PUSH MOVIMENTS----------------
void	pa(t_stack **a, t_stack **b)
{
	push(&(*a),&(*b));
}

void	pb(t_stack **b, t_stack **a)
{
	push(&(*b),&(*a));
}
//---------------------------------------------

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

t_stack *ft_find_place(t_stack *src, t_stack **dest)
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
    ft_put_total_mov(src, place);
    return(place);
}
//TACAR O TACACA DA DECLARACAO DA FUNCAO NO HEADER
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

t_stack *ft_best_case(t_stack **src)
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

        /*int size_list_a = ft_put_index_and_return_size(&head_a);
        printf("\nO tamanho da Lista A:%d\n", size_list_a);
        printf("\n|----------------------------LIST A-----------------------------|\n");
        print_list(&head_a);
        
        int size_list_b = ft_put_index_and_return_size(&head_b);
        printf("\nO tamanho da Lista B:%d\n", size_list_b);
        printf("\n|----------------------------LIST B-----------------------------|\n");
        print_list(&head_b);*/
        int size_list_a = ft_put_index_and_return_size(&head_a);
        int size_list_b = ft_put_index_and_return_size(&head_b);

        
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
        rra(&head_a);
        pb(&head_b, &head_a);
        rra(&head_a);
        rb(&head_b);
        pb(&head_b, &head_a);
        rb(&head_b);
        rb(&head_b);
        rb(&head_b);
        pb(&head_b, &head_a);
        rr(&head_a, &head_b);
        ra(&head_a);
        pb(&head_b, &head_a);
        pb(&head_b, &head_a);
        sa(&head_a);
        rrb(&head_b);
        rrb(&head_b);
        rrb(&head_b);
        rrb(&head_b);
        rrb(&head_b);
        rrb(&head_b);
        pb(&head_b, &head_a);
        rrb(&head_b);
        rrb(&head_b);
        pb(&head_b, &head_a);



        t_stack *cur = head_a;

        size_list_a = ft_put_index_and_return_size(&head_a);
        size_list_b = ft_put_index_and_return_size(&head_b);
        while(cur)
        {
            t_stack *place = ft_find_place(cur, &head_b);
            cur = cur->next;
        }
        printf("\nO tamanho da Lista A:%d\n", size_list_a);
        printf("\n|----------------------------LIST A-----------------------------|\n");
        print_list(&head_a);
        
        size_list_b = ft_put_index_and_return_size(&head_b);
        printf("\nO tamanho da Lista B:%d\n", size_list_b);
        printf("\n|----------------------------LIST B-----------------------------|\n");
        print_list(&head_b);
        
        cur = head_a;

        while(cur)
        {
            if(ft_best_case(&head_a) == cur)
                printf("O melhor node para movimentar em A: %d\n", cur->content);
            cur = cur->next;
        }

        //printf("Lugar de A em B esta acima do: %d\n", place->content);

        //TESTE COM AS ENTRADAS: 5 2 7 1 6 3 9 4 8
        //TESTE COM AS ENTRADAS: 2 7 15 3 8 9 10 100 37 28 42 32 6 1 29 30 55 80
    }
}