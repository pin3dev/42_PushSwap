/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:11:46 by ivbatist          #+#    #+#             */
/*   Updated: 2023/05/17 19:56:56 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_sort_3(t_stack **stack_a)
{
	t_stack	*x;
	t_stack	*y;
	t_stack	*z;

	x = *stack_a;
	y = (*stack_a)->next;
	z = y->next;
	if (ft_max(stack_a) == z && ft_min(stack_a) == y)
		sa(stack_a);
	if (ft_max(stack_a) == x && ft_min(stack_a) == z)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (ft_max(stack_a) == x && ft_min(stack_a) == y)
		ra(stack_a);
	if (ft_max(stack_a) == y && ft_min(stack_a) == x)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (ft_max(stack_a) == y && ft_min(stack_a) == z)
		rra(stack_a);
}

void	ft_big_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_src;
	t_stack	*node_dest;
	int		size;

	node_src = *stack_a;
	node_dest = *stack_b;
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	size = ft_put_index_n_def_mov_n_orient(stack_a, stack_b);
	ft_find_place_n_def_total_mov(stack_a, stack_b);
	while (size > 3 && ft_check_sorted(stack_a) == 0)
	{
		node_src = ft_find_best_case(stack_a);
		node_dest = ft_return_dest_place(node_src, stack_b);
		if (node_src->mov_orientation == node_dest->mov_orientation)
			ft_move_node_to_top_ab(node_src, node_dest, stack_a, stack_b);
		if (node_src->mov > 0)
			ft_move_node_to_top_a(node_src, stack_a);
		if (node_dest->mov > 0)
			ft_move_node_to_top_b(node_dest, stack_b);
		pb(stack_b, stack_a);
		size = ft_put_index_n_def_mov_n_orient(stack_a, stack_b);
		ft_find_place_n_def_total_mov(stack_a, stack_b);
	}
}

void	ft_sort_cases(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else
	{
		if (ft_lstsize(*stack_a) == 4)
			pb(&stack_b, stack_a);
		if (ft_lstsize(*stack_a) >= 5)
		{
			ft_big_sort(stack_a, &stack_b);
		}
		ft_sort_3(stack_a);
		if (stack_b)
			ft_back_to_a(stack_a, &stack_b);
	}
}
