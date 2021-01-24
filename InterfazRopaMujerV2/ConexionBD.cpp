#include "pch.h"
#include "ConexionBD.h"

ConexionBD::ConexionBD() {
	//Constructor
}
MYSQL* ConexionBD::conectarBD() {


	

	conn = mysql_init(0);
	int final;

	conn = mysql_real_connect(conn, "localhost", "root", "n0m3l0", "ropamujer", 3306, NULL, 0);
	if (conn) {
		final = 1;
	}
	else {
		final = 0;
	}
		//puts("si jalo");

		
	return conn;

}
MYSQL_ROW ConexionBD:: despliegaProductos() {
	int qstate = 0;
	//ArrayList^ lista = gcnew ArrayList();
	std::string query = "select Prenda, Tipo, Corte, Cuello, Manga from catalogo_ropa_mujer";
	const char* q = query.c_str();
	std::string aux = "";
	String^ aux2;
	qstate = mysql_query(conn, q);
	if (!qstate) {
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res)) {
			
			aux = row[0];
			aux2= gcnew String(aux.c_str());
			
			 //, row[1], row[2], row[3], row[4]);
		}
		//lista->Add(gcnew Producto(aux2, "Scappino", 32, 850, 0, "Satin", "Liso Rosa"));
	}
	else {
		std::cout << "Chale";
		
	}
	return row;
}