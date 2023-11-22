/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:28:34 by gcosenza          #+#    #+#             */
/*   Updated: 2023/11/22 18:35:49 by gcosenza         ###   ########.fr       */
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
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	fill_list(t_list **list, int fd);
int		end_line(t_list *list);
char	*concatenate(t_list *list);
void	init_list(t_list **list);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	fill_line(t_list *list, char *line, int i, int j);
void	ft_lstadd_back(t_list **lst, t_list *new, int fd);

#endif
