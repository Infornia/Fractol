/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 18:16:44 by mwilk             #+#    #+#             */
/*   Updated: 2015/06/01 21:53:05 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

unsigned int	get_img_color(t_data *d, double it, int max_i)
{
	unsigned	color;
	int			i;
	t_img		*img;
	img = &d->pals[d->current_pal];
	i = it / (double)max_i * (double)X_WIN;
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

void			draw(t_data *d)
{
	int		max_i;
//	int		color;
	int		x;
	int		y;

	max_i = sqrt(ABS(2 * sqrt(ABS(1 - sqrt(5 * d->zoom))))) * 66.5;
	x = 0;
	while (x < X_WIN)
	{
		y = 0;
		while (y < Y_WIN)
		{
			d->u.zx = 0.0;
			d->u.zy = 0.0;
			color = d->fractal[d->current_frac](d, x, y, max_i);
			color_pixel(&d->screen, color, x, y);
			y++;
		}
		x++;
	}
}
