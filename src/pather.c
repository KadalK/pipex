/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pather.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:46:10 by kapinarc          #+#    #+#             */
/*   Updated: 2025/03/11 16:53:02 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_path(char **envp)
{
	size_t	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			break ;
		i++;
	}
	return (envp[i] + 5);
}

//fix le acces direct si il est deja bon || cest ok a faire gaff quand meme
char	*the_path(char *cmd, char **envp)
{
	char	**split_path;
	char	*ultimate_path;
	char	*tmp;
	size_t	i;

	i = -1;
	tmp = get_path(envp);
	if (!tmp)
		return (NULL);
	tmp += 5;
	split_path = ft_split(tmp, ':');
	if (!split_path)
		return (NULL);
	if (access(cmd, F_OK) != -1)
			return(cmd);
	while (split_path[++i])
	{
		ultimate_path = ft_strjoin(split_path[i], "/");
		tmp = ft_strjoin(ultimate_path, cmd);
		if (!tmp || access(tmp, F_OK) != -1)
			return (freeman(split_path), free(ultimate_path), tmp);
		free(ultimate_path);
		free(tmp);
	}
	return (freeman(split_path), NULL);
}

char	*get_access(char *cmd, char **envp)
{
	if (access(the_path(cmd, envp), F_OK) != -1)
		return (the_path(cmd, envp));
	return (NULL);
}

int	exec_arg(char *cmd, char **envp)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	path = the_path(split_cmd[0], envp);
	if (!path)
	{
		free(path);
		freeman(split_cmd);
		return (preturn(-1));
	}
	if (execve(path, split_cmd, envp) == -1)
	{
		freeman(split_cmd);
		free(path);
		return (preturn(-1));
	}
	return (1);
}

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
