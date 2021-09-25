/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 01:27:33 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/24 13:30:59 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_imgx	load_image(void *mlx, char *path)
{
	t_imgx	data;

	data.mlx_img = mlx_xpm_file_to_image(mlx, path, &(data.width), \
	&(data.height));
	if (!data.mlx_img)
		return (data);
	data.addr = mlx_get_data_addr(data.mlx_img, &(data.bpp), \
	&(data.line_len), &(data.endian));
	if (data.height != 32 || data.width != 32)
	{
		ft_putstr("Error\nwrong texture dimension for ");
		ft_putstr(path);
		mlx_destroy_image(mlx, data.mlx_img);
	}
	return (data);
}

int	parse_texture(t_vars *vars)
{
	vars->map.hero = load_image(vars->mlx, "images/hero.xpm");
	if (!vars->map.hero.mlx_img)
		return (0);
	vars->map.exit = load_image(vars->mlx, "images/exit.xpm");
	if (!vars->map.exit.mlx_img)
		return (0);
	vars->map.coin = load_image(vars->mlx, "images/coin.xpm");
	if (!vars->map.coin.mlx_img)
		return (0);
	vars->map.floor = load_image(vars->mlx, "images/floor.xpm");
	if (!vars->map.floor.mlx_img)
		return (0);
	vars->map.wall = load_image(vars->mlx, "images/wall.xpm");
	if (!vars->map.wall.mlx_img)
		return (0);
	return (1);
}
