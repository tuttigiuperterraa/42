/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:57 by gcosenza          #+#    #+#             */
/*   Updated: 2024/02/27 07:52:12 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **add, t_stack **take)
{
	t_stack	*g;
	t_stack	*temp;

	if (!add || !take)
		return ;
	g = malloc(sizeof(t_stack));
	if (!g)
	{
		while (*add != NULL)
		{
			temp = *add;
			*add = (*add)->next;
			free(temp);
		}
		return ;
	}
	g->val = (*take)->val;
	g->next = *add;
	*add = g;
	remove_first(take);
	write(1, "pa\n", 3);
}

void	pb(t_stack **add, t_stack **take)
{
	t_stack	*g;
	t_stack	*temp;

	if (!add || !take)
		return ;
	g = malloc(sizeof(t_stack));
	if (!g)
	{
		while (*add != NULL)
		{
			temp = *add;
			*add = (*add)->next;
			free(temp);
		}
		return ;
	}
	g->val = (*take)->val;
	g->next = *add;
	*add = g;
	remove_first(take);
	write(1, "pb\n", 3);
}

int	find_direction_push(t_stack *a, int push)
{
	int	pi;
	int	pj;

	pi = penality_r_push(a, push);
	pj = penality_rr_push(a, push);
	if (pj < pi)
		return (4);
	else
		return (1);
}

int	penality_r_push(t_stack *a, int t)
{
	int		pi;
	int		i;
	t_stack	*head;

	head = a;
	i = 0;
	pi = 0;
	while (i++ < counter(a) / 2)
	{
		if (head->push == t)
			break ;
		pi++;
		head = head->next;
	}
	return (pi);
}

int	penality_rr_push(t_stack *a, int t)
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
		if (mid->push == t)
			tmp = pj;
		pj++;
		mid = mid->next;
	}
	return (counter(a) / 2 - tmp);
}
