/**********************************************************************************************************************************************\
*   @file     #01_Struct.c++💻                                                                                                                *
*   @author   Lucas Klein   👨💻                                                                                                              *
*   @version  v1            👾                                                                                                                *  
*   @date     03-02-2021    📅                                                                                                                *
*   @brief    Studying for Fun 🌎                                                                                                             *
***********************************************************************************************************************************************/
//---------|Library|----------------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <locale.h>

//---------|Defines|----------------------------------------------------------------------------------


//---------|Functions|--------------------------------------------------------------------------------
//protoripando
void mostra(void);
void desenha_primeiro(int m);
void desenha_segundo(int c);
void desenha_terceiro(int d);
void desenha_quarto(int u);
void stop(char pause);

//---|Bugiganga|---------------------------------------------------------------------------------------
enum DOS_COLORS {
        PRETO, AZUL, VERDE, CIANO ,VERMELHO, MAGENTA, MARRON,
        LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
        LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE
        };


void teclado_portugues(void)
{
    setlocale(LC_ALL,"portuguese");
}

void gotoxy(int coluna, int linha)
{
        COORD point;
        point.X = coluna; point.Y = linha;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}



void textcolor(DOS_COLORS iColor)
{
        HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
        BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
        bufferInfo.wAttributes &= 0x00F0;
        SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

//-----------------------------------------------------------------------------------------------------

/**---------|Global Variables|-------------------------------------------------------------------------*/
char displays[11][40]={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                       2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,
                       2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,
                       2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,
                       2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,
                       2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,
                       2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,
                       2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,
                       2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,
                       2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,
                       2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
struct seg{
    char a;
    char b;
    char c;
    char d;
    char e;
    char f;
    char g;
}seg;

int main(void){

    system("cls");
    gotoxy(0,42);
    printf("use Space bar to stop the program");
    gotoxy(0,0);

    char pause;
    int m,d,c,u;

    for(m=9;m!=0;m--){
        desenha_primeiro(m);
        mostra();

        for(c=9;c!=0;c--){
            desenha_segundo(c);
            mostra();

            for(d=9;d!=0;d--){
                desenha_terceiro(d);
                mostra();

                for(u=9;u!=0;u--){
                    desenha_quarto(u);
                    Sleep(100);
                    mostra();

                    stop(pause);
                }
            }
        }
    }


return 0;
}

/**---------|Function I|--------------------------------------------------------------------------------*/
void mostra(void){
    for(int l=0;l<11;l++){
        for(int c=0;c<40;c++){
            gotoxy(c,l);//pra reescrever cada parte quando houver a troca de numeros ele conseguir mudar a cor

            if(displays[l][c]==1){textcolor(VERMELHO);}
            if(displays[l][c]==2){textcolor(VERDE);}
            if(displays[l][c]==3){textcolor(AZUL);}

            printf("%c",219); // printa o caracter vazio (219 da ASCII = caractere  ) qu vai ter a cor que eu quero
        }
    }

    printf("\n\n");
    textcolor(WHITE);
}

/**---------|Function II|-------------------------------------------------------------------------------*/
void desenha_primeiro(int m){
    seg.a=1,seg.b=1,seg.c=1,seg.d=1,seg.e=1,seg.f=1,seg.g=1;     //definindo o fundo (praticamente)

    if(m==0){     //se o caractere que eu quero da unidade de milhar for ==0, entao isso acontece
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.e=3;
        seg.f=3;
    }           //todos com 3 vao estar ligados enquanto o seg g (g=1) vai ter a mesma cor do fundo
                //e se repete para todas as outras.

    if(m==1){
        seg.b=3;
        seg.c=3;
    }

    if(m==2){
        seg.a=3;
        seg.b=3;
        seg.d=3;
        seg.e=3;
        seg.g=3;
    }
    if(m==3){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.g=3;
    }
    if(m==4){
        seg.b=3;
        seg.c=3;
        seg.f=3;
        seg.g=3;
    }
    if(m==5){
        seg.a=3;
        seg.c=3;
        seg.d=3;
        seg.f=3;
        seg.g=3;
    }
    if(m==6){
        seg.a=3;
        seg.c=3;
        seg.d=3;
        seg.e=3;
        seg.f=3;
        seg.g=3;
    }
    if(m==7){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.f=3;
    }
    if(m==8){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.e=3;
        seg.f=3;
        seg.g=3;
    }
    if(m==9){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.f=3;
        seg.g=3;
    }

    /*******comeca a ser desenhado os segmentos*********/

    for(int sA=3; sA<=6;sA++)
        //desenho do segmento "A" do display
        displays[2][sA] = seg.a;

    for(int sB=3;sB<=4;sB++)
        //desenho do segmento "B" do display
        displays[sB][7] = seg.b;

    for(int sC=6;sC<=7;sC++)
        //desenho do segmento "C" do display
        displays[sC][7] = seg.c;

    for(int sD=3;sD<=6;sD++)
        //desenho do segmento "D" do display
        displays[8][sD]=seg.d;

    for(int sE=6;sE<=7;sE++)
        //desenho do segmento "E" do display
        displays[sE][2]=seg.e;

    for(int sF=3;sF<=4;sF++)
        //desenho do segmento "F" do display
        displays[sF][2]=seg.f;

   for(int sG=3;sG<=6;sG++)
        //desenho do segmento "G" do display
        displays[5][sG]=seg.g;

}

/**---------|Function III|------------------------------------------------------------------------------*/
void desenha_segundo(int c){
    seg.a=1,seg.b=1,seg.c=1,seg.d=1,seg.e=1,seg.f=1,seg.g=1;     //definindo o fundo (praticamente)

    if(c==0){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.e=3;
        seg.f=3;

    }

    if(c==1){
        seg.b=3;
        seg.c=3;
    }

    if(c==2){
        seg.a=3;
        seg.b=3;
        seg.d=3;
        seg.e=3;
        seg.g=3;
    }
    if(c==3){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.g=3;
    }
    if(c==4){
        seg.b=3;
        seg.c=3;
        seg.f=3;
        seg.g=3;
    }
    if(c==5){
        seg.a=3;
        seg.c=3;
        seg.d=3;
        seg.f=3;
        seg.g=3;
    }
    if(c==6){
        seg.a=3;
        seg.c=3;
        seg.d=3;
        seg.e=3;
        seg.f=3;
        seg.g=3;
    }
    if(c==7){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.f=3;
    }
    if(c==8){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.e=3;
        seg.f=3;
        seg.g=3;
    }
    if(c==9){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.f=3;
        seg.g=3;
    }
     /*******comeca a ser desenhado os segmentos*********/

    for(int sA=3; sA<=6;sA++)
        //desenho do segmento "A" do display
        displays[2][sA+10] = seg.a;

    for(int sB=3;sB<=4;sB++)
        //desenho do segmento "B" do display
        displays[sB][7+10] = seg.b;

    for(int sC=6;sC<=7;sC++)
        //desenho do segmento "C" do display
        displays[sC][7+10] = seg.c;

    for(int sD=3;sD<=6;sD++)
        //desenho do segmento "D" do display
        displays[8][sD+10]=seg.d;

    for(int sE=6;sE<=7;sE++)
        //desenho do segmento "E" do display
        displays[sE][2+10]=seg.e;

    for(int sF=3;sF<=4;sF++)
        //desenho do segmento "F" do display
        displays[sF][2+10]=seg.f;

    for(int sG=3;sG<=6;sG++)
        //desenho do segmento "G" do display
        displays[5][sG+10]=seg.g;

}
/**---------|Function IV|-------------------------------------------------------------------------------*/
void desenha_terceiro(int d){
    seg.a=1,seg.b=1,seg.c=1,seg.d=1,seg.e=1,seg.f=1,seg.g=1;     //definindo o fundo (praticamente)

    if(d==0){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.e=3;
        seg.f=3;
    }

    if(d==1){
        seg.b=3;
        seg.c=3;
    }

    if(d==2){
        seg.a=3;
        seg.b=3;
        seg.d=3;
        seg.e=3;
        seg.g=3;
    }
    if(d==3){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.g=3;
    }
    if(d==4){
        seg.b=3;
        seg.c=3;
        seg.f=3;
        seg.g=3;
    }
    if(d==5){
        seg.a=3;
        seg.c=3;
        seg.d=3;
        seg.f=3;
        seg.g=3;
    }
    if(d==6){
        seg.a=3;
        seg.c=3;
        seg.d=3;
        seg.e=3;
        seg.f=3;
        seg.g=3;
    }
    if(d==7){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.f=3;
    }
    if(d==8){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.e=3;
        seg.f=3;
        seg.g=3;
    }
    if(d==9){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.f=3;
        seg.g=3;
    }
     /*******comeca a ser desenhado os segmentos*********/

    for(int sA=3; sA<=6;sA++)
        //desenho do segmento "A" do display
        displays[2][sA+20] = seg.a;

    for(int sB=3;sB<=4;sB++)
        //desenho do segmento "B" do display
        displays[sB][7+20] = seg.b;

    for(int sC=6;sC<=7;sC++)
        //desenho do segmento "C" do display
        displays[sC][7+20] = seg.c;

    for(int sD=3;sD<=6;sD++)
        //desenho do segmento "D" do display
        displays[8][sD+20]=seg.d;

    for(int sE=6;sE<=7;sE++)
        //desenho do segmento "E" do display
        displays[sE][2+20]=seg.e;

    for(int sF=3;sF<=4;sF++)
        //desenho do segmento "F" do display
        displays[sF][2+20]=seg.f;

    for(int sG=3;sG<=6;sG++)
        //desenho do segmento "G" do display
        displays[5][sG+20]=seg.g;

}
/**---------|Function V|--------------------------------------------------------------------------------*/
void desenha_quarto(int u){
    seg.a=1,seg.b=1,seg.c=1,seg.d=1,seg.e=1,seg.f=1,seg.g=1;     //definindo o fundo (praticamente)

    if(u==0){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.e=3;
        seg.f=3;
    }

    if(u==1){
        seg.b=3;
        seg.c=3;
    }

    if(u==2){
        seg.a=3;
        seg.b=3;
        seg.d=3;
        seg.e=3;
        seg.g=3;
    }
    if(u==3){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.g=3;
    }
    if(u==4){
        seg.b=3;
        seg.c=3;
        seg.f=3;
        seg.g=3;
    }
    if(u==5){
        seg.a=3;
        seg.c=3;
        seg.d=3;
        seg.f=3;
        seg.g=3;
    }
    if(u==6){
        seg.a=3;
        seg.c=3;
        seg.d=3;
        seg.e=3;
        seg.f=3;
        seg.g=3;
    }
    if(u==7){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.f=3;
    }
    if(u==8){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.e=3;
        seg.f=3;
        seg.g=3;
    }
    if(u==9){
        seg.a=3;
        seg.b=3;
        seg.c=3;
        seg.d=3;
        seg.f=3;
        seg.g=3;
    }
     /*******comeca a ser desenhado os segmentos*********/

    for(int sA=3; sA<=6;sA++)
        //desenho do segmento "A" do display
        displays[2][sA+30] = seg.a;

    for(int sB=3;sB<=4;sB++)
        //desenho do segmento "B" do display
        displays[sB][7+30] = seg.b;

    for(int sC=6;sC<=7;sC++)
        //desenho do segmento "C" do display
        displays[sC][7+30] = seg.c;

    for(int sD=3;sD<=6;sD++)
        //desenho do segmento "D" do display
        displays[8][sD+30]=seg.d;

    for(int sE=6;sE<=7;sE++)
        //desenho do segmento "E" do display
        displays[sE][2+30]=seg.e;

    for(int sF=3;sF<=4;sF++)
        //desenho do segmento "F" do display
        displays[sF][2+30]=seg.f;

    for(int sG=3;sG<=6;sG++)
        //desenho do segmento "G" do display
        displays[5][sG+30]=seg.g;
}
/**---------|Function VI|-------------------------------------------------------------------------------*/
void stop(char pause){
    if(kbhit()){
        pause=getch();
            if(pause==' '){
                while(1){
                    if(kbhit()){
                       pause=getch();
                       if(pause==' '){
                           break;
                       }else{} 
                    }
                }
            }else{}

    }
}
