#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <process.h>
//#include <graphics>   //for textcolor & textbackground
using namespace std;
int datecheck(int d,int m,int y)
{
int f=0;
if(m==1||m==3||m==5||m==7||m==8||m==10||m==12 && d>=1&&d<=31)
f=1;
else
if(m==4||m==6||m==9||m==11&&d>=1&&d<=30)
f=1;
else
if(m==2&&( y%100==0&&y%400==0 || y%100!=0&&y%4==0)&&d>=1&&d<=29 )
f=1;
else
if(m==2&&d>=1&&d<=28 )
f=1;
else
f=0;
return f;
}
class finishedgoods
{
char medicinename[15];
int qty;
int tabinstrip;
int totalstrip;
float mrp;
int d1,m1,y1;		//manufacturing date
int d2,m2,y2;          //expiry date
char batchno[15];
public:
finishedgoods()
{
strcpy(medicinename,"\0");
qty=0;
tabinstrip=0;
totalstrip=0;
d1=0;
m1=0;
y1=0;
d2=0;
m2=0;
y2=0;
strcpy(batchno,"\0");
mrp=0.0;
}
~finishedgoods(){}
void input(void);
void search(void);
void display(void);
void edit(void);
void dele();
}ob1;
void finishedgoods::dele(void)
{
 char *mn[]={"BRUSTAN","ACILOC 150","RAXITID 150","ALPRAX 0.25","NORFLOX TZ"};
//clrscr();
int i,r,c,f,p,f1;
char cc1,cc;
fstream oo("MEDICINE.DAT",ios::in|ios::out|ios::binary);
fstream aa("temp.dat",ios::out|ios::binary);
f=0;
f1=0;
do
{
cc1='n';
do
{
f=0;
cout<<"\n\t Select Medicine No.  :";
for(i=0;i<5;i++)
cout<<"\n"<<i+1<<"\t"<<mn[i];
cout<<"\n\tSelect no. of selected medicine :-";
cin>>c;
if(c>=1&&c<=5)
f=1;
else
cout<<"You entered wrong no./Enter Again/Press Enter to continue";
}while(f==0);
f=0;
for(i=1;i<=r;i++)
{
  oo.read((char*)&ob1,sizeof(ob1));
  if(strcmp(ob1.medicinename,mn[c-1])==0)
  {
 cout<<"\nMedicine Name        "<<ob1.medicinename;
 cout<<"\nTotal Quantity       "<<ob1.qty;
 cout<<"\nTablets In Strip     "<<ob1.tabinstrip;
 cout<<"\nTotal Strips         "<<ob1.totalstrip;
 cout<<"\nM.R.P.            Rs."<<setprecision(2)<<ob1.mrp;
 cout<<"\nDate of Manf.        "<<ob1.d1<<":"<<ob1.m1<<":"<<ob1.y1;
 cout<<"\nExp Date             "<<ob1.d2<<":"<<ob1.m2<<":"<<ob1.y2;
 cout<<"\nBatch No.            "<<ob1.batchno;
 cout<<endl<<endl;
 f=1;
 }
cout<<"\n\tDo You Want To Delete Y/N:-";
cin>>cc1;
if(cc1=='Y'||cc1=='y')
 {
  cout<<"\n\tRecord Deleted ";
  }
  else
   {
aa.write((char*)&ob1,sizeof(ob1));
f1=1;
   }
  }
    aa.write((char*)&ob1,sizeof(ob1));
if(f==0)
{
cout<<"\n\tChemical not found ";
}
if(f1==0)
{
cout<<"\n\tDo You Want to Delete Any More ";
cout<<"\n\tSearch again Y/N  ";
cin>>cc1;
}
oo.close();
aa.close();
remove("rawstok.dat");
rename("temp.dat","rawstok.dat");
}while(cc1=='Y'||cc1=='y');
}

