/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:30:09 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/27 17:34:48 by aaapatou         ###   ########.fr       */
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
