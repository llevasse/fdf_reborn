/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:37:28 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 16:07:45 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_pound(const char *str, va_list args, int *sum)
{
	int	nbr;

	while (*str && !is_specifier(*str, 0))
		str++;
	if (*str == 'x')
	{	
		nbr = va_arg(args, int);
		if (nbr == 0)
			return (ft_putchar('0', sum));
		ft_putstr("0x", sum);
		return (ft_putnbr_base(nbr, "0123456789abcdef", sum));
	}
	else if (*str == 'X')
	{
		nbr = va_arg(args, int);
		if (nbr == 0)
			return (ft_putchar('0', sum));
		ft_putstr("0X", sum);
		return (ft_putnbr_base(nbr, "0123456789ABCDEF", sum));
	}
}
