#include"saper.h"

int main()
{
 srand(time(NULL));  
 int x = Menu();
 while(x != 0 && (x == 1 || x == 2)){
 switch(x)
 {
   case 1 : Nowa_gra();
            break;       
   case 2 : Info();
            break;
   //case 0 : break;       
 }
 x = Menu();
}
return 0;
}
