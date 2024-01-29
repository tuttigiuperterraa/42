/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:18:00 by gcosenza          #+#    #+#             */
/*   Updated: 2024/01/29 15:18:00 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h";
#include "pushswap.h";

int mid(t_list **stack, int dim)
{
    int i;
    int j;
    t_list *tmp;
    int *array;
    int *sort;

    if (!stack || !(*stack))
        return (NULL);

    i = 0;
    tmp = *stack;
    array = (int *)calloc(dim + 1, sizeof(int));

    while (tmp && i < dim)
    {
        array[i] = tmp->content;
        tmp = tmp->next;
        i++;
    }
    i = 0;
    while (i < dim - 1)
    {
        sort = &array[i];
        j = i + 1;
        while (j < dim)
        {
            if (array[j] < *sort)
            {
                int temp = array[j];
                array[j] = *sort;
                *sort = temp;
            }
            j++;
        }
        i++;
    }

    if (dim % 2 == 0)
        return array[dim / 2];
    else
        return array[(dim - 1) / 2];
}

int	max(t_list *a)
{
	int	max;
	
	if (!a)
		return (0);
	max = a->val;
	while (a->next)
	{
		a = a->next;
		if (max < a->val)
			max = a->val;
	}
	return (max);
}

int	count_elements(t_list *a)
{
	int i;
	
	i = 0;
	while (a->next)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	little_order(t_list **a)
{
	while ((*a)->next)
	{
		if ((*a)->val > (*a)->next->val)
			swap(a);
		a = (*a)->next;
	}
}

void	sort(t_list **a, t_list **b)
{
	int	t;

	while (count_elements(a) > 3)
	{
		t = mid(a) / 2;
		while ((*a)->next)
		{
			if ((*a)->val < t)
				push(a, b);
			(*a) = (*a)->next;
		}
	}
	little_order(a);
	//prende meta grande b e butta in a....
	//rimangono 2/3 elementi e ordina
	
}

void rotate(t_list **stack)
{
    t_list *node_2;
    t_list *tmp;

    if (stack && *stack && (*stack)->next)
    {
        tmp = *stack;
        node_2 = (*stack)->next;

        while (tmp->next)
            tmp = tmp->next;

        tmp->next = *stack;
        (*stack)->next = NULL;
        *stack = node_2;
    }
}

void rev_rotate(t_list **stack)
{
    t_list *tmp;
    t_list *end;

    if (stack && *stack && (*stack)->next)
    {
        tmp = *stack;
        while (tmp->next->next)
            tmp = tmp->next;

        end = tmp->next;
        tmp->next = NULL;
        end->next = *stack;
        *stack = end;
    }
}

void	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if (stack_to && stack_from && *stack_from)
	{
		tmp = *stack_from;
		*stack_from = (*stack_from)->next;
		tmp->next = *stack_to;
		*stack_to = tmp;
	}
}

void	swap(t_list **stack)
{
	t_list	*node_1;
	t_list	*node_2;

	if (stack && *stack && (*stack)->next)
	{
		node_1 = *stack;
		node_2 = fst->next;
		node_1->next = node_2->next;
		node_2->next = node_1;
		*stack = node_2;
	}
}
