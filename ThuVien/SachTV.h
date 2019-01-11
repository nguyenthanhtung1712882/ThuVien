#ifndef _SACH_TIENG_VIET_H_
#define _SACH_TIENG_VIET_H_

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class SachTV
{
protected:
	string maSach, tenSach, tacGia, NXB, giaSach;
public:
	SachTV();
	SachTV(string masach, string tensach, string tacgia, string nxb, string giasach) :
		maSach(masach), tenSach(tensach), tacGia(tacgia), NXB(nxb), giaSach(giasach) {}

	void setMaSach(string masach);
	void setTenSach(string tensach);
	void setTacGia(string tacgia);
	void setNXB(string nxb);
	void setGiaSach(string giasach);
	// virtual ở đây do lớp SachNN kế thừa đã có ko cài đặt trỏ lại hàm này
	virtual string getMaSach();
	virtual string getTenSach();
	virtual string getTacGia();
	// tách dữ liệu các thông tin sách từ một chuối string
	virtual void docSachTV(string temp);

	virtual void nhapSach();
	virtual void xuatSach();
	// so sánh với tất cả thuộc tính trong class SachTV
	virtual bool timKiemTonTai(string temp);

	virtual void suaSachTV();

	virtual int tienPhat();

	// xuat 1 file theo dạng csv (1 câu)
	virtual void xuatFile(ostream& outDev);

	~SachTV();
};

#endif // !_SACH_TIENG_VIET_H_


