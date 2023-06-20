/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:07:19 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/20 11:15:03 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    print_lines(char **lines, int col, int rows)
{
    int i; //col
    int y; //ros

    i = 0;
    y = 0;
    while (lines[y + i])
    {
        ft_printf(" %s ", lines[y + i]);
        if (i == col)
        {
            ft_printf("\n");
            i = 0;
            y += col;
        }
        i++;
    }
    (void)rows;
}
