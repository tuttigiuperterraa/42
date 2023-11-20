/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:47:31 by marvin            #+#    #+#             */
/*   Updated: 2023/11/20 17:47:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define BUFFER_SIZE 42
void	init_list(t_list *list)
{
	int	i;
	int	j;
	t_list	*new_node;
	t_list	*last_node;

	i = 0;
	j = 0;
	last_node = ft_lstlast(list);
	while (last_node[back_size] != '\n' || last_node[back_size] != '\0')
		i++;
	new_node = malloc(sizeof(char)*(BUFFER_SIZE - i + 1));
	if (!new_node)
		return (NULL);
	ft_bzero(new_node);
	while (BUFFER_SIZE >= ++i)
		new_node[j++] = last_node[i];
	ft_lstclear(&list);
	list = new_node;
}

void	fill_line(t_list *list, char *line, int	i, int j)
{
	while (list->content != '\0')
	{
		while ((list->content)[j] != '\0' || (list->content)[j] != '\n')
			line[i++] = list->content[j++];
		list->content = list->next;
		j = 0;
	}
	line[i] = '\n';
}

char *concatenate(t_list *list)
{
	char *line;
	char *back;
	int	list_size;
	int	back_size;

	if (!list)
		return (NULL);
	back_size = 0;
	list_size = ft_lstsize(list); /*cambia, non dare per scontato che siano lunghi BUFFER_SIZE*/
	back = ft_lstlast(list);
	while (back[back_size] != '\n')
		back_size++;
	line = malloc(sizeof(char)*(BUFFER_SIZE * (list_size - 1) + back_size + 1));
	if (!line)
		return (NULL);
	ft_bzero(line);
	fill_line(list, line, 0, 0);
	return (line);
}

int	end_line(list)
{
	int	i;

	i = 0;
	if (!list)
		return (NULL);
	while(list->content != NULL)
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

t_list	fill_list(t_list **list, int fd)
{
	char	*buffer;
	int	tot;

	while (!end_line(*list))
	{
		buffer = malloc(sizeof(char)* (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		tot = read(fd, buffer, BUFFER_SIZE);
		if (tot == 0)
		{
			free(buffer);
			return;
		}
		buffer[tot] = '\0';
		ft_lsaddback(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	char	*line;
	t_list	*list;	

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	fill_list(&list, fd);
	if (!list)
		return (NULL);
	line = concatenate(list);
	init_list(list);
}