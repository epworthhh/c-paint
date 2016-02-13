//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ULinea.h"
using namespace std;

//---------------------------------------------------------------------------

#pragma package(smart_init)


tLinea::tLinea(int g,TColor c,bool r,int x1,int y1,int x2,int y2):
               tGrafico(g,c,r,x1,y1,x2,y2){};

void tLinea::dibujar(TCanvas* lienzo){

        lienzo->Brush->Color = color;
        if (relleno == false) lienzo->Brush->Style=bsClear;
        else lienzo->Brush->Style=bsSolid;

        lienzo->Pen->Width=grosorLinea;
        lienzo->Pen->Color=color;
        lienzo->MoveTo(Xini,Yini);
        lienzo->LineTo(Xfin,Yfin);
}

void tLinea::dibujarConPuntoSingular(TCanvas* lienzo) {
     lienzo->Brush->Color = color;

     lienzo->Pen->Width=grosorLinea;
     lienzo->Pen->Color=color;
     lienzo->MoveTo(Xini,Yini);
     lienzo->LineTo(Xfin,Yfin);
     lienzo->Brush->Color=color;
     lienzo->Rectangle(Xini+4,Yini+4,Xini-4,Yini-4);
}

tGrafico* tLinea::copiar() {
        tGrafico* grafico;
        grafico=new tLinea();
        return grafico;
}


void tLinea::salvarFich(ofstream& archivo)
{

        archivo << "\\Linea" << " \\XIni " << Xini << " \\YIni " << Yini
                << " \\XFin " << Xfin << " \\YFin " << Yfin
                << " \\GrosorLapiz " << grosorLinea
                << " \\Color " << color
                << " \\Relleno " << relleno << endl;
}

void tLinea::LeerFich(ifstream& archivo){

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
        archivo >> id; // lee \Relleno
        archivo >> relleno;

}
