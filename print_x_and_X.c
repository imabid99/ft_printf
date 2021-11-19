/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_and_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:05:13 by imabid            #+#    #+#             */
/*   Updated: 2021/11/18 13:19:48 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_hexa(unsigned long int nb)
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

void	ft_putnbr_base(unsigned int nb, char x)
{
	int		j;
	int		tab[100];
	char	*base;
	char	*baseuperx;

	base = "0123456789abcdef";
	baseuperx = "0123456789ABCDEF";
	j = 0;
	if (nb == 0)
		ft_putchar(base[0]);
	while (nb)
	{
		tab[j] = nb % 16;
		nb = nb / 16;
		j++;
	}
	while (--j >= 0)
	{
		if (x == 'X')
			ft_putchar(baseuperx[tab[j]]);
		else
			ft_putchar(base[tab[j]]);
	}
}
