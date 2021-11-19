/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:51:23 by imabid            #+#    #+#             */
/*   Updated: 2021/11/19 11:21:01 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_print
{
	char	type;
	char	*str;
}	t_print;

int		ft_printf(const char *s, ...);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putnbr_base(unsigned int nb, char x);
int		len(int nb);
int		len_u(unsigned int nb);
int		len_hexa_p(unsigned long int nb);
void	ft_putnbr_base_p(void *x);
int		len_hexa(unsigned long int nb);
void	ft_putnbr(int nb);
void	ft_unsigned_putnbr(unsigned int nb);
void	ft_convert_a(t_print *var, va_list pa, int *count);
void	ft_convert_b(t_print *var, va_list pa, int *count);
void	ft_convert_c(t_print *var, va_list pa, int *count);
void	ft_convert_d(t_print *var, va_list pa, int *count);
void	ft_convert_e(t_print *var, va_list pa, int *count);
void	convert_type(t_print *var, va_list pa, int *count);
int		get_type(t_print *var, int index);

#endif