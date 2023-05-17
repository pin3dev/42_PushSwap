/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clima-fr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:49:40 by clima-fr          #+#    #+#             */
/*   Updated: 2023/05/17 18:49:42 by clima-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
