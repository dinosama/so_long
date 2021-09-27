/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:51:42 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/27 17:35:19 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_size_x(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	**error_free(char **map, int y, int error)
{
	while (y >= 0)
	{
		free(map[y]);
		y--;
	}
	free(map);
	if (error == 1)
	{
		ft_putstr("Error\nMap not rectangle");
		return (NULL);
	}
	ft_putstr("Error\nMemory issue while allocating");
	return (NULL);
}

char	**allocate_map(t_vars *vars, char *str, int y)
{
	char	**map;

	vars->map.xmax = get_size_x(str);
	vars->map.ymax = ft_get_nl(str) + 1;
	map = malloc(sizeof(char *) * vars->map.ymax + 1);
	if (!map)
		return (0);
	map[0] = malloc(sizeof(char) * vars->map.xmax + 1);
	if (!map[0])
		return (error_free(map, 0, 0));
	map[0][vars->map.xmax] = '\0';
	while (y < vars->map.ymax)
	{
		if (y != vars->map.ymax - 1)
			str = str + vars->map.xmax + 1;
		if (vars->map.xmax != get_size_x(str))
			return (error_free(map, y - 1, 1));
		map[y] = malloc(sizeof(char) * vars->map.xmax + 1);
		if (!map[y])
			return (error_free(map, y, 0));
		map[y][vars->map.xmax] = '\0';
		y++;
	}
	return (map);
}

char	**get_two_d_map(t_vars *vars, char *str, int x, int y)
{
	int		i;
	char	**map;

	i = 0;
	map = allocate_map(vars, str, 1);
	if (!map)
		return (NULL);
	while (str[i] != '\0')
	{
		map[y][x] = str[i];
		if (str[i] == 'P')
		{
			vars->player.x = x;
			vars->player.y = y;
		}
		i++;
		x++;
		if (str[i] == '\n')
		{
			i++;
			y++;
			x = 0;
		}
	}
	return (map);
}

int	parse_map(t_vars *vars, char *file)
{
	int		fd;
	char	*map;

	if (!check_filename(file))
	{
		ft_putstr("Error\nbad filename (map file should be .ber type");
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error\nCannot open file/do not exist");
		return (0);
	}
	map = read_file(fd);
	if (!map)
		return (0);
	vars->map.map = get_two_d_map(vars, map, 0, 0);
	free(map);
	close(fd);
	if (vars->map.map == NULL)
		return (0);
	return (1);
}
