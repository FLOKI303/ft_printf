/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:31:16 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/11 15:13:35 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char *base, int	*length)
{
	unsigned int	base_len;
	unsigned int	n;

	base_len = ft_strlen(base);
	n = nbr;
	if (nbr >= 0 && nbr < base_len)
		ft_putchar_fd(base[nbr], 1, length);
	else
	{
		ft_putnbr_base(nbr / base_len, base, length);
		ft_putnbr_base(nbr % base_len, base, length);
	}
}

void	ft_putptr(int *nbr, int *length)
{
	unsigned int	n;

	n = (unsigned int)nbr;
	ft_putnbr_base(n, BASE_HEX_LOW, length);
}
