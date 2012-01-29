//******************************************************************************//
//    \file   funcs.h															//
//    \author Daniel Panster													//
//    \brief  Hauptfunktionen													//
//******************************************************************************//
#ifndef _FUNCS_H_
#define _FUNCS_H_

void Textcolor(unsigned short color = 15);
void Curpos(unsigned short x,unsigned short y);
void Spirale(void);


#endif














/*

int main()
{

    double positiony=0;
    unsigned short zeigery=0;
    double positionx=0;
    unsigned short zeigerx=0;
    unsigned short altx=0;
    unsigned short alty=0;

    cout << "Click @ this ---->    O" << endl;


    INPUT_RECORD inRec;
    HANDLE hcon = GetStdHandle(STD_INPUT_HANDLE);
    RECT *rect = (RECT*)malloc(sizeof(RECT));
    POINT mPos;
    int mPosinConsleX = mPos.x - (rect->left);
    int mPosinConsleY = mPos.y - (rect->top);

    HWND hwnd = FindWindow("ConsoleWindowClass",NULL);



    while(true)
    {
       GetCursorPos(&mPos);
       GetWindowRect(hwnd,rect);
       mPosinConsleY = mPos.y - (rect->top);
       mPosinConsleX = mPos.x - (rect->left);
       Curpos(0,0);
       cout << "X =   " << mPosinConsleX << "     Y =    " << mPosinConsleY << "    " << endl;


       Sleep(25);

       Curpos(altx,alty);
       cout << " ";

        //645 + 325


    if(mPosinConsleX<=645 && mPosinConsleY<=325 && mPosinConsleX>10 && mPosinConsleY >31){

       positiony=(mPosinConsleY-31)/12;
       zeigery=(unsigned short)positiony;

       positionx=(mPosinConsleX-10)/8;
       zeigerx=(unsigned short)positionx;

       altx=zeigerx;
       alty=zeigery;

      // system("cls");

       Curpos(zeigerx,zeigery);
       cout << "o";


    }


____________


       if (mPosinConsleX > 180 && mPosinConsleX < 190)
       {
          if (mPosinConsleY > 32 && mPosinConsleY < 41)
          {
             DWORD nCnt = 0;
             BOOL bOK = ReadConsoleInput(hcon, &inRec, 1, &nCnt);
             if(bOK && nCnt == 1)
             {
                if(inRec.EventType == MOUSE_EVENT)
                {
                   if(inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                   cout << "Du hast auf den Kreis gedrueckt" << endl;

                }
              }
           }
       }




    getch();
    return 0;
}


*/