void finishedgoods::search(void)
{
//clrscr();
char *mn[]={"BRUSTAN","ACILOC 150","RAXITID 150","ALPRAX 0.25","NORFLOX TZ"};
int i,c,f;
char cc;
fstream aa("MEDICINE.DAT",ios::in|ios::binary);
f=0;
do
{
cc='n';
do
{
f=0;
cout<<"\n\t Select Medicine No.  :";
for(i=0;i<5;i++)
cout<<"\n"<<i+1<<"\t"<<mn[i];
cout<<"\n\tSelect no. of selected medicine :-";
cin>>c;
if(c>=1&&c<=5)
f=1;
else
cout<<"You entered wrong no./Enter Again/Press Enter to continue";
}while(f==0);
f=0;
while(!aa.eof())
{
  aa.read((char*)&ob1,sizeof(ob1));
  if(aa.eof())
  break;
  if(strcmp(ob1.medicinename,mn[c-1])==0)
  {
 cout<<"\nMedicine Name        "<<ob1.medicinename;
 cout<<"\nTotal Quantity       "<<ob1.qty;
 cout<<"\nTablets In Strip     "<<ob1.tabinstrip;
 cout<<"\nTotal Strips         "<<ob1.totalstrip;
 cout<<"\nM.R.P.            Rs."<<setprecision(2)<<ob1.mrp;
 cout<<"\nDate of Manf.        "<<ob1.d1<<":"<<ob1.m1<<":"<<ob1.y1;
 cout<<"\nExp Date             "<<ob1.d2<<":"<<ob1.m2<<":"<<ob1.y2;
 cout<<"\nBatch No.            "<<ob1.batchno;
 cout<<endl<<endl;
 f=1;
 getch();
 }
}
if(f==0)
cout<<"\n\tMedicine Out Of Stock ";
cout<<"\n\tDo You Want To Search Again Y/N  :-";
cin>>cc;
aa.seekg(0);
}while(cc=='Y'||cc=='y');
aa.close();
}
void finishedgoods::edit(void)
{
//clrscr();
char *mn[]={"BRUSTAN","ACILOC 150","RAXITID 150","ALPRAX 0.25","NORFLOX TZ"};
int i,c,f,p,f1;
char cc1,cc;
fstream oo1("MEDICINE.DAT",ios::in|ios::binary);
int r;
oo1.seekg(0,ios::end);
r=oo1.tellg();
r=r/sizeof(ob1);
oo1.close();
int ii;
fstream oo("MEDICINE.DAT",ios::in|ios::out|ios::binary);
f=0;
f1=0;
do
{
cc1='n';
do
{
f=0;
cout<<"\n\t Select Medicine No.  :";
for(i=0;i<5;i++)
cout<<"\n"<<i+1<<"\t"<<mn[i];
cout<<"\n\tSelect no. of selected medicine :-";
cin>>c;
if(c>=1&&c<=5)
f=1;
else
cout<<"You entered wrong no./Enter Again/Press Enter to continue";
}while(f==0);
f=0;
for(ii=1;ii<=r;ii++)
{
  oo.read((char*)&ob1,sizeof(ob1));
  if(strcmp(ob1.medicinename,mn[c-1])==0)
  {
 cout<<"\nMedicine Name        "<<ob1.medicinename;
 cout<<"\nTotal Quantity       "<<ob1.qty;
 cout<<"\nTablets In Strip     "<<ob1.tabinstrip;
 cout<<"\nTotal Strips         "<<ob1.totalstrip;
 cout<<"\nM.R.P.            Rs."<<setprecision(2)<<ob1.mrp;
 cout<<"\nDate of Manf.        "<<ob1.d1<<":"<<ob1.m1<<":"<<ob1.y1;
 cout<<"\nExp Date             "<<ob1.d2<<":"<<ob1.m2<<":"<<ob1.y2;
 cout<<"\nBatch No.            "<<ob1.batchno;
 cout<<endl<<endl;
 f=1;
 }
cout<<"\n\tDo You Want To Edit Y/N  :-";
cin>>cc1;
  if(cc1=='y'||cc1=='Y')
  {
   strcpy(ob1.medicinename,mn[c-1]);
cout<<"\n\tEnter Quantity   :-";
cin>>ob1.qty;
cout<<"\n\tEnter no. of tablet in strip   :-";
cin>>ob1.tabinstrip;
ob1.totalstrip=ob1.qty/ob1.tabinstrip;
cout<<"\n\tEnter M.R.P.   :-";
cin>>ob1.mrp;
do//year check
{
do
{
cout<<"\n\tEnter Manufacturing Date DD MM YYYY   :-";
cin>>ob1.d1>>ob1.m1>>ob1.y1;
f=datecheck(ob1.d1,ob1.m1,ob1.y1);
if(f==0)
{
cout<<"\n\tYou Entered Wrong Date/Enter Again/Press Enter To Continue";
getch();
}
}while(f==0);
do
{
cout<<"\n\tEnter Expiry Date DD MM YYYY   :-";
cin>>ob1.d2>>ob1.m2>>ob1.y2;
f=datecheck(ob1.d2,ob1.m2,ob1.y2);
if(f==0)
{
cout<<"\n\tYou Entered Wrong Date/Enter Again/Press Enter To Continue";
getch();
}
}while(f==0);
f=0;
if(ob1.y2>ob1.y1)
   f=1;
   else
   if(ob1.y2==ob1.y1)
   if(ob1.m2>ob1.m1)
   f=1;
   else
   if(ob1.m2==ob1.m1)
   if(ob1.d2>ob1.d1)
   f=1;
   else
   f=0;
if(f==0)
{
cout<<"\n\tManf. Date is Greater Then Exp. Date / Enter Again / Press Enter ";
getch();
}
}while(f==0);
cin.get();
do
{
f=1;
cout<<"\n\tEnter Batch no. Only 14 Character  :-";
gets(ob1.batchno);
if(strlen(ob1.batchno)>14)
{
f=0;
cout<<"\n\tYou Entered Wrong Batch No/Enter Again/Press Enter To Continue";
getch();
}
}while(f==0);
p=oo.tellg();
p=p-sizeof(ob1);
oo.seekg(p);
oo.write((char*)&ob1,sizeof(ob1));
f1=1;
cc1='N';
break;
}
}//for
if(f==0)
cout<<"\n\tMedicine Out Of Stock";
if(f1==0)
{
cout<<"\n\tDo You Want To Edit More";
cout<<"\n\tSearch Again Y/N";
cin>>cc;
}
oo.seekg(0);
}while(cc=='Y'||cc=='y');
oo.close();
}
void finishedgoods::display(void)
{
  fstream aa("MEDICINE.DAT",ios::in|ios::binary);
  while(!aa.eof())
  {
  aa.read((char*)&ob1,sizeof(ob1));
  if(aa.eof())
  break;
 cout<<"\nMedicine Name        "<<ob1.medicinename;
 cout<<"\nTotal Quantity       "<<ob1.qty;
 cout<<"\nTablets In Strip     "<<ob1.tabinstrip;
 cout<<"\nTotal Strips         "<<ob1.totalstrip;
 cout<<"\nM.R.P.            Rs."<<setprecision(2)<<ob1.mrp;
 cout<<"\nDate of Manf.        "<<ob1.d1<<":"<<ob1.m1<<":"<<ob1.y1;
 cout<<"\nExp Date             "<<ob1.d2<<":"<<ob1.m2<<":"<<ob1.y2;
 cout<<"\nBatch No.            "<<ob1.batchno;
 cout<<endl<<endl;
 getch();
 }
 aa.close();
 }
