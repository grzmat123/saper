#include"saper.h"

Gra::Gra(int x , int y, int m, int l){
             polozenie_x = x;
             polozenie_y = y;
             Czysc_plansze();
             liczba_min = m;
             licznik = l;
             miny = new int *[m];
             for (int i = 0; i < m; i ++){
                 miny[i] = new int[2];
                 do 
                 { 
                 miny[i][0] = ((rand() % 20) + 1);
                 miny[i][1] = ((rand() % 20) + 1);
                 } while(miny[i][0] == polozenie_x && miny[i][1] == polozenie_y);
                 }
             for (int i = 0; i < m; i++){
                 cout<<"Mina nr: "<<i+1<<" wspolrzedne: X = "<<miny[i][0]<<" Y = "<<miny[i][1]<<endl;
                 }             
             }

void Gra::Czysc_plansze(){
     for(int j = 0; j < 22; j++){             
     for (int i = 0; i < 22; i++){
         Plansza[j][i] = " ";
         }
         }
     for (int i = 0; i < 22; i++){
         Plansza[0][i] = "+";
         }
     for (int i = 0; i < 22; i++){
         Plansza[21][i] = "+";
         }
     for (int i = 0; i < 22; i++){
         Plansza[i][0] = "+";
         }
     for (int i = 0; i < 22; i++){
         Plansza[i][21] = "+";
         }
     Plansza[1][20] = "@";
     }
             
void Gra::Rysuj_plansze(){
     Plansza[polozenie_y][polozenie_x] = "o";
     for(int j = 0; j < 22; j++){             
     for (int i = 0; i < 22; i++){
         cout<<Plansza[j][i];
         }
         cout<<endl;
         }
     cout<<"Sterowanie: W - do gory, S - do dolu, A - w lewo, D - w prawo, O - wyjscie z gry";    
     }

void Gra::Rysuj_miny(){
     for (int i = 0; i < liczba_min; i ++){
         
           Plansza[miny[i][1]][miny[i][0]] = "X";
           }
     Rysuj_plansze();
     
     }
     
int Menu(){
     int x;
     cout<<"WITAJ W GRZE SAPER ;)"<<"\a"<<endl;
     cout<<"Co chcesz zrobic?"<<endl;
     cout<<"1. Nowa gra"<<endl;
     cout<<"2. Informacje o autorze i grze"<<endl;
     cout<<"0. Wyjscie"<<endl;
     cout<<"Wybieram: ";
     cin>>x;
     return x;
     }


void Info(){
     cout<<"----> SAPER <----"<<"\a"<<endl;
     cout<<"Autor gry: Grzegorz Matyszczak"<<endl;
     cout<<"Projekt z 'Jezykow' Programowania 2018"<<endl;
     }

void Nowa_gra(){
     string przycisk;
     int m;
     cout<<"Rozpoczynamy gre!"<<endl<<"Podaj liczbe min: ";
     cin>>m;
     Gra Gra(1, 20, m);
     Gra.Rysuj_plansze();
     //Gra.Rysuj_miny();
     przycisk = getch();
     while (przycisk != "o"){ 
     Gra.Ruch(przycisk);
     Gra.Idiotoodpornosc(); 
     Gra.Rysuj_plansze();
     Gra.Podaj_polozenie();
     int decyzja = Gra.Sprawdz_wygrana();
     if (decyzja == 0) {Gra.Sprawdz_otoczenie();
                       przycisk = getch();};
     if (decyzja == 1) przycisk = "o";
     if (decyzja == 2) {cout<<"Czy chcesz zapisac swoj wynik? t - tak, n - nie"<<endl;
     cin>>przycisk;
     if (przycisk == "t") {string imie; cout<<"Podaj swoje imie"<<endl; cin>>imie; 
     fstream plik; plik.open("wyniki.txt"); plik.seekg(0, ios::end); 
     plik<<"Gracz "<<imie<<" wykonal "<<Gra.licznik<<" krokow przy "<<Gra.liczba_min<<" minach"<<endl;
     plik.close();
     przycisk = "o";};
     if (przycisk == "n") przycisk = "o";}
     }
     //delete Gra.miny;
     Gra.~Gra();
     }

