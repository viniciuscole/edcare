all: cuidador.o lista.o idoso.o edcare.o listaCuidadores.o
	gcc -o edcare.out cuidador.o lista.o idoso.o edcare.o listaCuidadores.o main.c -lm

lista.o: lista.h
	gcc -c lista.c

idoso.o: idoso.h
	gcc -c idoso.c

cuidador.o: cuidador.h
	gcc -c cuidador.c

edcare.o: edcare.h
	gcc -c edcare.c

listaCuidadores.o: listaCuidadores.h
	gcc -c listaCuidadores.c

val: edcare.out
	valgrind ./edcare.out 4

clean: 
	rm -f *.o *-saida.txt edcare.out
