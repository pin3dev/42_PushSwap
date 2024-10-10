/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:47:30 by ivbatist          #+#    #+#             */
/*   Updated: 2024/10/01 00:36:48 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdlib.h>
# include<unistd.h>
# include "../../../42_Libft/libft/inc/libft.h"

//////////////////////////////////////////////////ESTRUTURA
typedef struct stack
{
	int				content;
	struct stack	*next;
	int				mov;
	int				mov_orientation;
	int				total_mov;
	int				index;
}			t_stack;
//////////////////////////////////////////////////MAIN
int	pushswap(int ac, char **av);
//////////////////////////////////////////////////OPERATIONS
void		swap(t_stack **stack);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
void		push(t_stack **dest, t_stack **src);
//////////////////////////////////////////////////ALGORITHM
void		sort_3(t_stack **stack_a);
void		big_sort(t_stack **stack_a, t_stack **stack_b);
void		sort_cases(t_stack **stack_a);
void		mv_node_to_top_a(t_stack *node_a, t_stack**stack_a);
void		mv_node_to_top_ab(t_stack *node_a, t_stack *node_b, \
void		mv_node_to_top_b(t_stack *node_b, t_stack**stack_b);
void		rotate_to_finish(t_stack **stack_a, t_stack **stack_b);
void		back_to_a(t_stack **stack_a, t_stack **stack_b);
t_stack		*return_dest_place(t_stack *src, t_stack **dest);
t_stack		*find_best_case(t_stack **src);
t_stack		*fit_between(t_stack *src, t_stack **dest);
//////////////////////////////////////////////////ALGORITHM
int		put_index_n_def_mov_n_orient(t_stack **src, t_stack **dest);
void		find_place_n_def_total_mov(t_stack **src, t_stack **dest);
void		put_mov_and_orientation(int size, t_stack **stack);
void		put_total_mov(t_stack *src, t_stack *dest);
//////////////////////////////////////////////////UTILS
int		ck_doubles(t_stack **stack_a);
int		ck_sorted(t_stack **stack);
void		create_node(t_stack **head, char *str);
void		ft_error(void);
void		free_stack(t_stack **stack);
void		free_split(char **str);
t_stack		*ft_max(t_stack **stack);
t_stack		*ft_min(t_stack **stack);
t_stack		*ck_new_min_max(t_stack *node_a, t_stack **stack_b);
t_stack		*args_splited(char **split);
t_stack		*args_to_node(int ac, char **av);
//////////////////////////////////////////////////WRAPPED
int		ft_stacksize(t_stack *lst);
void		ft_stackadd_back(t_stack **lst, t_stack *new);
void		sa(t_stack **a);
void		ss(t_stack **a, t_stack **b);
void		sb(t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);
t_stack		*ft_stacklast(t_stack *lst);
//////////////////////////////////////////////////REFACTORED
int		_atoi(const char *str);
t_stack		*ft_stacknew(int content);
const char	*ft_skip_spaces(const char *str);

#endif
