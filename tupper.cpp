/*

		TUPPER'S SELF REFERENTIAL FUNCTION
		 	by Paul Planchon - 27/06/17
						 version 0.a

graphical version comming soon see https://pdubs.xyz/info/
*/


#include "ttmath/ttmath.h"
#include <iostream>
#include <fstream>

using namespace ttmath;

int main(){

	const int WIDTH = 106;																												//vraiment des constantes ?
	const int HEIGHT = 17;																												//TODO: answer the question above

	//matrice pour faire les prints dans un fichier, plus propre et plus modulable (ex: si on veut en faire une version graphique)
	char image[106][17];

	std::ofstream file;
	file.open("result");

	Big<300,300> kTemp, temp, temp2, temp3, temp4, temp5, temp6;
	Big<1,200>k("960939379918958884971672962127852754715004339660129306651505519271702802395266424689642842174350718121267153782770623355993237280874144307891325963941337723487857735749823926629715517173716995165232890538221612403238855866184013235585136048828693337902491454229288667081096184496091705183454067827731551705405381627380967602565625016981482083418783163849115590225610003652351370343874461848378737238198224849863465033159410054974700593138339226497249461751545728366702369745461014655997933798537483143786841806593422227898388722980000748404719");

	/*
	*		temp = -mod(y, 17)
	*		temp2 = -17 * x
	*		temp3 = temp2 + temp
	*		temp4 = 2 ^ temp3;
	*		temp5 = y / 17;
	*		temp6 = temp5 * temp4
	*/

	for (int y = 0; y < HEIGHT; y++) {
		for(int x = 0; x < WIDTH; x++){
			temp = k;
			temp.Mod(17);
			temp2 = 17;
			temp2.Mul(x);
			temp2.Add(temp);
			temp4 = 2;
			temp4.Pow(temp2);
			temp5 = k;
			temp5.Div(17);
			Floor(temp5);
			temp6 = temp5;
			temp6.Div(temp4);
			temp6.Mod(2);
			temp6 > 0.5 ? image[x][y] = '0' : image[x][y] = ' ';
		}
		k++;
	}

	for(int y = 0; y < HEIGHT; y++){
		for(int x = 0; x < WIDTH; x++){
			file << image[WIDTH - x][y];
		}
		file << std::endl;
	}

	return 0;
}
