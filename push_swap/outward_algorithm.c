/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outward_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:15:20 by ivbatist          #+#    #+#             */
/*   Updated: 2023/05/17 16:15:22 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*ft_return_dest_place(t_stack *src, t_stack **dest)
{
	t_stack		*place;
	t_stack		*cur;

	place = ft_check_new_min_max(src, dest);
	cur = *dest;
	while (cur)
	{
		if (cur->content > src->content)
			cur = cur->next;
		else
		{
			if (cur->content > place->content)
				place = cur;
			cur = cur->next;
		}
	}
	return (place);
}

t_stack	*ft_find_best_case(t_stack **src)
{
	t_stack	*cur;
	t_stack	*best_case;
	int		less_mov;

	cur = *src;
	best_case = cur;
	less_mov = cur->total_mov;
	while (cur)
	{
		if (cur->total_mov < less_mov)
		{
			best_case = cur;
			less_mov = cur->total_mov;
		}
		cur = cur->next;
	}
	return (best_case);
}

void	ft_move_node_to_top_a(t_stack *node_a, t_stack**stack_a)
{
	if (node_a->mov_orientation == 0)
	{
		while (node_a->mov > 0)
		{
			ra(stack_a);
			node_a->mov--;
		}
	}
	else if (node_a->mov_orientation == 1)
	{
		while (node_a->mov > 0)
		{
			rra(stack_a);
			node_a->mov--;
		}
	}
}

void	ft_move_node_to_top_ab(t_stack *node_a, t_stack *node_b, \
t_stack**stack_a, t_stack**stack_b)
{
	int	mov_tog;

	mov_tog = node_a->mov;
	if (node_b->mov < mov_tog)
		mov_tog = node_b->mov;
	if (node_a->mov_orientation == 0 && node_b->mov_orientation == 0)
	{
		while (mov_tog > 0)
		{
			rr(stack_a, stack_b);
			mov_tog--;
			node_a->mov--;
			node_b->mov--;
		}
	}
	else if (node_a->mov_orientation == 1 && node_b->mov_orientation == 1)
	{
		while (mov_tog > 0)
		{
			rrr(stack_a, stack_b);
			mov_tog--;
			node_a->mov--;
			node_b->mov--;
		}
	}
}
