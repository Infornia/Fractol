/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 17:24:04 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/13 17:38:42 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_img	init_image(t_data *d, char *path, int w, int h)
{
	t_img	img;

	img.w = w;
	img.h = h;
	img.ptr = mlx_xpm_file_to_image(d->mlx, path, &w, &h);
	img.data_img = mlx_get_data_addr(img.img, &img.bpp, &img.size, &img.endian);
	img.bpp /= 8;
	img.max_size = img.size_line * h + img.bpp * w;
	return (img);
}

void			init_images(t_data *d)
{
	d->plas[0] = init_image(d, T_PAL, 256, 1);
	d->plas[1] = init_image(d, T_PAL1, 512, 1);
	d->plas[2] = init_image(d, T_PAL2, 512, 1);
	d->plas[3] = init_image(d, T_PAL3, 512, 1);
	d->plas[4] = init_image(d, T_PAL4, 512, 1);
	d->plas[5] = init_image(d, T_PAL5, 512, 1);
	d->plas[6] = init_image(d, T_PAL6, 512, 1);
}

void			frac_del(t_data *d)
{
	int	i;

	if (!d)
		return ;
	if (d->screen.ptr)
		mlx_destroy_image(d->mlx, d->screen.img);
	i= -1;
	while (++i < NB_PAL)
		mlx_destroy_image(d->mlx, d->plas[i].img);
	free(d);
	exit(0);
}
