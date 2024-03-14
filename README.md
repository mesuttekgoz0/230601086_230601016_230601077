RSA ŞİFRELEME

RSA Şifreleme ve Deşifreleme Adımları

RSA algoritması üç adımdan oluşmaktadır. Anahtar oluşturma, şifreleme ve şifre çözme.

Anahtar Oluşturma

1. İki asal sayı seçilir. Bu sayılara p ve q diyelim.

2. Bu iki sayının çarpımı gizli ve açık şifrelerimiz tarafından kullanılacak. Bu çarpımı n diye gösterelim.

n = p * q

3. Bir tam sayının o sayıdan daha küçük ve o sayı ile aralarında asal olan sayı sayısını bulmak için kullanırız (totient fonksyionu)

Φ(n) = (p-1)(q-1)

4. 1 < e < Φ(n) koşunu sağlayacak bir e tam sayısı seçilir.

5. Gizli üs d hesaplanır (1<d< Φ(n)).

d*e ≡ 1 (d*e mod Φ(n) = 1)

6. Genel anahtar (n,e) ve özel anahtar (n,d)’ dir. p,q ve Φ(n) değerleri de gizli tutulmalıdır.

Anahtar oluşturma işlemimizi tamamlamış olduk.

Şifreleme

Anahtar oluşturma adımlarını teker teker uygulayacağız.

1. İki tane asal sayı seçelim. P = 7 q = 17 olsun .

2. n= 7 * 17 = 119

3. Φ(n) = (7–1) * (17–1) = 6 * 16 = 96

4. Toient fonksiyonu sonucu ile aralarında asal olan ve 1’den büyük sayı seçilir.

1 < e < 96 için e =13 seçebilirim çünkü 96 ile aralarında asal .

5. Gizli anahtarımızı bulmamız gerekir. Bunun içinde d sayısını bulmalıyız. Bu yüzden Extended Euclid Algorithm (uzatılmış öklid algoritması)kullanacağız.

d.e ≡ 1 mod ϕ(n) olacak şekilde d sayısı buluruz ama önce dönüşümleri yapmamız gerekiyor.

de=1+kmod ϕ(n) à d=(1+ kmod ϕ(n) ) /e

e=13 , Φ(n) = 96 ve n=119 O zaman hesaplamaya başlayalım .

k = 0 için d= (1 + 0*96) / 13 = 1/13 à Bunu seçemeyiz

k = 1 için d= (1 + 1*96) / 13 = 97/13 à Bunu seçemeyiz

k = 2 için d= (1 + 2*96) / 13 = 193/13 à Bunu seçemeyiz

k = 3 için d= (1 + 3*96) / 13 = 289/13 à Bunu seçemeyiz

k = 4 için d= (1 + 4*96) / 13 = 385/13 à Bunu seçemeyiz

k = 5 için d= (1 + 5*96) / 13 = 481/13 à d =37

Private key değerlerimiz n=119 d = 37 Public key değerlerimiz n =119 e =13

Şifreleme yapılırken sizi dinleyen saldırgan sizin verdiğiniz public değerleri kullanacağı için yanlış bir cevaba ulaşacaktır.

Tüm değerleri bulduğumuza göre E ve C harflerini şifreleyelim.

ASCII de E = 45 ve C= 43 .

C ≡ m ^ e (mod n) (1)

E= 45 için ; C ≡ 45 ^ 13 (mod 119) ≡ 24(mod119)

C = 43 için ; C ≡ 43 ^ 13 (mod 119) ≡ 8 (mod119)

Şifre Çözme

Antik yunanda, Polybius ismindeki kişi tarafından bulunan iki boyutlu bir tahtaya dayalı şifreleme sistemidir.

Bu sistemin özelliği, alfabedeki harflerin, iki boyutlu bir tabloya yerleştirilmesi ve ardından bu tablodaki satır ve sütun numaralarına göre okunmasıdır.

Kullanıcıdan alınan gizli anahtar ile mesaj çözümlenmeye başlanır .

M ≡ C ^ d (mod n ) (1)

24 ^ 37 (mod 119) ≡ 45 (mod 119 )

8 ^ 37 (mod 119) ≡ 43 (mod 119)
