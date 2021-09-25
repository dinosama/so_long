/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:59:13 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/23 16:58:32 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_rainbow_color(int color)
{
	int	red;
	int	green;
	int	blue;
	int	op;

	op = (color >> 24) & 255;
	red = (color >> 16) & 255;
	green = (color >> 8) & 255;
	blue = color & 255;
	if (green == 220 && red > 120 && blue == 120)
		red--;
	if (blue == 220 && green > 120 && red == 120)
		green--;
	if (red == 220 && blue > 120 && green == 120)
		blue--;
	if (red == 220 && green < 220 && blue == 120)
		green++;
	else if (green == 220 && blue < 220 && red == 120)
		blue++;
	else if (blue == 220 && red < 220 && green == 120)
		red++;
	return (op << 24 | red << 16 | green << 8 | blue);
}

void	render_background(t_vars *vars, int color)
{
	int		i;
	int		j;
	int		fluid;

	i = vars->width;
	fluid = 0;
	while (i >= 0)
	{
		j = vars->height;
		while (j >= 0)
		{
			img_pix_put(&vars->img, i, j, color);
			if (fluid == 100)
			{
				color = get_rainbow_color(color);
				fluid = 0;
			}
			j--;
		}
		fluid++;
		i--;
	}
}

void	render_background_game(t_vars *vars, int color)
{
	int		i;
	int		j;

	i = vars->map.img.width;
	while (i >= 0)
	{
		j = vars->map.img.height;
		while (j >= 0)
		{
			img_pix_put(&vars->map.img, i, j, color);
			j--;
		}
		i--;
	}
}
