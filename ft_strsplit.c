/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:20:37 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/30 18:21:03 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	n_words(char const *s, char c)
{
	size_t	i;
	size_t	n;

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

char	**free_array(char **array, int g)
{
	while (--g >= 0)
		free(array[g]);
	free(array);
	return (NULL);
}

size_t	skip(char const *s, char c, size_t p)
{
	while (s[p] == c)
		p++;
	return (p);
}

char	**fill(char const *s, char **array, char c, size_t *q)
{
	while (s[q[0]] != '\0')
	{
		if (s[q[0]] == c)
		{
			q[3] = q[2];
			q[3] = skip(s, c, q[3]);
			array[q[1]] = (char *)malloc(q[0] - q[2] + 1);
			if (!array[q[1]])
				free_array(array, q[1]);
			while (q[2] < q[0])
			{
				array[q[1]][q[2] - q[3]] = s[q[2]];
				q[2]++;
			}
			q[0]++;
			q[0] = skip(s, c, q[0]);
			q[2]++;
			q[1]++;
		}
		q[0]++;
	}
	return (array);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	*q;
	char	**array;

	q = (size_t *)malloc(sizeof(size_t) * 5);
	q[0] = 0;
	q[1] = 0;
	q[2] = 0;
	q[3] = 0;
	if (!s)
		return (NULL);
	array = (char **)malloc(n_words(s, c) + 1);
	if (!array)
		return (NULL);
	while (s[q[0]] == c)
		(q[0])++;
	q[2] = q[0];
	fill(s, array, c, q);
	array[n_words(s, c)] = NULL;
	return (array);
}

/*int main() 
{
    char const *s = "JFDSJDJJJKJJJ";
    char c = 'J';
    //int i = 0;
   // char **array = ;
    
   // while (!array[i])
  //  {
        printf("%zu\n", n_words(s,c));
        printf("%s\n", ft_strsplit(s, c)[3]);
    //    i++;
    //}
}*/
