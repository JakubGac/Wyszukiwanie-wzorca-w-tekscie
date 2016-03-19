#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int zlicz_znaki(char* nazwa_pliku){
	int znak;
	int ile = 0;
	FILE *plik = fopen(nazwa_pliku,"r");

	/* zliczamy ile jest znaków w pliku, pomijając spacje */
	znak = getc(plik);
	ile++;
	while (znak != EOF) {
		if(znak == ' ' || znak == '\0' || znak == '\n'){
			znak = getc(plik);
		} else {
			znak = getc(plik);
			ile++;
		}
	}
	ile--;
	fclose(plik);
	return ile;	
}

char* wczytaj_dane(int ile, char* nazwa_pliku){

	/* tworzymy tablice o zadanej ilosci znakow */
	char *tablica_znakow = (char*)malloc(ile * sizeof(*tablica_znakow));

	/* i zapelniamy ja */
	FILE *plik = fopen(nazwa_pliku,"r");
	int pozycja = 0;
	char znak = getc(plik);
	
	while(ile){
		if(znak == ' ' || znak == '\0' || znak == '\n'){
                        znak = getc(plik);
                } else {
                        tablica_znakow[pozycja] = znak;
			znak = getc(plik);
			ile--;
			pozycja++;
                }		
	}
	fclose(plik);
	
	return tablica_znakow;
}
