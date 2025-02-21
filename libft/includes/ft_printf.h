/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:32:58 by kapinarc          #+#    #+#             */
/*   Updated: 2024/11/19 15:45:51 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# define HEXADEC "0123456789abcdef"
# define UPHEXADEC "0123456789ABCDEF"

int		ft_formator(const char *format, va_list *arg);
int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(const char *str);
void	ft_putnbr_base(ssize_t nb, char *base, int *count);
void	ft_putnbr_lb(unsigned long nb, char *base, int *count);
void	print_memo(size_t ptr, int *count);
size_t	ft_strlen(const char *str);

#endif