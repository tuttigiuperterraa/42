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
    t_list **chunk;
    int i;
    int value;

    i = 2;
    if (argc <= 2)
    {
        if(argv[1])
            ft_atoi(argv[1]);
        return (0);
    }
    value = ft_atoi(argv[i]);
    stackA = ft_lstnew(&value);
    while (++i < argc)
    {
        value = ft_atoi(argv[i]);
        new = ft_lstnew(&value);
        ft_lstadd_back(&stackA, new);
    }
   free(new);
   chunk = sort_a(&stackA, &stackB);
   sort_b(&stackB, &stackA, &chunk);
   //print moves TODO
    ft_lstclear(&stackA, free);
    ft_lstclear(&stackB, free);
    ft_lstclear(chunk, free);
}
