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
void eliminarproducto();
void totalregistrados();
// INTERIOR MENU
void data();
void desplegar();
void datainventario();
void desplegarinv();
void busquedanit();
void busquedanom();
// ESTRUCTURA BASE DE DATOS
struct est{
char nom[30];
int nit;
};
struct inv{
char product[50];
int code;
int pricec;
int pricev;
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
	      case 1: datainventario();break;
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
	  cout << "4.- Volver menu principal" << endl;
	  cout << "Que opcion desea : " ;cin >> i;
	  switch (i)
	  {
	      case 1: data();break;
	      case 2: busquedanit();break;
	      case 3: busquedanom();break;
	      case 4: menu_principal();break;
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
	      case 1: desplegarinv();break;
	      case 2: eliminarproducto();break;
	      case 3: datainventario();break;
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
	      case 4: totalregistrados();break;
	      case 5: menu_principal();break;
	  }
	   cout << "\n";
	   system("pause");
	  }
}
/*INTERIOR MENU*/
void data(){
	est fc;
fstream file("factura.dat",ios::out|ios::binary|ios::app); // ios::app guarda los datos
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
void datainventario(){
	inv fi;
fstream file("inventario.dat",ios::out|ios::binary|ios::app); // ios::app guarda los datos
for(int i=0;i<1;i++){
	cout<<"Nombre producto: ";cin>>fi.product;
	cout<<"Codigo: ";cin>>fi.code;
	cout<<"Precio de compra: ";cin>>fi.pricec;
	cout<<"Precio de venta: ";cin>>fi.pricev;
	file.write((char*)&fi,sizeof(fi));
	}
file.close();
}
void desplegarinv(){
		inv fi;
fstream file("inventario.dat",ios::in|ios::binary);
cout<<"Nombre"<<"   "<<char(178)<<"   "<<"codigo"<<"   "<<char(178)<<"   "<<"Precio de compra"<<"   "<<char(178)<<"   "<<"Precio de venta"<<endl;
while(file.read((char*)&fi,sizeof(fi))){
	cout<<fi.product<<"..."<<fi.code<<"........"<<fi.pricec<<"Bs................"<< fi.pricev<<"Bs"<<endl;
	}
file.close();
}



void busquedanit(){
	est fc;
	int o;
	cout<<"Cual NIT desea buscar:";cin>>o;
fstream file("factura.dat",ios::in|ios::binary);
while(file.read((char*)&fc,sizeof(fc))){
	 if (o==fc.nit ){
	 	cout<<"El nombre asociado al NIT: "<<fc.nit<<" es:" <<fc.nom;
	 }
	}
file.close();
}
void busquedanom(){
	est fc;
	string o;
	cout<<"Cual nombre desea buscar:";cin>>o;
fstream file("factura.dat",ios::in|ios::binary);
while(file.read((char*)&fc,sizeof(fc))){
	 if (fc.nom==o){
	 	cout<<"El NIT asociado al nombre: "<<fc.nom<<" es:" <<fc.nit<<endl;
	 }
	}
file.close();
}
void eliminarproducto() {
    int codigo;
    cout << "Ingrese el código del producto que desea eliminar: ";
    cin >> codigo;
    fstream file("inventario.dat", ios::in | ios::binary);
    fstream tempFile("temp.dat", ios::out | ios::binary);

    if (!file || !tempFile) {
        cerr << "Error al abrir archivos." << endl;
        return;
    }
    inv fi;
    bool encontrado = false;

    while (file.read((char*)&fi, sizeof(fi))) {
        if (fi.code != codigo) {
            // Copiar datos al archivo temporal, excepto el producto a eliminar
            tempFile.write((char*)&fi, sizeof(fi));
        } else {
            encontrado = true;
        }
    }
    file.close();
    tempFile.close();
    // Eliminar el archivo original
    remove("inventario.dat");
    // Renombrar el archivo temporal al archivo original
    rename("temp.dat", "inventario.dat");
    if (encontrado) {
        cout << "Producto eliminado con éxito." << endl;
    } else {
        cout << "Producto no encontrado en el inventario." << endl;
    }
}
void totalregistrados(){
		est fc;
		int i=0;
	fstream file("factura.dat",ios::in|ios::binary);
	while(file.read((char*)&fc,sizeof(fc))){
		i++;
		}
	cout<<"Se registraron un total de: "<<i<<" personas";
	file.close();
}
