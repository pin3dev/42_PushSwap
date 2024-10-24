/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:17:18 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/25 00:56:19 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Moves a node to the top of stack B.
 *
 * This function moves the given node from stack B to the top, using
 * either rotation or reverse rotation operations, depending on the
 * movement orientation (`mov_orientation`). The movement is repeated
 * until the number of moves (`mov`) reaches zero.
 *
 * @param node_b The node in stack B that needs to be moved to the top.
 *               It contains the number of moves remaining and the movement orientation.
 * @param stack_b A pointer to stack B, which will be modified as the node is moved to the top.
 * 
 * @note If `mov_orientation` is 0, the stack will be rotated upwards using the `rb()` function.
 *       If it is 1, the stack will be rotated downwards using the `rrb()` function.
 */
void	mv_node_to_top_b(t_stack *node_b, t_stack**stack_b)
{
	if (node_b->mov_orientation == 0)
	{
		while (node_b->mov > 0)
		{
			rb(stack_b);
			node_b->mov--;
		}
	}
	else if (node_b->mov_orientation == 1)
	{
		while (node_b->mov > 0)
		{
			rrb(stack_b);
			node_b->mov--;
		}
	}
}

/**
 * @brief Finds the right position to insert a node into the destination stack.
 *
 * This function determines the right place to insert the `src` node into the `dest` stack,
 * so that the stack remains ordered. It searches for a node in the `dest` stack whose
 * content is greater than the `src` node's content but smaller than any other greater value found.
 *
 * @param src The node from the source stack that will be inserted into the destination stack.
 *            It contains the value (`content`) that needs to be placed in the correct position.
 * @param dest A pointer to the destination stack where the node will be inserted.
 *             The stack will be examined to find the right position for `src`.
 *
 * @return A pointer to the node in the destination stack that represents the ideal
 *         place to insert the `src` node.
 *
 * @note If `src->content` is greater than the maximum value in the `dest` stack,
 *       the function will return the node with the minimum value in the stack.
 * 
 * @see ft_max() to retrieve the maximum value from the stack.
 * @see ft_min() to retrieve the minimum value from the stack.
 */
t_stack	*fit_between(t_stack *src, t_stack **dest)
{
	t_stack	*place;
	t_stack	*cur;

	place = ft_max(dest);
	cur = *dest;
	if (src->content > place->content)
		place = ft_min(dest);
	while (cur)
	{
		if (cur->content < src->content)
			cur = cur->next;
		else
		{
			if (cur->content < place->content)
				place = cur;
			cur = cur->next;
		}
	}
	return (place);
}

/**
 * @brief Rotates the stack A to bring the smallest node to the top, completing the sorting process.
 *
 * This function identifies the node in stack A with the smallest value and rotates
 * stack A to move this node to the top, if necessary. It also updates the index, movement,
 * and orientation information for all nodes in both stack A and stack B.
 *
 * @param stack_a A pointer to stack A, which will be modified to move the smallest node to the top.
 * @param stack_b A pointer to stack B, which is used in calculating node indices, movement, and orientation.
 *
 * @note If the smallest node's index is greater than 0, it calls `mv_node_to_top_a()` to move the node to the top of stack A.
 * 
 * @see ft_min() to find the node with the minimum value in stack A.
 * @see put_index_n_def_mov_n_orient() to update the index, movement, and orientation for all nodes.
 * @see mv_node_to_top_a() to move the node to the top of stack A.
 */
void	rotate_to_finish(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_to_mov;

	node_to_mov = ft_min(stack_a);
	put_index_n_def_mov_n_orient(stack_a, stack_b);
	if (node_to_mov->index > 0)
		mv_node_to_top_a(node_to_mov, stack_a);
}

/**
 * @brief Moves all nodes from stack B back to stack A, ensuring correct placement.
 *
 * This function moves all nodes from stack B back to stack A in the correct order,
 * utilizing the `fit_between` function to determine where each node from stack B
 * should be placed in stack A. After all nodes have been moved, it calls `rotate_to_finish()`
 * to complete the sorting of stack A.
 *
 * @param stack_a A pointer to stack A, where nodes from stack B will be moved.
 * @param stack_b A pointer to stack B, from which nodes will be moved to stack A.
 * 
 * @note The function repeatedly calls `put_index_n_def_mov_n_orient()` to update
 *       node movement and orientation information. Each node is placed in the optimal position
 *       in stack A before being moved with the `pa()` function.
 *
 * @see put_index_n_def_mov_n_orient() to update index, movement, and orientation information.
 * @see fit_between() to find the correct place in stack A for the current node from stack B.
 * @see mv_node_to_top_a() to move a node to the top of stack A.
 * @see pa() to move a node from stack B to stack A.
 * @see rotate_to_finish() to complete the sorting of stack A.
 */
void	back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_to_mov;

	node_to_mov = *stack_b;
	while (put_index_n_def_mov_n_orient(stack_b, stack_a) > 0)
	{
		node_to_mov = fit_between(*stack_b, stack_a);
		mv_node_to_top_a(node_to_mov, stack_a);
		pa(stack_a, stack_b);
	}
	rotate_to_finish(stack_a, stack_b);
}
