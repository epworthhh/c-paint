//---------------------------------------------------------------------------

#ifndef UFormAuxH
#define UFormAuxH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TDatos : public TForm
{
__published:	// IDE-managed Components
     TButton *ButtonOK;
     TButton *ButtonCancel;
     TComboBox *ComboBox1;
     void __fastcall ButtonCancelClick(TObject *Sender);
     void __fastcall ButtonOKClick(TObject *Sender);
private: 	// User declarations
public:   int num;// User declarations
     __fastcall TDatos(TComponent* Owner);
};
//---------------------------------------------------------------------------
//extern PACKAGE TDatos *Datos;
//---------------------------------------------------------------------------
#endif
