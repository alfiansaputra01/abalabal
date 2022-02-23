#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

typedef int typeinfo;
typedef struct vaksin *typeptr;

struct screening{
	char nama[50];
	int umur;
	long int NIK;
	int dosis;
	float suhu;
	int sistol;
	int diastol;
	int jenisvaksin;
	int status;
};

struct vaksin{
	screening info;
	typeptr next;
};

void buatlistbaru();
void inputdata();
void simpandata(screening BARU);
void cetakdata();
void cekdata();
void hapusdata(typeinfo IH);
void caridata();


typeptr awal;
typeptr akhir;

int main()
{
	int pilih;
	string ulang;
	typeptr cari;

	buatlistbaru();
	
	do{
	
	system("cls");
	cout << "Nama : Alfian Saputra" << endl;
	cout << "NIM : 123200007" << endl;
	
	cout << "\nPROGRAM VAKSINASI KOTA KENDARI" << endl;
	
	cout << endl;
	cout << "+------------------------------+" << endl;
	cout << "|****MENU PROGRAM VAKSINASI****|" << endl;
	cout << "+------------------------------+" << endl;
	cout << "| 1. Input Data                |" << endl;
	cout << "| 2. Lihat Peserta Vaksinasi   |" << endl;
	cout << "| 3. Cek Status Vaksinasi      |" << endl;
	cout << "| 4. Hapus Data Vaksinasi      |" << endl;
	cout << "| 5. Exit                      |" << endl;
	cout << "+------------------------------+" << endl;
		
	cout << "\nMasukkan Menu yang di pilih : "; cin>>pilih;
		if(pilih==1){
			system("cls");
			cout << "---------- INPUT DATA PESERTA VAKSINASI ---------" << endl;
			inputdata();
		} else if(pilih==2){
			cetakdata();
		} else if(pilih==3){
			cekdata();
		} else if(pilih==4){
			cout << "--------- HAPUS DATA PESERTA VAKSIN ---------" << endl;
			caridata();
		} else if(pilih==5){
			break;
		} 
			cout << "Kembali ke menu (y/n)? "; cin >> ulang;
	} while(ulang=="Y" || ulang=="y");
	
	return 0;
}

void buatlistbaru(){	
	typeptr baru;
	baru=(vaksin *) malloc(sizeof(vaksin));
	baru=NULL;                                          //mendeklarasikan bahwa data nya kosong
	awal=baru;
	akhir=baru;
}

void inputdata(){
	vaksin temp;
	
	cout << "\nScreening Tahap 1" << endl;
	cout << "     Nama\t\t: "; cin.ignore(); cin.getline(temp.info.nama, sizeof(temp.info.nama));
	cout << "     Umur\t\t: "; cin >> temp.info.umur;
	cout << "     NIK\t\t: "; cin >> temp.info.NIK;
	cout << "     Dosis Vaksin Ke-\t: "; cin >> temp.info.dosis; if(temp.info.dosis==2){temp.info.status=1;}
	
	if(temp.info.umur>12){
		cout << "Screening Tahap 2" << endl;
		cout << "     Suhu Badan\t\t: "; cin >> temp.info.suhu;
		cout << "     Tekanan Darah\t: "; cin >> temp.info.sistol; cin >> temp.info.diastol;
		
		if(temp.info.suhu<37.5 && (temp.info.sistol>=100 && temp.info.sistol<=120) && (temp.info.diastol>=60 && temp.info.diastol<=90)){
			cout << "\nScreening Tahap 3" << endl;
			cout << "+---------------------------------------------------------+" << endl;
			cout << "|***************Daftar Vaksin Yang Tersedia***************|" << endl;
			cout << "+---------------------------------------------------------+" << endl;
			cout << "| 1. Sinovac                                              |" << endl;
			cout << "| 2. Astrazeneca                                          |" << endl;
			cout << "| 3. Moderna                                              |" << endl;
			cout << "+---------------------------------------------------------+" << endl;
			cout << "Masukkan Vaksin yang di pilih : "; cin>>temp.info.jenisvaksin;
			cout << "Penginputan Data Selesai" << endl;	
		}
	} if(temp.info.umur<12||temp.info.suhu>37.5 || temp.info.sistol<100 || temp.info.sistol>120 || temp.info.diastol<60 || temp.info.diastol>90){
		cout << "Mohon maaf anda belum bisa melakukan vaksinasi" << endl;	
	}
	
	simpandata(temp.info);
}

void simpandata(screening BARU){
	typeptr NB;
	NB=(vaksin *)malloc(sizeof(vaksin));
	NB->info=BARU;
	if(awal==NULL){
		awal=NB;
		akhir=awal;
	}
	else{
		akhir->next=NB;
		akhir=NB;
	}
	akhir->next=NULL;
}

void cetakdata(){
	typeptr bantu;
	bantu=awal;
	int no=1;

	if (awal==NULL){
		cout << "Data Kosong" << endl;
	}
	else{
		while(bantu!=NULL){
			cout << no <<". " << bantu->info.nama << " (" << bantu->info.umur << ")" << endl;
			no++;
			bantu=bantu->next;
		}
	}
}

