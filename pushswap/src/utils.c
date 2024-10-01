/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:54:49 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/01 01:00:16 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Outputs an error message and terminates the program.
 *
 * This function writes the message "Error\n" to the standard error (file descriptor 2)
 * and exits the program with a status code of 1, indicating an error occurred.
 */
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/**
 * @brief Frees all nodes in the stack and resets the pointer to `NULL`.
 *
 * This function frees the memory allocated for each node in the stack, starting from the head.
 * It iterates through the stack and frees each node, setting the stack pointer to `NULL` at the end.
 *
 * @param stack A pointer to the head of the stack to be freed.
 */
void	free_stack(t_stack **stack)
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
/**
 * @brief Frees a split string array and sets its pointer to `NULL`.
 *
 * This function frees each string in the split string array and then sets the pointer
 * to `NULL` to avoid dangling pointers.
 *
 * @param str A pointer to the split string array that will be freed.
 */
void	free_split(char **str)
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

/**
 * @brief Skips leading whitespace characters in a string.
 *
 * This function skips over leading whitespace characters in the input string (`str`),
 * including spaces and special whitespace characters like tabs, newlines, and others.
 * If the string only contains whitespace, the function exits the program.
 *
 * @param str The input string from which leading spaces will be skipped.
 *
 * @return A pointer to the first non-whitespace character in the string.
 */
const char	*skip_spaces(const char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v' || \
*str == '\f' || *str == '\r' || *str == ' ')
		++str;
	if (*str == '\0')
		exit (0);
	return (&(*str));
}

/**
 * @brief Converts a string to an integer, with error checking.
 *
 * This function converts the input string (`str`) to an integer, handling optional leading spaces,
 * optional sign characters, and checking for non-numeric characters. If invalid characters are
 * encountered or if the converted value exceeds the range of a 32-bit signed integer
 * (`-2147483648` to `2147483647`), it calls `ft_error()` to handle the error.
 *
 * @param str The input string to be converted to an integer.
 *
 * @return The integer value represented by the input string.
 *
 * @note This function assumes that the input string represents a valid integer in base 10.
 * 
 * @see ft_error() to handle conversion errors.
 * @see skip_spaces() to skip leading whitespace.
 */
int	_atoi(const char *str)
{
	long long int	ret;
	int				sign;

	ret = 0;
	sign = 1;
	str = skip_spaces(str);
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