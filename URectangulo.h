//---------------------------------------------------------------------------

#ifndef URectanguloH
#define URectanguloH

#include "UGrafico.h"
#include <fstream>
//---------------------------------------------------------------------------
class tRectangulo:public tGrafico{

public:
        tRectangulo():tGrafico(){};
        tRectangulo(int g,TColor c,bool r,int x1,int y1,int x2,int y2);

        virtual ~tRectangulo(){};

        virtual void dibujar(TCanvas* canvas);
        virtual void dibujarConPuntoSingular(TCanvas* canvas);
        virtual void salvarFich(ofstream& archivo);
        virtual void LeerFich(ifstream& archivo);
        virtual tGrafico* copiar();
};

#endif
