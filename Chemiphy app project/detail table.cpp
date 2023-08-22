#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<sstream>
#include <conio.h>
#include <Windows.h>
#include<fstream>
#include <cstdlib>
//#include "library.h"
using namespace std;
class Filing;
class element;
void show_table(element e[]);

void color(int color)	//to make changing colours easier
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void gotoxy(int x, int y)	//for formatting text
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
class Periodic_Table{
	public:
		virtual void display_periodic_table()=0;  //pure virtual function 
};
class element:public Periodic_Table{ // inheritance
	string s,name;
	int group;
	int atomic_no;
	int period;
	double mass_no,melting_point,boiling_point,density;
	int discovery_year;
	double ionization_energy;
	
	public:
		element(){} //non para constructor
		element(string s,int  group,int period ,int atomic_no,float mass_no){
			this->s=s;
			this->group=group;
			this->period=period;
			this->atomic_no=atomic_no;
			this->mass_no=mass_no;
		}
		void set_Name(string s){
			this->name=s;
		}
		string get_Name(){
			return name;
		}
		void set_mp(double mp){
			melting_point= mp;
		}
		double get_mp(){
			return melting_point;
		}
		void set_bp(double bp){
			boiling_point=bp;
		}

		double get_bp(){
			return boiling_point;
		}
		void set_density(double dens){
			density=dens;
		}
		double get_density(){
			return density;
		}
		void set_discovery(int d){
			discovery_year=d;
		}
		int get_discovery(){
			return discovery_year;
		}
		void set_ie(double ip){
			ionization_energy=ip;
		}
		double get_ie(){
			return ionization_energy;
		}
		void display_periodic_table(){
			cout<<setw(4)<<left<<s;	
		}
	string get_name()
	{
		return s;
	}
	int get_group(){
		return group;
	}
	int get_atomic(){
		return atomic_no;
	}
	float get_mass_no(){
		return mass_no;
	}
	void set_name(string name){
		this->s=name;
	}
	void set_mass(float mass){
		mass_no=mass;
	}
	void set_atomicno(int atomicno){
		atomic_no=atomicno;
	}
	void set_group(int group){
		this->group=group;
	}
	int get_period(){
		return period;
	}
	void set_period(int p){
		period = p;
	}
	static void show(element e[]);
		
};

class specialgroup:public element{
	string specialname;
	public:
		void set_sp_name(element e);
		string getspecialname(){
			return specialname;
		}
		void display();
		static void search(string sp_name,specialgroup obj[]);
		static void createfile(string sp_name,specialgroup obj[]);
};
class ElementDetail:public specialgroup{
	protected:
	string ElectronicConfiguration;
	int neutrons;
	float density;
	public:
		ElementDetail(){}
		void operator --(){
			neutrons  = (int)get_mass_no() - get_atomic();
		}
		void Electronic_configuration();
		
		int MAX(string subshell);
		void SetValues(element e);
		void display();
		int get_neutron(){
			return neutrons;
		}
		string getElectronicConfiguration(){
			return ElectronicConfiguration;
		}
	static void search(Filing e[]);	//overloading of search function
	static void search(Filing e[],string name,int);
	static void search(Filing e[],string symbol);//overriden from speacial group search funtion
	static void search(Filing e[],int atomic);

};

