/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:52:34 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/27 17:33:26 by aaapatou         ###   ########.fr       */
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

char	*allocate_file(char *str, char *temp, int value)
{
	if (value == 0)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
		{
			ft_putstr("Error\nMemory issue while allocating");
			return (NULL);
		}
		str[0] = '\0';
		return (str);
	}
	if (value == 1)
	{
		temp = malloc(sizeof(char) * 2);
		if (!temp)
		{
			free(str);
			ft_putstr("Error\nMemory issue while allocating");
			return (NULL);
		}
		temp[0] = '?';
		temp[1] = '\0';
		return (temp);
	}
}

char	*ft_strjoinjoin(char *str, char *temp)
{
	str = ft_strjoint(str, temp);
	if (!str)
	{
		ft_putstr("Error\nMemory issue while allocating");
		return (NULL);
	}
	return (str);
}

char	*read_file(int fd)
{
	char	*temp;
	char	*str;
	int		lire;

	str = allocate_file(str, temp, 0);
	if (!str)
		return (NULL);
	temp = allocate_file(str, temp, 1);
	if (!temp)
		return (NULL);
	lire = 1;
	while (lire != 0 && str != NULL)
	{
		lire = read(fd, temp, 1);
		if (lire == -1)
		{
			free(temp);
			free(str);
			return (NULL);
		}
		if (lire != 0)
			str = ft_strjoinjoin(str, temp);
	}
	free(temp);
	return (str);
}
