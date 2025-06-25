CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Contact.cpp PhoneBook.cpp

ODIR = ofiles
OBJS = $(addprefix $(ODIR)/,$(notdir $(SRCS:.cpp=.o)))

NAME = macpbook

all: $(NAME)

$(NAME): $(OBJS)
    $(CC) $(OBJS) $(CPPFLAGS) -o $(NAME)

$(ODIR)/%.o: %.cpp | $(ODIR)
    $(CC) $(CPPFLAGS) -c $< -o $@

$(ODIR):
    mkdir -p $(ODIR)

clean:
    rm -rf $(ODIR)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re