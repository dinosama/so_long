/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 02:19:50 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/24 12:22:44 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_wall(t_vars *vars)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = ft_strlen(vars->map.map[0]);
	while (j < vars->map.ymax)
	{
		i = 0;
		while (i < vars->map.xmax)
		{
			if ((j == 0 || j == vars->map.ymax - 1)
				&& vars->map.map[j][i] != '1')
				return (0);
			if (j != 0 && j != vars->map.ymax - 1
				&& (i == 0 || i == vars->map.xmax - 1)
				&& vars->map.map[j][i] != '1')
				return (0);
			i++;
		}
		if (count != i)
			return (0);
		j++;
	}
	return (1);
}

int	check_hero_exit(t_vars *vars, int j)
{
	int	i;
	int	hero;
	int	exit;

	hero = 0;
	exit = 0;
	while (j < vars->map.ymax)
	{
		i = 0;
		while (i < vars->map.xmax)
		{
			if (vars->map.map[j][i] == 'P')
				hero++;
			if (vars->map.map[j][i] == 'E')
				exit++;
			i++;
		}
		j++;
	}
	if (hero != 1)
		return (0);
	if (exit == 0)
		return (0);
	return (1);
}

int	check_map(t_vars *vars)
{
	if (vars->map.ymax > ((vars->height / 6) * 4) / 32)
	{
		ft_putstr("Error\nmap too big");
		return (0);
	}
	if (vars->map.xmax > ((vars->width / 6) * 4) / 32)
	{
		ft_putstr("Error\nmap too big");
		return (0);
	}
	if (check_coins(vars) || !check_hero_exit(vars, 0))
	{
		ft_putstr("Error\nno coins on map or multiple spawn/no exit");
		return (0);
	}
	if (!check_wall(vars))
	{
		ft_putstr("Error\nmap not closed/surrounded by walls or not rect");
		return (0);
	}
	return (1);
}
