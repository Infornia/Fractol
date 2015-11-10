/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 15:30:23 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/10 15:53:12 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			print_usage(int ac)
{
	if (ac != 1)
	{
    	ft_putstr("\033[32m\tusage: ./fractol\n\n\033[0m");
		return ;
	}
    ft_putstr("\033[35m\n\t *****Welcome to Fractol*****\n\n\033[0m");
    ft_putstr("\033[33m\t---------Commands---------\n");
    ft_putstr("\tColors:");
    ft_putstr("\t\n\t\tNext =\t\t2\n\t\tPrevious =\t1\n\n");
    ft_putstr("\tIterations:\n\t\tMore =\t\t]\n\t\tLess =\t\t[\n\n");
    ft_putstr("\tZoom:\n\t\t");
	ft_putstr("In =\t\t+\n\t\tOut =\t\t-\n\t\tMouse Scroll\n\n");
    ft_putstr("\tMoves:\t\t\tArrows\n\n\033[0m");
    ft_putstr("\033[36m\tReset:\t\t\t0\n\033[0m");
    ft_putstr("\033[31m\tExit:\t\t\tesc\n\n\033[0m");
}
