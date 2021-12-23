/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:08:59 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/23 16:23:48 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

size_t	ft_varenvexist(t_general *g, char *varenv)
{
	size_t	i;

	i = -1;
	while (g->ownenv[++i])
		if (!ft_strncmp(varenv, g->ownenv[i], ft_strlen(varenv))
			&& g->ownenv[i][ft_strlen(varenv)] == '=')
			return (1);
	return (0);
}

void	ft_remenv(t_general *g, char *remenv)
{
	char	**newenv;
	size_t	i;
	size_t	j;

	if (!ft_checkenvname(remenv) || !ft_varenvexist(g, remenv))
		return ;
	newenv = ft_calloc(sizeof(char *), ft_splitlen(g->ownenv));
	if (!newenv)
		return ;
	i = -1;
	j = 0;
	while (g->ownenv[++i])
		if (ft_strncmp(remenv, g->ownenv[i], ft_strlen(remenv))
			|| g->ownenv[i][ft_strlen(remenv)] != '=')
			newenv[j++] = ft_strdup(g->ownenv[i]);
	ft_freedouble(g->ownenv);
	g->ownenv = newenv;
}
