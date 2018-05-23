#include <stdio.h> // memakai library stdio untuk dapat memanggil fungsi fungsi yang ada ex printf
#include <stdlib.h> // memakai library untuk dapat memanggil fungsi fungsi yang ada ex system
#include <windows.h> // memakai library windows untuk dapat memanggil fungsi fungsi yang ada ex Sleep

int input; // untuk inputan user untuk switch case
int totalsks,sks; // totalsks untuk mendeskripsikan total sks yang diperoleh, sks untuk mendeskripsikan jumlah sks tiap mata kuliah
int totalkomp,kmp; //totalkomp untuk mendeskripsikan total komponen yang diperoleh, kmp untuk mendeskripsikan nilai bobot komponen dari total Komponen 
int totalnilai,nilai;// totalnilai untuk mendeskripsikan total nilai yang diperoleh tiap mata kuliah, nilai untuk mendeskripsikan nilai bobot komponen tiap komponen
int totalnilai2; // totalnilai2 bernilai sama seperti total nilai satu tetapi total nilai di reset untuk dipakai perhitungan di matkul lain 
int pembagitotalkmp, pembagitotalsks;//pembagitotalkmp sebagai pembagi agar nilai sesuai dengan inputan komponen,pembagitotalsks untuk membagi nilai nilai agar menjadi ipk
int judul(); // fungsi judul program agar bisa dipanggil di fungsi lain 
int keluarmenu();  //fugsi keluar menu agar bisa dipanggil di fungsi lain  
char ketnamakomponen[50],ketnamamatkul[50]; // keteranagan nama komponen dan ketarangan nama matkul
float totalnilaiskala4 ; // totalnilaiskala4 untuk mendeskripsian total nilai yang diperoleh tiap mata kuliah dengan sekala 0-4
float ipksementara ;// ipksementara untuk mendeskripsian ipk yang diperoloeh sementara
float penghitungipk ; // penghitungipk untuk menghitung ipk yang diperoloeh sementara
int target = 0; // target untuk menjadi parameter jika masuk featur targetipk maka 1 jika tidak maka 0

FILE *fp; // file dengan pointer fp

int ipk()
{
	Sleep(1000); // untuk mendelay dengan 1000 ms atau 1 detik
	pembagitotalsks += sks; // agar pembagi sama dengan total inputan sks
	ipksementara = penghitungipk/pembagitotalsks; // perhitungan ipk
//	printf("		Pembagi	:%d\n",pembagitotalsks); // untuk mengecek nilai pembagitotal adalah penjumlahan dari jumlah sks yang telah di input
	printf("		Predikisi IPK SEMENTARA		:%.2f\n",ipksementara);
	
	if (target == 1) // agar membedakan dengan prediksiipk dengan target 0
	{
		fp = fopen("target.txt", "a+"); // membuka file target dengan mode a+ bisa write + read dengan melanjutkan file sebelumnya di pointer fp
		fprintf(fp, "#%.2f", ipksementara  );// memasukan nilai ipk sementara
   		fclose(fp); // file di tutup
	}
}
void savenilaitotal()
{
	if (target == 1) // agar membedakan dengan prediksiipk dengan target 0	
	{
		fp = fopen("target.txt", "a+");// membuka file target dengan mode a+ bisa write + read dengan melanjutkan file sebelumnya di pointer fp
		fprintf(fp, "%d#%d", totalnilai2, totalnilaiskala4  );
   		fclose(fp);// file di tutup
	}
}

