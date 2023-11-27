# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbernard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:56:49 by mbernard          #+#    #+#              #
#    Updated: 2023/11/27 20:26:10 by mbernard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I $(HEADERS_DIR)
DEP_FLAGS = -MMD -MP -MF
AR = ar rcs
RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p
PRINTF_SRCS =	ft_printf
LIBFT_SRCS =	ft_isalpha	ft_isdigit	ft_isalnum	ft_isascii	\
		ft_isprint	ft_strlen		ft_memset		ft_bzero	\
		ft_memcpy		ft_memmove	ft_strlcpy	ft_strlcat	\
		ft_toupper	ft_tolower	ft_strchr		ft_strrchr	\
		ft_strncmp	ft_strnstr	ft_atoi		ft_calloc	\
		ft_strdup		ft_memchr		ft_memcmp		ft_substr	\
		ft_strjoin	ft_strtrim	ft_split		ft_itoa	\
		ft_putchar_fd	ft_putstr_fd	ft_putendl_fd	ft_putnbr_fd	\
		ft_strmapi	ft_striteri
LIBFT_DIR = Libft/
PRINTF_DIR = ft_printf/
HEADERS_DIR = headers/
OBJS_DIR = .objs/

# -----------------------------------Repertories gestion---------------------- #

SRCS_FILES = $(PRINTF_SRCS) $(LIBFT_DIR)
PRINTF_HEADER = $(addprefix $(HEADERS_DIR), ft_printf.h)
LIBFT_HEADER = $(addprefix $(HEADERS_DIR), libft.h)
LIBFT_OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(LIBFT_SRCS)))
PRINTF_OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(PRINTF_SRCS)))
DEPS = $(addprefix $(OBJS_DIR), $($(OBJS_DIR)%.o=.d))

# -----------------------------------Compile---------------------------------- #

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(PRINTF_OBJS) 
	$(AR) $(NAME) $(LIBFT_OBJS) $(PRINTF_OBJS)

$(OBJS_DIR)%.o: $(LIBFT_DIR)%.c $(LIBFT_HEADER) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
	#$(CC) $(CFLAGS) $(DEP_FLAGS) $< -c $@

$(OBJS_DIR)%.o: $(PRINTF_DIR)%.c $(LIBFT_HEADER) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
	#$(CC) $(CFLAGS) $(DEP_FLAGS) $< -c $@

# -----------------------------------Dependances------------------------------ #
	#$(CC) $(CFLAGS) $(DEP_FLAGS) -MF $@ -I $(HEADERS_DIR) -c $<
$(OBJS_DIR)%.d: $(PRINTF_DIR)%.c $(PRINTF_HEADER) | $(DEPS_DIR)
	#$(CC) $(CFLAGS) $(DEP_FLAGS) $(DEPS) -c $< -o $@
	$(CC) $(CFLAGS) -MMD -MP -MF $(OBJS_DIR)/$*.d -c $< -o $@

$(OBJS_DIR)%.d: $(LIBFT_DIR)%.c $(LIBFT_HEADER) | $(DEPS_DIR)
	$(CC) $(CFLAGS) $(DEP_FLAGS) $(DEPS) -c $< -o $@
-include $($(OBJS_DIR)%.o=.d)

# -----------------------------------Create Repertories----------------------- #

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

# -----------------------------------Clean------------------------------------ #
clean:
	$(RMDIR) $(OBJS_DIR) $(DEPS_DIR)
fclean: clean
	$(RM) $(NAME)
re:    fclean
	$(NAME)

# -----------------------------------Phony------------------------------------ #
.PHONY: all clean fclean re
