/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:45:14 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/27 17:49:10 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_heredock(t_general *g, size_t i)
{
	char	*line;
	char	*eof;
	int		tmp;

	tmp = open("tmp", O_CREAT | O_RDWR, 0644);
	eof = g->args[i + 1].content[0];
	line = NULL;
	while (ft_strncmp(line, eof, ft_strlen(eof))
		|| ft_strlen(eof) != ft_strlen(line))
	{
		write(tmp, line, ft_strlen(line));
		if (line)
			write(tmp, "\n", 1);
		free(line);
		line = readline(BEGIN"> "CLOSE);
	}
	close(tmp);
	tmp = open("tmp", O_CREAT | O_RDWR, 0644);
	dup2(tmp, STDIN_FILENO);
	close(tmp);
	free(line);
	unlink("tmp");
	if (i + 2 >= g->argssize || g->args[i + 2].type == 5)
		exit(0);
}
