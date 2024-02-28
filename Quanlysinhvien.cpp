#include<iostream>
#include<string.h>
#include<conio.h>
#include<iomanip>
using namespace std;
class sinhvien
{
	public:
		char hoten[20], gioitinh[20];
		char namsinh[20], diachi[30];
		char masv[10], lop[10];
		float toan, ly, hoa, sinh, anh, dia, DTB;
			void nhap();
			void hienthi();
};

void sinhvien::nhap()
{
	cin.ignore(1);
	cout<<"\n Nhap ho ten:";cin.getline(hoten,20);fflush(stdin);
	cout<<"\n Nhap gioi tinh:";cin.getline(gioitinh,20);fflush(stdin);
	cout<<"\n Nhap nam sinh:";cin.getline(namsinh,20);fflush(stdin);
	cout<<"\n Nhap dia chi:";cin.getline(diachi,30);fflush(stdin);
	cout<<"\n Nhap ma sinh vien:";cin.getline(masv,10);fflush(stdin);
	cout<<"\n Nhap lop:";cin.getline(lop,10);fflush(stdin);
	cout<<"\n Nhap diem toan:";
	cin>>toan;
	cout<<"\n Nhap diem ly:";
	cin>>ly;
	cout<<"\n Nhap diem hoa:";
	cin>>hoa;
	cout<<"\n Nhap diem sinh:";
	cin>>sinh;
	cout<<"\n Nhap diem anh:";
	cin>>anh;
	cout<<"\n Nhap diem dia:";
	cin>>dia;
	cout<<endl;
}

void sinhvien::hienthi()
{
	cout<<""<<hoten<<setw(8)<<gioitinh<<setw(10)<<namsinh;
	cout<<""<<setw(11)<<diachi<<setw(11)<<masv<<setw(11)<<lop;
	
	cout<<""<<setw(10)<<toan<<setw(10)<<ly<<setw(10)<<hoa<<setw(10)<<sinh;
	cout<<""<<setw(10)<<anh<<setw(10)<<dia;
	
	DTB=(toan+ly+hoa+sinh+anh+dia)/6;
	cout<<""<<setw(12)<<DTB;
	cout<<""<<setw(10)<<setprecision(2)<<DTB;
	
	if(DTB>=8)
	{
		cout<<" Xep loai gioi\n";
	}
	else if(DTB>=7)
	{
		cout<<" Xep loai Kha\n";
	}
		else if(DTB>=5)
	{
		cout<<" Xep loai Trung binh\n";
	}
		else if(DTB<5)
	{
		cout<<" Xep loai Yeu\n";
	}
}

class quanlysv: public sinhvien
{
	public:
		sinhvien sv[100];
		int n;
		
			void nhap();
			void hienthi();
			void xeploaiHL();
			void dssvDTBtd();
			void dssvDTBgd();
			void timsvDTBMAX();
			void timkiemsv();
};

void quanlysv::nhap()
{
	cout<<"Nhap so luong sinh vien:";cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\n sinh vien thu:"<<i+1<<"";
		sv[i].nhap();
	}
}

void quanlysv::hienthi()
{
	cout<<"\n Ho Ten"<<setw(12)<<"Gioi Tinh"<<setw(11)<<"Nam Sinh"<<setw(12);
	cout<<"Dia Chi"<<setw(14)<<"Ma Sinh Vien"<<setw(12)<<"Lop"<<setw(10);
	
	cout<<"Toan"<<setw(10)<<"Ly"<<setw(10)<<"Hoa"<<setw(10)<<"Sinh"<<setw(10);
	cout<<"Anh"<<setw(10)<<"Dia"<<setw(9)<<"DTB"<<setw(14)<<"DTB Lam Tron\n";
	for(int i=0;i<n;i++)
	{
		sv[i].hienthi();
	}
}

void quanlysv::xeploaiHL()
{
	cout<<"\n";
	cout<<"---\n Sinh vien xep loai hoc luc Gioi---"<<endl;
	for(int i=0;i<n;i++)
	{
		if(sv[i].DTB>=8)
		{
			sv[i].hienthi();
		}
	}
	cout<<"\n";
	cout<<"---\n Sinh vien xep loai hoc luc Kha---"<<endl;
	for(int i=0;i<n;i++)
	{
		if(sv[i].DTB>=7)
		{
			sv[i].hienthi();
		}
	}
	cout<<"\n";
	cout<<"---\n Sinh vien xep loai hoc luc Trung Binh---"<<endl;
	for(int i=0;i<n;i++)
	{
		if(sv[i].DTB>=5)
		{
			sv[i].hienthi();
		}
	}
	cout<<"\n";
	cout<<"\n--- Sinh vien xep loai hoc luc Yeu---"<<endl;
	for(int i=0;i<n;i++)
	{
		if(sv[i].DTB<5)
		{
			sv[i].hienthi();
		}
	}
}

