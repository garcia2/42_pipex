SRCS_FILES = main.c \
			 command.c \
			 dup.c \
			 errors.c \
			 pipe.c \
			 pipex.c \
			 exec.c \
			 process.c \
			 wait.c

SRCS_BONUS_FILES = main_bonus.c \
				command_bonus.c \
				dup_bonus.c \
				errors_bonus.c \
				exec_bonus.c \
				pipe_bonus.c \
				pipex_bonus.c \
				process_bonus.c \
				wait_bonus.c

SRCS = $(addprefix srcs/, $(SRCS_FILES))
SRCS_BONUS = $(addprefix srcs_bonus/, $(SRCS_BONUS_FILES))

OBJS	= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME	= pipex
NAME_BONUS = bonus

CC	= gcc

LIBFT = libft/libft.a

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -g3

.c.o:
		${CC} ${CFLAGS} -I includes/ -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${GNL_OBJS}
		make -C libft
		${CC} -o ${NAME} ${OBJS} ${GNL_OBJS} -I includes/ -L. ${LIBFT}

bonus:	${OBJS_BONUS} ${GNL_OBJS}
		make -C libft
		${CC} -o ${NAME_BONUS} ${OBJS_BONUS} ${GNL_OBJS} -I includes/ -L. ${LIBFT}

all:		${NAME} bonus

clean:
		make clean -C libft
		${RM} ${OBJS} ${GNL_OBJS} ${OBJS_BONUS}

fclean:		clean
		make fclean -C libft 
		${RM} ${NAME} ${NAME_BONUS}

re:		clean all


.PHONY:		all clean fclean re