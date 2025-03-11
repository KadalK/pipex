/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:07:33 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/19 14:07:33 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct s_exe
{
	char	*path;
	int		*tab;
	char	*cmd[];
} t_exe;

//pather.c
char	*get_path(char **envp);
char	*the_path(char *cmd, char **envp);
char	*get_access(char *cmd, char **envp);

void	freeman(char **man);
int		exec_arg(char *cmd, char **envp);
int	hen_lays(char *cmd, char **envp, int fd_pipe[2], int mod);


#endif