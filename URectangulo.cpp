//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "URectangulo.h"

//---------------------------------------------------------------------------

tRectangulo::tRectangulo(int g,TColor c,bool r,int x1,int y1,int x2,int y2):
               tGrafico(g,c,r,x1,y1,x2,y2){};

void tRectangulo::dibujar(TCanvas* lienzo){

        lienzo->Brush->Color=color;
        if (relleno==false) lienzo->Brush->Style=bsClear;
        else lienzo->Brush->Style=bsSolid;

        lienzo->Pen->Width=grosorLinea;
        lienzo->Pen->Color=color;
        lienzo->Rectangle(Xini,Yini,Xfin,Yfin);
}

void tRectangulo::dibujarConPuntoSingular(TCanvas* lienzo){

        lienzo->Brush->Color=color;
        if (relleno==false) lienzo->Brush->Style=bsClear;
        else lienzo->Brush->Style=bsSolid;

        lienzo->Pen->Width=grosorLinea;
        lienzo->Pen->Color=color;
        lienzo->Rectangle(Xini,Yini,Xfin,Yfin);
        lienzo->Brush->Color=color;
        lienzo->Rectangle(Xini+4,Yini+4,Xini-4,Yini-4);
}

tGrafico* tRectangulo::copiar() {
        tGrafico* grafico;
        grafico=new tRectangulo();
        return grafico;
}

void tRectangulo::salvarFich(ofstream& archivo){

          archivo << "\\Rectangulo" << " \\XIni " << Xini << " \\YIni " << Yini
                  << " \\XFin " << Xfin << " \\YFin " << Yfin
                  << " \\GrosorLapiz " << grosorLinea
                  << " \\Color " << color
                  << " \\Relleno " << relleno << endl;

}

void tRectangulo::LeerFich(ifstream& archivo){

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
