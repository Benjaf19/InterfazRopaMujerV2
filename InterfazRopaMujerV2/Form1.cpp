#include "pch.h"
#include "Form1.h"


//1.1) Se le quita el private y se le agrega la ubicacion del "Form1_Load" (ubicada en el Form1.h)::Nombredelmetodo
System::Void CppCLRWinformsProjekt::Form1::Form1_Load(System::Object^ sender, System::EventArgs^ e)
{
	conexion = cnx->conectarBD();
	
	
	lstProds = gcnew ArrayList(); //gcnew es para que se utilice el garbage collector como en los objetos dinamicos
	//Agregamos de la BD
	int qstate = 0;
	std::string query = "select distinct Prenda, Marca, Stock, Precio, Descuento,Material,Estampado from catalogo_ropa_mujer";
	const char* q = query.c_str();
	std::string aux[7] ;
	String^ aux2;
	qstate = mysql_query(conexion, q);
	if (!qstate) {
		resul = mysql_store_result(conexion);
		while (col = mysql_fetch_row(resul)) {
			for (int i= 0; i < 7;i++) {
				aux[i] = col[i];
			}
			
			lstProds->Add(gcnew Producto(gcnew String(aux[0].c_str()), gcnew String(aux[1].c_str()), stoi(aux[2]), stoi(aux[3]), stoi(aux[4]), gcnew String(aux[5].c_str()), gcnew String(aux[6].c_str())));
			//, row[1], row[2], row[3], row[4]);
		}

	}
	else {
		std::cout << "Chale";

	}
	
	/*lstProds->Add(gcnew Producto("Pantalon", "Levis", 30, 1000, 0, "Mezclilla", "Liso"));
	lstProds->Add(gcnew Producto("Vestido", "Julio", 31, 900, 0, "Poliuretano", "Liso Azul"));
	lstProds->Add(gcnew Producto("Sueter", "Dockers", 33, 450, 0, "Algodon", "Tejido de punto"));
	lstProds->Add(gcnew Producto("Capa", "Valentino", 34, 380, 0, "Seda", "Rombos"));
	lstProds->Add(gcnew Producto("Falda", "Zara", 35, 660, 0, "Terlenca", "Rosa"));
	lstProds->Add(gcnew Producto("Saco", "Ermenegildo", 36, 720, 0, "Poliester", "Liso Negro"));
	lstProds->Add(gcnew Producto("Chaleco", "Oscar de la Renta", 38, 1100, 0, "Pluma", "Abombado"));*/

	for each (Producto ^ p in lstProds)
	{
		lstCatalogo->Items->Add(p->getNombre());
	}

	lstCatalogo->SelectedIndex = 0;

	txtTotal->Text = String::Format("{0:C}", 0);

}

	System::Void CppCLRWinformsProjekt::Form1::btnAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
		int i = lstCatalogo->SelectedIndex;
		lstSeleccionados->Items->Add((Producto^)lstProds[i]); //A la lista de texto, se pueden agregar objetos.
		lstSeleccionados->SelectedIndex = lstSeleccionados->Items->Count - 1; //Ir agregando a la lista
		actualizarTotal();
	}
	System::Void CppCLRWinformsProjekt::Form1::btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		int i = lstSeleccionados->SelectedIndex;
		if (i == -1) {
			return;
		}
		lstSeleccionados->Items->RemoveAt(i);
		actualizarTotal();
	}
	System::Void CppCLRWinformsProjekt::Form1::btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
		lstSeleccionados->Items->Clear();
		txtProducto->Text = L"";
		txtPrecio->Text = L"";
		txtTotal->Text = String::Format("{0:C}", 0);
	}

	System::Void CppCLRWinformsProjekt::Form1::lstCatalogo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int i = lstCatalogo->SelectedIndex;
		txtProducto->Text = ((Producto^)lstProds[i])->getNombre(); //Para reinterpretar lstProds como un objeto de tipo Producto, se pone el tipo de objeto que queremos para tener acceso a la funcion getNombre();
		txtPrecio->Text = ((Producto^)lstProds[i])->getPrecio().ToString(); //Todos los objetos de .NET tienen incluidos el metodo ToString
	}

	System::Void CppCLRWinformsProjekt::Form1::actualizarTotal(){
		float total = 0;
		for each (Producto ^ p in lstSeleccionados->Items)//Para cada ProductoEliminable p en la lstSeleccionados, su Item
		{
			total += p->getPrecio();
		}
		txtTotal->Text= String::Format("{0:C}", total);
	}