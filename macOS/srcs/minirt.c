/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 00:07:59 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/26 22:01:19 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		val_init(t_objects *obj, t_setting *set)
{
	obj->nc = 0;
	obj->nl = 0;
	obj->ns = 0;
	obj->ntmp = 0;
	set->save = 0;
	set->width = -1;
	set->heigth = -1;
	set->amblrat = -1;
}

static void		start(int ac, char **av, t_objects *obj, t_setting *set)
{
	val_init(obj, set);
	start_errors(ac, av);
	if (ac > 2 && (ft_strcmp(av[2], "-save") == 0))
		set->save = 1;
}

static void		initiate_window(t_setting *set)
{
	if (!(set->d.mlx = mlx_init()))
		mlx_error(set->d);
	if (!(set->d.win = mlx_new_window(set->d.mlx, set->width,
			set->heigth, "miniRT")))
		mlx_error(set->d);
	if (!(set->d.img = mlx_new_image(set->d.mlx, set->width, set->heigth)))
		mlx_error(set->d);
	if (!(set->d.clr = mlx_get_data_addr(set->d.img, &(set->d.bpp),
			&(set->d.sz_line), &(set->d.endian))))
		mlx_error(set->d);
}

int				main(int ac, char **av)
{
	t_ray		ray;
	t_setting	set;
	t_objects	obj;

	start(ac, av, &obj, &set);
	parse(av, &set, &obj);
	initiate_window(&set);
	obj.ctmp = obj.chead;
	render(&ray, set, obj);
	return (0);
}
