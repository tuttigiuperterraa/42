/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:26:41 by gcosenza          #+#    #+#             */
/*   Updated: 2023/12/01 19:15:46 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	create_list(t_list **list, int fd);
void	add_node_back(t_list **list, char *buffer);
char	*concatenate(t_list *list);
void	init_list(t_list **list);
void	dealloc(t_list **list, t_list *clean_node, char *buffer);
int		len_string(t_list *list);
void	fill_str(t_list *list, char *str);
t_list	*find_last_node(t_list *list);
int		end_line(t_list *list);

#endif