//fungsi ini untuk menentukan nilaiakhir mata kuliah
int nilaitotal()
{	
	totalnilai2 = totalnilai; // menjadikan totalnilai2 nilainya sama dengan totalnilai
	Sleep(100); // untuk mendelay dengan 1000 ms atau 1 detik
	if(totalnilai2>= 85 && totalnilai2<=100)
	{
		printf("\n		Total Nilai			:%d \n", totalnilai2);
		printf("		Nilai Huruf			:A \n");
		totalnilaiskala4 = 4;
		printf("		Nilai Skala 4			:%.2f\n\n\n",totalnilaiskala4);
		savenilaitotal(); // menyimpan nilai  dengan memanggil fungsi savnilaitotal
		penghitungipk += totalnilaiskala4 * sks;
	}
	else if(totalnilai2>= 80 && totalnilai2<85)
	{
		printf("\n		Total Nilai			:%d \n", totalnilai2);
		printf("		Nilai Huruf			:A- \n");
		totalnilaiskala4 = 3.7;
		printf("		Nilai Skala 4			:%.2f\n\n\n",totalnilaiskala4);
		savenilaitotal(); // menyimpan nilai  dengan memanggil fungsi savnilaitotal
		penghitungipk += totalnilaiskala4 *sks ;
	}
	else if(totalnilai2>= 75 && totalnilai2<80)
	{
		printf("\n		Total Nilai			:%d \n", totalnilai2);
		printf("		Nilai Huruf			:B+ \n");
		totalnilaiskala4 = 3.3;
		printf("		Nilai Skala 4			:%.2f\n\n\n",totalnilaiskala4);
		savenilaitotal(); // menyimpan nilai  dengan memanggil fungsi savnilaitotal
		penghitungipk += totalnilaiskala4 * sks;
	}
	else if(totalnilai2>= 70 && totalnilai2<75)
	{
		printf("\n		Total Nilai			:%d \n", totalnilai2);
		printf("		Nilai Huruf			:B \n");
		totalnilaiskala4 = 3;
		printf("		Nilai Skala 4			:%.2f\n\n\n",totalnilaiskala4);
		savenilaitotal(); // menyimpan nilai  dengan memanggil fungsi savnilaitotal
		penghitungipk += totalnilaiskala4 * sks;
	}
	else if(totalnilai2>= 65 && totalnilai2<70)
	{
		printf("\n		Total Nilai			:%d \n", totalnilai2);
		printf("		Nilai Huruf			:B- \n");
		totalnilaiskala4 = 2.7;
		printf("		Nilai Skala 4			:%.2f\n\n\n",totalnilaiskala4);
		savenilaitotal(); // menyimpan nilai  dengan memanggil fungsi savnilaitotal
		penghitungipk += totalnilaiskala4 * sks;
	}
	else if(totalnilai2>= 60 && totalnilai2<65)
	{
		printf("\n		Total Nilai			:%d \n", totalnilai2);
		printf("		Nilai Huruf			:C+ \n");
		totalnilaiskala4 = 2.3;
		printf("		Nilai Skala 4			:%.2f\n\n\n",totalnilaiskala4);
		savenilaitotal(); // menyimpan nilai  dengan memanggil fungsi savnilaitotal
		penghitungipk += totalnilaiskala4 * sks;
	}
	else if(totalnilai2>= 55 && totalnilai2<60)
	{
		printf("\n		Total Nilai			:%d \n", totalnilai2);
		printf("		Nilai Huruf			:C \n");
		totalnilaiskala4 = 2;
		printf("		Nilai Skala 4			:%.2f\n\n\n",totalnilaiskala4);
		savenilaitotal(); // menyimpan nilai  dengan memanggil fungsi savnilaitotal
		penghitungipk += totalnilaiskala4 * sks;
	}
	else if(totalnilai2>= 50 && totalnilai2<55)
	{
					
		printf("\n		Total Nilai			:%d \n", totalnilai2);
		printf("		Nilai Huruf			:C- \n");
		totalnilaiskala4 = 1.7;
		savenilaitotal(); // menyimpan nilai  dengan memanggil fungsi savnilaitotal
		printf("		Nilai Skala 4			:%.2f\n\n\n",totalnilaiskala4);
		penghitungipk += totalnilaiskala4 * sks;
	}
	else if(totalnilai2>= 40 && totalnilai2<50)
	{
		printf("\n		Total Nilai			:%d \n", totalnilai2);
		printf("		Nilai Huruf			:D \n");
		totalnilaiskala4 = 1.3;
		printf("		Nilai Skala 4			:%.2f\n\n\n",totalnilaiskala4);
		savenilaitotal(); // menyimpan nilai  dengan memanggil fungsi savnilaitotal
		penghitungipk += totalnilaiskala4 * sks;
	}
	else if(totalnilai2>= 0 && totalnilai2<40)
	{
		printf("\n		Total Nilai			:%d \n", totalnilai2);
		printf("		Nilai Huruf			:E \n");
		totalnilaiskala4 = 1;
		printf("		Nilai Skala 4			:%.2f\n\n\n",totalnilaiskala4);
		savenilaitotal(); // menyimpan nilai  dengan memanggil fungsi savnilaitotal
		penghitungipk += totalnilaiskala4 * sks; // penghitung ipk untuk mengetahui nilai mutu ipk dengan += adalah nilai sebelumnya ditambah karena looping
	}
	else {
		printf("\n\nAnda mungkin memasukan angka yang salah Silahkan ulang program kembali\n");
		keluarmenu(); // memanggil fungsi keluarmenu
	}
	ipk(); // memanggil fungsi ipk
	totalnilai = 0;
//	printf("total nilai = %d",totalnilai); untuk mengecek total nilai terreset atau tidak agar tidak mempengaruhi nilai matakuliah lain

}

