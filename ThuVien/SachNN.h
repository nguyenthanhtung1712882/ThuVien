#ifndef _SACH_NGOAI_NGU_
#define _SACH_NGOAI_NGU_
#include"SachTV.h"

class SachNN:public SachTV
{
protected:
	string ISBN;
public:
	SachNN();
	SachNN(string masach, string tensach, string tacgia, string nxb, string giasach, string isbn) :
		SachTV(masach, tensach, tacgia, nxb, giasach), ISBN(isbn) {}

	void setISBN(string isbn);

	void docSachTV(string temp);
	void nhapSach();
	void xuatSach();
	// tương tự ở đây cũng so sánh từng thuộc tính trả về true/false
	bool timKiemTonTai(string temp);

	void suaSachTV();

	int tienPhat();

	void xuatFile(ostream& outDev);
	~SachNN();
};

#endif // !_SACH_NGOAI_NGU_



