/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:59:50 by gcosenza          #+#    #+#             */
/*   Updated: 2024/01/26 14:59:50 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h";
#incllude "pushswap.h";

int main(int argc, int *argv)
{
    t_list	*stackA;
    t_list  *new;
    int i;
    int value;

    i = 0;
    if (argc < 2)
        return 1;
    value = ft_atoi(argv[i]);
    stackA = ft_lstnew(&value);
    while (++i < argc)
    {
        value = ft_atoi(argv[i]);
        new = ft_lstnew(&value);
        ft_lstadd_back(&stackA, new);
    }
   free(new);
   //sort TODO
   //print moves TODO
    ft_lstclear(&stackA, free);
}
