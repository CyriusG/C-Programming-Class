# Specify what shell and what compiler to use
SHELL		= /bin/bash
CC			= gcc
# Tell the compiler to use the gnu99 standard and look for #included files in the "include" directory
FLAGS		= -std=gnu99 -Iinclude
# Instruct the compiler to be strict with errors
CFLAGS		= -pedantic -Wall -Wextra -march=native -ggdb3
DEBUGFLAGS	= -O0 -D _DEBUG

# Name of the compiled binary
TARGET		= addition
# Source files
SOURCES		= $(shell echo src/*.c)
# Common headers
COMMON		= include/definitions.h include/debug.h
HEADERS		= $(shell echo include/*.h)
OBJECTS		= $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS) $(COMMON)
	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) $(OBJECTS) -o $(TARGET)

release: $(SOURCES) $(HEADERS) $(COMMON)
	$(CC) $(FLAGS) $(CFLAGS) $(SOURCES) -o $(TARGET)

profile: CFLAGS += -pg
profile: $(TARGET)

clean:
	-rm -f $(OBJECTS)
	-rm -f gmon.out

.SECONDEXPANSION:

$(foreach OBJ,$(OBJECTS),$(eval $(OBJ)_DEPS = $(shell gcc -MM $(OBJ:.o=.c) | sed s/.*://)))
%.o: %.c $$($$@_DEPS)
	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@
