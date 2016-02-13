//---------------------------------------------------------------------------

#ifndef UBMPH
#define UBMPH

#include "UGrafico.h"
#include <fstream>

using namespace std;
//---------------------------------------------------------------------------
class tBMP:public tGrafico {

      private:
                AnsiString nombArch;
                Graphics::TBitmap* bmp;
      public:
                tBMP():tGrafico(){
                        nombArch="";
                };

                tBMP(int xi, int yi, const AnsiString& nombre):tGrafico(){

                        Xini=xi;
                        Yini=yi;
                        nombArch=nombre;
                        bmp=new Graphics::TBitmap();
                        bmp->LoadFromFile(nombre.c_str());
                };
                virtual ~tBMP(){}
                virtual void dibujar(TCanvas* lienzo);
                virtual void LeerFich(ifstream& archivo);
                virtual void salvarFich(ofstream& archivo);
                virtual void dibujarConPuntoSingular(TCanvas* lienzo);
                virtual tGrafico* copiar();
                void setNombre(AnsiString nombre){
                    nombArch=nombre;
                    bmp=new Graphics::TBitmap();
                    bmp->LoadFromFile(nombre.c_str());
                }
                void getNombre(AnsiString &nombre){
                    nombre=nombArch;
                };
};

#endif
