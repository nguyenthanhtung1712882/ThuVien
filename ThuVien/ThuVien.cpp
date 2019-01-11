#include "ThuVien.h"



ThuVien::ThuVien()
{
}

void ThuVien::docFileSach()
{
	fstream fileSach;
	fileSach.open("..//Data//Sach.csv", ios::in);
	if (fileSach.fail())
	{
		cout << "File khong ton tai." << endl;
		exit(0);
	}
	string temp;
	SachTV *a;
	getline(fileSach >> ws, temp);
	while (!fileSach.eof())
	{
		if (getline(fileSach >> ws, temp))
		{
			if (temp[temp.size() - 1] == ',')
			{
				a = new SachTV();
			}
			else
			{
				a = new SachNN();
			}
			a->docSachTV(temp);
			this->dsSach.push_back(a);
		}
	}
	fileSach.close();
}

void ThuVien::xuatDSSach()
{
	cout << left <<setw(5)<<"STT"<< setw(12) << "Ma sach"
		<< setw(40) << "Ten sach"
		<< setw(40) << "Tac gia"
		<< setw(20) << "Nha xuat ban"
		<< setw(12) << "Gia sach"
		<< setw(20) << "ISBN" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < dsSach.size(); i++)
	{
		cout << setw(5) << i + 1;
		dsSach[i]->xuatSach();
		cout << endl;
	}
	cout << endl;
}

void ThuVien::themSach()
{
	SachTV*a;
	int n;
	cout << "Nhap vao so luong can them : ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		system("cls");
		cout << "Lan nhap thu " << i + 1 << "/" << n << endl;
		cout << "1. Sach tieng viet\n2. Sach ngoai ngu\n";
		char ch;
		cout << "Nhap su lua chon : ";
		cin >> ch;
		if (ch == '1')a = new SachTV();
		else a = new SachNN();
		a->nhapSach();
		dsSach.push_back(a);
	}
}

void ThuVien::timKiemSach()
{
	string temp;
	int choose;
	if (dsSach.size() >= 1)
	{
		cout << "Nhap vao ma sach, ten sach hay tac gia can tim: ";
		getline(cin >> ws, temp);
		int flag = 0;
		for (auto a : dsSach)
		{
			if (a->timKiemTonTai(temp) == true)
			{
				if (flag == 0)
				{
					cout << left << setw(12) << "Ma sach"
						<< setw(40) << "Ten sach"
						<< setw(40) << "Tac gia"
						<< setw(20) << "Nha xuat ban"
						<< setw(12) << "Gia sach"
						<< setw(20) << "ISBN" << endl;
					cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				}
				a->xuatSach();
				cout << endl;
				flag = 1;
			}
		}
		if (flag == 0)cout << "Khong co sach nhu ban tim.\n";
		else cout << endl;
	}
}

void ThuVien::xoaSach()
{
	string temp;
	char ch;
	if (dsSach.size() >= 1)
	{
		cout << "Nhap vao ma sach de tim kiem sach can xoa : ";
		getline(cin >> ws, temp);
		int flag = 0;
		for (int i = 0; i < dsSach.size(); i++)
		{
			if (dsSach[i]->getMaSach() == temp)
			{
				dsSach.erase(dsSach.begin() + i);
				flag = 1;
			}
		}
		if (flag == 0)cout << "Khong co sach can xoa\n";
		else cout << "Da xoa thanh cong.\n";
	}
}

void ThuVien::suaSach()
{
	string temp;
	char choose;
	int ch;
	if (dsSach.size() >= 1)
	{
		cout << "Nhap vao ma sach de tim kiem sach can sua : ";
		getline(cin >> ws, temp);
		int flag = 0;
		for (int i = 0; i < dsSach.size(); i++)
		{
			if (dsSach[i]->getMaSach() == temp)
			{
					dsSach[i]->suaSachTV();
					flag = 1;
			}
		}
		if (flag == 0)cout << "Khong co sach de sua\n";
		else cout << "Da sua thanh cong.\n";
	}
}



