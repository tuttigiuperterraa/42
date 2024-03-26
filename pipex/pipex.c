/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:27:47 by gcosenza          #+#    #+#             */
/*   Updated: 2024/03/26 08:51:26 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "pipex.h"
#include    <stdlib.h>
# include <stdbool.h>
#include    <stdio.h>
#include    <string.h>
#include    <unistd.h>
#include    <sys/types.h>
#include	<fcntl.h>
#include    <sys/wait.h>
#include    "libft/libft.h"
#include    "get_next_line.h"


typedef struct s_pipex
{
	int		file_fds[2];
	int		pipe_fds[2];
	int		prev_output_fd;
	char	**path;
	int		n_cmds;
	int		n_pipes;
}	t_pipex;

void    verbose_exit(char *str)
{
    write (1, str, ft_strlen(str));
    exit (1); 
}

void	ft_error(char *msg, int id)
{
	if (!msg)
		perror("Error");
	else
	{
		ft_putstr_fd("Error: ", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	close_fds();
	if (id == 127)
		free(msg);
	exit(id);
}
char	**get_path(char **envp)
{
	char	**path;

	while (envp && *envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path = ft_split(*envp + 5, ':');
			return (path);
		}
		envp++;
	}
	ft_error("PATH not found in envp", 9);
	return (NULL);
}
const char	**free_path(t_func **funcs, t_pipex pipex)
{
	int i;

	i = 0;
	while(i < pipex.n_cmds)
	{
		(*funcs)[i].path;
		i++;
	}
}
void	dup2_p(int old_fd, int new_fd)
{
	if (dup2(old_fd, new_fd) == -1)
		ft_error(NULL, 12);
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
void	close_fds(void)
{
	int	i;

	i = 0;
	while (i < 1024)
		close(i++);
}
void	close_p(int *fd)
{
	if (*fd != -1)
	{
		if (close(*fd) == -1)
			exit(1);
		*fd = -1;
	}
}
bool	check_heredoc(int argc, char **argv)
{
	if (argc < 5)
		return (write(1, "Wrong number of arguments.\n", 27));
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (argc < 6)
			return (write(1, "Wrong number of arguments.\n", 27));
		return (true);
	}
	return (false);
}
int	create_heredoc(char *limiter)
{
	int		heredoc_fd;
	char	*line;
	int		len;

	heredoc_fd = open("heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		len = ft_strlen(line);
		line[len - 1] = '\0';
		if (ft_strncmp(line, limiter, len) == 0)
			break ;
		ft_putstr_fd(line, heredoc_fd);
		ft_putstr_fd("\n", heredoc_fd);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	get_next_line(-1);
	close_p(&heredoc_fd);
	heredoc_fd = open("heredoc", O_RDONLY, 0644);
	return (heredoc_fd);
}
int	wait_child(int n_cmds)
{
	int	status;
	int	i;

	i = 0;
	while (i < n_cmds)
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		i++;
	}
	return (status);
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
void	menage_inout(int argc, char **argv, t_pipex *pipex, bool is_heredoc)
{
	if (is_heredoc)
	{
		pipex->file_fds[0] = create_heredoc(argv[2]);
		pipex->file_fds[1] = open(argv[argc - 1], O_WRONLY
				| O_CREAT | O_APPEND, 0644);
	}
	else
	{
		pipex->file_fds[0] = open(argv[1], O_RDONLY, 0644);
		pipex->file_fds[1] = open(argv[argc - 1], O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
	}
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
int	parent(t_pipex *pipex, bool is_last)
{
	if (is_last == false)
		close_p(&pipex->pipe_fds[1]);
	else
		close_p(&pipex->file_fds[1]);
	close_p(&pipex->prev_output_fd);
	return (pipex->pipe_fds[0]);
}

void	child(char *cmd_line, char **envp, t_pipex *pipex, bool is_last)
{
	char	**cmd_args;
	char	*cmd_path;

	if (is_last == false)
		close_p(&pipex->pipe_fds[0]);
	dup2_p(pipex->prev_output_fd, STDIN_FILENO);
	close_p(&pipex->prev_output_fd);
	if (is_last == false)
	{
		dup2_p(pipex->pipe_fds[1], STDOUT_FILENO);
		close_p(&pipex->pipe_fds[1]);
	}
	else
	{
		dup2_p(pipex->file_fds[1], STDOUT_FILENO);
		close_p(&pipex->file_fds[1]);
	}
	cmd_args = ft_split(cmd_line, ' ');
	cmd_path = get_cmd_path(cmd_args[0], pipex);
	execve_p(cmd_path, cmd_args, envp);
	close_fds();
}
void	launch(char **argv, t_func *funcs, char **envp, t_pipex *pipex)
{
	int			i;
	pid_t		pid;

	pipex->prev_output_fd = pipex->file_fds[0];
	i = 0;
	while (i < pipex->n_cmds)
	{
		if (i < pipex->n_pipes)
			pipe(pipex->pipe_fds);
		pid = fork();
		if (pid == 0)
			child(argv[i], envp, pipex, i == (pipex->n_cmds -1));
		else
			pipex->prev_output_fd = parent( pipex, i == (pipex->n_cmds - 1));
		i++;
	}
}
int	main(int argc, char **argv, char **envp)
{
	bool	heredoc;
	int		status;
	t_pipex	pipex;

	if (argc < 6)
        return (write(1, "Wrong number of arguments.\n", 27));
	else
	{
		heredoc = check_heredoc(argc, argv);
		pipex.path = get_path(envp);
		menage_inout(argc, argv, &pipex, heredoc);;
		pipex.n_cmds = argc - 3 - heredoc;
		pipex.n_pipes = pipex.n_cmds - 1;
		launch(argv + 2 + heredoc, funcs, envp, &pipex);
		status = wait_child(pipex.n_cmds);
		free_path(&funcs, pipex);
		close_fds();
		exit(status);
	}

}