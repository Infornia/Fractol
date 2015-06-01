/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 17:24:04 by mwilk             #+#    #+#             */
/*   Updated: 2015/06/01 19:41:16 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_img	init_image(t_data *d, char *path, int w, int h)
{
	t_img	img;

	img.w = w;
	img.h = h;
	img.img = mlx_xpm_file_to_image(d->mlx, path, &w, &h);
	img.data_img = mlx_get_data_addr(img.img, &img.bpp, &img.size, &img.endian);
	img.bpp /= 8;
	img.max_size = img.size * h + img.bpp * w;
	return (img);
}

void			init_images(t_data *d)
{
	d->pals[0] = init_image(d, T_PAL, 256, 1);
	d->pals[1] = init_image(d, T_PAL1, 512, 1);
	d->pals[2] = init_image(d, T_PAL2, 512, 1);
	d->pals[3] = init_image(d, T_PAL3, 512, 1);
	d->pals[4] = init_image(d, T_PAL4, 512, 1);
	d->pals[5] = init_image(d, T_PAL5, 512, 1);
	d->pals[6] = init_image(d, T_PAL6, 512, 1);
}
