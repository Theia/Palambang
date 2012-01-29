#ifndef GEGENSTANDSGENERIERUNG_H_INCLUDED
#define GEGENSTANDSGENERIERUNG_H_INCLUDED


struct GegenstandInfo{
    int verzauberung;
    int gegenstandID;
    int gegenstand_number_enchant;
};

struct Geld{
    int Steine;
    int Gold;
    int Diamanten;
    int Quarks;
};



struct GegenstandInfo Gegenstand(int, int);
int Verzauberung(int, int);
int Zaubertext(int, int);
int Leer(void);
void BZauber(int);
void BName(int);
void BStats(int, int);
void AusgabeGeldConv(Geld);
Geld GeldConv(int);
int Gegenstand_Waffe(int);
int Gegenstand_Ruestung(int);
int Zaubertext(int,int);


#endif // GEGENSTANDSGENERIERUNG_H_INCLUDED
