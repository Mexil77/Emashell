# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 17:52:26 by emgarcia          #+#    #+#              #
#    Updated: 2022/01/08 17:20:06 by emgarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	gcc
RM			=	rm -rf

SRCS_PATH	=	./srcs
OBJS_PATH	=	./objs
INCLUDES	=	-I ./includes -I /Users/$(USER)/.brew/opt/readline/include
LDFLAGS		=	-L /Users/$(USER)/.brew/opt/readline/lib

CFLAGS		=	-Wall -Wextra -Werror
#CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

SRCS		=	main.c ft_ownenv.c											\
				parse/ft_args.c parse/ft_args2.c parse/ft_args3.c			\
				parse/ft_args4.c parse/ft_aux.c parse/ft_aux2.c				\
				parse/ft_aux3.c parse/ft_dropquotes.c parse/ft_parse.c		\
				parse/ft_printg.c parse/ft_args5.c							\
				builtins/ft_addenv.c builtins/ft_cd.c builtins/ft_expuns.c	\
				builtins/ft_remenv.c builtins/ft_builtins.c					\
				builtins/ft_echo.c builtins/ft_aux.c builtins/ft_pwd.c		\
				builtins/ft_env.c											\
				executor/ft_executor.c executor/ft_fds.c					\
				executor/ft_pipes.c executor/ft_process.c					\
				executor/ft_heredock.c executor/ft_aux.c					\
				signals/ft_signals.c
OBJS		=	$(addprefix $(OBJS_PATH)/,$(SRCS:.c=.o))
LIBFT		=	./libft/libft.a

all: ${NAME}

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir -p $(OBJS_PATH)/parse 2> /dev/null || true
	@mkdir -p $(OBJS_PATH)/builtins 2> /dev/null || true
	@mkdir -p $(OBJS_PATH)/executor 2> /dev/null || true
	@mkdir -p $(OBJS_PATH)/signals 2> /dev/null || true
	@$(CC) ${CFLAGS} $(INCLUDES) -o $@ -c $^

${NAME}: ${OBJS}
	@make -C libft
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME} -lreadline ${LDFLAGS}

clean:
	@cd libft ; make fclean
	@${RM} ${OBJS}

fclean: clean
	@cd libft ; make fclean
	@${RM} ${NAME}

re: fclean all
