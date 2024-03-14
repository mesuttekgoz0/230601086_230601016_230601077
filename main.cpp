#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

string Sifreleme(string metin);
string Cozme(string sifreliMetin);

int main()
{
    string sec, dosyaAdi, metin;
    
    cout << "------------------------------------" << endl;
    cout << "Polybius Sifreleme ve Cozme Programi" << endl;
    cout << "------------------------------------" << endl;
    cout << "1 - Metni sifrelemek mi istersiniz?" << endl;
    cout << "2 - Metni cozmek mi istersiniz?" << endl;
    cout << "(1/2): ";
    cin >> sec;

    if (sec == "1") {
        cout << "Sifrelemek istediginiz metni giriniz: ";
        cin.ignore();
        getline(cin, metin);
        cout << "Sifreli metin: " << Sifreleme(metin) << endl;
    }
    else if (sec == "2") {
        cout << "Cozmek istediginiz metni giriniz: ";
        cin.ignore();
        getline(cin, metin);
        cout << "Cozulmus metin: " << Cozme(metin) << endl;
    }
    else {
        cout << "Gecersiz!" << endl;
    }

    cout << "Dosya adini giriniz: ";
    cin >> dosyaAdi;

    ofstream dosya(dosyaAdi);

    if (dosya.is_open()) {
        if (sec == "1") {
            dosya << "Sifreli metin: " << Sifreleme(metin) << endl;
        }
        else if (sec == "2") {
            dosya << "Cozulmus metin: " << Cozme(metin) << endl;
        }
        cout << "Islem basariyla tamamlandi. Dosyaya yazildi." << endl;
    }
    else {
        cout << "Dosya acilamadi." << endl;
    }

    dosya.close();
    
    return 0;
}

string Sifreleme(string metin)
{
    char harf;
    string sifreliMetin;
    string polybiusKaresi[5] = {
        "ABCDE",
        "FGHIK",
        "LMNOP",
        "QRSTU",
        "VWXYZ"
    };
    
    for (char harf : metin) {
        harf = toupper(harf);
        
        if (isalpha(harf)) {
            if (harf == 'J')
                harf = 'I';

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (polybiusKaresi[i][j] == harf) {
                        sifreliMetin = sifreliMetin + to_string(i + 1);
                        sifreliMetin = sifreliMetin + to_string(j + 1);
                    }
                }
            }
        }
        else if (harf == ' ') {
            sifreliMetin = sifreliMetin + ' ';
        }
    }   
    return sifreliMetin;
}

string Cozme(string sifreliMetin)
{
    string metin;
    string polybiusKaresi[5] = {
        "ABCDE",
        "FGHIK",
        "LMNOP",
        "QRSTU",
        "VWXYZ"
    };
    
    for (int i = 0; i < sifreliMetin.length(); i = i + 2) {
        if (sifreliMetin[i] == ' ') {
            metin = metin + " ";
            continue;
        }
        int satir = sifreliMetin[i] - '1';  
        int sutun = sifreliMetin[i + 1] - '1';

        if (satir >= 0 && satir < 5 && sutun >=0 && sutun < 5) {
            metin = metin + polybiusKaresi[satir][sutun];
        }
    }
    return metin;
}
