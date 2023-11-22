/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:43:13 by gcosenza          #+#    #+#             */
/*   Updated: 2023/11/22 18:46:51 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstadd_back(t_list **lst, t_list *new, int fd)
{
	t_list	*tmp;

	if (lst[fd] == NULL)
	{
		lst[fd] = new;
		return ;
	}
	tmp = lst[fd];
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	fill_line(t_list *list, char *line, int i, int j)
{
	if (!list)
		return (NULL);
	while (list->content != '\0')
	{
		while ((list->content)[j] != '\0' || (list->content)[j] != '\n')
			line[i++] = list->content[j++];
		list->content = list->next;
		j = 0;
	}
	line[i++] = '\n';
	line[i] = '\0';
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL || lst == NULL)
		return ;
	if ((*lst)->content != NULL)
	{
		tmp = *lst->next;
		free(*lst->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
