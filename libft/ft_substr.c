/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 00:25:26 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/15 03:00:32 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		n;
	char	*str;

	if (!s)
		return (0);
	n = (int)start;
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len && s[i] && (size_t)n < ft_strlen(s))
	{
		str[i] = s[n];
		n++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
