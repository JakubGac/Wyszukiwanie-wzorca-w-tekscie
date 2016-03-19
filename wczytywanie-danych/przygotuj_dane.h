#ifndef _KMP_H
#define _KMP_H

#include "wczytaj_dane.h"
#include "../knuth-morris-pratt/kmp.h"
#include "../boyera-moorea/bm.h"
#include "../karpa-rabina/kr.h"
#include "../naiwny/na.h"
#include "../wszystkie/uruchom_wszystkie.h"

void przygotuj_dane(char* plik1, char* plik2, int ktory_algorytm);

#endif
