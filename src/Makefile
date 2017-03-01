NAME=		../libnanotekspice.a

SRC=    Component.cpp \
				Circuit.cpp \
				Parser.cpp \
				FileParse.cpp \
				Input.cpp \
				Output.cpp \
				Component4081.cpp \
				Component4071.cpp \
				Component4069.cpp \
				Component4030.cpp \
				Component4017.cpp \
				Component4011.cpp \
				Component4001.cpp \
				False.cpp \
				True.cpp \
				Clock.cpp \
				SpiceExecptions.cpp

CC=		g++

OBJ=		$(SRC:.cpp=.o)

RM=		rm -f

CXXFLAGS=		-W -Wextra -Werror -Wall -I../include/

COMPILE= $(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
