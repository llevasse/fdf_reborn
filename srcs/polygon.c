/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:40:24 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/10 18:39:34 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//first_point is the point with the lowest Y
//sec_point is the point with the farther west X
//third_point is the point with the farther east X
//fourth_point is the point with the highest Y

/* void	draw_polygon(t_polygon poly, t_img *img)
{
	int	i;
	int	y;
	int	x;
	int	len;
	int	colour;

	i = 0;
	x = poly.first_line.x;
	y = 0;
	draw_line(poly.y_diag, img);
	draw_line(poly.x_diag, img);
	colour = 0xffffff;
	while (i <= poly.first_line.dx || i <= poly.first_line.dy)
	{
		len = poly.y_diag.x;
		x = poly.first_line.x;
		while (x <= len)
			img_pix_put(img, x++, poly.y_diag.y, colour);
		poly.first_line.e2 = poly.first_line.error;
		poly.y_diag.e2 = poly.y_diag.error;
		if (poly.first_line.e2 < poly.first_line.dy)
		{
			poly.first_line.error += poly.first_line.dx;
			poly.first_line.y += poly.first_line.sy;
		}
		if (poly.y_diag.e2 < poly.y_diag.dy)
		{
			poly.y_diag.error += poly.y_diag.dx;
			poly.y_diag.y += poly.y_diag.sy;
		}
		if (poly.first_line.e2 > (0 - poly.first_line.dx))
		{
			poly.first_line.error -= poly.first_line.dy;
			poly.first_line.x += poly.first_line.sx;
		}
		if (poly.y_diag.e2 > (0 - poly.y_diag.dx))
		{
			poly.y_diag.error -= poly.y_diag.dy;
			poly.y_diag.x += poly.y_diag.sx;
		}
		i++;
	}
	(void)i;
	(void)poly;
	(void)y;
} */
// sort lines by Y values of points
// line with the bigger Ys is first
// line with lowest Ys is last
int	is_points_sorted_y(t_polygon poly)
{
	if (poly.first_point.y_bis > poly.sec_point.y_bis)
		return (0);
	if (poly.sec_point.y_bis > poly.third_point.y_bis)
		return (0);
	if (poly.third_point.y_bis > poly.fourth_point.y_bis)
		return (0);
	if (poly.first_point.y_bis > poly.fourth_point.y_bis)
		return (0);
	return (1);
}
void	swap_point(t_point *p_a, t_point *p_b)
{
	t_point	temp;

	temp = *p_a;
	*p_a = *p_b;
	*p_b = temp;
}

t_polygon	set_polygon_data(t_point p_up_left, t_point p_up_right,
		t_point p_down_left, t_point p_down_right)
{
	struct s_polygon	polygon;

	polygon.first_point = p_up_left;
	polygon.sec_point = p_up_right;
	polygon.third_point = p_down_left;
	polygon.fourth_point = p_down_right;
	while (!is_points_sorted_y(polygon))
	{
		if (polygon.first_point.y_bis > polygon.sec_point.y_bis)
			swap_point(&polygon.first_point, &polygon.sec_point);
		if (polygon.sec_point.y_bis > polygon.third_point.y_bis)
			swap_point(&polygon.sec_point, &polygon.third_point);
		if (polygon.third_point.y_bis > polygon.fourth_point.y_bis)
			swap_point(&polygon.third_point, &polygon.fourth_point);
		if (polygon.first_point.y_bis > polygon.fourth_point.y_bis)
			swap_point(&polygon.first_point, &polygon.fourth_point);
	}
	if (polygon.sec_point.x_bis > polygon.third_point.x_bis)
		swap_point(&polygon.sec_point, &polygon.third_point);
	polygon.y_diag = set_line_data(polygon.first_point, polygon.fourth_point);
	polygon.x_diag = set_line_data(polygon.sec_point, polygon.third_point);
	return (polygon);
}

void	set_center_point(t_polygon *poly)
{
	t_point	center;
	int		colour;

	center.x_bis = poly->x_diag.p_a.x_bis + (poly->x_diag.dx / 2);
	center.y_bis = poly->y_diag.p_a.y_bis + (poly->y_diag.dy / 2);
	center.x = poly->x_diag.p_a.x_bis + (poly->x_diag.dx / 2);
	center.y = poly->y_diag.p_a.y_bis + (poly->y_diag.dy / 2);
	colour = (poly->first_point.colour.hex + poly->sec_point.colour.hex
			+ poly->third_point.colour.hex + poly->fourth_point.colour.hex) / 4;
	center.colour = init_colour(colour, 0, 0, 0);
	poly->center_point = center;
}

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
			&& line.y <= WINDOW_HEIGHT && get_pixel_color(img, line.x,
				line.y) != 0x000000)
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
		draw_line(left_to_right, img);
		move_forward(&left_to_top);
		left_to_right.p_a.x_bis = left_to_top.x;
		left_to_right.p_a.y_bis = left_to_top.y;
		left_to_right = set_line_data(left_to_right.p_a, left_to_right.p_b);
		draw_line(left_to_right, img);
		move_forward(&right_to_top);
		left_to_right.p_b.x_bis = right_to_top.x;
		left_to_right.p_b.y_bis = right_to_top.y;
		left_to_right = set_line_data(left_to_right.p_a, left_to_right.p_b);
		left_to_top.i++;
		right_to_top.i++;
	}
}

void	draw_polygon(t_polygon poly, t_img *img)
{
	set_center_point(&poly);
	poly.first_point.colour = init_colour(0, 0, 0, 0);
	poly.sec_point.colour = init_colour(0, 0, 0, 0);
	poly.third_point.colour = init_colour(0, 0, 0, 0);
	poly.fourth_point.colour = init_colour(0, 0, 0, 0);
	draw_triangle(poly.first_point, poly.sec_point, poly.center_point, img);
	draw_triangle(poly.first_point, poly.third_point, poly.center_point, img);
	draw_triangle(poly.sec_point, poly.fourth_point, poly.center_point, img);
	draw_triangle(poly.third_point, poly.fourth_point, poly.center_point, img);
}
