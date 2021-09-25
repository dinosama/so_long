/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:31:17 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/24 13:33:18 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	encode_rgb(__uint8_t op, __uint8_t red, __uint8_t green, __uint8_t blue)
{
	return (op << 24 | red << 16 | green << 8 | blue);
}

void	img_pix_put(t_imgx *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr;
	pixel = pixel + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	get_pixel(t_imgx img, int x, int y)
{
	return (*(int *)(img.addr + (y * img.line_len + (x * \
						(img.bpp / 8)))));
}

void	put_tile(t_vars *vars, t_imgx img, int xstart, int ystart)
{
	int	x;
	int	y;
	int	mem;

	x = 0;
	y = 0;
	mem = xstart;
	while (y < 32)
	{
		while (x < 32)
		{
			img_pix_put(&vars->map.img, xstart, ystart, get_pixel(img, x, y));
			x++;
			xstart++;
		}
		y++;
		ystart++;
		xstart = mem;
		x = 0;
	}
}
