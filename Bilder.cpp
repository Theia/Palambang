#include <windows.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "funktion.h"
#include "Gegenstandsgenerierung.h"

using namespace std;


int Bild(int gegenstandID){
    char zeichen=219;

    int x=4;
    int y=6;
    int h1=0;
    int h2=0;


    while(h2<14){                   // Linker Rahmen wird komplett leer geschrieben
        while(h1<11){
            Curpos(x+h1,y+h2);
            cout << " ";
            h1++;
        }
        h1=0;
        h2++;
    }



    //    *******************    B I L D  - - - G E N E R I E R U N G  - - -         //             *******************

    if(gegenstandID==100){          // Helm
        x=5;
        y=7;
        int i=0;
        while(i<7){
            Curpos(x,y+i);
            cout << zeichen;
            i++;
        }
        x=6;
        i=0;
        while(i<7){
            Curpos(x,y+i);
            cout << zeichen;
            i++;
        }

        x=12;
        i=0;
        while(i<7){
            Curpos(x,y+i);
            cout << zeichen;
            i++;
        }

        x=13;
        i=0;
        while(i<7){
            Curpos(x,y+i);
            cout << zeichen;
            i++;
        }

        x=5;
        y=14;
        i=0;
        while(i<9){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }

        y=15;
        i=0;
        while(i<9){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }

        y=16;
        i=0;
        while(i<9){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }

        Curpos(5,17); cout << zeichen;
        Curpos(9,17); cout << zeichen;
        Curpos(13,17); cout << zeichen;
        Curpos(7,9); cout << zeichen;
        Curpos(11,9); cout << zeichen;
        Curpos(9,13); cout << zeichen;

        x=7;
        y=10;
        i=0;
        while(i<5){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }

        y=11;
        i=0;
        while(i<5){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }

        y=12;
        i=0;
        while(i<5){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }


    }

    if(gegenstandID==0){            // Schwert
        x=9;
        y=7;
        int i=0;
        while(i<12){
            Curpos(x,y+i);
            cout << zeichen;
            i++;
        }

        i=0;
        x=8;
        y=9;
        while(i<10){
            Curpos(x,y+i);
            cout << zeichen;
            i++;
        }

        i=0;
        x=10;
        while(i<10){
            Curpos(x,y+i);
            cout << zeichen;
            i++;
        }

        i=0;
        x=5;
        y=15;
        while(i<9){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }

        i=0;
        y=16;
        while(i<9){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }

    }

    if(gegenstandID==1){            // Dolch
        x=9;
        y=9;
        int i=0;
        while(i<8){
            Curpos(x, y+i);
            cout << zeichen;
            i++;
        }

        x=7;
        y=14;
        i=0;
        while(i<5){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }

    }

    if(gegenstandID==3){            // Streitkolben
        x=9;
        y=7;
        int i=0;
        while(i<11){
            Curpos(x,y+i);
            cout << zeichen;
            i++;
        }

        i=0;
        x=5;
        y=10;
        while(i<9){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }

        x=7;
        y=9;
        i=0;
        while(i<5){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }

        y=10;
        i=0;
        while(i<5){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }

        y=11;
        i=0;
        while(i<5){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }
    }

    if(gegenstandID==102){          // Stiefel
        int i2=5;
        int i=0;
        x=7;
        y=10;
        while(i<7){
            Curpos(x,y+i);
            cout << zeichen;
            Curpos(x+i2,y+i);
            cout << zeichen;
            i++;
        }

        x=8;
        i=0;
        while(i<7){
            Curpos(x,y+i);
            cout << zeichen;
            Curpos(x+i2,y+i);
            cout << zeichen;
            i++;
        }

        x=5;
        i=0;
        y=15;
        while(i<2){
            Curpos(x+i,y);
            cout << zeichen;
            Curpos(x+i+i2,y);
            cout << zeichen;
            i++;
        }

        i=0;
        y=16;
        while(i<2){
            Curpos(x+i,y);
            cout << zeichen;
            Curpos(x+i+i2,y);
            cout << zeichen;
            i++;
        }
    }

    if(gegenstandID==4){            // Hammer
        int i=0;
        x=5;
        y=7;
        while(i<9){
            Curpos(x+i,y);
            cout << zeichen;
            Curpos(x+i,y+1);
            cout << zeichen;
            Curpos(x+i,y+2);
            cout << zeichen;
            Curpos(x+i,y+3);
            cout << zeichen;
            i++;
        }

        i=0;
        x=8;
        y=11;
        while(i<8){
            Curpos(x,y+i);
            cout << zeichen;
            Curpos(x+1,y+i);
            cout << zeichen;
            Curpos(x+2,y+i);
            cout << zeichen;
            i++;
        }
    }

    if(gegenstandID==101){          // Schild
        int i=0;
        x=6;
        y=8;
        while(i<7){
            Curpos(x+i,y);
            cout << zeichen;
            Curpos(x+i,y+1);
            cout << zeichen;
            Curpos(x+i,y+2);
            cout << zeichen;
            Curpos(x+i,y+3);
            cout << zeichen;
            Curpos(x+i,y+4);
            cout << zeichen;
            Curpos(x+i,y+5);
            cout << zeichen;
            Curpos(x+i,y+6);
            cout << zeichen;
            i++;
        }

        Curpos(9,17);
        cout << zeichen;
        i=0;
        x=7;
        y=15;
        while(i<5){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }

        i=0;
        x=8;
        y=16;
        while(i<3){
            Curpos(x+i,y);
            cout << zeichen;
            i++;
        }

    }

    if(gegenstandID==104){          // Hose
        int i=0;
        x=6;
        y=9;
        while(i<9){
            Curpos(x,y+i);
            cout << zeichen;
            Curpos(x+1,y+i);
            cout << zeichen;
            Curpos(x+2,y+i);
            cout << zeichen;
            Curpos(x+4,y+i);
            cout << zeichen;
            Curpos(x+5,y+i);
            cout << zeichen;
            Curpos(x+6,y+i);
            cout << zeichen;
            i++;
        }
        Curpos(9,9);
        cout << zeichen;
        Curpos(9,10);
        cout << zeichen;
        Curpos(9,11);
        cout << zeichen;

    }

    if(gegenstandID==103){          // Handschuhe
        int i=0;
        x=6;
        y=8;
        while(i<7){
            Curpos(x+i,y);
            cout << zeichen;
            Curpos(x+i,y+1);
            cout << zeichen;
            Curpos(x+i,y+2);
            cout << zeichen;
            Curpos(x+i,y+3);
            cout << zeichen;
            Curpos(x+i,y+5);
            cout << zeichen;
            Curpos(x+i,y+6);
            cout << zeichen;
            Curpos(x+i,y+7);
            cout << zeichen;
            Curpos(x+i,y+8);
            cout << zeichen;
            i++;
        }
        Curpos(6,10);
        cout << " ";
        Curpos(6,14);
        cout << " ";
    }

    if(gegenstandID==2){             // Degen
        int i=0;
        x=9;
        y=7;
        while(i<12){
            Curpos(x,y+i);
            cout << zeichen;
            i++;
        }

        i=0;
        x=8;
        y=19;
        Curpos(8,18);
        cout << zeichen;
        Curpos(7,15);
        cout << zeichen << zeichen << zeichen << zeichen;
        Curpos(7,16);
        cout << zeichen;
        Curpos(7,17);
        cout << zeichen;
        Curpos(11,16);
        cout << zeichen;

    }

return 0;

}
