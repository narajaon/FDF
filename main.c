/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 15:27:58 by narajaon          #+#    #+#             */
/*   Updated: 2017/05/29 18:33:43 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		do_fdf3(int fd, t_env *e)
{
	t_list	line[2];
	char	**tab;
	int		y;

	y = -200;
	parse_line(fd, &tab);
	line[0].content = tab;
	while (parse_line(fd, &tab) > 0)
	{
		line[1].content = tab;
		fill_tile_struct(e, &line[0], &line[1], y);
		line[0].content = line[1].content;
		y += e->hei;
	}
	free_tab(tab);
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		size;
	t_env	e;

	if (ac < 2)
		exit(error_msg(1));
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "FDF showcase");
	mlx_key_hook(e.win, &key_fun, 0);
	fd = open(av[1], O_RDONLY);
	e.wid = (ac > 2) ? ft_atoi(av[2]) : 10;
	e.hei = (ac > 3) ? ft_atoi(av[3]) : 10;
	e.wid = (e.wid < -50) ? -50 : e.wid;
	e.hei = (e.hei < -50) ? -50 : e.hei;
	e.wid = (e.wid > 50) ? 50 : e.wid;
	e.hei = (e.hei > 50) ? 50 : e.hei;
	e.col = (ac > 4) ? ft_atoi(av[4]) : 0x00D77412;
	do_fdf3(fd, &e);
	if (!(mlx_loop(e.mlx)))
		exit(error_msg(2));
	return (0);
}
