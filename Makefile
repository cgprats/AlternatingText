CC=clang
SOURCEFILES=main.c
OUTPUTBINARY=-o AlternatingText
OPTS=-Wall -lncurses
AlternatingText:
	$(CC) $(SOURCEFILES) $(OUTPUTBINARY) $(OPTS)
