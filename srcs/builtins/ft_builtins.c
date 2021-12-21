/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:00:15 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/21 16:38:19 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_builtins(t_general *g)
{
	size_t	i;
	//char	**cmd;

	i = -1;
	while (++i < g->argssize)
	{
		if (g->args[i].type == 3)
		{
			//cmd = ft_split(g->args[i].content, ' ');
			if (!ft_strncmp(g->args[i].content[0], "cd", 2))
				ft_cd(&g->ownenv, g->args[i].content[1]);
			else if (!ft_strncmp(g->args[i].content[0], "unset", 4)
				|| !ft_strncmp(g->args[i].content[0], "export", 6))
				ft_parsebuiltin(g, g->args[i].content);
		}
	}
}
