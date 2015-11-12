/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 19:01:49 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/12 12:22:31 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			julia(t_data *d, int x, int y, int max_i)
{
	init_julia(d, x, y);
	while (++d->u.i < max_i)
	{
		d->u.zxx = d->u.RZ * d->u.RZ;
		d->u.zyy = d->u.IZ * d->u.IZ;
		d->u.old_RZ = d->u.RZ;
		d->u.old_IZ = d->u.IZ;
		d->u.RZ = d->u.zxx - d->u.zyy + d->u.RC;
		d->u.IZ = 2 * d->u.IZ * d->u.old_RZ + d->u.IC;
		if (d->u.RZ == d->u.old_RZ && d->u.IZ == d->u.old_IZ)
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
		d->u.old_RZ = d->u.RZ;
		d->u.RZ = d->u.RZ * d->u.RZ - d->u.IZ * d->u.IZ;
		d->u.IZ = 2 * d->u.old_RZ * d->u.IZ;
		d->u.RZ += d->u.RC;
		d->u.IZ += d->u.IC;
		if (d->u.RZ * d->u.RZ + d->u.IZ * d->u.IZ > 4.0)
			break ;
		d->u.i++;
	}
	if (d->u.i >= max_i)
		return (0);
	color = d->u.i + 1 - log(log(d->u.RZ + d->u.IZ)) / log(2);
	return (get_img_color(d, color, max_i));
}
