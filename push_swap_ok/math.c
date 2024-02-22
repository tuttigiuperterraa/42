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

int	counter(t_stack *a)
{
	int n;
	t_stack *temp;

	n = 0;
	temp = a;
	while (temp != NULL)
	{
		temp = temp->next;
		n++;
	}
	return (n);
}

double	media(t_stack *a)
{
	int i;
	t_stack *temp;
	double val;

	i = 0;
	temp = a;
	val = 0;
	while (temp != NULL)
	{
		i++;
		val +=temp->val;
		temp = temp->next;
	}
	return (val/i);
}

int max(t_stack **stack)
{
	int	max;
	t_stack *temp;

	temp = *stack;
	max = INT_MIN;
	while (temp)
	{
		if (max < temp->val)
			max = temp->val;
		temp = temp->next;	
	}
	return (max);
}

float media_array(long array[], int lunghezza)
{
	float media;
    int i;
	int somma;

    i = 0;
    if (lunghezza == 0)
        return 0;
    somma = 0;
    while (i < lunghezza)
        somma += array[i++];
	media = (float)somma / lunghezza;    
	return (media);
}

int count_num(char **nptr)
{
	int n;
    int i;
    int j;

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