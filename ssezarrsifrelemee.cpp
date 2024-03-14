#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Þifreleme fonksiyonu,  parametre olarak þifrelenecek metni (metin) ve þifreleme için kullanýlacak kaydýrma miktarýný (kaydirma) alýr.
string sifrele(string metin, int kaydirma) {
    string sonuc = "";

    for (int i = 0; i < metin.length(); i++) {
        // Büyük harfleri þifreler
        if (isupper(metin[i]))//if (isupper(metin[i])): Bu koþul, metin içindeki karakterin büyük harf olup olmadýðýný kontrol eder. 
            sonuc += char(int(metin[i] + kaydirma - 65) % 26 + 65);//Büyük harfleri þifrelemek için, ASCII deðerlerini kullanarak bir kaydýrma yapýlýr.
        // Küçük harfleri þifreler
        else if (islower(metin[i]))// Bu koþul, karakterin küçük harf olup olmadýðýný kontrol eder. Eðer karakter bir küçük harfse, þifreleme iþlemi uygulanýr.
            sonuc += char(int(metin[i] + kaydirma - 97) % 26 + 97); /*Küçük harfleri þifrelemek için, büyük harflerde olduðu gibi ASCII deðerlerini kullanarak bir kaydýrma yapýlýr.
			 Ancak, küçük harfler için kaydýrma iþlemi 97 (ASCII'de 'a' harfinin deðeri) baz alýnarak yapýlýr. */
        // Diðer karakterleri deðiþtirmeden ekler
        else
            sonuc += metin[i];// Büyük ya da küçük harf deðilse karakter deðiþtirilmeden sonuc dizisine eklenir.
    }

    return sonuc;
}

/*Deþifreleme fonksiyonu Parametre olarak deþifre edilecek metni (metin) ve þifreleme için kullanýlan kaydýrma miktarýný (kaydirma) alýr.
Metni deþifrelemek için sifrele fonksiyonunu tersine çevirir ve deþifrelenmiþ metni geri döndürür.*/
string desifrele(string metin, int kaydirma) {
    // Þifreleme iþlemi tersine çevrilerek deþifre eder.
    return sifrele(metin, 26 - kaydirma);
}

int main() {
    string girisMetni;
    int kaydirmaorani;
    
    // Kullanýcýdan giriþ metnini ve kaydýrma oranýný alýp kaydýrýr.
    cout << "Sifrelenecek metni girin: ";
    getline(cin, girisMetni);
    
    cout << "Kaydýrma oranini girin: ";
    cin >> kaydirmaorani;
    
    // Þifreleme iþlemini yapan fonksiyon
    string sifrelenmisveri = sifrele(girisMetni, kaydirmaorani);
    cout << "Sifrelenmis metin: " << sifrelenmisveri << endl;
    
    // Deþifreleme iþlemi yapan fonksiyon
    string desifrelenmisveri = desifrele(sifrelenmisveri, kaydirmaorani);
    cout << "Desifrelenmis metin: " << desifrelenmisveri << endl;
    
    // Dosyaya þifrelenmiþ metni yaz
    ofstream ciktiDosyasi("sifrelenmis_metin.txt");
    if (ciktiDosyasi.is_open()) {
        ciktiDosyasi << sifrelenmisveri;
        ciktiDosyasi.close();
        cout << "Sifrelenmis metin dosyaya yazildi." << endl;
    } else {
        cout << "Dosya acilmiyor." << endl;
    }
    
    return 0;
}
