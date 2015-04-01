/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 20:43:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/01 19:03:46 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_key	set_event(int key_button, void (*event)(t_data *d))
{
	t_key	key;

	key.key_button = key_button;
	key.event = event;
	return (key);
}

static void		reset(t_data *d)
{
	d->projection_type = ISO;
	d->draw_type = IMG;
	d->color_mode = 0;
	d->lr = X_WIN * 2 / 5;
	d->ud = 200 + Y_WIN / 1000;
	d->zoom = 1 + (X_WIN / d->map->map_w / 8) + (Y_WIN / d->map->map_h / 6);
	d->peaks = d->map->z_max / Y_WIN;
}

void			init_events(t_data *d)
{
	d->key_event[0] = set_event(ESC, &ft_fdf_exit);
	d->key_event[1] = set_event(UP, &move_up);
	d->key_event[2] = set_event(DOWN, &move_down);
	d->key_event[3] = set_event(LEFT, &move_left);
	d->key_event[4] = set_event(RIGHT, &move_right);
	d->key_event[5] = set_event(ZOOM_IN, &more_zoom);
	d->key_event[6] = set_event(ZOOM_OUT, &less_zoom);
	d->key_event[7] = set_event(PEAK_UP, &more_peak);
	d->key_event[8] = set_event(PEAK_DOWN, &less_peak);
	d->key_event[9] = set_event(RESET, &reset);
	d->key_event[10] = set_event(ZOOM_IN_M, &zoom_in_mouse);
	d->key_event[11] = set_event(ZOOM_OUT_M, &zoom_out_mouse);
}
