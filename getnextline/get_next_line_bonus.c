/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:45:29 by gcosenza          #+#    #+#             */
/*   Updated: 2023/02/20 00:45:34 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	init_list(t_list **list)
{
	int		i;
	int		j;
	t_list	*last_node;
	t_list	*new_node;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (!buffer || !new_node)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[++i])
		buffer[j++] = last_node->content[i];
	buffer[j] = '\0';
	new_node->content = buffer;
	new_node->next = NULL;
	clear_all(list, new_node, buffer);
}

char	*concatenate(t_list *list)
{
	int		str_len;
	char	*str;

	if (!list)
		return (NULL);
	str_len = len_string(list);
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	fill_str(list, str);
	return (str);
}

void	ft_lstadd_back(t_list **list, char *buf, int fd)
{
	t_list	*last_node;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	last_node = find_last_node(list[fd]);
	if (!last_node)
		list[fd] = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

void	fill_list(t_list **list, int fd)
{
	char	*buffer;
	int		tot;

	while (!end_line(list[fd]))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		tot = read(fd, buffer, BUFFER_SIZE);
		if (tot == 0)
		{
			free(buffer);
			return ;
		}
		buffer[tot] = '\0';
		ft_lstadd_back(list, buffer, fd);
	}
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*list[4096];

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	fill_list(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	line = concatenate(list[fd]);
	init_list(&list[fd]);
	return (line);
}
