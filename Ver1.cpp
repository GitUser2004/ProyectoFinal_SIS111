#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

//  MENUS
void menu_principal();
void menucaja();
void menuin();
void menuac();
void menureportes();

// INTERIOR MENU
void data();
void desplegar();

// ESTRUCTURA BASE DE DATOS
struct est{
char nom[30];
int nit;
};
struct inv{
char product[50];
int price;
};
int main(){
	system("color 0A");
	menu_principal();
}
void menu_principal(){
	int i;
  for (;;)
  {
  system("cls");
  cout << "     MENU PRINCIPAL DE OPCIONES" << endl;
  cout << "====================================" << endl;
  cout << "1.- Caja" << endl;
  cout << "2.- Atencion al cliente" << endl;
  cout << "3.- Inventario" << endl;
  cout << "4.- Reportes" << endl;
  cout << "5.- Cerrar programa" << endl;
  cout << "Que opcion desea : " ;cin >> i;
  switch (i)
  {
      case 1: menucaja();break;
      case 2: menuac();break;
      case 3: menuin();break;
      case 4: menureportes();break;
      case 5: exit(0);
  }
   cout << "\n";
   system("pause");
  }
}
void menucaja(){
	int i=0;
	  for (;;)
	  {
	  system("cls");
	  cout << "     MENU CAJA" << endl;
	  cout << "====================================" << endl;
	  cout << "1.- Compra" << endl;
	  cout << "2.- Venta" << endl;
	  cout << "3.- Volver menu principal" << endl;
	  cout << "Que opcion desea : " ;cin >> i;
	  switch (i)
	  {
	      case 1: break;
	      case 2: break;
	      case 3: menu_principal();break;
	  }
	   cout << "\n";
	   system("pause");
	  }
}

void menuac(){
	int i=0;
	  for (;;)
	  {
	  system("cls");
	  cout << "     MENU DE ATENCION AL CLIENTE" << endl;
	  cout << "====================================" << endl;
	  cout << "1.- Registrar datos" << endl;
	  cout << "2.- Buscar datos por NIT" << endl;
	  cout << "3.- Buscar datos por nombre" << endl;
	  cout << "4.- Generar cliente aleatorio" << endl;
	  cout << "5.- Volver menu principal" << endl;
	  cout << "Que opcion desea : " ;cin >> i;
	  switch (i)
	  {
	      case 1: data();break;
	      case 2: break;
	      case 3: break;
	      case 4: break;
	      case 5: menu_principal();break;
	  }
	   cout << "\n";
	   system("pause");
	  }
}
void menuin(){
	int i=0;
	  for (;;)
	  {
	  system("cls");
	  cout << "     MENU INVENTARIO" << endl;
	  cout << "====================================" << endl;
	  cout << "1.- Mostrar inventario" << endl;
	  cout << "2.- Eliminar producto" << endl;
	  cout << "3.- Agregar producto" << endl;
	  cout << "4.- Lista de clientes registrados" << endl;
	  cout << "5.- Volver menu principal" << endl;
	  cout << "Que opcion desea : " ;cin >> i;
	  switch (i)
	  {
	      case 1: break;
	      case 2: break;
	      case 3: break;
	      case 4: desplegar();break;
	      case 5: menu_principal();break;
	  }
	   cout << "\n";
	   system("pause");
	  }
}
void menureportes(){
	int i=0;
	  for (;;)
	  {
	  system("cls");
	  cout << "     MENU REPORTES" << endl;
	  cout << "====================================" << endl;
	  cout << "1.- Productos mas vendidos" << endl;
	  cout << "2.- Margen de ganancia desde apertura" << endl;
	  cout << "3.- Numero de clientes que se atendio" << endl;
	  cout << "4.- Numero de clientes registrados total" << endl;
	  cout << "5.- Volver menu principal" << endl;
	  cout << "Que opcion desea : " ;cin >> i;
	  switch (i)
	  {
	      case 1: break;
	      case 2: break;
	      case 3: break;
	      case 4: break;
	      case 5: menu_principal();break;
	  }
	   cout << "\n";
	   system("pause");
	  }
}
/*INTERIOR MENU*/
void data(){
	est fc;
fstream file("factura.dat",ios::out|ios::binary|ios::app); // guarda los datos
for(int i=0;i<1;i++){
	cout<<"Señor(s): ";cin>>fc.nom;
	cout<<"NIT/CI: ";cin>>fc.nit;
	file.write((char*)&fc,sizeof(fc));
	}
file.close();
}
void desplegar(){
		est fc;
		int i=1;
fstream file("factura.dat",ios::in|ios::binary);
while(file.read((char*)&fc,sizeof(fc))){
	cout<<"Registro numero: "<<i<<endl;
	cout<<"Nombre : "<<fc.nom<<endl;
	cout<<"NIT/CI: "<<fc.nit<<endl;
	i++;
	}
file.close();
}

