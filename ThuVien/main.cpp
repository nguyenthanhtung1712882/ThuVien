#include"ThuVien.h"
#include"PhieuMuonTra.h"
#include<conio.h>
#include<Windows.h>

void menuChinh(ThuVien tv);
void menuSach(ThuVien tv);
void menuDocGia(ThuVien tv);
void menuPhieuMuonTra(ThuVien tv);

void backMenu(ThuVien tv, void(*cmp)(ThuVien))
{
	char ch;
	cout << "\n\n\t\tChon 'E' de tro lai menu\n";
	do {
		ch = _getch();
		if (ch == 'e' || ch == 'E')cmp(tv);
	} while (ch != 'e' | ch != 'E');
}

int luaChon(int a, int b)
{
	cout << endl;
	int lc;
	do {
		cout << "Nhap vao lua chon : ";
		cin >> lc;
	} while (lc < a || lc > b);
	return lc;
}

void menuChinh(ThuVien tv)
{
	system("cls");
	cout << endl;
	cout << "   ---------------------------  " << endl;
	cout << "   |  MENU THU VIEN DHQG HCM | " << endl;
	cout << "   ---------------------------  \n" << endl;
	cout << " 0. Thoat.\n";
	cout << " 1. Sach.\n";
	cout << " 2. Doc gia.\n";
	cout << " 3. Phieu muon/tra.\n";
	int lc = luaChon(0, 3);
	switch (lc)
	{
	case 0:
	{
		char ch;
		cout << "Ban co muon luu du lieu vao file ? (Y/N) ";
		cin >> ch;
		ch = toupper(ch);
		if (ch == 'Y' || ch == 'y')
		{
			tv.luuDuLieuRaFile();
			cout << "Da luu thanh cong." << endl;
		}
		cout << "Tu tat sau 3s " << endl;
		Sleep(3000);
		exit(0);
	}
	case 1:
		menuSach(tv);
	case 2:
		menuDocGia(tv);
	default:
		menuPhieuMuonTra(tv);
	}
}

void menuSach(ThuVien tv)
{
	system("cls");
	cout << endl;
	cout << "   -----------  " << endl;
	cout << "   |   SACH  |    " << endl;
	cout << "   ----------- \n " << endl;
	cout << " 0. Menu chinh\n";
	cout << " 1. Tim kiem sach.\n";
	cout << " 2. Them sach.\n";
	cout << " 3. Xoa sach.\n";
	cout << " 4. Sua sach.\n";
	cout << " 5. Xuat danh sach sach.\n";
	int lc = luaChon(0, 5);
	switch (lc)
	{
	case 0:
		menuChinh(tv);
	case 1:
		system("cls");
		tv.timKiemSach();
		backMenu(tv, menuSach);
	case 2:
		system("cls");
		tv.themSach();
		backMenu(tv, menuSach);
	case 3:
		system("cls");
		tv.xoaSach();
		backMenu(tv, menuSach);
	case 4:
		system("cls");
		tv.suaSach();
		backMenu(tv, menuSach);
	default:
		system("cls");
		tv.xuatDSSach();
		backMenu(tv, menuSach);
	}
}

void menuDocGia(ThuVien tv)
{
	system("cls");
	cout << endl;
	cout << "   -------------- " << endl;
	cout << "   |   DOC GIA  |    " << endl;
	cout << "   -------------- \n" << endl;
	cout << " 0. Menu chinh\n";
	cout << " 1. Tim kiem doc gia.\n";
	cout << " 2. Them doc gia.\n";
	cout << " 3. Xoa doc gia.\n";
	cout << " 4. Sua doc gia.\n";
	cout << " 5. Xuat danh sach doc gia.\n";
	int lc = luaChon(0, 5);
	switch (lc)
	{
	case 0:
		menuChinh(tv);
	case 1:
		system("cls");
		tv.timKiemDocGia();
		backMenu(tv, menuDocGia);
	case 2:
		system("cls");
		tv.themDocGia();
		backMenu(tv, menuDocGia);
	case 3:
		system("cls");
		tv.xoaDocGia();
		backMenu(tv, menuDocGia);
	case 4:
		system("cls");
		tv.suaDocGia();
		backMenu(tv, menuDocGia);
	default:
		system("cls");
		tv.xuatDSDocGia();
		backMenu(tv, menuDocGia);
	}
}

void menuPhieuMuonTra(ThuVien tv)
{
	system("cls");
	cout << endl;
	cout << "   ---------------------  \n" << endl;
	cout << "   |   PHIEU MUON TRA  |    " << endl;
	cout << "   ---------------------  \n" << endl;
	cout << " 0. Menu chinh\n";
	cout << " 1. Thay doi ngay can xet.\n";
	cout << " 2. Tao phieu muon.\n";
	cout << " 3. Tao phieu tra.\n";
	cout << " 4. Thong ke nhung nguoi muon.\n";
	cout << " 5. Xuat danh sach phieu muon.\n";	
	int lc = luaChon(0, 5);
	switch (lc)
	{
	case 0:
		menuChinh(tv);
	case 1:
		system("cls");
		tv.thayDoiNgayDangXet();
		backMenu(tv, menuPhieuMuonTra);
	case 2:
		system("cls");
		tv.taoPhieuMuon();
		backMenu(tv, menuPhieuMuonTra);
	case 3:
		system("cls");
		tv.TaoPhieuTra();
		backMenu(tv, menuPhieuMuonTra);
	case 4:
		system("cls");
		tv.lietKeDanhSachMuonVaTienPhat();
		backMenu(tv, menuPhieuMuonTra);
	default:
		system("cls");
		tv.xuatDSPhieuMuonTra();
		backMenu(tv, menuPhieuMuonTra);
	}
}
int main()
{
	ThuVien tv;
	tv.docDuLieuTuFileVaNhapNgayHienTai();
	menuChinh(tv);
	
	system("pause");
	return 0;
}