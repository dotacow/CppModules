CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Harl.cpp

ODIR = ofiles
OBJS = $(addprefix $(ODIR)/,$(notdir $(SRC:.cpp=.o)))

NAME = HARL-2.0

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

$(ODIR)/%.o: %.cpp | $(ODIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(ODIR):
	mkdir -p $(ODIR)

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re