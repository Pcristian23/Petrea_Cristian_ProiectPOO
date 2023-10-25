#include <iostream>
#include <vector>
using namespace std;

class PartidPolitic
{
public:
	string nume;
	int AnInfiintare;
	float ProcentAlegeri;
	char* Ideologie;
	static string LocuriActivitate;
	const int id;
	PartidPolitic(string nume): id(1)
	{
		this->nume=nume;
		this->AnInfiintare = 1984;
		this->ProcentAlegeri = 19.47;
		this->Ideologie= NULL;
	}
	PartidPolitic(int AnInfiintare, float ProcentAlegeri): id(2)
	{
		this->nume="Gryffindor";
		this->AnInfiintare = AnInfiintare;
		this->ProcentAlegeri = ProcentAlegeri;
		this->Ideologie = NULL;
	}
	PartidPolitic(string nume, int AnInfiintare, float ProcentAlegeri, char* Ideologie): id(3)
	{
		this->nume=nume;
		this->AnInfiintare = AnInfiintare;
		this->ProcentAlegeri = ProcentAlegeri;
		size_t aux = strlen(Ideologie) + 1;
		this->Ideologie = new char[aux];
		strcpy_s(this->Ideologie, aux, Ideologie);
	}
	static int ComparatiePBucuresti(float ProcentAlegeri)
	{
		int p = 19014788;
		int pBucuresti = 1716961;
		int x = ProcentAlegeri * p / 100;
		if (x > pBucuresti)
			return 1;
		else
			return 0;
	}
	void afisare() {
		cout << "Partidul se numeste " << nume << " ,luand fiinta in anul " << AnInfiintare <<" are id-ul de "<<id<<" .Acesta a obtinut un respectabil scor de  " << ProcentAlegeri;
		if (Ideologie == NULL)
			cout << ".-" << endl;
		else
			cout<<" datorita unei ideologii consecvente " << Ideologie << " " << endl;
		cout << endl;
	}
	
};

string PartidPolitic::LocuriActivitate = "Romania";

class SediuPartid
{
public:
	string StilArhitectura;
	int AnConstruit;
	bool EsteMonumentIstoric;
	float SuprafataTotala;
	string* InformatiiExceptionale;
	static string StatusConstructie;
	const string Adresa;

	SediuPartid(int AnConstruit) : Adresa("Strada Izvor nr 2, Bucuresti")
	{
		this->StilArhitectura = "Neomodernism";
		this->AnConstruit = AnConstruit;
		this->SuprafataTotala = 3948.33;
		this->InformatiiExceptionale = new string[100];
	}
	SediuPartid(string StilArhitectura, int AnConstruit, float SuprafataTotala, string Adresa) : Adresa(Adresa)
	{
		this->StilArhitectura = StilArhitectura;
		this->AnConstruit = AnConstruit;
		this->SuprafataTotala = SuprafataTotala;
		this->InformatiiExceptionale = NULL;
	}
	SediuPartid(string adresa) : Adresa(adresa)
	{
		this->StilArhitectura = "Baroc";
		this->AnConstruit = 1691;
		this->SuprafataTotala = 2015.8;
		this->InformatiiExceptionale = new string[100];
	}
	static bool MonumentIstoric(int AnConstruit, string StilArhitectura)
	{
		vector<string> StilIstoric = { "baroc", "medieval", "renscentist", "bizantin", "neo - gotic", "clasicism" };
		for (const string& stil : StilIstoric)
		{ 
			if (AnConstruit < 1920 && StilArhitectura == stil)
				return true;
		}
				return false;			
	}
	void afisare() {
		cout << "Aceasta cladire este un sediu de partid, fiind construita in stil  " << StilArhitectura << " in anul " << AnConstruit << " .Cu o suprafata de " << SuprafataTotala << " metri patrati, aceasta se impune in peisagisticul urban. ";
		if (InformatiiExceptionale == NULL)
			cout << ".-" << endl;
		else
			cout <<"Totusi trebuie reamintit ca aceasta cladire s-a construit in urma unei ambitii dictatoriale nebune" << endl;
		cout << endl;
	}
};

string SediuPartid::StatusConstructie = "Construit";

class OmPolitic
{
public:
	string Nume;
	int Varsta;
	int NumarAniExperienta;
	int* AniExperienta;
	static string StatutLegal;
	const string Universitate;
	OmPolitic(int varsta, int* AniExperienta) : Universitate("Unibuc")
	{
		this->Nume = "Marian";
		this->Varsta = varsta;
		this->NumarAniExperienta = 0;
		this->AniExperienta = new int[varsta];
		for (int i = 0; i < varsta; i++)
		{
			this->AniExperienta[i] = AniExperienta[i];
			if (AniExperienta[i] > 0)
				this->NumarAniExperienta++;
		}
	}
	OmPolitic(string nume) : Universitate("SNSPA")
	{
		this->Nume = nume;
		this->Varsta = 41;
		///int Numar=1;
		this->AniExperienta = NULL;
	}
	OmPolitic() : Universitate("Danubius")
	{
		this->Nume = "Leao";
		this->Varsta = 24;
		///int Numar=1;
		this->AniExperienta = NULL;
	}
	static int VarstaMaxima(int varsta, int Numar) {
		int Vmax = 18;
		if (Numar == 0)
			Vmax = 0;
		for (int i = 0; i <= Numar; i++)
			if (varsta >= Vmax)
				Vmax = varsta;
		return Vmax;
	}
	void afisare() {
		cout << "Politicianul " << Nume << " de varsta " << Varsta << " a absolvit universitatea " << Universitate;
		if (AniExperienta == NULL)
			cout << ".-" << endl;
		else
		{
			cout << " acumuland un numar impresionant de " << NumarAniExperienta << " ani de experienta, deoarece a intrat in politica inca de cand a devenit " << StatutLegal << " " << endl;
		}
		/*else
		{
			cout << " acumuland un numar impresionant de ";
			for (int i = 0; i < Varsta; i++) {
				cout << AniExperienta[i];
				if (i < Varsta - 1) {
					cout << ", ";
				}
			}
			cout << ", deoarece a intrat in politica inca de cand a devenit " << StatutLegal << " " << endl;

	}*/
	
};
};

string OmPolitic::StatutLegal = "Major";

int main()
{
	PartidPolitic partid1("Csf,Ncsf");
	PartidPolitic partid2(1988,17.76);
	char ideologie[] = "care combina conservatorismul economic cu promisiunea unui stat mai putin angrenat in viata de zi cu zi a cetatenilor";
	PartidPolitic partid3("PLibertarian", 2011, 12.04, ideologie);
	partid1.afisare();
	partid2.afisare();
	partid3.afisare();

	SediuPartid sediu1(1927);
	SediuPartid sediu2("Neo-Gotic", 1841, 1899, "Soseaua Bucuresti-Ploiesti, nr 2B, Bucuresti");
	SediuPartid sediu3("Piata Unirii 1, Bucuresti");
	sediu1.afisare();
	sediu2.afisare();
	sediu3.afisare();


	int aniexperienta[] = { 2017,2018,2019,2020,2021,2022, 2023, 2024 };
	OmPolitic om1(37, aniexperienta);
	OmPolitic om2("Bosie");
	OmPolitic om3;
	om1.afisare();
	om2.afisare();
	om3.afisare();

}




 