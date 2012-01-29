#include <windows.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "funktion.h"

#include "WorldGenerate.h"
#include "Bilder.h"

#include "Gegenstandsgenerierung.h"
#include "EasyBMP.h"


using namespace std;



void LeerKomplett(void){
    int i=0;
    while(i<=24){
        Curpos(0,i);
        cout << "                                                                              ";
        i++;
    }

}



int Farbe(int farbe){       // passt Schriftfarbe an
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, farbe);
    return farbe;
}



void RahmenMap(){               // Großer Rahmen um Karte
    unsigned short cx=1;
    unsigned short cy=1;
    char viereck=219;

    Curpos(cx,cy);
    Farbe(7);

    while(cx<=77){
        cout << viereck;
        cx++;
        Curpos(cx,cy);
    }


    cy=1;
    cx=77;
    Curpos(cx,cy);


    while(cy<=23){
        cout << viereck;
        cy++;
        Curpos(cx,cy);
    }



    cx=77;
    cy=23;
    Curpos(cx,cy);

    while(cx>=1){
        cout << viereck;
        cx--;
        Curpos(cx,cy);
    }

    cx=1;
    cy=23;
    Curpos(cx,cy);

    while(cy>=1){
        cout << viereck;
        cy--;
        Curpos(cx,cy);
    }

}



void RahmenLinks(){             // Gegenstand Rahmen Links

    unsigned short cx=3;
    unsigned short cy=5;
    char viereck=178;

    Curpos(cx,cy);

    while(cx<=15){
        cout << viereck;
        cx++;
        Curpos(cx,5);
    }
    cx=3;
    Curpos(cx,20);

    while(cx<=15){
        cout << viereck;
        cx++;
        Curpos(cx,20);
    }

    cx=15;
    cy=5;
    Curpos(cx,cy);

    while(cy<=20){
        cout << viereck;
        cy++;
        Curpos(3,cy);
    }

    cy=5;
    Curpos(15,cy);



    while(cy<=20){
        cout << viereck;
        cy++;
        Curpos(15,cy);
    }

}



void Rahmen(){                  // Gegenstand Rahmen Rechts

    unsigned short cx=20;
    unsigned short cy=5;
    char viereck=178;

    Curpos(20,5);

    while(cx<=60){
        cout << viereck;
        cx++;
        Curpos(cx,5);
    }
    cx=20;
    Curpos(cx,20);

    while(cx<=60){
        cout << viereck;
        cx++;
        Curpos(cx,20);
    }

    cx=20;
    cy=5;
    Curpos(cx,cy);

    while(cy<=20){
        cout << viereck;
        cy++;
        Curpos(20,cy);
    }

    cy=5;
    Curpos(60,cy);



    while(cy<=20){
        cout << viereck;
        cy++;
        Curpos(60,cy);
    }

}



float FarbeConv(int zufallsfarbe){
    float n=0;
    if(zufallsfarbe==8){            // grau
        n=0.05;
    }

    if(zufallsfarbe==15){            // weiß
        n=0.2;
    }

    if(zufallsfarbe==10){            // grün
        n=0.8;
    }

    if(zufallsfarbe==9){            // blau
        n=1.5;
    }

    if(zufallsfarbe==13){            // lila
        n=3.2;
    }

    if(zufallsfarbe==12){            // rot
        n=7.0;
    }

    if(zufallsfarbe==14){            // gelb
        n=18.1;
    }

    if(zufallsfarbe==24){            // hintergrund Ultra Rare
        n=49.2;
    }


    return n;
}



