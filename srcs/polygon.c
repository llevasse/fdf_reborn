/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:40:24 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/08 17:02:40 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//first_point is the point with the lowest Y
//sec_point is the point with the farther west X
//third_point is the point with the farther east X
//fourth_point is the point with the highest Y

int	get_current_len_from_y_center(int x, t_point p, int len)
{
	return (x + (len - (x - p.x_bis)));

}

void	draw_polygon(t_polygon poly, t_img *img)
{
	int	i;
	int	y;
	int	x;
	int len;
	int	colour;

	i = 0;
	x = poly.first_line.x;
	y = 0;
	draw_line(poly.y_diag, img);
	colour = 0xffffff;
	while (i <= poly.first_line.dx || i <= poly.first_line.dy)
	{
		if (poly.y_diag.y >= poly.first_line.y)
		{
			x = poly.first_line.x;
			len = get_current_len_from_y_center(x, poly.first_line.p_b, poly.x_diag.dx / 2);
			while (x <= len)
				img_pix_put(img, x++, poly.y_diag.y, colour);
		}
		poly.first_line.e2 = poly.first_line.error;
		if (poly.first_line.e2 < poly.first_line.dy)
		{
			poly.first_line.error += poly.first_line.dx;
			poly.first_line.y += poly.first_line.sy;
			poly.y_diag.y += poly.first_line.sy;
		}
		if (poly.first_line.e2 > (0 - poly.first_line.dx))
		{
			poly.first_line.error -= poly.first_line.dy;
			poly.first_line.x += poly.first_line.sx;
		}
		if (i % poly.y_diag.dy)
			poly.y_diag.x += poly.first_line.sx;
		i++;
	}
	(void)i;
	(void)poly;
	(void)y;
}

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
	struct s_polygon polygon;
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