class Filing:public ElementDetail{
	public:
	static void StoreData(Filing f[118]);
	static void AlkaliMetalsfile(Filing f[118]);
	static void AlkalineEarthMetalsFile(Filing f[118]);
	static void HalogensFile(Filing f[118]);
	static void NobleGasesFile(Filing f[118]);
	static void sblockfile(Filing f[118]);
	static void pblockfile(Filing f[118]);
	static void dblockfile(Filing f[118]);
	static void fblockfile(Filing f[118]);
	static void CoinageMetalsFile(Filing f[118]);
	static void AtomDetailFile(Filing f[118]);
};
void Filing::StoreData(Filing f[118]){
	string option;
	system("cls");
				int Set1[] = {11,7,7,7,7,7,7,7,7}; // DEFAULT COLORS
	    int counter1 = 1;
	    char key1;
	
	    for(int i=0;;)
	    {
			gotoxy(0,3);
			color(11);
			cout << "SELECT A GROUP:";
	
	        gotoxy(0,5);
	        color(Set1[0]);
	        cout<<"Alkali metals";
	
	        gotoxy(0,7);
	        color(Set1[1]);
	        cout<<"Alkali earth metals";
	
	        gotoxy(0,9);
	        color(Set1[2]);
	        cout<<"halogens";
	
	        gotoxy(0,11);
	        color(Set1[3]);
	        cout<<"Noble gases";
	
	        gotoxy(0,13);
	        color(Set1[4]);
	        cout<<"S block";
	        
	        gotoxy(0,15);
	        color(Set1[5]);
	        cout<<"P block";
			
			gotoxy(0,17);
	        color(Set1[6]);
	        cout<<"F block";
	        
	        gotoxy(0,19);
	        color(Set1[7]);
	        cout<<"Coinage metals";
	        
	        gotoxy(0,21);
	        color(Set1[8]);
	        cout<<"Detail of a particular atom";
	        
	        key1 = _getch();
	
	        if(key1 == 72 && (counter1 >=2 && counter1 <= 9))
	        {
	            counter1--;
	        }
	        if(key1 == 80 && (counter1 >=1 && counter1 <= 8))
	        {
	            counter1++;
	        }
	        if(key1 == '\r')//carriage return
	        {
	            if(counter1 == 1)
	            {
	            	system("cls");
	                AlkaliMetalsfile(f);
	            }
	            if(counter1 == 2)
	            {
	            	system("cls");
	                AlkalineEarthMetalsFile(f);
	            }
	            if(counter1 == 3)
	            {
	            	system("cls");
	            	HalogensFile(f);
	            }
	            if(counter1 == 4)
	            {
	            	system("cls");
	                NobleGasesFile(f);
	            }
	            if(counter1 == 5)
	            {
	            	system("cls");
	               	sblockfile( f);
	            }
	             if(counter1 == 6)
	            {
	            	system("cls");
	               	pblockfile(f);
	            }
	             if(counter1 == 7)
	            {
	            	system("cls");
	               	fblockfile(f);
	            }
	             if(counter1 == 8)
	            {
	            	system("cls");
	               	CoinageMetalsFile(f);
	            }
	             if(counter1 == 9)
	            {
	            	system("cls");
	               	AtomDetailFile(f);
	            }	
				cout<<"\nFile created!!!\n\n"<<endl;
//				PlaySound("./Sounds/file created.wav", NULL, SND_FILENAME | SND_SYNC);		
		        Sleep(1000);
		        break;
	        }
	
	        Set1[0] = 7;
	        Set1[1] = 7;
	        Set1[2] = 7;
	        Set1[3] = 7;
	        Set1[4] = 7;
	        Set1[5] = 7;
	        Set1[6] = 7;
			Set1[7] = 7;
			Set1[8] = 7;
			Set1[9] = 7;
	        if(counter1 == 1)
	        {
	            Set1[0] = 11;
	        }
	        if(counter1 == 2)
	        {
	            Set1[1] = 11;
	        }
	        if(counter1 == 3)
	        {
	            Set1[2] = 11;
	        }
	        if(counter1 == 4)
	        {
	            Set1[3] = 11;
	        }
	        if(counter1 == 5)
	        {
	            Set1[4] = 11;
	        }
	        if(counter1 == 6)
	        {
	            Set1[5] = 11;
	        }
	        if(counter1 == 7)
	        {
	            Set1[6] = 11;
	        }
	        if(counter1 == 8)
	        {
	            Set1[7] = 11;
	        }
	        if(counter1 == 9)
	        {
	            Set1[8] = 11;
	        }
	
	    }
	    
	}
