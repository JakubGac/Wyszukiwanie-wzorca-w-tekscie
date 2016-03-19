#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "wczytywanie-danych/przygotuj_dane.h"

int main(int argc, char** argv) {

	int wybor = 0;
	int koniec = 1;

	if(argc != 3){
		system("clear");
		printf("Jako argumenty wywołania podaj nazwę pliku zawierającego tekst\n");
		printf("do przeszukania oraz nazwę pliku zawierającego wzorzec\n\n");
		return EXIT_FAILURE;
	}	

	system("clear");
	
	while(koniec) {
		printf("\nWybierz którym algorytmem chcesz wyszukać wzorzec w tekście: \n");
		printf("1 - algorytm Knutha-Morrisa-Pratta\n");
		printf("2 - algorytm Boyera i Moore'a\n");
		printf("3 - algorytm Karpa-Rabina\n");
		printf("4 - algorytm naiwny\n");
		printf("5 - uruchom wszystkie algorytmy i porównaj czas działania.\n");
		printf("6 - zakończ działanie programu.\n");	
		
   		printf ("Podaj liczbę: ");
   		scanf ("%d", &wybor);
		switch(wybor){
			case 1:
				printf("Wybrales algorytm Knutha-Morrisa-Pratta.\n");
				sleep(2);
				przygotuj_dane(argv[1],argv[2],wybor);
				break ;
			case 2:
				printf("Wybrales algorytm Boyera i Moore'a.\n");
                                sleep(2);
                                przygotuj_dane(argv[1],argv[2],wybor);
				break;
			case 3:
				printf("Wybrales algorytm Karpa-Rabina.\n");
                                sleep(2);
                                przygotuj_dane(argv[1],argv[2],wybor);
				break;
			case 4:
				printf("Wybrałeś algorytm naiwny.\n");
                                sleep(2);
                                przygotuj_dane(argv[1],argv[2],wybor);
				break;
			case 5:
				printf("Uruchamiam wszystkie algorytmy. \n");
				sleep(2);
				przygotuj_dane(argv[1],argv[2],wybor);
				break;
			case 6:
				printf("Kończe działanie\n");
				koniec = 0;
				break;
			default:
				printf("Nie wybrałeś prawidłowej opcji!\n");
				sleep(2);
		}
	}	
	return EXIT_SUCCESS;
}
