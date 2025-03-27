#include "TXLib.h"
#include <windows.h>

using namespace std;


//����������
int SCH=0;

int xbat_1=750;
int ybat_1=200;
int xbat_2=600;
int ybat_2=550;

int x_batton1=330;
int x_batton11=120;
int x_batton2=330;
int x_batton21=120;
int x_batton3=330;
int x_batton31=120;
int x_batton4=330;
int x_batton41=120;


int schetcik=1000;


string itapG="game";


//������� ������
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






    //�����������
    HDC pole = txLoadImage("pictures/location.bmp");
    HDC bat = txLoadImage("pictures/bat.bmp");
    HDC astr_world = txLoadImage("pictures/astr_world.bmp");
    HDC birdA_1 = txLoadImage("pictures/bird_1.bmp");
    HDC birdA_2 = txLoadImage("pictures/bird_2.bmp");
    HDC birdA_1_astrW = txLoadImage("pictures/bird_1_astr_world.bmp");
    HDC birdA_2_astrW = txLoadImage("pictures/bird_2_astr_world.bmp");
    HDC birdAZ_1 = txLoadImage("pictures/bird_1_zerk.bmp");
    HDC birdAZ_2 = txLoadImage("pictures/bird_2_zerk.bmp");
    HDC nebo = txLoadImage("pictures/nebo.bmp");
    HDC cityP = txLoadImage("pictures/cityP.bmp");
    HDC bird_CP = txLoadImage("pictures/bird_CP.bmp");
    HDC space_1 = txLoadImage("pictures/SPACE_1.bmp");
    HDC space_2 = txLoadImage("pictures/SPACE_2.bmp");
    HDC astr_priz = txLoadImage("pictures/astr_priz.bmp");
    HDC star = txLoadImage("pictures/star.bmp");




    while (!GetAsyncKeyState(VK_F9))
    {

        txBegin();

        Button btn0 = {x_batton1, 190, x_batton11, 40, "�����"};
        Button btn1 = {x_batton2, 310, x_batton21, 40, "�����"};
        Button btn2 = {x_batton3, 270, x_batton31, 40, "��������"};
        Button btn3 = {x_batton4, 230, x_batton41, 40, "�������"};

        txSetFillColor (TX_WHITE);
        txRectangle(0,0,800,600);

        //����
        if (PAGE=="menu");
        {
            btn0.draw();
            btn1.draw();
            btn2.draw();
            btn3.draw();
            if (btn0.click())
            {
                PAGE=itapG;
            }


            if (btn1.click())
            {
                break;
            }

            if (btn3.click())
            {
                PAGE="rulers";
            }

            if (btn2.click())
            {
                PAGE="item";
            }
            if (itapG=="astr_priz" or itapG=="nicegame1.1" or itapG=="nicegame1" or itapG=="nicegame" or itapG=="astr_world" or itapG=="astr_priz_dialog2" or itapG=="astr_priz_dialog1"){
                if (btn3.click())
                {
                    PAGE="rulers1";
                }



                x_batton1=0;
                x_batton11=800;
                x_batton2=500;
                x_batton21=700;
                x_batton3=0;
                x_batton31=340;
                x_batton4=700;
                x_batton41=800;

                if (PAGE=="rulers1"){
                txSetFillColor(TX_BLACK);
                txRectangle(0,0,800,600);
                txSetFillColor(TX_RED);
                txSelectFont("Times New Roman", 30);
                txTextOut(0, 300, "??><<?/.,,><>>[][[[[[]]]]>?>><<:$%#@^&#@%$#@%^@#$%##@^$#@*&#$????");


                }

             }
              if (PAGE=="rulers"){
                txSetFillColor(TX_WHITE);
                txRectangle(0,0,800,600);
                txSetFillColor(TX_BLACK);
                txSelectFont("Times New Roman", 30);
                txTextOut(0, 300, "���� ��� ����� ������� ��� ����� � ���������� ");
                txTextOut(0, 350, "������������, ������ ��� ����������� ��������� ����� ����������");
                txTextOut(0, 400, "���������� wasd");
            }
        }

        if (GetAsyncKeyState(VK_ESCAPE))
        {
          PAGE="menu";
        }
        //�������� ����
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

        //����� ����� ��������� ����
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
        //������ ����� ��������� ����
        if (PAGE=="Rlist")
        {

            itapG="Rlist";
            txBitBlt(txDC(),0,0,800,600,nebo);

            txBitBlt(txDC(),x,y,800,600,birdA_1);
            txSleep(70);
            txBitBlt(txDC(),x,y,800,600,birdA_2);
            txSleep(70);

            txBitBlt(txDC(),650,570,800,600,star);
            txSleep(2);




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

        //��������� ���
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
        //��������
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
            txTextOut(200,60,"astral ghost:������ ����� ���������� #?/?#\\");
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
            txBitBlt(txDC(),750,570,800,600,star);
            txSleep(2);


            txBitBlt(txDC(),x,y,800,600,birdA_1_astrW);
            txSleep(20);
            txBitBlt(txDC(),x,y,800,600,birdA_2_astrW);
            txSleep(20);

            txBitBlt(txDC(),xbat_1,ybat_1,800,600,bat);
            ybat_1=ybat_1+30;
            if (ybat_1>600)
            {
                ybat_1=0;
            }




            if (ybat_1<400)
            {

                txSetFillColor(TX_RED);
                txRectangle(0,ybat_1-10,xbat_1,ybat_1+20);
                if (ybat_1+20==y or ybat_1-20==y or ybat_1==y)
                {
                  PAGE="DIE";


                }
            }


            if (GetAsyncKeyState('A'))
            {
                x=x-20;
            }

            if (GetAsyncKeyState('W'))
            {
                y=y-20;
            }

            if (GetAsyncKeyState('D'))
            {
                x=x+20;

            }

            if (GetAsyncKeyState('S'))
            {
                y=y+20;
            }


            if (x>750)
            {
                PAGE="nicegame";
            }



         }


         if (PAGE=="nicegame")
            {
                itapG="nicegame";
                txBitBlt(txDC(),0,0,800,600,astr_world);

                txBitBlt(txDC(),5,570,800,600,star);
                txSleep(2);
                txBitBlt(txDC(),x,y,800,600,birdA_1_astrW);
                txSleep(20);
                txBitBlt(txDC(),x,y,800,600,birdA_2_astrW);
                txSleep(20);

                if (GetAsyncKeyState('A'))
                {
                    x=x-20;
                }

                if (GetAsyncKeyState('W'))
                {
                    y=y-20;
                }

                if (GetAsyncKeyState('D'))
                {
                    x=x+20;

                }

                if (GetAsyncKeyState('S'))
                {
                    y=y+20;
                }


                txBitBlt(txDC(),xbat_2-20,ybat_2,800,600,bat);
                xbat_2=xbat_2-30;
                if (xbat_2<50)
                {
                    xbat_2=750;
                }

                if (xbat_2>200)
                {

                txSetFillColor(TX_RED);
                txRectangle(xbat_2,0,xbat_2+40,ybat_2);
                if (xbat_2+20==x or xbat_2-20==x or xbat_2==x)
                    {
                        PAGE="DIE";
                    }
                }

                if (x<0)
                {
                    PAGE="nicegame1";
                }





            }

            if (PAGE=="nicegame1")
            {
                itapG="nicegame1";
                txBitBlt(txDC(),0,0,800,600,astr_world);


                txBitBlt(txDC(),x,y,800,600,birdA_1_astrW);
                txSleep(20);
                txBitBlt(txDC(),x,y,800,600,birdA_2_astrW);
                txSleep(20);


                txBitBlt(txDC(),0,300,800,600,bat);
                txSleep(20);
                txBitBlt(txDC(),0,500,800,600,bat);
                txSleep(20);
                txBitBlt(txDC(),0,100,800,600,bat);
                txSleep(20);


                if (GetAsyncKeyState('A'))
                {
                    x=x-20;
                }

                if (GetAsyncKeyState('W'))
                {
                    y=y-20;
                }

                if (GetAsyncKeyState('D'))
                {
                    x=x+20;

                }

                if (GetAsyncKeyState('S'))
                {
                    y=y+20;
                }

                schetcik=schetcik-20;
                if (schetcik==900)
                {
                    PAGE="nicegame1.1";
                }

             }


             if (PAGE=="nicegame1.1")
             {
                itapG="nicegame1.1";
                txBitBlt(txDC(),0,0,800,600,astr_world);


                txBitBlt(txDC(),x,y,800,600,birdA_1_astrW);
                txSleep(20);
                txBitBlt(txDC(),x,y,800,600,birdA_2_astrW);
                txSleep(20);

                if (GetAsyncKeyState('A'))
                {
                    x=x-20;
                }

                if (GetAsyncKeyState('W'))
                {
                    y=y-20;
                }

                if (GetAsyncKeyState('D'))
                {
                    x=x+20;

                }

                if (GetAsyncKeyState('S'))
                {
                    y=y+20;
                }


                txBitBlt(txDC(),0,300,800,600,bat);
                 txSetFillColor(TX_RED);
                txRectangle(0,300,800,320);
                if (300+20==y or 300-20==y or 300==y)
                {
                  PAGE="DIE";


                }
                txBitBlt(txDC(),0,500,800,600,bat);
                 txSetFillColor(TX_RED);
                txRectangle(0,500,800,520);
                if (500+20==y or 500-20==y or 500==y)
                {
                  PAGE="DIE";


                }
                txBitBlt(txDC(),0,100,800,600,bat);
                 txSetFillColor(TX_RED);
                txRectangle(0,100,800,120);
                if (100+20==y or 100-20==y or 100==y)
                {
                  PAGE="DIE";


                }
                schetcik=schetcik-20;
                if (schetcik==400)
                {
                  PAGE="nicegame2";

                }

             }



             if (PAGE=="nicegame2.1")
             {
                itapG="nicegame2";
                txBitBlt(txDC(),0,0,800,600,astr_world);


                txBitBlt(txDC(),x,y,800,600,birdA_1_astrW);
                txSleep(20);
                txBitBlt(txDC(),x,y,800,600,birdA_2_astrW);
                txSleep(20);

                if (GetAsyncKeyState('A'))
                {
                    x=x-20;
                }

                if (GetAsyncKeyState('W'))
                {
                    y=y-20;
                }

                if (GetAsyncKeyState('D'))
                {
                    x=x+20;

                }

                if (GetAsyncKeyState('S'))
                {
                    y=y+20;
                }


                txBitBlt(txDC(),0,300,800,600,bat);
                 txSetFillColor(TX_RED);
                txRectangle(0,300,800,320);
                if (300+20==y or 300-20==y or 300==y)
                {
                  PAGE="DIE";


                }
                txBitBlt(txDC(),0,500,800,600,bat);
                 txSetFillColor(TX_RED);
                txRectangle(0,500,800,520);
                if (500+20==y or 500-20==y or 500==y)
                {
                  PAGE="DIE";


                }
                txBitBlt(txDC(),0,150,800,600,bat);
                 txSetFillColor(TX_RED);
                txRectangle(0,150,800,170);
                if (150+20==y or 150-20==y or 150==y)
                {
                  PAGE="DIE";


                }

                txBitBlt(txDC(),0,200,800,600,bat);
                 txSetFillColor(TX_RED);
                txRectangle(0,200,800,120);
                if (y==y or y==y or y==y)
                {
                  PAGE="DIE";


                }





             }





             if (PAGE=="nicegame2")
            {
                itapG="nicegame2.1";
                txBitBlt(txDC(),0,0,800,600,astr_world);


                txBitBlt(txDC(),x,y,800,600,birdA_1_astrW);
                txSleep(20);
                txBitBlt(txDC(),x,y,800,600,birdA_2_astrW);
                txSleep(20);


                txBitBlt(txDC(),0,300,800,600,bat);
                txSleep(20);
                txBitBlt(txDC(),0,500,800,600,bat);
                txSleep(20);
                txBitBlt(txDC(),0,100,800,600,bat);
                txSleep(20);


                if (GetAsyncKeyState('A'))
                {
                    x=x-20;
                }

                if (GetAsyncKeyState('W'))
                {
                    y=y-20;
                }

                if (GetAsyncKeyState('D'))
                {
                    x=x+20;

                }

                if (GetAsyncKeyState('S'))
                {
                    y=y+20;
                }

                schetcik=schetcik-20;
                if (schetcik==300)
                {
                    PAGE="nicegame2.1";
                }

             }






























         if (PAGE=="DIE")
         {
           txSetColor(TX_BLACK);
           txSetFillColor(TX_BLACK);
           txRectangle(0,0,800,600);
           txSetColor(TX_RED);
           txSetFillColor(TX_RED);
           txTextOut(400,300,"Die");
         }

        txEnd();



    }





txDisableAutoPause();
return 0;
}
