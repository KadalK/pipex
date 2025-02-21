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

#include "pipex.h"

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
	man =	NULL;
}

char *get_path(char **envp)
{
	char	*path;

	while (envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5))
			break;
		envp++;
	}
	if (!envp)
		return (NULL);
	path = *envp;
	*path += 5;
	return (path);
}

char	*the_path(char *str, char **envp)
{
	char	**split_path;
	char	*ultimate_path;
	char	*tmp;
	size_t i;

	i = -1;
	tmp = get_path(envp) + 5;
	if (!tmp)
		return (NULL);
	split_path = ft_split(tmp , ':');
	if (!split_path)
		return NULL;
	while(split_path[++i])
	{
		ultimate_path = ft_strjoin(split_path[i], "/");
		tmp = ft_strjoin(ultimate_path, str);
		if (access(tmp, F_OK | X_OK) == 0)
			return (freeman(split_path), free(ultimate_path), tmp);
		free(ultimate_path);
		free(tmp);
	}
	freeman(split_path);
	return (NULL);
}

int	exec_arg( t_exe *exe, char *cmd, char **envp)
{
	size_t	i;
	char	**split_cmd;

	i = 0;
	split_cmd = ft_split(cmd, ' ');
	exe->path = the_path(cmd, envp);

	if (exe->path == NULL)
		return (0);
	else
	{
		if (execve(the_path(cmd, envp), split_cmd, envp) == -1)
			return (0);
	}
	return (1);
}

int	hen_lays(t_exe *exe, char *cmd, char **envp)
{
	pid_t	pid;

	if (pipe(exe->tab) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		exec_arg(exe, cmd, envp);
	else
		wait(NULL);
	return (0);
}

int main(int ac, char **av, char **envp)
{
	char	*final_path;
	t_exe *exe;

	exe = NULL;
	if (!*envp)
		return (0);
	if(ac < 2)
		return (0);
	final_path = the_path(av[1], envp);
	printf("FINAL PATH : %s\n", final_path);
	free(final_path);
	return (0);
}