void Filing::AlkaliMetalsfile(Filing f[118])
{
	fstream alkalifile("Alkalifile.txt",ios::out);
	alkalifile<<"List of Alkali Metals"<<endl;
	for(int i=0;i<118;i++)
	{
		if(f[i].getspecialname()=="Alkali metals")
		{
			alkalifile<<f[i].get_name()<<endl;
		}
	}
	alkalifile.close();
	
}
void Filing::AlkalineEarthMetalsFile(Filing f[118]){
	fstream alkalinefile("AlkalineEarthmetals.txt",ios::out);
	alkalinefile<<"List of Alkaline Earth metals:"<<endl;
	for(int i=0;i<118;i++)
	{
		if(f[i].getspecialname()=="Alkaline Earth metals")
		alkalinefile<<f[i].get_name();
	}
	alkalinefile.close();
}
void Filing::HalogensFile(Filing f[118])
{
		fstream Halogenfile("Halogens.txt",ios::out);
			Halogenfile<<"List of Halogens:"<<endl;
	for(int i=0;i<118;i++)
	{
		if(f[i].getspecialname()=="Halogens")
		Halogenfile<<f[i].get_name()<<endl;
	}
	Halogenfile.close();

}
void Filing::NobleGasesFile(Filing f[118])
{
		fstream Noblegas("Noblegases.txt",ios::out);
			Noblegas<<"List of Noblegases:"<<endl;
	for(int i=0;i<118;i++)
	{
		if(f[i].getspecialname()=="Noble gases")
		Noblegas<<f[i].get_name()<<endl;
	}
	Noblegas.close();

}
void Filing::CoinageMetalsFile(Filing f[118])
{
		fstream coinage("coinage metals.txt",ios::out);
			coinage<<"List of Coinage metals:"<<endl;
	for(int i=0;i<118;i++)
	{
		if(f[i].getspecialname()=="Coinage metals")
		coinage<<f[i].get_name()<<endl;
	}
	coinage.close();
}
void Filing::sblockfile(Filing f[118])
{
	fstream sblock("sblock.txt",ios::out);
	sblock<<"List of sblock elements"<<endl;
	for(int i=0;i<118;i++)
	{
		if(f[i].get_group()==1 || f[i].get_group()==2)
		sblock<<f[i].get_name()<<endl;
	}
	sblock.close();
}
void Filing::pblockfile(Filing f[118]){
		fstream pblock("pblock.txt",ios::out);
	pblock<<"List of pblock elements"<<endl;
	for(int i=0;i<118;i++)
	{
		if(f[i].get_group()>=13 && f[i].get_group()<=18)
		pblock<<f[i].get_name()<<endl;
	}
	pblock.close();
}
void Filing::dblockfile(Filing f[118])
{
	fstream dblock("dblock.txt",ios::out);
	dblock<<"List of dblock elements"<<endl;
	for(int i=0;i<118;i++)
	{
		if(f[i].get_group()>=3 && f[i].get_group()<=12 && !((f[i].get_atomic()>=57 && f[i].get_atomic()<=70)||(f[i].get_atomic()>=89 && f[i].get_atomic()<=102)))
		dblock<<f[i].get_name()<<endl;
	}
	dblock.close();
}
void Filing::fblockfile(Filing f[118]){
		fstream fblock("fblock.txt",ios::out);
	fblock<<"List of fblock elements"<<endl;
	for(int i=0;i<118;i++)
	{
		if((f[i].get_atomic()>=57 && f[i].get_atomic()<=70)||(f[i].get_atomic()>=89 && f[i].get_atomic()<=102))
		fblock<<f[i].get_name()<<endl;
	}
	fblock.close();
}
void Filing::AtomDetailFile(Filing f[118]){
	string symbol;
	cout<<"Enter the symbol of element:";
	cin>>symbol;
	fstream file("Atom Detail.txt",ios::out|ios::app);
	for(int i=0;i<118;i++)
	{
		if(f[i].get_name()==symbol)
		{
			file<<"Name:"<<f[i].get_Name()<<endl
				<<"Symbol"<<f[i].get_name()<<endl
				<<"Group:"<<f[i].get_group()<<endl
				<<"Period:"<<f[i].get_period()<<endl
				<<"Atomic Number"<<f[i].get_atomic()<<endl
				<<"Mas number"<<f[i].get_mass_no()<<endl
				<<"Neutrons"<<f[i].get_neutron()<<endl
				<<"Period: "<<f[i].get_period()<<endl
				<<"Discovery year:"<<f[i].get_discovery()<<endl
				<<"Density:"<<f[i].get_density()<<endl
				<<"Ionization energy:"<<f[i].get_ie()<<endl
				<<"Electronic configuration"<<f[i].getElectronicConfiguration()<<endl;
		}
	}
}
void ElementDetail::search(Filing e[],string name,int l)
{
	for(int i=0;i<118;i++)
	{
		if(e[i].get_Name()==name)
		{
			e[i].display();
			break;
		}
		else if(e[i].get_Name()!=name && i==117){
		cout<<"No such element found!!"<<endl;
//		PlaySound("./Sounds/error.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		
	}
}
void ElementDetail::search(Filing e[],string symbol){
		for(int i=0;i<118;i++)
	{
		if(e[i].get_name()==symbol)
		{
			e[i].display();
			break;
		}
		else if(e[i].get_name()!=symbol && i==117){
		cout<<"No such element found!!"<<endl;
//		PlaySound("./Sounds/error.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
	}
}
void ElementDetail::search(Filing e[],int a){
			for(int i=0;i<118;i++)
	{
		if(e[i].get_atomic()==a)
		{
			e[i].display();
			break;
		}
		else if(e[i].get_atomic()!=a && i==117)
		{cout<<"No such element found!!"<<endl;
//		PlaySound("./Sounds/error.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
	}
}
void ElementDetail::search(Filing e[])
{
	char opt,input;
	string name,symbol;
	int atomicno;
	cout<<"\nSearch by:";
	int Set[] = {11,7,7,7,7,7,7};
	int counter = 1;
    char key;

    for(int i=0;;)
    {


        gotoxy(0,3);
        color(Set[0]);
        cout<<"1. Name";

        gotoxy(0,5);
        color(Set[1]);
        cout<<"2. Symbol";

        gotoxy(0,7);
        color(Set[2]);
        cout<<"3. Atomic number";

        key = _getch();
		
        if(key == 72 && (counter >=2 && counter <= 3))	//up arrow
        {
            counter--;
        }
        if(key == 80 && (counter >=1 && counter <= 2))	//down arrow
        {
            counter++;
        }
        if(key == '\r')//carriage return
        {
//        	PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
            if(counter == 1)
            {
            	system("cls");
            	color(11);
                cout<<"\nEnter name:";
                color(7);
				cin>>name;
				color(11);
//				PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
				ElementDetail::search(e,name,1);
				break;
            }
            if(counter == 2)
            {
            	system("cls");
                color(11);
				cout<<"\nEnter the symbol:";
				color(7);
				cin>>symbol;
				color(11);
//				PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
				ElementDetail::search(e,symbol);
				break;
            }
            if(counter == 3)
            {
            	system("cls");
            	color(11);
                cout<<"\nEnter the atomic number:";
                color(7);
				cin>>atomicno;
				color(11);
//				PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
				ElementDetail::search(e,atomicno);
				break;
            }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        if(counter == 1)
        {
            Set[0] = 11;
        }
        if(counter == 2)
        {
            Set[1] = 11;
        }
        if(counter == 3)
        {
            Set[2] = 11;
        }

    }
}
void ElementDetail:: Electronic_configuration(){
			string subshell[]={"1s","2s","2p","3s","3p","4s","3d","4p","5s","4d","5p","6s",
								"4f","5d","6p","7s","5f","6d","7p"};
			string s;
			stringstream ss[25];
			int protons=get_atomic(),maxocc=2;
			for(int i=0;protons!=0;i++)
			{
				maxocc=MAX(subshell[i]);
				if(protons>maxocc)
				{
					ss[i]<<maxocc;
					ElectronicConfiguration+=subshell[i]+ss[i].str()+" ";
					protons=
					protons-maxocc;
				}
				else if(maxocc>=protons)
				{
					ss[i]<<protons;
					ElectronicConfiguration+=subshell[i]+ss[i].str();
					protons=protons-maxocc;
					break;
				}
			}
			
		}
int ElementDetail::MAX(string subshell){
			if(subshell[1]=='s')
			return 2;
			else if(subshell[1]=='p')
			return 6;
			else if(subshell[1]=='d')
			return 10;
			else if(subshell[1]=='f')
			return 14;
			else 
			return 0;
}
void ElementDetail::SetValues(element e){
	set_name(e.get_name());
	set_mass(e.get_mass_no());
	set_group(e.get_group());
	set_atomicno(e.get_atomic());
	set_period(e.get_period());
	set_sp_name(e);
	set_Name(e.get_Name());
	set_mp(e.get_mp());
	set_bp(e.get_bp());
	set_density(e.get_density());
	set_discovery(e.get_discovery());
	set_ie(e.get_ie());
	Electronic_configuration();
}
void ElementDetail::display(){
	cout<<"\nName:"<<get_Name()<<endl
		<<"Symbol: "<<get_name()<<endl
		<<"Atmoic number: "<<get_atomic()<<endl
		<<"Nutron number: "<<get_neutron()<<endl
		<<"Mass number:"<<get_mass_no()<<endl
		<<"Group: "<<get_group()<<endl
		<<"Period: "<<get_period()<<endl
		<<"Discovery year:"<<get_discovery()<<endl
		<<"Density:"<<get_density()<<endl
		<<"Ionization energy:"<<get_ie()<<endl
		<<"Electronic-Configuration: "<<getElectronicConfiguration()<<endl << endl;
}
class Test:public element{
	string name;
	int points;
	public:
		Test(){
			name="";
			points=0;
		}
		void operator ++(int){
			points+=5;
		}
		void operator --(int){
			points--;
		}
		static show(element e[],int random);
		void set_name(string s){
			name=s;
		}
		void scoreboard(){
			fstream file("scoreboard.txt",ios::out|ios::app);
			file<<"Name:"<<name<<endl
			<<"Points:"<<points<<endl
			<<"------------------------------------------------------"<<endl;
		}
		int get_points(){
			return points;
		}
		string get_name(){
			return name;
		}
};
void quiz(element e[]){
	HANDLE q=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(q, 11);
	int random,index,at;
	float mass;
	Test person;
	string name;
	cin.ignore();
	cout<<"Enter your name : ";
	getline(cin,name);
	person.set_name(name);
	for(int k=0;k<3;k++)
	{
	for(;;)
	{
		random=rand()%100;
		if(random>=0 && random <=118)
		break;
	}
		for(int i=0;i<118;i++)
	{
		if(random==e[i].get_atomic())
		{
			index=i;
			break;
		}
	}
	person.show(e,random);
	HANDLE q=GetStdHandle(STD_OUTPUT_HANDLE);   //used for changing colours 
	SetConsoleTextAttribute(q, 11);
	cout<<endl<<"Q"<<k+1<<")"<<"Enter the symbol missing:";
	string s;
	cin>>s;
	if(s==e[index].get_name())
	{
//		PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
		cout<<"correct!!"<<endl;
		person++;
	}
	else
	{
//		PlaySound("./Sounds/error.wav", NULL, SND_FILENAME | SND_ASYNC);
		cout<<"wrong!!"<<endl;
		person--;
	}
	Sleep(700);
	system("cls");
}
	for(;;)
	{
		random=rand()%100;
		if(random>=0 && random <=118)
		break;
	}
		HANDLE l=GetStdHandle(STD_OUTPUT_HANDLE);   //used for changing colours 
	SetConsoleTextAttribute(l, 11);
	cout << "Q4)Enter the atmoic number of symbol "<<e[random+1].get_name();
	cin>>at;
	if(at==e[random+1].get_atomic())
	{
//		PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
		cout<<"correct!!"<<endl;
		person++;
	}
	else
	{
//		PlaySound("./Sounds/error.wav", NULL, SND_FILENAME | SND_ASYNC);
		cout<<"wrong!!"<<endl;
		person--;
	}
		for(;;)
	{
		random=rand()%100;
		if(random>0 && random <=118)
		break;
	}
		HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);   //used for changing colours 
	SetConsoleTextAttribute(k, 11);
	cout<<"Q5)Enter the mass number of "<<e[random].get_name()<<endl;
	cin>>mass;
		if(mass==e[random].get_mass_no())
	{
//		PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
		cout<<"correct!!"<<endl;
		person++;
	}
	else
	{
//		PlaySound("./Sounds/error.wav", NULL, SND_FILENAME | SND_ASYNC);
		cout<<"wrong!!"<<endl;
		person--;
	}
	cout<<"Name:"<<person.get_name()<<endl
	<<"points:"<<person.get_points()<<endl;
	
	person.scoreboard(); //storing record
	
	
}
void element::show(element e[]){
	HANDLE q=GetStdHandle(STD_OUTPUT_HANDLE);   //used for changing colours 
	int d=0;
	for(int k=1;k<=18;k++)
	{
		SetConsoleTextAttribute(q, 8);		//syntax for changing colours (second argument i.e 8 is colour)
		cout<<setw(4)<<left<<k;
		SetConsoleTextAttribute(q, 7);
	}
	cout<<endl;
	for(int j=0;j<118;j++){
		if(e[j].group==1 || e[j].group==2){	
			SetConsoleTextAttribute(q, 12);
		}
		else if(e[j].group>=3 && e[j].group<=12){	
			SetConsoleTextAttribute(q, 9);
		}
		else if(e[j].group>=13 && e[j].group<=18){	
			SetConsoleTextAttribute(q, 6);
		}
		if(j>55 && j<71 || j>=88 && j<=102)
		{
			if(d==0)
			{
				cout<<setw(4)<<left<<"||";
			}
			d++;
			continue;
		}
		d=0;
		e[j].display_periodic_table();
		if(j==1 || j==9 || j==17 || j==35 || j==53 || j==85 || j==117)
		cout<<endl;
		if(j==0)
		{
			for(int k=0;k<16;k++)
			{
			cout<<setw(4)<<left<<" ";
			}	
		}
		else if(j==3 || j==11)
		{
			for(int k=0;k<10;k++)
			cout<<setw(4)<<left<<" ";
		}
	}
	
	cout<<endl<<setw(12)<<left<<" ";
	for(int k=56;k<71;k++)
	{
		SetConsoleTextAttribute(q, 2);
		e[k].display_periodic_table();
	}
	cout<<endl;
	cout<<setw(12)<<left<<" ";
	for(int k=88;k<103;k++)
	{
		e[k].display_periodic_table();
	}
	SetConsoleTextAttribute(q, 7);
}

void specialgroup::set_sp_name(element e)
{
	if(e.get_group()==1)
	specialname="Alkali metals";
	else if(e.get_group()==2)
	specialname="Alkaline Earth metals";
	else if(e.get_group()==17)
	specialname="Halogens";
	else if(e.get_group()==18)
	specialname="Noble gases";
	else if(e.get_name()=="Cu"||e.get_name()=="Ag"||e.get_name()=="Au"||e.get_name()=="Pd"||e.get_name()=="Pt")
	specialname="Coinage metals";
	else if(e.get_group()>=3 && e.get_group()<=12)
	specialname="Transition metals";
	set_name(e.get_name());
	set_mass(e.get_mass_no());
	set_group(e.get_group());
	set_atomicno(e.get_atomic());
	
}
void specialgroup::search(string sp_name,specialgroup obj[])
{
	fflush(stdin);
	for(int i=0;i<118;i++)
	{
		if(sp_name==obj[i].specialname)
		obj[i].display();
		else if(sp_name=="s block")
		{
			if(obj[i].get_group()==1 || obj[i].get_group()==2)
			obj[i].display();
		}
		else if(sp_name=="p block")
		{
			if(obj[i].get_group()>=13 && obj[i].get_group()<=18)
			obj[i].display();
		}
		else if(sp_name=="f block" || sp_name=="inner transition")
		{
			if((obj[i].get_atomic()>=57 && obj[i].get_atomic()<=70)||(obj[i].get_atomic()>=89 && obj[i].get_atomic()<=102))
			obj[i].display();
		}
		
		else if(sp_name=="d block" || sp_name=="outer transition")
		{
			if(obj[i].get_group()>=3 && obj[i].get_group()<=12 && !((obj[i].get_atomic()>=57 && obj[i].get_atomic()<=70)||(obj[i].get_atomic()>=89 && obj[i].get_atomic()<=102)))
			obj[i].display();
		}
		else if(sp_name=="radioactive")
		{
			if(obj[i].get_atomic()>82)
			obj[i].display();
		}
		else if(sp_name=="lanthanides")
		{
			if(obj[i].get_atomic()>=57 && obj[i].get_atomic()<=70)
			obj[i].display();
		}
		else if(sp_name=="Actinides")
		{
			if(obj[i].get_atomic()>=89 && obj[i].get_atomic()<=102)
			obj[i].display();
		}
	}
}
void specialgroup::display(){
	cout<<get_name()<<endl;
}
void specialgroup::createfile(string sp_name,specialgroup obj[]){
	fstream file("specialgroup.txt",ios::out);
	for(int i=0;i<118;i++){
		if(sp_name==obj[i].specialname)
		{
			file<<obj[i].get_name()<<endl;
		}
	}
	file.close();
}
Test::show(element e[],int random){
	HANDLE q=GetStdHandle(STD_OUTPUT_HANDLE);   //used for changing colours 
	int d=0;
	for(int k=1;k<=18;k++)
	{
		SetConsoleTextAttribute(q, 8);		//syntax for changing colours (second argument i.e 8 is colour)
		cout<<setw(4)<<left<<k;
		SetConsoleTextAttribute(q, 7);
	}
	cout<<endl;
	for(int j=0;j<118;j++){
		if(e[j].get_group()==1 || e[j].get_group()==2){	
			SetConsoleTextAttribute(q, 12);
		}
		else if(e[j].get_group() && e[j].get_group()<=12){	
			SetConsoleTextAttribute(q, 9);
		}
		else if(e[j].get_group()>=13 && e[j].get_group()<=18){	
			SetConsoleTextAttribute(q, 6);
		}
		if(j>55 && j<71 || j>=88 && j<=102)
		{
			if(d==0)
			{
				cout<<setw(4)<<left<<"||";
			}
			d++;
			continue;
		}
		d=0;
		if(random!=e[j].get_atomic())
		e[j].display_periodic_table();
		else 
		{
			SetConsoleTextAttribute(q, 11);
			cout<<setw(4)<<left<<"??";
		}
		if(j==1 || j==9 || j==17 || j==35 || j==53 || j==85 || j==117)
		cout<<endl;
		if(j==0)
		{
			for(int k=0;k<16;k++)
			{
			cout<<setw(4)<<left<<" ";
			}	
		}
		else if(j==3 || j==11)
		{
			for(int k=0;k<10;k++)
			cout<<setw(4)<<left<<" ";
		}
	}
	
	cout<<endl<<setw(12)<<left<<" ";
	for(int k=56;k<71;k++)
	{
		SetConsoleTextAttribute(q, 2);
		if(random!=e[k].get_atomic())
		e[k].display_periodic_table();
		else 
		{
			SetConsoleTextAttribute(q, 11);
			cout<<setw(4)<<left<<"??";
		}
	}
	cout<<endl;
	cout<<setw(12)<<left<<" ";
	for(int k=88;k<103;k++)
	{
		if(random!=e[k].get_atomic())
		e[k].display_periodic_table();
		else 
		{
			SetConsoleTextAttribute(q, 11);
			cout<<setw(4)<<left<<"??";
		}
	}
	SetConsoleTextAttribute(q, 7);
	return 0;
}
//template functions
template <class x>
void Electronic_Configuration(x &a){
	HANDLE q=GetStdHandle(STD_OUTPUT_HANDLE);   //used for changing colours 
	SetConsoleTextAttribute(q, 11);
	int atomic,check;
	cout<<"Enter the atomic number of element:";
	check = scanf("%d",&atomic);
//	PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
	try{
	if(atomic>0 && atomic<118 && check == 1)
	std::cout<<"Electronic Configuration:"<<a[atomic-1].ElementDetail::getElectronicConfiguration()<<endl;
	else throw 1;
}
	catch(int a)
	{cout<<"No such element found!!!"<<endl;
//	PlaySound("./Sounds/error.wav", NULL, SND_FILENAME | SND_ASYNC);}
}
}

int main()
{	
	HANDLE q=GetStdHandle(STD_OUTPUT_HANDLE);
	element e[118];
	char input;
	string symbol,sp_name,name;
	int group,period,atomic,year;
	double mass,mp,bp,density,ie;
	bool flag=0;
	fstream file("data.txt");
	for(int i=0;i<118;i++)
	{
		file>>period>>group>>atomic>>symbol>>name>>mass>>mp>>bp>>density>>year>>ie;
		e[i].set_name(symbol);
		e[i].set_mass(mass);
		e[i].set_atomicno(atomic);
		e[i].set_group(group);
		e[i].set_period(period);
		e[i].set_mp(mp);
		e[i].set_bp(bp);
		e[i].set_Name(name);
		e[i].set_density(density);
		e[i].set_discovery(year);
		e[i].set_ie(ie);
		
	}
	specialgroup sp[118];		//Making special groups like alkali metals, alkaline metals etc...
	for(int i=0;i<118;i++)
	{
		sp[i].set_sp_name(e[i]);
	}
	//Making files of special groups...
	
	Filing elementdetail[118];
	for(int i=0;i<118;i++){
		elementdetail[i].SetValues(e[i]);
		--elementdetail[i];//operator overloading for calculating neutrons
	}
//		PlaySound("./Sounds/intro.wav", NULL, SND_FILENAME | SND_ASYNC);
		//Sleep(2200);
	int Set[] = {11,7,7,7,7,7,7}; // DEFAULT COLORS
    int counter = 1;
    char key;

    for(int i=0;;)
    {
		gotoxy(30,0);
		color(11);
		cout << "====================";
		color(7);
		cout << "Welcome to";
		color(11);
		cout << "====================\n";
		gotoxy(30,1);
		cout << "==============";
		color(7);
		cout << "Modern Periodic Table";
		color(11);
		cout << "===============\n\n";

        gotoxy(40,8);
        color(Set[0]);
        cout<<" Display periodic Table";

        gotoxy(40,10);
        color(Set[1]);
        cout<<" Learn about an element";

        gotoxy(40,12);
        color(Set[2]);
        cout<<" Display special groups of elements";

        gotoxy(40,14);
        color(Set[3]);
        cout<<" Take a Quiz";

        gotoxy(40,16);
        color(Set[4]);
        cout<<" Make a file of a special group";
        
        gotoxy(40,18);
        color(Set[5]);
        cout<<" Electronic configuration";
        
        gotoxy(40,20);
        color(Set[6]);
        cout<<" Quit\n";

        key = _getch();

        if(key == 72 && (counter >=2 && counter <= 7))//up arrow
        {
            counter--;
        }
        else if(key == 80 && (counter >=1 && counter <= 6))//down arrow
        {
            counter++;
        }
        else if(key == 72 && (counter == 1))
        {
            counter=7;
        }
        else if(key == 80 && (counter == 7))//down arrow
        {
            counter=1;
        }
        if(key == '\r')//carriage return
        {
//        	PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
            if(counter == 1)
            {
                system("cls");
				element::show(e);	//displaying the periodic table
				cout << endl;
            }
            if(counter == 2)
            {
                system("cls");
			SetConsoleTextAttribute(q, 11);
			ElementDetail::search(elementdetail);
            }
            if(counter == 3)
            {
               
				system("cls");
				int Set1[] = {11,7,7,7,7,7,7,7,7}; // DEFAULT COLORS
	    int counter1 = 1;
	    char key1;
	
	    for(int i=0;;)
	    {
			gotoxy(0,3);
			color(11);
			cout << "SELECT A GROUP:";
	
	        gotoxy(0,5);
	        color(Set1[0]);
	        cout<<"Alkali metals";
	
	        gotoxy(0,7);
	        color(Set1[1]);
	        cout<<"Alkali earth metals";
	
	        gotoxy(0,9);
	        color(Set1[2]);
	        cout<<"halogens";
	
	        gotoxy(0,11);
	        color(Set1[3]);
	        cout<<"Noble gases";
	
	        gotoxy(0,13);
	        color(Set1[4]);
	        cout<<"S block";
	        
	        gotoxy(0,15);
	        color(Set1[5]);
	        cout<<"P block";
			
			gotoxy(0,17);
	        color(Set1[6]);
	        cout<<"F block";
	        
	        gotoxy(0,19);
	        color(Set1[7]);
	        cout<<"Coinage metals";
	        
	        gotoxy(0,21);
	        color(Set1[8]);
	        cout<<"Transition metals";
	        
	        key1 = _getch();
	
	        if(key1 == 72 && (counter1 >=2 && counter1 <= 9))
	        {
	            counter1--;
	        }
	        if(key1 == 80 && (counter1 >=1 && counter1 <= 8))
	        {
	            counter1++;
	        }
	        if(key1 == '\r')//carriage return
	        {
//	        	PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
	            if(counter1 == 1)
	            {
	            	system("cls");
	                // if enter is click and highlight is on 1 the program will run the code here
	               specialgroup::search("Alkali metals",sp);
	               break;
	            }
	            if(counter1 == 2)
	            {
	            	system("cls");
	                specialgroup::search("Alkaline Earth metals",sp);
	                 break;
	            }
	            if(counter1 == 3)
	            {
	            	system("cls");
	            	specialgroup::search("Halogens",sp);
	            	 break;
	            }
	            if(counter1 == 4)
	            {
	            	system("cls");
	               specialgroup::search("Noble gases",sp);
	                break;
	            }
	            if(counter1 == 5)
	            {
	            	system("cls");
	               	specialgroup::search("s block",sp);
	               	 break;
	            }
	             if(counter1 == 6)
	            {
	            	system("cls");
	               	specialgroup::search("p block",sp);
	               	 break;
	            }
	             if(counter1 == 7)
	            {
	            	system("cls");
	               	specialgroup::search("f block",sp);
	               	 break;
	            }
	             if(counter1 == 8)
	            {
	            	system("cls");
	               	specialgroup::search("Coinage metals",sp);
	               	 break;
	            }
	             if(counter1 == 9)
	            {
	            	system("cls");
	               	specialgroup::search("Transition metals",sp);
	               	 break;
	            }				
//		      PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);      
	        }
	
	        Set1[0] = 7;
	        Set1[1] = 7;
	        Set1[2] = 7;
	        Set1[3] = 7;
	        Set1[4] = 7;
	        Set1[5] = 7;
	        Set1[6] = 7;
			Set1[7] = 7;
			Set1[8] = 7;
			Set1[9] = 7;
	        if(counter1 == 1)
	        {
	            Set1[0] = 11;
	        }
	        if(counter1 == 2)
	        {
	            Set1[1] = 11;
	        }
	        if(counter1 == 3)
	        {
	            Set1[2] = 11;
	        }
	        if(counter1 == 4)
	        {
	            Set1[3] = 11;
	        }
	        if(counter1 == 5)
	        {
	            Set1[4] = 11;
	        }
	        if(counter1 == 6)
	        {
	            Set1[5] = 11;
	        }
	        if(counter1 == 7)
	        {
	            Set1[6] = 11;
	        }
	        if(counter1 == 8)
	        {
	            Set1[7] = 11;
	        }
	        if(counter1 == 9)
	        {
	            Set1[8] = 11;
	        }
	
	    }
	    
	}
            if(counter == 4)
            {
            	system("cls");
				quiz(e);
            }
            if(counter == 5)
            {
            	system("cls");
            	Filing::StoreData(elementdetail);
            }
            if(counter == 6)
            {
            	system("cls");
				Electronic_Configuration(elementdetail);
            }
            if(counter == 7)
            {
            	break;
            }
            
            for(;;){
            try{
            	color(11);
            cout << "Return to main menu? [Y/N] ";
			SetConsoleTextAttribute(q, 7);
			cin >> input;
			if(input!='n'&&input!='y'&&input!='Y'&&input!='N')
			throw 101;
			else break;
		}
		catch(int a){
			cout<<"Error invalid input!!"<<endl;
//			PlaySound("./Sounds/error.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
	}
//			PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
			Sleep(400);
			if(input=='n' || input=='N')
			break;
			else
			system("cls");
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;
        Set[5] = 7;
        Set[6] = 7;

        if(counter == 1)
        {
            Set[0] = 11;
        }
        if(counter == 2)
        {
            Set[1] = 11;
        }
        if(counter == 3)
        {
            Set[2] = 11;
        }
        if(counter == 4)
        {
            Set[3] = 11;
        }
        if(counter == 5)
        {
            Set[4] = 11;
        }
        if(counter == 6)
        {
            Set[5] = 11;
        }
        if(counter == 7)
        {
            Set[6] = 11;
        }


    }
    system("cls");
    color(11);
    gotoxy(40,5);
	cout << "Thank you for using Modern Periodic Table!";
	gotoxy(57,7);
	cout << "Made By:\n";
	color(7);
	gotoxy(47,9);
	cout << "Sara Hameed    " << endl;

	color(7);
//	PlaySound("./Sounds/quit.wav", NULL, SND_FILENAME | SND_SYNC);
	color(11);
	return 0;
}
