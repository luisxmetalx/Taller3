#estableciendo variables a las librerias y archivos cabecera
INCLUDE=-Iinclude/
LIBS=-Llib/

#creando ejecutable
cifrador: main.o codificacion.o cifraso.so
	gcc $(LIBS) obj/*.o -Lm lib/*.so -o bin/cifrador

#creando .o de main
main.o: src/main.c
	gcc -Wall -c $(INCLUDE) src/main.c -o obj/main.o

#creando .o de codificacion
codificacion.o: src/codificacion.c
	gcc -Wall -c $(INCLUDE) src/codificacion.c -o obj/codificacion.o

#cifraso.o: src/cifraso.c
#	gcc -Wall -c $(INCLUDE) src/cifraso.c -o obj/cifraso.o

#generamos libreria dinamica
cifraso.so: src/cifraso.c
	gcc -Wall $(INCLUDE) -shared -fPIC src/cifraso.c -o lib/cifraso.so

#cifraso.a: obj/cifraso.o
#	ar rcs lib/cifraso.a obj/cifraso.o

.PHONY: clean
clean:
	rm -rf obj/* bin/* lib/*