// ini untuk inputan komponen fungsi ini menjelaskan komponen nilai
int komponen()
{
	printf("\n		Nama Komponen 			:");
	scanf(" %[^\n]",&ketnamakomponen); // %[^\n] adalah inputan akan berakhir jika di enter (\n)
	printf("		Bobot Komponen (dalam persen)	:"); 
	scanf("%d", &kmp);// memasukan jumlah sks diambil di mata kuliah
	
	if (kmp <= totalkomp) // agar inputan sks benar dengan tidak melebihi total sks
	{
		totalkomp -= kmp ;	 // agar bisa membadingkan dengan total sks yang diperoleh
		printf("		Nilai Komponen			:");
		scanf("%d", &nilai);
		totalnilai +=  (nilai * kmp  / (pembagitotalkmp ) ); // menghitung total nilai dengan mengalikan nilai dengan komponen dibagi dengan total komponen agar nilai komponen ketika loop menghasilkan nilai yang akuran
//		printf("%d", totalnilai); untuk mengecek total nilai yang ada sesuai dengan perhitungan
		return totalnilai;
	}
	else
	{
		// pesan eror
		printf("\n			Harap Masukan Bobot Komponen dengan benar \n"); 
		printf("			Tidak melebihi total Komponen  \n");
		printf("			Silahkan ulang Kembali \n");	
		return komponen();
	}
}

// ini untuk inputan matakuliah
int matakuliah()
	{
		printf("\n\tNama Mata Kuliah	:");
		scanf(" %[^\n]",&ketnamamatkul); //%[^\n] Error handling ketika input ada spasi=>> sekarang sudah bisa ada spasi dengan acuan enter untuk mengakhiri inputan
		printf("\tJumlah Sks		:"); 
		scanf("%d", &sks);// memasukan jumlah sks diambil di matakuliah
		// save file dengan parameter nilai target jika nilai target 1 maka akan men nulis data
		if (target == 1)
		{
			fp = fopen("target.txt", "w+"); // membuka file target dengan mode w+ bisa write + read dengan membuat file  di pointer fp
			fprintf(fp, "%d#%s#%d", totalsks, ketnamamatkul , sks );
   			fclose(fp);// file di tutup
		}
	
		if (sks <= totalsks) // agar inputan sks benar dengan tidak melebihi total sks
		{
			totalsks -= sks; // agar inputan sks sama dengan inputan total SKS
			printf("\tMasukan Total Komponen(dalam persen) 	:"); // jumlah total komponen satu matkul biasanya 100
			scanf("%d",&totalkomp); // total semua komponen satu matkul
			if (totalkomp>=0 && totalkomp<=100) // agar inputan dibatasi dan tida error
			{
				pembagitotalkmp = totalkomp; // agar nilai akhir sesuai dengan nilai komponen
				while(totalkomp != 0) // agar total komponen dengan total inputan komponen nilainya sama
				{
					komponen(); // masuk ke fungsi komponen
					if (target == 1) // agar membedakan dengan prediksiipk dengan target 0				
					{
						fp = fopen("target.txt", "a+");// membuka file target dengan mode a+ bisa write + read dengan melanjutkan file sebelumnya di pointer fp
						fprintf(fp, "#%d#%s#%d#%d", pembagitotalkmp, ketnamakomponen , kmp, nilai);
	   					fclose(fp);// file di tutup
					}		
				}
			}
			else
			{
				// pesan eror
				printf("\n		Harap Masukan Total Komponen  dengan benar \n"); 
				printf("		Jumlah Total Komponen yaitu 100 \n");
				printf("		Silahkan ulang Kembali \n");
				Sleep(3000); // untuk mendelay dengan 1000 ms atau 1 detik
				return matakuliah();
			}

		}
		else
		{
			// pesan eror
			printf("\n		Harap Masukan SKS Matakuliah dengan benar \n"); 
			printf("		Tidak melebihi total sks yang diambil \n");
			printf("		Silahkan ulang Kembali \n");
			
			return matakuliah();
		}
	}

