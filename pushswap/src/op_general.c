/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_general.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:48:33 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/01 00:56:50 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Swaps the top two elements of the stack.
 *
 * This function swaps the first two elements in the stack. If the stack has fewer than two elements,
 * the function returns without performing any operation.
 *
 * @param stack A pointer to the stack where the swap will be performed.
 */
void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

/**
 * @brief Rotates the stack by moving the top element to the bottom.
 *
 * This function moves the first element of the stack to the end, effectively rotating the stack upwards.
 * If the stack has fewer than two elements, the function returns without performing any operation.
 *
 * @param stack A pointer to the stack that will be rotated.
 * 
 * @note This function relies on `ft_stacklast()` to find the last element in the stack.
 */
void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = ft_stacklast(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
}

/**
 * @brief Reverse rotates the stack by moving the bottom element to the top.
 *
 * This function moves the last element of the stack to the top, effectively rotating the stack downwards.
 * If the stack has fewer than two elements, the function returns without performing any operation.
 *
 * @param stack A pointer to the stack that will be reverse rotated.
 */
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

/**
 * @brief Pushes the top element from the source stack to the destination stack.
 *
 * This function removes the top element from the source stack (`src`) and places it on top of the destination stack (`dest`).
 * If the source stack is empty, the function returns without performing any operation.
 *
 * @param dest A pointer to the destination stack, where the top element of the source stack will be pushed.
 * @param src A pointer to the source stack, from which the top element will be removed.
 */
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
