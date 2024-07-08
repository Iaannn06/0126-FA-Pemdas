#include <iostream>
using namespace std;

class MataKuliah {
protected:
    float presensi;
    float activity;
    float exercise;
    float tugasakhir;

public:
    MataKuliah() : presensi(0.0), activity(0.0), exercise(0.0), tugasakhir(0.0) {}

    virtual void namaMataKuliah();
    virtual void inputNilai(float presensi, float activity, float exercise, float tugasakhir) {
        this->presensi = presensi;
        this->activity = activity;
        this->exercise = exercise;
        this->tugasakhir = tugasakhir;
    }

    virtual float hitungNilaiAkhir(); 
    virtual void cekKelulusan() = 0; 
    float getPresensi() const { return presensi; }
    void setPresensi(float nilai) { presensi = nilai; }
    float getActivity() const { return activity; }
    void setActivity(float nilai) { activity = nilai; }
    float getExercise() const { return exercise; }
    void setExercise(float nilai) { exercise = nilai; }
    float getTugasAkhir() const { return tugasakhir; }
    void setTugasAkhir(float nilai) { tugasakhir = nilai; }
};


class Pemrograman : public MataKuliah {
public:
    void namaMataKuliah()  {
        cout << "Mata Kuliah: Pemrograman" << endl;
    }
    void inputNilai(float presensi, float activity, float exercise, float tugasAkhir) override {
        setPresensi(presensi);
        setActivity(activity);
        setExercise(exercise);
        setTugasAkhir(tugasAkhir);
    }
    float hitungNilaiAkhir() {
        
        const float bobotPresensi = 0.2;
        const float bobotActivity = 0.2;
        const float bobotExercise = 0.3;
        const float bobotTugasAkhir = 0.5;

        float nilaiAkhir = getPresensi() * bobotPresensi +
            getActivity() * bobotActivity +
            getExercise() * bobotExercise +
            getTugasAkhir() * bobotTugasAkhir;
        return nilaiAkhir;
    }

    void cekKelulusan()  {
        float nilaiAkhir = hitungNilaiAkhir();
        if (nilaiAkhir >= 75.0) {
            cout << "Selamat! Anda lulus dengan nilai akhir " << nilaiAkhir << endl;
        }
        else {
            cout << "Maaf, Anda tidak lulus dengan nilai akhir " << nilaiAkhir << endl;
        }
    }
};


class Jaringan : public MataKuliah {
public:
    void namaMataKuliah()  {
        cout << "Mata Kuliah: Jaringan" << endl;
    }
    void inputNilai(float presensi, float activity, float exercise, float tugasAkhir) override {
        setPresensi(presensi);
        setActivity(activity);
        setExercise(exercise); 
    }
    float hitungNilaiAkhir()  {
       
        const float bobotActivity = 0.4;
        const float bobotExercise = 0.6;
        float nilaiAkhir = getActivity() * bobotActivity +
            getExercise() * bobotExercise;
        return nilaiAkhir;
    }

    void cekKelulusan()  {
        float nilaiAkhir = hitungNilaiAkhir();
        if (nilaiAkhir >= 75.0) {
            cout << "Selamat! Anda lulus dengan nilai akhir= " << nilaiAkhir << endl;
        }
        else {
            cout << "Maaf, Anda tidak lulus dengan nilai akhir= " << nilaiAkhir << endl;
        }
    }
};


int main() {
    char pilih;
    MataKuliah* mataKuliah = nullptr;
    Pemrograman pemrograman;
    Jaringan jaringan;
    cout << "Pilih mata kuliah (P/Pemrograman, J/Jaringan, K/Keluar): ";
    cin >> pilih;

    if (pilih == 'P' || pilih == 'p')
    {
        mataKuliah = &pemrograman;
        pemrograman.setPresensi(75.0); 
    }
    else if (pilih == 'J' || pilih == 'j')
    {
        mataKuliah = &jaringan;
        jaringan.setPresensi(75.0); 
    }
    else if (pilih == 'K' || pilih == 'K')
    {
        return 0;
    }
    else
    {
        cout << "Pilihan tidak valid." << endl;
        return 1;
    }

    float presensiP, activityP, exerciseP, tugasAkhirP;
    cout << "Masukkan nilai Presensi Pemrograman: ";
    cin >> presensiP;
    cout << "Masukkan nilai Activity Pemrograman: ";
    cin >> activityP;
    cout << "Masukkan nilai Exercise Pemrograman: ";
    cin >> exerciseP;
    cout << "Masukkan nilai Tugas Akhir Pemrograman: ";
    cin >> tugasAkhirP;
    pemrograman.inputNilai(presensiP, activityP, exerciseP, tugasAkhirP);
    pemrograman.namaMataKuliah();
    pemrograman.cekKelulusan();

    float presensiJ, activityJ, exerciseJ;
    cout << "Masukkan nilai Presensi Jaringan: ";
    cin >> presensiJ;
    cout << "Masukkan nilai Activity Jaringan: ";
    cin >> activityJ;
    cout << "Masukkan nilai Exercise Jaringan: ";
    cin >> exerciseJ;
    jaringan.inputNilai(presensiJ, activityJ, exerciseJ, 0.0);
    jaringan.namaMataKuliah();
    jaringan.cekKelulusan();

    cout << endl;
    return 0;
}

