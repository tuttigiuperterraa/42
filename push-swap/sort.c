#include "push-swap.h"

int	check_med(t_list *a, int med)
{
	t_list *tmp;

	tmp = a;
	while(tmp)
	{
		if (tmp->content < med)
			return(1);
		tmp = tmp->next;
	}
	return (0);
}

int	counter(t_list *a)
{
	int n;
	t_list *temp;

	n = 0;
	temp = a;
	while (temp != NULL)
	{
		temp = temp->next;
		n++;
	}
	return (n);
}

int check_push(t_list **a, int i)
{
	t_list *temp;

	temp = *a;
	while (temp)
	{
		if (temp->push == i)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void pre_order(t_list **a, t_list **b)
{
    int i;

    i = 1;
    while (i < 6)
    {
        if ((*a)->push == i)
            pb(b, a);
        else if(*b && (*b)->next && (*b)->content < (*b)->next->content)
            do_rotate(a, b, 3);
        else
            do_rotate(a, b, find_direction_push(*a, i, 1));//Qui non dovrebbe guardare med ma il push
        if (!check_push(a, i))
            i++;
    }
}

void	sort(t_list **a, t_list **b, int n)
{
	int	med;
	int i;

	*b = NULL;
	if ((*a)->push != 0)
		pre_order(a, b);
	while (counter(*a) > 2)
	{
		if (is_sorted_list(*a) == 0)
			break;
		med = mid_list(*a);	
		while(check_med(*a, med))
		{	
			if (is_sorted_list(*a) == 0)
				break;
			if ((*a)->content < med)
				pb(b, a);
			else if (*b && (*b)->next && (*b)->content < (*b)->next->content)
				do_rotate(a, b, 3);
			else
				do_rotate(a, b, find_direction_med(*a, med, 1));
		}
	}
	if ((*a)->content > (*a)->next->content && !(counter(*a) > 2))
	{
		sa(a);
		write(1, "sa\n", 3);
	}
	little_check(a, b);
    check_ss(a, b);
    pa(a, b);
    pa(a, b);
}
