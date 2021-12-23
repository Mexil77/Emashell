/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 00:30:48 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/23 16:23:25 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_trimchar(char **str, char c)
{
	char	*final;
	size_t	i;
	size_t	j;
	size_t	trimed;

	final = ft_calloc(sizeof(char), ft_strlen(str[0]));
	if (!str[0] || !final)
		return ;
	i = -1;
	j = 0;
	trimed = 0;
	while (str[0][++i])
	{
		if ((str[0][i] != c) || (str[0][i] == c && trimed))
			final[j++] = str[0][i];
		else if (str[0][i] == c && !trimed)
			trimed = 1;
	}
	free(str[0]);
	str[0] = final;
}
