# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 09:35:20 by ehouot            #+#    #+#              #
#    Updated: 2023/06/13 18:24:36 by ehouot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH	=	./Libft/

GNL_PATH	= 	./Get_next_line/

SRC 		= 	./main.c \
				./parsing.c \
				./exec_cmd.c \
				
SRC_BONUS	=	./main_bonus.c \
				./parsing_bonus.c \
				./exec_cmd_bonus.c \

SRC_GNL		=	 $(addprefix $(GNL_PATH), get_next_line.c \
				get_next_line_utils.c)

OBJ 		= $(SRC:.c=.o) $(SRC_LIBFT:.c=.o)

OBJ_BONUS	= $(SRC_BONUS:.c=.o) $(SRC_LIBFT:.c=.o) $(SRC_GNL:.c=.o)

HEADER		= ./

CC 			= clang

RM 			= rm -f

CFLAGS 		= -Wall -Werror -Wextra

ifdef DEBUG
	CFLAGS += -fsanitize=address -g3
endif

NAME 		= pipex

all:		$(NAME)

.c.o:
			@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
			@${MAKE} -C ${LIBFT_PATH}
			@$(CC) $(CFLAGS) $(OBJ) -I $(HEADER) -o $(NAME) ${LIBFT_PATH}libft.a -o $@

bonus:		$(OBJ) $(OBJ_BONUS)
			@${MAKE} -C ${LIBFT_PATH}
			@$(CC) $(CFLAGS) $(OBJ) $(OBJ_BONUS) -I $(HEADER) -o $(NAME) ${LIBFT_PATH}libft.a -o

debug:
	${MAKE} DEBUG=1

clean:
			@$(RM) $(OBJ) $(OBJ_BONUS)
			@${MAKE} clean -C ${LIBFT_PATH}

fclean: 	clean
			@$(RM) $(NAME)
			@${MAKE} fclean -C ${LIBFT_PATH}

re:			fclean $(NAME)

.PHONY: 	all clean fclean re bonus