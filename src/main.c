/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:06:38 by kapinarc          #+#    #+#             */
/*   Updated: 2025/03/11 16:36:18 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (!*envp)
		return (0);
	if (ac != 5)
	{
		errno = EINVAL;
		return (preturn(0));
	}
	mother(ac, av, envp);
	return (0);
}
