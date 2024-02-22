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

void free_stack(t_stack *head)
{
    t_stack *current = head;
    t_stack *next;

    while (current != NULL)
	{
        next = current->next;
        free(current);
        current = next;
    }
}

void remove_first(t_stack **stack)
{
	t_stack *temp;
	
	temp = (*stack)->next;
	free(*stack);
	(*stack) = temp;
}

void cont(t_stack **a, t_stack **b)
{
	check_ss(a, b);
	little_check(a, b);
	pa(a, b);
	free_stack(*b);
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