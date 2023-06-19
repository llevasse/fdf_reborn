/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:28:41 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 16:07:45 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	skip_minus(const char **str)
{
	if (**str == '-')
	{	
		while (**str == '-')
			(*str)++;
		(*str)--;
	}
}

void	print_width_filling(const char *str, va_list args, int width, int *sum)
{
	int	len;

	len = predict_len(str, args);
	if (len > 1 && get_spec(str) == 'p')
		len += 2;
	if (len == 1 && get_spec(str) == 'p')
		len = 5;
	while (width-- > len)
	{
		if (get_para(str) != '0')
			ft_putchar(' ', sum);
		else
			ft_putchar('0', sum);
	}
}
