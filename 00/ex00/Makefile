# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 17:56:07 by jaewpark          #+#    #+#              #
#    Updated: 2022/06/13 17:57:01 by jaewpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	g++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	megaphone.cpp
OBJS	=	$(SRCS:.cpp=.o)
TARGET	=	megaphone
SUBJECT	=	00

LF			=	\e[1K\r$(NO_COLOR)
CRLF		=	\n$(LF)

all : $(TARGET)

$(TARGET) : $(OBJS)
	@printf "$(LF)CPP MODULE $(SUBJECT): $(TARGET)\n"
	@$(CC) $(OBJS) $(CFLAGS) -o $(TARGET)

%.o : %.cpp
	@$(CC) $(CFLAGS) -c -o $@ $< -I ./

clean :
	@printf "$(LF)Deleting $(TARGET)...\n"
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(TARGET)

re : fclean all