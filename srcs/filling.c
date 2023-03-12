/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:40:24 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/12 17:50:23 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	set_false_point(t_point p_1, t_point p_2)
{
	struct s_point	p_3;

	if (p_1.z > p_2.z)
	{
		p_3.x_bis = p_1.x_bis_no_z;
		p_3.y_bis = p_1.y_bis_no_z;
		p_3.colour.hex = p_2.colour.hex;
	}
	else
	{
		p_3.x_bis = p_2.x_bis_no_z;
		p_3.y_bis = p_2.y_bis_no_z;
		p_3.colour.hex = p_1.colour.hex;
	}
	return (p_3);
}

void	draw_line_filling(t_line line, t_img *img)
{
	while (line.i <= line.dx || line.i <= line.dy)
	{
		if ((line.p_a.x_bis < 0 && line.p_b.x_bis < 0)
			|| (line.p_a.x_bis > WINDOW_WIDTH && line.p_b.x_bis > WINDOW_WIDTH)
			|| (line.p_a.y_bis < 0 && line.p_b.y_bis < 0)
			|| (line.p_a.y_bis > WINDOW_HEIGHT
				&& line.p_b.y_bis > WINDOW_HEIGHT))
			break ;
		if (line.x >= 0 && line.x <= WINDOW_WIDTH && line.y >= 0
			&& line.y <= WINDOW_HEIGHT)
			img_pix_put(img, line.x, line.y, get_colour(line));
		move_forward(&line);
		line.i++;
	}
}

void	draw_triangle(t_point left, t_point right, t_point top, t_img *img)
{
	t_line	left_to_right;
	t_line	left_to_top;
	t_line	right_to_top;

	left.colour.hex = 0x000000;
	right.colour.hex = 0x000000;
	top.colour.hex = 0x000000;
	left_to_right = set_line_data(left, right);
	left_to_top = set_line_data(left, top);
	right_to_top = set_line_data(right, top);
	while ((left_to_top.i <= left_to_top.dx || left_to_top.i <= left_to_top.dy)
		&& (right_to_top.i <= right_to_top.dx
			|| right_to_top.i <= right_to_top.dy))
	{
		draw_line_filling(left_to_right, img);
		move_forward(&left_to_top);
		left_to_right.p_a.x_bis = left_to_top.x;
		left_to_right.p_a.y_bis = left_to_top.y;
		left_to_right = set_line_data(left_to_right.p_a, left_to_right.p_b);
		draw_line_filling(left_to_right, img);
		move_forward(&right_to_top);
		left_to_right.p_b.x_bis = right_to_top.x;
		left_to_right.p_b.y_bis = right_to_top.y;
		left_to_right = set_line_data(left_to_right.p_a, left_to_right.p_b);
		left_to_top.i++;
		right_to_top.i++;
	}
}
