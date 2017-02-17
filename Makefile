NAME=		nanotekspice

SRC=		main.cpp \
	      src/Component.cpp \
				src/Circuit.cpp \
				src/Parser.cpp \
				src/FileParse.cpp \
				src/Input.cpp \
				src/Output.cpp \
				src/Component4081.cpp \
				src/Component4071.cpp \
				src/Component4069.cpp \
				src/Component4030.cpp \
				src/Component4011.cpp \
				src/Component4001.cpp \
				src/False.cpp \
				src/True.cpp \
				src/Clock.cpp \
				src/SpiceExecptions.cpp

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
