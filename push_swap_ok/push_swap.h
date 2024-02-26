/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:28:23 by aconti            #+#    #+#             */
/*   Updated: 2024/02/26 07:34:07 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	long			val;
	int				push;
	struct s_stack	*next;
}	t_stack;

void	print_stack(t_stack *stack);
//check
int		is_sorted_list(t_stack *list);
int		count_num(char **nptr);
int		is_sign(char av);
int		all_num(char **nptr);
int		ft_atoi(char **nptr, long int *nums);
int		ft_check(long int *nums, int i);
//init
void	array_to_stack(long int *arr, int size, t_stack **stack);
void	add_push(t_stack *new_node, int size, long int *arr);
float	media_array(long array[], int lunghezza);
//push
void	pa(t_stack **add, t_stack **take);
void	pb(t_stack **add, t_stack **take);
void	remove_first(t_stack **stack);
int		penality_rr_push(t_stack *a, int t);
int		penality_r_push(t_stack *a, int t);
int		find_direction_push(t_stack *a, int push, int A);
//rotate
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	rotate(t_stack **lst);
void	reverse_rotate(t_stack **lst);
void	do_rotate(t_stack **a, t_stack **b, int cod);
int		penality_rr(t_stack *a, int t);
int		penality_r(t_stack *a, int t);
int		find_direction_med(t_stack *a, int med, int A);
//sort
int		mid(t_stack *a);
double	media(t_stack *a);
int		counter(t_stack *a);
void	little_order_min(t_stack **a);
void	sort(t_stack **a, t_stack **b, int n);
//swap
void	sa(t_stack **a);
void	sb(t_stack **a);
void	ss(t_stack **a, t_stack **b);
void	check_ss(t_stack **a, t_stack **b);
//cont
void	cont(t_stack **a, t_stack **b);
//some utils
int		max(t_stack **stack);
int		type_rot_b(t_stack **stack);
void	free_stack(t_stack *head);

#endif
