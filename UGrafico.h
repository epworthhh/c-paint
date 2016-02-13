//---------------------------------------------------------------------------

#ifndef UGraficoH
#define UGraficoH

#include <iostream>
//---------------------------------------------------------------------------
using namespace std;


class tGrafico {

     protected:
               int grosorLinea;
               TColor color;
               bool relleno;

               int Xini;
               int Yini;
               int Xfin;
               int Yfin;
     public:
            tGrafico(){
                    grosorLinea=1;
                    relleno=false;
                    color=clBlack;
                    Xini = 0;
                    Yini = 0;
                    Xfin = 0;
                    Yfin = 0;
            };

            virtual ~tGrafico(){};
            tGrafico(int g,TColor c,bool r,int x1,int y1,int x2,int y2) {
                     grosorLinea=g;
                     color=c;
                     relleno=r;
                     Xini=x1;
                     Yini=y1;
                     Xfin=x2;
                     Yfin=y2;
            };

             void ponCoordenadas(int x1,int y1,int x2,int y2) {
                   Xini=x1;
                   Yini=y1;
                   Xfin=x2;
                   Yfin=y2;
             }
             void damePuntoSingular(int& x, int& y) {
                 x=Xini;
                 y=Yini;
             }
             void ponPuntoSingular(int x, int y) {
                 Xini=x;
                 Yini=y;
             }
             void dameCoordenadas(int &x1,int &y1,int &x2,int &y2){
                 x1=Xini;
                 y1=Yini;
                 x2=Xfin;
                 y2=Yfin;
             }


             void rellenoCambio(bool r){
                  relleno=r;
             }
             void setColor(TColor Color){
                 color=Color;
             }

             void setGrosor(int g) {
                 grosorLinea=g;
             }

             void getColor(TColor &Color) {
                 Color=color;
             }

              void getRelleno(bool &Relleno) {
                 Relleno=relleno;
             }

              void getGrosor(int &Grosor) {
                 Grosor=grosorLinea;
             }

            virtual void dibujar(TCanvas* lienzo)=0;
            virtual void dibujarConPuntoSingular(TCanvas* lienzo)=0;
            virtual void salvarFich(ofstream& archivo)=0;
            virtual void LeerFich(ifstream &f)=0;
            virtual tGrafico* copiar()=0;
};

void liberaMemoria(tGrafico* grafico) {
    delete grafico;
    grafico=NULL;
}


#endif
