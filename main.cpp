//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Practica5.res");
USEFORM("UFormMenu.cpp", FormMenu);
USEUNIT("UGrafico.cpp");
USEUNIT("ULinea.cpp");
USEUNIT("ULista.cpp");
USEUNIT("URectangulo.cpp");
USEUNIT("UElipse.cpp");
USEUNIT("UTexto.cpp");
USEFORM("UFormAux.cpp", Datos);
USEUNIT("UBMP.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFormMenu), &FormMenu);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
