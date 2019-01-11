#ifndef _DOC_GIA_H_
#define _DOC_GIA_H_

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class DocGia
{
private:
	string hoTen, CMND, queQuan,namSinh;
public:
	DocGia();
	DocGia(string hoten, string cmnd, string namsinh, string quequan) :
		hoTen(hoten), CMND(cmnd), namSinh(namsinh), queQuan(quequan) {}

	void docDocGia(string temp);

	void setHoTen(string hoten);
	void setCMND(string cmnd);
	void setNamSinh(string namsinh);
	void setQueQuan(string quequan);

	string getHoTen();
	string getCMND();

	bool timKiemTonTai(string temp);

	void nhapDocGia();
	void xuatDocGia();

	void suaDocGia();

	void xuatFile(ostream& outDev);
	~DocGia();
};

#endif // !_DOC_GIA_H_



