/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:51:41 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/19 15:51:47 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*size_t	ft_strlen(const char *c)
{
	size_t	n;

	n = 0;
	while (c[n])
		n++;
	return (n);
}*/

size_t start(char const *s1, char const *set)
{
    size_t  i;
    size_t j;
    size_t start;
    char *trim;
    
    i = 0;
    j = 0;
    
    if (set[0] == '\0')
    	return(0);
    while (s1[i] != '\0' && j < ft_strlen(set))
    {
        j = 0;
        while (set[j] != '\0' && s1[i] != set[j])
            j++;
        i++;
    }
    start = i - 1;
    return (start);
}

size_t stop(char const *s1, char const *set)
{
    size_t  i;
    size_t j;
    size_t stop;
    i = 0;
    j = 0;
    while (ft_strlen(s1) - i > start(s1, set) && j < ft_strlen(set))
    {
        j = 0;
        while (set[j] != '\0' && s1[ft_strlen(s1) - i - 1] != set[j])
            j++;
        i++;
        
    }
    stop = ft_strlen(s1) - i +1;
    return (stop);
}
char *ft_strtrim(char const *s1, char const *set)
{
    size_t  i;
    char *trim;
    
    trim = NULL;
    trim = (char *)malloc(stop(s1, set) - start(s1, set) + 2);
    if (!trim)
        return (NULL);
    i = 0;
    while(stop(s1, set) - i > start(s1, set))
    {
        trim[i] = s1[start(s1, set) + i];
        i++;
    }
    return(trim);
}


/*int	main(void)
{
	char *str1 = "6CCICAoCICA";
	char *set = "CI";
    
    printf("nuova stringa: %zu\n", start(str1, set));
    printf("nuova stringa: %zu\n", stop(str1, set));
	printf("nuova stringa: %s\n", ft_strtrim(str1, set));
}*/
