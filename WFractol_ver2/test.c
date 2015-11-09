/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 16:32:24 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/09 18:40:26 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_data *d)
{
	float	mx;
	float	Mx;
	float	my;
	float	My;
	int		x;
	int		y;
	int		i;
	float	R;
	float	RC;
	float	IC;
	float	RZ;
	float	IZ;
	float	zoom_x;
	float	zoom_y;
	float	max_i;

	mx = -2.1;
	Mx = 0.6;
	my = -1.2;
	My = 1.2;
	zoom_x = X_WIN / (Mx - mx);
	zoom_y = Y_WIN / (My - my);
	max_i = sqrt(ABS(2 * sqrt(ABS(1 - sqrt(5 * zoom_x))))) * 66.5;
	for (x = 0; x < X_WIN; x++)
	{
		for (y = 0; y < Y_WIN; y++)
		{
			RC = x / zoom_x + mx;
			IC = y / zoom_y + my;
			RZ = 0;
			IZ = 0;
			for (i = 0; i < max_i; i++)
			{
				R = RZ;
				RZ = R * R - IZ * IZ + RC;
				IZ = 2 * R * IZ + IC;
				if (RZ * RZ + IZ * IZ >= 4)
					break ;
			}
			if (i == 255)
				color_pixel(&d->s, BLACK, x, y);
			else
				color_pixel(&d->s, RGB(0, 0, i * 255 / max_i), x, y);
		}
	}
}
