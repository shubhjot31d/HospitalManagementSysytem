#include<bits/stdc++.h>
using namespace std;

class patient
{
public:
  string  name;
  char gender;
  int age;
  string phone;
  int ID;
  patient *next;
  int room_num;
};


//DOCTOR CLASS//
class doctor
{
public:
  string name;
  int ID;
  string speciality;
  int availability;
  long int contact;
  vector<string>patient_booking;
  doctor *next;
};


//PATIENT MANAGEMENT//
class patient_process
{
private:
  patient *first;
public:
  patient_process(string *n,char g[],int *a,string*p)
  {
    first = new patient;
    first->name=n[0];
    first->gender=g[0];
    first->age=a[0];
    first->phone=p[0];
    first->ID=1;
    first->room_num=1;
    first->next=nullptr;
    patient *tail = first;


    for(int i=1;i<=2;i++)
    {
      patient *t=new patient;
      t->name=n[i];
      t->gender=g[i];
      t->age=a[i];
      t->phone=p[i];
      t->ID=i+1;
      t->room_num=i+1;
      t->next=nullptr;
      tail->next=t;
      tail=t;
    }
  }
 int count()
 {
   patient *t=first;
   int ct=1;
   while(t!=nullptr)
   {
     ct++;
     t=t->next;
   }
   return ct;
 }

//PATIENT REGISTERATION//
void registers()
{
  string n;int a;char g;string p;
  cout<<" ! Welcome to Registeration portal ! \n\n";
  cout<<"Enter the patient`s name : ";
  cin>>n;
  cout<<"\nEnter patient`s age (yrs): ";
  cin>>a;
  cout<<"\nEnter patient`s gender (M/F) : ";
  cin>>g;
  cout<<"\nEnter phone number (10 digits) : ";
  cin>>p;

  patient *k=first;
  patient *fresh = new patient;
  fresh->name=n;
  fresh->age=a;
  fresh->gender=g;
  fresh->phone=p;
  fresh->ID=count();
  fresh->room_num=count();
  while(k->next!=nullptr)
  {
    k=k->next;
  }
  fresh->next=k->next;
  k->next=fresh;
  system("pause");
  system("CLS");
  system("pause");
  cout<<"\n\n Patient is registered successfuly with us !\n\n";
  cout<<"Registered reciept is displayed\n";
    cout<<"NAME: "<<fresh->name;
    cout<<"\n"<<"AGE: "<<fresh->age;
    cout<<"\n"<<"GENDER: "<<fresh->gender;
    cout<<"\n"<<"PHONE: "<<fresh->phone;
    cout<<"\n"<<"DOC ID: "<<fresh->ID;
    cout<<"\n"<<"ROOM NUM: "<<fresh->room_num;
}

//PATIENT DISCHARGE WITH BILL GENERATION//
void  discharge()
{
  cout<<"Welcome to patient discharge portal ! \n\n";
  cout<<"Enter patient`s ID number : ";
  int identity;
  cin>>identity;
  patient * temp=first;
  patient * temp_prev=first;

  if(temp->ID==identity)
  {
    first=temp->next;
    cout<<temp->name<<" is Discharged"<<endl;
    delete(temp);
  }
  else{
  while(temp->ID!=identity)
  {
    temp_prev=temp;
    temp=temp->next;
  }
  patient *discharged_patient=temp;
  temp_prev->next=temp->next;
  temp->next=nullptr;
  system("pause");
  system("CLS");
  system("pause");
  cout<<temp->name<<" is discharged "<<endl;
  delete(temp);
}
}

//HOSPITAL ROOM STATUS ENQUIRY//
void room_status()
{ int room;
  cout<<"Welcome to room status enquiry portal ! "<<endl;
  cout<<"Enter room number : ";
  cin>>room;
  patient *temp=first;
  system("pause");
  system("CLS");
  system("pause");
  while(temp!=nullptr)
  {
    if(temp->room_num==room)
    {
      cout<<"This room is ooccupied by the patient : "<<temp->name<<" \nID :"<<temp->ID<<endl;
      break;
    }
    temp=temp->next;
  }
  if(temp==nullptr)
    cout<<"\nRoom number "<<room<<" is vacant "<<endl;
}

//fUNCTION TO DISPLAY DETAILS OF PATIENT//
void display_all()
  {
    patient *k=first;
    cout<<"Enter the patient ID : ";
    int pp_IDD;
    cin>>pp_IDD;
    system("pause");
    system("CLS");
    system("pause");
    //cout<<" Name "<<" Age "<<" Gender "<<" Mobile Number "<<" ID "<<" Room no. "<<endl;
    while(k!=nullptr)
    {
      if(k->ID==pp_IDD){
        cout<<" Name : "<<k->name<<"\n :Age : "<<k->age<<"\n :Gender : "<<k->gender<<"\n :Phone : "<<k->phone<<"\n :ID : "<<k->ID<<"\n :Room : "<<k->room_num<<endl;
        break;}
      k=k->next;
    }
    if(k==nullptr)
    {
      cout<<"\n\n NO such patient found !\n\n";
    }
  }
};