int keluarmenu() // fungsi keluarmenu agar program dapat berjalan berulang ulang
{
	printf("\n	Tekan \n	[0] untuk Keluar \n	[1] Untuk Kembali Ke Menu Awal\n");
	printf("	Pilihan:");
	scanf("%d", &input);
	if (input >= 0 && input <=2)
	{
		switch (input)
		{
			case 0: 
				return 0; // fungsi keluar dengan berhasis
				break;
			case 1:
				system("cls"); //membersihkan layar menjadi kosong lagi
				judul();
				break;
		}
	}
	else
	{
		printf("\n		Harap Menekan Nomor Pilihan dengan benar \n"); 	
		return keluarmenu();
	}
}

int judullihattarget() // fungsi untuk mendeskripsikan featur lihat target
{
	system("cls"); // membersihkan layar menjadi kosong lagi
	printf("\n\n-------------------------------------------------------------------------------\n");
	printf("                           TARGET IPK ANDA							               \n");               
	printf("-------------------------------------------------------------------------------\n");
	
}
int judultargetipkbaru() // fungsi untuk mendeskripsikan featur buat target
{
	system("cls");// membersihkan layar menjadi kosong lagi
	printf("\n\n-------------------------------------------------------------------------------\n");
	printf("                           BUAT TARGET							               \n");               
	printf("-------------------------------------------------------------------------------\n");
	target = 1;
	prediksiipk(); // masuk ke fungsi prediksiipk
}
int judultargetipk()// fungsi untuk mendeskripsikan judul featur target ipk
{
	system("cls");// membersihkan layar menjadi kosong lagi
	printf("\n\n-------------------------------------------------------------------------------\n");
	printf("                           TARGET IPK							               \n");               
	printf("-------------------------------------------------------------------------------\n");
	menutargetipk();// masuk ke menutargetipk 
}

