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

void pre_order(t_stack **a, t_stack **b)
{
    int i;

    i = 1;
    while (i < 6)
    {
        if ((*a)->push == i)
            pb(b, a);
        else if(*b && (*b)->next && (*b)->val < (*b)->next->val )
            do_rotate(a, b, 3);
        else
            do_rotate(a, b, find_direction_push(*a, i, 1));
        if (!check_push(a, i))
            i++;
    }
}

void	sort(t_stack **a, t_stack **b, int n)
{
	int	mediat;
	int j;
	int rot_a;

	if ((*a)->push != 0)
		pre_order(a, b);
	while (counter(*a) > 2)
	{
		if (is_sorted_list(*a) == 0)
			break;
		mediat = media(*a);		
		if ((*a)->val < mediat)
			pb(b, a);
		else if (*b && (*b)->next && (*b)->val < (*b)->next->val)
			do_rotate(a, b, 3);
		else
		{
			rot_a = type_rot_b(a, mediat);
			if (rot_a <= 0)
			{
				while ((*a)->val != mediat)
					do_rotate(a, b, 4);
				pa(a, b);
			}
			else
			{
				while ((*a)->val != mediat)
					do_rotate(a, b, 1);
				pa(a, b);
			}
		}
			//do_rotate(a, b, find_direction_med(*a, mediat, 1));
	}
	if ((*a)->val > (*a)->next->val && !(counter(*a) > 2))
	{
		sa(a);
		write(1, "sa\n", 3);
	}
	cont(a, b);
}