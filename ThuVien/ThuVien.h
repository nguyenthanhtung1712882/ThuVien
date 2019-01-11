#ifndef _THU_VIEN_H_
#define _THU_VIEN_H_

#include"SachTV.h"
#include"SachNN.h"
#include"DocGia.h"
#include"PhieuMuonTra.h"
#include"MyDate.h"
#include<fstream>
#include<vector>

class ThuVien
{
private:
	vector<SachTV*> dsSach;
	vector<DocGia> dsDocGia;
	vector<PhieuMuonTra> dsPhieu;
	MyDate homNay;
public:
	ThuVien();
	// Thao tác file sách
	void docFileSach();
	void xuatDSSach();

	void themSach();
	void timKiemSach();
	void xoaSach();
	void suaSach();

	// thao tác file độc giả
	void docFileDocGia();
	void xuatDSDocGia();

	void themDocGia();
	void timKiemDocGia();
	void xoaDocGia();
	void suaDocGia();

	// thao tác file phiếu
	void docFilePhieuMuonTra();
	void xuatDSPhieuMuonTra();

	void taoPhieuMuon();
	void TaoPhieuTra();

	void xuatDocGiaTheoCMND(DocGia a);
	void xuatSachTheoMaSach(SachTV* a);

	DocGia timDocGiaTheoCMND(string cmnd);
	SachTV* timSachTheoMaSach(string masach);

	void lietKeDanhSachMuonVaTienPhat();

	void xuatFileSach();
	void xuatFileDocGia();
	void xuatFilePhieuMuonTra();

	void docDuLieuTuFileVaNhapNgayHienTai();
	void luuDuLieuRaFile();

	void setNgayHomNay(MyDate md);
	MyDate getNgayHomNay();
	void thayDoiNgayDangXet();

	~ThuVien();
};

#endif // !_THU_VIEN_H_



