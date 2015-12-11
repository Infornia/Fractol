/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 19:01:49 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/11 22:51:13 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			julia(t_data *d, int x, int y, int max_i)
{
	init_julia(d, x, y);
	while (++d->u.i < max_i)
	{
		d->u.zxx = d->u.rz * d->u.rz;
		d->u.zyy = d->u.iz * d->u.iz;
		d->u.old_rz = d->u.rz;
		d->u.old_iz = d->u.iz;
		d->u.rz = d->u.zxx - d->u.zyy + d->u.rc;
		d->u.iz = 2 * d->u.iz * d->u.old_rz + d->u.ic;
		if (d->u.rz == d->u.old_rz && d->u.iz == d->u.old_iz)
			d->u.i = max_i - 1;
		if (d->u.zxx + d->u.zyy > 4.0)
			break ;
	}
	if (d->u.i >= max_i)
		return (0);
	return (get_img_color(d, d->u.i, max_i));
}

int			julia_special(t_data *d, int x, int y, int max_i)
{
	double		color;

	init_julia(d, x, y);
	while (++d->u.i < max_i)
	{
		d->u.old_rz = d->u.rz;
		d->u.rz = d->u.rz * d->u.rz - d->u.iz * d->u.iz;
		d->u.iz = 2 * d->u.old_rz * d->u.iz;
		d->u.rz += d->u.rc;
		d->u.iz += d->u.ic;
		if (d->u.rz * d->u.rz + d->u.iz * d->u.iz > 4.0)
			break ;
		d->u.i++;
	}
	if (d->u.i >= max_i)
		return (0);
	color = d->u.i + 1 - log(log(d->u.rz + d->u.iz)) / log(2);
	return (get_img_color(d, color, max_i));
}
