/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/02/10 11:41:34 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

int		ft_printf(const char *string, ...);
void	ft_putstr(char *str, int *sum);
void	ft_putchar(char c, int *sum);
void	ft_putnbr(long long n, int *sum);
void	ft_putnbr_base(long long n, const char *base, int *sum);
void	ft_putnbr_base_u(unsigned long long n, const char *base, int *sum);
void	print_var(char c, va_list args, int *sum);

#endif