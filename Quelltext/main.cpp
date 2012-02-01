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


/*
    grau=8;
    weiß=15;
    grün=10;
    blau=9;
    lila=13;
    rot=12;
    gelb=14;
    blau=24;

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

#include <MMSystem.h>




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
char name[100];
int char_level=1;
int char_exp=0;
int char_life=0;
int char_life_damage=0;

int steps=0;
int chest_1=0;
int chest_2=0;
int chest_3=0;

time_t t_start;
time_t t_messure;



int main(){
    srand(time(NULL));


    Nameinput();

    char* WAV = "New.wav";// cow.wav is a piano song in hard drive
    sndPlaySound(WAV, SND_ASYNC);




    HMIDIOUT hMidiOut;
    UINT result = midiOutOpen(&hMidiOut, MIDI_MAPPER, 0, 0, 0);
    /*if(result != MMSYSERR_NOERROR){
    cout<< ("Geht nicht!");
    }*/

    BYTE volume = 127;
    BYTE note = 72;  // Ein C
/*
    for(int ih=0; ih<10000; ih++){
        midiOutShortMsg(hMidiOut, (volume << 16) | (note << ih+200) | ih); // note on
        Sleep(1);

    }
*/
/*
midiOutShortMsg(hMidiOut, (volume << 16) | (note << 8) | 0x91); // note on
Sleep(1000);
midiOutShortMsg(hMidiOut, (volume << 16) | (note << 8) | 0x81); // note off

midiOutClose(hMidiOut);
*/



    t_start = time(0);

    //Datum = GetCurrentTime();


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
    Lebensanzeige();

while(1){

        Farbe(8);
        if(kistegeoff==0){
            Curpos(1,0);
            cout << "                ";
            Curpos(1,0);
            cout << "x:" << char_x << "  | y:" << char_y;
        }


        richtung=Richtung();                // Hier erfolgt Eingabe

        if(kistegeoff==1){
            LeerKomplett();
            MapNew2Rand();
            kistegeoff=0;
            RahmenMap();
            Lebensanzeige();
        };

        Farbe(15);
        char_Geld=GeldConv(char_wert);
        Curpos(17,0);
        cout << "> ";
        AusgabeGeldConv(char_Geld);
        Lebensanzeige();
        Farbe(15);


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


