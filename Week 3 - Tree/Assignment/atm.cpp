#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
// Nama : Kholis Ardi
// Nim : 1600018244

using namespace std;

struct kholis
{
    char input;
    char bank[15];
    string kode;
    int masukan;
    int pin;
    int nominal;
    int saldo=100000000;
}atm;

void selamat()
{
    cout<<“===========================================================”<<endl;
    cout<<“================SELAMAT DATANG DI BANK INI=================”<<endl;
    cout<<“===========================================================”<<endl<<endl;
}

void cls()
{
    system(“cls”);
}

void menu()
{
    cls();
    selamat();
    
    cout<<“|******** Menu utama BANK INI **********| “<<endl;
    cout<<“| | “<<endl;
    cout<<“| 1. Penambahan saldo 4. Lihat Saldo | “<<endl;
    cout<<“| 2. Penarikan Tunai 5. Keluar | “<<endl;
    cout<<“| 3. Transfer uang | “<<endl;
    cout<<“| | “<<endl;
    cout<<“| **************************************| “<<endl<<endl;
    
    cout<<“Masukan pilihan anda disini : “; cin>> atm.masukan;
    
    switch(atm.masukan){
        
        case 1:{
            cls();
            selamat();
            cout<<“Anda memilih Penambahan saldo”<<endl;
            cout<<“Masukan nominal : RP.”; cin>>atm.nominal;
            atm.saldo=atm.saldo+atm.nominal;
            
            cls();
            selamat();
            cout<<“Penambahan Saldo anda sebesar Rp.”<<atm.nominal<<” Berhasil.”<<endl;
            cout<<“Total saldo Anda saat ini adalah : Rp.”<<atm.saldo<<endl;
            
            goto ulang;
            break;
        }
        
        case 2:{
            cls();
            selamat();
            cout<<“Anda memilih Penarikan Tunai “<<endl;
            cout<<“Masukan nominal penarikan : Rp.”; cin>>atm.nominal;
            atm.saldo=atm.saldo-atm.nominal;
            
            cls();
            selamat();
            cout<<“Anda melalukan Penarikan tunai sebesar Rp.”<<atm.nominal<<endl;
            cout<<“Sisa saldo Anda saat ini adalah : Rp.”<<atm.saldo<<endl;
            
            goto ulang;
            break;
        }
        
        case 3:{
            transfer:
            cls();
            selamat();
            cout<<“Anda memilih Transfer Uang “<<endl<<endl;
            cout<<“Silakan masukan kode bank / (ketik kode untuk melihat kode bank ) : “; cin>>atm.kode;
            if(atm.kode==“kode”){
                cout<<” | ************* Kode transfer BANK *********** | “<<endl;
                cout<<” | | “<<endl;
                cout<<” | 1. BANK INI ( 001 ) 4. BANK K.E ( 004 ) | “<<endl;
                cout<<” | 2. BANK ITU ( 002 ) 5. BANK KOTAN ( 005 ) | “<<endl;
                cout<<” | 3. BANK SANA ( 003 ) 6. BANK KONG ( 006 ) | “<<endl;
                cout<<” | | “<<endl;
                cout<<” | ******************************************** | “<<endl<<endl;
                cout<<“Masukan kode Bank : “; cin>>atm.kode;
            }
            
                if(atm.kode==“001”){    
                    strcpy(atm.bank,“BANK INI”);
                }
                
                else if(atm.kode==“002”){    
                    strcpy(atm.bank,“BANK ITU”);
                }
                
                else if(atm.kode==“003”){    
                    strcpy(atm.bank,“BANK SANA”);
                }
                
                else if(atm.kode==“004”){    
                    strcpy(atm.bank,“BANK K.E”);
                }
                
                else if(atm.kode==“005”){    
                    strcpy(atm.bank,“BANK KOTAN”);
                }
                
                else if(atm.kode==“006”){    
                    strcpy(atm.bank,“BANK KONG”);
                }
                
                else{
                    cout<<“ERROR.. KODE YANG ANDA MASUKAN INVALID”<<endl;
                    goto transfer;
                }
            cout<<“Masukan No.rekening tujuan : “; cin>>atm.masukan;
            cout<<“Masukan Nominal : Rp.”; cin>>atm.nominal;
            
            cls();
            selamat();
            cout<<“Transfer uang sebesar Rp.”<<atm.nominal<<” ke no.rek “<<atm.bank<<” “<<atm.masukan<<” Berhasil.”<<endl;
            atm.saldo=atm.saldo-atm.nominal;
            cout<<“Sisa saldo anda saat ini adalah Rp.”<<atm.saldo;
            
            goto ulang;
            break;
        }
        
        case 4:{
            cls();
            selamat();
            cout<<“Sisa total saldo anda saat ini adalah Rp.”<<atm.saldo;
            
            goto ulang;
            break;
        }
        
        case 5:{
            cls();
            cout<<“\nTerimakasih Sudah menggunakan ATM “<<endl<<endl;
            exit(0);
            break;
        }
        default:{
            cls();
            cout<<“ERROR.. “<<endl;
            menu();
            break;
        }
    }
    
ulang:    //saya membuat pilihan menggulang nya disini untuk memudahkan serta meringkas kodingan
        cout<<“\n\nIngin melakukan transaksi lagi ? (Y/N) “; cin>>atm.input;
        if(atm.input==‘Y’ || atm.input==‘y’){
        menu();
        }
        
        else if(atm.input==‘N’ || atm.input==‘n’){
            cls();
            cout<<“Terimakasih Sudah menggunakan ATM”<<endl;
            exit(0);
        }    
}

void pin()
{
    atm.pin=1600018244;
    
    cout<<“Silakan Masukan Pin anda : “; cin>>atm.masukan;
    
    if(atm.masukan!=atm.pin){
        for(int a=0; a<2; a++){
            cls();
            cout<<“Pin yang anda masukan inValid.”<<endl;
            cout<<“Silakan masukan kembali pin anda : “; cin>>atm.masukan;
            
            if(atm.masukan==atm.pin){
                menu();
            }
        }
            cls();
            cout<<“Anda salah memasukan pin sebanyak 3x”<<endl;
            cout<<“Untuk sementara Akun anda kami blokir, silakan hub. petugas BANK”<<endl;
            cout<<“Terimakasih sudah menggunakan ATM”<<endl;
            exit(0);
    }
    
    else if(atm.masukan==atm.pin){
        menu();
    }
}

main(){
    
    pin();
}
