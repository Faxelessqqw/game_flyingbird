#include "TXLib.h"

using namespace std;


int SCH=0;

string itapG="game";

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




    Button btn0 = {330, 190, 120, 40, "�����"};
    Button btn1 = {330, 230, 120, 40, "�����"};

    HDC pole = txLoadImage("location.bmp");
    HDC astr_world = txLoadImage("astr_world.bmp");
    HDC birdA_1 = txLoadImage("bird_1.bmp");
    HDC birdA_2 = txLoadImage("bird_2.bmp");
    HDC birdA_1_astrW = txLoadImage("bird_1_astr_world.bmp");
    HDC birdA_2_astrW = txLoadImage("bird_2_astr_world.bmp");
    HDC birdAZ_1 = txLoadImage("bird_1_zerk.bmp");
    HDC birdAZ_2 = txLoadImage("bird_2_zerk.bmp");
    HDC nebo = txLoadImage("nebo.bmp");
    HDC cityP = txLoadImage("cityP.bmp");
    HDC bird_CP = txLoadImage("bird_CP.bmp");
    HDC space_1 = txLoadImage("SPACE_1.bmp");
    HDC space_2 = txLoadImage("SPACE_2.bmp");
    HDC astr_priz = txLoadImage("astr_priz.bmp");


    //Pole pole1={-150,230,300,93,100,31,txLoadImage("location.bmp")}   ;

    while (!GetAsyncKeyState(VK_F9))
    {

        txBegin();

        txSetFillColor (TX_WHITE);
        txRectangle(0,0,800,600);


        if (PAGE=="menu");
        {
            btn0.draw();
            btn1.draw();
            if (btn0.click())
            {
                PAGE=itapG;
            }


            if (btn1.click())
            {

            }
        }

        if (GetAsyncKeyState(VK_ESCAPE))
        {
          PAGE="menu";
        }

        if (PAGE=="game")
        {
            itapG="game";
            txBitBlt(txDC(),0,0,800,600,pole);




            txBitBlt(txDC(),x,y,800,600,birdA_1);
            txSleep(70);
            txBitBlt(txDC(),x,y,800,600,birdA_2);
            txSleep(70);


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

            if (x>760)
            {
                PAGE="Rlist";
            }

        }


        if (PAGE=="Llist")
        {

            itapG="Llist";
            txBitBlt(txDC(),0,0,800,600,nebo);

            txBitBlt(txDC(),x,y,800,600,birdA_1);
            txSleep(70);
            txBitBlt(txDC(),x,y,800,600,birdA_2);
            txSleep(70);


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

            if (y>550)
            {
              y=y-15;
            }

            if (y<0)
            {
              y=y+15;
            }


        }

        if (PAGE=="Rlist")
        {

            itapG="Rlist";
            txBitBlt(txDC(),0,0,800,600,nebo);

            txBitBlt(txDC(),x,y,800,600,birdA_1);
            txSleep(70);
            txBitBlt(txDC(),x,y,800,600,birdA_2);
            txSleep(70);


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

            if (x>730)
            {
              x=x-15;
            }


            if (x<50)
            {
              PAGE="game";

            }


            if (x<600 && x>700 && y>550)
            {
              y=y-15;
            }

            if (y<0)
            {
              y=y+15;
            }


            if (x>600 && x<700 && y>550)
            {
                PAGE="cityP";


            }


        }
        if (PAGE=="cityP")
        {
            itapG="cityP";
            x=100;
            y=20;

            PAGE="cityP!";
            Sleep(200);

        }


        if (PAGE=="cityP!")
        {

            itapG="cityP!";
            txBitBlt(txDC(),0,0,800,600,cityP);

            txBitBlt(txDC(),x,y,800,600,bird_CP);


            x=100;
            y=20;


            if (GetAsyncKeyState(VK_SPACE))
            {
               SCH=SCH+1;
               txSleep(100);
            }

            txBitBlt(txDC(),340,500,500,590,space_1);
            txSleep(250);
            txBitBlt(txDC(),340,500,500,590,space_2);
            txSleep(250);


            if (SCH==10)
            {
                PAGE="con_1";
            }


        }

        if (PAGE=="con_1")
        {

            itapG="con_1";
            txSetColor(TX_BLACK);
            txSetFillColor(TX_BLACK);
            txRectangle(0,0,800,600);

            txSetColor(TX_GREY,5);
            txRectangle(50,50,150,150);
            txSetFillColor(TX_GREY);
            txRectangle(150,50,700,150);
            txBitBlt(txDC(),75,75,800,600,bird_CP);


            txSetColor(TX_BLACK);
            txSetFillColor(TX_BLACK);
            txSelectFont("Ink Free",20);
            txTextOut(200,60,"parrot:��� �?");
            txTextOut(600,130,"Press ""E""");


            if (GetAsyncKeyState('E'))
            {
              while(GetAsyncKeyState('E'))  txSleep(20);
              PAGE="astr_priz";
            }



        }

        if (PAGE=="astr_priz")
        {
            itapG="astr_priz";
            txSetColor(TX_BLACK);
            txSetFillColor(TX_BLACK);
            txRectangle(0,0,800,600);

            txSetColor(TX_GREY,5);
            txRectangle(50,50,150,150);
            txSetFillColor(TX_GREY);
            txRectangle(150,50,700,150);
            txBitBlt(txDC(),60,60,800,600,astr_priz);


            txSelectFont("Ink Free",20);
            txSetColor(TX_BLACK);
            txSetFillColor(TX_BLACK);
            txTextOut(200,60,"astral ghost:������ ����� ���������� ��������");
            txTextOut(600,130,"Press ""E""");

             if (GetAsyncKeyState('E'))
            {
              while(GetAsyncKeyState('E'))  txSleep(20);
              PAGE="astr_priz_dialog1";
            }


        }

        if (PAGE=="astr_priz_dialog1")
        {
            itapG="astr_priz_dialog1";
            txSetColor(TX_BLACK);
            txSetFillColor(TX_BLACK);
            txRectangle(0,0,800,600);

            txSetColor(TX_GREY,5);
            txRectangle(50,50,150,150);
            txSetFillColor(TX_GREY);
            txRectangle(150,50,700,150);
            txBitBlt(txDC(),60,60,800,600,astr_priz);

            txSelectFont("Ink Free",20);
            txSetColor(TX_BLACK);
            txSetFillColor(TX_BLACK);
            txTextOut(200,60,"astral ghost:� �� ������ � ����� �������������");
            txTextOut(600,130,"Press ""E""");


            txSetColor(TX_WHITE);
            txSetFillColor(TX_WHITE);
            txRectangle(615,530,800,600);
            txSetColor(TX_GREEN);
            txSetFillColor(TX_GREEN);
            txSelectFont("Courier New",20);
            txTextOut(630,550,"������� ����� �������");


             if (GetAsyncKeyState('E'))
             {
               while(GetAsyncKeyState('E'))  txSleep(20);
               PAGE="astr_priz_dialog2";
             }

        }



        if (PAGE=="astr_priz_dialog2")
        {
            itapG="astr_priz_dialog2";
            txSetColor(TX_BLACK);
            txSetFillColor(TX_BLACK);
            txRectangle(0,0,800,600);

            txSetColor(TX_GREY,5);
            txRectangle(50,50,150,150);
            txSetFillColor(TX_GREY);
            txRectangle(150,50,700,150);
            txBitBlt(txDC(),60,60,800,600,astr_priz);

            txSelectFont("Ink Free",20);
            txSetColor(TX_BLACK);
            txSetFillColor(TX_BLACK);
            txTextOut(200,60,"astral ghost:���� � ����� ���� ������, ���� ���� �����������");
            txTextOut(600,130,"Press ""E""");


             if (GetAsyncKeyState('E'))
             {
               while(GetAsyncKeyState('E'))  txSleep(20);
               PAGE="astr_world";
             }


         }


         if (PAGE=="astr_world")
         {
            itapG="astr_world";
            txBitBlt(txDC(),0,0,800,600,astr_world);


            txBitBlt(txDC(),x,y,800,600,birdA_1_astrW);
            txSleep(70);
            txBitBlt(txDC(),x,y,800,600,birdA_2_astrW);
            txSleep(70);



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
         }

        txEnd();



    }





txDisableAutoPause();
return 0;
}

