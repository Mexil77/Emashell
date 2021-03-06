/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emashell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:41:37 by emgarcia          #+#    #+#             */
/*   Updated: 2022/01/08 17:19:34 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMASHELL_H
# define EMASHELL_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

# define CLOSE "\001\033[0m\002"
# define BEGIN "\001\033[1;49;34m\002"

typedef struct s_arg {
	size_t	type;
	char	**content;
}			t_arg;

typedef struct s_parse
{
	char	**comnds;
	size_t	comndssize;
	size_t	comand;
}			t_parse;

typedef struct s_general {
	size_t	npipes;
	size_t	nfds;
	size_t	nexecutables;
	size_t	nsemicolons;
	size_t	ncommands;
	size_t	nredirections;
	t_arg	*args;
	int		*fds;
	int		**pipes;
	int		quot;
	int		dquot;
	char	**ownenv;
	t_parse	parse;
	size_t	argssize;
}			t_general;

int	g_piperet;

void	ft_freedouble(char **split);
size_t	ft_contsp(t_general *g, size_t i);
size_t	ft_error(size_t ncomands, size_t i, char **cmds);
void	ft_iniargs(t_general *g);
void	ft_iniarg(t_general *g, size_t *j, char *str);
t_arg	*ft_copycleanargs(t_general *g, size_t newargs);
void	ft_freecontent(t_arg *args, size_t argssize);
char	*ft_dropquotes(t_general *g, char *str);
char	*ft_dropexportquotes(t_general *g, char *str);
size_t	ft_spchar(char c);
size_t	ft_findchar(char *str, char c);
size_t	ft_findspchar(char *str);
void	ft_checkquotes(t_general *g);
void	ft_refacttypes(t_general *g);
void	ft_expvar(t_general *g);
void	ft_refactquotes(t_general *g);
void	ft_countthings(t_general *g);
void	ft_checknewenv(t_general *g, char *newenv);
void	ft_remenv(t_general *g, char *remenv);
size_t	ft_checkenvname(char *name);
char	**ft_ownenv(char **environ);
void	ft_inigeneral(t_general *general);
void	ft_parse(t_general *general, char *str);
void	ft_printgeneral(t_general *general);
void	ft_pcont(t_general *g, size_t type);
void	ft_cd(char	***env, char *path);
void	ft_parsebuiltin(t_general *g_mini, char **cmd);
char	**ft_dropkeyvalue(char *str, int quote, int dquote);
size_t	ft_ignorespace(size_t i, char *str);
char	*ft_dropspace(char *str);
size_t	ft_isspar(char *str);
void	ft_freegeneral(t_general *g);
size_t	ft_errormsg(char *str, size_t ret);
void	ft_checkquote(char c, char *kindquote);

void	ft_executor(t_general *g);
void	ft_createfds(t_general *g);
void	ft_createpipes(t_general *g);
void	ft_makeprocess(t_general *g);
void	ft_closeallfdspipes(t_general *g);
int		ft_getenvpos(char *envvar, char **env);
void	ft_builtins(t_general *g);
void	ft_heredock(t_general *g, size_t i, size_t exec);
size_t	ft_isinvalidbuiltin(char **cmd);
size_t	ft_countpipes(t_general *g, size_t *i, size_t exec);
int		ft_nheredocks(t_general *g);
void	ft_echo(char **cmd);
size_t	ft_childbuiltin(t_general *g, char **exe);
void	ft_pwd(void);
void	ft_env(char **ownenv);
size_t	ft_validatefds(t_general *g, size_t *iarg, size_t *fdpos);
char	**ft_findallcontent(t_general *g, size_t i);

void	ft_signals(void);
void	ft_sigheredock(void);

#endif