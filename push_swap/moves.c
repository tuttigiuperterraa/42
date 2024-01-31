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

/*int	max(t_list *a)
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
}*/

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

int little_order(t_list **a)
{
    while ((*a)->next)
    {
        if ((*a)->val > (*a)->next->val)
        {
            swap(a);
            return (1);
        }
        (*a) = (*a)->next;
        return (0);
    }
}

t_list **sort_a(t_list **a, t_list **b)
{
    int t;
    int b_num;
    int i;
    t_list *chunk[3];

    i = 0;
    while (count_elements(*a) > 3)
    {
        t = mid(*a, count_elements(*a));
        b_num = count_elements(*b);
        while (count_elements(*b) == b_num + t - 1)
        {
            if ((*a)->val < t)
            {
                push(a, b);
                write(1, "pa ", 3);
                (*a) = (*a)->next;
            }
            rotate(a);
            write (1, "ra ", 3);
        }
        chunk[i++] = *b;
    }
    if (little_order(a))
        write(1, "sa ", 3);
    return (chunk);
}

int chunk_len(t_list *chunk1, t_list *chunk2)
{
    int i;

    i = 0;
    while (chunk1 != chunk2)
    {
        i++;
        chunk1 = chunk1->next;
    }
    return (i);
}

/*void sort_b(t_list **b, t_list **a, t_list **chunk)
{
    int t;

    push(b, a);
    write(1, "pb ", 3);
    while (*b != chunk[0])
    {
        t = mid(*b, chunk_len(chunk[1], chunk[0]));
        if ((*b)->val > t)
        {
            push(b, a);
            write(1, "pb ", 3);
            (*b) = (*b)->next;
        }
        rotate(b);
        write(1, "rb ", 3);
    }
    while ((*b)->next)
    {
        t = mid(*a, count_elements(*a));
        if ((*b)->val > t)
        {
            push(b, a);
            write(1, "pb ", 3);
            (*b) = (*b)->next;
        }
        rotate(b);
        write(1, "rb ", 3);
    }
    if (little_order(b));
        write(1, "sb ", 3);
    while (b)
    {
        push(b,a);
        write(1, "pb ", 3);
        b = b->next;
    }
}*/

void rotate(t_list **stack)
{
    t_list *node_2;
    t_list *tmp;
    char s;

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
    write(1,"r",3);
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
    write(1,"rr",3);
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
    write(1,"p",3);
}

void	swap(t_list **stack)
{
	t_list	*node_1;
	t_list	*node_2;

	if (stack && *stack && (*stack)->next)
	{
		node_1 = *stack;
		node_2 = node_1->next;
		node_1->next = node_2->next;
		node_2->next = node_1;
		*stack = node_2;
	}
    write(1,"s",3);
}

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
        mid = array[dim / 2];
    else
        mid = array[(dim - 1) / 2];
    free(array);
    return (mid);
}

