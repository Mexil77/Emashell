/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:11:48 by emgarcia          #+#    #+#             */
/*   Updated: 2022/01/12 14:18:06 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_checkquotes(t_general *g)
{
	char	*last;
	char	*tmp;
	size_t	i;

	last = ft_strdup(g->parse.comnds[g->parse.comndssize - 1]);
	while (g->dquot == -1 || g->quot == -1)
	{
		tmp = readline(">");
		i = -1;
		while (tmp[++i])
		{
			if (tmp[i] == '\'' && g->dquot > 0)
				g->quot = -g->quot;
			else if (tmp[i] == '\"' && g->quot > 0)
				g->dquot = -g->dquot;
		}
		ft_strownjoin(&last, tmp);
		free (tmp);
	}
	free (g->parse.comnds[g->parse.comndssize - 1]);
	g->parse.comnds[g->parse.comndssize - 1] = last;
}

void	ft_pcont(t_general *g, size_t type)
{
	if (type)
	{
		g->parse.comndssize++;
		g->parse.comand = 1;
	}
	else
	{
		g->parse.comndssize++;
		g->parse.comand = 0;
	}
}

size_t	ft_ignorespace(size_t i, char *str)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

size_t	ft_checkjoinsp(char *str, size_t *spaces)
{
	size_t	i;
	size_t	others;

	others = 1;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			(*spaces)++;
		else if (!ft_spchar(str[i]))
			others = 1;
		else if (ft_spchar(str[i]) && others)
			others = 0;
		else if (ft_spchar(str[i]) && !others && !ft_spchar(str[i - 1]))
		{
			printf("syntax error near unexpected token `");
			printf("%c'\n", str[i]);
			return (0);
		}
	}
	return (1);
}

char	*ft_dropspace(char *str)
{
	size_t	spaces;
	size_t	i;
	size_t	j;
	char	*strnsp;

	spaces = 0;
	if (!ft_checkjoinsp(str, &spaces))
	{
		g_piperet = 258;
		return (0);
	}
	strnsp = ft_calloc(sizeof(char), (ft_strlen(str) - spaces + 1));
	if (!strnsp)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != ' ')
			strnsp[j++] = str[i];
	return (strnsp);
}
