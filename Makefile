
program: memoryctrl.o util.o file_manager.o main.o
	gcc memoryctrl.o util.o file_manager.o main.o -o program

memoryctrl.o: memoryctrl.c
	gcc -c memoryctrl.c
util.o: util.c
	gcc -c util.c
file_manager.o: file_manager.c cars.csv
	gcc -c file_manager.c 
main.o: main.c
	gcc -c main.c
clea: 
	rm *.o program





