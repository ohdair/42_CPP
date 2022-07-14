# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 12:45:49 by jaewpark          #+#    #+#              #
#    Updated: 2022/07/14 11:03:53 by jaewpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS		=	main.cpp \
				ClapTrap.cpp
OBJS		=	$(SRCS:.cpp=.o)
TARGET		=	ClapTrap
SUBJECT		=	02

LF			=	\e[1K\r$(NO_COLOR)
CRLF		=	\n$(LF)

all : $(TARGET)

$(TARGET) : $(OBJS)
	@printf "$(LF)CPP MODULE $(SUBJECT): $(TARGET)\n"
	@$(CXX) $(OBJS) $(CXXFLAGS) -o $(TARGET)

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $< 

clean :
	@printf "$(LF)Deleting $(TARGET)...\n"
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(TARGET)

re : fclean all