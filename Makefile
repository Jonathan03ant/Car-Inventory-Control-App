EXECS = program 
OBJS = memoryctrl.o util.o file_manager.o main.o
CFLAGS = -Wall -Wextra -g

all: $(EXECS)

program: $(OBJS)
	gcc $(OBJS) -o program 
memoryctrl.o: memoryctrl.c 
	gcc -c memoryctrl.c $(CFLAGS)
util.o: util.c
	gcc -c util.c $(CFLAGS)
file_manager.o: file_manager.c cars.csv
	gcc -c file_manager.c $(CFLAGS)
main.o: main.c
	gcc -c main.c $(CFLAGS)
clean:
	rm -f $(OBJS) $(EXECS)













