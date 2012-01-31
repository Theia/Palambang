// by Oertel

/*

    char npc=2;
    char stein=219;
    char kiste=254;
    char lava=176;
    char seltenekiste=184;
    char charakter=1;
    char superseltenekiste=244;
    char dungeon=36;
    char wasser=177;

*/


// Startposition charakter  x=501  y=502

#include <windows.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include "funktion.h"

#include "WorldGenerate.h"
#include "Bilder.h"

#include "Gegenstandsgenerierung.h"
#include "EasyBMP.h"
#include "Formatierung.h"





using namespace std;




int zaubertextzeilen=0;     // Anzahl der Beschreibungen unten
char map[1000][1000];
int char_x=501;
int char_y=502;
int char_x_versatz=0;
int char_y_versatz=0;
Geld char_Geld={0,0,0,0};
int char_wert=0;
int char_map_x=38;
int char_map_y=11;
int char_map_offset_x=0;
int char_map_offset_y=0;
int kistegeoff=0;
int hide_bild=0;
float wert=0;
int mengeverzauberungen=0;



int main(){

    //Datum = GetCurrentTime();


    srand( time(NULL) );
    int debug=0;
    Geld wert_Conv={0,0,0,0};
    GegenstandInfo halter = {0,0,0};
    int wert_einser=0;
    int richtung=0;
    int richtungok=0;

/*
    Curpos(0,24);
    for(int z=0; z<29; z++){
        Farbe(z);
        cout << z << " ";
    }
*/

    WorldGenerate();
    BmpGenerate();


while(1){

        if(kistegeoff==0){
            Curpos(1,0);
            cout << "                                        ";
            Curpos(1,0);
            cout << "x:" << char_x << "  | y:" << char_y;
        }


        richtung=Richtung();                // Hier erfolgt Eingabe

        if(kistegeoff==1){
            LeerKomplett();
            MapNew2Rand();
            kistegeoff=0;
            RahmenMap();
        }

        Curpos(70,0);
        cout << "   ";
        Curpos(70,0);
        cout << richtung;


        Curpos(1,24);
        cout << "                                                    ";
        Curpos(1,24);
        cout << "Aktuelles Geld: ";
        char_Geld=GeldConv(char_wert);
        AusgabeGeldConv(char_Geld);


        richtungok=RichtungTest2(richtung);

        MapNew2();



    if(richtungok==1){
        MapNew2();
    }

    if(richtungok==2){
        LeerKomplett();
        Rahmen();
        RahmenLinks();
        Kistengenerierung(2,0);
    }



    if(richtungok==3){
        LeerKomplett();
        Rahmen();
        RahmenLinks();
        Kistengenerierung(50,0);
    }



    if(richtungok==4){
        LeerKomplett();
        Rahmen();
        RahmenLinks();
        Kistengenerierung(50000,1);
    }


    }


}


