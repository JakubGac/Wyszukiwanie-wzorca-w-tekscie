CC = gcc -g -Wall -pedantic -ansi -Qunused-arguments
OBJC = main.o przygotuj_dane.o wczytaj_dane.o kmp.o bm.o kr.o na.o uruchom_wszystkie.o


all: $(OBJC)
	@echo "Łączę moduły *.o"
	@$(CC) $(OBJC) -o program
	@echo "Czyszczę pliki *.o"
	@rm *.o

main.o: main.c
	@echo "Kompiluję moduł $@"
	@$(CC) main.c -c -o main.o

przygotuj_dane.o : wczytywanie-danych/przygotuj_dane.c
	@echo "Kompiluję moduł $@"
	@$(CC) wczytywanie-danych/przygotuj_dane.c -c -o przygotuj_dane.o

wczytaj_dane.o : wczytywanie-danych/wczytaj_dane.c
	@echo "Kompiluję moduł $@"
	@$(CC) wczytywanie-danych/wczytaj_dane.c -c -o wczytaj_dane.o

kmp.o : knuth-morris-pratt/kmp.c
	@echo "Kompiluję moduł $@"
	@$(CC) knuth-morris-pratt/kmp.c -c -o kmp.o

bm.o : boyera-moorea/bm.c
	@echo "Kompiluję moduł $@"
	@$(CC) boyera-moorea/bm.c -c -o bm.o

kr.o : karpa-rabina/kr.c
	@echo "Kompiluję moduł $@"
	@$(CC) karpa-rabina/kr.c -c -o kr.o

na.o : naiwny/na.c
	@echo "Kompiluję moduł $@"
	@$(CC) naiwny/na.c -c -o na.o

uruchom_wszystkie.o : wszystkie/uruchom_wszystkie.c
	@echo "Kompiluję moduł $@"
	@$(CC) wszystkie/uruchom_wszystkie.c -c -o uruchom_wszystkie.o

.PHONY: clean

clean:
	@echo "Czyszczę pliki *.o"
	@rm *.o	

test1:
	@echo "Uruchamiam test pierwszy"
	@./program dane.txt wzorzec.txt

test2:
	@echo "Uruchamiam test drugi"
	@./program dane2.txt wzorzec2.txt
