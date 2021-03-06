# Specify what shell and what compiler to use
SHELL		= /bin/bash
CC			= gcc
# Tell the compiler to use the gnu99 standard and look for #included files in the "include" directory
FLAGS		= -std=c90 -Iinclude
# Instruct the compiler to be strict with errors
CFLAGS		= -pedantic -Wall -Wextra -march=native -ggdb3
DEBUGFLAGS	= -O0 -D _DEBUG

# Name of the compiled binary
TARGET		= data_analysis
# Source files
SOURCES		= $(shell echo src/*.c)
# Common headers
OBJECTS		= $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) $(OBJECTS) -o $(TARGET)

release: $(SOURCES)
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
