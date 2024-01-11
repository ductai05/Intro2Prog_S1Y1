//ciel_23122013 23TNTN1 FIT@HCMUS
// TH NMLT 01.01.2023

#include <iostream>

using namespace std;

bool laNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

bool laNgayHopLe(int ngay, int thang, int nam) {
    if (nam < 0) return false;
    if (thang < 1 || thang > 12) return false;
    int soNgayTrongThang;
    if (thang == 2) {
        soNgayTrongThang = laNamNhuan(nam) ? 29 : 28;
    }
    else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        soNgayTrongThang = 30;
    }
    else {
        soNgayTrongThang = 31;
    }
    return ngay >= 1 && ngay <= soNgayTrongThang;
}

int soNgayTrongThang(int thang, int nam) {
    if (thang == 2) {
        return laNamNhuan(nam) ? 29 : 28;
    }
    else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

void timNgayHomTruoc(int& ngay, int& thang, int& nam) {
    ngay--;
    if (ngay == 0) {
        thang--;
        if (thang == 0) {
            thang = 12;
            nam--;
        }
        ngay = soNgayTrongThang(thang, nam);
    }
}

void timNgayHomSau(int& ngay, int& thang, int& nam) {
    ngay++;
    int soNgayTrongThangHienTai = soNgayTrongThang(thang, nam);
    if (ngay > soNgayTrongThangHienTai) {
        ngay = 1;
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }
}

void timNgayK(int& ngay, int& thang, int& nam, int k) {
    if (k > 0) {
        for (int i = 0; i < k; i++) {
            timNgayHomSau(ngay, thang, nam);
        }
    }
    else {
        for (int i = 0; i > k; i--) {
            timNgayHomTruoc(ngay, thang, nam);
        }
    }
}

int timThuTrongTuan(int ngay, int thang, int nam) {
    if (thang < 3) {
        thang += 12;
        nam--;
    }

    int A = ngay + 2 * thang + (3 * (thang + 1) / 5) + nam + (nam / 4) - (nam / 100) + (nam / 400) + 2;
    int thu = A % 7;

    if (thu == 0) {
        thu = 7;
    }

    return thu;
}

int tinhSoNgayTrongNam(int nam) {
    if (laNamNhuan(nam))
        return 366;
    return 365;
}

int soNgayTrongNam(int ngay, int thang, int nam) {
    int Ngay[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int soNgayTrongNam = ngay;
    for (int i = 0; i < thang - 1; i++) {
        soNgayTrongNam += Ngay[i];
    }

    if (thang > 2 && laNamNhuan(nam)) {
        soNgayTrongNam += 1;
    }

    return soNgayTrongNam;
}

int timTuanTrongNam(int ngay, int thang, int nam) {
    int soNgay = soNgayTrongNam(ngay, thang, nam);

    int tuan = (soNgay - 1) / 7 + 1;

    return tuan;
}

int main() {
    int ngay, thang, nam, k;
    cout << "Nhap vao ngay, thang, nam: ";
    cin >> ngay >> thang >> nam;

    if (!laNgayHopLe(ngay, thang, nam)) {
        cout << "Ngay khong hop le!" << '\n';
        return 0;
    }

    cout << "Thang " << thang << " co " << soNgayTrongThang(thang, nam) << " ngay." << '\n';

    int ngayHomTruoc = ngay, thangHomTruoc = thang, namHomTruoc = nam;
    timNgayHomTruoc(ngayHomTruoc, thangHomTruoc, namHomTruoc);
    cout << "Ngay hom truoc la: " << ngayHomTruoc << "/" << thangHomTruoc << "/" << namHomTruoc << '\n';

    int ngayHomSau = ngay, thangHomSau = thang, namHomSau = nam;
    timNgayHomSau(ngayHomSau, thangHomSau, namHomSau);
    cout << "Ngay mai la: " << ngayHomSau << "/" << thangHomSau << "/" << namHomSau << '\n';

    cout << "Nhap k: ";
    cin >> k;

    int ngayK = ngay, thangK = thang, namK = nam;
    timNgayK(ngayK, thangK, namK, k);
    cout << "Ngay " << k << " ngay sau la: " << ngayK << "/" << thangK << "/" << namK << '\n';

    timNgayK(ngayK, thangK, namK, -2*k);
    cout << "Ngay " << k << " ngay truoc la: " << ngayK << "/" << thangK << "/" << namK << '\n';

    int thu = timThuTrongTuan(ngay, thang, nam);
    if (thu == 1) {
        cout << "Ngay " << ngay << "/" << thang << "/" << nam << " la chu nhat.\n";
    }
    else {
        cout << "Ngay " << ngay << "/" << thang << "/" << nam << " la thu " << thu << '\n';
    }

    int tuan = timTuanTrongNam(ngay, thang, nam);
    cout << "Ngay " << ngay << "/" << thang << "/" << nam << " la tuan thu " << tuan << " cua nam" << '\n';

    return 0;
}