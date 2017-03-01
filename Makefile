CXX		=	g++

NAME		=	nanotekspice

RM		=	rm -f

CXXFLAGS	+=	-std=c++11
CXXFLAGS	+=	-Werror -Wall -Wextra
CXXFLAGS	+=	-Iinclude/

LDFLAGS		+=	-L./ -lnanotekspice

SRCS		=	main.cpp

OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		make -C src/
		$(CXX) $(OBJS) $(CXXFLAGS) $(LDFLAGS) -o $(NAME)

clean:
		make clean -C src/
		$(RM) $(OBJS)

fclean:		clean
		make fclean -C src/
		$(RM) $(NAME)

re:		fclean all
