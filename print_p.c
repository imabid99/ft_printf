/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:55:49 by imabid            #+#    #+#             */
/*   Updated: 2021/11/18 13:19:33 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_hexa_p(unsigned long int nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

void	ft_putnbr_base_p(void *x)
{
	int					j;
	int					tab[100];
	unsigned long int	nb;
	char				*base;

	nb = (unsigned long int)x;
	base = "0123456789abcdef";
	j = 0;
	ft_putstr("0x");
	if (nb == 0)
		ft_putchar(base[0]);
	while (nb)
	{
		tab[j] = nb % 16;
		nb = nb / 16;
		j++;
	}
	while (--j >= 0)
		ft_putchar(base[tab[j]]);
}
