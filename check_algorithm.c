/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:08:31 by ivbatist          #+#    #+#             */
/*   Updated: 2023/05/17 19:36:03 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_find_place_n_def_total_mov(t_stack **src, t_stack **dest)
{
	t_stack	*cur_src;
	t_stack	*place;
	t_stack	*cur_dest;

	cur_src = *src;
	cur_dest = *dest;
	while (cur_src)
	{
		place = ft_check_new_min_max(cur_src, dest);
		while (cur_dest)
		{
			if (cur_dest->content > cur_src->content)
				cur_dest = cur_dest->next;
			else
			{
				if (cur_dest->content > place->content)
					place = cur_dest;
				cur_dest = cur_dest->next;
			}
		}
		ft_put_total_mov(cur_src, place);
		cur_dest = *dest;
		cur_src = cur_src->next;
	}
}

int	ft_put_index_n_def_mov_n_orient(t_stack **src, t_stack **dest)
{
	int		i;
	int		j;
	t_stack	*cur;

	cur = *src;
	i = 0;
	j = 0;
	while (cur)
	{
		cur->index = i;
		cur = cur->next;
		i++;
	}
	ft_put_mov_and_orientation(i, src);
	cur = *dest;
	while (cur)
	{
		cur->index = j;
		cur = cur->next;
		j++;
	}
	ft_put_mov_and_orientation(j, dest);
	return (i);
}

void	ft_put_mov_and_orientation(int size, t_stack **stack)
{
	t_stack	*cur;

	cur = *stack;
	while (cur)
	{
		if (cur->index <= (size) / 2)
		{
			cur->mov = cur->index;
			cur->mov_orientation = 0;
		}
		else
		{
			cur->mov = (size - (cur->index));
			cur->mov_orientation = 1;
		}
		cur = cur->next;
	}
}

void	ft_put_total_mov(t_stack *src, t_stack *dest)
{
	if (src->mov_orientation == dest->mov_orientation)
	{
		if (src->mov > dest->mov)
			src->total_mov = src->mov;
		else
			src->total_mov = dest->mov;
	}
	else
		src->total_mov = src->mov + dest->mov;
}
