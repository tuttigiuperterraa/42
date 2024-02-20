#include "push-swap.h"

int is_sorted_list(t_list *list)
{
	t_list *tmp;
	int i = 0;
	
	tmp = list;
	while (tmp->next != NULL)
	{
		if (!(tmp->next->content > tmp->content))
			i++;
		tmp = tmp->next;	
	}
	return (i);
}

int find_direction_med(t_list *a, int med, int A)
{
	int pi;
	int pj;

	pi = penality_r(a, med);
	pj = penality_rr(a, med);
    if (pj < pi)
	{
		if (A)
			return (4);
		return (5);
	}  
    else 
	{
		if (A)
			return (1);
	}
	return (2);
}

int penality_r(t_list *a, int t)
{
    int pi;
    int i;
    t_list *head;
    
    head = a;
    i = 0;
    pi = 0;
    while (i++ < counter(a)/2)
    {
        if (head->content >= t)
        {
            pi++;
            head = head->next;
        } 
    }
	return (pi); 
}

int penality_rr(t_list *a, int t)
{
    int pj;
    int j;
    t_list *mid;
    
    mid = a;
    j = 0;
    pj = 0;
    while (j++ < counter(a)/2 -1)
        mid = mid->next;
    while (mid)
    {
        if (mid->content >= t)
        {
            pj++;
            mid = mid->next;
        }
        return (counter(a)/2 -pj);
    }
}
