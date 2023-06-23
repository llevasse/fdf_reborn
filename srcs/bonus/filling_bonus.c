/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:40:24 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/23 14:03:26 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

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
	t_line	l_to_r;
	t_line	l_to_t;
	t_line	r_to_t;

	left.colour.hex = 0x000000;
	right.colour.hex = 0x000000;
	top.colour.hex = 0x000000;
	l_to_r = set_line_data(left, right);
	l_to_t = set_line_data(left, top);
	r_to_t = set_line_data(right, top);
	draw_filling(l_to_r, l_to_t, r_to_t, img);
}

void	draw_filling(t_line l_to_r, t_line l_to_t, t_line r_to_t, t_img *img)
{
	while ((l_to_t.i <= l_to_t.dx || l_to_t.i <= l_to_t.dy)
		&& (r_to_t.i <= r_to_t.dx
			|| r_to_t.i <= r_to_t.dy))
	{
		draw_line_filling(l_to_r, img);
		move_forward(&l_to_t);
		l_to_r.p_a.x_bis = l_to_t.x;
		l_to_r.p_a.y_bis = l_to_t.y;
		l_to_r = set_line_data(l_to_r.p_a, l_to_r.p_b);
		draw_line_filling(l_to_r, img);
		move_forward(&r_to_t);
		l_to_r.p_b.x_bis = r_to_t.x;
		l_to_r.p_b.y_bis = r_to_t.y;
		l_to_r = set_line_data(l_to_r.p_a, l_to_r.p_b);
		l_to_t.i++;
		r_to_t.i++;
	}
}
