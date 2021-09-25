/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasaboun <rasaboun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:51:42 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/25 17:44:13 by rasaboun         ###   ########.fr       */
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
	{
		fprintf(stderr,"%c",str[i]);
		i++;
	}
		fprintf(stderr,"\n");
	return (i);
}

void	ft_maperror(char	**map)
{
	
}

char	**allocate_map(t_vars *vars, char *str, int y)
{
	char	**map;
	int		length;
	int		line;
	int 	xinit;

	xinit = get_size_x(str);
	map = NULL;
	length = 0;
	line = 0;
	length = get_size_x(str);
	vars->map.xmax = length;
	line = ft_get_nl(str) + 1;
	vars->map.ymax = line;
	map = malloc(sizeof(char *) * line + 1);
	map[0] = malloc(sizeof(char) * length + 1);
	map[0][length] = '\0';
	while (y < line)
	{
		length = get_size_x(str);
		str = str + length + 1;
		if (length != xinit)
			return (NULL);	
		map[y] = malloc(sizeof(char) * length + 1);
		map[y][length] = '\0';
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
		return (0);
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
	if (!vars->map.map)
		return (0);
	free(map);
	close(fd);
	return (1);
}
