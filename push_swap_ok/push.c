/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:18:57 by aconti            #+#    #+#             */
/*   Updated: 2024/02/20 13:53:41 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void remove_first(t_stack **stack)
{
	t_stack *temp;
	
	temp = (*stack)->next;
	free(*stack);
	(*stack) = temp;
}

void pa(t_stack **add, t_stack **take)
{
	t_stack *g;
    t_stack *temp;

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
	free(g);
	write(1, "pa\n", 3);
}


void pb(t_stack **add, t_stack **take)
{
	t_stack *g;
    t_stack *temp;

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

/*int main()
{
    // Example usage
    t_stack *stackA = (t_stack *)malloc(sizeof(t_stack));
    t_stack *nodeB = (t_stack *)malloc(sizeof(t_stack));
    stackA->index = 31;
    nodeB->index = 42;
    push(&stackA, nodeB);
    printf("%d\n",stackA->index);
        printf("%d",stackA->next->index);
    // Cleanup: Free allocated memory
    while (stackA)
    {
        t_stack *temp = stackA;
        stackA = stackA->next;
        free(temp);
    }
    free(nodeB);
    return 0;
}*/