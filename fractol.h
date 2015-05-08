/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:42:54 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/08 19:43:03 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "libft/includes/libft.h"

/*
**Parameters
*/

# define X_WIN 2222
# define Y_WIN 1111
# define Y_HALF Y_WIN / 2
# define X_HALF X_WIN / 2
# define NB_FRACTAL 12
# define NB_PAL 12

/*
**Colors
*/
# define RED	0xFF0000
# define BLUE 	0x0000FF
# define QUOISE	0x74BDF9
# define GREEN 	0x00FF00
# define PINK 	0xFF00FF
# define WHITE 	0xFFFFFF
# define GRAY 	0x0F0F0F
# define BLACK 	0x000000
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

/*
**keys
*/

# define ESC		53
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define TAB		48
# define SHIFT		257
# define ZOOM_IN	24
# define ZOOM_OUT	27
# define PEAK_UP	30
# define PEAK_DOWN	33
# define RESET		29
# define TKEY	13
# define ZOOM_IN_M	5
# define ZOOM_OUT_M	4

/*
**Structures
*/

typedef struct s_data	t_data;

typedef struct	s_key
{
	int			key_code;
	void		(*event)(t_data *d);
}				t_key;

typedef struct	s_util
{

}				t_util;

typedef struct	s_img
{
	void		*img;
	char		*data_img;	
	int			bpp;
	int			size;
	int			endian;
	int			max_size;
}				t_img;

struct			s_data
{
	void		*mlx;
	void		*win;
	t_img		screen;
	t_img		pals[NB_PALS];
	t_fractal	fractal[NB_FRACTAL];
	t_util		u;
	t_key		key_event[TKEY];
	int			color;
	int			color_mode;
	int			projection_type;
	int			draw_type;
	int			lr;
	int			ud;
	int			current_pal;
	double		mouse_x;
	double		mouse_y;
	double		c0x;
	double		c0y;
	double		zoom;
	double		zoom_w;
	double		zoom_h;
	double		os_x;
	double		os_y;
	double		os_zoom_x;
	double		os_zoom_y;
};


/*
**Prototypes
*/

/*
*******************INIT
*/
void			ft_fdf_init(t_data *d, char *file);		
void			init_events(t_data *d);
int				expose_hook(t_data *d);
int				mouse_hook(int button, int x, int y, t_data *d);
int				key_hook(int keycode, t_data *d);
void			color_hook(int keycode, t_data *d);
void			ft_fdf_exit(t_data *d);
void			erase_img(t_data *d);

/*
*******************DRAW
*/



/*
*******************MOVE
*/

void			move_left(t_data *d);
void			move_right(t_data *d);
void			move_up(t_data *d);
void			move_down(t_data *d);
void			less_zoom(t_data *d);
void			more_zoom(t_data *d);
void			less_peak(t_data *d);
void			more_peak(t_data *d);
void			rotation(t_point *p, int rot);
void			zoom_in_mouse(t_data *d);
void			zoom_out_mouse(t_data *d);

/*
*******************INUTILISE
*/

void			load_data(t_data *d);
void			print_data(t_data *d);

#endif
