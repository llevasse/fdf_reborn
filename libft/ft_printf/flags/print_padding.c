/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:44:31 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 16:07:45 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_padding(const char *str, va_list args, char c, int *sum)
{
	int			var_len;
	long long	int_to_print;
	int			padding_len;

	padding_len = ft_atoi(str);
	while (*str && !is_specifier(*str, 0))
		str++;
	var_len = print_odd(str, args, sum, &padding_len);
	if (padding_len == 0 && is_neg(str, args) == 2 && get_para(str) == '0')
		return (ft_putchar('0', sum));
	while (padding_len-- - var_len > 0)
		ft_putchar(c, sum);
	if (is_neg(str, args) == 2)
		return ((void)va_arg(args, int));
	if (!ft_is_in_str("di", *str))
		return (print_var(str, args, sum));
	int_to_print = va_arg(args, int);
	if (int_to_print == 0 && !has_prec(str))
		return (ft_putchar('0', sum));
	if (int_to_print >= 0 && has_prec(str))
		padding_len--;
	if (int_to_print < 0)
		int_to_print *= -1;
	return (ft_putnbr(int_to_print, 0, sum));
}

int	print_odd(const char *str, va_list args, int *sum, int *padding)
{
	va_list	args_cp;
	int		var_len;

	va_copy(args_cp, args);
	var_len = predict_len(str, args);
	if (*str == 'p')
	{
		*padding -= 2;
		ft_putstr("0x", sum);
	}
	var_len = odd_nbr(str, args_cp, padding, sum);
	return (var_len);
}

int	odd_nbr(const char *str, va_list args_cp, int *padding, int *sum)
{
	int	int_to_print;
	int	var_len;

	var_len = predict_len(str, args_cp);
	if (*str == 'd' || *str == 'i')
	{
		int_to_print = va_arg(args_cp, int);
		if (int_to_print < 0)
		{
			if (get_para(str) == '0' && !has_prec(str))
				(*padding)--;
			var_len--;
			ft_putchar('-', sum);
			int_to_print *= -1;
		}
		if (int_to_print == 0 && get_para(str) == '0' && !has_prec(str))
			var_len--;
	}
	if (ft_is_in_str("xXu", *str))
	{
		int_to_print = va_arg(args_cp, long long);
		if (int_to_print == 0 && get_para(str) == '0' && !has_prec(str))
			var_len--;
	}
	return (var_len);
}
