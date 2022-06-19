# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 08:25:08 by jaewpark          #+#    #+#              #
#    Updated: 2022/06/20 08:26:11 by jaewpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp
OBJS	=	$(SRCS:.cpp=.o)
TARGET	=	StringPointer
SUBJECT	=	01

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