void ThuVien::docFileDocGia()
{
	fstream fileDocGia;
	fileDocGia.open("..//Data//DocGia.csv", ios::in);
	if (fileDocGia.fail())
	{
		cout << "File khong ton tai." << endl;
		exit(0);
	}
	DocGia a;
	string temp;
	int i_DocGia = 0;
	getline(fileDocGia >> ws, temp);
	while (!fileDocGia.eof())
	{
		if (getline(fileDocGia >> ws, temp))
		{
			a.docDocGia(temp);
			dsDocGia.push_back(a);
		}
	}
	fileDocGia.close();
}

void ThuVien::xuatDSDocGia()
{
	cout << left << setw(5) << "STT" << setw(25) << "Ho ten"
		<< setw(15) << "CMND"
		<< setw(10) << "Nam sinh"
		<< setw(20) << "Que quan" << endl;
	cout << "-------------------------------------------------------------" << endl;
	/*for (auto a : dsSach)
	{
		a->xuatSach();
		cout << endl;
	}*/
	for (int i = 0; i < dsDocGia.size(); i++)
	{
		cout << setw(5) << i + 1;
		dsDocGia[i].xuatDocGia();
		cout << endl;
	}
	cout << endl;
}

void ThuVien::themDocGia()
{
	int n;
	cout << "Nhap vao so luong doc gia can them : ";
	cin >> n;
	DocGia docgia;
	for (int i = 0; i < n; i++)
	{
		cout << "Doc gia thu :" << i + 1 << "/" << n << endl;
		docgia.nhapDocGia();
		dsDocGia.push_back(docgia);
		cout << endl;
	}
}



void ThuVien::timKiemDocGia()
{
	if (dsDocGia.size() >= 1)
	{
		string temp;
		int flag = 0;
		cout << "Nhap vao so CMND doc gia can tim : ";
		getline(cin >> ws, temp);
		for (auto a : dsDocGia)
		{
			if (a.getCMND() == temp)
			{
				if (flag == 0)
				{
					cout << left << setw(25) << "Ho ten"
						<< setw(15) << "CMND"
						<< setw(10) << "Nam sinh"
						<< setw(20) << "Que quan" << endl;
					cout << "-------------------------------------------------------------" << endl;
				}
				a.xuatDocGia();
				cout << endl;
				flag = 1;
			}
		}
		if (flag == 0)cout << "Khong co doc gia can tim." << endl;
		else cout << endl;
	}
}

void ThuVien::xoaDocGia()
{
	if (dsDocGia.size() >= 1)
	{
		string temp;
		int flag = 0;
		cout << "Nhap vao so CMND doc gia can xoa : ";
		getline(cin >> ws, temp);
		for (int i = 0; i < dsDocGia.size(); i++)
		{
			if (dsDocGia[i].getCMND() == temp)
			{
				dsDocGia.erase(dsDocGia.begin() + i);
				cout << endl;
				flag = 1;
			}
		}
		if (flag == 0)cout << "Khong co doc gia can xoa." << endl;
		else cout << "Da xoa thanh cong !\n";
	}
}

void ThuVien::suaDocGia()
{
	if (dsDocGia.size() >= 1)
	{
		string temp;
		int flag = 0;
		cout << "Nhap vao so CMND doc gia can sua : ";
		getline(cin >> ws, temp);
		for (int i = 0; i < dsDocGia.size(); i++)
		{
			if (dsDocGia[i].getCMND() == temp)
			{
				dsDocGia[i].suaDocGia();
				flag = 1;
				break;
			}
		}
		if (flag == 0)cout << "Khong co doc gia can sua." << endl;
		else cout << "Da sua thanh cong !" << endl;
	}
}

void ThuVien::docFilePhieuMuonTra()
{
	fstream filePhieu;
	filePhieu.open("..//Data//PhieuMuonTra.csv", ios::in);
	if (filePhieu.fail())
	{
		cout << "File khong ton tai." << endl;
		exit(0);
	}
	string temp;
	PhieuMuonTra a;
	getline(filePhieu >> ws, temp);
	while (!filePhieu.eof())
	{
		if (getline(filePhieu >> ws, temp))
		{
			a.docPhieu(temp);
			dsPhieu.push_back(a);
		}
	}
	filePhieu.close();
}

