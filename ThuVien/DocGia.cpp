#include "DocGia.h"



DocGia::DocGia()
{
}




void DocGia::docDocGia(string temp)
{
	int pos = 0, pos1;
	pos1 = temp.find_first_of(',');
	setHoTen(temp.substr(pos, pos1 - pos));
	pos = pos1 + 1;
	pos1 = temp.find_first_of(',', pos);
	setCMND(temp.substr(pos, pos1 - pos));
	pos = pos1 + 1;
	pos1 = temp.find_first_of(',', pos);
	setNamSinh(temp.substr(pos, pos1 - pos));
	pos = pos1 + 1;
	pos1 = temp.find_first_of(',', pos);
	setQueQuan(temp.substr(pos, pos1 - pos));
}

void DocGia::setHoTen(string hoten)
{
	this->hoTen = hoten;
}

void DocGia::setCMND(string cmnd)
{
	this->CMND = cmnd;
}

string DocGia::getCMND()
{
	return string(this->CMND);
}

void DocGia::setNamSinh(string namsinh)
{
	this->namSinh = namsinh;
}

void DocGia::setQueQuan(string quequan)
{
	this->queQuan = quequan;
}

string DocGia::getHoTen()
{
	return string(this->hoTen);
}

bool DocGia::timKiemTonTai(string temp)
{
	return this->CMND == temp;
}

void DocGia::nhapDocGia()
{
	fflush(stdin);
	cout << "Nhap vao ho ten : ";
	getline(cin >> ws, this->hoTen);
	cout << "Nhap vao CMND : ";
	getline(cin >> ws, this->CMND);
	cout << "Nhap vao nam sinh : ";
	cin >> this->namSinh;
	cout << "Nhap vao que quan : ";
	getline(cin >> ws, this->queQuan);
}

void DocGia::xuatDocGia()
{
	cout << setw(25) << this->hoTen
		<< setw(15) << this->CMND
		<< setw(10) << this->namSinh
		<< setw(20) << this->queQuan;
}

void DocGia::suaDocGia()
{
	cout << "Nhap vao thong tin can sua : " << endl;
	cout << "1. Ho ten.\n";
	cout << "2. CMND.\n";
	cout << "3. Que quan.\n";
	cout << "4. Nam sinh.\n";
	cout << "5. Tat ca.\n";
	int ch;
	cout << "Nhap vao lua chon : ";
	cin >> ch;
	string temp;
	switch (ch)
	{
	case 1:
		cout << "Nhap vao ho ten can sua : ";
		getline(cin >> ws, temp);
		this->hoTen = temp;
		break;
	case 2:
		cout << "Nhap vao CMND can sua : ";
		getline(cin >> ws, temp);
		this->CMND = temp;
		break;
	case 3:
		cout << "Nhap vao que quan can sua : ";
		getline(cin >> ws, temp);
		this->queQuan = temp;
		break;
	case 4:
		cout << "Nhap vao nam sinh can sua : ";
		getline(cin >> ws, temp);
		this->namSinh = temp;
		break;
	default:
		nhapDocGia();
		break;
	}
	cout << endl;
}

void DocGia::xuatFile(ostream & outDev)
{
	outDev << this->hoTen << "," << this->CMND << "," << this->namSinh << "," << this->queQuan;
}

DocGia::~DocGia()
{
}
