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
#include <sys/wait.h>

typedef struct s_exe
{
	char	*path;
	int		*tab;
	char	*cmd[];
} t_exe;

#endif