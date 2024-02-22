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

#include "push-swap.h"

int is_sorted_list(t_stack *list)
{
	t_stack *tmp;
	int i = 0;
	
	tmp = list;
	while (tmp->next != NULL)
	{
		if (!(tmp->next->val > tmp->val))
			i++;
		tmp = tmp->next;	
	}
	return (i);
}

int check_push(t_stack **a, int i)
{
	t_stack *temp;

	temp = *a;
	while (temp)
	{
		if (temp->push == i)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void check_ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	if ((*a)->next != NULL && (*b)->next != NULL)
	{
		if ((*a)->val > (*a)->next->val && (*b)->val < (*b)->next->val)
			ss(a, b);
	}
	if ((*a)->next != NULL && (*a)->val > (*a)->next->val)
	{
		write(1, "sa\n", 3);
		sa(a);
	}
	if ((*b)->next != NULL && (*b)->val < (*b)->next->val)
	{
		write(1, "sb\n", 3);
		sb(b);
	}
}

void little_check(t_stack **a, t_stack **b)
{
	int i;
	int rot_b;
	
	i = 0;
	if (!a || !(*a) || !b || !(*b))
		return ;
	if (!(*a)->next || !(*b)->next)
		return ;
	while (counter(*b) > 1)
	{
		rot_b = type_rot_b(b, max(b));
		if (rot_b <= 0)
		{
			while ((*b)->val != max(b))
				do_rotate(a, b, 5);
			pa(a, b);
		}
		else
		{
			while ((*b)->val != max(b))
				do_rotate(a, b, 2);
			pa(a, b);
		}
	}
}

int ft_check(long int *nums, int i)
{
	int j;

	i--;
    while (i >= 0)
    {
		j = 0;
		if(nums[i] > 2147483647 || nums[i] < -2147483648)
			return (0);
		while (j < i)
		{
			if((int)nums[i] == (int)nums[j])
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}