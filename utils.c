/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 15:26:18 by narajaon          #+#    #+#             */
/*   Updated: 2017/05/29 12:12:22 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error_msg(int error)
{
	if (error == 1)
	{
		ft_putstr_fd("Usage : ./fdf <map> [width] [height]\n", 2);
		return (1);
	}
	if (error == 2)
	{
		ft_putstr_fd("Couldn't allocate memory :(\n", 2);
		return (2);
	}
	if (error == 3)
	{
		ft_putstr_fd("Error occured while reading file :(\n", 2);
		return (3);
	}
	ft_putstr_fd("Window closed, cya\n", 2);
	return (0);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		key_fun(int keycode, void *param)
{
	if (keycode == 53)
		exit(error_msg(0));
	return (0);
}

int		tab_len(char **tab)
{
	int		len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void	coor_dup(t_coor *p, t_coor *tmp)
{
	tmp->x = p->x - (p->z * 4);
	tmp->y = p->y - (p->z * 4);
	tmp->z = p->z;
	tmp->col = p->col;
}
