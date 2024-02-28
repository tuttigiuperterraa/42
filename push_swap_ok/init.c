/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:57 by gcosenza          #+#    #+#             */
/*   Updated: 2024/02/28 08:18:04 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	return ;
}

void	array_to_stack(long int *arr, int size, t_stack **stack)
{
	t_stack	*new_node;
	int		i;

	i = size - 1;
	while (i >= 0)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			f(*stack);
		new_node->val = arr[i];
		if (size > 50)
			add_push(new_node, size, arr);
		else
			new_node->push = 0;
		new_node->next = *stack;
		*stack = new_node;
		i--;
	}
}

void	add_push(t_stack *new_node, int size, long int *arr)
{
	float	media;

	media = media_array(arr, size);
	if (new_node->val < media / 4)
		new_node->push = 1;
	else if (new_node->val < media / 3)
		new_node->push = 2;
	else if (new_node->val < media / 2)
		new_node->push = 3;
	else if (new_node->val < media / 1.5)
		new_node->push = 4;
	else if (new_node->val < media)
		new_node->push = 5;
	else
		new_node->push = 6;
}

int	penality_r(t_stack *a, int t)
{
	int		pi;
	int		i;
	t_stack	*head;

	head = a;
	i = 0;
	pi = 0;
	while (i++ < counter(a) / 2)
	{
		if (head->push >= t)
			break ;
		pi++;
		head = head->next;
	}
	return (pi);
}

int	penality_rr(t_stack *a, int t)
{
	int		pj;
	int		j;
	t_stack	*mid;
	int		tmp;

	mid = a;
	pj = 0;
	tmp = 0;
	j = 0;
	while (j++ < counter(a) / 2 - 1)
		mid = mid->next;
	while (mid)
	{
		if (mid->val <= t)
			tmp = pj;
		pj++;
		mid = mid->next;
	}
	return (counter(a) / 2 - tmp);
}
