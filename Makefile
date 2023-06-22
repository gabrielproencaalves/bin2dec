CC = c89
CFLAGS = -Werror -Wall
.RECIPEPREFIX += 

install: bin2dec.c
  $(CC) $(CFLAGS) bin2dec.c -o bin2dec
