/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 15:34:51 by narajaon          #+#    #+#             */
/*   Updated: 2017/05/28 15:35:53 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_iso(t_coor *p)
{
	int		iso_x;
	int		iso_y;

	iso_x = p->x - p->y;
	iso_y = (p->x + p->y) / 2;
	p->x = iso_x;
	p->y = iso_y;
}

void	sq_to_iso(t_coor *p1, t_coor *p2, t_coor *p3, t_coor *p4)
{
	to_iso(p1);
	to_iso(p2);
	to_iso(p3);
	to_iso(p4);
}

void	print_tile(t_tile *tile, t_env *e)
{
	t_coor	tmp0;
	t_coor	tmp1;
	t_coor	tmp2;
	t_coor	tmp3;
	t_coor	tmp4;

	coor_dup(&tile->p1, &tmp0);
	coor_dup(&tile->p1, &tmp1);
	coor_dup(&tile->p2, &tmp2);
	coor_dup(&tile->p3, &tmp3);
	coor_dup(&tile->p4, &tmp4);
	sq_to_iso(&tmp1, &tmp2, &tmp3, &tmp4);
	link_points(&tmp1, &tmp2, e);
	link_points(&tmp2, &tmp4, e);
	link_points(&tmp4, &tmp3, e);
	to_iso(&tmp0);
	link_points(&tmp3, &tmp0, e);
}
