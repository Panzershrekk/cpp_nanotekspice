NAME=		Nanotekspice

SRC=		main.cpp \
	      src/Component.cpp \
				src/Circuit.cpp \
				src/Parser.cpp \
				src/FileParse.cpp \
				src/Input.cpp \
				src/Output.cpp \
				src/Component4081.cpp

CC=		g++

OBJ=		$(SRC:.cpp=.o)

RM=		rm -f

CXXFLAGS=		-W -Wextra -Werror -Wall -Iinclude/

COMPILE= $(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(COMPILE)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
