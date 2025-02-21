/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@strudent.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:50:32 by kapinarc          #+#    #+#             */
/*   Updated: 2024/11/04 14:50:32 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	wrd;

	i = 0;
	wrd = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			wrd++;
		i++;
	}
	return (wrd);
}

static size_t	ft_superlen(char const *s, char c, size_t *index)
{
	size_t	len;

	len = 0;
	while (s[*index] && s[*index] == c)
		(*index)++;
	while (s[*index + len] && s[*index + len] != c)
		len++;
	return (len);
}

static char	*ft_superdup(char const *s, size_t len, size_t *index)
{
	char	*word;
	size_t	i;

	word = ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[*index];
		(*index)++;
		i++;
	}
	return (word);
}

static void	split_destroy(char **split, size_t i)
{
	while (i > 0)
		free (split[--i]);
	free (split);
	split = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	index;
	size_t	len;

	if (!s)
		return (NULL);
	split = ft_calloc(count_word(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	index = 0;
	while (index < count_word(s, c))
	{
		len = ft_superlen(s, c, &i);
		split[index] = ft_superdup(s, len, &i);
		if (!split[index])
		{
			split_destroy(split, index);
			return (NULL);
		}
		index++;
	}
	split[index] = NULL;
	return (split);
}
