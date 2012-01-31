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
#include "Inventar.h"



using namespace std;


extern char map[1000][1000];
extern int char_x_versatz;
extern int char_y_versatz;
extern int char_x;
extern int char_y;
extern int char_map_x;
extern int char_map_y;
extern int char_map_offset_x;
extern int char_map_offset_y;



void BmpGenerate(void){     // Funktion zur Erzeugung des BitMaps; benötigt ->    extern char map[1000][1000]

    BMP output;
    output.SetSize(1000,1000);


    char stein=219;
    char npc=2;
    char kiste=254;
    char lava=176;
    char seltenekiste=184;
    char charakter=1;
    char leer=32;
    char superseltenekiste=244;
    char dungeon=36;
    char wasser=177;

    int lava_rand_1=0;
    int lava_rand_2=0;
    int lava_rand_3=0;

    int rand_1=0;
    int rand_2=0;
    int rand_3=0;


/*
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            output(i,j)->Red=0;
            output(i,j)->Green=0;
            output(i,j)->Blue=0;
        }
    }
*/


    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){

                if(map[i][j]==leer){

                    rand_1=rand();
                    rand_2=rand();
                    rand_3=rand();

                    rand_1=rand_1%20;
                    rand_2=rand_2%20;
                    rand_3=rand_3%20;

                    output(i,j)->Red=255-rand_1;
                    output(i,j)->Green=255-rand_2;
                    output(i,j)->Blue=255-rand_3;
                }


                if(map[i][j]==stein){
                    output(i,j)->Red=60;
                    output(i,j)->Green=30;
                    output(i,j)->Blue=10;
                }

                if(map[i][j]==dungeon){
                    output(i,j)->Red=150;
                    output(i,j)->Green=50;
                    output(i,j)->Blue=150;
                }


                if(map[i][j]==kiste){
                    output(i,j)->Red=255;
                    output(i,j)->Green=255;
                    output(i,j)->Blue=0;
                }

                if(map[i][j]==npc){
                    output(i,j)->Red=0;
                    output(i,j)->Green=255;
                    output(i,j)->Blue=0;
                }


                if(map[i][j]==seltenekiste){
                    output(i,j)->Red=255;
                    output(i,j)->Green=255;
                    output(i,j)->Blue=0;
                }

                if(map[i][j]==wasser){                      // Wasser Randomize ebenfalls mit Lava Variablen    !!!!

                    lava_rand_1=rand();
                    lava_rand_2=rand();
                    lava_rand_3=rand();

                    lava_rand_1=lava_rand_1%60;
                    lava_rand_2=lava_rand_2%60;
                    lava_rand_3=lava_rand_3%60;

                    lava_rand_1=lava_rand_1%-30;
                    lava_rand_2=lava_rand_2%-30;
                    lava_rand_3=lava_rand_3%-30;


                    output(i,j)->Red=30+lava_rand_1;
                    output(i,j)->Green=30+lava_rand_2;
                    output(i,j)->Blue=200+lava_rand_3;
                }


                if(map[i][j]==superseltenekiste){
                    output(i,j)->Red=255;
                    output(i,j)->Green=255;
                    output(i,j)->Blue=0;
                }


                if(map[i][j]==lava){

                    lava_rand_1=rand();
                    lava_rand_2=rand();
                    lava_rand_3=rand();

                    lava_rand_1=lava_rand_1%60;
                    lava_rand_2=lava_rand_2%60;
                    lava_rand_3=lava_rand_3%60;

                    lava_rand_1=lava_rand_1%-30;
                    lava_rand_2=lava_rand_2%-30;
                    lava_rand_3=lava_rand_3%-30;


                    output(i,j)->Red=150+lava_rand_1;
                    output(i,j)->Green=30+lava_rand_2;
                    output(i,j)->Blue=50+lava_rand_3;
                }


            }


        }

    output(501,502)->Red=100;
    output(501,502)->Green=200;
    output(501,502)->Blue=240;

    output(500,502)->Red=100;
    output(500,502)->Green=200;
    output(500,502)->Blue=240;

    output(501,501)->Red=100;
    output(501,501)->Green=200;
    output(501,501)->Blue=240;

    output(501,503)->Red=100;
    output(501,503)->Green=200;
    output(501,503)->Blue=240;

    output(502,502)->Red=100;
    output(502,502)->Green=200;
    output(502,502)->Blue=240;

    output(502,503)->Red=100;
    output(502,503)->Green=200;
    output(502,503)->Blue=240;

    output(502,501)->Red=100;
    output(502,501)->Green=200;
    output(502,501)->Blue=240;

    output(500,503)->Red=100;
    output(500,503)->Green=200;
    output(500,503)->Blue=240;

    output(500,501)->Red=100;
    output(500,501)->Green=200;
    output(500,501)->Blue=240;

    output.WriteToFile("Output.bmp");

}



