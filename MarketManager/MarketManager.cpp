#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <limits>
#include <locale.h>
using namespace std;

void urunTablosu(int sepettekiUrunSayisi, string urunListesi[]) {
    system("CLS");
    int urun = 0;

    for (int sutun = 1;sutun <= 10; sutun++) {
        for (int satir = 1;satir <= 75;satir++) {
            if (sutun == 1 && satir == 50) {
                cout << "Sepetteki Ürün [ " << sepettekiUrunSayisi << " ]";
                satir += 19;
            }
            else if (sutun != 1 && (satir == 1 || satir == 75))
                cout << "|";

            else if (sutun == 1 || sutun == 10)
                cout << "_";

            else if ((sutun == 4 || sutun == 5 || sutun == 6 || sutun == 7) && (satir == 5 || satir == 22 || satir == 40 || satir == 60)) {
                cout << urun + 1 << "." << urunListesi[urun];

                if (urun >= 9)
                    satir += urunListesi[urun].size() + 2;
                else
                    satir += urunListesi[urun].size() + 1;

                urun += 4;
            }
            else
                cout << " ";
        }
        if (sutun == 4 || sutun == 5 || sutun == 6 || sutun == 7)
            urun -= 15;

        cout << "\n";
    }
}


void sepetTablosu(string sepettekiUrunler[50], float sepettekiUrunFiyatlari[50], int sepettekiUrunAdetleri[50], int sepettekiUrunSayisi) {
    double toplam = 0;
    int kontrol = 0;

    system("CLS");
    for (int sutun = 1;sutun <= sepettekiUrunSayisi + 6;sutun++) {
        for (int satir = 1;satir <= 75;satir++) {
            if (sutun <= 4) {
                if (sutun != 1 && (satir == 1 || satir == 75))
                    cout << "|";

                else if (sutun == 1 || sutun == 4)
                    cout << "_";

                else if (sutun == 3 && satir == 29) {
                    cout << "Sepetteki Ürünler";
                    satir += 16;
                }
                else
                    cout << " ";
            }
            else if (sutun >= sepettekiUrunSayisi + 5) {
                if (sutun == sepettekiUrunSayisi + 5)
                    cout << "_";
                else if (sutun == sepettekiUrunSayisi + 6 && satir == 4)
                    cout << "TOPLAM     ";
                else if (sutun == sepettekiUrunSayisi + 6 && satir == 50)
                    cout << toplam << " TL";
                else
                    cout << " ";
            }
            else {
                kontrol = 1;
                switch (satir) {
                case 4:
                    cout << sepettekiUrunler[sutun - 5];
                    satir += sepettekiUrunler[sutun - 5].size();
                    break;

                case 15:
                    cout << " x " << sepettekiUrunAdetleri[sutun - 5] << "    ";
                    if (sepettekiUrunAdetleri[sutun - 5] >= 10)
                        satir += 1;
                    break;
                case 25:
                    cout << sepettekiUrunFiyatlari[sutun - 5] << " TL";
                    if (sepettekiUrunFiyatlari[sutun - 5] == 3 || sepettekiUrunFiyatlari[sutun - 5] == 2 || sepettekiUrunFiyatlari[sutun - 5] == 5 || sepettekiUrunFiyatlari[sutun - 5] == 4)
                        cout << "  ";
                    break;
                case 35:
                    cout << "x " << sepettekiUrunAdetleri[sutun - 5];
                    if (sepettekiUrunAdetleri[sutun - 5] >= 10)
                        satir += 1;
                    break;
                case 45:
                    cout << "= " << sepettekiUrunFiyatlari[sutun - 5] * sepettekiUrunAdetleri[sutun - 5] << " TL";
                    break;
                default:
                    cout << " ";
                }
            }
        }
        cout << "\n";
        if (kontrol == 1) {
            toplam += sepettekiUrunFiyatlari[sutun - 5] * sepettekiUrunAdetleri[sutun - 5];
            kontrol = 0;
        }
    }
    cout << "\n";

    cout << "Çıkmak İçin Herhangi Bir Tuşa Basın";
    getch();

}


int main() {
    setlocale(LC_ALL, "Turkish");

    string urunListesi[] = { "Domates", "Kabak", "Havuç", "Patlıcan", "Iceberg", "Salatalık", "Marul", "Lahana", "Elma", "Portakal", "Mandalina", "Armut", "Cips", "Kola", "IceTea", "Kek" };
    string sepettekiUrunler[50];
    float fiyatListesi[] = { 1.5, 3.00, 2.00, 1.4, 5.00, 2.5, 4.00, 2.00, 2.00, 2.4, 2.7, 1.6, 3.5, 2.8, 3.6, 4.1 };
    float sepettekiUrunFiyatlari[50];
    int sepettekiUrunAdetleri[50], sepettekiUrunSayisi = 0, urun, adet, kontrol;
    char giris;

    do {
        urunTablosu(sepettekiUrunSayisi, urunListesi);

        cout << "\nMalzeme Secin: ";
        while (!(cin >> urun) || (urun < 1 || urun>16)) {
            cout << "Hatalı Bir Islem Yaptınızz! Tekrar Deneyin.\n";
            cout << "Malzeme Seçin: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "\n" << urunListesi[urun - 1] << "(Adet " << fiyatListesi[urun - 1] << "TL ) Adedi girin: ";
        while (!(cin >> adet) || (urun < 1 || urun>50)) {
            cout << "Hatalı Bir Islem Yaptınızz! Tekrar Deneyin.\n";
            cout << "\n" << urunListesi[urun - 1] << "(Adet " << fiyatListesi[urun - 1] << "TL ) Adedi girin: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        sepettekiUrunler[sepettekiUrunSayisi] = urunListesi[urun - 1];
        sepettekiUrunFiyatlari[sepettekiUrunSayisi] = fiyatListesi[urun - 1];
        sepettekiUrunAdetleri[sepettekiUrunSayisi] = adet;

        sepettekiUrunSayisi++;
        urunTablosu(sepettekiUrunSayisi, urunListesi);
        cout << "\nÜrün sepete eklendi\n\n" << "Başka ürün eklemek ister misiniz? (e/h)";

        do {
            giris = getche();
            if (giris == 'E' || giris == 'e')
                kontrol = 0;
            else if (giris == 'h' || giris == 'H')
                kontrol = 1;
            else {
                cout << endl << endl << "Hatali Bir Islem Yaptiniz! Tegirisar Deneyin.";
                cout << endl << endl << "Baska urun eklemek ister misiniz? (e/h)";
                kontrol = 2;
            }
        } while (kontrol == 2);

    } while (kontrol == 0);

    sepetTablosu(sepettekiUrunler, sepettekiUrunFiyatlari, sepettekiUrunAdetleri, sepettekiUrunSayisi);
}