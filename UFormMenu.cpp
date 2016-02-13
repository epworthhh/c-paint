//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormMenu.h"
#include <typeinfo>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMenu *FormMenu;
//---------------------------------------------------------------------------
__fastcall TFormMenu::TFormMenu(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::Salir1Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::FormCreate(TObject *Sender)
{
        cadena="";
        fichero="";
        bmp="";
        Nuevo1Click(Sender);

}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if (dibujaLinea)
          if ((Button==mbLeft)||(Button==mbRight)){
            grafico=new tLinea();
            grafico->ponCoordenadas(X,Y,X,Y);
            grafico->setColor(color);
            grafico->setGrosor(grosor);
            mover=true;
          }

        if (dibujaRectangulo)
          if ((Button==mbLeft)||(Button==mbRight)){
            grafico=new tRectangulo();
            grafico->rellenoCambio(relleno);
            grafico->ponCoordenadas(X,Y,X,Y);
            grafico->setColor(color);
            grafico->setGrosor(grosor);
            mover=true;
          }

        if (dibujaElipse)
          if ((Button==mbLeft)||(Button==mbRight)){
            grafico=new tElipse();
            grafico->rellenoCambio(relleno);
            grafico->ponCoordenadas(X,Y,X,Y);
            grafico->setColor(color);
            grafico->setGrosor(grosor);
            mover=true;
          }
        if ((dibujaTexto)&&(grafico==NULL))
          if ((Button==mbLeft)||(Button==mbRight)){
            grafico=new tTexto();
            grafico->setColor(color);
            grafico->ponPuntoSingular(X,Y);
            ((tTexto*)grafico)->setTam(tam);
          }
        if (seleccionaPunto) {
          if ((Button==mbLeft)||(Button==mbRight)){
            int i=1;
            tGrafico* g;
            while((!encontrado)&&(i<=dibujo->getNum())) {
               g=dibujo->getElem(i);
               int x,y;
               g->damePuntoSingular(x,y);
               if((X<=x+4)&&(Y<=y+4)&&(X>=x-4)&&(Y>=y-4)){
                 pos=i;
                 encontrado=true;
                 ToolButton10->Marked=true;
               }
               else i++;
            }
          }
        }
        if (moverGrafico){
          if ((Button==mbLeft)||(Button==mbRight)){
             int x1,y1,x2,y2,xfin,yfin;
             dibujo->getElem(pos)->dameCoordenadas(x1,y1,x2,y2);
             xfin=X+(x2-x1);
             yfin=Y+(y2-y1);
             dibujo->getElem(pos)->ponCoordenadas(X,Y,xfin,yfin);
             moverGrafico=false;
             ToolButton10->Marked=false;
             encontrado=false;
          }
        }

        if (copiarGrafico){
          if ((Button==mbLeft)||(Button==mbRight)){
            if (encontrado) {
              int x1,y1,x2,y2,xfin,yfin;
              dibujo->getElem(pos)->dameCoordenadas(x1,y1,x2,y2);
              xfin=X+(x2-x1);
              yfin=Y+(y2-y1);
              copiaGraf=dibujo->getElem(pos)->copiar();

              dibujo->getElem(pos)->getColor(colorAux);
              copiaGraf->setColor(colorAux);

              dibujo->getElem(pos)->getRelleno(rellenoAux);
              copiaGraf->rellenoCambio(rellenoAux);

              dibujo->getElem(pos)->getGrosor(grosorAux);
              copiaGraf->setGrosor(grosorAux);

              if (typeid(*copiaGraf)==typeid(tTexto)){
                ((tTexto*)dibujo->getElem(pos))->getTam(tam);
                cadena=((tTexto*)dibujo->getElem(pos))->dameCadena();
                ((tTexto*)copiaGraf)->setCadena(cadena);
                ((tTexto*)copiaGraf)->setTam(tam);
              }
              if (typeid(*copiaGraf)==typeid(tBMP)){
                ((tBMP*)dibujo->getElem(pos))->getNombre(fichero);
                ((tBMP*)copiaGraf)->setNombre(fichero);
              }

              copiaGraf->ponCoordenadas(X,Y,xfin,yfin);
              dibujo->aniadirElem(copiaGraf);
              copiaGraf=NULL;
              copiarGrafico=false;
              ToolButton10->Marked=false;
              encontrado=false;
            }
          }
        }

        if (dibujaBMP){
          if ((Button==mbLeft)||(Button==mbRight)){
            grafico=new tBMP();
            grafico->ponCoordenadas(X,Y,X,Y);
            ((tBMP*)grafico)->setNombre(bmp);
            dibujo->aniadirElem(grafico);
            grafico=NULL;
          }
        }

      Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
      int x,y;
      if (mover) {
        if((dibujaLinea)||(dibujaRectangulo)||(dibujaElipse)){
          grafico->damePuntoSingular(x,y);
          grafico->ponCoordenadas(x,y,X,Y);
          Repaint();
        }
      }
}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::FormMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        mover=false;

        if((dibujaLinea)||(dibujaRectangulo)||(dibujaElipse)){
          dibujo->aniadirElem(grafico);
          dibujaTexto=false;
          grafico=NULL;
        }

        Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::FormPaint(TObject *Sender)
{
        if (seleccionaPunto){
             if(grafico!=NULL) grafico->dibujarConPuntoSingular(Canvas);
             for (int i=1; i<=dibujo->getNum(); i++)
                dibujo->getElem(i)->dibujarConPuntoSingular(Canvas);
         }
         else {
             if(grafico!=NULL) grafico->dibujar(Canvas);

             for (int i=1; i<=dibujo->getNum(); i++)
                dibujo->getElem(i)->dibujar(Canvas);
         }
}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::FormDestroy(TObject *Sender)
{
        if (grafico!=NULL) {
          dibujo->aniadirElem(grafico);
          delete grafico;
          grafico=NULL;
        }

        delete dibujo;
        dibujo=NULL;

}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::ToolButton2Click(TObject *Sender)
{
     if (grafico!=NULL) {
       dibujo->aniadirElem(grafico);
       dibujaTexto=false;
       dibujaBMP=false;
       grafico=NULL;
     }
     dibujaLinea=true;
     dibujaRectangulo=false;
     dibujaElipse=false;
     dibujaTexto=false;
     seleccionaPunto=false;
     moverGrafico=false;
     dibujaBMP=false;

}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::Nuevo1Click(TObject *Sender)
{
        if (grafico!=NULL) {
          dibujo->aniadirElem(grafico);
          grafico=NULL;
        }

        if (dibujo!=NULL) {
          delete dibujo;
          dibujo=NULL;
        }
        dibujo=new Lista<tGrafico*>();

        grosor=1;
        DoubleBuffered=true;
        ForceCurrentDirectory=true;
        pos=0;
        dibujaLinea=false;
        dibujaRectangulo=false;
        dibujaElipse=false;
        dibujaTexto=false;
        moverGrafico=false;
        copiarGrafico=false;
        dibujaBMP=false;


        encontrado=false;
        mover=false;
        seleccionaPunto=false;
        Color=clWhite;

        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ToolButton3Click(TObject *Sender)
{
     if (grafico!=NULL) {
       dibujo->aniadirElem(grafico);
       dibujaTexto=false;
       dibujaBMP=false;
       grafico=NULL;
     }
     dibujaRectangulo=true;
     dibujaLinea=false;
     dibujaElipse=false;
     dibujaTexto=false;
     seleccionaPunto=false;
     moverGrafico=false;
     dibujaBMP=false;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ToolButton4Click(TObject *Sender)
{
     if (grafico!=NULL) {
       dibujo->aniadirElem(grafico);
       dibujaTexto=false;
       dibujaBMP=false;
       grafico=NULL;
     }
     dibujaElipse=true;
     dibujaLinea=false;
     dibujaRectangulo=false;
     dibujaTexto=false;
     seleccionaPunto=false;
     moverGrafico=false;
     dibujaBMP=false;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ToolButton1Click(TObject *Sender)
{
     if (grafico!=NULL) {
       dibujo->aniadirElem(grafico);
       dibujaTexto=false;
       dibujaBMP=false;
       grafico=NULL;
     }
     dibujaTexto=true;
     dibujaElipse=false;
     dibujaLinea=false;
     dibujaRectangulo=false;
     seleccionaPunto=false;
     moverGrafico=false;
     dibujaBMP=false;

     Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::FormKeyPress(TObject *Sender, char &Key)
{
        if (dibujaTexto)
            if (Key=='\r') {
              dibujaTexto=false;
              dibujo->aniadirElem(grafico);
              grafico=NULL;
            }
            else
                if (Key=='\b') ((tTexto*)grafico)->BorraChar();
                else ((tTexto*)grafico)->ponChar(Key);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ToolButton6Click(TObject *Sender)
{

     if (grafico!=NULL) {
       dibujo->aniadirElem(grafico);
       dibujaTexto=false;
       grafico=NULL;
     }
     if (ToolButton6->Marked==true){
       ToolButton6->Marked=false;
       relleno=false;
     }
     else {
        ToolButton6->Marked=true;
        relleno=true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ToolButton7Click(TObject *Sender)
{
     if (grafico!=NULL) {
       dibujo->aniadirElem(grafico);
       dibujaTexto=false;
       grafico=NULL;
     }
     ColorDialog1->Color=color;
     if (ColorDialog1->Execute())
       color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ToolButton9Click(TObject *Sender)
{
     if (grafico!=NULL) {
       dibujo->aniadirElem(grafico);
       dibujaTexto=false;
       grafico=NULL;
     }
     ColorDialog1->Color=Color;
     if (ColorDialog1->Execute())
       Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ToolButton8Click(TObject *Sender)
{
     if (grafico!=NULL) {
       dibujo->aniadirElem(grafico);
       dibujaTexto=false;
       grafico=NULL;
     }
     TDatos *x=new TDatos(this);
     for (int i=1; i<5; i++) x->ComboBox1->Items->Add(i);
     x->ShowModal();
     grosor=x->num;
     delete x;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ToolButton5Click(TObject *Sender)
{
     if (grafico!=NULL) {
       dibujo->aniadirElem(grafico);
       dibujaTexto=false;
       grafico=NULL;
     }
     TDatos *x=new TDatos(this);
     x->ComboBox1->Items->Add(10);
     x->ComboBox1->Items->Add(12);
     x->ComboBox1->Items->Add(14);
     x->ShowModal();
     tam=x->num;
     delete x;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ToolButton10Click(TObject *Sender)
{
        if (grafico!=NULL) {
          dibujo->aniadirElem(grafico);
          dibujaTexto=false;
          grafico=NULL;
        }

        seleccionaPunto=true;
        dibujaTexto=false;
        dibujaElipse=false;
        dibujaLinea=false;
        dibujaRectangulo=false;
        moverGrafico=false;
        dibujaBMP=false;

        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ToolButton12Click(TObject *Sender)
{
        if (encontrado) {
          dibujo->quitarElem(pos);
          encontrado=false;
          ToolButton10->Marked=false;
        }
        Repaint();

}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ToolButton13Click(TObject *Sender)
{
        if (encontrado) moverGrafico=true;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ToolButton14Click(TObject *Sender)
{
        if (encontrado) copiarGrafico=true;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::Guardar1Click(TObject *Sender)
{
        if (!fichero.IsEmpty()){
            ofstream archivo(fichero.c_str(),ofstream::out);
            tGrafico* aux;
            archivo << Color << endl;
            for (int i=1;i<=dibujo->getNum();i++){
               aux=dibujo->getElem(i);
               aux->salvarFich(archivo);
            }
            archivo.close();
        }
        else GuardarComo1Click(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::Abrir1Click(TObject *Sender){

        if (grafico!=NULL) {
          dibujo->aniadirElem(grafico);
          dibujaTexto=false;
          dibujaBMP=false;
          grafico=NULL;
        }

        TColor c;
        if (OpenDialog1->Execute()) fichero=OpenDialog1->FileName;

        if (!fichero.IsEmpty()){
          ifstream archivo1(fichero.c_str(),ifstream::in);
          Nuevo1Click(Sender);
          tGrafico* grafico=NULL;
          archivo1 >> (int)c;
          Color=c;
          string stipo;
          while (archivo1 >> stipo){
              if (stipo=="\\Rectangulo")grafico=new tRectangulo();
              else
                  if (stipo=="\\Linea")grafico=new tLinea();
                  else
                      if (stipo=="\\Elipse")grafico=new tElipse();
                      else
                          if (stipo=="\\Texto")grafico=new tTexto();
                          else
                              if(stipo=="\\BMP") grafico=new tBMP();

             grafico->LeerFich(archivo1);
             dibujo->aniadirElem(grafico);
          }
          archivo1.close();
        }
}
//---------------------------------------------------------------------------


void __fastcall TFormMenu::ToolButton11Click(TObject *Sender)
{
       if (grafico!=NULL) {
          dibujo->aniadirElem(grafico);
          dibujaTexto=false;
          grafico=NULL;
       }
       if (OpenDialog1->Execute()) bmp=OpenDialog1->FileName.c_str();
       if (!bmp.IsEmpty()) {
         dibujaBMP=true;
         seleccionaPunto=false;
         dibujaTexto=false;
         dibujaElipse=false;
         dibujaLinea=false;
         dibujaRectangulo=false;
         moverGrafico=false;
       }

}
//---------------------------------------------------------------------------


void __fastcall TFormMenu::GuardarComo1Click(TObject *Sender)
{
        if (grafico!=NULL) {
          dibujo->aniadirElem(grafico);
          dibujaTexto=false;
          dibujaBMP=false,
          grafico=NULL;
        }
        if (SaveDialog1->Execute()) fichero=SaveDialog1->FileName;

        if (!fichero.IsEmpty()){
            ofstream archivo(fichero.c_str(),ofstream::out);
            tGrafico* aux;
            archivo << Color << endl;
            for (int i=1;i<=dibujo->getNum();i++){
               aux=dibujo->getElem(i);
               aux->salvarFich(archivo);
            }
            archivo.close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ToolButton15Click(TObject *Sender)
{
        Abrir1Click(Sender);
}
//---------------------------------------------------------------------------

