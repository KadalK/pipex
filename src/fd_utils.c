/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:54:17 by kapinarc          #+#    #+#             */
/*   Updated: 2025/03/11 15:54:17 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	opener(int ac, char **av, int mod)
{
	int	fd;

	if (mod == 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (preturn(-1));
	}
	else
	{
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			return (preturn(-1));
	}
	return (fd);
}

void	close_fd(int fd_pipe[2])
{
	close(fd_pipe[0]);
	close(fd_pipe[1]);
}

int	close_all(int tab[2], int data2, int value)
{
	if (tab)
		close_fd(tab);
	if (data2)
		close(data2);
	return (value);
}

int	preturn(int value)
{
	perror("ERROR");
	return (value);
}
