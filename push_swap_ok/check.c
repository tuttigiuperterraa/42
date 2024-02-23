/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:57 by aconti            #+#    #+#             */
/*   Updated: 2024/02/23 08:25:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int is_sign(char av)
{
	if (av == '+')
		return (1);
	else if(av == '-')
		return (-1);
	else
		return (0);
}

int ft_atoi(char **nptr, long int *nums)
{
    int i = 1;
    long int num = 0;
    int n = 0;
    while (nptr[i])
    {
        int sign = 1;
        int j = 0;
        while (nptr[i][j])
        {
            if (is_sign(nptr[i][j]) == 1 || is_sign(nptr[i][j]) == -1)
            {
                sign = is_sign(nptr[i][j]);
                j++;
            }
            while (nptr[i][j] >= '0' && nptr[i][j] <= '9')
            {
                num = num * 10 + (nptr[i][j] - '0');
                if (nptr[i][j + 1] == ' ' || nptr[i][j + 1] == '\0')
                {
                    nums[n] = sign * num;
                    num = 0;
                    n++;
                    if(nptr[i][j + 1] == '\0')
                        break;
                }
                j++;
            }
            j++;
        }
        i++;
    }
    return n;
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

/*void print_stack(t_stack *stack)
{
    while (stack != NULL) {
        printf("Value: %ld\n", stack->val);
        stack = stack->next;
    }
    printf("\n");
}*/

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

void add_push(t_stack *new_node, int size, long int *arr)
{
	float media;
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

void array_to_stack(long int *arr, int size, t_stack **stack)
{
	t_stack *new_node;
    t_stack *temp; 
	int i; 
    
    i = size - 1;
	while (i >= 0)
	{
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
        {
            while (*stack != NULL)
            {
                temp = *stack;
                *stack = (*stack)->next;
                free(temp);
            }
            return ;
        }
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