void finishedgoods::input(void)
{
//clrscr();
char *mn[]={"BRUSTAN","ACILOC 150","RAXITID 150","ALPRAX 0.25","NORFLOX TZ"};
int i,c,f;
char cc;
fstream aa("MEDICINE.DAT",ios::app|ios::binary);
do
{
do
{
f=0;
cout<<"\n\t Select Medicine No.  :";
for(i=0;i<5;i++)
cout<<"\n"<<i+1<<"\t"<<mn[i];
cout<<"\n\tSelect no. of selected medicine :-";
cin>>c;
if(c>=1&&c<=5)
f=1;
else
cout<<"You entered wrong no./Enter Again/Press Enter to continue";
}while(f==0);
strcpy(ob1.medicinename,mn[c-1]);
cout<<"\n\tEnter Quantity   :-";
cin>>ob1.qty;
cout<<"\n\tEnter no. of tablet in strip   :-";
cin>>ob1.tabinstrip;
ob1.totalstrip=ob1.qty/ob1.tabinstrip;
cout<<"\n\tEnter M.R.P.   :-";
cin>>ob1.mrp;
do//year check
{
do
{
cout<<"\n\tEnter Manufacturing Date DD MM YYYY   :-";
cin>>ob1.d1>>ob1.m1>>ob1.y1;
f=datecheck(ob1.d1,ob1.m1,ob1.y1);
if(f==0)
{
cout<<"\n\tYou Entered Wrong Date/Enter Again/Press Enter To Continue";
getch();
}
}while(f==0);
do
{
cout<<"\n\tEnter Expiry Date DD MM YYYY   :-";
cin>>ob1.d2>>ob1.m2>>ob1.y2;
f=datecheck(ob1.d2,ob1.m2,ob1.y2);
if(f==0)
{
cout<<"\n\tYou Entered Wrong Date/Enter Again/Press Enter To Continue";
getch();
}
}while(f==0);
f=0;
if(ob1.y2>ob1.y1)
   f=1;
   else
   if(ob1.y2==ob1.y1)
   if(ob1.m2>ob1.m1)
   f=1;
   else
   if(ob1.m2==ob1.m1)
   if(ob1.d2>ob1.d1)
   f=1;
   else
   f=0;
if(f==0)
{
cout<<"\n\tManf. Date is Greater Then Exp. Date / Enter Again / Press Enter ";
getch();
}
}while(f==0);
cin.get();
do
{
f=1;
cout<<"\n\tEnter Batch no. Only 14 Character  :-";
gets(ob1.batchno);
if(strlen(ob1.batchno)>14)
{
f=0;
cout<<"\n\tYou Entered Wrong Batch No/Enter Again/Press Enter To Continue";
getch();
}
}while(f==0);
aa.write((char*)&ob1,sizeof(ob1));
cout<<"\n\tDo You Want To Input Again Y/N  :-";
cin>>cc;
}while(cc=='y'||cc=='Y');
aa.close();
}

