/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:15:07 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/11 16:12:57 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	check_option(const char *string, va_list arg, int *length)
{
	if (*string == '%')
		ft_putchar_fd('%', 1, length);
	if (*string == 'c')
		ft_putchar_fd(va_arg(arg, int), 1, length);
	if (*string == 's')
		ft_putstr_fd(va_arg(arg, char *), 1, length);
	if (*string == 'd' || *string == 'i')
		ft_putnbr_fd(va_arg(arg, int), 1, length);
	if (*string == 'u')
		ft_putnbr_unsiged_fd(va_arg(arg, unsigned int), 1, length);
	if (*string == 'x')
		ft_putnbr_base(va_arg(arg, size_t), BASE_HEX_LOW, length, *string);
	if (*string == 'X')
		ft_putnbr_base(va_arg(arg, size_t), BASE_HEX_UP, length, *string);
	if (*string == 'p')
	{
		ft_putstr_fd("0x", 1, length);
		ft_putnbr_base((size_t)va_arg(arg, void *),
			BASE_HEX_LOW, length, *string);
	}
}
