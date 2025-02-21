/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:22:42 by kapinarc          #+#    #+#             */
/*   Updated: 2025/01/08 14:05:12 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, const char *s2);
char	*ft_strdup_gnl(char *str);
void	ft_buffclean(char *str);
int		is_line(const char *str);
char	*get_next_line(int fd);

#endif
