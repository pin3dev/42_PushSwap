/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:11:46 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/25 00:56:19 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts a stack of three elements in ascending order.
 *
 * This function handles sorting a stack with exactly three elements by identifying
 * the maximum and minimum values in the stack. It then performs the necessary
 * operations (swaps and rotations) to sort the stack in ascending order.
 *
 * @param stack_a A pointer to stack A, which contains exactly three elements to be sorted.
 *
 * @note The function compares the nodes in the stack based on their content values, @see https://t.ly/qhqhS
 *
 * @see ft_max() to determine the maximum value in stack A.
 * @see ft_min() to determine the minimum value in stack A.
 * @see sa() to swap the first two elements of stack A.
 * @see ra() to rotate stack A upwards.
 * @see rra() to reverse rotate stack A downwards.
 */
void	sort_3(t_stack **stack_a)
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

/**
 * @brief Sorts a stack with more than three elements using an advanced sorting algorithm.
 *
 * The `big_sort` function sorts a large stack by moving elements between stack A and stack B
 * using a combination of operations. It repeatedly moves nodes from stack A to stack B,
 * adjusting their positions based on the number of movements needed and their relative positions
 * in stack A and stack B. The process continues until all elements are properly sorted in stack A.
 *
 * @param stack_a A pointer to stack A, which initially contains the elements to be sorted.
 * @param stack_b A pointer to stack B, which serves as a temporary holding stack during the sorting process.
 *
 * @note The function performs the Turk Algorithm, @see https://t.ly/qhqhS
 * - Moves two elements from stack A to stack B using the `pb()` function.
 * - Calculates and assigns the index, movement, and orientation for each node in both stacks using `put_index_n_def_mov_n_orient()`.
 * - Repeatedly finds the best candidate (`node_src`) from stack A and the best destination (`node_dest`) in stack B.
 * - Moves the nodes to the top of their respective stacks, using either simultaneous rotations (`mv_node_to_top_ab()`) if they share the same movement orientation, or individual rotations (`mv_node_to_top_a()` and `mv_node_to_top_b()`).
 * - Transfers nodes from stack A to stack B using `pb()` and updates the stack state until the stack is sorted.
 * 
 * The process continues until the size of stack A is reduced to 3 elements or it is sorted (`ck_sorted()` returns 1).
 *
 * @see pb() to move an element from stack A to stack B.
 * @see put_index_n_def_mov_n_orient() to calculate the index, movement, and orientation of each node.
 * @see find_place_n_def_total_mov() to find the best place for each node and determine the total movements required.
 * @see find_best_case() to find the node in stack A that requires the fewest movements.
 * @see return_dest_place() to find the appropriate place for a node in stack B.
 * @see mv_node_to_top_ab() to move nodes to the top of both stacks simultaneously.
 * @see mv_node_to_top_a() to move a node to the top of stack A.
 * @see mv_node_to_top_b() to move a node to the top of stack B.
 * @see ck_sorted() to check if stack A is sorted.
 */
void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_src;
	t_stack	*node_dest;
	int		size;

	node_src = *stack_a;
	node_dest = *stack_b;
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	size = put_index_n_def_mov_n_orient(stack_a, stack_b);
	find_place_n_def_total_mov(stack_a, stack_b);
	while (size > 3 && ck_sorted(stack_a) == 0)
	{
		node_src = find_best_case(stack_a);
		node_dest = return_dest_place(node_src, stack_b);
		if (node_src->mov_orientation == node_dest->mov_orientation)
			mv_node_to_top_ab(node_src, node_dest, stack_a, stack_b);
		if (node_src->mov > 0)
			mv_node_to_top_a(node_src, stack_a);
		if (node_dest->mov > 0)
			mv_node_to_top_b(node_dest, stack_b);
		pb(stack_b, stack_a);
		size = put_index_n_def_mov_n_orient(stack_a, stack_b);
		find_place_n_def_total_mov(stack_a, stack_b);
	}
}

/**
 * @brief Sorts a stack based on its size using appropriate sorting strategies.
 *
 * The `sort_cases` function handles sorting the stack by selecting the appropriate sorting method
 * based on the number of elements in stack A. It sorts stacks of size 2, 3, 4, or larger, using
 * different strategies tailored to the stack's size.
 *
 * @param stack_a A pointer to stack A, which contains the elements to be sorted.
 *
 * @note The function follows these steps based on the size of the stack:
 * - If stack A has 2 elements, it simply swaps the two elements using `sa()`.
 * - If stack A has 4 elements, one element is moved to stack B using `pb()` before sorting.
 * - If stack A has 5 or more elements, it applies the `big_sort()` algorithm to perform an efficient sort.
 * - For stacks of size 3, the `sort_3()` function is used to handle sorting.
 * - After sorting, if any elements were moved to stack B, they are moved back to stack A using `back_to_a()`.
 * 
 * @see sa() to swap the top two elements of stack A.
 * @see pb() to move an element from stack A to stack B.
 * @see big_sort() to sort stacks with 5 or more elements.
 * @see sort_3() to sort exactly 3 elements in stack A.
 * @see back_to_a() to move elements from stack B back to stack A after sorting.
 * @see ft_stacksize() to determine the size of stack A.
 */
void	sort_cases(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_stacksize(*stack_a) == 2)
		sa(stack_a);
	else
	{
		if (ft_stacksize(*stack_a) == 4)
			pb(&stack_b, stack_a);
		if (ft_stacksize(*stack_a) >= 5)
		{
			big_sort(stack_a, &stack_b);
		}
		sort_3(stack_a);
		if (stack_b)
			back_to_a(stack_a, &stack_b);
	}
}