class chemicalstock
{
char suppliername[20];
char add[20];
char chemicalname[30];
int codeofchemical;
int minlim;      //minimum limit of chemical
int d1,m1,y1;    //Date of Manufacturing of chemical
int d2,m2,y2;    //Date of expiry of chemical
int d3,m3,y3;    //Date of purchasing of chemical
char batchno[10];
float rate;
int qty;         //Quantity in Kilogram

public:
chemicalstock()
{
strcpy(suppliername,"\0");
strcpy(add,"\0");
strcpy(chemicalname,"\0");
codeofchemical=0;
minlim=0;
d1=0;
m1=0;
y1=0;
d2=0;
m2=0;
y2=0;
d3=0;
m3=0;
y3=0;
strcpy(batchno,"\0");
rate=0.0;
qty=0;
}
~chemicalstock(){}
void input ();
void display();
void edit();
void del();
void search();       //Search on the basis of chemical name and code
void minlimit();
void indent(void);
}ob;
void chemicalstock::indent(void)
{
   char chemicalname[5][30];
int codeofchemical[5];
int qty[5];         //Quantity in Kilogram
    for(int k=0;k<5;k++)
    {
    strcpy(chemicalname[k],"\0");
    codeofchemical[k]=0;
    qty[k]=0;
    }
   char *nn[]={"IBUPROFEN IP              ","PARACETAMOL IP            "
   ,"RANITIDINE HCl IP   ","TITANIUM DI OXIDE IP      ","ROXITHROMYCIN             "
   ,"ALPRAZOIAM IP             ","TARTRAZINE IP             "
   ,"NORFLOXACIN IP            ","TINIDAZOL IP              "
   ,"QUINOLINE YELLOW     "};
   int code[]={101,102,103,104,105,106,107,108,109,110};
//  clrscr();
char cc;
int f,tm,i,s,p,f1,l,j;
cout<<"\n\tSelect Chemical Name For Issue To Lab.";
tm=0;
do
{
cc='N';
	do
	{
	f=0;
    cout<<"\n\tSelect Chemical No.";
    for( i=0;i<10;i++)
    {
    if(i==9)
     cout<<"\n"<<i+1<<".  "<<nn[i]<<"\t"<<code[i];
     else
     cout<<"\n"<<" "<<i+1<<".  "<<nn[i]<<"\t"<<code[i];
     }
    cout<<"\n\tEnter The Selected No. ";
    cin>>s;
    if(s>=1&&s<=10)
    f=1;
    else
    {
    cout<<"\n\tENTER NO. IS WRONG / ENTER AGAIN / PRESS ENTER TO CONTINUE";
    getch();
    }
    }while(f==0);
  strcpy(chemicalname[tm],nn[s-1]);
  codeofchemical[tm]=code[s-1];
cout<<"\n\tENTER QUANTITY        ";
cin>>qty[tm];
tm++;
if(tm<5)
{         //Quantity in Kilogram
cout<<"\n\tSelect More Chemical Name Y/N  ";
cin>>cc;
}
}while(cc=='Y'||cc=='y');
    cout<<"\n input taken selected  "<<tm;
    int tr;
//    clrscr();
    fstream oo("rawstok.dat",ios::in|ios::out|ios::binary);
    oo.seekg(0,ios::end);
    tr=oo.tellg();
    tr=tr/sizeof(ob);
    cout<<"\n total record "<<tr;
    l=0;
    f1=0;
    int tqty;
    oo.seekg(0);
    cout<<"\n hit key";
    getch();
    for(i=1;i<=tr;i++)
    {
    tqty=0;
    for(j=1;j<=tr;j++)
    {
    oo.read((char*)&ob,sizeof(ob));
cout<<"\nSupplier Name        :-"<<ob.suppliername;
cout<<"\nAddress              :-"<<ob.add;
cout<<"\nChemical Name        :-"<<ob.chemicalname;
cout<<"\nCode of Chemical     :-"<<ob.codeofchemical;
cout<<"\nMinimum Limit        :-"<<ob.minlim;
cout<<"\nQuantity In Stock    :-"<<ob.qty;
cout<<"\n j="<<j<<"  tr="<<tr;
getch();
     if(strcmp(ob.chemicalname,chemicalname[l])==0)
     {
     cout<<"\n qty is adding";
     tqty=tqty+ob.qty;
     getch();
     }
    } //for  j
    if(qty[l]<=tqty)
    {
     f1++;
    }
    else
    break;
     l++;
     oo.seekg(0);
     i=0;
     if(f1==tm)
     break;
     }
     cout<<"\n\ttotal chemical entered "<<tm<<" selected meet "<<f1;
    if(f1==tm)
     {
     oo.seekg(0);
     l=0;
     f1=0;
     for(i=1;i<=tr;i++)
    {
     oo.read((char*)&ob,sizeof(ob));
     if(strcmp(ob.chemicalname,chemicalname[l])==0)
     {
      if(ob.qty>=qty[l])
      {
      ob.qty-=qty[l];
      qty[l]=0;
      cout<<"\n qty[l] "<<qty[l];
      }
      else
      {
      qty[l]=qty[l]-ob.qty;
      ob.qty=0;
      cout<<"\n qty[l] "<<qty[l];
      }
     p=oo.tellg();
     p=p-sizeof(ob);
     cout<<"\n position  "<<p;
     oo.seekg(p);
     oo.write((char*)&ob,sizeof(ob));
     }
     if(qty[l]>0)
     {;}
     else
     {
     l++;
     f1++;
     oo.seekg(0);
     i=0;
     }
     if(f1==tm)
     break;
    }      //for
    oo.seekg(0);
    cout<<"\n finished  ";
    fstream aa("temp.dat",ios::out|ios::binary);
   for(i=1;i<=tr;i++)
   {
    oo.read((char*)&ob,sizeof(ob));
    if(ob.qty==0)
    {;}
    else
    aa.write((char*)&ob,sizeof(ob));
   }
   oo.close();
   aa.close();
   remove("rawstok.dat");
   rename("temp.dat","rawstok.dat");
   }//if f1==tm
     else
     {
     cout<<"\n\tChemical Selected Out Of Stock / Press Enter to Continue:";
     getch();
     }
}
    void chemicalstock::minlimit(void)
  {
    fstream oo("rawstok.dat",ios::in|ios::binary);
    cout<<"\nList of Chemicals Which Are Less Then Min. Limit\n";
    while(!oo.eof())
    {
    oo.read((char*)&ob,sizeof(ob));
    if(oo.eof())
    break;
    if(ob.qty<5)
    {
cout<<"\nSupplier Name        :-"<<ob.suppliername;
cout<<"\nAddress              :-"<<ob.add;
cout<<"\nChemical Name        :-"<<ob.chemicalname;
cout<<"\nCode of Chemical     :-"<<ob.codeofchemical;
cout<<"\nMinimum Limit        :-"<<ob.minlim;
cout<<"\nQuantity In Stock    :-"<<ob.qty;
cout<<endl<<endl;
    getch();
    }
    }
    oo.close();
  }
  void chemicalstock::display(void)
  {
    fstream oo("rawstok.dat",ios::in|ios::binary);
   cout<<"\nList of Details of Chemicals\n";
    while(!oo.eof())
    {
    oo.read((char*)&ob,sizeof(ob));
    if(oo.eof())
    break;
cout<<"\nSupplier Name        :-"<<ob.suppliername;
cout<<"\nAddress              :-"<<add;
cout<<"\nChemical Name        :-"<<chemicalname;
cout<<"\nCode of Chemical     :-"<<codeofchemical;
cout<<"\nMinimum Limit        :-"<<minlim;
cout<<"\nDate of Manufacture  :-"<<d1<<"/"<<m1<<"/"<<y1;
cout<<"\nDate of Expiry       :-"<<d2<<"/"<<m2<<"/"<<y2;
cout<<"\nDate of Purchasing   :-"<<d3<<"/"<<m3<<"/"<<y3;
cout<<"\nBatch No.            :-"<<batchno;
cout<<"\nRate of Chemical     :-"<<rate;
cout<<"\nQuantity in Kg       :-"<<qty;
    cout<<endl<<endl;
    getch();
    }
    oo.close();
  }
  void chemicalstock::input(void)
  {
   char ch;
   cout<<"\n\tDo You Want To Input Stock Y/N  :";
   cin>>ch;
   cin.get();
   if(ch=='Y'||ch=='y')
   {
   char *nn[]={"IBUPROFEN IP              ","PARACETAMOL IP            "
   ,"RANITIDINE HCl IP   ","TITANIUM DI OXIDE IP      ","ROXITHROMYCIN             "
   ,"ALPRAZOIAM IP             ","TARTRAZINE IP             "
   ,"NORFLOXACIN IP            ","TINIDAZOL IP              "
   ,"QUINOLINE YELLOW     "};
   int code[]={101,102,103,104,105,106,107,108,109,110};
   int lim=5;
//    clrscr();
int f,i,s;
fstream oo("rawstok.dat",ios::app|ios::binary);
int l;
do
{
//   clrscr();
do
{
	f=0;
    cout<<"\n\tSelect Chemical No.";
    for( i=0;i<10;i++)
    {
    if(i==9)
     cout<<"\n"<<i+1<<".  "<<nn[i]<<"\t"<<code[i]<<"\tMin. Lim. "<<lim<<"  kg.";
     else
     cout<<"\n"<<" "<<i+1<<".  "<<nn[i]<<"\t"<<code[i]<<"\tMin. Lim. "<<lim<<"  kg.";
     }
    cout<<"\n\tEnter The Selected No. ";
    cin>>s;
    if(s>=1&&s<=10)
    f=1;
    else
    {
    cout<<"\n\tENTER NO. IS WRONG / ENTER AGAIN / PRESS ENTER TO CONTINUE";
    getch();
    }
    }while(f==0);
//    clrscr();
strcpy(ob.chemicalname,nn[s-1]);
ob.codeofchemical=code[s-1];
ob.minlim=lim;
cin.get();
  cout<<"\n\tCHEMICAL NAME     "<<ob.chemicalname;
  cout<<"\n\tCODE NO.          "<<ob.codeofchemical;
  cout<<"\n\tMIN. LIMIT        "<<ob.minlim;
do
{
f=1;
cout<<"\n\tEnter Supplier Name 19(Char) ONLY   :";
gets(ob.suppliername);
l=strlen(ob.suppliername);
if(l>19)
{
cout<<"\n\tONLY 19 CHARACTER / ENTER AGAIN / PRESS ENTER TO CONTINUE";
f=0;
getch();
}
}while(f==0);
strupr(ob.suppliername);
do
{
f=1;
cout<<"\n\tEnter Supplier Add. 19(Char)ONLY   :";
  gets(ob.add);
if(strlen(ob.add)>19)
{
cout<<"\n\tONLY 19 CHARACTER / ENTER AGAIN / PRESS ENTER TO CONTINUE";
f=0;
getch();
}
}while(f==0);
strupr(ob.add);
do
{
cout<<"\n\tEnter Manf. Date DD MM YYYY :";
cin>>ob.d1>>ob.m1>>ob.y1;
f=datecheck(ob.d1,ob.m1,ob.y1);
if(f==0)
{
cout<<"\n\tDate Entered Wrong Enter Again / Press Enter To Continue";
getch();
cout<<"                                                        ";
}
}while(f==0);
do
{
cout<<"\n\tEnter Exp. Date DD MM YYYY :";
cin>>ob.d2>>ob.m2>>ob.y2;
f=datecheck(ob.d2,ob.m2,ob.y2);
if(f==0)
{
cout<<"\n\tDate Entered Wrong Enter Again / Press Enter To Continue";
getch();
cout<<"\n\t                                                        ";
}
}while(f==0);
do
{
cout<<"\n\tEnter Purchase Date DD MM YYYY :";
cin>>ob.d3>>ob.m3>>ob.y3;
f=datecheck(ob.d3,ob.m3,ob.y3);
if(f==0)
{
cout<<"\n\tDate Entered Wrong Enter Again / Press Enter To Continue";
getch();
cout<<"\n\t                                                        ";
}
}while(f==0);
cin.get();
do
{
f=1;
cout<<"\n\tENTER BATCH NO.9 (Char) ONLY       ";
gets(ob.batchno);
if(strlen(ob.batchno)>9)
{
cout<<"\n\tONLY 9 CHARACTER / ENTER AGAIN / PRESS ENTER TO CONTINUE";
f=0;
getch();
}
}while(f==0);
cout<<"\n\tENTER ITS RATE        ";
cin>>ob.rate;
cout<<"\n\tENTER QUANTITY        ";
cin>>ob.qty;
oo.write((char*)&ob,sizeof(ob));
cout<<"\n\tENTER MORE DATA Y/N  ";
cin>>ch;
cin.get();
}while(ch=='y'||ch=='Y');
oo.close();
}//if(ch=='y') input or not
    }
