/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:26:41 by gcosenza          #+#    #+#             */
/*   Updated: 2023/11/29 19:09:39 by gcosenza         ###   ########.fr       */
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

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

void	init_list(t_list **list);
char	*concatenate(t_list *list);
void	ft_lstadd_back(t_list **list, char *buf);
void	fill_list(t_list **list, int fd);
char	*get_next_line(int fd);
int		end_line(t_list *list);
t_list	*find_last_node(t_list *list);
void	fill_str(t_list *list, char *str);
int		len_string(t_list *list);
void	clear_all(t_list **list, t_list *new_node, char *buffer);

#endif
