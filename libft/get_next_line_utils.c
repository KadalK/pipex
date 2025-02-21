/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:23:39 by kapinarc          #+#    #+#             */
/*   Updated: 2025/01/08 14:07:20 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char		*join;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (free(s1), NULL);
	join = ft_calloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) +1, sizeof(char));
	if (!join)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = 0;
	while (s2[j] && s2[j] != '\n')
	{
		join[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
		join[i + j] = s2[j];
	free(s1);
	return (join);
}

char	*ft_strdup_gnl(char *str)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = ft_calloc(ft_strlen_gnl(str) + 1, sizeof (char));
	if (!dup)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		dup[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		dup[i] = str[i];
	return (dup);
}
