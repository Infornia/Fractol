/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 20:08:06 by mwilk             #+#    #+#             */
/*   Updated: 2015/06/10 18:14:17 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define COL_R(i) (i >> 16) & 0x000000ff
#define COL_G(i) (i >> 8) & 0x000000ff
#define COL_B(i) i & 0x000000ff

void	color_pixel(t_img *d, unsigned int color, int x, int y)
{
	int	i;

		i = x * d->bpp + y * d->size;
	if (i > 0 && i < d->max_size)
	{
		d->data_img[i] = COL_B(color);
		d->data_img[i + 1] = COL_G(color);
		d->data_img[i + 2] = COL_R(color);
	}
}

unsigned int	create_color(int r, int g, int b)
{
	return (b + (g << 8) + (r << 16));
}
