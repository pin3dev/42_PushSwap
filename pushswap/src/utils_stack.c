/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:45:04 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/01 00:59:18 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* t_stack	*ft_lstnew(int content)
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
} */

/**
 * @brief Creates a new stack node with the given content.
 *
 * This function allocates memory for a new `t_stack` node and initializes its values.
 * The content of the node is set to the provided integer value. All other fields (`mov`, `mov_orientation`, `total_mov`, and `index`)
 * are initialized to 0, and the `next` pointer is set to `NULL`.
 *
 * @param content The integer value to be stored in the new node.
 *
 * @return A pointer to the newly created node, or `NULL` if memory allocation fails.
 */
t_stack *ft_stacknew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	if (new)
	{
		new->content = content;
		new->mov = 0;
		new->mov_orientation = 0;
		new->total_mov = 0;
		new->index = 0;
		new->next = NULL;
	}
    return new;
}

/**
 * @brief Adds a new node to the end of the stack.
 *
 * This function adds the `new_node` to the end of the stack (`lst`). It uses the
 * `ft_lstadd_back()` function to add the node to the back of the stack.
 *
 * @param lst A pointer to the head of the stack.
 * @param new_node The new node to be added to the end of the stack.
 *
 * @see ft_lstadd_back() for adding a node to the end of a generic linked list.
 */
void ft_stackadd_back(t_stack **lst, t_stack *new_node)
{
    ft_lstadd_back((t_list **)lst, (t_list *)new_node);
}
/**
 * @brief Returns the last node in the stack.
 *
 * This function returns a pointer to the last node in the stack. It uses `ft_lstlast()`
 * to find the last node in a generic linked list and casts it to the `t_stack` type.
 *
 * @param lst A pointer to the head of the stack.
 *
 * @return A pointer to the last node in the stack, or `NULL` if the stack is empty.
 *
 * @see ft_lstlast() to find the last node in a generic linked list.
 */
t_stack *ft_stacklast(t_stack *lst)
{
    return (t_stack *)ft_lstlast((t_list *)lst);
}

/**
 * @brief Returns the number of nodes in the stack.
 *
 * This function calculates and returns the size (number of nodes) in the stack by
 * calling `ft_lstsize()` on the linked list and casting it to the `t_stack` type.
 *
 * @param lst A pointer to the head of the stack.
 *
 * @return The number of nodes in the stack.
 *
 * @see ft_lstsize() to get the size of a generic linked list.
 */
int ft_stacksize(t_stack *lst)
{
    return ft_lstsize((t_list *)lst);
}
