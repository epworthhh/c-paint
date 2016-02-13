//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormAux.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TDatos *Datos;
//---------------------------------------------------------------------------
__fastcall TDatos::TDatos(TComponent* Owner)
     : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDatos::ButtonCancelClick(TObject *Sender)
{
     Close();
}
//---------------------------------------------------------------------------


void __fastcall TDatos::ButtonOKClick(TObject *Sender)
{
     num=StrToInt(ComboBox1->Text);
     Close();
}
//---------------------------------------------------------------------------

