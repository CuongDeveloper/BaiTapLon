#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class SinhVien
{
private:
    string maSinhVien;
    string hoVaTen;
    tm ngaySinh;
    bool gioiTinh;
    string lop;

public:
    SinhVien(string maSinhVien, string hoVaTen, tm ngaySinh, bool gioiTinh, string lop)
    {
        this->maSinhVien = maSinhVien;
        this->hoVaTen = hoVaTen;
        this->ngaySinh = ngaySinh;
        this->gioiTinh = gioiTinh;
        this->lop = lop;
    }
    SinhVien()
    {
    }
    static vector<SinhVien> Read(string path, vector<SinhVien> lstSinhVien)
    {
        ifstream is(path, ios::binary);
        if (!is.good())
        {
            cout << "File không tồn tại" << endl;
            return lstSinhVien;
        }
        int size2;
        is.read((char *)&size2, 4);
        lstSinhVien.resize(size2);
        is.read((char *)&lstSinhVien[0], size2 * sizeof(SinhVien));
        cout << "Đọc file thành công" << endl;
        return lstSinhVien;
    }
    static void Save(string path, vector<SinhVien> lstSinhVien)
    {
        ofstream os(path, ios::binary);

        int size1 = lstSinhVien.size();
        os.write((const char *)&size1, 4);
        os.write((const char *)&lstSinhVien[0], size1 * sizeof(SinhVien));
        os.close();
        cout << "Lưu file thành công" << endl;
    }
    static vector<SinhVien> Add(vector<SinhVien> lstSinhVien)
    {
        string maSinhVien;
        string hoVaTen;
        int ngay;
        int thang;
        int nam;
        int gioiTinh = 0;
        string lop;
        cout << "Nhập mã sinh viên : " << endl;
        cin >> maSinhVien;
        cout << "Nhập họ và tên sinh viên : " << endl;
        cin >> hoVaTen;
        cout << "Nhập ngày sinh sinh viên : " << endl;
        cin >> ngay;
        cout << "Nhập tháng sinh sinh viên : " << endl;
        cin >> thang;
        cout << "Nhập năm sinh sinh viên : " << endl;
        cin >> nam;
        tm ngaySinh;
        ngaySinh.tm_mday = ngay;
        ngaySinh.tm_mon = thang;
        ngaySinh.tm_year = nam;
        cout << "Nhập giới tính sinh viên với 1 là Nam và 0 là nữ: " << endl;
        cin >> gioiTinh;
        while (gioiTinh != 0 && gioiTinh != 1)
        {
            cout << "Giới tính là 0 hoặc 1" << endl;
            cout << "Nhập giới tính sinh viên với 1 là Nam và 0 là nữ: " << endl;
            cin >> gioiTinh;
        }
        cout << "Nhập lớp sinh viên : " << endl;
        cin >> lop;
        lstSinhVien.push_back(SinhVien(maSinhVien, hoVaTen, ngaySinh, gioiTinh == 1, lop));
        cout << "Thêm thành công" << endl;
        return lstSinhVien;
    }
    static vector<SinhVien> Delete(vector<SinhVien> lstSinhVien)
    {
        lstSinhVien.pop_back();
        return lstSinhVien;
    }
    static void Show(vector<SinhVien> lstSinhVien)
    {
        if (lstSinhVien.size() == 0)
        {
            cout << "Danh sách trống" << endl;
            return;
        }
        for (int i = lstSinhVien.size() - 1; i >= 0; i--)
        {
            cout << "Mã sinh viên : " << lstSinhVien[i].maSinhVien << endl;
            cout << "Tên sinh viên : " << lstSinhVien[i].hoVaTen << endl;
            tm ngaySinh = lstSinhVien[i].ngaySinh;
            cout << "Ngày sinh : " << ngaySinh.tm_mday << "/" << ngaySinh.tm_mon << "/" << ngaySinh.tm_year << endl;
            string gioiTinh = lstSinhVien[i].gioiTinh ? "Nam" : "Nữ";
            cout << "Giới tính : " << gioiTinh << endl;
            cout << "Lớp : " << lstSinhVien[i].lop << endl;
        }
    }
    static vector<SinhVien> Edit(vector<SinhVien> lstSinhVien)
    {
        if (lstSinhVien.size() == 0)
        {
            cout << "Danh sách trống" << endl;
            return lstSinhVien;
        }
        string maSinhVien;
        string hoVaTen;
        int ngay;
        int thang;
        int nam;
        int gioiTinh = 0;
        string lop;
        int sinhVienIndex = Search(lstSinhVien);
        if (sinhVienIndex == -1)
        {
            return lstSinhVien;
        }
        cout << "Nhập thông tin mới" << endl;
        cout << "Nhập mã sinh viên : " << endl;
        cin >> maSinhVien;
        cout << "Nhập họ và tên sinh viên : " << endl;
        cin >> hoVaTen;
        cout << "Nhập ngày sinh sinh viên : " << endl;
        cin >> ngay;
        cout << "Nhập tháng sinh sinh viên : " << endl;
        cin >> thang;
        cout << "Nhập năm sinh sinh viên : " << endl;
        cin >> nam;
        tm ngaySinh;
        ngaySinh.tm_mday = ngay;
        ngaySinh.tm_mon = thang;
        ngaySinh.tm_year = nam;
        cout << "Nhập giới tính sinh viên với 1 là Nam và 0 là nữ: " << endl;
        cin >> gioiTinh;
        while (gioiTinh != 0 && gioiTinh != 1)
        {
            cout << "Giới tính là 0 hoặc 1" << endl;
            cout << "Nhập giới tính sinh viên với 1 là Nam và 0 là nữ: " << endl;
            cin >> gioiTinh;
        }
        cout << "Nhập lớp sinh viên : " << endl;
        cin >> lop;
        SinhVien sinhVienNew(maSinhVien, hoVaTen, ngaySinh, gioiTinh == 1, lop);
        lstSinhVien[sinhVienIndex] = sinhVienNew;
        return lstSinhVien;
    }
    static int Search(vector<SinhVien> lstSinhVien)
    {
        if (lstSinhVien.size() == 0)
        {
            cout << "Danh sách trống" << endl;
            return -1;
        }
        string tenSinhVien;
        cout << "Danh sách tên sinh viên" << endl;
        for (int i = lstSinhVien.size() - 1; i >= 0; i--)
        {
            cout << "Tên sinh viên: " << lstSinhVien[i].hoVaTen << endl;
        }
        cout << "Nhập tên sinh viên bạn muốn tìm kiếm: " << endl;
        cin >> tenSinhVien;
        int i = lstSinhVien.size() - 1;
        for (i; i >= 0; i--)
        {
            if (lstSinhVien[i].hoVaTen.find(tenSinhVien) != string::npos)
            {
                cout << "Sinh viên này đang có thông tin như sau" << endl;
                cout << "Mã sinh viên : " << lstSinhVien[i].maSinhVien << endl;
                cout << "Tên sinh viên : " << lstSinhVien[i].hoVaTen << endl;
                tm ngaySinh = lstSinhVien[i].ngaySinh;
                cout << "Ngày sinh : " << ngaySinh.tm_mday << "/" << ngaySinh.tm_mon << "/" << ngaySinh.tm_year << endl;
                string gioiTinh = lstSinhVien[i].gioiTinh ? "Nam" : "Nữ";
                cout << "Giới tính : " << gioiTinh << endl;
                cout << "Lớp : " << lstSinhVien[i].lop << endl;
                cout << i << endl;
                return i;
            }
        }
        cout << "Sinh viên không tồn tại trong dánh sách" << endl;
        return -1;
    }
};