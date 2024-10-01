/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:59:01 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/01 00:58:29 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Creates a new node and adds it to the end of the stack.
 *
 * This function converts the given string (`str`) into an integer using `_atoi()`
 * and creates a new node with that value. The new node is added to the end of the stack (`head`)
 * using `ft_stackadd_back()`.
 *
 * @param head A pointer to the head of the stack where the new node will be added.
 * @param str The string to be converted into an integer and used as the content of the new node.
 *
 * @see _atoi() to convert the string to an integer.
 * @see ft_stackadd_back() to add the new node to the end of the stack.
 * @see ft_stacknew() to create a new node with the given integer value.
 */
void	create_node(t_stack **head, char *str)
{
	int	numb;

	numb = _atoi(str);
	ft_stackadd_back(head, ft_stacknew(numb));
}

/**
 * @brief Converts a split string array into a stack of nodes.
 *
 * This function takes an array of split strings (`split`), converts each string into
 * an integer, and creates a corresponding node in a stack. It returns the head of the newly
 * created stack. If the split array is NULL or empty, the function frees the split array
 * and terminates the program.
 *
 * @param split A split string array to be converted into a stack of nodes.
 *
 * @return A pointer to the head of the newly created stack.
 *
 * @note The function calls `create_node()` to create each node and `free_split()` to free the split array if needed.
 * 
 * @see create_node() to add each value as a node to the stack.
 * @see free_split() to free the split array in case of an error.
 */
t_stack	*args_splited(char **split)
{
	t_stack	*head_a;
	int		i;

	head_a = NULL;
	if (*split == NULL || split == NULL)
	{	
		free_split(split);
		free(split);
		exit (0);
	}
	i = 0;
	while (split[i])
	{
		create_node(&head_a, split[i]);
		i++;
	}
	return (head_a);
}

/**
 * @brief Converts command-line arguments into a stack of nodes.
 *
 * This function converts the command-line arguments into a linked list of stack nodes. If only one argument
 * is passed (when `ac == 2`), it splits the argument using `ft_split()` and processes it with `args_splited()`.
 * Otherwise, it directly processes each argument by calling `create_node()` for each.
 *
 * @param ac The argument count from the command-line input.
 * @param av The argument vector (array of strings) containing the values to be converted into nodes.
 *
 * @return A pointer to the head of the newly created stack.
 *
 * @note 
 * - If `ac == 2`, the function splits the single argument into multiple strings using `ft_split()`.
 * - After processing, the split array is freed using `free_split()` and `free()`.
 * 
 * @see ft_split() to split the input string into separate components.
 * @see args_splited() to convert the split components into a stack.
 * @see create_node() to add each argument as a node to the stack.
 * @see free_split() to free the memory used by the split array.
 */
t_stack	*args_to_node(int ac, char **av)
{
	t_stack	*head_a;
	char	**split;
	int		i;

	head_a = NULL;
	if (ac == 2)
	{
		split = ft_split(av[1], 32);
		head_a = args_splited(split);
		free_split(split);
		free(split);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			create_node(&head_a, av[i]);
			i++;
		}
	}
	return (head_a);
}

