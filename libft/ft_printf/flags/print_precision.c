/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:53:50 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 16:07:45 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_prec(const char *str, va_list args, int *sum)
{
	int		i;
	int		prec;
	char	*str_to_print;

	i = 0;
	prec = ft_atoi(str);
	while (!is_specifier(*(str + i), 0))
		i++;
	if (ft_is_in_str("diuxX", *(str + i)))
		return (print_padding(str, args, '0', sum));
	str += i;
	if (*str == 's' && prec > 0)
	{
		i = 0;
		str_to_print = va_arg(args, char *);
		if (!str_to_print && (size_t)prec < ft_strlen("(null)"))
			return ;
		else if (!str_to_print)
			str_to_print = "(null)";
		while (i < prec && str_to_print[i])
			ft_putchar(str_to_print[i++], sum);
	}
	if (*str == 'c')
		ft_putchar(va_arg(args, int), sum);
}

void	print_padding_prec(const char *str, va_list args, char c, int *sum)
{
	int		var_len;
	int		int_to_print;
	int		padding_len;

	padding_len = ft_atoi(str);
	while (*str && !is_specifier(*str, 0))
		str++;
	var_len = print_odd_prec(str, args, sum);
	while (padding_len-- - var_len > 0)
		ft_putchar(c, sum);
	if (*str != 'd' && *str != 'i')
		return (print_var(str, args, sum));
	int_to_print = va_arg(args, int);
	if (int_to_print < 0)
		int_to_print *= -1;
	return (ft_putnbr(int_to_print, 0, sum));
}

int	print_odd_prec(const char *str, va_list args, int *sum)
{
	va_list	args_cp;
	int		var_len;
	int		int_to_print;

	va_copy(args_cp, args);
	var_len = predict_len(str, args);
	if (*str == 'd' || *str == 'i')
	{
		int_to_print = va_arg(args_cp, int);
		if (int_to_print < 0)
		{
			var_len--;
			ft_putchar('-', sum);
			int_to_print *= -1;
		}
	}
	return (var_len);
}

int	predict_length_precision(const char *str, va_list args, int prec)
{
	int			var_len;
	va_list		args_cp;

	while (*str && !is_specifier(*str, 0))
		str++;
	va_copy(args_cp, args);
	var_len = predict_len(str, args);
	if (*str == 's')
	{
		if (!(va_arg(args_cp, char *)) && prec < 6)
			var_len = 0;
	}
	if (ft_is_in_str("diuxX", *str))
	{
		if (ft_is_in_str("di", *str) \
		&& va_arg(args_cp, int) < 0 && prec >= var_len)
			prec++;
		if (prec > var_len)
			var_len = prec;
		return (var_len);
	}
	if (var_len < prec || *str == 'c')
		return (var_len);
	return (prec);
}
