/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:51:02 by imabid            #+#    #+#             */
/*   Updated: 2021/11/18 13:02:39 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_a(t_print *var, va_list pa, int *count)
{
	int		nb;
	char	*b;

	if (var->type == 'd' || var->type == 'i')
	{
		nb = va_arg(pa, int);
		ft_putnbr(nb);
		*count = *count + len(nb);
	}
	else if (var->type == 's')
	{
		b = va_arg(pa, char *);
		if (!b)
		{
			write(1, "(null)", 6);
			*count += 6;
		}
		else
		{
			ft_putstr(b);
			*count += ft_strlen(b);
		}
	}
}

void	ft_convert_b(t_print *var, va_list pa, int *count)
{
	int				c;
	unsigned int	nb;

	if (var->type == 'u')
	{
		nb = va_arg(pa, unsigned int);
		ft_unsigned_putnbr(nb);
		*count = *count + len_u(nb);
	}
	else if (var->type == 'c')
	{
		c = va_arg(pa, int);
		ft_putchar(c);
		*count += 1;
	}
	else if (var->type == '%')
	{
		ft_putchar('\%');
		*count += 1;
	}
}

void	ft_convert_c(t_print *var, va_list pa, int *count)
{
	int		nb;

	if (var->type == 'x')
	{
		nb = va_arg(pa, int);
		if (nb < 0)
		{
			ft_putnbr_base(nb, 'x');
			*count += 8;
		}
		else if (nb == 0)
		{
			ft_putnbr_base(nb, 'x');
			*count += 1;
		}
		else
		{
			ft_putnbr_base(nb, 'x');
			*count = *count + len_hexa(nb);
		}
	}
}

void	ft_convert_d(t_print *var, va_list pa, int *count)
{
	int		nb;

	if (var->type == 'X')
	{
		nb = va_arg(pa, int);
		if (nb < 0)
		{
			ft_putnbr_base(nb, 'X');
			*count += 8;
		}
		else if (nb == 0)
		{
			ft_putnbr_base(nb, 'x');
			*count += 1;
		}
		else
		{
			ft_putnbr_base(nb, 'X');
			*count = *count + len_hexa(nb);
		}
	}
}

void	ft_convert_e(t_print *var, va_list pa, int *count)
{
	void				*nc;
	unsigned long int	n;

	if (var->type == 'p')
	{
		nc = va_arg(pa, void *);
		ft_putnbr_base_p(nc);
		n = (unsigned long int)nc;
		if (n == 0)
			*count += 3;
		else
			*count = *count + len_hexa(n) + 2;
	}
}
