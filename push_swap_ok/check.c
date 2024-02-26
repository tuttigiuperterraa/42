/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:57 by gcosenza          #+#    #+#             */
/*   Updated: 2024/02/26 08:49:59 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_list(t_stack *list)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp->next != NULL)
	{
		if (!(tmp->next->val > tmp->val))
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	count_num(char **nptr)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 1;
	while (nptr[i])
	{
		j = 0;
		while (nptr[i][j])
		{
			if (nptr[i][j] >= '0' && nptr[i][j] <= '9')
			{
				while (nptr[i][j] >= '0' && nptr[i][j] <= '9')
					j++;
				n++;
			}
			else
				j++;
		}
		i++;
	}
	return (n);
}

int	ft_check(long int *nums, int i)
{
	int	j;

	i--;
	while (i >= 0)
	{
		j = 0;
		if (nums[i] > 2147483647 || nums[i] < -2147483648)
			return (0);
		while (j < i)
		{
			if ((int)nums[i] == (int)nums[j])
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

/*void print_stack(t_stack *stack)
{
    while (stack != NULL) {
        printf("Value: %ld\n", stack->val);
        stack = stack->next;
    }
    printf("\n");
}*/

float	media_array(long array[], int lunghezza)
{
	float	media;
	int		i;
	int		somma;

	i = 0;
	if (lunghezza == 0)
		return (0);
	somma = 0;
	while (i < lunghezza)
		somma += array[i++];
	media = (float)somma / lunghezza;
	return (media);
}
