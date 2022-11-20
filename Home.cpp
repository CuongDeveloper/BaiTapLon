#include "SinhVien.cpp"
#include <vector>

int main()
{
    string path = "data.bin";
    vector<SinhVien> lstSinhVien;
    tm tmtime;
    tmtime.tm_mday = 19;
    tmtime.tm_mon = 10;
    tmtime.tm_year = 2003;
    lstSinhVien.push_back(SinhVien("1", "1", tmtime, true, "1"));
    lstSinhVien.push_back(SinhVien("2", "2", tmtime, true, "2"));
    lstSinhVien.push_back(SinhVien("3", "3", tmtime, true, "3"));
    int luaChon;
    do
    {
        cout << "----------Menu----------" << endl;
        cout << "1. Đọc danh sách từ file" << endl;
        cout << "2. Ghi danh sách vào file" << endl;
        cout << "3. Nhập thành viên vào cuối danh sách" << endl;
        cout << "4. Xóa một thành viên" << endl;
        cout << "5. Hiển thị danh sách" << endl;
        cout << "6. Sửa đổi một thành viên trong danh sách" << endl;
        cout << "7. Tìm kiem thành viên trong danh sách" << endl;
        cout << "0. Thoát" << endl;
        cout << "----------Menu----------" << endl;
        cout << "Nhập lựa chọn của bạn : " << endl;
        cin >> luaChon;
        switch (luaChon)
        {
        case 1:
        {
            lstSinhVien = SinhVien::Read(path, lstSinhVien);
            break;
        }
        case 2:
        {
            SinhVien::Save(path, lstSinhVien);
            break;
        }
        case 3:
        {
            lstSinhVien = SinhVien::Add(lstSinhVien);
            break;
        }
        case 4:
        {
            lstSinhVien = SinhVien::Delete(lstSinhVien);
            break;
        }
        case 5:
        {
            SinhVien::Show(lstSinhVien);
            break;
        }
        case 6:
        {
            lstSinhVien = SinhVien::Edit(lstSinhVien);
            break;
        }
        case 7:
        {
            SinhVien::Search(lstSinhVien);
            break;
        }
        case 0:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "Không có lựa chọn này : " << endl;
            cin >> luaChon;
            break;
        }
        }
    } while (luaChon != 0);
    return 0;
}