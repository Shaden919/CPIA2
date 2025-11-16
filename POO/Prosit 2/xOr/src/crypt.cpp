#include "crypt.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

string toHex(unsigned char c);
unsigned char fromHex(const string &hex);

Crypt::Crypt(string key) : key(key) {}
Crypt::~Crypt() {}
void Crypt::setKey(string key) {
    this->key = key;
}
string Crypt::getKey() {
    cout << this->key << "\n";
    return this->key;
}


bool Crypt::executeXOR(File file, int mode) {
    string tempName = "tempFile";
    File tempFile(tempName, tempName + ".txt");

    ifstream oldFile(file.getPath().c_str(), ios::in);
    if (oldFile.fail()) {
        cerr << "Erreur d'ouverture du fichier \"" << file.getName() << "\"\n";
        return false;
    }

    ofstream newFile(tempFile.getPath().c_str(), ios::out);
    if (newFile.fail()) {
        cerr << "Erreur d'ouverture du fichier temporaire\n";
        return false;
    }

    string ligne;
    while (getline(oldFile, ligne)) {

        string xorLine = "";

        if (mode == 1) {
            for (int i = 0; i < ligne.length(); i++) {
                unsigned char x = ligne[i] ^ key[i % key.length()];
                xorLine += toHex(x);
            }
        } 
        else {
            if (ligne.length() % 2 != 0) {
                cerr << "Erreur : ligne hex impaire, fichier invalide.\n";
                return false;
            }

            for (int i = 0; i < ligne.length(); i += 2) {
                unsigned char x = fromHex(ligne.substr(i, 2));
                xorLine += (x ^ key[(i / 2) % key.length()]);
            }
        }

        newFile << xorLine << "\n";
    }

    // Remplacement de l'ancien fichier
    string oldName = file.getName();
    remove(file.getPath().c_str());
    tempFile.rename(oldName);

    return true;
}


string toHex(unsigned char c) {
    const char *hex = "0123456789ABCDEF";
    string result;
    result += hex[(c >> 4) & 0xF];
    result += hex[c & 0xF];
    return result;
}

unsigned char fromHex(const string &hex) {
    auto hexValue = [](char c) {
        if ('0' <= c && c <= '9') return c - '0';
        if ('A' <= c && c <= 'F') return c - 'A' + 10;
        if ('a' <= c && c <= 'f') return c - 'a' + 10;
        return 0;
    };
    return (hexValue(hex[0]) << 4) | hexValue(hex[1]);
}