//DOCTORS MANAGEMENT//

class doctor_process
{
private:
  doctor *first;
public:

//STORING DOCTOR`S INFORMATIONS USING LINKED LIST//
   doctor_process(string *n,string * spec,int*avail,long int*pho,int *id)
  {
    first = new doctor;
    first->name=n[0];
    first->speciality=spec[0];
    first->availability=avail[0];
    first->contact=pho[0];
    first->ID=id[0];
    first->next=nullptr;
    doctor *tail = first;

    for(int i=1;i<=9;i++)
    {
      doctor *t=new doctor;
      t->name=n[i];
      t->speciality=spec[i];
      t->availability=avail[i];
      t->contact=pho[i];
      t->ID=id[i];
      t->next=nullptr;
      tail->next=t;
      tail=t;
    }
     doctor *k=first;
    while(k!=nullptr)
    {
      cout<<k->name<<endl;
      k=k->next;
    }

  }

  //DOCTOR AVAILABILITY SEARCH BY NAME//
  void search_by_name()
  {
    cout<<" ! Welcome to appointment booking portal ! "<<endl<<endl;
    cout<<"Select the doctor check availability and appointment booking"<<endl;
    cout<<"1.)Dr.Gupta\n2.)Dr.Aayush\n3.)Dr.Rahul\n4.)Dr.Rohit\n5.)Dr.Gayatri\n6.)Dr.Eshaan\n7.)Dr.Sumit\n8.)Dr.Gulati\n9.)Dr.Rajeev\n10.)Dr.Batra ";
    doctor *temp=first;
    cout<<endl;
    int t;
    cin>>t;
    system("pause");
    system("CLS");
    system("pause");
    while(temp!=nullptr)
    {
      if((temp->ID)==t)
        {
          if((temp->availability) == 1){
            cout<<temp->name<<" is available "<<endl;
            cout<<"Want to book appointment : YES::1  NO::0 -> "<<endl;
            int f;
            cin>>f;
            if(f==1)
             {
               string P_name;
               cout<<"Enter patient name : ";
               cin>>P_name;
               (temp->patient_booking).push_back(P_name);
               system("pause");
               system("CLS");
               system("pause");
               cout<<"\nAPPOINTMENT is book with "<<temp->name<<endl<<endl;
               cout<<"      THANK YOU !";
             }
             break;
          }
          else
            cout<<"Sorry Doctor is not available , contact us later "<<endl;
           break;
        }
        temp=temp->next;
    }
  }


//DOCTOR AVAILABILITY SEARCH BY SPECIALITY//
  void search_by_speciality()
  {
    cout<<"Welcome to appointment booking portal "<<endl<<endl;
    cout<<"Select the doctor check availability and appointment booking"<<endl<<endl;
    cout<<"1.)Cardiologist\n2.)Dentist\n3.)ENT specialist\n4.)Gynaecologist\n5.)Paediatrician\n6.)Psychiatrists\n7.)Pulmonologist\n8.)Oncologist\n9.)Neurologist\n10.)Orthopaedic ";
    doctor *temp=first;
    int t;
    cin>>t;
    system("pause");
    system("CLS");
    system("pause");
    while(temp!=nullptr)
    {
      if((temp->ID)==t)
        {
          if((temp->availability)==1){
            cout<<temp->name<<" is available ";
            cout<<"Want to book appointment : YES::1  NO::0 -> "<<endl;
            int f;
            cin>>f;
            cout<<endl;
            if(f==1)
             {
               string P_name;
               cout<<"Enter patient name : ";
               cin>>P_name;
               (temp->patient_booking).push_back(P_name);
               system("pause");
               system("CLS");
               system("pause");
               cout<<"\nAPPOINTMENT is book with "<<temp->name<<endl<<endl;
               cout<<"      THANK YOU !";
             }
             break;
          }
          else{
          cout<<"\nSorry Doctor is not available , contact us later "<<endl;
           break;
         }
        }
        else
        temp=temp->next;
    }
  }

//DISPLAY BOOKED APPOINTMENT OF DOCTORS//
  void doc_booked_records()
  {
    int n;
    cout<<"Select the Doctor for which you want to know the booked patients -> ";
    cout<<"1.)Dr.Gupta\n2.)Dr.Aayush\n3.)Dr.Rahul\n4.)Dr.Rohit\n5.)Dr.Gayatri\n6.)Dr.Eshaan\n7.)Dr.Sumit\n8.)Dr.Gulati\n9.)Dr.Rajeev\n10.)Dr.Batra \n\n";
    cin>>n;
    system("pause");
    system("CLS");
    system("pause");
    doctor *temp=first;
    while(temp!=nullptr)
    {
      if((temp->ID)==n)
      {
        if(temp->patient_booking.empty())
        {
         cout<<"No appointment is booked with "<<temp->name<<endl;
         break;
        }
        else
        {
        for (auto i = (temp->patient_booking).cbegin(); i != (temp->patient_booking).cend(); ++i)
            cout << *i << " ";
            break;
        }
      }
      temp=temp->next;
    }
  }
};


