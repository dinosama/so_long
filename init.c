/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasaboun <rasaboun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:59:13 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/25 16:32:44 by rasaboun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"


void    initimg(t_imgx* mm)
{
    mm->width = 0;
    mm->mlx_img = NULL;
    mm->line_len = 0;
    mm->height = 0;
    mm->endian = 0;
    mm->bpp = 0;
    mm->addr = NULL;
}

void    initpos(t_pos *pp)
{
    pp->texture = 0;
    pp->x = 0;
    pp->y = 0;
}

void    initmap(t_map *ma)
{
    initimg(&ma->coin);
    initimg(&ma->exit);
    initimg(&ma->floor);
    initimg(&ma->hero);
    initimg(&ma->img);
    initimg(&ma->wall);
    ma->map = NULL;
    ma->ymax = 0;
    ma->xmax = 0;
}

void    initvars(t_vars *va)
{
    va->height = 0;
    initimg(&va->img);
    initmap(&va->map);
    va->mlx = NULL;
    va->rgb = 0;
    va->width = 0;
    va->win = NULL;
    initpos(&va->player);
}
