/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:18:02 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 16:07:45 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_space(const char *str, va_list args, int *sum)
{
	int		var;
	char	*str_to_print;

	while (*str && !is_specifier(*str, 0))
		str++;
	if (*str == 'i' || *str == 'd')
	{
		var = va_arg(args, int);
		if (var >= 0)
			ft_putchar(' ', sum);
		return (ft_putnbr(var, 0, sum));
	}
	if (*str == 's')
	{
		str_to_print = va_arg(args, char *);
		if (!*str_to_print)
			return ;
		return (ft_putstr(str_to_print, sum));
	}
	print_var(str, args, sum);
}
