/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:25:29 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/13 17:27:05 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/// @brief Create a line based om two poits.
/// @param p_a Point struct of point A,
/// @param p_b Point struct of point B.
/// @return Return the line struct created.
t_line	set_line_data(t_point p_a, t_point p_b)
{
	struct s_line	line;

	if (is_out_of_bound(p_a) && !is_out_of_bound(p_b))
		return (set_line_data(p_b, p_a));
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
		if (is_out_of_bound(line.p_a) && is_out_of_bound(line.p_b))
			break ;
		if (line.x >= 0 && line.x <= WINDOW_WIDTH && line.y >= 0
			&& line.y <= WINDOW_HEIGHT)
			img_pix_put(img, line.x, line.y, get_colour(line));
		else
			break ;
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
