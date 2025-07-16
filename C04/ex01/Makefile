# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -MMD -MP -Iincludes

# Directories
SRCDIR = src
INCDIR = includes
ODIR = ofiles

# Source and object files
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
SRC = $(addprefix $(SRCDIR)/,$(SRCS))
OBJS = $(addprefix $(ODIR)/,$(notdir $(SRC:.cpp=.o)))
DEPS = $(OBJS:.o=.d)

# Executable name
NAME = TheInkSpots

# Default target
all: $(NAME)

# Link object files into binary
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile source to object
$(ODIR)/%.o: $(SRCDIR)/%.cpp | $(ODIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create object directory if missing
$(ODIR):
	mkdir -p $(ODIR)

# Clean object files
clean:
	rm -rf $(ODIR)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Include header dependencies
-include $(DEPS)

.PHONY: all clean fclean re
