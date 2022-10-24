# DEPS = afd.h

afdtool: main.o afd.o visualizacao.o complemento.o intersecao.o uniao.o reconhecer.o 
	gcc main.o afd.o visualizacao.o complemento.o intersecao.o uniao.o reconhecer.o -o afdtool

main.o: main.c
	gcc -c main.c

afd.o: afd.c afd.h
	gcc -c afd.c

visualizacao.o: visualizacao.c visualizacao.h
	gcc -c visualizacao.c

complemento.o: complemento.c complemento.h
	gcc -c complemento.c

intersecao.o: intersecao.c intersecao.h
	gcc -c intersecao.c

uniao.o: uniao.c uniao.h
	gcc -c uniao.c

reconhecer.o: reconhecer.c reconhecer.h
	gcc -c reconhecer.c

clean:
	rm *.o */*.dot */*.svg afdtool
