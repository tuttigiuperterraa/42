#include "push-swap.h"

void rotate(t_list **stack)
{
    t_list *node_2;
    t_list *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    tmp = *stack;
    node_2 = (*stack)->next;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = *stack;
    (*stack)->next = NULL;
    *stack = node_2;
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
    else
        return;
}

int type_rot_b(t_list **stack)
{
	t_list *temp;
	int rot;
	int rev;
	
	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (0);
	temp = *stack;
	rot = 0;
	rev = 0;
	while (temp)
	{
		if (temp->content == max(stack))
			break ;
		rot++;
		temp = temp->next;
	}
	rev = counter(*stack) - rot;
	if (rot <= rev)
		return (rot);
	else
		return (rev * -1);	
}

void do_rotate(t_list **a, t_list **b, int cod)
{
    if (cod == 1 && a && *a && (*a)->next)
    {
        rotate(a);
        write(1, "ra\n", 3);
    }
    else if (cod == 2 && b && *b && (*b)->next)
    {
        rotate(b);
        write(1, "rb\n", 3);
    }
    else if (cod == 3 && a && *a && (*a)->next && b && *b && (*b)->next)
    {
        rotate(a);
        rotate(b);
        write(1, "rr\n", 3);
    }
    else if (cod == 4 && a && *a && (*a)->next)
    {
        rev_rotate(a);
        write(1, "rra\n", 4);
    }
    else if (cod == 5 && b && *b && (*b)->next)
    {
        rev_rotate(b);
        write(1, "rrb\n", 4);
    }
    else if (cod == 6 && a && *a && (*a)->next && b && *b && (*b)->next)
    {
        rev_rotate(a);
        rev_rotate(b);
        write(1, "rrr\n", 4);
    }
}