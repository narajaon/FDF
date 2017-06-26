/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:13:03 by narajaon          #+#    #+#             */
/*   Updated: 2017/05/29 13:40:25 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define WIN_X 2500
# define WIN_Y 1300

typedef struct	s_coor
{
	int		x;
	int		y;
	int		z;
	char	*col;
}				t_coor;

typedef struct	s_tile
{
	t_coor	p1;
	t_coor	p2;
	t_coor	p3;
	t_coor	p4;
}				t_tile;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	long	wid;
	long	hei;
	int		left;
	int		up;
	int		col;
	int		x;
	int		y;
	t_tile	tile;
}				t_env;

int				tab_len(char **tab);
int				error_msg(int error);
void			free_tab(char **tab);
void			coor_dup(t_coor *p, t_coor *tmp);
void			to_iso(t_coor *p);
void			sq_to_iso(t_coor *p1, t_coor *p2, t_coor *p3, t_coor *p4);
int				key_fun(int keycode, void *param);
void			link_points(t_coor *p1, t_coor *p2, t_env *e);
void			coor_dup(t_coor *p, t_coor *tmp);
void			print_tile(t_tile *tile, t_env *e);
int				parse_line(int fd, char ***tab);
int				fill_tile_struct(t_env *e, t_list *line1, t_list *line2, int y);
#endif
