/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:04:06 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/23 16:18:42 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	draw_redcross_on_point(t_point point, t_img *img)
{
	img_pix_put(img, point.x_bis, point.y_bis, 0xff0000);
	img_pix_put(img, point.x_bis - 1, point.y_bis, 0xff0000);
	img_pix_put(img, point.x_bis - 2, point.y_bis, 0xff0000);
	img_pix_put(img, point.x_bis - 3, point.y_bis, 0xff0000);
	img_pix_put(img, point.x_bis - 4, point.y_bis, 0xff0000);
	img_pix_put(img, point.x_bis + 1, point.y_bis, 0xff0000);
	img_pix_put(img, point.x_bis + 2, point.y_bis, 0xff0000);
	img_pix_put(img, point.x_bis + 3, point.y_bis, 0xff0000);
	img_pix_put(img, point.x_bis + 4, point.y_bis, 0xff0000);
	img_pix_put(img, point.x_bis, point.y_bis - 1, 0xff0000);
	img_pix_put(img, point.x_bis, point.y_bis - 2, 0xff0000);
	img_pix_put(img, point.x_bis, point.y_bis - 3, 0xff0000);
	img_pix_put(img, point.x_bis, point.y_bis - 4, 0xff0000);
	img_pix_put(img, point.x_bis, point.y_bis + 1, 0xff0000);
	img_pix_put(img, point.x_bis, point.y_bis + 2, 0xff0000);
	img_pix_put(img, point.x_bis, point.y_bis + 3, 0xff0000);
	img_pix_put(img, point.x_bis, point.y_bis + 4, 0xff0000);
}

void	draw_greencross_on_center(t_img *img)
{
	img_pix_put(img, (WINDOW_WIDTH / 2) - 1, (WINDOW_HEIGHT / 2), 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2) - 2, (WINDOW_HEIGHT / 2), 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2) - 3, (WINDOW_HEIGHT / 2), 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2) - 4, (WINDOW_HEIGHT / 2), 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2) + 1, (WINDOW_HEIGHT / 2), 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2) + 2, (WINDOW_HEIGHT / 2), 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2) + 3, (WINDOW_HEIGHT / 2), 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2) + 4, (WINDOW_HEIGHT / 2), 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2) - 1, 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2) - 2, 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2) - 3, 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2) - 4, 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2) + 1, 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2) + 2, 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2) + 3, 0x00ff00);
	img_pix_put(img, (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2) + 4, 0x00ff00);
}
