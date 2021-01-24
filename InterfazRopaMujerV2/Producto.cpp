#include "pch.h"
#include "Producto.h"

//3. Implementacoin de funciones

Producto:: Producto() //Recordar que para implementar funciones, debo indicar de que Biblioteca vienen
{

}

Producto::Producto(String^ nombre, String^ marca, float talla, float precio, int descuento, String^ material, String^ estampado) 
{
	this->nombre = nombre;
	this->marca = marca;
	this->talla = talla;
	this->precio = precio;
	this->descuento = descuento;
	this->material = material;
	this->estampado = estampado;
}

String^ Producto::getNombre() {
	return nombre;
}

String^ Producto::getMarca() {
	return marca;
}

float Producto::getTalla() {
	return talla;
}

float Producto::getPrecio() {
	return precio;
}

int Producto::getDescuento() {
	return descuento;
}

String^ Producto::getMaterial() {
	return material;
}

String^ Producto::getEstampado() {
	return estampado;
}

float Producto::getPreciofinal() {
	return preciofinal;
}

float Producto::calcDescuento(int descuento, float precio)
{
	preciofinal = precio - (precio * (descuento / 100));
	return preciofinal;
}

String^ Producto::ToString(){
	return String::Format("{0}\t{1:C}", nombre, precio); //El ":C" indica que el numero va a ser desplegado como currency o moneda
}