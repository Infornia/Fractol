/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_key_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 16:25:27 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/01 18:59:47 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_left(t_data *d)
{
	d->lr -= 50;
	erase_img(d);
}

void	move_right(t_data *d)
{
	d->lr += 50;
	erase_img(d);
}

void	move_up(t_data *d)
{
	d->ud -= 50;
	erase_img(d);
}

void	move_down(t_data *d)
{
	d->ud += 50;
	erase_img(d);
}
