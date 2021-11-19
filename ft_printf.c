/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:08:25 by imabid            #+#    #+#             */
/*   Updated: 2021/11/19 11:27:23 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	while (s1[i])
		i++;
	i += 1;
	cpy = (char *)malloc(sizeof(char) * i);
	j = 0;
	if (cpy != NULL)
	{
		while (s1[j])
		{
			cpy[j] = s1[j];
			j++;
		}
		cpy[j] = '\0';
		return (cpy);
	}
	return (NULL);
}

int	get_type(t_print *var, int index)
{
	if (var->str[index] == 'd' || var->str[index] == 'i')
		var->type = 'd';
	else if (var->str[index] == 's')
		var->type = 's';
	else if (var->str[index] == 'c')
		var->type = 'c';
	else if (var->str[index] == 'u')
		var->type = 'u';
	else if (var->str[index] == 'x')
		var->type = 'x';
	else if (var->str[index] == 'X')
		var->type = 'X';
	else if (var->str[index] == '%')
		var->type = '%';
	else if (var->str[index] == 'p')
		var->type = 'p';
	else
		var->type = 0;
	return (index);
}

void	convert_type(t_print *var, va_list pa, int *count)
{
	if (var->type == 'd' || var->type == 'i')
		ft_convert_a(var, pa, count);
	else if (var->type == 's')
		ft_convert_a(var, pa, count);
	else if (var->type == 'c')
		ft_convert_b(var, pa, count);
	else if (var->type == 'u')
		ft_convert_b(var, pa, count);
	else if (var->type == 'x')
		ft_convert_c(var, pa, count);
	else if (var->type == 'X')
		ft_convert_d(var, pa, count);
	else if (var->type == 'p')
		ft_convert_e(var, pa, count);
	else if (var->type == '%')
		ft_convert_b(var, pa, count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	pa;
	t_print	var;

	i = -1;
	count = 0;
	var.str = ft_strdup(s);
	va_start (pa, s);
	while (var.str[++i])
	{
		if (var.str[i] != '%')
		{
			ft_putchar (s[i]);
			count++;
		}
		else
		{
			i = get_type(&var, i + 1);
			convert_type(&var, pa, &count);
		}
	}
	va_end(pa);
	free(var.str);
	return (count);
}
