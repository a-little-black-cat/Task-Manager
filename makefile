# Makefile for Task Manager

CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = task_manager
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

# Default target to build the project
all: $(TARGET)

# Compile the source file to object file
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

# Link the object file to create the final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Clean up object and executable files
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Rebuild the project
rebuild: clean all

