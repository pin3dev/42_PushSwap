/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:45:04 by ivbatist          #+#    #+#             */
/*   Updated: 2023/05/17 19:39:19 by clima-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

int	ft_lstsize(t_stack *lst)
{
	int		count;
	t_stack	*cur;

	count = 0;
	cur = lst;
	while (cur != NULL)
	{
		cur = cur->next;
		count++;
	}
	return (count);
}
