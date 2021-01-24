#pragma once
using namespace System; //Para trabajar con los objetos de .NET 

ref class Producto : public System::Object // Todas las clases deben ser hijas de System::Object
{
private: String^ nombre;
private: String^ marca;
private: float talla;
private: float precio;
private: int descuento;
private: String^ material;
private: String^ estampado;
private: float preciofinal;

public: Producto();
public: Producto(String^, String^, float, float, int, String^, String^);

public: String^ getNombre();
public: String^ getMarca();
public: float getTalla();
public: float getPrecio();
public: int getDescuento();
public: String^ getMaterial();
public: String^ getEstampado();
public: float getPreciofinal();

public: float calcDescuento(int descuento, float precio);
public: String^ ToString() override;//2 En .NET ya existe una funcion ToString por tanto, debe sobreescribirse, en este caso, se necesita escribir la palabra override para hacerlo.
//2.FINAL Ahora vamos a la implementación de todas estas funciones, en Producto.cpp
};

