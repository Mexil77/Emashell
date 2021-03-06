/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:00:15 by emgarcia          #+#    #+#             */
/*   Updated: 2022/01/03 18:32:33 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_builtins(t_general *g)
{
	size_t	i;

	if (g->npipes)
		return ;
	i = -1;
	while (++i < g->argssize)
	{
		if (g->args[i].type == 3)
		{
			if (!ft_strncmp(g->args[i].content[0], "cd\0", 3))
				ft_cd(&g->ownenv, g->args[i].content[1]);
			else if (!ft_strncmp(g->args[i].content[0], "unset\0", 6)
				|| (!ft_strncmp(g->args[i].content[0], "export\0", 7)
					&& ft_splitlen(g->args[i].content) > 1))
				ft_parsebuiltin(g, g->args[i].content);
		}
	}
}
