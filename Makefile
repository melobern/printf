# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbernard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:56:49 by mbernard          #+#    #+#              #
#    Updated: 2023/11/30 15:24:02 by mbernard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP 
AR = ar rcs
RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p
SRCS =	ft_printf	ft_write_str	ft_write_num	ft_write_hex	ft_len

# ---------------------------------- Repertories ----------------------------- #
SRCS_DIR = ft_printf/
OBJS_DIR = .objs/
HEADER_DIR = header/
INCLUDES = -I ${HEADER_DIR}
DEPS = ${SRCS_DIR%.c:OBJS_DIR%.d}

# ---------------------------------- Addpredix and suffix -------------------- #
HEADER = $(addprefix ${HEADER_DIR}, ft_printf.h)
OBJS = $(addprefix ${OBJS_DIR}, $(addsuffix .o, ${SRCS}))
 
# ---------------------------------- Compilation ----------------------------- #
all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${HEADER} | ${OBJS_DIR}
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

-include ${DEPS}

# ---------------------------------- Create Repertory ---------------------- #
${OBJS_DIR}:
	${MKDIR} ${OBJS_DIR}

# ---------------------------------- Clean ----------------------------------- #
clean:
	${RMDIR} ${OBJS_DIR}

fclean: clean
	${RM} ${NAME}

re:    fclean
	${MAKE} ${NAME}

# ---------------------------------- Phony ----------------------------------- #
.PHONY: all clean fclean re
