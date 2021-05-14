OUTPUTFILE 	= cbadapple

INSTALL_DEST 	= /usr/local/bin

INSTALL_BIN 	= /usr/local/bin/cbadapple

SRCC            = main

SRC             = $(addsuffix .c, $(addprefix src/, $(SRCC)))

OBJ             = $(SRC:.c=.o)

CC           	= gcc

CFLAGS          = -W -Wall -Wextra -g3

CPPFLAGS        = -Iinclude/

.PHONY          = all, clean, re, uninstall, install

all: 		$(OBJ)
	$(CC) $(OBJ) -o $(OUTPUTFILE)

clean:
	$(RM) $(OBJ)

fclean:         clean
	$(RM) $(OUTPUTFILE)

re:             fclean all

uninstall:	fclean
	$(RM) $(INSTALL_BIN)

install:	uninstall 	re
	install -m 557 $(OUTPUTFILE) $(INSTALL_DEST)
	cp $(OUTPUTFILE) $(INSTALL_DEST)
