#ifndef _PHIEU_MUON_TRA_H_
#define _PHIEU_MUON_TRA_H_

#include"MyDate.h"
#include<iomanip>
const int HAN_MUON = 7;

class PhieuMuonTra{
private:
	string CMND, maSach;
	MyDate ngayMuon;
	MyDate ngayHanTra;
public:
	PhieuMuonTra();

	void setCMND(string cmnd);
	void setMaSach(string masach);
	void setNgayMuon(MyDate md);
	void setNgayHanTra(MyDate md);

	string getCMND();
	string getMaSach();
	MyDate getNgayMuon();
	MyDate getNgayHanTra();

	void docPhieu(string temp);
	void xuatPhieu();

	void xuatFile(ostream& outDev);

	~PhieuMuonTra();
};

#endif // !_PHIEU_MUON TRA_H_



