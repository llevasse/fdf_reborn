/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:40:24 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/09 10:14:37 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//first_point is the point with the lowest Y
//sec_point is the point with the farther west X
//third_point is the point with the farther east X
//fourth_point is the point with the highest Y

int	get_current_len_from_y_center(int x, t_point p, int len)
{
	return (x + (len - (x)));
	(void)p;
}

//bug on test.fdf rotation 45.5.30

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
	polygon.first_line = set_line_data(polygon.first_point, polygon.sec_point);
	polygon.sec_line = set_line_data(polygon.first_point, polygon.third_point);
	polygon.third_line = set_line_data(polygon.sec_point, polygon.fourth_point);
	polygon.fourth_line = set_line_data(polygon.third_point,
										polygon.fourth_point);
	return (polygon);
}

void	set_center_point(t_polygon *poly, t_data *data)
{
	t_point	center;

	center.x_bis = poly->x_diag.p_a.x_bis + (poly->x_diag.dx / 2);
	center.y_bis = poly->y_diag.p_a.y_bis + (poly->y_diag.dy / 2);
	center.x = poly->x_diag.p_a.x_bis + (poly->x_diag.dx / 2);
	center.y = poly->y_diag.p_a.y_bis + (poly->y_diag.dy / 2);
	center.colour = init_colour(0xffffff, 255, 255, 255);
	poly->center_point = center;
	poly->first_to_center = set_line_data(poly->first_point, center);
	poly->sec_to_center = set_line_data(poly->sec_point, center);
	poly->third_to_center = set_line_data(poly->third_point, center);
	poly->fourth_to_center = set_line_data(poly->fourth_point, center);
	(void)data;
}

void	draw_polygon(t_data *data, t_polygon poly, t_img *img)
{
	set_center_point(&poly, data);
	draw_line(poly.first_to_center, img);
	poly.first_to_center.i = 0;
	draw_line(poly.sec_to_center, img);
	poly.sec_to_center.i = 0;
	draw_line(poly.third_to_center, img);
	poly.third_to_center.i = 0;
	draw_line(poly.fourth_to_center, img);
	poly.fourth_to_center.i = 0;
	while ((poly.first_to_center.i <= poly.first_to_center.dx
			|| poly.first_to_center.i <= poly.first_to_center.dy) &&
			(poly.sec_to_center.i <= poly.sec_to_center.dx
					|| poly.sec_to_center.i <= poly.sec_to_center.dy))
	{
		draw_line(poly.first_line, img);
		move_forward(&poly.first_to_center);
		move_forward(&poly.sec_to_center);
		poly.first_line.p_a.x_bis = poly.first_to_center.x;
		poly.first_line.p_a.y_bis = poly.first_to_center.y;
		poly.first_line.p_b.x_bis = poly.sec_to_center.x;
		poly.first_line.p_b.y_bis = poly.sec_to_center.y;
		poly.first_line = set_line_data(poly.first_line.p_a, poly.first_line.p_b);
		poly.first_to_center.i++;
		poly.sec_to_center.i++;
	}
}