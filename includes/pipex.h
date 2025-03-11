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
# define PIPEX_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

//pather.c
char	*get_path(char **envp);
char	*the_path(char *cmd, char **envp);
char	*get_access(char *cmd, char **envp);
int		exec_arg(char *cmd, char **envp);
void	freeman(char **man);
//incubator.c
int		egg(char *cmd, char **envp, int fd_pipe[2], int mod);
int		mother(int ac, char **av, char **envp);
//fd_utils.c
int		opener(int ac, char **av, int mod);
void	close_fd(int fd_pipe[2]);
int		close_all(int tab[2], int data2, int value);
int		preturn(int value);

#endif