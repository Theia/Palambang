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



int Richtung(void);
int RichtungTest(int, int, int);

int RichtungTest2(int);



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

   // while(1){

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

    //}

//Sleep(10000);

    if(richtungok==1){
        //RahmenMap();
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
                Curpos(20,3);           // L�schen der Prozentanzeige
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




        int input=100;
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
                Curpos(20,3);           // L�schen der Prozentanzeige
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




        int input=100000;
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
                Curpos(20,3);           // L�schen der Prozentanzeige
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


//*************************************************************************************************************************************************

int Richtung(void){

        int eingabe=0;

        eingabe=getch();
        if(eingabe==224){

            eingabe=getch();
                if(eingabe==77){
                    Curpos(60,0);
                    cout << "       ";
                    Curpos(60,0);
                    cout << "rechts";
                    return 4;
                }


                if(eingabe==75){
                    Curpos(60,0);
                    cout << "       ";
                    Curpos(60,0);
                    cout << "links";
                    return 3;
                }

                if(eingabe==72){
                    Curpos(60,0);
                    cout << "       ";
                    Curpos(60,0);
                    cout << "oben";
                    return 1;
                }

                if(eingabe==80){
                    Curpos(60,0);
                    cout << "       ";
                    Curpos(60,0);
                    cout << "unten";
                    return 2;
                }
        }

        return 0;
}






//*************************************************************************************************************************************************


int RichtungTest2(int richtung){


    Curpos(75,0);
    cout << "   ";

    char stein=219;
    char kiste=254;
    char lava=176;
    char seltenekiste=184;
    char charakter=1;
    char superseltenekiste=244;
    char dungeon=36;
    char wasser=177;

    if(richtung==1){        // oben
        if(map[char_x][char_y-1]==32){
            Curpos(75,0);
            cout << "ok!";
            char_y=char_y-1;
            Curpos(char_map_x+1, char_map_y+1);
            cout << " ";
            char_map_y=char_map_y-1;
            return 1;
        }

        else if (map[char_x][char_y-1]==kiste){  //kiste
            map[char_x][char_y-1]=32;
            char_y=char_y-1;
            char_map_y=char_map_y-1;





            LeerKomplett();
        Rahmen();
        RahmenLinks();

            return 2;
        }

        else if(map[char_x][char_y-1]==seltenekiste){  //special_kiste
            map[char_x][char_y-1]=32;
            char_y=char_y-1;
            char_map_y=char_map_y-1;
            return 3;
        }

        else if(map[char_x][char_y-1]==superseltenekiste){  //superspecial_kiste
            map[char_x][char_y-1]=32;
            char_y=char_y-1;
            char_map_y=char_map_y-1;
            return 4;
        }

    }



    if(richtung==2){        //unten
        if(map[char_x][char_y+1]==32){
            Curpos(75,0);
            cout << "ok!";
            char_y=char_y+1;
            Curpos(char_map_x+1, char_map_y+1);
            cout << " ";
            char_map_y=char_map_y+1;
            return 1;
        }

        else if(map[char_x][char_y+1]==kiste){  //kiste
            map[char_x][char_y+1]=32;
            char_y=char_y+1;
            char_map_y=char_map_y+1;
            return 2;
        }

        else if(map[char_x][char_y+1]==seltenekiste){  //special_kiste
            map[char_x][char_y+1]=32;
            char_y=char_y+1;
            char_map_y=char_map_y+1;
            return 3;
        }

        else if(map[char_x][char_y+1]==superseltenekiste){  //superspecial_kiste
            map[char_x][char_y+1]=32;
            char_y=char_y+1;
            char_map_y=char_map_y+1;
            return 4;
        }
    }



    if(richtung==3){        //links
        if(map[char_x-1][char_y]==32){
            Curpos(75,0);
            cout << "ok!";
            Curpos(char_map_x+1, char_map_y+1);
            cout << " ";
            char_x=char_x-1;
            char_map_x=char_map_x-1;
            return 1;
        }

        else if(map[char_x-1][char_y]==kiste){  //kiste
            map[char_x-1][char_y]=32;
            char_map_x=char_map_x-1;
            char_x=char_x-1;
            return 2;
        }

        else if(map[char_x-1][char_y]==seltenekiste){  //special_kiste
            map[char_x-1][char_y]=32;
            char_map_x=char_map_x-1;
            char_x=char_x-1;
            return 3;
        }

        else if(map[char_x-1][char_y]==superseltenekiste){  //superspecial_kiste
            map[char_x-1][char_y]=32;
            char_map_x=char_map_x-1;
            char_x=char_x-1;
            return 4;
        }
    }



    if(richtung==4){        //rechts
        if(map[char_x+1][char_y]==32){
            Curpos(75,0);
            cout << "ok!";
            Curpos(char_map_x+1, char_map_y+1);
            cout << " ";
            char_x=char_x+1;
            char_map_x=char_map_x+1;
            return 1;
        }

        else if(map[char_x+1][char_y]==kiste){  //kiste
            map[char_x+1][char_y]=32;
            char_map_x=char_map_x+1;
            char_x=char_x+1;
            return 2;
        }

        else if(map[char_x+1][char_y]==seltenekiste){  //special_kiste
            map[char_x+1][char_y]=32;
            char_map_x=char_map_x+1;
            char_x=char_x+1;
            return 3;
        }

        else if(map[char_x+1][char_y]==superseltenekiste){  //superspecial_kiste
            map[char_x+1][char_y]=32;
            char_x=char_x+1;
            char_map_x=char_map_x+1;
            return 4;
        }
    }

    else{
        Curpos(75,0);
        cout << "Ne!";
        return 0;

    }

}






//*************************************************************************************************************************************************


int RichtungTest(int richtung, int char_x, int char_y){         // oben 1    unten 2    links 3    rechts 4

    Curpos(75,0);
    cout << "   ";

    char stein=219;
    char kiste=254;
    char lava=176;
    char seltenekiste=184;
    char charakter=1;
    char superseltenekiste=244;
    char dungeon=36;

    if(richtung==1){        // oben
        if(map[char_x+char_x_versatz][char_y-1+char_y_versatz]==32){
            Curpos(75,0);
            cout << "ok!";
            char_y_versatz=char_y_versatz-1;
            return 1;
        }

        else if(map[char_x+char_x_versatz][char_y-1+char_y_versatz]==kiste){  //kiste
            map[char_x+char_x_versatz][char_y-1+char_y_versatz]=32;
            return 2;
        }

        else if(map[char_x+char_x_versatz][char_y-1+char_y_versatz]==seltenekiste){  //special_kiste
            map[char_x+char_x_versatz][char_y-1+char_y_versatz]=32;
            return 3;
        }

        else if(map[char_x+char_x_versatz][char_y-1+char_y_versatz]==superseltenekiste){  //superspecial_kiste
            map[char_x+char_x_versatz][char_y-1+char_y_versatz]=32;
            return 4;
        }


    }



    if(richtung==2){        //unten
        if(map[char_x+char_x_versatz][char_y+1+char_y_versatz]==32){
            Curpos(75,0);
            cout << "ok!";
            char_y_versatz=char_y_versatz+1;
            return 1;
        }

        else if(map[char_x+char_x_versatz][char_y+1+char_y_versatz]==kiste){  //kiste
            map[char_x+char_x_versatz][char_y+1+char_y_versatz]=32;
            return 2;
        }

        else if(map[char_x+char_x_versatz][char_y+1+char_y_versatz]==seltenekiste){  //special_kiste
            map[char_x+char_x_versatz][char_y+1+char_y_versatz]=32;
            return 3;
        }

        else if(map[char_x+char_x_versatz][char_y+1+char_y_versatz]==superseltenekiste){  //superspecial_kiste
            map[char_x+char_x_versatz][char_y+1+char_y_versatz]=32;
            return 4;
        }
    }



    if(richtung==3){        //links
        if(map[char_x-1+char_x_versatz][char_y+char_y_versatz]==32){
            Curpos(75,0);
            cout << "ok!";
            char_x_versatz=char_x_versatz-1;
            return 1;
        }

        else if(map[char_x-1+char_x_versatz][char_y+char_y_versatz]==kiste){  //kiste
            map[char_x-1+char_x_versatz][char_y+char_y_versatz]=32;
            return 2;
        }

        else if(map[char_x-1+char_x_versatz][char_y+char_y_versatz]==seltenekiste){  //special_kiste
            map[char_x-1+char_x_versatz][char_y+char_y_versatz]=32;
            return 3;
        }

        else if(map[char_x-1+char_x_versatz][char_y+char_y_versatz]==superseltenekiste){  //superspecial_kiste
            map[char_x-1+char_x_versatz][char_y+char_y_versatz]=32;
            return 4;
        }
    }



    if(richtung==4){        //rechts
        if(map[char_x+1+char_x_versatz][char_y+char_y_versatz]==32){
            Curpos(75,0);
            cout << "ok!";
            char_x_versatz=char_x_versatz+1;
            return 1;
        }

        else if(map[char_x+1+char_x_versatz][char_y+char_y_versatz]==kiste){  //kiste
            map[char_x+1+char_x_versatz][char_y+char_y_versatz]=32;
            return 2;
        }

        else if(map[char_x+1+char_x_versatz][char_y+char_y_versatz]==seltenekiste){  //special_kiste
            map[char_x+1+char_x_versatz][char_y+char_y_versatz]=32;
            return 3;
        }

        else if(map[char_x+1+char_x_versatz][char_y+char_y_versatz]==superseltenekiste){  //superspecial_kiste
            map[char_x+1+char_x_versatz][char_y+char_y_versatz]=32;
            return 4;
        }
    }

    else{
        return 0;

    }

}