int menulaporannilai() // fungsi ini mendeskripsikan laporan nilai dengan adanya input dan lihat
{
	printf("                                   PILIHAN \n");      
	printf("\t[1] Input Nilai \n");
	printf("\t[2] Lihat Nilai \n");
	printf("\t[3] Kembali \n");
	printf("\t[0] Keluar \n");
	printf("\tPilihan:");
	scanf("%d", &input);
	if (input >= 0 && input <=3 )
	{
		switch (input)
		{
			case 0: 
				return 0; // fungsi keluar dengan berhasil
				break;
			case 1:
				system("cls"); //membersihkan layar menjadi kosong lagi
				judultargetipkbaru(); // memanggil fungsijudultargetipkbaru 
				break;
			case 2:
				system("cls"); //membersihkan layar menjadi kosong lagi
				judullihattarget();// memanggil fungsi judullihattarget
				lihattarget();// memanggil fungsi lihattarget
				break;
			case 3:
				system("cls"); //membersihkan layar menjadi kosong lagi
				judul();// memanggil fungsi judul
				break;
		}
	}
	else
	{
		printf("\n		Harap Menekan Nomor Pilihan dengan benar \n"); 	
		return keluarmenu();
	}
}
int menutargetipk()
{
	printf("                                   PILIHAN \n");      
	printf("\t[1] Buat Target Baru \n");
	printf("\t[2] Lihat Target \n");
	printf("\t[3] Kembali \n");
	printf("\t[0] Keluar \n");
	printf("\tPilihan:");
	scanf("%d", &input);
	if (input >= 0 && input <=3 )
	{
		switch (input)
		{
			case 0: 
				return 0; // keluar dengan berhasil
				break;
			case 1:
				system("cls"); //membersihkan layar menjadi kosong lagi
				judultargetipkbaru();
				break;
			case 2:
				system("cls"); //membersihkan layar menjadi kosong lagi
				judullihattarget();
				lihattarget();
				break;
			case 3:
				system("cls"); //membersihkan layar menjadi kosong lagi
				judul();
				break;
						
				
		}
	}
	else
	{
		printf("\n		Harap Menekan Nomor Pilihan dengan benar \n"); 	
		return keluarmenu();
	}
}
int lihattarget()
{
	// lihat target adalah untuk menampilkan data yang sudah di save
		// Matakuliah
	fp = fopen("target.txt", "r");// membuka file target dengan mode  read dengan membaca filenya di pointer fp	
	fscanf(fp, "%d#%[^#]#%d", &totalsks, &ketnamamatkul, &sks); // menscan file t
	printf("\n\n\tTotal SKS\t\t: %d \n",totalsks);
	printf("\n\t\tNama Mata Kuliah\t\t: %s ", ketnamamatkul );
	printf("\n\t\tJumlah Sks\t\t\t:%d", sks); 
	//Komponen
	fscanf(fp, "%d#%[^#]#%d#%d", &pembagitotalkmp, &ketnamakomponen, &kmp, &nilai);
	printf("\n\n\t\tMasukan Total Komponen(dalam persen)\t: %d",pembagitotalkmp);
	printf("\n\t\t\tNama Komponen\t\t\t: %s ", ketnamakomponen );
	printf("\n\t\t\tBobot Komponen (dalam persen)\t: %d", kmp); 
	printf("\n\t\t\tNilai Komponen\t\t\t: %d", nilai);
	//nilai total
	fscanf(fp, "%d#%.2f", &totalnilai2, &totalnilaiskala4);
	printf("\n\n\t\t\tTotal Nilai\t\t: %d",totalnilai2);
	printf("\n\t\t\tNilai Skla 4\t\t: %.2f ", totalnilaiskala4 );
	//ipk
	fscanf(fp, "%.2f", &ipksementara);
	printf("\n\n\t\t\tTarget IPK Sementara 	: %.2f",ipksementara);
	
	keluarmenu();// memanggil fungsi keluarmenu
}
int judulprediksiipk()
{
	system("cls"); //membersihkan layar menjadi kosong lagi
	printf("\n\n-------------------------------------------------------------------------------\n");
	printf("                           	PREDIKSI IPK							               \n");               
	printf("-------------------------------------------------------------------------------\n");
	target = 0;
	// pemberitahuan feature ke user
	printf("*-----------------------------------------------------------------------------/*\n");
	printf("\t\t\tFeature Prediksi IPK ini\n\t\tMemprediksi dan Menghitung IPK yang anda akan dapat\n");
//	printf("\t\t\tProgram akan terus berjalan sampai\n \t\tJumlah Inputan SKS sama dengan Jumlah Total SKS\n");
//	printf("\t\t\t\t\t&\n\t\tJumlah bobot komponen sama dengan nilai total komponen\n");
	printf("\tCATATAN \n");
	printf("\t[1] Total Sks Maksimum SKS = 27 \n");
	printf("\t[2] Total Komponen Maksimum SKS = 100 \n");
	printf("\t[3] Program akan terus berjalan sampai \n\t    Jumlah Inputan SKS sama dengan Jumlah Total SKS\n");
	printf("\t    Jumlah bobot komponen sama dengan nilai total komponen\n");	
	printf("*-----------------------------------------------------------------------------/*\n");
	
	prediksiipk(); // memanggil fungsi prediksiipk
}
int prediksiipk()
{
	printf("Masukan Total SKS	:");
	scanf("%d",&totalsks); // memasukan jumlah total sks yang dijalani
	if (totalsks>=0 && totalsks<=27)
	{
		while (totalsks != 0)// agar total inputan matkul sks sama dengan inputan total sks
		{
		matakuliah();
		nilaitotal(); // menuju ke fungsi nilaiakhir dimana menghasilkan ouput nilai dalam huruf
		}	
	}

	else
	{
		// pesan eror
		printf("\n		Harap Masukan Total SKS  dengan benar \n"); 
		printf("		Jumlah Maksimum Sks yaitu 27 \n");
		printf("		Silahkan ulang Kembali \n");
		Sleep(3000); // untuk mendelay dengan 1000 ms atau 1 detik
		return judulprediksiipk();
	}
	return keluarmenu(); // memanggil fungsi keluarmenu
}

