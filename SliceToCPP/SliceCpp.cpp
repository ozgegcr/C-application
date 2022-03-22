/*Dinamik programlama ile alandan �d�n verirken zamandan tasarruf etmi� oluyoruz. 
Bir kere hesaplan�p saklan�yor ve her defas�nda yeniden hesaplamak zorunda kalmadan saklanan veriyi kullan�yoruz*/

#include <iostream>

using namespace std;
#define ksize (sizeof(sozluk)/sizeof(string))


string cumle = "Erismekistedikleribirhedefiolmayanlarcalismaktanzevkalmazlar";

string sozluk[] = { "Erismek","istedikleri","iste","dikleri",
											"bir","hedefi","olmayanlar","calismaktan","calismak","tan",
										   "zevk","almazlar" };
  

int karsilastirma(string& kelime)
{
	string *ptr= &kelime;
   
    
	
	for (int i =0; i < ksize; i++)
		 
			
				
				if(sozluk[i].compare(*ptr) == 0) 
                return true;
                
                return false;
		//compare metodu d���nda kullan�lan bir y�ntem daha �rettik, bu y�ntemi kullanmamam�z�n nedeni ekrana bo� ��kt� vermesidir.	
    /*for (int i =1; i < ksize; i++)
	for(int j=0; j< ksize-1; j++ ){
			if(sozluk[j]==sozluk[j+1]){
				word=sozluk[j];
				sozluk[j]=sozluk[j+1];
			    sozluk[j+1]= word;
				return true;
				return false;

			}
	}*/	
	
}



int ayirmaIslemi(string s, int n ,string sonuc)
{
	
	
	int i;
	for ( i = 0; i <= n; i++)
	{
		//0 ile i aras� se� cumleEki ne ata
		string cumleEki;
		
		cumleEki = s.substr(0, i);
		

		// Eger cumleEki, karsilastirma icinde varsa diger if i kontrol et yoksa  tkr dene
		if (karsilastirma(cumleEki))
		{
			
			
			// i say�s� n e e�itse
		 	if (i == n)
			{
			
				//bu ogeyi onceki cumleEki ne ekle,yani yeni sonuca
				sonuc += cumleEki;
				
				
					cout << sonuc + " " +cumleEki<< endl; 
					ayirmaIslemi(s.substr(i, n), n-i,  sonuc +  " " + cumleEki);
					
					return 0;

			
			
			}
				ayirmaIslemi(s.substr(i, n), n-i,  sonuc +  " " + cumleEki);	
			
		
		}
		
		
	}
	
	return 1 ;
	
}


int main()
{
   //	string *ptr;
	

	cout << "BOLUNECEK BITISIK CUMLE: Erismekistedikleribirhedefiolmayanlarcalismaktanzevkalmazlar \n\n "; 

	cout << "BOLUNMUS HALLERI: \n\n";
		ayirmaIslemi(cumle, cumle.length(), "");
	//	karsilastirma(*ptr);

	//cout << "cumle uzunlugu: " << cumle.length();

	return 0;
}
