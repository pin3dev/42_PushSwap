/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:59:53 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/01 00:57:16 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Entry point for the push_swap program, handling input validation, sorting, and cleanup.
 *
 * The `pushswap` function is the main entry point of the push_swap program. It processes the command-line
 * arguments to create an initial stack (stack A), checks for duplicate values and whether the stack is already
 * sorted. If the stack is not sorted, it applies the appropriate sorting algorithm. After sorting, it frees
 * the memory allocated for the stack and exits.
 *
 * @param ac The argument count from the command-line input.
 * @param av The argument vector (array of strings) containing the input values to be sorted.
 * 
 * @return Returns 0 on successful execution.
 *
 * @note The function performs the following operations:
 * - Converts the command-line arguments into a linked list of stack nodes using `args_to_node()`.
 * - Checks for duplicate values in the stack using `ck_doubles()`. If duplicates are found, it frees the stack and displays an error.
 * - Verifies if the stack is already sorted using `ck_sorted()`. If the stack is not sorted, it calls `sort_cases()` to sort the stack.
 * - Frees the memory allocated for the stack using `free_stack()` after sorting or when an error is encountered.
 * - If any error occurs, it calls `ft_error()` to handle the error output.
 * 
 * @see args_to_node() to convert command-line arguments into a stack.
 * @see ck_doubles() to check for duplicate values in the stack.
 * @see ck_sorted() to verify if the stack is already sorted.
 * @see sort_cases() to handle the sorting process based on the stack's size.
 * @see free_stack() to free the memory allocated for the stack.
 * @see ft_error() to handle errors and display appropriate error messages.
 */
int	pushswap(int ac, char **av)
{
	t_stack	*head_a;

    head_a = args_to_node(ac, av);
    if (!head_a || ck_doubles(&head_a) == 1)
    {
        free_stack(&head_a);
        ft_error();
    }
    if (!ck_sorted(&head_a))
    {
        sort_cases(&head_a);
    }
    free_stack(&head_a);
    return (0);
}
