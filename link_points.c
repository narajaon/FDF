/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 15:57:22 by narajaon          #+#    #+#             */
/*   Updated: 2017/05/28 15:57:24 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		change_pix(int p1, int p2, int i, int max)
{
	int		pix;

	if (p1 > p2)
		pix = 0x00E13501 - ((i * 255) / max);
	else if (p1 < p2)
		pix = 0x00E13501 - (255 - (i * 255) / max);
	else
		pix = 0x00FFFFFF;
	return (pix);
}

void	put_pix1(t_coor *p1, t_coor *p2, t_env *e)
{
	int		d[2];
	int		inc[2];
	int		cumul;
	int		i;

	i = 1;
	inc[0] = ((p2->x - p1->x) > 0) ? 1 : -1;
	inc[1] = ((p2->y - p1->y) > 0) ? 1 : -1;
	d[0] = ft_abs(p2->x - p1->x);
	d[1] = ft_abs(p2->y - p1->y);
	cumul = d[0] / 2;
	mlx_pixel_put(e->mlx, e->win, p1->x, p1->y, e->col);
	while (i++ <= d[0])
	{
		e->col = 0x004BB5C1;
		cumul = cumul + d[1];
		p1->x += inc[0];
		if (cumul >= d[0])
		{
			cumul = cumul - d[0];
			p1->y += inc[1];
		}
		(p1->z || p2->z) ? e->col = change_pix(p1->z, p2->z, i, d[0]) : e->col;
		mlx_pixel_put(e->mlx, e->win, p1->x, p1->y, e->col);
	}
}

void	put_pix2(t_coor *p1, t_coor *p2, t_env *e)
{
	int		d[2];
	int		inc[2];
	int		cumul;
	int		i;

	i = 1;
	inc[0] = ((p2->x - p1->x) > 0) ? 1 : -1;
	inc[1] = ((p2->y - p1->y) > 0) ? 1 : -1;
	d[0] = ft_abs(p2->x - p1->x);
	d[1] = ft_abs(p2->y - p1->y);
	cumul = d[1] / 2;
	mlx_pixel_put(e->mlx, e->win, p1->x, p1->y, e->col);
	while (i++ <= d[1])
	{
		e->col = 0x004BB5C1;
		cumul = cumul + d[0];
		p1->y += inc[1];
		if (cumul >= d[1])
		{
			cumul = cumul - d[1];
			p1->x += inc[0];
		}
		(p1->z || p2->z) ? e->col = change_pix(p1->z, p2->z, i, d[1]) : e->col;
		mlx_pixel_put(e->mlx, e->win, p1->x, p1->y, e->col);
	}
}

void	link_points(t_coor *p1, t_coor *p2, t_env *e)
{
	int		d[2];

	d[0] = ft_abs(p2->x - p1->x);
	d[1] = ft_abs(p2->y - p1->y);
	if (d[0] > d[1])
		put_pix1(p1, p2, e);
	else
		put_pix2(p1, p2, e);
}
