/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 21:38:27 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/26 21:41:10 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		fill_res(char *line, t_uint nln, t_setting *set)
{
	int x;

	x = 0;
	if (check(line, 2))
		return (rt_errors(0, "resolution", nln));
	set->width = my_atoi(line, &x);
	set->heigth = my_atoi(line, &x);
	if (set->width <= 0)
		return (rt_errors(1, "window width", nln));
	if (set->heigth <= 0)
		return (rt_errors(1, "window heigth", nln));
	if (set->width > MAX_WIDTH)
		set->width = MAX_WIDTH;
	if (set->heigth > MAX_HEIGTH)
		set->heigth = MAX_HEIGTH;
	return (0);
}

int		fill_ambl(char *line, t_uint nln, t_setting *set)
{
	int x;

	x = 0;
	if (check(line, 2))
		return (rt_errors(0, "ambient light", nln));
	set->amblrat = my_atof(line, &x);
	if (set->amblrat < 0 || set->amblrat > 1)
		return (rt_errors(1, "ambient light ratio", nln));
	set->amblclr.r = set->amblrat * my_atoi(line, &x);
	set->amblclr.g = set->amblrat * my_atoi(line, &x);
	set->amblclr.b = set->amblrat * my_atoi(line, &x);
	return (check_clr(set->amblclr, "ambient light color", nln));
}