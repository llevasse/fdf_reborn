/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/11 10:55:12 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

int		ft_printf(const char *string, ...);
void	ft_putstr(char *str, int *sum);
void	ft_putchar(char c, int *sum);
void	ft_putnbr(long long n, int abs, int *sum);
void	ft_putnbr_base(int n, const char *base, int *sum);
void	ft_putnbr_base_u(unsigned long long n, const char *base, int *sum);
void	print_var(const char *str, va_list args, int *sum);
void	print_var_bonus(const char *str, va_list args, int *sum);
int		is_specifier(char c, int bonus);

void	print_pound(const char *str, va_list args, int *sum);

void	print_minus(const char *str, va_list args, int *sum);

void	print_padding(const char *str, va_list args, char c, int *sum);
int		odd_nbr(const char *str, va_list args_cp, int *padding, int *sum);
int		get_para(const char *str);
int		get_spec(const char *str);
int		has_prec(const char *str);

void	print_prec(const char *str, va_list args, int *sum);
void	print_padding_prec(const char *str, va_list args, char c, int *sum);
int		print_odd_prec(const char *str, va_list args, int *sum);

void	print_space(const char *str, va_list args, int *sum);

void	print_plus(const char *str, va_list args, int *sum);

void	print_field_width(const char *str, va_list args, int *sum);
void	print_width_prec(const char *str, va_list args, int width, int *sum);
int		is_neg(const char *str, va_list args);
int		predict_length_precision(const char *str, va_list args, int prec);
void	print_width_prec_s(char *str_to_print, int prec, int *sum);

int		predict_len(const char *str, va_list args);
int		get_size_base_u(unsigned long long n, const char *base);
int		get_size_base(int n, const char *base);
int		get_int_len(int n);
int		get_unsigned_len(unsigned int n);
int		print_odd(const char *str, va_list args, int *sum, int *padding);

int		check_priorities(const char *str, va_list args, int *sum);
int		priorities_zero(const char *str, va_list args, int *sum);

void	skip_to_spec(const char **str);

void	skip_minus(const char **str);
void	print_width_filling(const char *str, va_list args, int width, int *sum);

#endif