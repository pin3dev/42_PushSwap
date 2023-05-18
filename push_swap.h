/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:47:30 by ivbatist          #+#    #+#             */
/*   Updated: 2023/05/17 22:47:39 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdlib.h>
# include<unistd.h>
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
//////////////////////////////////////////////////FT GERAIS
void		ft_error(void);
int			ft_isdigit(int c);
//////////////////////////////////////////////////FT GERAIS LISTA
t_stack		*ft_lstnew(int content);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);
//////////////////////////////////////////////////FT VERIFICA MAIN
int			ft_atoi(const char *str);
const char	*ft_skip_spaces(const char *str);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
void		ft_create_node(t_stack **head, char *str);
void		ft_freelst(t_stack **stack);
void		ft_freesplit(char **str);
t_stack		*ft_check_arg_and_create_stack_a(int ac, char **av);
t_stack		*ft_args_splited(char **split);
int			ft_check_doubles(t_stack **stack_a);
int			ft_check_sorted(t_stack **stack);
//////////////////////////////////////////////////FT MOVIMENTO
void		swap(t_stack **stack);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
void		push(t_stack **dest, t_stack **src);
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
//////////////////////////////////////////////////FT ALGORITMO
t_stack		*ft_max(t_stack **stack);
t_stack		*ft_min(t_stack **stack);
t_stack		*ft_check_new_min_max(t_stack *node_a, t_stack **stack_b);
t_stack		*ft_return_dest_place(t_stack *src, t_stack **dest);
void		ft_find_place_n_def_total_mov(t_stack **src, t_stack **dest);
int			ft_put_index_n_def_mov_n_orient(t_stack **src, t_stack **dest);
void		ft_put_mov_and_orientation(int size, t_stack **stack);
void		ft_put_total_mov(t_stack *src, t_stack *dest);
t_stack		*ft_find_best_case(t_stack **src);
void		ft_move_node_to_top_a(t_stack *node_a, t_stack**stack_a);
void		ft_move_node_to_top_b(t_stack *node_b, t_stack**stack_b);
void		ft_move_node_to_top_ab(t_stack *node_a, t_stack *node_b, \
t_stack**stack_a, t_stack**stack_b);
t_stack		*ft_fit_between(t_stack *src, t_stack **dest);
void		ft_rotate_to_finish(t_stack **stack_a, t_stack **stack_b);
void		ft_back_to_a(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_3(t_stack **stack_a);
void		ft_big_sort(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_cases(t_stack **stack_a);

#endif
