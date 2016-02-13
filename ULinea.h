//---------------------------------------------------------------------------

#ifndef ULineaH
#define ULineaH

#include "UGrafico.h"
#include <fstream>
//---------------------------------------------------------------------------
class tLinea:public tGrafico {
     public:
             tLinea():tGrafico(){};
             tLinea(int g,TColor c,bool r,int x1,int y1,int x2,int y2);

             virtual ~tLinea(){};

             virtual void dibujar(TCanvas* lienzo);
             virtual void dibujarConPuntoSingular(TCanvas* lienzo);
             virtual void salvarFich(ofstream& archivo);
             virtual void LeerFich(ifstream& archivo);
             virtual tGrafico* copiar();
};

#endif
 