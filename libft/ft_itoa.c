/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 21:42:08 by aaapatou          #+#    #+#             */
/*   Updated: 2021/07/10 15:21:57 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countnumbers(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = countnumbers(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size] = '\0';
	if (n < 0)
		str[0] = '-';
	while (size != 0)
	{
		if (str[size - 1] != '-')
		{
			if (n < 0)
				str[size - 1] = -(n % 10) + 48;
			else
				str[size - 1] = (n % 10) + 48;
		}
		n = n / 10;
		size--;
	}
	return (str);
}
