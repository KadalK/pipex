/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@strudent.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:50:32 by kapinarc          #+#    #+#             */
/*   Updated: 2024/11/04 14:50:32 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_in_set(s1[i], set))
		i++;
	len = ft_strlen(s1);
	while (len > i && ft_in_set(s1[len - 1], set))
		len--;
	trim = ft_calloc (len - i + 1, sizeof (char));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[i], len - i +1);
	return (trim);
}
