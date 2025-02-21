/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:01 by kapinarc          #+#    #+#             */
/*   Updated: 2024/11/13 14:17:01 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_putchar(int c)
{
	return ((int)write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(ssize_t nb, char *base, int *count)
{
	int	base_len;

	if (!base || !count)
		return ;
	base_len = (int)ft_strlen(base);
	if (nb < 0)
	{
		nb *= -1;
		*count += ft_putchar('-');
	}
	if (nb >= base_len)
	{
		ft_putnbr_base(nb / base_len, base, count);
		ft_putnbr_base(nb % base_len, base, count);
	}
	else
		*count += ft_putchar(base[nb]);
}

void	ft_putnbr_lb(unsigned long nb, char *base, int *count)
{
	unsigned long long	base_len;

	if (!base || !count)
		return ;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return ;
	if (nb >= base_len)
	{
		ft_putnbr_lb(nb / base_len, base, count);
		ft_putnbr_lb(nb % base_len, base, count);
	}
	else
		*count += ft_putchar(base[nb]);
}
