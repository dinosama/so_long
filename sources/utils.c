/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:52:34 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/24 13:37:16 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strjoint(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[k] != '\0')
	{
		str[i] = s1[k];
		k++;
		i++;
	}
	k = 0;
	while (s2[k] != '\0')
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*read_file(int fd)
{
	char	*temp;
	char	*str;
	int		lire;

	str = malloc(sizeof(char) * 1);
	temp = malloc(sizeof(char) * 2);
	str[0] = '\0';
	temp[0] = '?';
	temp[1] = '\0';
	lire = 1;
	while (lire != 0)
	{
		lire = read(fd, temp, 1);
		if (lire == -1)
		{
			free(temp);
			free(str);
			return (NULL);
		}
		if (lire != 0)
			str = ft_strjoint(str, temp);
	}
	free(temp);
	return (str);
}

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
