# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 17:52:26 by emgarcia          #+#    #+#              #
#    Updated: 2021/12/18 22:16:15 by emgarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	gcc
RM			=	rm -rf

SRCS_PATH	=	./srcs
OBJS_PATH	=	./objs
INCLUDES	=	-I ./includes

#CFLAGS		=	-Wall -Wextra -Werror -lreadline
CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address -lreadline

SRCS		=	main.c ft_ownenv.c											\
				parse/ft_args.c parse/ft_args2.c parse/ft_args3.c			\
				parse/ft_args4.c parse/ft_aux.c parse/ft_aux2.c				\
				parse/ft_aux3.c parse/ft_dropquotes.c parse/ft_parse.c		\
				builtins/ft_addenv.c builtins/ft_cd.c builtins/ft_expuns.c	\
				builtins/ft_remenv.c	\
				executor/ft_executor.c executor/ft_fds.c
OBJS		=	$(addprefix $(OBJS_PATH)/,$(SRCS:.c=.o))
LIBFT		=	./libft/libft.a

all: ${NAME}

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir -p $(OBJS_PATH)/parse 2> /dev/null || true
	@mkdir -p $(OBJS_PATH)/builtins 2> /dev/null || true
	@mkdir -p $(OBJS_PATH)/executor 2> /dev/null || true
	@$(CC) $(INCLUDES) -o $@ -c $^

${NAME}: ${OBJS}
	@make -C libft
	${CC} ${CFLAGS} ${LIBFT} ${OBJS} -o ${NAME}

clean:
	@cd libft ; make fclean
	@${RM} ${OBJS}

fclean: clean
	@cd libft ; make fclean
	@${RM} ${NAME}

re: fclean all
