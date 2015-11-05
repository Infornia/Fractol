/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:12:22 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/05 18:08:58 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_data *d)
{
	d->current_frac = 0;
	d->current_pal = 0;
	d->mlx = mlx_init();
	d->win = mlx_new_window (d->mlx, X_WIN, Y_WIN, "Fract'ol");
}

void	init_screen(t_screen *d, void *mlx)
{
	d->img = mlx_new_image(mlx, X_WIN, Y_WIN);
	d->data_img = mlx_get_data_addr
		(d->img, &d->bpp, &d->size, &d->endian);
	d->bpp /= 8;
	d->max_size = d->size * Y_WIN + d->bpp * X_WIN;
}

void	init_variables(t_data *d)
{
	d->os_x = 0.0f;
	d->os_y = 0.0f;
}
