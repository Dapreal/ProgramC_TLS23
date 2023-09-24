#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
using namespace std;


int main() {
	unordered_map<string, int> buah = {
		{"Mangga", 9000},
		{"Apel", 5000},
		{"Sirsak", 7000},
		{"Terong", 6000},
		{"Jambu", 6000},
		{"Kelengkeng", 10000},
		{"Jeruk", 5000},
		{"Kelapa", 12000},
		{"Nanas", 8000},
		{"Durian", 30000}
	};

	unordered_map<string, int> keranjang;
	string belanja;
	
	cout<<"Selamat datang di toko buah Al-Fakiha"<<endl<<"Berikut adalah list buah-buahan yang tersedia di toko kami: "<<"\n"<<endl;
	
	
	for(const auto& key_value : buah){
		cout<<key_value.first<<": "<<key_value.second<<endl;
	}
	
	cout<<"\nSilahkan memilih buah yang anda inginkan:"<<endl;	
		
	while(true) {
		cin >> belanja;
		if(buah.find(belanja) == buah.end()) {
			cout << "ga ada";
		} else {
			keranjang[belanja] += 1;
		}
		
		cout << "\nDaftar belanja anda: \n";
		for(const auto& key_value : keranjang) {
			cout << key_value.first << "\t\t: " << key_value.second << "\n";
		}
		
		cout << "apakah ingin menyelesaikan pembelian? (yes/no) \n";
		string konfirmasi;
		cin >> konfirmasi;
		if(konfirmasi == "yes") {
			cout << "\nRincian harga :\n";
			int total;
			for(const auto& key_value : keranjang) {
				int cur = key_value.second * buah[key_value.first];
				cout << key_value.first << "\t\t: " << cur << "\n";
				total += cur;	
			}
			cout << "total harga\t: " << total;
			break;
		} else{
			cout<<"\nSilakan pilih buah selanjutnya: "<<endl;
		}
	}
}

