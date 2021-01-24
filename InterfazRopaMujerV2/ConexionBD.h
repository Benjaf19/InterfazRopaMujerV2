#pragma once
#include <mysql.h>
#include<sstream>
#include <string>
#include<iostream>
#include "Producto.h"
using namespace System::Collections;
ref class ConexionBD
{
private:
	MYSQL* conn;

	MYSQL_ROW row;
	MYSQL_RES* res;
public:
	ConexionBD();
	MYSQL* conectarBD();
	MYSQL_ROW despliegaProductos();
};