void cekdata(){
	typeptr bantu;
	long int cariNIK;
	int statussementara;
	string setujuvaksin, yakinvaksin;
	bantu=awal;

	if(awal==NULL){
		cout << "Data Kosong" << endl;
	} else{
		cout << "Silahkan masukkan NIK yang ingin anda cek" << endl;
		cout << "NIK : "; cin >> cariNIK;
		
		while(bantu!=NULL){
			if(bantu->info.NIK==cariNIK){
				if(bantu->info.status==0){
					cout << "Nama\t\t\t: " << bantu->info.nama << endl;
					cout << "Umur\t\t\t: " << bantu->info.umur << endl;
					cout << "NIK\t\t\t: " << bantu->info.NIK << endl;
					cout << "Suhu\t\t\t: " << bantu->info.suhu << endl;
					cout << "Tekanan Darah\t\t: " << bantu->info.sistol <<"/" << bantu->info.diastol << endl;
					cout << "Vaksin yang diambil\t: ";
					
					if(bantu->info.jenisvaksin==1){
						cout << "Sinovac";
					} else if(bantu->info.jenisvaksin==2){
						cout << "Astrazeneca";
					} else if(bantu->info.jenisvaksin==3){
						cout << "Moderna";}
						cout << endl;
					
						cout << "\nStatus Vaksinasi\t: Belum melakukan vaksinasi" << endl;
						cout << "Lakukan vaksinasi? "; cin >> setujuvaksin;
					
						if(setujuvaksin=="y"||setujuvaksin=="Y"){
							cout << "Yakin? "; cin>>yakinvaksin;
									
							if(yakinvaksin=="y" || yakinvaksin=="Y"){
								statussementara=1;
								bantu->info.status=statussementara;
							}
						}
							break;
					} else if(bantu->info.status==1){
						cout << "Nama\t\t\t: " << bantu->info.nama << endl;
						cout << "Umur\t\t\t: " << bantu->info.umur << endl;
						cout << "NIK\t\t\t: " << bantu->info.NIK << endl;
						cout << "Suhu\t\t\t: " << bantu->info.suhu << endl;
						cout << "Tekanan Darah\t\t: " << bantu->info.sistol << "/" << bantu->info.diastol << endl;
						cout << "Vaksin yang diambil\t: ";
					
						if(bantu->info.jenisvaksin==1){
							cout << "Sinovac";
						} else if(bantu->info.jenisvaksin==2){
							cout << "Astrazeneca";
						} else if(bantu->info.jenisvaksin==3){
							cout << "Moderna";
						}
							cout << endl;
							cout << "Status Vaksinasi\t: Sudah melakukan vaksinasi pertama" << endl;
							cout << "Lakukan vaksinasi? ";cin>>setujuvaksin;
					
							if(setujuvaksin=="y"||setujuvaksin=="Y"){
								cout << "Yakin? "; cin>>yakinvaksin;
								
								if(yakinvaksin=="y" || yakinvaksin=="Y"){
									statussementara=2;
									bantu->info.status=statussementara;
								}
							}
								break;
						} else if(bantu->info.status==2){
							cout << "Nama\t\t\t: " << bantu->info.nama << endl;
							cout << "Umur\t\t\t: " << bantu->info.umur << endl;
							cout << "NIK\t\t\t: " << bantu->info.NIK << endl;
							cout << "Suhu\t\t\t: " << bantu->info.suhu << endl;
							cout << "Tekanan Darah\t\t: " << bantu->info.sistol << "/" << bantu->info.diastol << endl;
							cout << "Vaksin yang diambil\t: ";
								
							if(bantu->info.jenisvaksin==1){
								cout << "Sinovac";
							} else if(bantu->info.jenisvaksin==2){
								cout << "Astrazeneca";
							} else if(bantu->info.jenisvaksin==3){
								cout << "Moderna";
							}
								cout << endl;
								cout << "Status Vaksinasi\t: Proses vaksinasi anda sudah selesai" << endl;
								break;
				}
			}
		}
	}
}

void hapusdata(typeinfo IH){
	typeptr bantu, hapus;
	
	if (awal==NULL){	
		cout << "Data Masih Kosong" << endl;
	} else{	
		if (awal->info.NIK==IH){													//menghapus data yang ada diawal	
			hapus=awal;
			awal=hapus->next;
			free(hapus);
		} else{	
			bantu=awal;																// proses mencari data yang akan dihapus
			while ((bantu->next->info.NIK!=IH) && (bantu->next!=NULL)){
				bantu=bantu->next;
		}
			hapus=bantu->next;
			
			if (hapus==NULL){	
				cout << "Data tidak ditemukan" << endl; 
			} else{	
				if (hapus==akhir){													//menghapus data paling akhir
					akhir=bantu;
					akhir->next=NULL;
				} else{  															//menghapus data yang ada di tengah
					bantu->next=hapus->next;
				}
					free(hapus);
			}
		}
	}
}

void caridata(){
	typeptr cari;
	long int hapusNIK;
	string yakinhapus;
	bool cek;
	cari=awal;

	cout << "Masukkan NIK yang akan dihapus : "; cin>>hapusNIK;
	
	if (awal==NULL){
		cout << "Data Kosong" << endl;
	} else{
		while(cari!=NULL){
			if(hapusNIK==cari->info.NIK){
				cout << cari->info.nama<< endl;
				cek=1;
			}
				cari=cari->next;
		} if(cek==1){
			cout << "Yakin hapus data? "; cin>>yakinhapus;
			
			if(yakinhapus=="y"||yakinhapus=="Y"){
				hapusdata(hapusNIK);
			}
		}
	}
}
