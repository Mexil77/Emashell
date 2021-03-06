/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:08:46 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/30 12:32:13 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

size_t	ft_countkeyvalue(char *str, int quote, int dquote)
{
	size_t	i;
	size_t	last;
	size_t	size;

	if (!str)
		return (0);
	i = -1;
	size = 0;
	last = 0;
	while (str[++i])
	{
		if (str[i] == ' ' && dquote > 0 && quote > 0)
		{
			if (i - last > 0)
				size++;
			last = i;
		}
		if (str[i] == '\'' && dquote > 0)
			quote *= -1;
		if (str[i] == '\"' && quote > 0)
			dquote *= -1;
	}
	if (str[i - 1] != ' ')
		size++;
	return (size);
}

void	ft_changequote(int *quote, int *dquote, char c)
{
	if (c == '\'' && *dquote > 0)
		*quote *= -1;
	if (c == '\"' && *quote > 0)
		*dquote *= -1;
}

char	**ft_dropkeyvalue(char *str, int quote, int dquote)
{
	size_t	i;
	size_t	j;
	size_t	last;
	char	**cmd;

	cmd = ft_calloc(sizeof(char *), (ft_countkeyvalue(str, 1, 1) + 1));
	if (!cmd)
		return (NULL);
	i = -1;
	j = 0;
	last = 0;
	while (str[++i])
	{
		if (str[i] == ' ' && dquote > 0 && quote > 0)
		{
			if (i - last > 0)
				cmd[j++] = ft_substr(str, last, i - last);
			last = i + 1;
		}
		ft_changequote(&quote, &dquote, str[i]);
	}
	if (str[i - 1] != ' ')
		cmd[j++] = ft_substr(str, last, i - last);
	return (cmd);
}

char	**ft_splitkeyvalue(t_general *g, char *str)
{
	size_t	i;
	char	**cmd;
	char	*aux;

	if (!str)
		return (NULL);
	cmd = ft_dropkeyvalue(str, 1, 1);
	i = -1;
	while (cmd[++i])
	{
		if (ft_findchar(cmd[i], '\'') || ft_findchar(cmd[i], '\"'))
		{
			aux = ft_dropquotes(g, cmd[i]);
			free (cmd[i]);
			cmd[i] = ft_strdup(aux);
			free (aux);
		}
	}
	return (cmd);
}

void	ft_parsebuiltin(t_general *g, char **cmd)
{
	size_t	i;

	i = 0;
	if (!ft_strncmp(cmd[0], "export\0", 7) && ft_splitlen(cmd) == 1)
		ft_printsortenv(g->ownenv);
	else if (!ft_strncmp(cmd[0], "export\0", 7))
		while (cmd[++i])
			ft_checknewenv(g, cmd[i]);
	else if (!ft_strncmp(cmd[0], "unset\0", 7))
		while (cmd[++i])
			ft_remenv(g, cmd[i]);
}
