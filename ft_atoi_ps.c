/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:44:01 by ivbatist          #+#    #+#             */
/*   Updated: 2023/05/17 21:42:51 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_isdigit(int c)
{		
	if ((c >= '0') && (c <= '9'))
	{
		return (2048);
	}
	else
	{
		return (0);
	}
}

const char	*ft_skip_spaces(const char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v' || \
*str == '\f' || *str == '\r' || *str == ' ')
		++str;
	if (*str == '\0')
		exit (0);
	return (&(*str));
}

int	ft_atoi(const char *str)
{
	long long int	ret;
	int				sign;

	ret = 0;
	sign = 1;
	str = ft_skip_spaces(str);
	if (*str && (*str == 43 || *str == 45))
	{
		if (*str == 45)
			sign = -1;
		if (!ft_isdigit(*++str))
			ft_error();
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		ret *= 10;
		ret += (sign * (*(str++) - 48));
	}
	if (ret > 2147483647 || ret < -2147483648)
		ft_error();
	return (ret);
}
