/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:30:09 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/28 13:59:02 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putcharuni(int c)
{
	write(1, &c, 1);
}

int	key_is_ok(int key)
{
	if (key == XK_w || key == XK_Up)
		return (1);
	if (key == XK_s || key == XK_Down)
		return (1);
	if (key == XK_a || key == XK_Left)
		return (1);
	if (key == XK_d || key == XK_Right)
		return (1);
	return (0);
}

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

int	correct_map(char *map, int fd)
{
	int		i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'P' && map[i] != 'E'
			&& map[i] != 'C' && map[i] != '\n')
		{
			ft_putstr("Error\nBad map");
			free(map);
			close(fd);
			return (0);
		}
		i++;
	}
	return (1);
}
