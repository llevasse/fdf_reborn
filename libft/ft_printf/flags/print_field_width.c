/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:28:18 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 16:07:45 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_field_width(const char *str, va_list args, int *sum)
{
	int		width;

	skip_minus(&str);
	width = ft_atoi(str);
	if (width < 0)
		return (print_minus((str + 1), args, sum));
	if (*str == '*')
		width = va_arg(args, int);
	while (!is_specifier(*str, 0))
	{
		if (*str++ == '.')
			return (print_width_prec(str, args, width, sum));
	}
	if (is_neg(str, args) == 1)
		ft_putchar('-', sum);
	print_width_filling(str, args, width, sum);
	print_var(str, args, sum);
}

void	print_width_prec(const char *str, va_list args, int width, int *sum)
{
	int		i;
	int		prec;
	int		spec;

	prec = ft_atoi(str);
	spec = ' ';
	i = predict_length_precision(str, args, prec);
	while (width > i++)
		ft_putchar(spec, sum);
	i = 0;
	if (ft_is_in_str("diuxX", get_spec(str)))
		print_padding(str, args, '0', sum);
	if (get_spec(str) == 's')
		print_width_prec_s(va_arg(args, char *), prec, sum);
	if (get_spec(str) == 'c')
		ft_putchar(va_arg(args, int), sum);
}

int	is_neg(const char *str, va_list args)
{
	long long			int_to_print;
	va_list				args_cp;

	va_copy(args_cp, args);
	if (ft_is_in_str("dixXu", get_spec(str)))
	{
		int_to_print = va_arg(args_cp, int);
		if (get_para(str) == '0')
		{
			if (int_to_print < 0)
				return (1);
		}
		if (int_to_print == 0)
			return (2);
	}
	return (0);
}

void	print_width_prec_s(char *str_to_print, int prec, int *sum)
{
	if (!str_to_print && prec >= 6)
		str_to_print = "(null)";
	while (prec-- > 0 && str_to_print && *str_to_print)
		ft_putchar(*str_to_print++, sum);
}
