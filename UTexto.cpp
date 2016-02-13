//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UTexto.h"


//---------------------------------------------------------------------------

void tTexto::ponChar(char c){
        cadena=cadena+c;
}

void tTexto::BorraChar(){
        cadena.Delete(cadena.Length(),1);
}

void tTexto::dibujar(TCanvas* lienzo){
        lienzo->Font->Size=tam;
        lienzo->Font->Color=color;
        lienzo->Brush->Style=bsClear;
        lienzo->TextOut(Xini,Yini,cadena);
}

void tTexto::dibujarConPuntoSingular(TCanvas* lienzo) {
    lienzo->Font->Size=tam;
    lienzo->Font->Color=color;
    lienzo->Brush->Style=bsClear;
    lienzo->TextOut(Xini,Yini,cadena);
    lienzo->Brush->Color=color;
    lienzo->Rectangle(Xini+4,Yini+4,Xini-4,Yini-4);
}

tGrafico* tTexto::copiar() {
        tGrafico* grafico;
        grafico=new tTexto();
        return grafico;
}

void tTexto::salvarFich(ofstream& archivo){

      archivo << "\\Texto" << " \\Xini " << Xini << " \\Yini " << Yini
              << " \\Cadena " << cadena.c_str()
              << " \\TamFuente " << tam
              << " \\Color " << color << endl;

}

void tTexto::LeerFich(ifstream& archivo){

        string id;
        char aux;
        cadena="";
        archivo >> id; // lee \XIni
        archivo >> Xini;
        archivo >> id; // lee \YIni
        archivo >> Yini;
        archivo >> id; // lee \Cadena
        archivo.get(aux);
        while (aux!='\\'){
             cadena=cadena+aux;
             archivo.get(aux);
        }
        archivo >> id; // lee \TamFuente
        archivo >> tam;
        archivo >> id; // lee \Color
        archivo >> (int)color;
}



#pragma package(smart_init)
