INCLUDES := .
CC := clang -std=c11 -Wall -Werror -g
CFLAGS := -m64 -I$(INCLUDES)
#CC := gcc -std=c11 -Wall -Werror -g
#CFLAGS := -m64  -march=native -I $(INCLUDES)

testserialdate: libserialdate.a testserialdate.c
	$(CC) -static $(CFLAGS) testserialdate.c -L. -lserialdate -o testserialdate

libserialdate.a: serialdate.o
	$(AR) rcs libserialdate.a serialdate.o

.PHONY: clean

clean:
	@rm -f *.o *.a testserialdate

