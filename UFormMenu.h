//---------------------------------------------------------------------------

#ifndef UFormMenuH
#define UFormMenuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>

#include "UGrafico.h"
#include "ULinea.h"
#include "ULista.h"
#include "URectangulo.h"
#include "UElipse.h"
#include "UTexto.h"
#include <Dialogs.hpp>
#include "UFormAux.h"
#include "UBMP.h"
//---------------------------------------------------------------------------
class TFormMenu : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Archivos1;
        TMenuItem *Nuevo1;
        TMenuItem *Abrir1;
        TMenuItem *Guardar1;
        TMenuItem *GuardarComo1;
        TMenuItem *N1;
        TMenuItem *Salir1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TToolButton *ToolButton7;
        TToolButton *ToolButton8;
        TToolButton *ToolButton9;
        TToolButton *ToolButton10;
        TToolButton *ToolButton12;
        TToolButton *ToolButton13;
        TToolButton *ToolButton14;
        TToolButton *ToolButton15;
        TImageList *ImageList1;
        TColorDialog *ColorDialog1;
        TToolButton *ToolButton11;
        TSaveDialog *SaveDialog1;
        TOpenDialog *OpenDialog1;
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall ToolButton2Click(TObject *Sender);
        void __fastcall Nuevo1Click(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
        void __fastcall ToolButton4Click(TObject *Sender);
        void __fastcall ToolButton1Click(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall ToolButton6Click(TObject *Sender);
        void __fastcall ToolButton7Click(TObject *Sender);
        void __fastcall ToolButton9Click(TObject *Sender);
     void __fastcall ToolButton8Click(TObject *Sender);
     void __fastcall ToolButton5Click(TObject *Sender);
        void __fastcall ToolButton10Click(TObject *Sender);
        void __fastcall ToolButton12Click(TObject *Sender);
        void __fastcall ToolButton13Click(TObject *Sender);
        void __fastcall ToolButton14Click(TObject *Sender);
        void __fastcall Guardar1Click(TObject *Sender);
        void __fastcall Abrir1Click(TObject *Sender);
        void __fastcall ToolButton11Click(TObject *Sender);
        void __fastcall GuardarComo1Click(TObject *Sender);
        void __fastcall ToolButton15Click(TObject *Sender);
private:
        bool dibujaLinea, dibujaRectangulo, dibujaElipse,dibujaTexto, mover,
             seleccionaPunto,encontrado,moverGrafico,copiarGrafico,dibujaBMP;
        tGrafico* grafico;
        tGrafico* copiaGraf;
        Lista<tGrafico*>* dibujo;
        bool relleno,rellenoAux;
        int grosor,tam,pos,grosorAux;
        TColor color,colorAux;
        AnsiString cadena,fichero,bmp;
        ofstream archivo;
        ifstream archivo1;
                        // User declarations

public:		        // User declarations
        __fastcall TFormMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMenu *FormMenu;
//---------------------------------------------------------------------------
#endif