void MapNew(){              // veraltet für zentrierte Charakteransicht; benötigt ->    int Farbe(int);

    int i=2;
    int j=2;

    while(i<77){
        while(j<23){
            Curpos(i,j);
            cout << " ";
            j++;
        }
        j=2;
        i++;
    }
/*
    Curpos(1,1);
    cout << "                         ";
    Curpos(1,1);
    cout << "xV=" << char_x_versatz << "   yV=" << char_y_versatz;
*/
    i=2;
    j=2;



    char stein=219;
    char kiste=254;
    char lava=176;
    char seltenekiste=184;
    char charakter=1;
    char superseltenekiste=244;
    char dungeon=36;

    while(j<23){
        while(i<77){
            Curpos(i,j);
            if(map[462+i+char_x_versatz][490+j+char_y_versatz]==stein){            // stein vom Typ char mit dem wert 219 (Vollblock)
                Farbe(8);
                cout << map[462+i+char_x_versatz][490+j+char_y_versatz];
            }
            else if(map[462+i+char_x_versatz][490+j+char_y_versatz]==kiste){
                Farbe(14);
                cout << map[462+i+char_x_versatz][490+j+char_y_versatz];
            }

            else if(map[462+i+char_x_versatz][490+j+char_y_versatz]==lava){
                Farbe(12);
                cout << map[462+i+char_x_versatz][490+j+char_y_versatz];
            }

            else if(map[462+i+char_x_versatz][490+j+char_y_versatz]==seltenekiste){
                Farbe(11);
                cout << map[462+i+char_x_versatz][490+j+char_y_versatz];
            }

            else if(map[462+i+char_x_versatz][490+j+char_y_versatz]==superseltenekiste){
                Farbe(10);
                cout << map[462+i+char_x_versatz][490+j+char_y_versatz];
            }

            else if(map[462+i+char_x_versatz][490+j+char_y_versatz]==dungeon){
                Farbe(13);
                cout << map[462+i+char_x_versatz][490+j+char_y_versatz];
            }
/*
            else{
                Farbe(4);
                cout << map[462+i][490+j];
            }
*/          Sleep(1000);
            i++;
        }
        i=2;
        j++;
    }


    Curpos(39,12);
    Farbe(15);
    cout << charakter;

}



