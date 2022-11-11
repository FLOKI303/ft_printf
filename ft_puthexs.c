/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:31:16 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/11 15:47:03 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putnbr_base(size_t nbr, char *base, int	*length, int C)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (C != 'p')
		nbr = (unsigned int)nbr;
	if (nbr >= 0 && nbr < base_len)
		ft_putchar_fd(base[nbr], 1, length);
	else
	{
		ft_putnbr_base(nbr / base_len, base, length, C);
		ft_putnbr_base(nbr % base_len, base, length, C);
	}
}

void	ft_putptr(size_t nbr, int *length, int C)
{
	ft_putnbr_base(nbr, BASE_HEX_LOW, length, C);
}
