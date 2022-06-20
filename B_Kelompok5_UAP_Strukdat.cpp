#include <iostream>
#include <conio.h>
using namespace std; 

struct tNode{
	string kirim, terima, surat; //variable buat ngambil data
	tNode *next;
};

tNode *top = NULL;

void push(string pengirim, string penerima, string Surat){
	tNode *ptr; 
	
	cout << "\nSilahkan Tumpuk Surat Anda!"<<endl; 
	cout << "Nama Pengirim\t\t : "; getline(cin, pengirim);
	cout << "Nama Penerima\t\t : "; getline(cin, penerima);
	cout << "Jenis Surat\t\t : "; getline(cin, Surat);
	 
	ptr = new tNode; 
	ptr->kirim = pengirim; 
	ptr->terima = penerima;
	ptr->surat = Surat;
	ptr->next = NULL; 
	if(top!=NULL)
		ptr->next = top; 
	top = ptr; 	
	cout <<"\n" << ptr->surat << " telah masuk ke dalam Tumpukan!"<<endl; 
}

void pop(){
	tNode *temp; 
	
	if(top==NULL)
		cout <<"Tumpukan Kosong, tidak ada yang bisa dihapus!"<<endl; 
	else 
	temp = top; 
	top = top->next; 
	cout << "\nSurat dengan dari " << temp->kirim << " untuk " << temp->terima << " telah diambil!"<<endl; 
	delete temp; 
}

void print(){
	tNode *ptr1=top;
	 
	cout << "\nTUMPUKAN SURAT\n" <<endl; 	
	if(ptr1==NULL){
		cout << "Kosong" <<endl;
	} else {
		while(ptr1!=NULL){
		cout << ptr1->surat << " (" << ptr1->kirim << "->" << ptr1->terima << ")" <<endl; 
		ptr1=ptr1->next; 
		}
	}
}

void display(){
	cout << "1. Tumpuk Surat\n";
	cout << "2. Ambil Surat\n";
	cout << "3. Check Tumpukan Surat\n";
	cout << "4. EXIT\n\n";
}

int main(){
	int pilih; 
	string kirim, terima, surat;
	
	do{
	
		cout << "\tPROGRAM MENUMPUK SURAT"; 
		cout<< "\n--------------------------------------\n\n";
		display();
		cout << "Masukkan Pilihan\t : "; cin >> pilih; 
		cin.ignore(1,'\n');
		switch(pilih){
			case 1:
			push(kirim, terima, surat); 
			getch();
			break; 
			case 2:
			pop(); 
			getch();
			break;
			case 3:
			print(); 
			getch();
			break;
			case 4:
			cout <<"\nTerima Kasih!"<<endl;
			getch();   
			break;
			default:
			cout << "Maaf, pilihan tidak tersedia!"<<endl;
			getch(); 
			break;  
		} 	
		system("cls"); 
	} while (pilih!=4); 

		return 0; 
}
