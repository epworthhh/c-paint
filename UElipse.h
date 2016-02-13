//---------------------------------------------------------------------------

#ifndef UElipseH
#define UElipseH

#include "UGrafico.h"
#include <fstream>
//---------------------------------------------------------------------------

class tElipse:public tGrafico{

public:
        tElipse():tGrafico(){};
        tElipse(int g,TColor c,bool r,int x1,int y1,int x2,int y2);

        virtual ~tElipse(){};

        virtual void dibujar(TCanvas* canvas);
        virtual void dibujarConPuntoSingular(TCanvas* lienzo);
        virtual void salvarFich(ofstream& archivo);
        virtual void LeerFich(ifstream& archivo);
        virtual tGrafico* copiar();
};

#endif
 