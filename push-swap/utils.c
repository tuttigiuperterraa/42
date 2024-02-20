#include "push-swap.h"

void ft_lstclear(t_list *head) 
{
    t_list *current = head;
    t_list *next;

    while (current != NULL) {
        next = current->next; // Salva il puntatore al prossimo nodo
        free(current); // Libera il nodo corrente
        current = next; // Passa al prossimo nodo
    }
}

long int *stack_to_array(t_list *a)
{
	long int *arr;
	int size;
	int n;
	t_list *tmp;

	size = counter(a);
	n = size;
	arr = (long int *)malloc(sizeof(long int)* (size + 1));
	if (!arr)
		return (NULL);
	tmp = a;
	while(tmp && size > 0)
	{
		arr[n - size] = tmp->content;
		size--;
		tmp = tmp->next;
	}
	arr[n] = '\0';
	return (arr);
}

int max(t_list **stack)
{
	int	max;
	t_list *temp;

	temp = *stack;
	max = INT_MIN;
	while (temp)
	{
		if (max < temp->content)
			max = temp->content;
		temp = temp->next;	
	}
	return (max);
}

int is_sorted(long int *arr, int n)
{
	int i;
	
	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void little_check(t_list **a, t_list **b)
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
		rot_b = type_rot_b(b);
		if (rot_b <= 0)
		{
			while ((*b)->content != max(b))
			{
				rev_rotate(b);
				write(1, "rrb\n", 4);
			}
			pa(a, b);
		}
		else if (rot_b > 0)
		{
			while ((*b)->content != max(b))
			{
				rotate(b);
				write(1, "rb\n", 3);
			}
			pa(a, b);
		}
	}
}
