#include <windows.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "funktion.h"
#include "Bilder.h"
#include "Gegenstandsgenerierung.h"


GegenstandInfo item = {0,0,0};



using namespace std;


struct GegenstandInfo Gegenstand(int zaubertextzeilen_gegenstand, int anzeige){            //anzeige = 0 -> es wird angezeigt , anzeigt = 1, wird nicht angezeigt d.h. Bild() wird nicht ausgeführt

    int gegenstand=0;
    int gegenstand_wert=0;

     int i = rand();
     i=i%2;                 // Waffe, Rüstung


         if(i==0){
            gegenstand=Gegenstand_Waffe(anzeige);      // gegenstand für Bilder.cpp zur Darstellung über funktion int Bild(int gegenstandID)
         }

         if(i==1){
            gegenstand=Gegenstand_Ruestung(anzeige);
         }


    gegenstand_wert=Verzauberung(zaubertextzeilen_gegenstand, anzeige);
    if(anzeige==0){
        Bild(gegenstand);
    }

    item.gegenstandID=gegenstand;
    item.gegenstand_number_enchant=gegenstand_wert;


return item;
}

//***************************************************************************************************************

int Gegenstand_Waffe(int anzeige){
    string Waffe[5];
    Waffe[0]= "Schwert";
    Waffe[1]= "Dolch";
    Waffe[2]= "Degen";
    Waffe[3]= "Streitkolben";
    Waffe[4]= "Hammer";
    int i2 = rand();
    i2=i2%5;
    if(anzeige==0){
        cout << Waffe[i2] << " ";
    }

    // if(zaubertextzeilen>0){
    //    cout << "blaverzauberungbla";
    // }

    return i2;

}

//***************************************************************************************************************

int Gegenstand_Ruestung(int anzeige){
    string Ruestung[5];
    Ruestung[0]= "Helm";
    Ruestung[1]= "Schild";
    Ruestung[2]= "Stiefel";
    Ruestung[3]= "Handschuhe";
    Ruestung[4]= "Hose";
    int i2 = rand();
    i2=i2%5;
    if(anzeige==0){
        cout << Ruestung[i2] << " ";
    }
    return i2+100;

}

//***************************************************************************************************************

int Verzauberung(int zaubertextzeilen, int anzeige){

    if(zaubertextzeilen>0){

         string Verzauberung[5];
         Verzauberung[0]= "der Magie";
         Verzauberung[1]= "der Verteidigung";
         Verzauberung[2]= "des Grauens";
         Verzauberung[3]= "der Hoffnung";
         Verzauberung[4]= "der Legende";

         int gegenstand_wert=0;



         int i3 = rand();
         i3=i3%5;

         item.verzauberung=i3;

         if(anzeige==0){
            cout <<  Verzauberung[i3] << endl;
         }

         gegenstand_wert=Zaubertext(i3, anzeige);            // jetzt steht die Menge der Verzauberung drin z.b. 23 bei + 23 Verteidigung
         //gegenstand_wert=1000
         return gegenstand_wert;

    }

    else{
        if(anzeige==0){
            Curpos(20,0);
            cout << "    ";
        }
        return 0;
    }


}

//***************************************************************************************************************
//***************************************************************************************************************
//***************************************************************************************************************
//***************************************************************************************************************
//***************************************************************************************************************

int Leer(){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 1);
    Curpos(25,7);
    int i=1;
    while(i<9){

        cout << "                                  ";
        Curpos(25,7+i);

        i++;
    }
    Curpos(25,7);
    return 0;
}

//***************************************************************************************************************

void BZauber(int type){
    string Verzauberung[5];
    Verzauberung[0]= "der Magie";
    Verzauberung[1]= "der Verteidigung";
    Verzauberung[2]= "des Grauens";
    Verzauberung[3]= "der Hoffnung";
    Verzauberung[4]= "der Legende";
    cout << " " << Verzauberung[type];
}

//***************************************************************************************************************

