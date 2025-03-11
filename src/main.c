/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:06:38 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/21 20:58:27 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	freeman(char **man)
{
	int	x;

	x = 0;
	while (man && man[x])
	{
		free(man[x]);
		x++;
	}
	free(man);
	man = NULL;
}

int	exec_arg(char *cmd, char **envp)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	path = the_path(split_cmd[0], envp);
	if (!path)
		return (free(path), freeman(split_cmd), -1); //msg
	if (execve(path, split_cmd, envp) == -1) // msg
		return (freeman(split_cmd), free(path), 0);
	return (1);
}

int	opener(int ac, char **av, int mod)
{
	int	fd;

	if (mod == 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (-1);
	}
	else
	{
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (fd == -1)
				return (-1);
	}
	return (fd);
}

void	close_fd(int fd_pipe[2])
{
	close(fd_pipe[0]);
	close(fd_pipe[1]);
}

int	hen_lays(char *cmd, char **envp, int fd_pipe[2], int mod)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		if (mod == 1)
			if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
				return (-1);
		if (mod == 0)
			if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
				return (-1);
		close_fd(fd_pipe);
		exec_arg(cmd, envp);
	}
	return (0);
}

int	mother(int ac, char **av, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	fd_pipe[2];

	fd_in = opener(ac, av, 0);
	if (pipe(fd_pipe) == -1)
		return (-1);
	if (dup2(fd_in, STDIN_FILENO) == -1)
		ft_putendl_fd("Invalid infile", 2);
	hen_lays(av[2], envp, fd_pipe, 0);
	fd_out = opener(ac, av, 1);
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		ft_putendl_fd("Invalid outfile", 2);
	hen_lays(av[3], envp, fd_pipe, 1);
	close_fd(fd_pipe);
	while (wait(NULL) > 0)
	;
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	if (!*envp)
		return (0);
	if (ac < 5)
	{
		ft_putendl_fd("Invalid Arguments", 2);
		return (0);
	}
	mother(ac, av, envp);
	return (0);
}
