#include "push-swap.h"

void sa(t_list **a)
{
    int t;

    if (!a || !*a || !(*a)->next)
        return;

    t = (*a)->content;
    (*a)->content = (*a)->next->content;
    (*a)->next->content = t;
}

void sb(t_list **a)
{
    int t;

    if (!a || !*a || !(*a)->next)
        return;

    t = (*a)->content;
    (*a)->content = (*a)->next->content;
    (*a)->next->content = t;
}

void ss(t_list **a, t_list **b)
{
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}

void check_ss(t_list **a, t_list **b)
{
    if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
        return ;
    if ((*a)->next != NULL && (*b)->next != NULL)
    {
        if ((*a)->content > (*a)->next->content && (*b)->content < (*b)->next->content)
            ss(a, b);
    }

    if ((*a)->next != NULL && (*a)->content > (*a)->next->content)
    {
        write(1, "sa\n", 3);
        sa(a);
    }

    if ((*b)->next != NULL && (*b)->content < (*b)->next->content)
    {
        write(1, "sb\n", 3);
        sb(b);
    }
}