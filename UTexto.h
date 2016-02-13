//---------------------------------------------------------------------------

#ifndef UTextoH
#define UTextoH

#include "UGrafico.h"
#include <fstream>

//---------------------------------------------------------------------------
class tTexto:public tGrafico{

        private:
           int tam;
           AnsiString cadena;
        public:

           tTexto():tGrafico(){
                 tam=10;
                 cadena="";
           };
           tTexto(int x, int y,AnsiString Cadena,int t,TColor c){
                 Xini=x;
                 Yini=y;
                 cadena=Cadena;
                 tam=t;
                 color=c;
           };
           virtual ~tTexto(){};
           void ponChar(char c);
           void BorraChar();
           AnsiString dameCadena(){return cadena;};
           void getTam(int &tamanio){tamanio=tam;};

           void setTam(int tama){tam=tama;};
           void setCadena(AnsiString Cadena){cadena=Cadena;};

           virtual void dibujar(TCanvas* lienzo);
           virtual void dibujarConPuntoSingular(TCanvas* canvas);
           virtual tGrafico* copiar();
           void salvarFich(ofstream& archivo);
           void LeerFich(ifstream& archivo);
};

#endif
 