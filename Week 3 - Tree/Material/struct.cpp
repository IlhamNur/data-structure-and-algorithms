#include<iostream>

using namespace std;

/*
    struct: data yang dibentuk beberapa data
    buah = jeruk apel semangka
    rasa berat warna 

    rasaJeruk = 
    beratJeruk

    array vector 
*/

struct buah {
    string rasa;
    int berat;
};

int main (){
    buah jeruk;
    buah semangka;
    jeruk.rasa = "kecut";
    jeruk.berat = 3;
    semangka.rasa = "manis";
    cout << "rasa jeruk    : " << jeruk.rasa << endl;
    cout << "berat jeruk    : " << jeruk.berat << endl;
    cout << "rasa semangka : " << semangka.rasa << endl;

    
    return 0;
}