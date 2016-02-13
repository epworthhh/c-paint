//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UBMP.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

void tBMP::dibujar(TCanvas* lienzo){
        lienzo->Draw(Xini,Yini,bmp);
};

void tBMP::dibujarConPuntoSingular(TCanvas* lienzo){
        lienzo->Draw(Xini,Yini,bmp);
        lienzo->Brush->Color=color;
        lienzo->Rectangle(Xini+4,Yini+4,Xini-4,Yini-4);
};

void tBMP::LeerFich(ifstream& archivo){
        string id;
        char aux;
        AnsiString cadena="";

        archivo >> id; // lee \XIni
        archivo >> Xini;
        archivo >> id; // lee \YIni
        archivo >> Yini;
        archivo >> id; // lee \Cadena
        archivo.get(aux);
        while (aux!='\n'){
             cadena=cadena+aux;
             archivo.get(aux);
        }
        nombArch=cadena;
        bmp=new Graphics::TBitmap();
        bmp->LoadFromFile(cadena.c_str());
};

void tBMP::salvarFich(ofstream& archivo) {
        AnsiString nombre="";
        getNombre(nombre);
        archivo << "\\BMP" << " \\Xini " << Xini << " \\Yini " << Yini
                << " \\Archivo " << nombre.c_str() << endl;
};

tGrafico* tBMP::copiar() {
        tGrafico* grafico;
        grafico=new tBMP();
        return grafico;
};
