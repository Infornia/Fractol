/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 16:55:47 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/05 18:07:56 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data		*main_frac(void)
{
	t_data		*d;

	if (!(d = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	init_mlx(d);
	init_screen(&d->s, d->mlx);
//	init_images(d);
//	init_frac(d);
	init_variables(d);
	return(d);
}
void	fractal_del(t_data *d)
{
	if(!d)
		return ;
	free(d);
	exit(0);
}
