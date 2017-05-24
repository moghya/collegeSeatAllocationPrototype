#include<bits/stdc++.h>

using namespace std;

class seat;
class stud;

vector<stud> sv;

int cnt=0; 
int tot;

class seat
{
	public:
	char c;	
	char g;	
	int sn;
	void sets(char ct,char gn)
	{
		c=ct;	g=gn;	sn=0;
	}
};

seat t[3][6];

void funs()
{
	for(int i=0;i<3;i++)
	{		
		t[i][0].sets('G','G');
		t[i][1].sets('G','G');	
		t[i][2].sets('G','F');		
		t[i][3].sets('P','G');
		t[i][4].sets('P','F');
		t[i][5].sets('S','G');
	}
}

class stud{
	public:
	char g,c;	int m,r,n,ch[3],chf,ac;
	static int ttl;
	stud(){
		n=chf=ac=m=r=ch[0]=ch[1]=ch[2]=0;	g=c='\0';
		
	}
	
	void disp(){
		cout<<"\nRoll Number:"<<n;
		cout<<"\t\tGender:"<<g;
		cout<<"\nCategory:"<<c;
		cout<<"\t\tMarks:"<<m;		
	}	

	void set(){
		n=sv.size()+1;
		cout<<"\nRoll Number:"<<n;
		cout<<"\t\tEnter Gender(M/F):"; cin>>g;
		cout<<"\nEnter Category(G/P/S):"; cin>>c;
		cout<<"\t\tEnter Marks(out of 100):"; cin>>m;
		
	}
	
	void fillc(){
		char chy;
		up:	cout<<"\nEnter Your Choices(Prefrence Wise out of 1/2/3):";
			for(int i=0;i<3;i++)
			{	cout<<"\nChoice"<<i+1<<":";
				cin>>ch[i];
			}
		cout<<"\nConfirm(Y/N)";
		cin>>chy;
		if(chy=='Y'||chy=='y') chf=1;
		else goto up;
	}
};


void setr(){
	int mi;

	
	for(int i=0;i<sv.size();i++){
		mi=i;
		for(int j=i+1;j<sv.size();j++)	{
			if(sv[j].m>sv[mi].m)
				mi=j;
		}
		swap(sv[i],sv[mi]);
	}

	int cr=1;	sv[0].r=cr;

	for(int i=1;i<sv.size();i++){
		if(sv[i-1].m>sv[i].m) cr++;
		sv[i].r=cr;
	}

	for(int i=0;i<sv.size();i++){
		mi=i;
		for(int j=i+1;j<sv.size();j++){
			if(sv[j].n<sv[mi].n)
				mi=j;
		}
		swap(sv[i],sv[mi]);
	}

}

void setal(){

	int mi;
	for(int i=0;i<sv.size();i++){
		mi=i;
		for(int j=i+1;j<sv.size();j++){
			if(sv[j].r<sv[mi].r)
				mi=j;
		}
		swap(sv[i],sv[mi]);
	}


	for(int i=0;i<sv.size();i++){
		for(int j=0; j<3 && sv[i].ac==0 ;j++){			
			for(int k=0; k<6 ;k++){
						
				if( (k==0||k==1) && t[ sv[i].ch[j]-1 ][k].sn==0 ){
				t[ sv[i].ch[j]-1 ][k].sn=sv[i].n;
				sv[i].ac=sv[i].ch[j];
				break;
				}	
				
				if( k==2 && sv[i].g==t[sv[i].ch[j]-1 ][k].g && t[ sv[i].ch[j]-1 ][k].sn==0 ){
				t[ sv[i].ch[j]-1 ][k].sn=sv[i].n;
				sv[i].ac=sv[i].ch[j];
				break;
				}
				
				if( k==3 && sv[i].c==t[sv[i].ch[j]-1 ][k].c && t[ sv[i].ch[j]-1 ][k].sn==0 ){
				t[ sv[i].ch[j]-1 ][k].sn=sv[i].n;
				sv[i].ac=sv[i].ch[j];
				break;
				}
				if( ( k==4 && sv[i].c==t[sv[i].ch[j]-1 ][k].c ) && ( sv[i].g==t[sv[i].ch[j]-1 ][k].g && t[ sv[i].ch[j]-1 ][k].sn==0 ) ){
				t[ sv[i].ch[j]-1 ][k].sn=sv[i].n;
				sv[i].ac=sv[i].ch[j];
				break;
				}

				if( k==5 && sv[i].c==t[sv[i].ch[j]-1 ][k].c && t[ sv[i].ch[j]-1 ][k].sn==0 ){
				t[ sv[i].ch[j]-1 ][k].sn=sv[i].n;
				sv[i].ac=sv[i].ch[j];
				break;
				}
			}					
		}   
	}	


		for(int i=0;i<sv.size();i++){
		mi=i;
		for(int j=i+1;j<sv.size();j++){
			if(sv[j].n<sv[mi].n)
			mi=j;
		}
		swap(sv[i],sv[mi]);
		}

}

