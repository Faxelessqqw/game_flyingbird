#include "TXLib.h"

using namespace std;


struct Button
{
    int x;
    int y;
    int w;
    int h;
    const char* text;

    void draw()
    {
        txSetColor (TX_WHITE, 3);
        txSetFillColor (TX_YELLOW);
        Win32::RoundRect (txDC(), x, y, x+w, y+h, 15, 15);
        txSelectFont("Times New Roman", 30);
        txSetColor (TX_RED);
        txDrawText(x, y, x+w, y+h, text);
    }

    bool click()
    {
        return(txMouseX()>x && txMouseX()<x+w &&
                txMouseY()>y && txMouseY()<y+h &&
                txMouseButtons() == 1);
    }
};



int main()  {

txCreateWindow (800, 600);
txTextCursor (false);

    int x=430;
    int y=140;

    string PAGE="menu";




    Button btn0 = {100, 100, 120, 40, "Старт"};
    Button btn1 = {100, 160, 120, 40, "Выход"};

    HDC pole = txLoadImage("location.bmp");
    HDC birdA_1 = txLoadImage("bird_1.bmp");
    HDC birdA_2 = txLoadImage("bird_2.bmp");
    HDC birdAZ_1 = txLoadImage("bird_1_zerk.bmp");
    HDC birdAZ_2 = txLoadImage("bird_2_zerk.bmp");
    HDC nebo = txLoadImage("nebo.bmp");


    //Pole pole1={-150,230,300,93,100,31,txLoadImage("location.bmp")}   ;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {

        txBegin();

        txSetFillColor (TX_WHITE);
        txRectangle(0,0,800,600);



        btn0.draw();
        if (btn0.click())
        {
            PAGE="game";
        }


        if (PAGE=="game")
        {
            txBitBlt(txDC(),0,0,800,600,pole);


            txBitBlt(txDC(),x,y,800,600,birdA_1);
            txSleep(70);
            txBitBlt(txDC(),x,y,800,600,birdA_2);


            if (GetAsyncKeyState('A'))
            {
                x=x-10;
            }

            if (GetAsyncKeyState('W'))
            {
                y=y-10;
            }

            if (GetAsyncKeyState('D'))
            {
                x=x+10;

            }

            if (GetAsyncKeyState('S'))
            {
                y=y+10;
            }

            if (x<0)
            {
                PAGE="Llist";
            }

        }


        if (PAGE=="Llist")
        {
            txBitBlt(txDC(),0,0,800,600,nebo);

            txBitBlt(txDC(),x,y,800,600,birdA_1);
            txSleep(70);
            txBitBlt(txDC(),x,y,800,600,birdA_2);


            if (GetAsyncKeyState('A'))
            {
                x=x-10;
            }

            if (GetAsyncKeyState('W'))
            {
                y=y-10;
            }

            if (GetAsyncKeyState('D'))
            {
                x=x+10;

            }

            if (GetAsyncKeyState('S'))
            {
                y=y+10;
            }

            if (x<0)
            {
              x=x+15;
            }


            if (x>750)
            {
              PAGE="game";
            }

        }

        txEnd();



    }

    //x=430;
    //y=140;



txDisableAutoPause();
return 0;
}

