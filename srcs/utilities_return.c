/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:54:49 by ivbatist          #+#    #+#             */
/*   Updated: 2024/08/08 15:06:27 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_freelst(t_stack **stack)
{
	t_stack	*cur;

	if (!stack)
		return ;
	while (*stack)
	{
		cur = (*stack)->next;
		(*stack)->content = 0;
		free(*stack);
		*stack = cur;
	}
}

void	ft_freesplit(char **str)
{
	char	*s1;

	if (!str)
		return ;
	while (*str)
	{
		s1 = *str;
		str++;
		free(s1);
	}
	*str = NULL;
}
