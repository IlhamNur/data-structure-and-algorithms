#include <iostream>
#include <string>

using namespace std;

struct node
{
    string Name;
    node *next;
};

class List
{
private:
    node *head, *tail;
public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void create_daftar(string receiver)
    {
        node *temp = new node;
        temp->Name = receiver;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void display_all()
    {
        int daftarNum = 1;
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << daftarNum << ". " << temp->Name << endl;
            ++daftarNum;
            temp = temp->next;
            
        }
    }

    void delete_position(int pos)
    {
        node *current = new node;
        node *previous = new node;
        node *next = new node;
        current = head;
        for (int i = 1;i<pos;i++)
        {
            if (current == NULL)
                return;
            previous = current;
            current = current->next;
        }
        next = current->next;
        previous->next = current->next;
        delete current;
    }

    void delete_head()
    {
        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }
    
};

int main()
{
    List Daftar;
    int choice, position, n;
    string Name;

    while (1) {
        cout << "\nDaftar Penerima Zakat Fitrah (Mustahik) Mushola Alfalah: " << endl;
        cout << "=========================================================";
        cout << endl;
            Daftar.display_all();
            cout << endl;
        cout << "========================================================="<< endl;
        cout << "\n=======================||MENU||==========================";
        cout << "\n1. Tambahkan Nama Penerima" << endl;
        cout << "2. Hapus Nama Penerima (Sudah disalurkan)" << endl;
        cout << "3. Keluar dari program\n" << endl;
        cout << "Masukkan opsi: "; cin >> choice;

        switch (choice)
        {
        case 1:
        	cout << "\nMasukkan jumlah penerima yang akan ditambahkan: ";
        	cin >> n;
        	cout << "\nMasukkan nama penerima: ";
        	cout << "\n";
        	while(n--) 
			{
            	cin >> Name;
            	Daftar.create_daftar(Name);
        	}
        	cout << endl;
            break;
        case 2:
        	cout << "\nMasukkan jumlah penerima yang akan dihapus: ";
        	cin >> n;
			cout << "\nMasukkan nomor dari penerima yang ingin dihapus: ";
			cout << "\n";
			while(n--) 
			{
            	cin >> position;
           	 	if (position == 1)
                	Daftar.delete_head();
            	else
                	Daftar.delete_position(position);
        	}
            break;
        case 3:
            exit(1);
            break;
        default:
            cout << "\n" << choice << " Bukan termasuk opsi. Tolong coba opsi lain." << endl;
            break;
        }
        
    }
    return 0;
}
