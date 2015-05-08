/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 20:08:06 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/08 20:27:58 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define COL_R(i) (i >> 16) & 0x000000ff
#define COL_G(i) (i >> 8) & 0x000000ff
#define COL_B(i) i & 0x000000ff

void	color_pixel(t_data *e, int color, int x, int y)
{
	int	i;

	if (x > 0 && x < X_WIN && y > 0 && y < Y_WIN)
	{
		i = x * 4 + y * e->size;
		e->data_img[i] = COL_B(color);
		e->data_img[i + 1] = COL_G(color);
		e->data_img[i + 2] = COL_R(color);
	}
}