void chemicalstock::search(void)
{
   char *nn[]={"IBUPROFEN IP              ","PARACETAMOL IP            "
   ,"RANITIDINE HCl IP   ","TITANIUM DI OXIDE IP      ","ROXITHROMYCIN             "
   ,"ALPRAZOIAM IP             ","TARTRAZINE IP             "
   ,"NORFLOXACIN IP            ","TINIDAZOL IP              "
   ,"QUINOLINE YELLOW     "};
   int code[]={101,102,103,104,105,106,107,108,109,110};
   int lim=5;
//clrscr();
char cc;
int f,i,s;
do
{
cc='N';
do
{
	f=0;
    cout<<"\n\tSelect Chemical No.";
    for( i=0;i<10;i++)
    {
    if(i==9)
     cout<<"\n"<<i+1<<".  "<<nn[i]<<"\t"<<code[i]<<"\tMin. Lim. "<<lim<<"  kg.";
     else
     cout<<"\n"<<" "<<i+1<<".  "<<nn[i]<<"\t"<<code[i]<<"\tMin. Lim. "<<lim<<"  kg.";
     }
    cout<<"\n\tEnter The Selected No. ";
    cin>>s;
    if(s>=1&&s<=10)
    f=1;
    else
    {
    cout<<"\n\tENTER NO. IS WRONG / ENTER AGAIN / PRESS ENTER TO CONTINUE";
    getch();
    }
    }while(f==0);
//    clrscr();
    fstream aa("rawstok.dat",ios::in|ios::binary);
    f=0;
    while(!aa.eof())
    {
    aa.read((char*)&ob,sizeof(ob));
    if(strcmp(ob.chemicalname,nn[s-1])==0)
    {
    f=1;
cout<<"\nSupplier Name        :-"<<ob.suppliername;
cout<<"\nAddress              :-"<<add;
cout<<"\nChemical Name        :-"<<chemicalname;
cout<<"\nCode of Chemical     :-"<<codeofchemical;
cout<<"\nMinimum Limit        :-"<<minlim;
cout<<"\nDate of Manufacture  :-"<<d1<<"/"<<m1<<"/"<<y1;
cout<<"\nDate of Expiry       :-"<<d2<<"/"<<m2<<"/"<<y2;
cout<<"\nDate of Purchasing   :-"<<d3<<"/"<<m3<<"/"<<y3;
cout<<"\nBatch No.            :-"<<batchno;
cout<<"\nRate of Chemical     :-"<<rate;
cout<<"\nQuantity in Kg       :-"<<qty;
    cout<<endl<<endl;
	break;
    }
    }
if(f==0)
{
cout<<"\n\tChemical not found / Press enter to continue";
cout<<"\n\tSearch again Y/N  ";
cin>>cc;
}
aa.close();
}while(cc=='Y'||cc=='y');
}
void chemicalstock::edit(void)
{
   char *nn[]={"IBUPROFEN IP              ","PARACETAMOL IP            "
   ,"RANITIDINE HCl IP   ","TITANIUM DI OXIDE IP      ","ROXITHROMYCIN             "
   ,"ALPRAZOIAM IP             ","TARTRAZINE IP             "
   ,"NORFLOXACIN IP            ","TINIDAZOL IP              "
   ,"QUINOLINE YELLOW     "};
   int code[]={101,102,103,104,105,106,107,108,109,110};
   int lim=5;
//clrscr();
char cc,cc1;
int f,i,s,p,f1,l;
do
{
cc1='N';
f1=0;
do
{
	f=0;
    cout<<"\n\tSelect Chemical No.";
    for( i=0;i<10;i++)
    {
    if(i==9)
     cout<<"\n"<<i+1<<".  "<<nn[i]<<"\t"<<code[i]<<"\tMin. Lim. "<<lim<<"  kg.";
     else
     cout<<"\n"<<" "<<i+1<<".  "<<nn[i]<<"\t"<<code[i]<<"\tMin. Lim. "<<lim<<"  kg.";
     }
    cout<<"\n\tEnter The Selected No. ";
    cin>>s;
    if(s>=1&&s<=10)
    f=1;
    else
    {
    cout<<"\n\tENTER NO. IS WRONG / ENTER AGAIN / PRESS ENTER TO CONTINUE";
    getch();
    }
    }while(f==0);
//    clrscr();
    fstream oo("rawstok.dat",ios::in|ios::out|ios::binary);
    f=0;
    while(!oo.eof())
    {
    oo.read((char*)&ob,sizeof(ob));
    if(strcmp(ob.chemicalname,nn[s-1])==0)
    {
    f=1;
cout<<"\nSupplier Name        :-"<<ob.suppliername;
cout<<"\nAddress              :-"<<add;
cout<<"\nChemical Name        :-"<<chemicalname;
cout<<"\nCode of Chemical     :-"<<codeofchemical;
cout<<"\nMinimum Limit        :-"<<minlim;
cout<<"\nDate of Manufacture  :-"<<d1<<"/"<<m1<<"/"<<y1;
cout<<"\nDate of Expiry       :-"<<d2<<"/"<<m2<<"/"<<y2;
cout<<"\nDate of Purchasing   :-"<<d3<<"/"<<m3<<"/"<<y3;
cout<<"\nBatch No.            :-"<<batchno;
cout<<"\nRate of Chemical     :-"<<rate;
cout<<"\nQuantity in Kg       :-"<<qty;
    cout<<endl<<endl;
       cout<<"\n\t Do You Want to Edit Y/N  ";
       cin>>cc1;
       if(cc1=='Y'||cc1=='y')
       {
do
{
f=1;
cout<<"\n\tEnter Supplier Name 19(Char) ONLY   :";
gets(ob.suppliername);
l=strlen(ob.suppliername);
if(l>19)
{
cout<<"\n\tONLY 19 CHARACTER / ENTER AGAIN / PRESS ENTER TO CONTINUE";
f=0;
getch();
}
}while(f==0);
strupr(ob.suppliername);
do
{
f=1;
cout<<"\n\tEnter Supplier Add. 19(Char)ONLY   :";
  gets(ob.add);
if(strlen(ob.add)>19)
{
cout<<"\n\tONLY 19 CHARACTER / ENTER AGAIN / PRESS ENTER TO CONTINUE";
f=0;
getch();
}
}while(f==0);
strupr(ob.add);
do
{
cout<<"\n\tEnter Manf. Date DD MM YYYY :";
cin>>ob.d1>>ob.m1>>ob.y1;
f=datecheck(ob.d1,ob.m1,ob.y1);
if(f==0)
{
cout<<"\n\tDate Entered Wrong Enter Again / Press Enter To Continue";
getch();
cout<<"                                                        ";
}
}while(f==0);
do
{
cout<<"\n\tEnter Exp. Date DD MM YYYY :";
cin>>ob.d2>>ob.m2>>ob.y2;
f=datecheck(ob.d2,ob.m2,ob.y2);
if(f==0)
{
cout<<"\n\tDate Entered Wrong Enter Again / Press Enter To Continue";
getch();
cout<<"\n\t                                                        ";
}
}while(f==0);
do
{
cout<<"\n\tEnter Purchase Date DD MM YYYY :";
cin>>ob.d3>>ob.m3>>ob.y3;
f=datecheck(ob.d3,ob.m3,ob.y3);
if(f==0)
{
cout<<"\n\tDate Entered Wrong Enter Again / Press Enter To Continue";
getch();
cout<<"\n\t                                                        ";
}
}while(f==0);
cin.get();
do
{
f=1;
cout<<"\n\tENTER BATCH NO.9 (Char) ONLY       ";
gets(ob.batchno);
if(strlen(ob.batchno)>9)
{
cout<<"\n\tONLY 9 CHARACTER / ENTER AGAIN / PRESS ENTER TO CONTINUE";
f=0;
getch();
}
}while(f==0);
cout<<"\n\tENTER ITS RATE        ";
cin>>ob.rate;
cout<<"\n\tENTER QUANTITY        ";
cin>>ob.qty;
p=oo.tellg();
p=p-sizeof(ob);
oo.seekg(p);
oo.write((char*)&ob,sizeof(ob));
f1=1;
cc1='N';
break;
       }
    }
    }
if(f==0)
{
cout<<"\n\tChemical not found ";
}
if(f1==0)
{
cout<<"\n\tDo You Want to Edit Any More ";
cout<<"\n\tSearch again Y/N  ";
cin>>cc1;
}
oo.close();
}while(cc1=='Y'||cc1=='y');
}
void chemicalstock::del(void)
{
   char *nn[]={"IBUPROFEN IP              ","PARACETAMOL IP            "
   ,"RANITIDINE HCl IP   ","TITANIUM DI OXIDE IP      ","ROXITHROMYCIN             "
   ,"ALPRAZOIAM IP             ","TARTRAZINE IP             "
   ,"NORFLOXACIN IP            ","TINIDAZOL IP              "
   ,"QUINOLINE YELLOW     "};
   int code[]={101,102,103,104,105,106,107,108,109,110};
   int lim=5;
//clrscr();
char cc,cc1;
int f,i,s,p,f1,l;
do
{
cc1='N';
f1=0;
do
{
	f=0;
    cout<<"\n\tSelect Chemical No. To Delete";
    for( i=0;i<10;i++)
    {
    if(i==9)
     cout<<"\n"<<i+1<<".  "<<nn[i]<<"\t"<<code[i]<<"\tMin. Lim. "<<lim<<"  kg.";
     else
     cout<<"\n"<<" "<<i+1<<".  "<<nn[i]<<"\t"<<code[i]<<"\tMin. Lim. "<<lim<<"  kg.";
     }
     cout<<"\n\tEnter The Selected No. ";
    cin>>s;
    if(s>=1&&s<=10)
    f=1;
    else
    {
    cout<<"\n\tENTER NO. IS WRONG / ENTER AGAIN / PRESS ENTER TO CONTINUE";
    getch();
    }
    }while(f==0);
//    clrscr();
    fstream oo("rawstok.dat",ios::in|ios::binary);
     fstream aa("temp.dat",ios::out|ios::binary);
    f=0;
    while(!oo.eof())
    {
    oo.read((char*)&ob,sizeof(ob));
    if(oo.eof())
    break;
    if(strcmp(ob.chemicalname,nn[s-1])==0)
    {
    f=1;
cout<<"\nSupplier Name        :-"<<ob.suppliername;
cout<<"\nAddress              :-"<<add;
cout<<"\nChemical Name        :-"<<chemicalname;
cout<<"\nCode of Chemical     :-"<<codeofchemical;
cout<<"\nMinimum Limit        :-"<<minlim;
cout<<"\nDate of Manufacture  :-"<<d1<<"/"<<m1<<"/"<<y1;
cout<<"\nDate of Expiry       :-"<<d2<<"/"<<m2<<"/"<<y2;
cout<<"\nDate of Purchasing   :-"<<d3<<"/"<<m3<<"/"<<y3;
cout<<"\nBatch No.            :-"<<batchno;
cout<<"\nRate of Chemical     :-"<<rate;
cout<<"\nQuantity in Kg       :-"<<qty;
    cout<<endl<<endl;
       cout<<"\n\t Do You Want to Delete  Y/N  ";
       cin>>cc1;
       if(cc1=='Y'||cc1=='y')
       {
       cout<<"\n\tRecord Deleted ";
       }
       else
       {
aa.write((char*)&ob,sizeof(ob));
f1=1;
       }
    }
    else
    aa.write((char*)&ob,sizeof(ob));
     }
if(f==0)
{
cout<<"\n\tChemical not found ";
}
if(f1==0)
{
cout<<"\n\tDo You Want to Delete Any More ";
cout<<"\n\tSearch again Y/N  ";
cin>>cc1;
}
oo.close();
aa.close();
remove("rawstok.dat");
rename("temp.dat","rawstok.dat");
}while(cc1=='Y'||cc1=='y');
}
int control2()
{
//clrscr();
int c;
char ch;
do
{
//clrscr();
//gotoxy(10,4);
cout<<"Medicine Inventory:"<<endl<<endl;
cout<<"\t1. To Input Data in Finished goods" <<endl
    <<"\t2. To Display All The Records"      <<endl
    <<"\t3. To Search Any Record In The File"<<endl
    <<"\t4. To Edit Any Record"              <<endl
    <<"\t5. To Delete"                       <<endl
    <<"\t6. To Exit"<<endl
    <<endl<<"\tEnter your Choice"            <<endl;
cin>>c;
switch(c)
{
case 1 :ob1.input();
	break;
case 2 :ob1.display();
	break;
case 3 :ob1.search();
	break;
case 4 :ob1.edit();
	break;
case 5 :ob1.dele();
	break;
case 6 :break;
}
if(c==6)
return 0;
//clrscr();
cout<<"\tDo You Want To Return To Medicine Inventory (Y/N)";
cin>>ch;
}while(ch=='y'||ch=='Y');
return 1;
}
int control1()
{
//clrscr();
int c;
char ch;
do
{
//clrscr();
//gotoxy(10,4);
cout<<"Chemical Inventory:"<<endl<<endl;
cout<<"\t1. To Input Data in Raw Stock" <<endl;
cout<<"\t2. To Display All The Records"      <<endl;
cout<<"\t3. To Search Any Record In The File"<<endl ;
cout<<"\t4. To Edit Any Record"<<endl;
cout<<"\t5. To Delete Any Record"<<endl;
cout<<"\t6. To View Chemicals Below Minlimit"<<endl;
cout<<"\t7. To Make Indent"<<endl;
cout<<"\t8. To Exit"<<endl<<endl<<endl;
cout<<"\tEnter your Choice"            <<endl;
cin>>c;
switch(c)
{
case 1 :ob.input();
	break;
case 2 :ob.display();
	break;
case 3 :ob.search();
	break;
case 4 :ob.edit();
	break;
case 5 :ob.del();
	break;
case 6 :ob.minlimit();
	break;
case 7 :ob.indent();
	break;
default:break;
}
if(c==8)
return 0;
//clrscr();
cout<<"\tDo You Want To Return To Chemical Inventory (Y/N)";
cin>>ch;
}while(ch=='y'||ch=='Y');
return 1;
}
int main()
{
//main1();
//clrscr();
int c,d;
char ch;
do
{
//clrscr();
//gotoxy(10,4);
cout<<"                       WELCOME TO THE MEDICINE INVENTORY    ";
cout<<endl<<endl;
cout<<"\t   Main Menu"<<endl
    <<"\t1. Chemical Inventory"<<endl
    <<"\t2. Medicine Inventory"<<endl
    <<"\t3. exit"<<endl<<endl<<endl
    <<"\tChoose Your Option"<<endl;
cin>>c;
if(c==1)
d=control1();
else if(c==2)
d=control2();
else if(c==3)
//exit(0);
getch();
if(d==0)
{
cout<<"\tDo You Want To Return To Main Menu Y/N";
cin>>ch;
//if(ch=='n'||ch=='N')
//exit(0);
}
}while(d==0);
return 0;
}
