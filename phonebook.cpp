#include <iostream>
#include "phonebook_core.h"

using namespace std;

void showMenu() {
    cout << "\n1. Добавить\n2. Удалить\n3. Найти\n4. Все\n5. Сохранить\n6. Загрузить\n0. Выход\nВыбор: ";
}

void showContacts(const vector<Contact>& c) {
    for(size_t i=0; i<c.size(); i++)
        cout << i+1 << ". " << c[i].name << " - " << c[i].phone << " - " << c[i].email << endl;
}

int main() {
    PhoneBook pb;
    pb.load();
    
    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: {
                string n,p,e;
                cout << "Имя: "; getline(cin,n);
                cout << "Телефон: "; getline(cin,p);
                cout << "Email: "; getline(cin,e);
                if(pb.addContact(n,p,e)) cout << "Добавлено!\n";
                else cout << "Ошибка!\n";
                break;
            }
            case 2: {
                showContacts(pb.getAll());
                cout << "Номер для удаления: ";
                int i; cin >> i;
                if(pb.removeContact(i-1)) cout << "Удалено!\n";
                else cout << "Ошибка!\n";
                break;
            }
            case 3: {
                string q;
                cout << "Поиск: "; getline(cin,q);
                showContacts(pb.search(q));
                break;
            }
            case 4: 
                showContacts(pb.getAll());
                break;
            case 5:
                if(pb.save()) cout << "Сохранено!\n";
                else cout << "Ошибка!\n";
                break;
            case 6:
                if(pb.load()) cout << "Загружено!\n";
                else cout << "Ошибка!\n";
                break;
        }
    } while(choice != 0);
    
    return 0;
}
