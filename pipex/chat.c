#include    <stdlib.h>
#include    <stdio.h>
#include    <string.h>
#include    <unistd.h>
#include    <sys/types.h>
#include	<fcntl.h>
#include    <sys/wait.h>
#include    "libft/libft.h"

typedef struct s_func
{
    char    *name;
    char    *path;
    char    **parameters;
} t_func;

void	free_matrix(char **matrix)
{
	char	**start;

	if (!matrix || !*matrix)
		return ;
	start = matrix;
	while (*matrix)
		free(*matrix++);
	free(start);
}

char	*find_path(char **envp)
{
	while (envp && *envp)
		if (ft_strncmp(*envp++, "PATH=", 5) == 0)
			return (*(envp - 1) + 5);
	write(2, "PATH not found", 15);
	exit (1);
	return (NULL);
}

char	*get_path(char *path, char *name)
{
	char			**dirs;
	char			*full_path;
	unsigned int	i;
	unsigned int	size;

	dirs = ft_split(path, ':');
	full_path = NULL;
	i = -1;
	while (dirs[++i])
	{
		size = ft_strlen(dirs[i]) + ft_strlen(name) + 2;
		full_path = malloc(size * sizeof(char));
		if (!full_path)
			break ;
		ft_strlcpy(full_path, dirs[i], size);
		ft_strlcat(full_path, "/", size);
		ft_strlcat(full_path, name, size);
		if (access(full_path, X_OK) == 0)
			break ;
		free(full_path);
		full_path = NULL;
	}
	free_matrix(dirs);
    if (full_path == NULL)
    {
        write (1, "Function not found\n", 19);
        exit (1);
    }
	return (full_path);
}

int    init_func(t_func **funcs, char **argv, int argc, char **envp)
{
    int n;
    int i;

    i = 0;
    n = argc - 3;
    *funcs = malloc(sizeof(t_func) * n + 1);
    if (!(*funcs))
        return (write(1, "Malloc error.\n", 15));
    while (i < n)
    {
        (*funcs)[i].parameters = ft_split(argv[i + 2], ' ');
        (*funcs)[i].name = (*funcs)[i].parameters[0];
        (*funcs)[i].path = get_path(find_path(envp), (*funcs)[i].name);
	    if ((*funcs)[i].parameters[0] != NULL)
		    free((*funcs)[i].parameters[0]);
	    (*funcs)[i].parameters[0] = (*funcs)[i].path;
        i++;
    }
	return (0);
}

void    menage_inout(int *fd_files, char **argv, int argc)
{
    fd_files[0] = open(argv[1], O_RDONLY);
	fd_files[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_files[0] == -1 || fd_files[1] == -1)
		exit (1);
}

int sum(int *a, int size)
{
    int sum;

    sum = 0;
    while (size > 0)
    {
        sum += *a;
        a++;
        size--;
    }
	return (sum);
}

int main(int argc, char **argv, char **envp)
{
    int     fd[2];
    int     fd_files[2];
    int     n;
    int     i;
    t_func    *funcs;

    argc--;
    argv++;
    int     pid[argc - 3];
    if (argc < 5)
        return (write(1, "Wrong number of arguments.\n", 27));
    menage_inout(fd_files, argv, argc);
    init_func(&funcs, argv, argc, envp);
    if (pipe(fd) == -1)
        return (write(1, "Could not initialize the pipe.\n", 31));
    i = 0;
    while (i < argc - 3)
    {
        pid[i] = fork();
        if (pid[i] < 0)
        {
            write(1, "Could not fork the process.\n", 28);
            exit(1); // Termina il programma in caso di errore
        }
        else if (pid[i] == 0)
	    {
            //child process
            dup2(fd[1], STDOUT_FILENO);
            dup2(fd_files[0], STDIN_FILENO);
            close(fd[0]);
            close(fd[1]);
            close(fd_files[0]); // Chiudi il file nel figlio
            execve(funcs[i].path, funcs[i].parameters, NULL);
            exit(1); // Termina il processo figlio se execve fallisce
        }
        i++;
    }
    if (i > 0)
    {
        pid[i] = fork();
        if (pid[i] < 0)
        {
            write(1, "Could not fork the process.\n", 28);
            exit(1); // Termina il programma in caso di errore
        }
        else if (pid[i] == 0)
        {
            //child2 process
            dup2(fd[0], STDIN_FILENO);
            dup2(fd_files[1], STDOUT_FILENO);
            close(fd[0]);
            close(fd[1]);
            close(fd_files[1]); // Chiudi il file nel figlio
            execve(funcs[i].path, funcs[i].parameters, NULL);
            exit(1); // Termina il processo figlio se execve fallisce
        }
    }

    // Processo padre
    close(fd[0]);
    close(fd[1]);
    close(fd_files[0]);
    close(fd_files[1]);
    i = 0;
    while (i < argc - 3)
    {
        waitpid(pid[i], NULL, 0);
        i++;
    }
    return (0);
}
