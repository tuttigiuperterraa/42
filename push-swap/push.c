#include "push-swap.h"

void pa(t_list **add, t_list **take)
{
	t_list *g;

	g = (t_list *)malloc(sizeof(t_list));
	if (!g || !*take || !take)
		return ;
	g->content = (*take)->content;
	g->next = *add;
	*add = g;
	*take = (*take)->next;
	write(1, "pa\n", 3);
	free(g);
}

void pb(t_list **add, t_list **take)
{
	t_list *g;
	t_list *current;
	t_list *temp;

	g = (t_list *)malloc(sizeof(t_list));
	if (!g || !*take || !take)
		return ;
	g->content = (*take)->content;
	g->next = *add;
	*add = g;
	current = *add;
	temp = *take;
	*take = (*take)->next;
	write(1, "pb\n", 3);
	free(temp);
	current = *take;
}