#include <iostream>
#include <bits/stdc++.h>
#define MAX 10
using namespace std;

struct antrian{
    int antrian_depan;
    int antrian_belakang;
    string data[MAX];
}antrian_teller1, antrian_teller2, antrian_teller3;

void inisialisasi_antiran(antrian *queue) {
    queue->antrian_depan = -1;
    queue->antrian_belakang = -1;
}

bool isEmpty(antrian *queue) {
    return (queue->antrian_depan == -1 && queue->antrian_belakang == -1);
}

bool isFull(antrian *queue) {
    return (queue->antrian_belakang == MAX-1);
}

void masuk_antrian(antrian *queue, string data) {
    if (isFull(queue)) {
        cout << "Antrian sudah penuh!" << endl;
    } else {
        if (isEmpty(queue)) {
            queue->antrian_depan = 0;
        }
        queue->antrian_belakang++;
        queue->data[queue->antrian_belakang] = data;
    }
}

void keluar_antrian(antrian *queue) {
    if (isEmpty(queue)) {
        cout << "Antrian kosong" << endl;
    } else {
        if (queue->antrian_depan == queue->antrian_belakang) {
            inisialisasi_antiran(queue);
        } else {
            queue->antrian_depan++;
        }
    }
}

void cetak(antrian *queue) {
    if (isEmpty(queue)) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = queue->antrian_depan; i <= queue->antrian_belakang; i++) {
            cout << queue->data[i] << " " << "Urutan Nasabah" << " " << i+1 << endl;
        }
        cout << endl;
    }
}

int main(){

	int n;
    string perintah;
    string data;

    inisialisasi_antiran(&antrian_teller1);
    inisialisasi_antiran(&antrian_teller2);
    inisialisasi_antiran(&antrian_teller3);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> perintah;
        if (perintah == "Nasabah Masuk") {
            cin >> data;
            if((&antrian_teller1)->antrian_belakang <= (&antrian_teller2)->antrian_belakang && (&antrian_teller1)->antrian_belakang <= (&antrian_teller3)->antrian_belakang){
                masuk_antrian(&antrian_teller1, data);
            }else if((&antrian_teller2)->antrian_belakang <= (&antrian_teller1)->antrian_belakang && (&antrian_teller2)->antrian_belakang <= (&antrian_teller3)->antrian_belakang){
                masuk_antrian(&antrian_teller2, data);
            }else if((&antrian_teller3)->antrian_belakang <= (&antrian_teller1)->antrian_belakang && (&antrian_teller3)->antrian_belakang <= (&antrian_teller2)->antrian_belakang){
                masuk_antrian(&antrian_teller3, data);
            }
        } else if (perintah == "Layani Nasabah") {
            keluar_antrian(&antrian_teller1);
            keluar_antrian(&antrian_teller2);
            keluar_antrian(&antrian_teller3);
        }
    }
 
 cout << "Antrian Teller Pertama: ";
    cetak(&antrian_teller1);
    cout << "Antrian Teller Kedua: ";
    cetak(&antrian_teller2);
    cout << "Antrian Teller Ketiga: ";
    cetak(&antrian_teller3);

}