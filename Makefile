OUTPUTFILE 	= cbadapple
INSTALL_DEST 	= /usr/local/bin
SRCC            = main
SRC             = $(addsuffix .c, $(addprefix src/, $(SRCC)))
OBJ             = $(SRC:.c=.o)
CC           	= gcc
CFLAGS          = -W -Wall -Wextra -Werror -g3 -O2 -std=c99
CPPFLAGS        = -Iinclude/

.PHONY: all clean re uninstall install

all:	$(OBJ)
	$(CC) $(OBJ) -o $(OUTPUTFILE)

clean:
	$(RM) $(OBJ)

fclean:         clean
	$(RM) $(OUTPUTFILE)

re:	fclean all

uninstall:	fclean
	$(RM) $(INSTALL_DEST)/$(OUTPUTFILE)

install:
	install -m 557 $(OUTPUTFILE) $(INSTALL_DEST)

reinstall:	uninstall re install
