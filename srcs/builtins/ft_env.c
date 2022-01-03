/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:06:47 by emgarcia          #+#    #+#             */
/*   Updated: 2022/01/03 19:10:23 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_env(char **ownenv)
{
	size_t	i;

	if (!ownenv)
		return ;
	i = -1;
	while (++i < ft_splitlen(ownenv))
		printf("%s\n", ownenv[i]);
}
