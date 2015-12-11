/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 20:08:06 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/11 22:52:05 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	get_img_color(t_data *d, double it, int max_i)
{
	unsigned int	color;
	int				i;
	t_img			*img;

	img = &d->pals[d->cur_pal];
	i = it / (double)max_i * (double)img->w;
	i *= img->bpp;
	if (i > 0 && i < img->max_size)
	{
		color = img->data_img[i];
		color += img->data_img[i + 1] << 8;
		color += img->data_img[i + 2] << 16;
	}
	else
		color = 0;
	return (color);
}

void			color_pixel(t_img *d, unsigned int color, int x, int y)
{
	int	i;

	i = x * d->bpp + y * d->size;
	if (i > 0 && i < d->max_size)
	{
		d->data_img[i] = color;
		d->data_img[i + 1] = (color >> 8);
		d->data_img[i + 2] = (color >> 16);
	}
}

unsigned int	create_color(int r, int g, int b)
{
	return (b + (g << 8) + (r << 16));
}

int				get_r_color(double t)
{
	return (RGB(
				127.5 * (cos(t) + 1),
				127.5 * (sin(t) + 1),
				127.5 * (1 - cos(t))));
}
