/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:24:23 by pin3dev           #+#    #+#             */
/*   Updated: 2024/10/01 00:57:45 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Checks for duplicate values in the stack.
 *
 * This function iterates through the stack (`stack_a`) to check if any two nodes contain the same value.
 * If a duplicate value is found, it returns 1, indicating the presence of duplicates. If no duplicates
 * are found, it returns 0.
 *
 * @param stack_a A pointer to the stack that will be checked for duplicate values.
 *
 * @return Returns 1 if a duplicate value is found, and 0 if no duplicates are found.
 *
 * @note The function performs a nested loop to compare each node's content with every other node's content.
 */
int	ck_doubles(t_stack **stack_a)
{
	t_stack	*i;
	t_stack	*j;

	i = *stack_a;
	j = i->next;
	while (i && j)
	{
		while (j)
		{
			if (i->content == j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
		j = i->next;
	}
	return (0);
}

/**
 * @brief Checks if the stack is sorted in ascending order.
 *
 * This function iterates through the stack to check if its values are sorted in ascending order.
 * If any node is found where its value is greater than the next node's value, the function returns 0,
 * indicating that the stack is not sorted. If the stack is fully sorted, it returns 1.
 *
 * @param stack A pointer to the stack that will be checked for sorting.
 *
 * @return Returns 1 if the stack is sorted in ascending order, and 0 if it is not sorted.
 */
int	ck_sorted(t_stack **stack)
{
	t_stack	*cmp;
	t_stack	*i;

	cmp = *stack;
	i = cmp->next;
	while (cmp && i)
	{
		while (i)
		{
			if (cmp->content > i->content)
				return (0);
			i = i->next;
		}
		cmp = cmp->next;
		i = cmp->next;
	}
	return (1);
}