void BName(int gegenstandID){
    switch(gegenstandID){
        case 0: cout << "Schwert"; break;
        case 1: cout << "Dolch"; break;
        case 2: cout << "Degen"; break;
        case 3: cout << "Streitkolben"; break;
        case 4: cout << "Hammer"; break;
        case 100: cout << "Helm"; break;
        case 101: cout << "Schild"; break;
        case 102: cout << "Stiefel"; break;
        case 103: cout << "Handschuhe"; break;
        case 104: cout << "Hose"; break;
    }
}

//***************************************************************************************************************

void AusgabeGeldConv(Geld input){
    if(input.Quarks>0){
        if(input.Quarks>1){
            cout << input.Quarks << " Quarks, ";
        }

        if(input.Quarks==1){
            cout << input.Quarks << " Quark, ";
        }
    }

    if(input.Diamanten>0){
        if(input.Diamanten>1){
            cout << input.Diamanten << " Diamanten, ";
        }

        if(input.Diamanten==1){
            cout << input.Diamanten << " Diamant, ";
        }
    }

    if(input.Gold>0){
            cout << input.Gold << " Gold, ";
        }


    if(input.Steine>0){
        if(input.Steine>1){
            cout << input.Steine << " Steine";
        }

        if(input.Steine==1){
            cout << input.Steine << " Stein";
        }
    }
}

//***************************************************************************************************************

void BStats(int menge, int name){
    Curpos(25,9);
    switch(name){

                case 0: cout << "+ " << menge << " Intelligenz";
                        break;

                case 1: cout << "+ " << menge << " Ruestung";
                        break;

                case 2: cout << "+ " << menge << " Angriffskraft";
                        break;

                case 3: cout << "+ " << menge << " Willenskraft";
                        break;

                case 4: cout << "+ " << menge << " Lebenspunkte";
                        break;
            }
}

//***************************************************************************************************************

Geld GeldConv(int input){
    Geld output={0,0,0};

    while(input>=1000000){          // 100.00.00 Quarks
        output.Quarks=output.Quarks+1;
        input=input-1000000;
    }

    while(input>=10000){     // 100.00 Diamanten
        output.Diamanten=output.Diamanten+1;
        input=input-10000;
    }

    while(input>=100){     // 100 Gold
        output.Gold=output.Gold+1;
        input=input-100;
    }

    output.Steine=input;

    return output;
}



















// - - - GENERATE


/* while(int n=1){
        Sleep(50);
        if(kbhit()){

            int holder = getch();

            if(holder==100){            // 100 = d
                if(debug==0){
                     debug=1;
                }

                else if(debug==1){
                    debug=0;
                    Curpos(0,0);
                    cout << "    ";
                }
            }


            if(holder==45){         // Minuszeichen bzw. Bindestrich
                Curpos(28,22);
                float input=0;
                int fortschritt=0;
                cout << "Wie oft? -> ";
                cin >> input;
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
                cout << "Wertvollster Gegenstand: ";
                AusgabeGeldConv(wert_Conv);

                hide_bild=0;

            }

            else{
                if(debug==1){
                    Curpos(0,0);
                    cout << "    ";
                    Curpos(0,0);
                    cout << holder;
                }

            Curpos(1,2);
            cout << "                                                                  ";

                // Randomcounter();

                Leer();
                farbe=Farbe(Zufallsfarbe());
                wert=FarbeConv(farbe);
                Curpos(25,7);

                halter=Gegenstand(zaubertextzeilen, hide_bild);
                mengeverzauberungen=halter.gegenstand_number_enchant;
                wert_einser=rand();
                wert_einser=wert_einser%40;
                wert_einser=wert_einser-20;
                wert=(1000*wert)+(mengeverzauberungen*wert*100)+wert_einser;

                Curpos(1,1);
                cout << "                                                       ";
                Curpos(1,1);
                wert_Conv=GeldConv(wert);
                cout << "Wert des Gegenstandes: ";
                AusgabeGeldConv(wert_Conv);


                Farbe(14);
                Curpos(25,18);
                cout << "Generated by Oertel";

                Farbe(15);
                Curpos(22,0);
            }
        }
    } */