void petunjuktargetipk() // fungsi petujukprediksiipk untuk mendeskripsikan bagaiamana cara/petunjuk menggunakan fitur prediksi ipk
{
	system("cls"); //membersihkan layar menjadi kosong lagi
	printf("\n\n-------------------------------------------------------------------------------\n");
	printf("                           PETUNJUK TARGET IPK							               \n");               
	printf("-------------------------------------------------------------------------------\n");
	printf("\t[1]\tPertama Buka Aplikasi Pembantu Mahasiswa \n\n");
	printf("\t[2]\tTekan 3 untuk masuk ke Laporan Nilai lalu enter\n\n");
	printf("\t[2]\tTekan 1 untuk masuk ke Target Baru atau 2 untuk ke Lihat Target \n\n");
	printf("\t[3]\tMasukan Jumlah Sks Yang diambil semeseter ini lalu enter\n\t\tContohnya 20 sks maka tekan 20 di Masukan Total SKS : 20 \n\n");
	printf("\t[4]\tMasukan Mata kuliah apa saja yang diambil lalu enter\n\t\tContohnya PTK maka tulis PTK \n\n");
	printf("\t[5]\tMasukan Jumlah sks Mata kuliah tersebut lalu enter \n\t\tContohnya PTK dengan 3 Sks maka tulis 3\n\n");
	printf("\t[6]\tMasukan Total Komponen yang ada di mata kuliah PTK lalu enter \n\t\tBiasanya 100 maka tulis 100\n\n");
	printf("\t[7]\tMasukan Komponen apa saja lalu enter contohnya UAS,UTS,KUIS \n\t\tContohnya Nama Komponen UAS\n\n");
	printf("\t[8]\tMasukan Bobot dari UAS tersebut lalu enter \n\t\tMisal bobot uas yaitu 50% maka tulis 50 \n\n");
	printf("\t[9]\tMasukan nilai komponen lalu enter \n\t\tMisal nilai uas 100 maka tulis 100 \n\n");
	printf("\t[10]\tMasukan Komponen Lain \n\n");
	printf("\t[11]\tSampai Total inputan bobot Komponen sama dengan Total Komponen\n\n");
	printf("\t[12]\tMasukan Mata Kuliah Lain\n\n");
	printf("\t[13]\tSampai Total Jumlah sks matakuliah sama dengan Total SKS\n\n");
	printf("\t[14]\tNilai Prediksi IPK keluar dengan Nilai angka dan huruf\n\n\n");
	keluarmenu();// memanggil fungsi keluarmenu
}

