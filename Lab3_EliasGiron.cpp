#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

int mcd (int a, int b){
	int residuo = a % b;
	if (residuo == 0){
		return b;
	} else {
		residuo = a % b;
		a = b;
		b = residuo;
		return mcd(a, b);
	}
}
int* calculadoraPrimos(){
	int* num_primos = new int[25];
	num_primos[0] = 2;
	num_primos[1] = 3;
	num_primos[2] = 5;
	num_primos[3] = 7;
	num_primos[4] = 11;
	num_primos[5] = 13;
	num_primos[6] = 17;
	num_primos[7] = 19;
	num_primos[8] = 23;
	num_primos[9] = 29;
	num_primos[10] = 31;
	num_primos[11] = 37;
	num_primos[12] = 41;
	num_primos[13] = 43;
	num_primos[14] = 47;
	num_primos[15] = 53;
	num_primos[16] = 59;
	num_primos[17] = 61;
	num_primos[18] = 67;
	num_primos[19] = 71;
	num_primos[20] = 73;
	num_primos[21] = 79;
	num_primos[22] = 83;
	num_primos[23] = 89;
	num_primos[24] = 97;


	return num_primos;
}

int main(){
	char resp = 's';
	int opcion = 0, a = 0, b = 0, num_ejercicio2 = 0, cont = 0, temp = 0;
	stringstream salida;
	int* arreglo_primos = calculadoraPrimos();
	while (resp == 's' || resp == 'S'){
		cout << "1. Ejercicio 1 \n"
			"2. Ejercicio 2 \n"
			"3. Ejercicio 3 \n"
			"Ingrese una opcion: ";
		cin >> opcion;
		switch (opcion){
			case 1:
				cout << "Ingrese el valor de a: "<<endl;
				cin >> a;
				cout << "Ingrese el valor de b: "<<endl;
				cin >> b;
				while (b > a || a < 0 || b < 0){
					cout << "El valor de a debe ser mayor a b y positivo"<<endl;
					cout << "Ingrese a: "<<endl;
					cin >> a;
					cout << "Ingrese b: "<<endl;
					cin >> b;
				}
				cout <<"El máximo común divisor es: "<<mcd(a, b)<<endl;
			break;
			case 2:
				cout << "Ingrese un numero: ";
				cin >> num_ejercicio2;
				for(int i = 0; i < 25; i++){
					while (num_ejercicio2 % arreglo_primos[i] == 0){
						cont++;						
						num_ejercicio2 = num_ejercicio2/arreglo_primos[i];
					}
					if(cont != 0){
						salida << std::to_string(arreglo_primos[i]) << "^" << cont << " * ";
						cont = 0;
					}
				}
				cout << salida.str()<<endl;
			break;
			case 3:
			break;
		}
	cout << "Desea regresar[s/n]: ";
	cin >> resp;
	}

}
