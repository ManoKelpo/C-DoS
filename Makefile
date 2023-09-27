# Nome do programa
PROGRAM_NAME = DoS

# Nome do compiler
CC = gcc

CFLAGS = -Wall -g

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(PROGRAM_NAME).c
	# Command line, will use the variables above
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) $(PROGRAM_NAME).c


# Removes the program file. "-f" avoid error message.
#clean:
		#rm -f $(PROGRAM)
