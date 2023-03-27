#ifndef _saper_h_
#define _saper_h_
#include<iostream>
#include<ctime>
#include<fstream>
#include<cstring>
#include<conio.h>

using namespace std;


class Gra{
      
      public:
             
      string Plansza[22][22];
      int polozenie_x, polozenie_y;
      int **miny;
      int liczba_min;
      int licznik;
      Gra(int  = 1, int  = 20, int = 0, int = 0);
      ~Gra(){}
      
      void Rysuj_plansze();
      void Ruch(string p);
      void Czysc_plansze();
      void Rysuj_miny();
      void Sprawdz_otoczenie();
      void Podaj_polozenie();
      int Sprawdz_wygrana();
      void Idiotoodpornosc();
      };
      
void Info();
int Menu();
void Nowa_gra();


#endif
