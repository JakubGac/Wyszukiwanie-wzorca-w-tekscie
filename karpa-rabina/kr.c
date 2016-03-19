#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int r = 256; /* liczba symboli alfabetu */
int q = 9552; /* mozliwie duza liczba pierwsza */

/* funkcja obliczajaca a ^ b mod m */
int power_modulo_fast(int a, int b, int m) {
   int i;
   int result = 1;
   long int x = a%m;

   for (i=1; i<=b; i<<=1) {
      x %= m;
      if ((b&i) != 0) {
         result *= x;
         result %= m;
      }
      x *= x;
   }

   return result % m;
}

float uruchom_algorytm_kr(int ile_elementow_tekst,char* tablica_znakow,int ile_elementow_wzorzec,char* tablica_wzorzec) {
	clock_t start = clock();
	char *wzorzec = tablica_wzorzec;
	char *tekst = tablica_znakow;
	int m,n,i,j,h1,h2,rm;
	int wynik = 0;
	float time = 0.0;	

	n = ile_elementow_tekst;
	m = ile_elementow_wzorzec;
	h2=0;
	h1=0;
	/* algorytm Hornera do obliczenia funkcji haszujacej h(tekst[1..m]) */
	for (i=0; i<m; i++) {
   		h2=((h2*r) + tekst[i]);
   		h2%=q;
	}

	/* algorytm Hornera do obliczenia funkcji haszujacej h(wzorzec) */
	for (i=0; i<m; i++) {
   		h1=((h1*r) + wzorzec[i]);
   		h1%=q;
	}

	rm=power_modulo_fast(r, m-1, q);
	i=0;
	while (i<n-m) {
        	j=0;
        	if (h1==h2) while ((j<m)&&(wzorzec[j]==tekst[i+j])) j++;
        	if (j==m) wynik = i+1;
        	h2=((h2-tekst[i]*rm)*r+tekst[i+m]);
        	h2%=q;
        	if (h2<0) h2+=q;
        		i++;
	}
	j=0;
	if (h1==h2) 
		while ((j<m)&&(wzorzec[j]==tekst[i+j])) j++;
	if (j==m)
		wynik = i+1; 

	time = (clock() - start) / (float)CLOCKS_PER_SEC;
	printf("Pozycja wzorca w tekście: %d\n",wynik);
	sleep(2);
	return time;
}
