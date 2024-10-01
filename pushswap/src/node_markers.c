/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_markers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:08:31 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/01 00:54:57 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Determines the right destination position for each node in the source stack and calculates the total movements required.
 *
 * This function iterates through the source stack (`src`), finding the appropriate place in the destination stack (`dest`) for each node.
 * It compares the contents of the nodes to find the best insertion point in `dest` for each node in `src`. Once the optimal place
 * is found, the total number of movements required to move the node to that position is calculated and stored.
 *
 * @param src A pointer to the source stack, where each node will be evaluated and assigned a destination in the destination stack.
 * @param dest A pointer to the destination stack, where the function will search for the appropriate position for each node from `src`.
 *
 * @note 
 * - The function calls `ck_new_min_max()` to determine the initial candidate place for each node in the source stack.
 * - It iterates through the destination stack to compare the contents and update the best place for each node.
 * - After determining the best destination position for a node in `src`, the function calls `put_total_mov()` to calculate
 *   the total movements required for the node to reach that position in `dest`.
 * 
 * @see ck_new_min_max() to handle the boundary conditions and find an initial place in the destination stack.
 * @see put_total_mov() to calculate and store the total movements required to move a node to its destination.
 */
void	find_place_n_def_total_mov(t_stack **src, t_stack **dest)
{
	t_stack	*cur_src;
	t_stack	*place;
	t_stack	*cur_dest;

	cur_src = *src;
	cur_dest = *dest;
	while (cur_src)
	{
		place = ck_new_min_max(cur_src, dest);
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
		put_total_mov(cur_src, place);
		cur_dest = *dest;
		cur_src = cur_src->next;
	}
}

/**
 * @brief Assigns index values and determines movement and orientation for nodes in both source and destination stacks.
 *
 * This function iterates through both the source (`src`) and destination (`dest`) stacks, assigning index values
 * to each node and calculating the required movements and orientations to move the nodes to their appropriate positions.
 * The index values are set sequentially for each node based on their position in the stack, starting from 0.
 * The function also calculates the number of elements in the source stack and returns that value.
 *
 * @param src A pointer to the source stack, where index values and movements will be assigned.
 * @param dest A pointer to the destination stack, where index values and movements will also be assigned.
 *
 * @return The number of elements in the source stack (`src`), which is the total number of nodes indexed in that stack.
 *
 * @note 
 * - The function assigns an index value (`index`) to each node in the stacks, based on its position in the stack.
 * - After assigning the index values, the function calls `put_mov_and_orientation()` to calculate the required movements
 *   and orientations for each node in both `src` and `dest`.
 * 
 * @see put_mov_and_orientation() to calculate the movements and orientations for the nodes in the stacks.
 */
int	put_index_n_def_mov_n_orient(t_stack **src, t_stack **dest)
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
	put_mov_and_orientation(i, src);
	cur = *dest;
	while (cur)
	{
		cur->index = j;
		cur = cur->next;
		j++;
	}
	put_mov_and_orientation(j, dest);
	return (i);
}

/**
 * @brief Determines the number of movements and their orientation for each node in a stack.
 *
 * This function calculates the required movements (`mov`) and the movement orientation (`mov_orientation`)
 * for each node in a stack. The movement is determined based on the node's position (index) relative
 * to the size of the stack. If the node is in the first half of the stack, the movement is upwards
 * (`mov_orientation` = 0), while if the node is in the second half, the movement is downwards (`mov_orientation` = 1).
 *
 * @param size The total number of nodes in the stack.
 * @param stack A pointer to the stack, where each node's movement and orientation will be calculated and updated.
 *
 * @note 
 * - If a node's index is less than or equal to half the stack's size, the movement is upwards (`mov_orientation` = 0).
 * - If a node's index is greater than half the stack's size, the movement is downwards (`mov_orientation` = 1).
 * - The `mov` field represents how many movements are required to bring the node to the top of the stack.
 */
void	put_mov_and_orientation(int size, t_stack **stack)
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

/**
 * @brief Calculates the total number of movements required to move a node from the source stack to its destination position.
 *
 * This function calculates the total movements (`total_mov`) required for a node in the source stack (`src`)
 * to reach its appropriate position in the destination stack (`dest`). The total movement is determined
 * based on the movement orientations of both nodes. If the movement orientations are the same, the total movement
 * is the maximum of the two movement values. If the orientations differ, the total movement is the sum of both movements.
 *
 * @param src A pointer to the node in the source stack, for which the total movements will be calculated.
 * @param dest A pointer to the node in the destination stack, representing the target position for the source node.
 *
 * @note 
 * - If `src` and `dest` have the same movement orientation (`mov_orientation`), the total movement is set to the larger of `src->mov` and `dest->mov`.
 * - If `src` and `dest` have different movement orientations, the total movement is the sum of `src->mov` and `dest->mov`.
 */
void	put_total_mov(t_stack *src, t_stack *dest)
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
