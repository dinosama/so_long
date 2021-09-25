/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:52:28 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/24 14:15:45 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_filename(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'r')
		return (0);
	if (str[i - 2] != 'e')
		return (0);
	if (str[i - 3] != 'b')
		return (0);
	if (str[i - 4] != '.')
		return (0);
	return (1);
}

void	ft_error_two(t_vars *vars, int error, int y)
{
	while (y <= vars->map.ymax)
	{
		free(vars->map.map[y]);
		y++;
	}
	free(vars->map.map);
	if (error == 1)
	{
		mlx_destroy_image(vars->mlx, vars->map.coin.mlx_img);
		mlx_destroy_image(vars->mlx, vars->map.hero.mlx_img);
		mlx_destroy_image(vars->mlx, vars->map.floor.mlx_img);
		mlx_destroy_image(vars->mlx, vars->map.wall.mlx_img);
		mlx_destroy_image(vars->mlx, vars->map.exit.mlx_img);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	if (error == 3)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit(0);
	}
}

int	ft_error(t_vars *vars, int error, int y)
{
	if (error == 0)
	{
		free(vars->mlx);
		exit(0);
	}
	if (error == 2)
	{
		mlx_destroy_image(vars->mlx, vars->img.mlx_img);
		mlx_destroy_image(vars->mlx, vars->map.img.mlx_img);
	}
	ft_error_two(vars, error, 0);
	mlx_destroy_image(vars->mlx, vars->map.coin.mlx_img);
	mlx_destroy_image(vars->mlx, vars->map.hero.mlx_img);
	mlx_destroy_image(vars->mlx, vars->map.floor.mlx_img);
	mlx_destroy_image(vars->mlx, vars->map.wall.mlx_img);
	mlx_destroy_image(vars->mlx, vars->map.exit.mlx_img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}
