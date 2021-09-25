/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:38:09 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/24 14:15:20 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_map(t_vars *vars, int x, int j, int y)
{
	int	i;

	while (j < vars->map.ymax)
	{
		i = 0;
		x = 0;
		while (i < vars->map.xmax)
		{
			if (vars->map.map[j][i] == '1')
				put_tile(vars, vars->map.wall, x, y);
			if (vars->map.map[j][i] == '0')
				put_tile(vars, vars->map.floor, x, y);
			if (vars->map.map[j][i] == 'C')
				put_tile(vars, vars->map.coin, x, y);
			if (vars->map.map[j][i] == 'E')
				put_tile(vars, vars->map.exit, x, y);
			if (vars->map.map[j][i] == 'P')
				put_tile(vars, vars->map.hero, x, y);
			x = x + 32;
			i++;
		}
		j++;
		y = y + 32;
	}
}

int	render(t_vars *vars)
{
	static int		color;

	if (!color)
	{
		color = 0x00DC7878;
		vars->map.img.width = (vars->width / 6) * 4;
		vars->map.img.height = (vars->height / 6) * 4;
		vars->map.img.mlx_img = mlx_new_image(vars->mlx, vars->map.img.width, \
		vars->map.img.height);
		vars->map.img.addr = mlx_get_data_addr(vars->map.img.mlx_img, \
		&vars->map.img.bpp, &vars->map.img.line_len, &vars->map.img.endian);
		render_background_game(vars, 0x00078001);
	}
	if (vars->win == NULL)
		return (-1);
	color = get_rainbow_color(color);
	render_background(vars, color);
	render_map(vars, 0, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.mlx_img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.img.mlx_img, \
	vars->width / 6, vars->height / 6);
	return (0);
}

int	ft_exit(t_vars *vars)
{
	ft_error(vars, 2, 0);
	return (0);
}

int	parsing(t_vars *vars, char **av)
{
	if (!parse_texture(vars))
		return (ft_error(vars, 0, 0));
	if (!parse_map(vars, av[1]))
		return (ft_error(vars, 1, 0));
	if (!check_map(vars))
		return (ft_error(vars, 1, 0));
	if (vars->mlx == NULL)
		return (ft_error(vars, 1, 0));
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
		return (0);
	vars.width = 1920;
	vars.height = 1080;
	vars.rgb = encode_rgb(255, 255, 0, 0);
	vars.mlx = mlx_init();
	if (!parsing(&vars, av))
		return (0);
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, \
	"SEWERS RAFFLE");
	if (vars.win == NULL)
		return (ft_error(&vars, 1, 0));
	vars.img.mlx_img = mlx_new_image(vars.mlx, vars.width, vars.height);
	vars.img.addr = mlx_get_data_addr(vars.img.mlx_img, &vars.img.bpp, \
	&vars.img.line_len, &vars.img.endian);
	mlx_hook(vars.win, DestroyNotify, 1L << 17, &ft_exit, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, &handle_keypress, &vars);
	mlx_loop_hook(vars.mlx, &render, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
