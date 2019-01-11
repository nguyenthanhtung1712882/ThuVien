#include "PhieuMuonTra.h"



PhieuMuonTra::PhieuMuonTra()
{
}

void PhieuMuonTra::setCMND(string cmnd)
{
	this->CMND = cmnd;
}

void PhieuMuonTra::setMaSach(string masach)
{
	this->maSach = masach;
}

void PhieuMuonTra::setNgayMuon(MyDate md)
{
	this->ngayMuon = md;
}

void PhieuMuonTra::setNgayHanTra(MyDate md)
{
	this->ngayHanTra = md;
}

string PhieuMuonTra::getCMND()
{
	return string(this->CMND);
}

string PhieuMuonTra::getMaSach()
{
	return string(this->maSach);
}

MyDate PhieuMuonTra::getNgayMuon()
{
	return MyDate(this->ngayMuon);
}

MyDate PhieuMuonTra::getNgayHanTra()
{
	return MyDate(this->ngayHanTra);
}


void PhieuMuonTra::docPhieu(string temp)
{
	int pos = 0, pos1;
	MyDate md;
	pos1 = temp.find_first_of(',');
	setCMND(temp.substr(pos, pos1 - pos));
	pos = pos1 + 1;
	pos1 = temp.find_first_of(',', pos);
	setMaSach(temp.substr(pos, pos1 - pos));
	pos = pos1 + 1;
	pos1 = temp.find_first_of(',', pos);
	setNgayMuon(md.stringToDate(temp.substr(pos, pos1 - pos)));
	setNgayHanTra(md.stringToDate(temp.substr(pos, pos1 - pos))+ HAN_MUON);
}

void PhieuMuonTra::xuatPhieu()
{
	cout << left << setw(15) << this->CMND
		<< setw(10) << this->maSach
		<< setw(5) << "" << this->ngayMuon
		<< setw(5) << "" << this->ngayHanTra << endl;
}

void PhieuMuonTra::xuatFile(ostream & outDev)
{
	outDev << this->CMND << "," << this->maSach << "," << this->ngayMuon << "," << this->ngayHanTra;
}

PhieuMuonTra::~PhieuMuonTra()
{
}
