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


int Zufallsfarbe();
extern int zaubertextzeilen;



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



void Randomcounter(){                    // Toter Code zur Anzeige der Verteilung der Seltenheitsstufen
    int crot=0;
    int cgrau=0;
    int cweiss=0;
    int cblau=0;
    int cgruen=0;
    int clila=0;
    int cgelb=0;
    int cspecial=0;
    int momentan=0;

    int k=0;


    while(k<100000){
        momentan=Zufallsfarbe();

        if(momentan==8){
            cgrau++;
        }

        if(momentan==13){
            clila++;
        }

        if(momentan==10){
            cgruen++;
        }

        if(momentan==9){
            cblau++;
        }

        if(momentan==15){
            cweiss++;
        }

        if(momentan==12){
            crot++;
        }

        if(momentan==14){
            cgelb++;
        }

        if(momentan==24){
            cspecial++;
        }


        k++;

    }


    Curpos(25,8);
    cout << "Grau: " << cgrau << endl;
    Curpos(25,9);
    cout << "Weiss: " << cweiss << endl;
    Curpos(25,10);
    cout << "Grün: " << cgruen << endl;
    Curpos(25,11);
    cout << "Blau: " << cblau << endl;
    Curpos(25,12);
    cout << "Lila: " << clila << endl;
    Curpos(25,13);
    cout << "Rot: " << crot <<  endl;
    Curpos(25,14);
    cout << "Gelb: " << cgelb <<  endl;
    Curpos(25,15);
    cout << "Special: " << cspecial <<  endl;


}


int Zufall(){
     int i = rand();
     i=(i%10000)+1;
return i;
}




int Zufallsfarbe(){
    int output=0;
    int bonus = rand();
    bonus=bonus%10;
    int zufallsfarbe=0;
    zufallsfarbe = Zufall();


    if(zufallsfarbe<=4000){      //grau
        output=8;
        zaubertextzeilen=0;
        return output;
    }

    if(zufallsfarbe>4000 && zufallsfarbe<=7000){      //weiß
        output=15;
        zaubertextzeilen=0;
        return output;
    }

    if(zufallsfarbe>7000 && zufallsfarbe<=8750){      //grün
        output=10;
        zaubertextzeilen=1;
        return output;
    }

    if(zufallsfarbe>8750 && zufallsfarbe<=9500){      //blau
        output=9;
        zaubertextzeilen=2;
        return output;
    }

    if(zufallsfarbe>9500 && zufallsfarbe<=9950){      //lila
        output=13;
        zaubertextzeilen=3;
        return output;
    }

    if(zufallsfarbe>9950 && zufallsfarbe <=9990){      //rot
        output=12;
        zaubertextzeilen=4;
        return output;
    }

    if(zufallsfarbe>9990 && zufallsfarbe <=9999){      //gelb
        output=14;
        zaubertextzeilen=6;
        return output;
    }

    if(zufallsfarbe==10000){      //hintergrund Ultra Rare
        if(bonus==5){
            output=24;
            zaubertextzeilen=10;
            return output;
        }

        else if(bonus != 5){
            output=14;
            zaubertextzeilen=6;
            return output;
        }
    }
    return 0;

}
