#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

class Contact {
private:
    string name;
    string address;
    string power;

public:
    Contact(string n = "", string addr = "", string pow = "") : name(n), address(addr), power(pow) {}

    string getName() {
        return name;
    }

    void displayContact() {
        cout << "Nama    : " << name << endl;
        cout << "Alamat  : " << address << endl;
        cout << "Kekuatan: " << power << endl;
    }
};

class PhoneBook {
private:
    Contact contacts[8];
    int count;

public:
    PhoneBook() : count(0) {}

    void addContact(string name, string address, string power) {
        if (count < 8) {
            contacts[count] = Contact(name, address, power);
            count++;
        } else {
            cout << "Max 8 bang... Kontak (" << contacts[0].getName() << ") bakal digantiin sama orang baru ya TwT" << endl;
            for (int i = 1; i < 8; i++) {
                contacts[i - 1] = contacts[i];
            }
            contacts[7] = Contact(name, address, power);
        }
        cout << "Yey, kontak ditambahkan >///<" << endl;
    }

    void displayAllContacts() {
        if (count == 0) {
            cout << "Gak ada kontaknya... Tambahin dulu bang..." << endl;
            return;
        }

        cout << "Daftar Kontak:" << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << contacts[i].getName() << endl;
        }
    }

    void searchContactByIndex(int index) {
        if (index >= 1 && index <= count) {
            contacts[index - 1].displayContact();
        } else {
            cout << "Salah woi! Gak ada kontaknya!" << endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;
    string command;

    cout << "Bonjour!" << endl;

    while (true) {
        cout << "\nPerintah: ADD, SEARCH, EXIT" << endl;
        cout << "Masukkan perintah: ";
        cin >> command;

        command = toUpperCase(command);

        if (command == "ADD") {
            string name, address, power;
            cin.ignore();
            cout << "Masukkan nama: ";
            getline(cin, name);
            cout << "Masukkan alamat: ";
            getline(cin, address);
            cout << "Masukkan kekuatan: ";
            getline(cin, power);
            phoneBook.addContact(name, address, power);
        } else if (command == "SEARCH") {
            phoneBook.displayAllContacts();

            int choice;
            cout << "Masukin nomor kontak yang ada buat lihat detailnya yaa! (0 untuk batal): ";
            cin >> choice;

            if (choice == 0) {
                cout << "Kembali ke laptop" << endl;
            } else {
                phoneBook.searchContactByIndex(choice);
            }
        } else if (command == "EXIT") {
            cout << "Bye bye :(" << endl;
            break;
        } else {
            cout << "Salah bang... Coba tulis lagi yang bener..." << endl;
        }
    }

    return 0;
}
