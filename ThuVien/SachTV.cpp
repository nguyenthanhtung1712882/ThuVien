#include "SachTV.h"



SachTV::SachTV()
{
}

void SachTV::setMaSach(string masach)
{
	this->maSach = masach;
}

string SachTV::getMaSach()
{
	return string(this->maSach);
}

void SachTV::setTenSach(string tensach)
{
	this->tenSach = tensach;
}

string SachTV::getTenSach()
{
	return this->tenSach;
}

string SachTV::getTacGia()
{
	return string(this->tacGia);
}

void SachTV::setTacGia(string tacgia)
{
	this->tacGia = tacgia;
}

void SachTV::setNXB(string nxb)
{
	this->NXB = nxb;
}

void SachTV::setGiaSach(string giasach)
{
	this->giaSach = giasach;
}

void SachTV::docSachTV(string temp)
{
	int pos = 0, pos1;
	pos1 = temp.find_first_of(',');
	setMaSach(temp.substr(pos, pos1 - pos));
	pos = pos1 + 1;
	pos1 = temp.find_first_of(',', pos);
	setTenSach(temp.substr(pos, pos1 - pos));
	pos = pos1 + 1;
	pos1 = temp.find_first_of(',', pos);
	setTacGia(temp.substr(pos, pos1 - pos));
	pos = pos1 + 1;
	pos1 = temp.find_first_of(',', pos);
	setNXB(temp.substr(pos, pos1 - pos));
	pos = pos1 + 1;
	pos1 = temp.find_first_of(',', pos);
	setGiaSach(temp.substr(pos, pos1 - pos));
}


void SachTV::nhapSach()
{
	fflush(stdin);
	cout << "Nhap vao ma sach : ";
	getline(cin >> ws, this->maSach);
	cout << "Nhap vao ten sach : ";
	getline(cin >> ws, this->tenSach);
	cout << "Nhap vao tac gia : ";
	getline(cin >> ws, this->tacGia);
	cout << "Nhap vao nha xuat ban : ";
	getline(cin >> ws, this->NXB);
	cout << "Nhap vao gia sach : ";
	getline(cin >> ws, this->giaSach);
}

void SachTV::xuatSach()
{
	cout << left << setw(12) << this->maSach
		<< setw(40) << this->tenSach
		<< setw(40) << this->tacGia
		<< setw(20) << this->NXB
		<< setw(12) << this->giaSach;
}

bool SachTV::timKiemTonTai(string temp)
{
	return (this->maSach == temp || this->tenSach == temp || this->tacGia == temp || this->NXB == temp || this->tacGia == temp);
}


void SachTV::suaSachTV()
{
	cout << "Chon loai thong tin can sua : " << endl;
	cout << "1. Ma sach\n";
	cout << "2. Ten sach\n";
	cout << "3. Tac gia\n";
	cout << "4. Nha xuat ban\n";
	cout << "5. Gia sach\n";
	cout << "6. Tat ca\n";
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
		cout << "Nhap vao tac gia can sua : ";
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
	default:
		nhapSach();
		break;
	}
}

int SachTV::tienPhat()
{
	return 10000;
}

void SachTV::xuatFile(ostream & outDev)
{
	outDev << this->maSach << "," << this->tenSach << "," << this->tacGia << "," << this->NXB << "," << this->giaSach;
}

SachTV::~SachTV()
{
}