void petunjuklaporannilai() // fungsi petujukprediksiipk untuk mendeskripsikan bagaiamana cara/petunjuk menggunakan fitur prediksi ipk
{
	system("cls"); //membersihkan layar menjadi kosong lagi
	printf("\n\n-------------------------------------------------------------------------------\n");
	printf("                           PETUNJUK Laporan Nilai							               \n");               
	printf("-------------------------------------------------------------------------------\n");
	printf("\t[1]\tPertama Buka Aplikasi Pembantu Mahasiswa \n\n");
	printf("\t[2]\tTekan 2 untuk masuk ke Laporan Nilai lalu enter\n\n");
	printf("\t[2]\tTekan 1 untuk masuk ke Input Nilai atau 2 untuk ke Lihat nilai  \n\n");
	printf("\t[3]\tMasukan Jumlah Sks Yang diambil semeseter ini lalu enter\n\t\tContohnya 20 sks maka tekan 20 di Masukan Total SKS : 20 \n\n");
	printf("\t[4]\tMasukan Mata kuliah apa saja yang diambil lalu enter\n\t\tContohnya PTK maka tulis PTK \n\n");
	printf("\t[5]\tMasukan Jumlah sks Mata kuliah tersebut lalu enter \n\t\tContohnya PTK dengan 3 Sks maka tulis 3\n\n");
	printf("\t[6]\tMasukan Total Komponen yang ada di mata kuliah PTK lalu enter \n\t\tBiasanya 100 maka tulis 100\n\n");
	printf("\t[7]\tMasukan Komponen apa saja lalu enter contohnya UAS,UTS,KUIS \n\t\tContohnya Nama Komponen UAS\n\n");
	printf("\t[8]\tMasukan Bobot dari UAS tersebut lalu enter \n\t\tMisal bobot uas yaitu 50% maka tulis 50 \n\n");
	printf("\t[9]\tMasukan nilai komponen lalu enter \n\t\tMisal nilai uas 100 maka tulis 100 \n\n");
	printf("\t[10]\tMasukan Komponen Lain \n\n");
	printf("\t[11]\tSampai Total inputan bobot Komponen sama dengan Total Komponen\n\n");
	printf("\t[12]\tMasukan Mata Kuliah Lain\n\n");
	printf("\t[13]\tSampai Total Jumlah sks matakuliah sama dengan Total SKS\n\n");
	printf("\t[14]\tNilai Prediksi IPK keluar dengan Nilai angka dan huruf\n\n\n");
	keluarmenu();// memanggil fungsi keluarmenu
}

void petujukprediksiipk() // fungsi petujukprediksiipk untuk mendeskripsikan bagaiamana cara/petunjuk menggunakan fitur prediksi ipk
{
	system("cls"); //membersihkan layar menjadi kosong lagi
	printf("\n\n-------------------------------------------------------------------------------\n");
	printf("                           PETUNJUK PREDIKSI IPK							               \n");               
	printf("-------------------------------------------------------------------------------\n");
	printf("\t[1]\tPertama Buka Aplikasi Pembantu Mahasiswa \n\n");
	printf("\t[2]\tTekan 3 untuk masuk ke Prediksi IPK lalu enter\n\n");
	printf("\t[3]\tMasukan Jumlah Sks Yang diambil semeseter ini lalu enter\n\t\tContohnya 20 sks maka tekan 20 di Masukan Total SKS : 20 \n\n");
	printf("\t[4]\tMasukan Mata kuliah apa saja yang diambil lalu enter\n\t\tContohnya PTK maka tulis PTK \n\n");
	printf("\t[5]\tMasukan Jumlah sks Mata kuliah tersebut lalu enter \n\t\tContohnya PTK dengan 3 Sks maka tulis 3\n\n");
	printf("\t[6]\tMasukan Total Komponen yang ada di mata kuliah PTK lalu enter \n\t\tBiasanya 100 maka tulis 100\n\n");
	printf("\t[7]\tMasukan Komponen apa saja lalu enter contohnya UAS,UTS,KUIS \n\t\tContohnya Nama Komponen UAS\n\n");
	printf("\t[8]\tMasukan Bobot dari UAS tersebut lalu enter \n\t\tMisal bobot uas yaitu 50% maka tulis 50 \n\n");
	printf("\t[9]\tMasukan nilai komponen lalu enter \n\t\tMisal nilai uas 100 maka tulis 100 \n\n");
	printf("\t[10]\tMasukan Komponen Lain \n\n");
	printf("\t[11]\tSampai Total inputan bobot Komponen sama dengan Total Komponen\n\n");
	printf("\t[12]\tMasukan Mata Kuliah Lain\n\n");
	printf("\t[13]\tSampai Total Jumlah sks matakuliah sama dengan Total SKS\n\n");
	printf("\t[14]\tNilai Prediksi IPK keluar dengan Nilai angka dan huruf\n\n\n");
	keluarmenu();// memanggil fungsi keluarmenu
}

