/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numb_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:17:39 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/01 00:56:03 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


/**
 * @brief Finds the node with the maximum content value in the stack.
 *
 * This function iterates through the stack and returns the node that contains
 * the maximum content value.
 *
 * @param stack A pointer to the stack where the search for the maximum value will occur.
 *
 * @return A pointer to the node with the highest content value in the stack.
 */
t_stack	*ft_max(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*max;

	cur = *stack;
	max = cur;
	while (cur)
	{
		if (cur->content > max->content)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

/**
 * @brief Finds the node with the minimum content value in the stack.
 *
 * This function iterates through the stack and returns the node that contains
 * the minimum content value.
 *
 * @param stack A pointer to the stack where the search for the minimum value will occur.
 *
 * @return A pointer to the node with the lowest content value in the stack.
 */
t_stack	*ft_min(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*min;

	cur = *stack;
	min = cur;
	while (cur)
	{
		if (cur->content < min->content)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

/**
 * @brief Checks whether the source node's content is greater than the maximum or less than the minimum in the destination stack.
 *
 * This function checks if the content of the node from stack A (`node_a`) is either larger than
 * the maximum value or smaller than the minimum value in the destination stack (`stack_b`).
 * It returns the maximum node if this condition is met. Otherwise, it returns the minimum node.
 *
 * @param node_a The node from stack A whose content is being compared.
 * @param stack_b A pointer to the destination stack where the function will check the maximum and minimum values.
 *
 * @return A pointer to the node that represents either the maximum or minimum value in stack B, depending on the content of `node_a`.
 * 
 * @see ft_min() to get the minimum node in stack B.
 * @see ft_max() to get the maximum node in stack B.
 */
t_stack	*ck_new_min_max(t_stack *node_a, t_stack **stack_b)
{
	t_stack	*node_min;
	t_stack	*node_max;

	node_min = ft_min(stack_b);
	node_max = ft_max(stack_b);
	if (node_a->content > node_max->content \
	|| node_a->content < node_min->content)
		return (node_max);
	else
		return (node_min);
}
