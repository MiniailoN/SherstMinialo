//Меняйло Никита
#ifndef PHONEBOOK_CORE_H
#define PHONEBOOK_CORE_H

#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Contact {
    string name, phone, email;
};

class PhoneBook {
    vector<Contact> contacts;
    const string filename = "contacts.dat";
    
public:
    bool addContact(const string& n, const string& p, const string& e) {
        if(n.empty() || p.empty() || e.empty()) return false;
        contacts.push_back({n,p,e});
        return true;
    }
    
    bool removeContact(int i) {
        if(i<0 || i>=contacts.size()) return false;
        contacts.erase(contacts.begin()+i);
        return true;
    }
    
    vector<Contact> search(const string& q) const {
        vector<Contact> res;
        for(const auto& c : contacts)
            if(c.name.find(q)!=string::npos || c.phone.find(q)!=string::npos || c.email.find(q)!=string::npos)
                res.push_back(c);
        return res;
    }
    
    bool save() const {
        ofstream f(filename);
        if(!f) return false;
        for(const auto& c : contacts)
            f << c.name << "|" << c.phone << "|" << c.email << "\n";
        return true;
    }
    
    bool load() {
        ifstream f(filename);
        if(!f) return false;
        contacts.clear();
        string line;
        while(getline(f, line)) {
            size_t p1=line.find('|'), p2=line.find('|',p1+1);
            if(p1!=string::npos && p2!=string::npos)
                contacts.push_back({line.substr(0,p1), line.substr(p1+1,p2-p1-1), line.substr(p2+1)});
        }
        return true;
    }
    
    const vector<Contact>& getAll() const { return contacts; }
};

#endif
