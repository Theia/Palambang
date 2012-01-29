// by Oertel

/*

    char stein=219;
    char leer=32;
    char kiste=254;
    char lava=176;
    char seltenekiste=184;
    char charakter=1;
    char superseltenekiste=243;
    char dungeon=36;

*/

// Startposition charakter  x=501  y=502

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




int main(){

    srand( time(NULL) );
    //Randomcounter();;
    //Rahmen();
    //RahmenLinks();
    int debug=0;
    int farbe=0;
    float wert=0;
    Geld wert_Conv={0,0,0,0};
    GegenstandInfo halter = {0,0,0};
    int mengeverzauberungen=0;
    int wert_einser=0;
    int hide_bild=0;
    int richtung=0;
    int richtungok=0;
    int kistegeoff=0;
/*
    Curpos(0,24);
    for(int z=0; z<29; z++){
        Farbe(z);
        cout << z << " ";
    }
*/

    WorldGenerate();
    BmpGenerate();

/*
    Curpos(0,0);
    cout << "  [501][503]:" << map[501][503];
    cout << "  [501][501]:" << map[501][501];
    cout << "  [500][502]:" << map[500][502];
    cout << "  [502][502]:" << map[502][502];
*/

while(1){

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


        int input=2;
        Curpos(28,22);
                cout << "                                ";
                Curpos(1,2);
                cout << "                                                                  ";
                float best=0;

                hide_bild=1;

                Curpos(1,1);
                cout << "                                                          ";

                int best_gegenstandID=0;                // Schwert, Schuhe, Schild...
                int best_colorofthis=0;                 // Lila, Rot...
                int best_number_of_enchant=0;           // + 25... + 33...
                int best_enchanttype=0;                 // Mana, Lebenspunkte...

                for(int i=0; i<input; i++){


                    farbe=Farbe(Zufallsfarbe());
                    wert=FarbeConv(farbe);
                    halter=Gegenstand(zaubertextzeilen, hide_bild);
                    mengeverzauberungen=halter.gegenstand_number_enchant;
                    wert_einser=rand();
                    wert_einser=wert_einser%40;
                    wert_einser=wert_einser-20;

                    wert=(1000*wert)+(mengeverzauberungen*wert*100)+wert_einser;

                    if(wert>best){
                        best=wert;
                        best_colorofthis=farbe;     //8,15,10,9,13,10
                        best_number_of_enchant=halter.gegenstand_number_enchant;
                        best_enchanttype=halter.verzauberung;
                        best_gegenstandID=halter.gegenstandID;

                    }
                }

                Leer();
                Curpos(25,7);
                Farbe(best_colorofthis);
                BName(best_gegenstandID);
                BZauber(best_enchanttype);
                if(best_number_of_enchant>0){
                    BStats(best_number_of_enchant, best_enchanttype);
                }
                Bild(best_gegenstandID);

                Farbe(13);
                Curpos(20,3);           // Löschen der Prozentanzeige
                cout << "                     ";

                Curpos(1,2);
                cout << "                                                 ";
                Curpos(1,2);
                HANDLE hConsole;
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 15);
                wert_Conv=GeldConv(best);
                cout << "Wert des Gegenstandes: ";
                AusgabeGeldConv(wert_Conv);
                char_wert=char_wert+best;

                hide_bild=0;
                kistegeoff=1;
    }





    if(richtungok==3){
        LeerKomplett();
        Rahmen();
        RahmenLinks();




        int input=50;
        Curpos(28,22);
                cout << "                                ";
                Curpos(1,2);
                cout << "                                                                  ";
                float best=0;

                hide_bild=1;

                Curpos(1,1);
                cout << "                                                          ";

                int best_gegenstandID=0;                // Schwert, Schuhe, Schild...
                int best_colorofthis=0;                 // Lila, Rot...
                int best_number_of_enchant=0;           // + 25... + 33...
                int best_enchanttype=0;                 // Mana, Lebenspunkte...

                for(int i=0; i<input; i++){


                    farbe=Farbe(Zufallsfarbe());
                    wert=FarbeConv(farbe);
                    halter=Gegenstand(zaubertextzeilen, hide_bild);
                    mengeverzauberungen=halter.gegenstand_number_enchant;
                    wert_einser=rand();
                    wert_einser=wert_einser%40;
                    wert_einser=wert_einser-20;

                    wert=(1000*wert)+(mengeverzauberungen*wert*100)+wert_einser;

                    if(wert>best){
                        best=wert;
                        best_colorofthis=farbe;     //8,15,10,9,13,10
                        best_number_of_enchant=halter.gegenstand_number_enchant;
                        best_enchanttype=halter.verzauberung;
                        best_gegenstandID=halter.gegenstandID;

                    }
                }

                Leer();
                Curpos(25,7);
                Farbe(best_colorofthis);
                BName(best_gegenstandID);
                BZauber(best_enchanttype);
                if(best_number_of_enchant>0){
                    BStats(best_number_of_enchant, best_enchanttype);
                }
                Bild(best_gegenstandID);

                Farbe(13);
                Curpos(20,3);           // Löschen der Prozentanzeige
                cout << "                     ";

                Curpos(1,2);
                cout << "                                                 ";
                Curpos(1,2);
                HANDLE hConsole;
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 15);
                wert_Conv=GeldConv(best);
                cout << "Wert des Gegenstandes: ";
                AusgabeGeldConv(wert_Conv);
                char_wert=char_wert+best;

                hide_bild=0;
                kistegeoff=1;

    }






    if(richtungok==4){
        LeerKomplett();
        Rahmen();
        RahmenLinks();




        int input=50000;
        Curpos(28,22);
                cout << "                                ";
                Curpos(1,2);
                cout << "                                                                  ";
                float best=0;

                int fortschritt=0;

                hide_bild=1;

                Curpos(1,1);
                cout << "                                                          ";

                int best_gegenstandID=0;                // Schwert, Schuhe, Schild...
                int best_colorofthis=0;                 // Lila, Rot...
                int best_number_of_enchant=0;           // + 25... + 33...
                int best_enchanttype=0;                 // Mana, Lebenspunkte...

                for(int i=0; i<input; i++){


                    if(i%1000==0){
                        fortschritt=(i*100)/input;
                        Curpos(20,3);
                        Farbe(13);
                        cout << "                       ";
                        Curpos(20,3);

                        HANDLE hConsole;
                        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 8);

                        cout << "Fortschritt: " << fortschritt << "%";
                    }


                    farbe=Farbe(Zufallsfarbe());
                    wert=FarbeConv(farbe);
                    halter=Gegenstand(zaubertextzeilen, hide_bild);
                    mengeverzauberungen=halter.gegenstand_number_enchant;
                    wert_einser=rand();
                    wert_einser=wert_einser%40;
                    wert_einser=wert_einser-20;

                    wert=(1000*wert)+(mengeverzauberungen*wert*100)+wert_einser;

                    if(wert>best){
                        best=wert;
                        best_colorofthis=farbe;     //8,15,10,9,13,10
                        best_number_of_enchant=halter.gegenstand_number_enchant;
                        best_enchanttype=halter.verzauberung;
                        best_gegenstandID=halter.gegenstandID;

                    }
                }

                Leer();
                Curpos(25,7);
                Farbe(best_colorofthis);
                BName(best_gegenstandID);
                BZauber(best_enchanttype);
                if(best_number_of_enchant>0){
                    BStats(best_number_of_enchant, best_enchanttype);
                }
                Bild(best_gegenstandID);

                Farbe(13);
                Curpos(20,3);           // Löschen der Prozentanzeige
                cout << "                     ";

                Curpos(1,2);
                cout << "                                                 ";
                Curpos(1,2);
                HANDLE hConsole;
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 15);
                wert_Conv=GeldConv(best);
                cout << "Wert des Gegenstandes: ";
                AusgabeGeldConv(wert_Conv);
                char_wert=char_wert+best;

                hide_bild=0;
                kistegeoff=1;

    }
    }


}


