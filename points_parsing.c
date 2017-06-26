/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 15:37:22 by narajaon          #+#    #+#             */
/*   Updated: 2017/05/29 13:47:33 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		parse_line(int fd, char ***tab)
{
	int			ret;
	char		*str;
	static int	len_prev;
	int			len;

	len = 0;
	ret = get_next_line(fd, &str);
	if (ret == -1)
		exit(error_msg(3));
	if (!(*tab = ft_strsplit(str, ' ')))
		exit(error_msg(2));
	free(str);
	len = tab_len(*tab);
	if (len_prev && len && (len != len_prev))
		exit(error_msg(3));
	len_prev = len;
	return (ret);
}

void	fill_p(t_env *e, t_coor *p, char **ptr, int xy[2])
{
	t_tile		*tile;
	char		**tab;
	int			x;
	int			y;

	x = e->x;
	y = e->y;
	tile = &e->tile;
	p->x = x + xy[0];
	p->y = y + xy[1];
	tab = ft_strsplit(*ptr, ',');
	p->z = ft_atoi(tab[0]);
	p->col = (tab[1]) ? tab[1] : "0x00FFFFFF";
}

t_tile	*get_z(char **ptr1, char **ptr2, t_env *e)
{
	t_tile		*tile;
	int			**ptr;
	int			xy[2];

	tile = &e->tile;
	xy[0] = 0;
	xy[1] = 0;
	fill_p(e, &tile->p1, ptr1, xy);
	xy[0] = 0;
	xy[1] = e->hei;
	fill_p(e, &tile->p2, ptr2, xy);
	xy[0] = e->wid;
	xy[1] = 0;
	ptr1++;
	fill_p(e, &tile->p3, ptr1, xy);
	ptr2++;
	xy[0] = e->wid;
	xy[1] = e->hei;
	fill_p(e, &tile->p4, ptr2, xy);
	return (tile);
}

int		fill_tile_struct(t_env *e, t_list *line1, t_list *line2, int y)
{
	char	**ptr1;
	char	**ptr2;
	t_tile	*tile;
	int		x;
	int		i;

	x = 800;
	i = 0;
	tile = &e->tile;
	ptr1 = line1->content;
	ptr2 = line2->content;
	while (ptr1[i + 1])
	{
		e->x = x;
		e->y = y;
		tile = get_z(&ptr1[i], &ptr2[i], e);
		print_tile(tile, e);
		i++;
		x += e->wid;
	}
	return (0);
}
