/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:06:09 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/22 11:40:41 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct		s_llist
{
	struct s_llist	*next;
	struct s_llist	*prev;
	int				x;
	int				y;
	int				xiso;
	int				yiso;
	int				z;
	char			*color;
}					t_llist;

typedef struct		s_args
{
	char			*arg1;
	char			*arg2;
	char			*arg3;
}					t_args;

typedef struct		s_size
{
	int				nbline;
	int				nbcoor;
	int				height;
	int				width;
	int				scale;
	int				scale2;
	int				xmin;
	int				xmax;
	int				ymin;
	int				ymax;
	int				zmax;
	int				zmin;
	int				deep;
	int				svscale;
}					t_size;

typedef struct		s_read
{
	int				fd;
	char			*line;
	t_llist			*begin;
	t_llist			*tmp;
	char			**tab;
}					t_read;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
	int				*data;
	void			*img2;
}					t_mlx;

typedef struct		s_coor
{
	int				x;
	int				y;
}					t_coor;

typedef struct		s_draw
{
	double			tmp;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			x;
	double			y;
	double			z2;
	double			z1;
	double			z;
	double			a;
	double			b;
}					t_draw;

typedef struct		s_color
{
	char			*colorprev;
	char			*colornext;
	char			*color1hex;
	char			*color2hex;
	char			*color3hex;
	int				color;
	int				check;
}					t_color;

typedef struct		s_event
{
	int				x;
	int				y;
	int				m;
}					t_event;

typedef struct		s_param
{
	t_llist			*list;
	t_size			size;
	t_mlx			mlx;
}					t_param;

t_llist				*ft_callread(char *av, t_size size);
void				ft_assign(t_read *read, t_size size, t_coor *coor);
void				ft_read(t_read *read, t_size size);
t_llist				*ft_create(t_coor coor, char *tab, t_llist *tmp, \
																t_size size);
void				ft_check_valid(char *av, t_size *size);
void				ft_error_map(void);
void				ft_check_size(t_size *size, t_llist *list);
void				ft_init_size(t_size *size);
void				ft_put(t_llist *list, t_size size, t_mlx *ml);
int					ft_key(int keycode, t_param *param);
void				ft_drawx(t_mlx *ml, t_llist *list, t_size size, \
					t_color col);
void				ft_drawy(t_mlx *ml, t_llist *list, t_size size, \
					t_color col);
void				ft_drawseg(t_draw draw, t_mlx *ml, t_size size, \
					t_color col);
void				ft_low(t_draw draw, t_mlx *ml, t_size size, t_color col);
void				ft_high(t_draw draw, t_mlx *ml, t_size size, t_color col);
void				ft_mlx(t_llist *list, t_size size);
void				ft_getz(t_llist *list, t_size *size);
void				ft_error_file(void);
void				ft_init_args(t_args *ag);
void				ft_check_args(char **av, t_size *size, t_args ag);
int					ft_gradient(t_color color, int min, int max, int current);
void				ft_init_colors(t_color *color);
int					ft_color_alt(t_size size, int z);
int					ft_check_color(t_llist *list);
int					ft_choose_color(t_size size, t_draw draw, t_color color);
void				ft_move_lr(t_param *param, int keycode, t_event *event);
void				ft_init_mlx(t_mlx *mlx);
void				ft_move_tb(t_param *param, int keycode, t_event *event);
void				ft_zoom(t_param *param, int keycode, t_event *event);
t_llist				*ft_change_list(t_llist *list, t_size size);
void				ft_unzoom(t_param *param, t_event *event);
void				ft_reset(t_param *param, t_event *event);
void				ft_free_list(t_param *param);
int					ft_choose_color_min(t_size size, t_color color, \
															t_llist *list);
void				ft_minim(t_param *param, t_event *event);
void				ft_put2(t_llist *list, t_mlx *ml, t_size size);

#endif