void ThuVien::xuatDSPhieuMuonTra()
{
	cout << left << setw(5) << "STT" << setw(15) << "CMND"
		<< setw(10) << "Ma sach"
		<< setw(5) << "" << "Ngay muon"
		<< setw(5) << "" << "Ngay han tra" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < dsPhieu.size(); i++)
	{
		cout << setw(5) << i + 1;
		dsPhieu[i].xuatPhieu();
	}
}

void ThuVien::taoPhieuMuon()
{
	string temp;
	PhieuMuonTra pm;
	xuatDSDocGia();
	cout << endl;
	xuatDSSach();
	cout << endl;
	cout << "Luu y : Vui long nhap chinh xac CMND va ma sach !" << endl;
	while (1)
	{
		cout << "Nhap vao CMND nguoi muon : ";
		getline(cin >> ws, temp);
		if (timDocGiaTheoCMND(temp).getCMND() == temp)
		{
			pm.setCMND(temp);
			break;
		}
		cout << "Nguoi dung khong ton tai.\n";
	}
	while (1)
	{
		cout << "Nhap vao ma sach : ";
		getline(cin >> ws, temp);
		if (timSachTheoMaSach(temp)->getMaSach()==temp)
		{
			pm.setMaSach(temp);
			break;
		}
		cout << "Sach khong ton tai.\n";
	}
	pm.setNgayMuon(this->homNay);
	pm.setNgayHanTra(this->homNay + 7);
	dsPhieu.push_back(pm);
	cout << "\n\n";
	cout << "Thong tin doc gia muon sach: " << endl;
	xuatDocGiaTheoCMND(timDocGiaTheoCMND(pm.getCMND()));
	xuatSachTheoMaSach(timSachTheoMaSach(pm.getMaSach()));
	cout << "Thoi gian muon : " << this->homNay << " -> " << this->homNay + 7 << endl;
}

void ThuVien::TaoPhieuTra()
{
	string cmnd, masach;
	xuatDSPhieuMuonTra();
	cout << "\n\n";
	cout << "Luu y : Vui long nhap chinh xac CMND va ma sach !" << endl;
	cout << "Nhap vao CMND : ";
	getline(cin >> ws, cmnd);
	cout << "Nhap vao ma sach : ";
	getline(cin >> ws, masach);
	cout << "\n\n";
	int flag = 0;
	for (int i = 0; i < dsPhieu.size(); i++)
	{
		if (dsPhieu[i].getCMND() == cmnd && dsPhieu[i].getMaSach() == masach)
		{
			cout << "DOC GIA : " << endl;
			xuatDocGiaTheoCMND(timDocGiaTheoCMND(cmnd));
			xuatSachTheoMaSach(timSachTheoMaSach(masach));
			cout << "Ngay muon : " << dsPhieu[i].getNgayMuon() << " -> " << dsPhieu[i].getNgayHanTra() << endl;
			cout << "Ngay tra : " << this->homNay << endl;
			int day = this->homNay - dsPhieu[i].getNgayHanTra();
			if (day > 0)
			{
				cout << "Tien phat : " << day << "(ngay) * " << dsSach[i]->tienPhat() << " (dong/ngay) = "
					<< day * dsSach[i]->tienPhat() << " dong" << endl;
			}
			else {
				cout << "Ban da tra sang dung han. :)" << endl;
			}
			dsPhieu.erase(dsPhieu.begin() + i);
			flag = 1;
		}
	}
	if (flag == 0)cout << "\nThong tin nhap vao khong chinh xac.\n";
	else cout << "\nPhieu tra sach in ra thanh cong\n";
}

void ThuVien::docDuLieuTuFileVaNhapNgayHienTai()
{
	docFileSach();
	docFileDocGia();
	docFilePhieuMuonTra();

	cout << "Nhap ngay can xet (tu ngay 15/01/2019 tro ve sau ). ";
	cin >> this->homNay;
}

void ThuVien::xuatDocGiaTheoCMND(DocGia a)
{
	cout << "Ho ten : " << a.getHoTen() << endl;
	cout << "CMND : " << a.getCMND() << endl;
}

