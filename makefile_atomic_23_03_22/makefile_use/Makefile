$(CC) = gcc

calc: main_mkf.o calc_mean.o calc_sub.o
	$(CC) main_mkf.o calc_mean.o calc_sub.o -o calc

main.o: main_mkf.c calc_mean.h
	$(CC) -c main_mkf.c

calc_mean.o: calc_mean.c calc_mean.h
	$(CC) -c calc_mean.c

calc_sub.o: calc_sub.c calc_mean.h
	$(CC) -c calc_sub.c

clean:
	rm -f *.o 

