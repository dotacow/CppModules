CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -MMD -MP -Iincludes

SRCDIR = src
ODIR = ofiles

SRCS = main.cpp
SRC = $(addprefix $(SRCDIR)/,$(SRCS))
OBJS = $(addprefix $(ODIR)/,$(notdir $(SRC:.cpp=.o)))
DEPS = $(OBJS:.o=.d)

NAME = btc

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(ODIR)/%.o: $(SRCDIR)/%.cpp | $(ODIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(ODIR):
	mkdir -p $(ODIR)

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# for dependency files
-include $(DEPS)

.PHONY: all clean fclean re