int main()
{
cout<<"                          ! WELCOME TO HOSPITAL MANAGEMENT PORTAL !\n"<<endl;

//doctor_process dd(d_name,d_speciality,d_avail,d_phone,d_ID);
cout<<"Select the sub_portal\n\nPatient Registeration & Discharge-> 1 \n\nDoctor Availability search-> 2\n";
int portal;
cin>>portal;
cout<<endl;
system("pause");
system("CLS");
system("pause");
if(portal==1)
{
  //PATIENT INIALIZATION//
string  name[]={"Shubh","Vansh","Sawan"};
char gender[]={'M','M','M'};
int age[]={20,19,20};
string phone[]={"9999999999","8888888888","7777777777"};

patient_process pp (name,gender,age,phone);
int pat_pro;
int t=1,one;
while(t==1){
cout<<"Select from the following :: \n\nPatient Registeration-> 1\nPatient Discharge-> 2\nHospital room enquiry-> 3\n  Display full Record of inpatient-> 4\n\n";
cin>>pat_pro;
system("pause");
system("CLS");
system("pause");
switch(pat_pro)
{
  case 1:
    pp.registers();
    cout<<"\npress 1 to continue: ";
    int one;
    cin>>one;
    system("pause");
    system("CLS");
    system("pause");
    break;
  case 2:
    pp.discharge();
    cout<<"\npress 1 to continue: ";
    cin>>one;
    system("pause");
    system("CLS");
    system("pause");
    break;
  case 3:
    pp.room_status();
    cout<<"\npress 1 to continue: ";
    cin>>one;
    system("pause");
    system("CLS");
    system("pause");
    break;
  case 4:
    pp.display_all();
    cout<<"\npress 1 to continue: ";
    cin>>one;
    system("pause");
    system("CLS");
    system("pause");
    break;
}
cout<<"\n\nDo you want to process again ? YES-> 1 :: NO-> 0 :: ";
cin>>t;
}
}

else if(portal==2)
{
  int one,t=1;
  //DOCTOR RECORDS//
  string d_name[]={"Dr.Gupta","Dr.Aayush","Dr.Rahul","Dr.Rohit","Dr.Gayatri","Dr.Eshaan","Dr.Sumit","Dr.Gulati","Dr.Rajeev","Dr.Batra"};
  string  d_speciality[]={"Cardiologist","Dentist","ENT specialist","Gynaecologist","Paediatrician","Psychiatrists","Pulmonologist","Oncologist","Neurologist","Orthopaedic"};
  int d_avail[]={1,1,1,1,1,1,1,1,1,1};
  long int d_phone[]={2451160,2451170,2451180,2451190,2451210,2451220,2451230,2451240,2451250,2451260};
  int d_ID[]={1,2,3,4,5,6,7,8,9,10};
  doctor_process dd(d_name,d_speciality,d_avail,d_phone,d_ID);
  while(t==1){
  int two;
  cout<<"Select from the following : \n\n Doctor availability search by name-> 1\nDoctor availability search by speciality-> 2\nDisplay booked appointments-> 3";
  cin>>two;
  system("pause");
  system("CLS");
  system("pause");
  switch (two) {
    case 1:
     dd.search_by_name();
     cout<<"\npress 1 to continue: ";
     cin>>one;
     system("pause");
     system("CLS");
     system("pause");
     break;
   case 2:
     dd.search_by_speciality();
     cout<<"\npress 1 to continue: ";
     cin>>one;
     system("pause");
     system("CLS");
     system("pause");
     break;
   case 3:
     dd.doc_booked_records();
     cout<<"\npress 1 to continue: ";
     cin>>one;
     system("pause");
     system("CLS");
     system("pause");
     break;
   }
   cout<<"\n\nDo you want to process again ? YES-> 1 :: NO-> 0 :: ";
   cin>>t;
  }
}
return 0;
}
