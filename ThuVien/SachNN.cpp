#include "SachNN.h"



SachNN::SachNN()
{
}


void SachNN::setISBN(string isbn)
{
	this->ISBN = isbn;
}

void SachNN::docSachTV(string temp)
{
	SachTV::docSachTV(temp);
	int pos, pos1 = temp.size() - 1;
	pos = temp.find_last_of(',', pos1);
	setISBN(temp.substr(pos + 1, pos1 - pos - 1));
}

void SachNN::nhapSach()
{
	SachTV::nhapSach();
	cout << "Nhap ISBN : ";
	getline(cin >> ws, this->ISBN);
}

void SachNN::xuatSach()
{
	SachTV::xuatSach();
	cout << setw(20) << this->ISBN;
}

bool SachNN::timKiemTonTai(string temp)
{
	return (this->maSach == temp || this->tenSach == temp || this->tacGia == temp || this->NXB == temp || this->tacGia == temp || this->ISBN == temp);
}

void SachNN::suaSachTV()
{
	cout << "Chon loai thong tin can sua : " << endl;
	cout << "1. Ma sach.\n";
	cout << "2. Ten sach.\n";
	cout << "3. Tac gia.\n";
	cout << "4. Nha xuat ban.\n";
	cout << "5. Gia sach.\n";
	cout << "6. ISBN.\n";
	cout << "7. Tat ca.\n";
	cout << "Nhap vao lua chon :";
	int ch;
	cin >> ch;
	string temp;
	switch (ch)
	{
	case 1:
		cout << "Nhap vao ma sach can sua : ";
		getline(cin >> ws, temp);
		this->maSach = temp;
		break;
	case 2:
		cout << "Nhap vao ten sach can sua : ";
		getline(cin >> ws, temp);
		this->tenSach = temp;
		break;
	case 3:
		cout << "Nhap vao tac gia can sua: ";
		getline(cin >> ws, temp);
		this->tacGia = temp;
		break;
	case 4:
		cout << "Nhap vao nha xuat ban can sua : ";
		getline(cin >> ws, temp);
		this->NXB = temp;
		break;
	case 5:
		cout << "Nhap vao gia sach can sua : ";
		getline(cin >> ws, temp);
		this->giaSach = temp;
		break;
	case 6:
		cout << "Nhap ma ISBN can sua : ";
		getline(cin >> ws, temp);
		this->ISBN = temp;
		break;
	default:
		nhapSach();
		break;
	}
}

int SachNN::tienPhat()
{
	return 20000;
}

void SachNN::xuatFile(ostream & outDev)
{
	SachTV::xuatFile(outDev);
	outDev << "," << this->ISBN;
}

SachNN::~SachNN()
{
}
