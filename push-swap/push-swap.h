#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	long			content;
    int             push;
	struct s_list	*next;
}					t_list;
//Direction.c
int penality_rr(t_list *a, int t);
int penality_r(t_list *a, int t);
int find_direction_med(t_list *a, int med, int A);
int find_direction_push(t_list *a, int push, int A);
int is_sorted_list(t_list *list);
//Main.c
int count_element(char **argv);
int ft_atoi(char **argv, long int *nums);
int is_sign(char av);
int ft_check(long int *nums, int i);
int mid(long int *array);
//Prepare_stack.c
void array_to_stack(long int *arr, int size, t_list **stack);
void add_push(t_list *new_node, int size, long int *arr);
long int sub_array(long int *arr);
long int mid_list(t_list *a);
int count_array(long int *array, int i);
//Push.c
void pb(t_list **add, t_list **take);
void pa(t_list **add, t_list **take);
//Rotate.c
void do_rotate(t_list **a, t_list **b, int cod);
int type_rot_b(t_list **stack);
void rev_rotate(t_list **stack);
void rotate(t_list **stack);
//Sort.c
void	sort(t_list **a, t_list **b, int n);
void pre_order(t_list **a, t_list **b);
int check_push(t_list **a, int i);
int	counter(t_list *a);
int	check_med(t_list *a, int med);
//Swap.c
void check_ss(t_list **a, t_list **b);
void ss(t_list **a, t_list **b);
void sb(t_list **a);
void sa(t_list **a);
//Utils.c
void little_check(t_list **a, t_list **b);
int is_sorted(long int *arr, int n);
int max(t_list **stack);
long int *stack_to_array(t_list *a);
void ft_lstclear(t_list *head);
# endif
