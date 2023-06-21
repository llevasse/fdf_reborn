/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:37:51 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/21 11:20:06 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	project(t_data *data)
{
	int		i;

	get_pixel_color(&data->img, 0, 0);
	get_bis(data);
	i = 0;
	while (data->point->point_id != (data->nb_point - 1))
	{
		if ((data->point + 1)->x != 0)
			draw_line(set_line_data(*data->point, *(data->point + 1)),
						&data->img);
		if (i < data->nb_point - data->nb_column)
			draw_line(set_line_data(*data->point, *(data->point
							+ data->nb_column)),
						&data->img);
		data->point++;
		i++;
	}
	reset_point_ptr(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
			0);
}

t_line	set_line_data(t_point p_a, t_point p_b)
{
	struct s_line	line;

	line.p_a = p_a;
	line.p_b = p_b;
	line.dx = abs((int)p_b.x_bis - (int)p_a.x_bis);
	line.sx = 1;
	if (p_a.x_bis > p_b.x_bis)
		line.sx = -1;
	line.dy = abs((int)p_b.y_bis - (int)p_a.y_bis);
	line.sy = 1;
	if (p_a.y_bis > p_b.y_bis)
		line.sy = -1;
	line.error = line.dx / 2;
	if (line.dx < line.dy)
		line.error = (0 - line.dy) / 2;
	line.i = 0;
	line.len = sqrt(pow(line.dy, 2) + pow(line.dx, 2));
	line.x = p_a.x_bis;
	line.y = p_a.y_bis;
	return (line);
}
void	draw_line(t_line line, t_img *img)
{
	while (line.i <= line.dx || line.i <= line.dy)
	{
		if ((line.p_a.x_bis < 0 && line.p_b.x_bis < 0)
			|| (line.p_a.x_bis > WINDOW_WIDTH && line.p_b.x_bis > WINDOW_WIDTH)
			|| (line.p_a.y_bis < 0 && line.p_b.y_bis < 0)
			|| (line.p_a.y_bis > WINDOW_HEIGHT
				&& line.p_b.y_bis > WINDOW_HEIGHT))
			break ;
		img_pix_put(img, line.x, line.y);
		move_forward(&line);
		line.i++;
	}
}

void	move_forward(t_line *line)
{
	if (line->i > line->dx && line->i > line->dy)
		return ;
	line->e2 = line->error;
	if (line->e2 < line->dy)
	{
		line->error += line->dx;
		line->y += line->sy;
	}
	if (line->e2 > (0 - line->dx))
	{
		line->error -= line->dy;
		line->x += line->sx;
	}
}

//  plotLine(x0, y0, x1, y1)
//      dx = abs(x1 - x0)
//      sx = x0 < x1 ? 1 : -1
//      dy = -abs(y1 - y0)
//      sy = y0 < y1 ? 1 : -1
//      error = dx + dy
//
//      while true
//          plot(x0, y0)
//          if x0 == x1 && y0 == y1 break
//          e2 = 2 * error
//          if e2 >= dy
//              if x0 == x1 break
//              error = error + dy
//              x0 = x0 + sx
//          end if
//          if e2 <= dx
//              if y0 == y1 break
//              error = error + dx
//              y0 = y0 + sy
//          end if
//      end while

void	img_pix_put(t_img *img, int x, int y)
{
	char	*pixel;
	int		i;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel = (0xffffff >> i) & 0xFF;
		else
			*pixel = (0xffffff >> (img->bpp - 8 - i)) & 0xff;
		pixel++;
		i -= 8;
	}
}

float	check_angle(float angle)
{
	while (angle < 0)
		angle += 360;
	while (angle > 360)
		angle -= 360;
	return (angle);
}