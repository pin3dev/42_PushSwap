/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_going.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:15:20 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/25 00:56:19 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the appropriate destination place for a source node within the destination stack.
 *
 * This function determines the most suitable position for inserting the `src` node into the `dest` stack.
 * It searches through the destination stack to find a node that fits the correct ordering criteria. If the
 * source node's content is smaller than any node's content in the destination stack, the function tries to 
 * find a larger value but smaller than the already selected place.
 *
 * @param src The node from the source stack that needs to be placed in the destination stack.
 *            It contains the content that will be evaluated against the nodes in the destination stack.
 * @param dest A pointer to the destination stack where the function will search for the appropriate place.
 *
 * @return A pointer to the node in the destination stack that represents the optimal place for inserting the source node.
 *
 * @note The function initially checks for the minimum or maximum boundary for the destination stack 
 *       using `ck_new_min_max()`. It then iterates through the stack to find the most suitable insertion point.
 * 
 * @see ck_new_min_max() to handle the boundary conditions when checking the destination stack.
 */
t_stack	*return_dest_place(t_stack *src, t_stack **dest)
{
	t_stack		*place;
	t_stack		*cur;

	place = ck_new_min_max(src, dest);
	cur = *dest;
	while (cur)
	{
		if (cur->content > src->content)
			cur = cur->next;
		else
		{
			if (cur->content > place->content)
				place = cur;
			cur = cur->next;
		}
	}
	return (place);
}

/**
 * @brief Finds the node with the fewest total movements in the source stack.
 *
 * This function iterates through the source stack (`src`) to find the node that requires
 * the least number of movements (`total_mov`) to be properly placed in the destination stack.
 * It returns the node representing the "best case" based on this criterion.
 *
 * @param src A pointer to the source stack, where the function will search for the node
 *            with the fewest total movements.
 *
 * @return A pointer to the node with the smallest `total_mov` value, representing the
 *         best candidate for the next operation.
 * 
 * @note The function assumes that the `total_mov` field is already populated for each node
 *       in the source stack.
 */
t_stack	*find_best_case(t_stack **src)
{
	t_stack	*cur;
	t_stack	*best_case;
	int		less_mov;

	cur = *src;
	best_case = cur;
	less_mov = cur->total_mov;
	while (cur)
	{
		if (cur->total_mov < less_mov)
		{
			best_case = cur;
			less_mov = cur->total_mov;
		}
		cur = cur->next;
	}
	return (best_case);
}

/**
 * @brief Moves a node to the top of stack A.
 *
 * This function moves the given node from stack A to the top, using either
 * a rotation (`ra()`) or reverse rotation (`rra()`) operation, depending on
 * the movement orientation (`mov_orientation`). The movement is repeated until
 * the number of moves (`mov`) reaches zero.
 *
 * @param node_a The node in stack A that needs to be moved to the top. It contains
 *               the number of remaining moves and the movement orientation.
 * @param stack_a A pointer to stack A, which will be modified as the node is moved to the top.
 *
 * @note If `mov_orientation` is 0, the stack will be rotated upwards using the `ra()` function.
 *       If it is 1, the stack will be rotated downwards using the `rra()` function.
 * 
 * @see ra() to perform a rotation on stack A.
 * @see rra() to perform a reverse rotation on stack A.
 */
void	mv_node_to_top_a(t_stack *node_a, t_stack**stack_a)
{
	if (node_a->mov_orientation == 0)
	{
		while (node_a->mov > 0)
		{
			ra(stack_a);
			node_a->mov--;
		}
	}
	else if (node_a->mov_orientation == 1)
	{
		while (node_a->mov > 0)
		{
			rra(stack_a);
			node_a->mov--;
		}
	}
}


/**
 * @brief Moves two nodes simultaneously to the top of stack A and stack B.
 *
 * This function moves the nodes `node_a` and `node_b` to the top of their respective
 * stacks, `stack_a` and `stack_b`, by either performing double rotation (`rr()`) or
 * double reverse rotation (`rrr()`). The number of movements performed is the minimum
 * between the moves required for `node_a` and `node_b`. The movement continues until
 * both nodes reach the top, adjusting their `mov` values accordingly.
 *
 * @param node_a The node from stack A that needs to be moved to the top.
 * @param node_b The node from stack B that needs to be moved to the top.
 * @param stack_a A pointer to stack A, which will be modified to move `node_a` to the top.
 * @param stack_b A pointer to stack B, which will be modified to move `node_b` to the top.
 *
 * @note 
 * - If both `node_a` and `node_b` have `mov_orientation` set to 0, the function uses `rr()`
 *   to rotate both stacks upwards simultaneously.
 * - If both nodes have `mov_orientation` set to 1, the function uses `rrr()` to reverse rotate
 *   both stacks downwards simultaneously.
 * - The movement stops when both nodes reach their respective positions at the top of their stacks.
 * 
 * @see rr() to rotate both stack A and stack B simultaneously upwards.
 * @see rrr() to reverse rotate both stack A and stack B simultaneously downwards.
 */
void	mv_node_to_top_ab(t_stack *node_a, t_stack *node_b, \
t_stack**stack_a, t_stack**stack_b)
{
	int	mov_tog;

	mov_tog = node_a->mov;
	if (node_b->mov < mov_tog)
		mov_tog = node_b->mov;
	if (node_a->mov_orientation == 0 && node_b->mov_orientation == 0)
	{
		while (mov_tog > 0)
		{
			rr(stack_a, stack_b);
			mov_tog--;
			node_a->mov--;
			node_b->mov--;
		}
	}
	else if (node_a->mov_orientation == 1 && node_b->mov_orientation == 1)
	{
		while (mov_tog > 0)
		{
			rrr(stack_a, stack_b);
			mov_tog--;
			node_a->mov--;
			node_b->mov--;
		}
	}
}
