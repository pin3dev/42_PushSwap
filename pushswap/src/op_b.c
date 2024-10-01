/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:48:13 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/01 00:15:07 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sb(t_stack **b)
{
	swap(&(*b));
	write(1, "sb\n", 3);
}

void	rb(t_stack **b)
{
	rotate(&(*b));
	write(1, "rb\n", 3);
}

void	rrb(t_stack **b)
{
	reverse_rotate(&(*b));
	write(1, "rrb\n", 4);
}

void	pb(t_stack **b, t_stack **a)
{
	push(&(*b), &(*a));
	write(1, "pb\n", 3);
}
