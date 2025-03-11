/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pather.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:46:10 by kapinarc          #+#    #+#             */
/*   Updated: 2025/03/06 16:46:46 by kapinarc         ###   ########.fr       */
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

char	*the_path(char *cmd, char **envp)
{
	char	**split_path;
	char	*ultimate_path;
	char	*tmp;
	size_t	i;

	i = -1;
	tmp = get_path(envp) + 5;
	if (!tmp)
		return (NULL);
	split_path = ft_split(tmp, ':');
	if (!split_path)
		return (NULL);
	while (split_path[++i])
	{
		ultimate_path = ft_strjoin(split_path[i], "/");
		tmp = ft_strjoin(ultimate_path, cmd);
		if (access(tmp, F_OK) != -1)
			return (freeman(split_path), free(ultimate_path), tmp);
		free(ultimate_path);
		free(tmp);
	}
	freeman(split_path);
	return (NULL);
}

char	*get_access(char *cmd, char **envp)
{
	if (access(the_path(cmd, envp), F_OK) != -1)
		return (the_path(cmd, envp));
	return (NULL);
}


// ouvrir fichier entree (infile)
// cree pipe
// rediriger entree avec infile (dup2(infile, 0))
// executer premiere commande avec hen_lays en redirigant le contenu dans le pipe (dup2(1, fd[1]))
// ouvrir fichier de sortie (outfile)
// executer deuxieme commande avec hen_lays en redirigant le contenu dans le outfile (dup2(1, outfile))
// a partir du contenu du pipe soit (dup2(0, fddupipe[0]))
// petit tips oublie pas de close tout les fds des pipes a chaque fois que tu