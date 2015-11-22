/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:55:47 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/22 18:21:18 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data		*main_frac(int frac_number)
{
	t_data		*d;

	if (!(d = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	init_mlx(d, frac_number);
	init_screen(&d->screen, d->mlx);
	init_images(d);
	init_frac(d);
	init_variables(d);
	return(d);
}
void	fractal_del(t_data *d)
{
	int		i;

	if(!d)
		return ;
	i = -1;
	while(d->screen.img && ++i < NB_PAL)
		mlx_destroy_image(d->mlx, d->pals[i].img);
	free(d);
	exit(0);
}

void	init_frac(t_data *d)
{
	d->fractal[0] = &mandelbrot;
	d->fractal[1] = &mandelbrot_special;
	d->fractal[2] = &newton;
	d->fractal[3] = &burnship;
	d->fractal[4] = &julia;
	d->fractal[5] = &julia_special;
	d->fractal[6] = &mandelbrot;
}
