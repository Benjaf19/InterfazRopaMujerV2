#pragma once
#include "Producto.h"
#include "ConexionBD.h"
#include <mysql.h>
#include <string>


namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ConexionBD^ cnx = gcnew ConexionBD();
	private: MYSQL_ROW col;
	private:	   MYSQL_RES* resul;
	private:	   MYSQL* conexion;
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblProducto;
	private: System::Windows::Forms::Label^ lblPrecio;
	private: System::Windows::Forms::Label^ lblTotal;
	private: System::Windows::Forms::ListBox^ lstCatalogo;
	private: System::Windows::Forms::ListBox^ lstSeleccionados;
	private: System::Windows::Forms::Button^ btnAgregar;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::TextBox^ txtProducto;
	private: System::Windows::Forms::TextBox^ txtPrecio;
	private: System::Windows::Forms::TextBox^ txtTotal;
	private: System::Windows::Forms::Button^ btnLimpiar;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblProducto = (gcnew System::Windows::Forms::Label());
			this->lblPrecio = (gcnew System::Windows::Forms::Label());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->lstCatalogo = (gcnew System::Windows::Forms::ListBox());
			this->lstSeleccionados = (gcnew System::Windows::Forms::ListBox());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->txtProducto = (gcnew System::Windows::Forms::TextBox());
			this->txtPrecio = (gcnew System::Windows::Forms::TextBox());
			this->txtTotal = (gcnew System::Windows::Forms::TextBox());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Catalogo";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(298, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Seleccionados";
			// 
			// lblProducto
			// 
			this->lblProducto->AutoSize = true;
			this->lblProducto->Location = System::Drawing::Point(28, 261);
			this->lblProducto->Name = L"lblProducto";
			this->lblProducto->Size = System::Drawing::Size(50, 13);
			this->lblProducto->TabIndex = 2;
			this->lblProducto->Text = L"Producto";
			// 
			// lblPrecio
			// 
			this->lblPrecio->AutoSize = true;
			this->lblPrecio->Location = System::Drawing::Point(155, 261);
			this->lblPrecio->Name = L"lblPrecio";
			this->lblPrecio->Size = System::Drawing::Size(37, 13);
			this->lblPrecio->TabIndex = 3;
			this->lblPrecio->Text = L"Precio";
			// 
			// lblTotal
			// 
			this->lblTotal->AutoSize = true;
			this->lblTotal->Location = System::Drawing::Point(307, 261);
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->Size = System::Drawing::Size(31, 13);
			this->lblTotal->TabIndex = 4;
			this->lblTotal->Text = L"Total";
			// 
			// lstCatalogo
			// 
			this->lstCatalogo->FormattingEnabled = true;
			this->lstCatalogo->Location = System::Drawing::Point(28, 55);
			this->lstCatalogo->Name = L"lstCatalogo";
			this->lstCatalogo->Size = System::Drawing::Size(201, 186);
			this->lstCatalogo->TabIndex = 5;
			this->lstCatalogo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::lstCatalogo_SelectedIndexChanged);
			// 
			// lstSeleccionados
			// 
			this->lstSeleccionados->FormattingEnabled = true;
			this->lstSeleccionados->Location = System::Drawing::Point(297, 55);
			this->lstSeleccionados->Name = L"lstSeleccionados";
			this->lstSeleccionados->Size = System::Drawing::Size(205, 186);
			this->lstSeleccionados->TabIndex = 6;
			// 
			// btnAgregar
			// 
			this->btnAgregar->Location = System::Drawing::Point(235, 125);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(51, 23);
			this->btnAgregar->TabIndex = 7;
			this->btnAgregar->Text = L"=>";
			this->btnAgregar->UseVisualStyleBackColor = true;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &Form1::btnAgregar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(510, 125);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(51, 23);
			this->btnEliminar->TabIndex = 8;
			this->btnEliminar->Text = L"X";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &Form1::btnEliminar_Click);
			// 
			// txtProducto
			// 
			this->txtProducto->Location = System::Drawing::Point(28, 294);
			this->txtProducto->Name = L"txtProducto";
			this->txtProducto->Size = System::Drawing::Size(100, 20);
			this->txtProducto->TabIndex = 9;
			// 
			// txtPrecio
			// 
			this->txtPrecio->Location = System::Drawing::Point(158, 293);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->Size = System::Drawing::Size(100, 20);
			this->txtPrecio->TabIndex = 10;
			// 
			// txtTotal
			// 
			this->txtTotal->Location = System::Drawing::Point(310, 294);
			this->txtTotal->Name = L"txtTotal";
			this->txtTotal->Size = System::Drawing::Size(100, 20);
			this->txtTotal->TabIndex = 11;
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->Location = System::Drawing::Point(461, 290);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(75, 23);
			this->btnLimpiar->TabIndex = 12;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = true;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &Form1::btnLimpiar_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(569, 370);
			this->Controls->Add(this->btnLimpiar);
			this->Controls->Add(this->txtTotal);
			this->Controls->Add(this->txtPrecio);
			this->Controls->Add(this->txtProducto);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnAgregar);
			this->Controls->Add(this->lstSeleccionados);
			this->Controls->Add(this->lstCatalogo);
			this->Controls->Add(this->lblTotal);
			this->Controls->Add(this->lblPrecio);
			this->Controls->Add(this->lblProducto);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//1) Para respetar la forma canonica ortodoxa, dejar el codigo autogenerado así: private: System::Void Form1_Load(System::Object^ , System::EventArgs^);
	//3. Agregar lista de productos a lstCatalogo
	private: ArrayList^ lstProds;
	private: System::Void Form1_Load(System::Object^ , System::EventArgs^ );
	private: System::Void btnAgregar_Click(System::Object^ , System::EventArgs^ );
	private: System::Void btnEliminar_Click(System::Object^ , System::EventArgs^ );
	private: System::Void btnLimpiar_Click(System::Object^ , System::EventArgs^ );
	private: System::Void lstCatalogo_SelectedIndexChanged(System::Object^ , System::EventArgs^ );
	private: System::Void actualizarTotal();
};
}
