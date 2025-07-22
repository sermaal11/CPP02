NAME = Now_we_are_talking
CC = g++
CFLAGS = -g3 -Wall -Wextra -Werror -std=c++98

SRC =	    src/main.cpp \
    src/Fixed.cpp \


OBJS = $(notdir $(SRC:.cpp=.o))
OBJDIR = Now_we_are_talking_objects

all: $(OBJDIR) $(NAME)

$(NAME): $(addprefix $(OBJDIR)/, $(OBJS))
	$(CC) $(CFLAGS) -o $@ $(addprefix $(OBJDIR)/, $(OBJS))

$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