int pentunjuk()
{
	printf("                                   PILIHAN \n");      
	printf("\t[1] Petunjuk Prediksi IPK \n");
	printf("\t[2] Petunjuk Laporan IPK \n");
	printf("\t[3] Petunjuk Target IPK \n");
	printf("\t[4] Kembali \n");
	printf("\t[0] Keluar \n");
	printf("\tPilihan:");
	scanf("%d", &input);
	if (input >= 0 && input <=4 )
	{
		switch (input)
		{
			case 0: 
				return 0; // fungsi keluar dengan berhasil
				break;
			case 1:
				system("cls"); //membersihkan layar menjadi kosong lagi
				petujukprediksiipk(); // memanggil petujukprediksiipk 
				break;
			case 2:
				system("cls"); //membersihkan layar menjadi kosong lagi
				petunjuklaporannilai();// memanggil petunjuklaporannilai 
				break;
			case 3:
				system("cls"); //membersihkan layar menjadi kosong lagi
				petunjuktargetipk();// memanggil petunjuktargetipk
				break;
			case 4:
				system("cls"); //membersihkan layar menjadi kosong lagi
				judul(); //membersihkan layar menjadi kosong lagi
				break;
		}
	}
	else
	{
		printf("\n		Harap Menekan Nomor Pilihan dengan benar \n"); 	
		return keluarmenu();
	}
}


int pilihan() // pilihan menu yang akan dipilih
{
	printf("\n	Pilihan:"); // menampilkan pilihan
	scanf("%d", &input); 
	if(input>=0 && input<= 4) // switch untuk menentukan pilihan tergantung inputan
	{
		switch (input)
		{
			case 1: 
				judulprediksiipk(); // memanggil ke fungsi judulprediksiipk
				break;
			case 3: 
				judultargetipk(); // memanggil ke fungsi judultargetipk
				break;
			case 2: 
				menulaporannilai();
				break;
			case 4: 
				pentunjuk(); // memanggil ke fungsi pentunjuk
				break;
			case 0:
				return 0; //keluar dengan berhasil
				break;
		}
	}
	else 
	{
		// pesan error
		printf("Harap Masukan Nilai Pilihan dengan Benar \n");
		system("pause");// di delay
		system("cls"); //  //membersihkan layar menjadi kosong lagi
		return judul(); // kembali ke fungsi judul
	 } 
 
}

int menu() // fungsi ini untuk menampilkan menu
{
	 //pilihan menu
	printf("                                   PILIHAN \n");      
	printf("\t[1] Prediksi IPK \n");
	printf("\t[2] Laporan Nilai \n");
	printf("\t[3] Target IPK \n");
	printf("\t[4] Petujuk \n \n \n");
	printf("\t[0] Keluar \n");
	pilihan(); // memanggil ke fungsi pilihan
}
int judul() // program
{
	// judul program
	printf("\n\n-------------------------------------------------------------------------------\n");
	printf("                           PROGRAM PEMBANTU MAHASISWA 			               \n");               
	printf("-------------------------------------------------------------------------------\n");
	menu(); // memanggil ke fungsi menu
}

int main() // program main
{	
	system("color 70"); // ini buat background warna putih dengan nilai 7 dan huruf warna hitam dengan nilai 0
	judul(); // memanggil ke fungsi judul
}
