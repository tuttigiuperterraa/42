/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:59:55 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/19 16:34:20 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t n_words(char const *s, char c)
{
        size_t i;
        size_t n;

        i = 0;
        n = 0;
        while (s[i] == c)
                i++;
        while (s[i] != '\0')
        {
                if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
                        n++;
                i++;
        }
        return (n + 1);
}

char **ft_strsplit(char const *s, char c)
{
        size_t j;
        size_t i;
        size_t n;
        size_t p;
        char **array;

        i = 0;
        j = 0;
        n = 0;
        if (!s)
                return (NULL);
        array = (char **)malloc(n_words(s, c) + 1);
        if (!array)
                return (NULL);
        while (s[i] == c)
                i++;
        n = i;
        while (s[i] != '\0')
        {
                if (s[i] == c)
                {
                    p = n;
                    array[j] = (char *)malloc(i - n + 1);
                    if (!array[j])
                        return (NULL);
                    while (n < i)
                    {
                            array[j][n - p] = s[n];
                            n++;
                    }
                    i++;
                    while (s[i] == c)
                        i++;
                    n++;
                    j++;
                }
                else
                    i++;
        }
        array[n_words(s, c)] = NULL;
        return(array);
}

/*int main() 
{
    char const *s = "JFDSJDJJJKJJJ";
    char c = 'J';
    int i = 0;
   // char **array = ;
    
   // while (!array[i])
  //  {
        printf("%zu\n", n_words(s,c));
        printf("%s\n", ft_strsplit(s, c)[3]);
    //    i++;
    //}
}*/
