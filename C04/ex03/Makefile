# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -MMD -MP -Iincludes

# Directories
SRCDIR = src
ODIR = ofiles

# Source and object files
SRCS = AMateria.cpp  Character.cpp  Cure.cpp  Ice.cpp  main.cpp  MateriaSource.cpp
SRC = $(addprefix $(SRCDIR)/,$(SRCS))
OBJS = $(addprefix $(ODIR)/,$(notdir $(SRC:.cpp=.o)))
DEPS = $(OBJS:.o=.d)

# Executable name
NAME = myfirstRPG

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

# Include header dependencies
-include $(DEPS)

.PHONY: all clean fclean re