void ilist(int tmp){
	cout<<"\nAllotment for Institute: "<<tmp<<"\n";
	cout<<"\nSeat_Type\tRoll Num\tMarks\tRank\tStud_Type";
	for(int i=0;i<6;i++){
		if(t[tmp-1][i].sn!=0)
		cout<<"\n"<<t[tmp-1][i].c<<t[tmp-1][i].g<<"\t\t\t"<<t[tmp-1][i].sn<<"\t"<<sv[ t[tmp-1][i].sn -1 ].m<<"\t"<<sv[ t[tmp-1][i].sn -1 ].r<<"\t"<<sv[ t[tmp-1][i].sn -1 ].c<<sv[ t[tmp-1][i].sn -1 ].g;

	}
}


/*
void sysw(){
	fstream f; stud s;
	f.open("data.dat",ios::out|ios::bin);
	for(int i=0;i<sv.size();i++){
	s=sv[i];
	f.write((char*)&s,sizeof(s)) ;
	}
	f.close();
	cout<<"\nNo of Records on disk saved:"<<sv.size();
}

void sysr(){
	fstream f; stud s;
	f.open("data.dat",ios::in|ios::bin);
	while( f.read((char*)&s,sizeof(s)) ){
		sv.push_back(s);
		if(s.ch[0]!=0) cnt++;
	}
	f.close();
	cout<<"\nSystem Initialized No of Records on disk:"<<sv.size();
}
*/
void case1(){
	stud s;
	if(sv.size()==tot) cout<<"\nSorry No more Entires."; 
	else{ 	s.set();
		sv.push_back(s); 
		if(sv.size()==tot)
		setr();
	}
}

void case2(){
	int tmp;
	if(sv.size()!=tot) cout<<"\nSorry, Ranks are not yet declared ."; 
	else{	cout<<"Enter Roll Number:"; cin>>tmp;
		if(tmp<0||tmp>sv.size())
		cout<<"\nWrong Roll Number :("; 
		else{
		sv[tmp-1].disp();
		cout<<"\nRank:"<<sv[tmp-1].r;}
	}	
}

void case3(){
	int tmp;
	if(sv.size()!=tot) cout<<"\nSorry, This process is not started yet."; 
	else{
		cout<<"Enter Roll Number:"; cin>>tmp; 
		if(tmp<0||tmp>sv.size())
		cout<<"\nWrong Roll Number :(";
		else{	
			if(sv[tmp-1].chf){ 
				cout<<"\nYou Filled Choices";
				sv[tmp-1].disp();
				cout<<"\nRank:"<<sv[tmp-1].r;
				cout<<"\nChoices:"<<"\t1."<<sv[tmp-1].ch[0]<<"\t2."<<sv[tmp-1].ch[1]<<"\t3."<<sv[tmp-1].ch[2];
			}
			else{	
				sv[tmp-1].fillc(); cnt++;
				if(cnt==tot) setal();
			}	
		}
	}
}


void case4(){
	int tmp;
	if(cnt!=tot) cout<<"\nSorry, Allotment not yet declared."; 
	else{ 
		cout<<"Enter Roll Number:"; cin>>tmp; 
		if(tmp<0||tmp>sv.size())
			cout<<"\nWrong Roll Number :(";
		else{
			sv[tmp-1].disp();
			cout<<"\nRank:"<<sv[tmp-1].r;
			cout<<"\nChoices:"<<"\t1."<<sv[tmp-1].ch[0]<<"\t2."<<sv[tmp-1].ch[1]<<"\t3."<<sv[tmp-1].ch[2];							
			if(!sv[tmp-1].ac) cout<<"\nSorry No choice is alloted.";
			else	cout<<"\n\nAlloted Choice is:"<<sv[tmp-1].ac;
		}	
				
	}
}

void case5(){
	int tmp;
	if(cnt!=tot) cout<<"\nSorry, Allotment not yet declared."; 
	else{ 
		cout<<"\nEnter Institute Code (1/2/3):"; 
		cin>>tmp;
		ilist(tmp);				
	}
}

void case6(){
	if(sv.size()<=0) cout<<"\nNo Students Registered yet.";
	else{
		cout<<"\nRoll_Num\tCategory\tGender\tMarks\tRank";
		for(int i=0;i<sv.size();i++){
		cout<<"\n"<<sv[i].n<<"\t\t\t"<<sv[i].c<<"\t"<<sv[i].g<<"\t"<<sv[i].m<<"\t"<<sv[i].r;
		}
	}
}

int menu(){
	int c;
	cout<<"\n\n\n\n1.Entry\n2.Check Rank\n3.Fill Choice\n4.Check Allotment\n5.Institute wise allotment List\n6.Lis of all Reg_Students\n7.Clear all Records\n8.Exit\n.Enter Choice:";
	cin>>c;
	return c;
}

int main()
{
	int ch; tot=10;
	//sysr();
	funs();
	while(1){
	upp:	ch=menu();
	switch(ch){
		case 1: case1(); break;
		case 2: case2(); break;
		case 3: case3(); break;
		case 4: case4(); break;
		case 5: case5(); break;
		case 6: case6(); break;
		case 7:	sv.clear(); break;
		case 8: sv.clear();	exit(0); break;
		default: cout<<"\nWrong Choice !!"; goto upp;
	
	}	
		
}
	return 0;
}                                          
