/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:32:58 by kapinarc          #+#    #+#             */
/*   Updated: 2024/11/19 12:52:28 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_formator(const char *format, va_list *arg)
{
	int	count;

	count = 0;
	if (!*format)
		return (-1);
	if (*format == 'c')
		count += ft_putchar(va_arg(*arg, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(*arg, char *));
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_base(va_arg(*arg, int), "0123456789", &count);
	else if (*format == 'x')
		ft_putnbr_lb(va_arg(*arg, unsigned int), HEXADEC, &count);
	else if (*format == 'X')
		ft_putnbr_lb(va_arg(*arg, unsigned int), UPHEXADEC, &count);
	else if (*format == 'u')
		ft_putnbr_lb(va_arg(*arg, unsigned int), "0123456789", &count);
	else if (*format == 'p')
		print_memo((size_t) va_arg(*arg, size_t), &count);
	else if (*format == '%')
		count += (ft_putchar('%'));
	else
		count = -1;
	return (count);
}

void	print_memo(size_t ptr, int *count)
{
	if ((char *)ptr == NULL)
		return (*count += ft_putstr("(nil)"), (void)0);
	*count += ft_putstr("0x");
	ft_putnbr_lb(ptr, "0123456789abcdef", count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	arg;

	count = 0;
	va_start(arg, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			count += ft_formator(format, &arg);
			if (count == -1)
				break ;
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (count);
}
