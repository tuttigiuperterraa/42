
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

void    verbose_exit(char *str)
{
    write (1, str, ft_strlen(str));
    exit (1); 
}
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
	verbose_exit("PATH not found");
	//return (NULL);
}

char	*get_path(char *path, char *name)
{
	char			**dirs;
	char			*full_path;
	unsigned int	i;
	unsigned int	size;

	dirs = ft_split(path, ':');
	i = -1;
	while (dirs[++i])
	{
        full_path = NULL;
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
	}
	free_matrix(dirs);
    if (full_path == NULL)
        verbose_exit("Function not found\n");
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

void	wait_child(void)
{
	int		status;

	if (wait(&status) == -1)
		exit(6);
	if (WIFSIGNALED(status))
		exit(6);
	else
	{
		status = WEXITSTATUS(status);
		if (status >= 42 && status <= 44)
			exit(status);
	}
}
void    closepipes(int **pipefd, int i)
{
    while (i > 0)
    {
        close(pipefd[i][0]);
        close(pipefd[i][1]);
        i--;
    }
}
void    menage_parent(int argc, int **pipefd, int *fd_files)
{
    int i;

    i = 0;
    closepipes(pipefd, argc - 4);
	close(fd_files[0]);
	close(fd_files[1]);
    wait_child();
}
  
int main(int argc, char **argv, char **envp)
{
    int     pipefd[argc - 4][2];
    int     fd_files[2];
    int     pid[argc - 3];
    int     n;
    int     i;
    t_func    *funcs;

    if (argc < 5)
        return (write(1, "Wrong number of arguments.\n", 27));
    menage_inout(fd_files, argv, argc);
    init_func(&funcs, argv, argc, envp);
    i = 0;
    while (i < argc - 3)
    {
        if (i < argc - 4)
        {
            if (pipe(pipefd[i]) == -1)
                return (write(1, "Could not initialize the pipe.\n", 31));
        }
        pid[i] = fork();
        if (pid[i] < 0)
            verbose_exit("Could not fork the process.\n");
        else if (pid[i] == 0)
        {
            if (i == 0)
                dup2(fd_files[0], STDIN_FILENO);
            else
                dup2(pipefd[i - 1][0], STDIN_FILENO);
            if (i == argc - 4)
                dup2(fd_files[1], STDOUT_FILENO);
            else
                dup2(pipefd[i][1], STDOUT_FILENO);
            close(pipefd[i][0]);
            execve(funcs[i].path, funcs[i].parameters, NULL);
            verbose_exit("Could not execute child process.\n");
        }
        else
            menage_parent(argc, pipefd, fd_files);
        i++;
    }
    return (0);
}
