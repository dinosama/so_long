/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:51:42 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/24 13:57:33 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_get_nl(char *str)
{
	int	i;
	int	nl;

	i = 0;
	nl = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			nl++;
		i++;
	}
	return (nl);
}

int	get_size_x(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	**allocate_map(t_vars *vars, char *str, int y)
{
	char	**map;
	int		length;
	int		line;

	length = get_size_x(str);
	vars->map.xmax = length;
	line = ft_get_nl(str) + 1;
	vars->map.ymax = line;
	map = malloc(sizeof(char *) * line + 1);
	map[0] = malloc(sizeof(char) * length + 2);
	map[0][length] = '\0';
	while (y <= line)
	{
		map[y] = malloc(sizeof(char) * length + 2);
		if (y == line)
			map[y][length] = '?';
		map[y][length + 1] = '\0';
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
		return (0);
	fd = open(file, O_RDONLY);
	map = read_file(fd);
	vars->map.map = get_two_d_map(vars, map, 0, 0);
	free(map);
	close(fd);
	return (1);
}
