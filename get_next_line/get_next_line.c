/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:48:03 by gcosenza          #+#    #+#             */
/*   Updated: 2023/12/01 19:11:41 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buffer == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[++i])
		buffer[j++] = last_node->content[i];
	buffer[j] = '\0';
	clean_node->content = buffer;
	clean_node->next = NULL;
	dealloc(list, clean_node, buffer);
}

char	*concatenate(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_string(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	fill_str(list, next_str);
	return (next_str);
}

void	add_node_back(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	last_node = find_last_node(*list);
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buffer;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		tot;	
	char	*buffer;

	while (!end_line(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		tot = read(fd, buffer, BUFFER_SIZE);
		if (tot == 0)
		{
			free(buffer);
			return ;
		}
		if (tot < 0 || !tot)
		{
			free(buffer);
			dealloc(list, NULL, NULL);
			return ;
		}
		buffer[tot] = '\0';
		add_node_back(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	line = concatenate(list);
	init_list(&list);
	return (line);
}

/*int	main()
{
	int	i;
	int	fd;
	char	*str;
	fd = open("read_error.txt", O_RDONLY);
	while (i < 6)
	{
		printf("%s", str = get_next_line(fd));
		free(str);
		i++;
	}
}*/
