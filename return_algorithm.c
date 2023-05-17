/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:17:18 by ivbatist          #+#    #+#             */
/*   Updated: 2023/05/17 19:44:06 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_move_node_to_top_b(t_stack *node_b, t_stack**stack_b)
{
	if (node_b->mov_orientation == 0)
	{
		while (node_b->mov > 0)
		{
			rb(stack_b);
			node_b->mov--;
		}
	}
	else if (node_b->mov_orientation == 1)
	{
		while (node_b->mov > 0)
		{
			rrb(stack_b);
			node_b->mov--;
		}
	}
}

t_stack	*ft_fit_between(t_stack *src, t_stack **dest)
{
	t_stack	*place;
	t_stack	*cur;

	place = ft_max(dest);
	cur = *dest;
	if (src->content > place->content)
		place = ft_min(dest);
	while (cur)
	{
		if (cur->content < src->content)
			cur = cur->next;
		else
		{
			if (cur->content < place->content)
				place = cur;
			cur = cur->next;
		}
	}
	return (place);
}

void	ft_rotate_to_finish(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_to_mov;

	node_to_mov = ft_min(stack_a);
	ft_put_index_n_def_mov_n_orient(stack_a, stack_b);
	if (node_to_mov->index > 0)
		ft_move_node_to_top_a(node_to_mov, stack_a);
}

void	ft_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_to_mov;

	node_to_mov = *stack_b;
	while (ft_put_index_n_def_mov_n_orient(stack_b, stack_a) > 0)
	{
		node_to_mov = ft_fit_between(*stack_b, stack_a);
		ft_move_node_to_top_a(node_to_mov, stack_a);
		pa(stack_a, stack_b);
	}
	ft_rotate_to_finish(stack_a, stack_b);
}
