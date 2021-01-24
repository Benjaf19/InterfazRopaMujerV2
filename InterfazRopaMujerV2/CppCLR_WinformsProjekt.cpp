#include "pch.h"
#include "Form1.h"


//int main(array<System::String ^> ^args)
//{
//    return 0;
//}


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
	ConexionBD cnx;
	printf("%s",cnx.conectarBD());
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLRWinformsProjekt::Form1()); 
	return 0;
}