void ThuVien::xuatSachTheoMaSach(SachTV * a)
{
	cout << "Ma sach : " << a->getMaSach() << endl;
	cout << "Ten sach : " << a->getTenSach() << endl;
	cout << "Tac gia : " << a->getTacGia() << endl;
}

DocGia ThuVien::timDocGiaTheoCMND(string cmnd)
{
	DocGia a;
	for (int i = 0; i < dsDocGia.size(); i++)
	{
		if (dsDocGia[i].getCMND() == cmnd)
		{
			a = dsDocGia[i];
			break;
		}
	}
	return a;
}

SachTV * ThuVien::timSachTheoMaSach(string masach)
{
	SachTV* a = NULL;
	for (int i = 0; i < dsSach.size(); i++)
	{
		if (dsSach[i]->getMaSach() == masach)
		{
			a = dsSach[i];
			break;
		}
	}
	return a;
}

void ThuVien::lietKeDanhSachMuonVaTienPhat()
{
	cout << "Thoi gian dang xet : " << ThuVien::getNgayHomNay() << endl;
	for (int i = 0; i < dsPhieu.size(); i++)
	{
		cout << "\tNGUOI MUON " << i + 1 << ":" << endl;
		xuatDocGiaTheoCMND(timDocGiaTheoCMND(dsPhieu[i].getCMND()));
		xuatSachTheoMaSach(timSachTheoMaSach(dsPhieu[i].getMaSach()));
		cout << "Ngay muon : " << dsPhieu[i].getNgayMuon() << " -> " << dsPhieu[i].getNgayHanTra() << endl;
		int day = this->homNay - dsPhieu[i].getNgayHanTra();
		if (day > 0)
		{
			cout << "Nguoi muon da muon qua han : " << endl;
			cout << "Tien phat : " << day << "(ngay) * " << dsSach[i]->tienPhat() << " (dong/ngay) = "
				<< day * dsSach[i]->tienPhat() << " dong." << endl;
		}
		else {
			cout << "Van con trong thoi gian muon. Den het ngay. " << dsPhieu[i].getNgayMuon() + 7 << endl;
		}
		cout << endl;
	}
}

void ThuVien::xuatFileSach()
{
	fstream fileSach;
	fileSach.open("..//Data//Sach.csv", ios::out);
	fileSach << "Ma sach, Ten sach, Tac gia, NXB, Gia sach, ISBN" << endl;
	for (auto a : dsSach)
	{
		a->xuatFile(fileSach);
		fileSach << endl;
	}
	cout << "Xuat file sach thanh cong !\n";
}

void ThuVien::xuatFileDocGia()
{
	fstream fileDocGia;
	fileDocGia.open("..//Data//DocGia.csv", ios::out);
	fileDocGia << "Ho ten, CMND, Nam sinh, Que quan" << endl;
	for (auto a : dsDocGia)
	{
		a.xuatFile(fileDocGia);
		fileDocGia << endl;
	}
	cout << "Xuat file doc gia thanh cong !\n";
}

void ThuVien::xuatFilePhieuMuonTra()
{
	fstream filePhieu;
	filePhieu.open("..//Data//PhieuMuonTra.csv", ios::out);
	filePhieu << "CMND, Ma sach, Ngay muon, Ngay han tra" << endl;
	for (auto a : dsPhieu)
	{
		a.xuatFile(filePhieu);
		filePhieu << endl;
	}
	cout << "Xuat file phieu muon/tra thanh cong !\n";
}

void ThuVien::luuDuLieuRaFile()
{
	xuatFileSach();
	xuatFileDocGia();
	xuatFilePhieuMuonTra();
}

void ThuVien::setNgayHomNay(MyDate md)
{
	this->homNay = md;
}

MyDate ThuVien::getNgayHomNay()
{
	return MyDate(this->homNay);
}

void ThuVien::thayDoiNgayDangXet()
{
	MyDate md;
	cout << "Nhap ngay can xet (tu ngay 15/01/2019 tro ve sau ). ";
	cin >> md;
	setNgayHomNay(md);
}

ThuVien::~ThuVien()
{
}
