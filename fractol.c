/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:55:47 by mwilk             #+#    #+#             */
/*   Updated: 2015/06/01 19:34:45 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	main_frac(t_data *d)
{
	init_screen(&d->screen, d->mlx);
	init_images(d);
	//init_fractal_fun(d);
	init_variables(d);
	d->current_frac = 0;
	d->current_pal = 0;
	mlx_hook(d->win, 2, 1, key_hook, d);
	mlx_hook(d->win, 4, 4, mouse_hook, d);
	mlx_hook(d->win, 6, 16, mouse_hook_move, d);
	mlx_expose_hook(d->win, expose_hook, d);
	mlx_loop(d->mlx);
}

void	fractal_del(t_data *d)
{
	int		i;

	if(!d)
		return ;
	i = -1;
	while(d->screen.img && ++i < NB_PAL)
		mlx_destroy_image(d->mlx, d->pals[i].img);
	if (d->mlx)
		free(d->mlx);
	if (d->win)
		free(d->win);
	free(d);
	exit(0);
}
