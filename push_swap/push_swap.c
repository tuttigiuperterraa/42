#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;


t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new_n)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = new_n;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_n;
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst == NULL || del == NULL || lst == NULL)
		return ;
	if ((*lst)->next != NULL)
		ft_lstclear(&(*lst)->next, del);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	neg = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		neg = neg * -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = 10 * num + nptr[i] - 48;
		i++;
	}
	return (num * neg);
}


int mid(t_list **stack, int dim)
{
    int i;
    int j;
    t_list *tmp;
    int *array;
    int *sort;
    int m;

    if (!stack || !(*stack))
        return (0);
    i = 0;
    tmp = *stack;
    array = (int *)malloc(sizeof(int)*dim + 1);
    while (tmp->content != NULL || i < dim)
    {
        array[i] = *(int *)tmp->content;
        tmp = tmp->next;
        i++;
    }
    array[i] = '\0';
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
        m = array[dim / 2];
    else
        m = array[(dim - 1) / 2];
    free(array);
    return (m);
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
}

int little_order(t_list **a)
{
    while ((*a)->next)
    {
        if ((*a)->content > (*a)->next->content)
        {
            swap(a);
            return (1);
        }
        (*a) = (*a)->next;
        return (0);
    }
    return (0);
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
        t = mid(a, count_elements(*a));
        b_num = count_elements(*b);
        while (count_elements(*b) == b_num + t - 1)
        {
            if (*(int *)(*a)->content < t)
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

void sort_b(t_list **b, t_list **a, t_list **chunk)
{
    int t;

    push(b, a);
    write(1, "pb ", 3);
    while (*b != chunk[0])
    {
        t = mid(b, chunk_len(chunk[1], chunk[0]));
        if (*(int *)(*b)->content > t)
        {
            push(b, a);
            write(1, "pb ", 3);
            (*b) = (*b)->next;
        }
        rev_rotate(b);
        write(1, "rrb ", 3);
    }
    while ((*b)->next)
    {
        t = mid(a, count_elements(*a));
        if (*(int *)(*b)->content > t)
        {
            push(b, a);
            write(1, "pb ", 3);
            (*b) = (*b)->next;
        }
        rotate(b);
        write(1, "rb ", 3);
    }
    if (little_order(b))
        write(1, "sb ", 3);
    while (b)
    {
        push(b,a);
        write(1, "pb ", 3);
        (*b) = (*b)->next;
    }
}






int main(int argc, char **argv)
{
    t_list	*stackA;
    t_list  *stackB;
    t_list  *new_n;
    t_list **chunk;
    int i;
    int value;

    i = 1;
    if (argc <= 2)
        return (0);
    value = ft_atoi(argv[i]);
    stackA = ft_lstnew(&value);
    while (++i < argc)
    {
        value = ft_atoi(argv[i]);
        new_n = ft_lstnew(&value);
        ft_lstadd_back(&stackA, new_n);
        free(new_n);
    }
   chunk = sort_a(&stackA, &stackB);
   sort_b(&stackB, &stackA, chunk);
    ft_lstclear(&stackA, free);
    ft_lstclear(&stackB, free);
    ft_lstclear(chunk, free);
}
