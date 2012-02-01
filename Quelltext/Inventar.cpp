#include <windows.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include "funktion.h"
#include "Formatierung.h"
#include "WorldGenerate.h"


using namespace std;


extern time_t t_start;
extern time_t t_messure;
extern int steps;
extern int chest_1;
extern int chest_2;
extern int chest_3;
extern char name[100];



int Inventar(){
    int m=0;
    LeerKomplett();
    RahmenMap();
    Curpos(3,3);
    Farbe(14);
    cout << "INVENTAR & STATISTIK";


    Curpos(10,8);
    Farbe(2);
    cout << "Spielername: ";
    Farbe(4);
    while(name[m]!='\0'){
        cout << name[m];
        m++;
    }
    m=0;

    Curpos(10,10);
    Farbe(10);
    cout << "Spielstart: ";
    Farbe(15);
    cout << ctime( &t_start ) << endl;
    t_messure = time(0);
    t_messure=t_messure-t_start;

    Curpos(10,11);
    Farbe(10);
    cout << "Spielzeit: ";
    Farbe(15);
    cout << t_messure << " Sekunden" << endl;

    Curpos(10,12);
    Farbe(10);
    cout << "Distanz: ";
    Farbe(15);
    cout << steps;

    if(steps==1){
        cout << " Schritt";
    }

    else{
        cout << " Schritte";
    }



    Curpos(10,13);
    Farbe(10);
    cout << "Kisten: ";
    Farbe(14);
    Curpos(18,13);
    cout << chest_1;
    Farbe(15);

    if(chest_1==1){
        cout << " - Level 1 Kiste";
    }
    else{
        cout << " - Level 1 Kisten";
    }


    Farbe(14);
    Curpos(18,14);
    cout << chest_2;
    Farbe(15);

    if(chest_2==1){
        cout << " - Level 2 Kiste";
    }
    else{
        cout << " - Level 2 Kisten";
    }


    Farbe(14);
    Curpos(18,15);
    cout << chest_3;
    Farbe(15);

    if(chest_3==1){
        cout << " - Level 3 Kiste";
    }
    else{
        cout << " - Level 3 Kisten";
    }









    int eingabe=0;
    int n=1;

    while(n){
        eingabe=getch();

        if(eingabe==224){
            eingabe=getch();
        }

        if(eingabe==105){
            MapNew2Rand();
            RahmenMap();
            n=0;
        }
    }

    return 0;

}



using namespace std;


