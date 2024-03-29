/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:04:06 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/02 13:06:55 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/// @brief Draw red cross on a defined point.
/// @param point Point struct on which to draw,
/// @param *img Pointer to img struct on which to draw.
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

/// @brief Draw green cross at center of img.
/// @param *img Pointer to img struct on which to draw.
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
