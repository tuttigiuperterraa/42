/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:57 by gcosenza          #+#    #+#             */
/*   Updated: 2024/02/26 08:50:26 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **lst)
{
	t_stack	*first;
	t_stack	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	*lst = first->next;
	first->next = NULL;
	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = first;
}

void	reverse_rotate(t_stack **lst)
{
	t_stack	*second_last = NULL;
	t_stack	*last;

	last = *lst;
	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *lst;
	second_last->next = NULL;
	*lst = last;
}

void	do_rotate(t_stack **a, t_stack **b, int cod)
{
	if (cod == 1 && a && *a && (*a)->next)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if (cod == 2 && b && *b && (*b)->next)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	else if (cod == 3 && a && *a && (*a)->next && b && *b && (*b)->next)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
	else if (cod == 4 && a && *a && (*a)->next)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	else if (cod == 5 && b && *b && (*b)->next)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
	else if (cod == 6 && a && *a && (*a)->next && b && *b && (*b)->next)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write(1, "rrr\n", 4);
	}
}

int	find_direction_med(t_stack *a, int med, int A)
{
	int	pi;
	int	pj;

	pi = penality_r(a, med);
	pj = penality_rr(a, med);
	if (pj < pi)
	{
		if (A)
			return (4);
		return (5);
	}
	else
	{
		if (A)
			return (1);
	}
	return (2);
}
