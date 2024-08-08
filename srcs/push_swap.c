/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:59:53 by ivbatist          #+#    #+#             */
/*   Updated: 2024/08/08 15:06:04 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*head_a;

	if (ac < 2)
		return (0);
	else
	{
		head_a = ft_check_arg_and_create_stack_a(ac, av);
		if (!head_a || ft_check_doubles(&head_a) == 1)
		{
			ft_freelst(&head_a);
			ft_error();
		}
		if (!ft_check_sorted(&head_a))
		{
			ft_sort_cases(&head_a);
		}
		ft_freelst(&head_a);
	}
}
