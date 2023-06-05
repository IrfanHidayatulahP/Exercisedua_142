#include <iostream>
#include <vector>
using namespace std;

class Penerbit;
class Pengarang {
public:
    string nama;
    vector<Penerbit*> Nama_Penerbit;
    Pengarang(string pNama) : nama(pNama) {
        cout << "Pengarang \"" << nama << "\"Ada\n";
    }
    ~Pengarang() {
        cout << "Pengarang \"" << nama << "\"Tidak Ada\n";
    }
    void tambahPenerbit(Penerbit*);
    void cetakPenerbit();
};

class Penerbit {
public:
    string nama;
    vector<Pengarang*> Nama_Pengarang;

    Penerbit(string pNama) : nama(pNama) {
        cout << "Pengarang \"" << nama << "\" Ada\n";
    }
    ~Penerbit() {
        cout << "Pengarang \"" << nama << "\" Tidak Ada\n";
    }
    void tambahPengarang(Pengarang*);
    void cetakPengarang();
};

class Buku : Pengarang {
public:
    string Nama_Pengarang;

    Buku(string pNama, string ppengarang) :
        Pengarang(pNama),
        Nama_Pengarang(ppengarang) {
        cout << "Buku dibuat\n" << endl;
    }
    ~Buku() {
        cout << "Buku dihapus\n" << endl;
    }
    string buku() {
        return "Buku" + nama + "dibuat oleh" + Nama_Pengarang + "\n\n";
    }
};

void Penerbit::tambahPengarang(Pengarang* pPengarang) {
    Nama_Pengarang.push_back(pPengarang);
}
void Penerbit::cetakPengarang() {
    cout << "Daftar Pengarang Buku yang diterbitkan \"" << this->nama << "\":\n";
    for (auto& a : Nama_Pengarang) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

void Pengarang::tambahPenerbit(Penerbit* pPenerbit) {
    Nama_Penerbit.push_back(pPenerbit);
    pPenerbit->tambahPengarang(this);
}

void Pengarang::cetakPenerbit() {
    cout << "Nama Penerbit dari Pengarang \"" << this->nama << "\":\n";
    for (auto& a : Nama_Penerbit) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main() {
    Pengarang* varPengarang1 = new Pengarang("Joko");
    Pengarang* varPengarang2 = new Pengarang("Lia");
    Pengarang* varPengarang3 = new Pengarang("Asroni");
    Pengarang* varPengarang4 = new Pengarang("Giga");

    Penerbit* varPenerbit1 = new Penerbit("Gama Press");
    Penerbit* varPenerbit2 = new Penerbit("Intan Pariwara");

    varPengarang1->tambahPenerbit(varPenerbit1);
    varPengarang2->tambahPenerbit(varPenerbit1);
    varPengarang3->tambahPenerbit(varPenerbit2);
    varPengarang4->tambahPenerbit(varPenerbit1);
    varPengarang4->tambahPenerbit(varPenerbit2);



}





