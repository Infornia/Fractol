/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:12:22 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/28 20:03:08 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_data *d, int n)
{
	d->current_frac = n <= NB_FRACTAL - 1 ? n : 0;
	d->current_pal = 0;
	d->mlx = mlx_init();
	d->win = mlx_new_window (d->mlx, X_WIN, Y_WIN, "Fract'ol");
}

void	init_screen(t_img *d, void *mlx)
{
	d->img = mlx_new_image(mlx, X_WIN, Y_WIN);
	d->data_img = mlx_get_data_addr
		(d->img, &d->bpp, &d->size, &d->endian);
	d->bpp /= 8;
	d->max_size = d->size * Y_WIN + d->bpp * X_WIN;
}

void	init_variables(t_data *d)
{
	d->it = 0;
	d->count = 0;
	d->rainbow = 36;
	d->tri_color_opt = 0;
	d->tri_opt = 0;
	d->r = 255;
	d->g = 255;
	d->b = 255;
	d->os_zoom_x = 0.f;
	d->os_zoom_y = 0.f;
	d->os_x = 0.f;
	d->os_y = 0.f;
	d->zoom = 1.f;
	d->click_x = 0;
	d->click_y = 0;
	d->move_x = 0;
	d->move_y = 0;
	d->c0x = 1.5 * (-X_HALF) / (d->zoom * X_HALF);
	d->c0y = (-Y_HALF) / (d->zoom * Y_HALF);
	d->zoom_w = d->zoom * (float)X_HALF;
	d->zoom_h = d->zoom * (float)Y_HALF;
	d->julia_cx = -0.8;
	d->julia_cy = 0.3;
}

void	init_julia(t_data *d, int x, int y)
{
	d->u.RC = d->julia_cx;
	d->u.IC = d->julia_cy;
	d->u.RZ = 1.6 * (x - X_HALF) / (d->zoom_w) + d->os_x;
	d->u.IZ = 1.2 * (y - Y_HALF) / (d->zoom_h) + d->os_y;
	d->u.i = 1;
}

void	init_mandelbrot(t_data *d, int x, int y)
{
	d->u.i = 0;
	d->u.RC = 1.6 * (x - X_HALF) / (d->zoom * X_HALF);
	d->u.RC += d->os_x - 0.5 + d->os_zoom_x / 2.0;
	d->u.IC = 1.1 * (y - Y_HALF) / (d->zoom * Y_HALF);
	d->u.IC += d->os_y + d->os_zoom_y / 2.0;
	d->u.RZ = d->u.RC;
	d->u.IZ = d->u.IC;
}