void WorldGenerate(void){   // Generiert die Weltkarte in die Globale Variable ->    char map[1000][1000]

    int rand_map_box=0;
    int rand_map_help=0;
    int i=0;
    int j=0;
    int help=0;

    char stein=219;
    char kiste=254;
    char lava=176;
    char wasser=177;
    char seltenekiste=184;
    char charakter=1;
    char superseltenekiste=244;
    char dungeon=36;
    char npc=2;

    int lava_random=0;
    int lava_random2=0;
    int lava_random3=0;


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    while(i<1000){          // Map wird komplett auf 32 (Leerzeichen) gesetzt
        while(j<1000){
            map[i][j]=32;
            j++;
        }
        j=0;
        i++;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Farbe(7);
    RahmenMap();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    i=0;
    j=0;
    while(i<=999){                                          // Generierung der Steine
        while(j<=999){
            rand_map_box=rand();
            rand_map_help=rand();
            rand_map_help=rand_map_help%10+1;
            rand_map_box=rand_map_box%rand_map_help;
            if(rand_map_box==0){
                map[i][j]=219;
            }
            j++;
        }
        j=0;
        i++;
    }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    i=0;
    j=0;
    while(i<=999){                                          // Generierung der KISTEN
        while(j<=999){
            rand_map_box=rand();
            rand_map_help=rand();
            rand_map_help=rand_map_help%2000+1;
            rand_map_box=rand_map_box%rand_map_help;
            if(rand_map_box==0){
                map[i][j]=254;
            }
            j++;
        }
        j=0;
        i++;
    }


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    i=0;
    j=0;
    while(i<=999){                                          // Generierung der NPCs
        while(j<=999){
            rand_map_box=rand();
            rand_map_help=rand();
            rand_map_help=rand_map_help%20000+1;
            rand_map_box=rand_map_box%rand_map_help;
            if(rand_map_box==0){
                map[i][j]=npc;
            }
            j++;
        }
        j=0;
        i++;
    }


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    i=0;
    j=0;
    while(i<=999){                                          // Generierung des WASSERS
        while(j<=999){
            rand_map_box=rand();
            rand_map_help=rand();
            rand_map_help=rand_map_help%700+1;
            rand_map_box=rand_map_box%rand_map_help;
            if(rand_map_box==0){
                map[i][j]=177;
            }
            j++;
        }
        j=0;
        i++;
    }


    i=10;
    j=10;

    while(i<=990){                                          // Generierung der WASSER POOLS
        while(j<=990){
            if(map[i][j]==wasser){
                lava_random=rand();
                lava_random=lava_random%100+1;

                while(lava_random>0){

                    lava_random2=rand();
                    lava_random2=lava_random2%12;
                    lava_random2=lava_random2-6;

                    lava_random3=rand();
                    lava_random3=lava_random3%12;
                    lava_random3=lava_random3-6;

                    map[i+lava_random3][j+lava_random2]=wasser;
                    lava_random--;
                }
            }

            j=j+5;
        }
        j=10;
        i=i+5;
    }




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    i=0;
    j=0;
    while(i<=999){                                          // Generierung der LAVA
        while(j<=999){
            rand_map_box=rand();
            rand_map_help=rand();
            rand_map_help=rand_map_help%700+1;
            rand_map_box=rand_map_box%rand_map_help;
            if(rand_map_box==0){
                map[i][j]=176;
            }
            j++;
        }
        j=0;
        i++;
    }


    i=10;
    j=10;

    while(i<=990){                                          // Generierung der LAVApools
        while(j<=990){
            if(map[i][j]==lava){
                lava_random=rand();
                lava_random=lava_random%80+1;

                while(lava_random>0){

                    lava_random2=rand();
                    lava_random2=lava_random2%12;
                    lava_random2=lava_random2-6;

                    lava_random3=rand();
                    lava_random3=lava_random3%12;
                    lava_random3=lava_random3-6;

                    map[i+lava_random3][j+lava_random2]=lava;
                    lava_random--;
                }
            }

            j=j+5;
        }
        j=10;
        i=i+5;
    }



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    i=0;
    j=0;
    while(i<=999){                                          // Generierung der seltenen Kisten (r)
        while(j<=999){
            rand_map_box=rand();
            rand_map_help=rand();
            rand_map_help=rand_map_help%10000+1;
            rand_map_box=rand_map_box%rand_map_help;
            if(rand_map_box==0){
                map[i][j]=184;
            }
            j++;
        }
        j=0;
        i++;
    }





//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    i=0;
    j=0;

    while(i<=999){                                          // Generierung der superseltenen Kisten
        while(j<=999){
            help=rand();
            help=help%10;
            rand_map_box=rand();
            rand_map_help=rand();
            rand_map_help=rand_map_help%10000+1;
            rand_map_box=rand_map_box%rand_map_help;
            if(rand_map_box==0 && help==5){
                map[i][j]=244;
            }
            j++;
        }
        j=0;
        i++;
    }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



    i=25;
    j=25;
    while(i<=930){                                          // Generierung der dungeons
        while(j<=930){
            rand_map_box=rand();
            rand_map_help=rand();
            rand_map_help=rand_map_help%2000+1;
            rand_map_box=rand_map_box%rand_map_help;
            if(rand_map_box==0){
                CreateDungeon(i,j);
            }
            j=j+11;
        }
        j=25;
        i=i+10;
    }



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    map[501][502]=32;           // Spawn frei
    map[502][502]=32;
    map[500][502]=32;
    map[501][501]=32;
    map[501][503]=32;


    i=2;
    j=2;

    while(j<23){
        while(i<77){
            Curpos(i,j);
            if(map[462+i][490+j]==stein){            // stein vom Typ char mit dem wert 219 (Vollblock)
                Farbe(8);
                cout << map[462+i][490+j];
            }
            else if(map[462+i][490+j]==kiste){
                Farbe(14);
                cout << map[462+i][490+j];
            }

            else if(map[462+i][490+j]==lava){
                Farbe(12);
                cout << map[462+i][490+j];
            }

            else if(map[462+i][490+j]==seltenekiste){
                Farbe(11);
                cout << map[462+i][490+j];
            }

            else if(map[462+i][490+j]==superseltenekiste){
                Farbe(10);
                cout << map[462+i][490+j];
            }

            else if(map[462+i][490+j]==dungeon){
                Farbe(13);
                cout << map[462+i][490+j];
            }

            else if(map[462+i][490+j]==wasser){
                Farbe(25);
                cout << map[462+i][490+j];
            }

            else if(map[462+i][490+j]==npc){

                Farbe(2);
                cout << map[462+i][490+j];
            }

            else{
                Farbe(4);
                cout << map[462+i][490+j];
            }

            i++;
        }
        i=2;
        j++;
    }

    Curpos(39,12);
    Farbe(15);
    cout << charakter;
}



void CreateDungeon(int x, int y){
    int rand_1=0;
    int rand_2=0;

    for(int m=0; m<21; m++){
        for(int n=0; n<21; n++){
            map[x-10+n][y-10+m]=32;
        }
    }

    for(int m2=0; m2<10; m2++){
        rand_1=rand();
        rand_2=rand();
        rand_1=rand_1%20;
        rand_2=rand_2%20;
        rand_1=rand_1-10;
        rand_2=rand_2-10;
        map[x+rand_1][y+rand_2]=254;
    }
   // map[x,y]=244;


   for(int m4=0; m4<5; m4++){
        rand_1=rand();
        rand_2=rand();
        rand_1=rand_1%20;
        rand_2=rand_2%20;
        rand_1=rand_1-10;
        rand_2=rand_2-10;
        map[x+rand_1][y+rand_2]=184;
    }

   map[x][y]=244;


   for(int m4=0; m4<21; m4++){              // Die 4 for funktionen ziehen den DOLLAR-Zeichen Rahmen um den Dungeon
        map[x-10+m4][y-10]=36;
   }

   for(int m5=0; m5<21; m5++){
        map[x-10+m5][y+10]=36;
   }

   for(int m6=0; m6<21; m6++){
        map[x-10][y-10+m6]=36;
   }

   for(int m7=0; m7<21; m7++){
        map[x+10][y-10+m7]=36;
   }

   for(int m8=0; m8<6; m8++){
        rand_1=rand();
        rand_2=rand();
        rand_1=rand_1%17+2;
        rand_2=rand_2%17+2;
        map[x-10+rand_1][y-10]=32;
        map[x-10][y-10+rand_2]=32;
   }


   for(int m9=0; m9<6; m9++){
        rand_1=rand();
        rand_2=rand();
        rand_1=rand_1%17+2;
        rand_2=rand_2%17+2;
        map[x+10-rand_1][y+10]=32;
        map[x+10][y+10-rand_2]=32;
   }

}



void MapNew2(){             // aktuelle Funktion für Smiley auf Karte bzw nächster Abschnitt
    char charakter=1;

    if(char_map_x==0){
        char_map_offset_x=char_map_offset_x-1;
        LeerKomplett();
        char_map_x=75;
        MapNew2Rand();
        Curpos(char_map_x+1,char_map_y+1);
        Farbe(15);
        cout << charakter;
        RahmenMap();
    }

    else if(char_map_x==76){
        LeerKomplett();
        char_map_x=1;
        char_map_offset_x=char_map_offset_x+1;
        MapNew2Rand();
        Curpos(char_map_x+1,char_map_y+1);
        Farbe(15);
        cout << charakter;
        RahmenMap();
    }

    else if(char_map_y==0){
        char_map_offset_y=char_map_offset_y-1;
        LeerKomplett();
        char_map_y=21;
        MapNew2Rand();
        Curpos(char_map_x+1,char_map_y+1);
        Farbe(15);
        cout << charakter;
        RahmenMap();
    }

    else if(char_map_y==22){
        char_map_offset_y=char_map_offset_y+1;
        LeerKomplett();
        char_map_y=1;
        MapNew2Rand();
        Curpos(char_map_x+1,char_map_y+1);
        Farbe(15);
        cout <<charakter;
        RahmenMap();
    }

    else{
        Curpos(char_map_x+1, char_map_y+1);
        Farbe(15);
        cout << charakter;
    }

}



void MapNew2Rand(){

    int i=2;
    int j=2;
    LeerKomplett();

    char stein=219;
    char leer=32;
    char kiste=254;
    char lava=176;
    char seltenekiste=184;
    char charakter=1;
    char superseltenekiste=244;
    char dungeon=36;
    char wasser=177;
    char npc=2;

    int help1=0;
    int help2=0;

    help1=char_map_offset_x*73;
    help2=char_map_offset_y*19;

    help1=help1+464;
    help2=help2+492;

    while(i<78){
        while(j<24){
            Curpos(i,j);



            if(map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j]==stein){            // stein vom Typ char mit dem wert 219 (Vollblock)
                Farbe(8);
                Curpos(i,j);
                cout << map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j];
            }

            else if(map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j]==kiste){
                Farbe(14);
                Curpos(i,j);
                cout << map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j];
            }

            else if(map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j]==lava){
                Farbe(12);
                Curpos(i,j);
                cout << map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j];
            }

            else if(map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j]==npc){
                Farbe(2);
                Curpos(i,j);
                cout << map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j];
            }

            else if(map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j]==seltenekiste){
                Farbe(11);
                Curpos(i,j);
                cout << map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j];
            }

            else if(map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j]==superseltenekiste){
                Farbe(10);
                Curpos(i,j);
                cout << map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j];
            }

            else if(map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j]==dungeon){
                Farbe(13);
                Curpos(i,j);
                cout << map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j];
            }

            else if(map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j]==wasser){
                Farbe(25);
                Curpos(i,j);
                cout << map[462+i+(char_map_offset_x*75)][490+(char_map_offset_y*21)+j];
            }


          //  else{
          //      Farbe(4);
          //      cout << map[462+i][490+j];


            j++;
        }

        j=2;
        i++;
    }

}









//************************************************************************************************************************************************************






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

        else if(eingabe==105){
            Inventar();
        }

        return 0;
}






//*************************************************************************************************************************************************


int RichtungTest2(int richtung){


    Curpos(75,0);
    cout << "   ";

    char npc=2;
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






