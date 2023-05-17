/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:17:39 by ivbatist          #+#    #+#             */
/*   Updated: 2023/05/17 19:37:30 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

t_stack	*ft_check_new_min_max(t_stack *node_a, t_stack **stack_b)
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
