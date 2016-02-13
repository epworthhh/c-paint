//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UElipse.h"

//---------------------------------------------------------------------------

tElipse::tElipse(int g,TColor c,bool r,int x1,int y1,int x2,int y2):
               tGrafico(g,c,r,x1,y1,x2,y2){};

void tElipse::dibujar(TCanvas* lienzo){
        lienzo->Brush->Color=color;
        if (relleno==false) lienzo->Brush->Style=bsClear;
        else lienzo->Brush->Style=bsSolid;

        lienzo->Pen->Width=grosorLinea;
        lienzo->Pen->Color=color;
        lienzo->Ellipse(Xini,Yini,Xfin,Yfin);
}

void tElipse::dibujarConPuntoSingular(TCanvas* lienzo){
        lienzo->Brush->Color=color;
        if (relleno==false) lienzo->Brush->Style=bsClear;
        else lienzo->Brush->Style=bsSolid;

        lienzo->Pen->Width=grosorLinea;
        lienzo->Pen->Color=color;
        lienzo->Ellipse(Xini,Yini,Xfin,Yfin);
        lienzo->Brush->Color=color;
        lienzo->Rectangle(Xini+4,Yini+4,Xini-4,Yini-4);
}

tGrafico* tElipse::copiar() {
        tGrafico* grafico;
        grafico=new tElipse();
        return grafico;
}

void tElipse::salvarFich(ofstream& archivo){

            archivo <<"\\Elipse" << " \\XIni " << Xini << " \\YIni " << Yini
                    << " \\XFin " << Xfin << " \\YFin " << Yfin
                    << " \\GrosorLapiz " << grosorLinea
                    << " \\Color " << color
                    << " \\Relleno " << relleno << endl;

}


void tElipse::LeerFich(ifstream& archivo){

        string id;
        archivo >> id; // lee \XIni
        archivo >> Xini;
        archivo >> id; // lee \YIni
        archivo >> Yini;
        archivo >> id; // lee \XFin
        archivo >> Xfin;
        archivo >> id; // lee \YIni
        archivo >> Yfin;
        archivo >> id; // lee \GrosorLapiz
        archivo >> grosorLinea;
        archivo >> id; // lee \Color
        archivo >> (int)color;
        archivo >> id; // lee  \Relleno
        archivo >> relleno;
}


#pragma package(smart_init)
 