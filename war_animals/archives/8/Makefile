SRC = guerrier.cpp \
	  oeuf.cpp \
	  poulet.cpp \
	  panda.cpp \
	  autruche.cpp \
	  superpoulet.cpp \
	  team.cpp \
	  main.cpp

NAME = baston

OBJS = $(SRC:.cpp=.o)

CXX = g++

RM = rm -f

$(NAME): $(OBJS)
		 $(CXX) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:
		$(RM) $(NAME)

re: fclean clean all