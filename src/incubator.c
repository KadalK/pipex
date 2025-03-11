/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:47:34 by kapinarc          #+#    #+#             */
/*   Updated: 2025/03/11 17:29:55 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	egg(char *cmd, char **envp, int fd_pipe[2], int mod)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (preturn(-1));
	if (pid == 0)
	{
		if (mod == 1)
			if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
				return (-1);
		if (mod == 0)
			if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
				return (-1);
		close_fd(fd_pipe);
		if (exec_arg(cmd, envp) == -1)
			return (-1);
		exec_arg(cmd, envp);
	}
	return (0);
}

int	mother(int ac, char **av, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	fd_pipe[2];
	int	i;

	i = 3;
	fd_in = opener(ac, av, 0);
	if (pipe(fd_pipe) == -1)
		return (preturn(-1));
	if (dup2(fd_in, STDIN_FILENO) == -1)
		return (close_all(fd_pipe, 0, -1));
	if (egg(av[2], envp, fd_pipe, 0) == -1)
		return (close_all(fd_pipe, fd_in, -1));
	fd_out = opener(ac, av, 1);
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		return (close_all(fd_pipe, fd_in, -1));
	if (egg(av[3], envp, fd_pipe, 1) == -1)
		return (close_all(fd_pipe, fd_in, -1));
	close_fd(fd_pipe);
	while (wait(NULL) > 0)
		;
	while (i < 1024)
		close(i++);
	return (0);
}
