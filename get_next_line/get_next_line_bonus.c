/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:43:57 by gcosenza          #+#    #+#             */
/*   Updated: 2023/11/22 17:43:57 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_list(t_list **list)
{
	int		i;
	int		j;
	t_list	*new_node;
	t_list	*last_node;

	i = 0;
	j = 0;
	new_node = NULL;
	last_node = ft_lstlast(*list);
	if (!last_node)
		return (NULL);
	while (last_node[i] != '\n' || last_node[i] != '\0')
		i++;
	new_node = malloc(sizeof(t_list));
	new_node->content = malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
	if (!new_node)
		return (NULL);
	new_node[BUFFER_SIZE - i] = '\0';
	while (BUFFER_SIZE >= ++i)
		new_node[j++] = last_node[i];
	ft_lstclear(list);
	*list = new_node;
}

char	*concatenate(t_list *list)
{
	char	*line;
	char	*back;
	int		list_size;
	int		back_size;

	if (!list)
		return (NULL);
	back_size = 0;
	list_size = ft_lstsize(list);
	back = ft_lstlast(list);
	while (back[back_size] != '\n')
		back_size++;
	line = malloc(sizeof(char) * (BUFFER_SIZE * (list_size - 1)
				+ back_size + 1));
	if (!line)
		return (NULL);
	line[BUFFER_SIZE * (list_size - 1) + back_size] = '\0';
	fill_line(list, line, 0, 0);
	return (line);
}

int	end_line(t_list *list)
{
	int	i;

	i = 0;
	if (!list)
		return (NULL);
	while (list->content != NULL)
	{
		i = 0;
		while (list->content[i] != '\0' && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list->content = list->next;
	}
	return (0);
}

void	fill_list(t_list **list, int fd)
{
	char	*buffer;
	int		tot;

	while (!end_line(list[fd]))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
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
	char	*line;
	t_list	*list[4096];	

	list = NULL;
	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	fill_list(list, fd);
	if (!list)
		return (NULL);
	line = concatenate(list[fd]);
	init_list(&list[fd]);
	return (line);
}
