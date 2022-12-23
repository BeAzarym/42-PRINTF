# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 12:35:54 by cchabeau          #+#    #+#              #
#    Updated: 2022/12/23 15:55:25 by cchabeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=		ft_printf.c \
			ft_printf_utils.c

LIB_DIR	=	libft/

LIB		=	libft.a

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

CC	=	gcc

RM	=	@rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

all:	$(NAME)

$(NAME):	$(OBJS)
	@make -C $(LIB_DIR)
	@ar -rcs $(NAME) $(OBJS) $(LIB_DIR)$(LIB)

clean:
	$(RM) $(OBJS)
	@make -C $(LIB_DIR) clean

fclean:	clean
	$(RM) $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY:	all re clean fclean