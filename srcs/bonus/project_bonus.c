/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:37:51 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/12 23:48:18 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/// @brief Refresh the map's values and the display.
/// @param *data Pointr to the Data Struct containing map's data.
void	project(t_data *data)
{
	int		i;

	get_bis(data);
	i = 0;
	while (data->point->point_id != (data->nb_point - 1))
	{
		if ((data->point + 1)->x != 0)
			draw_line(set_line_data(*data->point, *(data->point + 1)),
				&data->img);
		if (i < data->nb_point - data->nb_column)
			draw_line(set_line_data(*data->point, *(data->point
						+ data->nb_column)), &data->img);
		data->point++;
		i++;
	}
	draw_redcross_on_point(*(data->point + 1), &data->img);
	draw_greencross_on_center(&data->img);
	reset_point_ptr(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
}

/// @brief Create a line based om two poits.
/// @param p_a Point struct of point A,
/// @param p_b Point struct of point B.
/// @return Return the line struct created.
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

/// @brief Display the line on to the *img.
/// @param line The line to display on the *img,
/// @param *img Pointer to img struct to display the line on.
void	draw_line(t_line line, t_img *img)
{
	while (line.i <= line.dx || line.i <= line.dy)
	{
		if (is_out_of_bound(line.p_a) || is_out_of_bound(line.p_b))
			break ;
		if (line.x >= 0 && line.x <= WINDOW_WIDTH && line.y >= 0
			&& line.y <= WINDOW_HEIGHT)
			img_pix_put(img, line.x, line.y, get_colour(line));
		move_forward(&line);
		line.i++;
	}
}

/// @brief Check if point is out of bound.
/// @param point t_point struct.
/// @return Return 1 if out of bound and 0 if not.
int	is_out_of_bound(t_point point)
{
	if (point.x_bis > WINDOW_WIDTH || point.x_bis < 0)
		return (1);
	if (point.y_bis > WINDOW_HEIGHT || point.y_bis < 0)
		return (1);
	return (0);
}

/// @brief Move the line's cursor toward it's end point.
/// @param *line The current line being display.
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

/// @brief Put a pixel at X:Y location on an image.
/// @param *img Point to img struct to put pixel on,
/// @param x Int to the horizontal value to print on,
/// @param y Int to the vertical value to print on,
/// @param colour Int value of the colour to print.
void	img_pix_put(t_img *img, int x, int y, int color)
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
			*pixel = (color >> i) & 0xFF;
		else
			*pixel = (color >> (img->bpp - 8 - i)) & 0xff;
		pixel++;
		i -= 8;
	}
}
