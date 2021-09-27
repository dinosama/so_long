/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 01:30:40 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/27 16:50:07 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	move_player_updown(char texture, t_vars *vars, int key)
{
	if (key == XK_w || key == XK_Up)
	{
		if (vars->map.map[vars->player.y - 1][vars->player.x] == '1')
			return (0);
		vars->map.map[vars->player.y][vars->player.x] = texture;
		if (texture == 'C')
			vars->map.map[vars->player.y][vars->player.x] = '0';
		texture = vars->map.map[vars->player.y - 1][vars->player.x];
		vars->map.map[vars->player.y - 1][vars->player.x] = 'P';
		vars->player.y = vars->player.y - 1;
		ft_putcharuni('^');
	}
	if (key == XK_s || key == XK_Down)
	{
		if (vars->map.map[vars->player.y + 1][vars->player.x] == '1')
			return (0);
		vars->map.map[vars->player.y][vars->player.x] = texture;
		if (texture == 'C')
			vars->map.map[vars->player.y][vars->player.x] = '0';
		texture = vars->map.map[vars->player.y + 1][vars->player.x];
		vars->map.map[vars->player.y + 1][vars->player.x] = 'P';
		vars->player.y = vars->player.y + 1;
		ft_putcharuni('v');
	}
	return (texture);
}

char	move_player_leftright(char texture, t_vars *vars, int key)
{
	if (key == XK_a || key == XK_Left)
	{
		if (vars->map.map[vars->player.y][vars->player.x - 1] == '1')
			return (0);
		vars->map.map[vars->player.y][vars->player.x] = texture;
		if (texture == 'C')
			vars->map.map[vars->player.y][vars->player.x] = '0';
		texture = vars->map.map[vars->player.y][vars->player.x - 1];
		vars->map.map[vars->player.y][vars->player.x - 1] = 'P';
		vars->player.x = vars->player.x - 1;
		ft_putcharuni('<');
	}
	if (key == XK_d || key == XK_Right)
	{
		if (vars->map.map[vars->player.y][vars->player.x + 1] == '1')
			return (0);
		vars->map.map[vars->player.y][vars->player.x] = texture;
		if (texture == 'C')
			vars->map.map[vars->player.y][vars->player.x] = '0';
		texture = vars->map.map[vars->player.y][vars->player.x + 1];
		vars->map.map[vars->player.y][vars->player.x + 1] = 'P';
		vars->player.x = vars->player.x + 1;
		ft_putcharuni('>');
	}
	return (texture);
}

int	check_coins(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	while (j < vars->map.ymax)
	{
		i = 0;
		while (i < vars->map.xmax)
		{
			if (vars->map.map[j][i] == 'C')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	show_movement(char mem, int count, char texture)
{
	int	value;

	count++;
	ft_putchar(' ');
	ft_putnbr_fd(count, 1);
	ft_putchar('\n');
	return (count);
}

int	handle_keypress(int key, t_vars *vars)
{
	static char	texture;
	static int	count;
	char		mem;

	if (texture == 0)
		texture = '0';
	mem = texture;
	if (key == XK_Escape)
		ft_error(vars, 2, 0);
	if (key == XK_w || key == XK_Up)
		texture = move_player_updown(texture, vars, key);
	if (key == XK_s || key == XK_Down)
		texture = move_player_updown(texture, vars, key);
	if (key == XK_a || key == XK_Left)
		texture = move_player_leftright(texture, vars, key);
	if (key == XK_d || key == XK_Right)
		texture = move_player_leftright(texture, vars, key);
	if (texture == 0)
		texture = mem;
	else if (key_is_ok(key))
		count = show_movement(mem, count, texture);
	if (texture == 'E' && check_coins(vars))
		ft_error(vars, 2, 0);
	return (0);
}
