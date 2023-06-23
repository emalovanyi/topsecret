CFLAGS=-std=c11 -Wall -Werror -g
LDLIBS=-lm
OUTPUT=ps1

all: $(OUTPUT)


$(OUTPUT): main.o playfair.o bmp.o
	gcc $(CFLAGS) main.o bmp.o playfair.o -o $(OUTPUT)
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $(OUTPUT)


main.o: main.c
	gcc $(CFLAGS) -c main.c -o main.o
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

playfair.o: playfair.c
	gcc $(CFLAGS) -c playfair.c -o playfair.o
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

bmp.o: bmp.c
	gcc $(CFLAGS) -c bmp.c -o bmp.o
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

clean:
	rm -f *o $(OUTPUT)

push:
	astyle --mode=c --indent=spaces=4
	git commit -a
	git push
