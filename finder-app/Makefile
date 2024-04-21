# Define the default target
.PHONY: all
all: writer

# Define the cross-compiler prefix
CROSS_COMPILE ?=

# Define the compiler and flags
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra -std=c99

# Define the sources and objects
SRCS = writer.c
OBJS = $(SRCS:.c=.o)

# Build the writer application
writer: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Clean up targets
.PHONY: clean
clean:
	rm -f writer $(OBJS)