void Gra::Ruch(string p){
     system( "cls" );
     Plansza[polozenie_y][polozenie_x] = "#";
     if (p == "w") {polozenie_y = polozenie_y - 1;};
     if (p == "s") {polozenie_y = polozenie_y + 1;};
     if (p == "a") {polozenie_x = polozenie_x - 1;};
     if (p == "d") {polozenie_x = polozenie_x + 1;};
     licznik++;
     }
     
void Gra::Podaj_polozenie(){
     cout<<"Saper: x = "<<polozenie_x<<"   y = "<<polozenie_y<<endl;
     }

void Gra::Sprawdz_otoczenie(){
     int pom = 0;
     for (int i = 0; i < liczba_min; i ++){
         if (miny[i][0] == polozenie_x + 1 && miny[i][1] == polozenie_y + 1 ||
         miny[i][0] == polozenie_x + 1 && miny[i][1] == polozenie_y ||
         miny[i][0] == polozenie_x + 1 && miny[i][1] == polozenie_y - 1 ||
         miny[i][0] == polozenie_x - 1 && miny[i][1] == polozenie_y + 1 ||
         miny[i][0] == polozenie_x - 1 && miny[i][1] == polozenie_y ||
         miny[i][0] == polozenie_x - 1 && miny[i][1] == polozenie_y - 1 ||
        miny[i][0] == polozenie_x && miny[i][1] == polozenie_y + 1 ||
        miny[i][0] == polozenie_x && miny[i][1] == polozenie_y - 1)
         {cout<<"MINY!!!"<<endl;
         pom = 1;};
         }
      if (pom != 1) cout<<"Brak min!"<<endl;   
     }

int Gra::Sprawdz_wygrana(){
     int decyzja = 0;
     for (int i = 0; i < liczba_min; i ++){
         if (miny[i][0] == polozenie_x && miny[i][1] == polozenie_y) {cout<<"Trafiles na mine! Game over!\a"<<endl; 
  cout<<"           '|/   "<<endl;
  cout<<"          .-*-   "<<endl;      
  cout<<"         | /|''   "<<endl;      
  cout<<"        _L_      "<<endl;      
  cout<<"      ,'   '.    "<<endl;      
  cout<<"  (  /  O O   /)"<<endl;      
  cout<<"   '\|    _    |/ "<<endl;      
  cout<<"     '\  (_)  /   "<<endl;      
  cout<<"     _/.___,'\_   "<<endl;      
  cout<<"    (_/     '\_)  "<<endl;
         decyzja = 1;};
         }
     if (polozenie_x == 20 && polozenie_y == 1) {cout<<"Uwolniles malpe!!! Gratulacje!\a\a\a"<<endl;
  cout<<"            __,__            "<<endl;
  cout<<"   .--.  .-'     '-.  .--.   "<<endl;
  cout<<"  | .. ||  .-. .-.  || .. |  "<<endl;
  cout<<" | |  '|  |   Y   |  |'  | | "<<endl;
  cout<<" | |   |  | 0 | 0 |  |   | | "<<endl;
  cout<<"  | '- ,|.-'`` ``'-.|, -' |  "<<endl;
  cout<<"   `'-' |_   ^ ^   _| '-'`   "<<endl;
  cout<<"       |  |._   _.|  |       "<<endl;
  cout<<"       |   | `~` |   |       "<<endl;
  cout<<"        '._ '-=-' _.'        "<<endl;
  cout<<"           '~---~'           "<<endl;
  cout<<"Wykonales "<<licznik<<" ruchow"<<endl;
      decyzja = 2;};  
     return decyzja;      
     }

void Gra::Idiotoodpornosc(){
     if (polozenie_x == 0) {polozenie_x = 1; cout<<"Nie skacz po plocie!\a"<<endl;};
     if (polozenie_x == 21) {polozenie_x = 20; cout<<"Nie skacz po plocie!\a"<<endl;};
     if (polozenie_y == 0) {polozenie_y = 1; cout<<"Nie skacz po plocie!\a"<<endl;};
     if (polozenie_y == 21) {polozenie_y = 20; cout<<"Nie skacz po plocie!\a"<<endl;};
     }