void quanlysv::dssvDTBtd()
{
	int i,j;
	sinhvien tg;
	cout<<"\n";
	cout<<"\n---Danh sach sinh vien co diem trung binh tang dan---"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(sv[i].DTB>sv[j].DTB)
			tg=sv[i];
			sv[i]=sv[j];
			sv[j]=tg;
		}
	}
	cout<<"Sau khi sap xep la:"<<endl;
	for(int i=0;i<n;i++)
	{
		sv[i].hienthi();
	}
}

void quanlysv::dssvDTBgd()
{
	int i,j;
	sinhvien gd;
	cout<<"\n";
	cout<<"\n---Danh sach sinh vien co diem trung binh giam dan---"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(sv[i].DTB<sv[j].DTB)
			gd=sv[i];
			sv[i]=sv[j];
			sv[j]=gd;
		}
	}
	cout<<"Sau khi sap xep la:"<<endl;
	for(int i=0;i<n;i++)
	{
		sv[i].hienthi();
	}
}

void quanlysv::timsvDTBMAX()
{
	cout<<"\n";
	cout<<"\n---Danh sach sinh vien co diem trung binh cao nhat---"<<endl;
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(sv[i].DTB>max)
		{
			max= sv[i].DTB;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(sv[i].DTB>max)
		{
			sv[i].hienthi();
		}
	}
}

void quanlysv::timkiemsv()
{
	string msv;
	int count=0;
	cout<<"\n Nhap ma sinh vien can tim:";fflush(stdin);getline(cin,msv);
	cout<<"\n--- Thong tin sinh vien khi nhap xong la---";
	cout<<"\n Ho ten"<<setw(12)<<"Gioi Tinh"<<setw(11)<<"Nam Sinh"<<setw(12);
	cout<<"Dia chi"<<setw(14)<<"Ma Sinh Vien"<<setw(12)<<"Lop"<<setw(10);
	cout<<"Anh"<<setw(10)<<"Dia"<<setw(9)<<"DTB"<<setw(14)<<"DTB Lam Tron"<<setw(10);
	for(int i=0;i<n;i++)
	{
		if(sv[i].masv == msv)
		{
			sv[i].hienthi();
			count++;
		}
	}
	if(count == 0)
	{
		cout<<"\n Khong tim thay thong tin sinh vien";
	}
}
int main()
{
	quanlysv QLSV;
	int option,n;
	cout<<"---Day La Chuong Trinh Quan Ly Sinh Vien---\n";
	cout<<"Xin moi cac ban nhap mot so > 0 de tiep tuc:";cin>>n;
	while(n>0)
	{
		cout<<"\n==============MENU==============";
		cout<<"\n === Chuong Trinh Quan Ly Sinh Vien ===";
		cout<<"\n 1.Nhap thong tin sinh vien.";
		cout<<"\n 2.Hien thi thong tin sinh vien.";
		cout<<"\n 3.Xep loai hoc luc sinh vien.";
		cout<<"\n 4.Sap xep sinh vien co diem trung binh tang dan.";
		cout<<"\n 5.Sap xep sinh vien co diem trung binh giam dan.";
		cout<<"\n 6.Tim kiem sinh vien co diem trung binh cao nhat.";
		cout<<"\n 7.Tim kiem sinh vien theo ma sinh vien.";
		cout<<"\n *Xin moi nhap lua chon cua ban:";cin>>option;
		switch(option)
		{
			case 1:
				QLSV.nhap();
				cout<<"Bam mot phim bat ki de tiep tuc. \n";
				system("pause");
				break;
			case 2:
				QLSV.hienthi();
				cout<<"Bam mot phim bat ki de tiep tuc. \n";
				system("pause");
				break;
			case 3:
				QLSV.xeploaiHL();
				cout<<"Bam mot phim bat ki de tiep tuc. \n";
				system("pause");
				break;
			case 4:
				QLSV.dssvDTBtd();
				cout<<"Bam mot phim bat ki de tiep tuc. \n";
				system("pause");
				break;
			case 5:
				QLSV.dssvDTBgd();
				cout<<"Bam mot phim bat ki de tiep tuc. \n";
				system("pause");
				break;
			case 6:
				QLSV.timsvDTBMAX();
				cout<<"Bam mot phim bat ki de tiep tuc. \n";
				system("pause");
				break;
			case 7:
				QLSV.timkiemsv();
				cout<<"Bam mot phim bat ki de tiep tuc. \n";
				system("pause");
				break;
			default:
				cout<<"\n Khong tim thay du lieu ban nhap. Xin moi nhap lai.";
				cout<<"Bam mot phim bat ki de tiep tuc. \n";
				system("pause");
		}
	}

	return 0;
}