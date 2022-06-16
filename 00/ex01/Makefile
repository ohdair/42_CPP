# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 08:00:03 by jaewpark          #+#    #+#              #
#    Updated: 2022/06/16 11:13:04 by jaewpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	phonebook.cpp \
			contact.cpp \
			main.cpp
OBJS	=	$(SRCS:.cpp=.o)
TARGET	=	phonebook
SUBJECT	=	00

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