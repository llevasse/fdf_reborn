/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:37:51 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/04 10:37:24 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	project(t_data *data)
{
	int	i;

	get_bis(data);
	i = 0;
	while (data->point->point_id != data->nb_point)
	{
		if ((data->point + 1)->x != 0)
			draw_line(*data, *data->point, *(data->point + 1), &data->img);
		if (i < data->nb_point - data->nb_column)
			draw_line(*data, *data->point, *(data->point + data->nb_column), &data->img);
		data->point++;
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
			0);
}

void	draw_line(t_data data, t_point p_a, t_point p_b, t_img *img)
{
	int dx, dy, sx, sy, error, e2;
	dx = abs((int)p_b.x_bis - (int)p_a.x_bis);
	sx = p_a.x_bis < p_b.x_bis ? 1 : -1;
	dy = -abs((int)p_b.y_bis - (int)p_a.y_bis);
	sy = p_a.y_bis < p_b.y_bis ? 1 : -1;
	error = dx + dy;
	while (1)
	{
		if ((p_a.x_bis < 0 && p_b.x_bis < 0) || (p_a.x_bis > WINDOW_WIDTH
				&& p_b.x_bis > WINDOW_WIDTH) || (p_a.y_bis < 0 && p_b.y_bis < 0)
			|| (p_a.y_bis > WINDOW_HEIGHT && p_b.y_bis > WINDOW_HEIGHT))
			break ;
		if (p_a.x_bis >= 0 && p_a.x_bis <= WINDOW_WIDTH && p_a.y_bis >= 0
			&& p_a.y_bis <= WINDOW_HEIGHT)
			img_pix_put(img, 1, 1, 0xffffff);
/* 			img_pix_put(img, p_a.x_bis, p_a.y_bis, 0xFFFFFF);
 */		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (p_a.x_bis == p_b.x_bis)
				break ;
			error = error + dy;
			p_a.x_bis += sx;
		}
		if (e2 <= dx)
		{
			if (p_a.y_bis == p_b.y_bis)
				break ;
			error += dx;
			p_a.y_bis += sy;
		}
	}
	(void)data;
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

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xff;
		i -= 8;
	}
}
