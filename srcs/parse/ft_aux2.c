/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:11:35 by emgarcia          #+#    #+#             */
/*   Updated: 2022/01/03 18:41:54 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

t_arg	*ft_copycleanargs(t_general *g, size_t newargs)
{
	t_arg	*tmp;
	size_t	i;

	i = -1;
	tmp = malloc(sizeof(t_arg) * (g->argssize + 1));
	if (!tmp)
		exit(0);
	tmp[g->argssize].type = 0;
	tmp[g->argssize].content = NULL;
	i = -1;
	while (++i < g->argssize)
	{
		tmp[i].type = g->args[i].type;
		tmp[i].content = ft_splitdup(g->args[i].content);
		ft_freedouble(g->args[i].content);
	}
	free(g->args);
	g->argssize = newargs;
	return (tmp);
}

void	ft_freecontent(t_arg *args, size_t argssize)
{
	size_t	i;

	i = -1;
	while (++i < argssize)
		ft_freedouble(args[i].content);
	free(args);
}

void	ft_freedouble(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	ft_freeall(t_general *g)
{
	ft_freedouble(g->parse.comnds);
	ft_freecontent(g->args, g->argssize);
}

void	ft_countthings(t_general *g)
{
	size_t	i;

	i = -1;
	while (++i < g->argssize)
	{
		if (g->args[i].type == 1 || g->args[i].type == 2
			|| g->args[i].type == 7 || g->args[i].type == 8)
			g->nredirections++;
		else if (g->args[i].type == 3)
			g->nexecutables++;
		else if (g->args[i].type == 5)
			g->npipes++;
		else if (g->args[i].type == 6)
			g->nsemicolons++;
		else if (g->args[i].type == 4)
			g->nfds++;
	}
}
