#include <emashell.h>

void	ft_heredock(t_general *g, size_t i)
{
	char	*line;
	char	*eof;

	eof = g->args[i + 1].content[0];
	line = NULL;
	while (ft_strncmp(line, eof, ft_strlen(eof)) || ft_strlen(eof) != ft_strlen(line))
	{
		free(line);
		line = readline(BEGIN"> "CLOSE);
		add_history (line);
		printf("%s\n", line);
	}
	free(line);
	exit(0);
}