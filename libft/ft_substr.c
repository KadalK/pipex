/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:48:15 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/20 14:50:59 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	total_size;
	size_t			i;

	i = 0;
	total_size = (unsigned int)ft_strlen(s);
	if (start >= total_size)
	{
		sub = ft_calloc(1, 1);
		if (!sub)
			return (NULL);
		return (sub);
	}
	if (len > total_size - start)
		len = total_size - start;
	sub = ft_calloc(len + 1, sizeof (char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
