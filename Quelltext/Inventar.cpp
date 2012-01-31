#include <windows.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "funktion.h"
#include "Formatierung.h"
#include "WorldGenerate.h"


using namespace std;


int Inventar(){
    LeerKomplett();
    RahmenMap();
    Curpos(3,3);
    cout << "INVENTAR";

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


