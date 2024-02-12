#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content, size_t content_size)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node == NULL)
        return (NULL);
    new_node->content = malloc(content_size);
    if (new_node->content == NULL)
    {
        free(new_node);
        return (NULL);
    }
    memcpy(new_node->content, content, content_size);
    new_node->next = NULL;
    return (new_node);
}

void ft_lstadd_back(t_list **lst, t_list *new_n)
{
    t_list *tmp;

    if (*lst == NULL)
    {
        *lst = new_n;
        return;
    }
    tmp = *lst;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_n;
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    if (*lst == NULL || del == NULL)
        return;
    while (*lst)
    {
        t_list *tmp = *lst;
        *lst = (*lst)->next;
        del(tmp->content);
        free(tmp);
    }
}

int ft_atoi(const char *nptr)
{
    int i;
    int num;
    int neg;

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
    int i = 0;
    t_list *tmp = *stack;
    int *array = (int *)malloc(sizeof(int) * dim);
    
    while (i < dim && tmp != NULL)
    {
        array[i] = *(int *)tmp->content;
        tmp = tmp->next;
        i++;
    }

    // Sort the array
    for (int j = 0; j < dim - 1; j++)
    {
        for (int k = j + 1; k < dim; k++)
        {
            if (array[j] > array[k])
            {
                int temp = array[j];
                array[j] = array[k];
                array[k] = temp;
            }
        }
    }

    int m;
    if (dim % 2 == 0)
        m = array[dim / 2];
    else
        m = array[(dim - 1) / 2];

    free(array);

    return m;
}


int count_elements(t_list *a)
{
    int i;

    i = 0;
    if (!a)
        return(0);
    while (a->next)
    {
        i++;
        a = a->next;
    }
    return (i+1);
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

void push(t_list **stack_from, t_list **stack_to)
{
    t_list *tmp;

    if (stack_to && stack_from && *stack_from)
    {
        tmp = *stack_from;
        *stack_from = (*stack_from)->next;
        tmp->next = *stack_to;
        *stack_to = tmp;
    }
}

void swap(t_list **stack)
{
    t_list *node_1;
    t_list *node_2;

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
        if (*(int *)(*a)->content > *(int *)(*a)->next->content)
        {
            swap(a);
            return (1);
        }
        (*a) = (*a)->next;
        return (0);
    }
    return (0);
}

int get_last_value(t_list *a)
{
    if (a == NULL)
        return 0;

    t_list *tmp = a;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    return (*(int *)tmp->content);
}

int penality_r(t_list *a, int t)
{
    int pi;
    int i;
    t_list *head;
    
    head = a;
    i = 0;
    pi = 0;
    while (i++ < count_elements(a)/2)
    {
        if (*(int *)head->content > t)
        {
            pi++;
            head = head->next;
        }
        return (pi);  
    }
}

int penality_rr(t_list *a, int t)
{
    int pj;
    int j;
    t_list *mid;
    
    mid = a;
    j = 0;
    pj = 0;
    while (j++ < count_elements(a)/2 -1)
        mid = mid->next;
    while (mid)
    {
        if (*(int *)mid->content > t)
        {
            pj++;
            mid = mid->next;
        }
        return (count_elements(a)/2 -pj);
    }
}

int penality_r_max(t_list *a, int t)
{
    int pi;
    int i;
    t_list *head;
    
    head = a;
    i = 0;
    pi = 0;
    while (i++ < count_elements(a)/2)
    {
        if (*(int *)head->content != t)
        {
            pi++;
            head = head->next;
        }
        return (pi);  
    }
}

int penality_rr_max(t_list *a, int t)
{
    int pj;
    int j;
    t_list *mid;
    
    mid = a;
    j = 0;
    pj = 0;
    while (j++ < count_elements(a)/2 -1)
        mid = mid->next;
    while (mid)
    {
        if (*(int *)mid->content != t)
        {
            pj++;
            mid = mid->next;
        }
        return (count_elements(a)/2 -pj);
    }
}

int find_direction(int pi, int pj)
{
    if (pj < pi)
    {
        printf ("si fa rr\n");
        return (1);
    }
    return (0);
}

void sort_a(t_list **a, t_list **b)
{
    int t;
    int a_num;
    int a_tot;
    int i;


    i = 0;
    while (count_elements(*a) >= 3)
    {
        t = mid(a, count_elements(*a));
        a_num = count_elements(*a)/2; 
        a_tot = count_elements(*a);
        while (count_elements(*a) > a_tot - a_num) 
        {
            if (*(int *)(*a)->content < t)
            {
                push(a, b);
                write(1, "pa \n", 4);
                //(*a) = (*a)->next;
            }
            else
            {   
                //printf("penality r: %i, penality rr: %i\n",penality_r(*a, t), penality_rr(*a, t)); 
                if (find_direction(penality_r(*a, t), penality_rr(*a, t)))
                {
                    rev_rotate(a);
                    write(1, "rra \n", 5);
                }
                else
                {
                    rotate(a);
                    write(1, "ra \n", 4);
                }
            }
        }
    }
    if (little_order(a))
        write(1, "sa \n", 4);
}

void sort_b(t_list **a, t_list **b) {
    t_list *current;
    t_list *max;
    
    if (*b == NULL) {
        printf("La lista è vuota\n");
        return;
    }
    
    while (count_elements(*b) >= 3) 
    {
        current = *b;
        max = *b;
        
        // Trova il nodo con il valore massimo nella lista
        while (current != NULL) 
        {
            if (*(int *)current->content > *(int *)max->content) 
                max = current;
            current = current->next;
        }
        
        // Se il nodo corrente è il massimo, sposta la testa al nodo successivo
        if (*b == max) {
            push(b, a);
            write(1, "pb \n", 4);
        }
        else
        {
            if (find_direction(penality_r_max(*b, *(int *)max->content), penality_rr_max(*b, *(int *)max->content))) 
            {
                rev_rotate(b);
                write(1, "rrb \n", 5);
            }
            else
            {
                rotate(b);
                write(1, "rb \n", 4);
            }
        }
    }
    if (!little_order(b)) 
        write(1, "sb \n", 4);
    write(1, "pb \n", 4);
    write(1, "pb \n", 4);
}


int main(int argc, char **argv)
{
    t_list *stackA;
    t_list *stackB = NULL;
    t_list *new_n;
    t_list **chunk;
    int i;
    int value;

    i = 1;
    if (argc <= 2)
        return (0);
    value = ft_atoi(argv[i]);
    stackA = ft_lstnew(&value, sizeof(int));
    while (++i < argc)
    {
        value = ft_atoi(argv[i]);
        new_n = ft_lstnew(&value, sizeof(int));
        ft_lstadd_back(&stackA, new_n);
    }
    sort_a(&stackA, &stackB);
    sort_b(&stackA, &stackB);
    ft_lstclear(&stackA, free);
    ft_lstclear(&stackB, free);
    ft_lstclear(chunk, free);
}
