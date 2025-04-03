# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Executable name
TARGET = matrix_program

# Source files
SRCS = main.cpp matrix.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule: Build the program
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compiling C++ files into object files
%.o: %.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)