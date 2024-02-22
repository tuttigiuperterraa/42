/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 07:54:29 by gcosenza          #+#    #+#             */
/*   Updated: 2024/02/22 07:54:29 by gcosenza         ###   ########.fr       */
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
	long		val;
	int			push;
	struct s_stack	*next;
}t_stack;

//check.c
int is_sorted_list(t_stack *list);
int check_push(t_stack **a, int i);
void check_ss(t_stack **a, t_stack **b);
void little_check(t_stack **a, t_stack **b);
int ft_check(long int *nums, int i);
//main.c
int is_sign(char av);
int ft_atoi(char **nptr, long int *nums);
int is_sorted(long int *arr, int n);
int main(int argc, char **argv);
//math.c
int	counter(t_stack *a);
double	media(t_stack *a);
int max(t_stack **stack);
float media_array(long array[], int lunghezza);
int count_num(char **nptr);
//push.c
void pa(t_stack **add, t_stack **take);
void pb(t_stack **add, t_stack **take);
void add_push(t_stack *new_node, int size, long int *arr);
int find_direction_push(t_stack *a, int push, int A);
int penality_r_push(t_stack *a, int t);
int penality_rr_push(t_stack *a, int t);
//rotate.c
int type_rot_b(t_stack **stack, int value);
void do_rotate(t_stack **a, t_stack **b, int cod);
void rotate(t_stack **lst);
void reverse_rotate(t_stack **lst);
//sort.c
void pre_order(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b, int n);
//swap.c
void sa(t_stack **a);
void sb(t_stack **a);
void ss(t_stack **a, t_stack **b);
//utils.c
void free_stack(t_stack *head);
void remove_first(t_stack **stack);
void cont(t_stack **a, t_stack **b);
void array_to_stack(long int *arr, int size, t_stack **stack);

# endif