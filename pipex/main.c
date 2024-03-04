/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:41:49 by gcosenza          #+#    #+#             */
/*   Updated: 2024/03/04 15:41:49 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdlib.h>
#include    <stdio.h>
#include    <string.h>
#include    <unistd.h>
#include    <sys/types.h>
#include    "libft.h"

int count_params(char *array)
{
    int i;
    int w;

    i = 0;
    w = 0;
    while (array[i] == '"')
        i++;
    while (array[i] != '"')
    {    
        if (array[i] == ' ' && array[i  +1] != ' ')
            w++;
        i++;
    }
    return (w + 1);
}

char    **fill_func(char **func, char *argv)
{
    int p;
    int i;
    int j;
    char **argv_sp;

    i = 0;
    j = 0;
    p = count_params(argv); 
    func = malloc(sizeof(char *) * p + 1);
    if (!func)
        return (write(1, "Malloc error.\n", 14));
    func[p] = '\0';
    argv_sp = ft_split(argv, " ");
    while (func[i] != '\0')
    {
        func[i] = malloc(sizeof(char) * ft_strlen(argv_split[i]) + 1);
        if (!func[i])
            return (write(1, "Malloc error.\n", 14));
        while (func[i][j] != '\0' || argv_sp[i][j] != '\0')
        {
            func[i][j] = argv_sp[i][j];
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int     fd[2];
    int     pid1;
    int     pid2;
    char    **func1;
    char    **func2;

    if (argc < 5)
        return (write(1, "Wrong number of arguments.\n", 27));
    if (pipe(fd) == -1)
        return (write(1, "Could not initialize the pipe.\n", 31));
    pid1 = fork();
    pid2 = fork();
    fill_func(func1, argv[2]);
    fill_func(func2, argv[4]);
    if (pid1 < 0 || pid2 < 0)
        return (write(1, "Could not fork the process.\n", 28));
    if (pid1 == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execve(func1[0], func1, NULL);
    }
    if (pid2 == 0)
    {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execve(func2[0], func2, NULL);
    }
    close(fd[0]);
    close(fd[1]);    
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return (0);
}