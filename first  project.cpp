#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;	
struct train{
	int train_id;
	string from;
	string to;
	string departure;
	string arrival;
long  price;
	int passenger_count;
	train* next;};
struct passenger{
	string name;
	 int train_id;
	int   Ticketnumber;
	string from;
	string to;
	passenger* next;};
void admin_mode()
{system("color 03");
	string pass="admin";
	string password;
	cout<<"   < ----Please log in to the program------->   "<<endl;
	cout<<"<<---------Welcome admin Please enter your password------->>"<<endl;
	s:
	cin>>password;
	if(password== pass)
	{
		cout<<"You have been logged in successfully";	
	}
else{
	cout<<"The password is incorrect, try again"<<endl;
	goto s ;
}}	
	train* head= NULL;
	void addtrain(int train_id,string from,string to,string departure,	string arrival,int passenger_count,long  price)
	{
			train* new_train,*last;
	new_train=new train;
	new_train->train_id=train_id;
	new_train->from=from;
	new_train->to=to;
	new_train->departure=departure;
	new_train->arrival=arrival;
	new_train->passenger_count=passenger_count;
	new_train-> price= price;
	if(head==NULL)
	{
		head=new_train;
		new_train->next=NULL;
		
	}
	else
	{
		train*last=head;
			while(last->next!=NULL)
		{
			last=last->next;
		}
		last->next=new_train;
		new_train->next=NULL;
	}
	}
	void displaytrains()
	{
			train* court_train;
		if(head==NULL)
		{
			cout<<"There are no trains available!";
		}
		else
		{
		
		train*	court_train =head;
				cout<<"List of available trips"<<endl;
		while(court_train!=NULL)
		{
			cout<<"====================================================="<<endl;
			cout<<"||  train_id:    "<<court_train->train_id<<endl;
			cout<<"||       ----------------"<<endl;
			cout<<"||   from :     "<<court_train->from<<endl;
			cout<<"||          -------------"<<endl;
			cout<<"||    to  :    "<<court_train->to<<endl;
			cout<<"||         ---------------"<<endl;
			cout<<"||departure:   "<<court_train->departure  <<endl;
			cout<<"||         --------------"<<endl;
			cout<<"||arrival  :   "<<court_train->arrival<<endl;
			cout<<"||          -----------------"<<endl;
			cout<<"||passcount:  "<<court_train->passenger_count<<endl;
			cout<<"||          -----------------"<<endl;
			cout<<"||     the price  :"<<court_train-> price <<endl;
			cout<<"||              --------------"<<endl;
			cout<<"========================================================"<<endl<<endl;
		
		court_train=court_train->next;}
				
		}
		
	}
	 void deleteTrain(int train_id) {
    if (head == NULL) {
        cout << "No trains to delete." << endl;
    }
    if (head->train_id == train_id) {
        train*temp = head;
        head = head->next;
        delete temp;
        cout << "Train --" << train_id << " -- deleted successfully." << endl;
    }
    train* x = head;
    train* y = NULL;

    while (x != NULL && x->train_id != train_id) {
        y = x;
        x = x->next;
    }

    if (x == NULL) {
        cout << "<<<Train --" << train_id << "-- not found.>>>" << endl;
    } else {
        y->next = x->next;
        delete (x);
        cout << "<<Train --" << train_id << "-- deleted successfully.>>" << endl;
    }
return;	
}
	void user_mode()
{system("color 06");
	string username;
	string pass="user123";
string  password;
	cout<<"<<----------log in to the program-------->>   "<<endl;
	cout<<" <<--------Please enter your username------>>   "<<endl;
	cin>>username;
	cout<<"   <<<--------Welcome ***"<< username<<"***Please enter your password------>>>"<<endl;
	s:
	cin>>password;
	if(password== pass)
	{
		cout<<"You have been logged in successfully..."<<endl;
	}
else{
	cout<<"The password is incorrect, try again"<<endl;
	goto s ;
}}
	passenger* first= NULL;
	void addpassenger(string name,int train_id, int Ticketnumber,string from,string to)
	{	passenger* newpassenger,*last;
	 newpassenger=new passenger;
	newpassenger-> name= name;
	newpassenger->train_id=train_id;
	newpassenger->Ticketnumber=Ticketnumber;
	newpassenger->from=from;
	newpassenger->to=to;

	if(first==NULL)
	{
		first=newpassenger;
		newpassenger->next=NULL;
		
	}
	else
	{
		passenger*last=first;
			while(last->next!=NULL)
		{
			last=last->next;
		}
		last->next=newpassenger;
	newpassenger->next=NULL;
	}
	
	cout<<"passenger added successfuly"<<endl;
}
	void displaypassenger()
	{
			passenger* court_passenger;
		if( first==NULL)
		{
			cout<<"There are no trains available!";
		}
		else
		{
	passenger*	court_passenge = first;
				cout<<"List of available trips"<<endl;
		while(court_passenge!=NULL)
		{
				cout<<"==================================="<<endl;
				cout<<"||   name : "<<court_passenge->name<<endl;
				cout<<"              -----------"<<endl;
				cout<<"||  Ticketnumber : "<<court_passenge->Ticketnumber<<endl;
				cout<<"             -----------"<<endl;
				cout<<"||   train_id   : "<<court_passenge-> train_id <<endl;
				cout<<"              --------------"<<endl;
			    cout<<"||   from   : "<<court_passenge-> from <<endl;
			    cout<<"            ----------"<<endl;
			   	cout<<"||   to  : "<<court_passenge-> to <<endl;
				cout<<"============================================"<<endl;
		court_passenge=court_passenge->next;}		
		}	
	}
void searchPassenger(int Ticketnumber) {
	
    passenger* k = first;
    while (k != NULL) {
        if (k->Ticketnumber == Ticketnumber) {
            cout<<"<<    Traveler information   >> "<<endl;
				cout<<"==================================="<<endl;
				cout<<"||   name : "<<k->name<<endl;
				cout<<"              -----------"<<endl;
				cout<<"||  Ticketnumber : "<<k->Ticketnumber<<endl;
				cout<<"             -----------"<<endl;
				cout<<"||   train_id   : "<<k-> train_id <<endl;
				cout<<"              --------------"<<endl;
			    cout<<"||   from   : "<<k-> from <<endl;
			    cout<<"            ----------"<<endl;
			   	cout<<"||   to  : "<<k-> to <<endl;
				cout<<"============================================"<<endl;
				return;}
				 k = k->next;
        }
    cout<<"no pasenher available"<<endl;
}
void deletepassenger (int Ticketnumber )
{ if (first==NULL) {
            cout << "list empty!" << endl;
            return;
    }
        if (first->Ticketnumber == Ticketnumber) {
         passenger*temp = first;
            first= first->next;
            delete temp;
            cout << "deleted successfuly!" << endl;
            return;
        }
        passenger* temp =first;
        while (temp->next && temp->next->Ticketnumber != Ticketnumber) {
            temp = temp->next;
        }
        if (temp->next) {
            passenger* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "deleted successfuly!" << endl;
        } else {
            cout << "no passenger found!" << endl;
        }}
void Modificationofpassengers(int Ticketnumber)
{	
	if(Ticketnumber==Ticketnumber)
	{
	searchPassenger( Ticketnumber);
	deletepassenger ( Ticketnumber);
		string name;int train_id;int Ticketnumber;string from;string to;
			cout<<"<---enter new passenger information---->>\n";
			  		for(int i=0;i<1;i++)
			  	{	
		  cout<<"---enter the name--"<<i+1<<":";
			  	cin>>name;
			  	cout<<"--enter the  train_id--"<<i+1<<":";
			  	cin>>train_id;
			  	cout<<"---enter the Ticket number--"<<i+1<<":";
			  	cin>>Ticketnumber;
			  	cout<<"--enter from--"<<i+1<<":";
			  	cin>>from;
			  	cout<<"--enter to--"<<i+1<<":";
			  	cin>>to;}
				  addpassenger(name, train_id, Ticketnumber,from,to);	
}}
main()	
{up:
system("color 05");
passenger*first=NULL;
train*head=NULL;
int choice;

cout<<"    <<<-----------Welcome to the train  -nhn- station---------->>>"<<endl;
cout<<" 1) admin login  "<<endl;
cout<<"2) User login  "<<endl;
cout<<"3)   exit!  "<<endl;
cin>>choice;
if(choice==1)
{
	admin_mode();
}
else 
if(choice==2)
{
	user_mode();
}
else
if(choice==3)
{
cout<<"exit!";
return  0;}
int ch;
do{
	if(choice==1)
	{ in:
			cout<<" **admin list**"<<endl;				
			cout<<"press\t1)add train\n2)delete train\n3) displaytrains\n4)return to menu\n5)exit\n";
			cin>>ch;
			switch(ch){
			case 1:{
			int train_id;string from;string to;string departure;	string arrival;int passenger_count;long  price;
		 	int newtrain;	addtrain(101,"Aden","Sanaa","5:30pm","7:30pm",50,40000);
addtrain(102,"Aden","Hadhramaut","6:30pm","9:30pm",50,50000);
addtrain(103,"Sanaa","Saudi Arabia","11:30Pm","4:30PM",50,40000);
		 	cout<<"<----train to be added----"<<endl;
		 	cin>>newtrain;
		 	for(int i=0;i<newtrain;i++)
		 	{
	cout<<" entertrain_id ::";
	cin>>train_id;
	cout<<"    <<" <<train_id<<">> "<<endl;
	cout<<"  enter  from:: ";
	cin>> from;
	cout<<"    <<  " <<from<<" >>"<<endl;
	cout<<"enter to::";
    cin>>to;
	cout<<"    << " <<to<<"  >>"<<endl;
	cout<<"enter departure::";
	cin>>departure;
	cout<<"   <<" <<departure<<"  >>"<<endl;
	cout<<"enter arrival::";
	cin>>arrival;
	cout<<"    <<" <<arrival<<"  >>"<<endl;
	cout<<"enter passenger_count::";
	cin>>passenger_count;
	cout<<"    <<" <<passenger_count<<"  >>"<<endl;
	cout<<" enter  price::";
	cin>> price;
	cout<<"    <<" <<price<<"  >>"<<endl;
    addtrain( train_id, from, to, departure, arrival, passenger_count, price);
    }
    goto in;
	break;
	}
	case 2:{
	int train_id ;
    cout<<"Enter the number of the train you want to delete\n";
    cin>>train_id ;
    deleteTrain(train_id );
    displaytrains();
	break;}
	case 3:{
	 displaytrains();
		break;}
	case 4:{
		goto up;
		break;}
	case 5:{
	cout<<"exit";
	break;
										
	default:
	cout<<"Incorrect option, try again ";
}}
}
if(choice==2)
{
		cout<<"       **User list**     " <<endl;
		cout<<"        -------------    "<<endl;
		s:
cout<<"press:\n 1)see available trips\n2)add passenger\n";
cout<<"3)inquire ticket\n4)delete\n5)delete and add ticket\n6)return main\n";
cin>>ch;
switch(ch){
	case 1:{
		cout<<"    <<----------View available trips-------->>   "  <<endl;

		  		displaytrains();
		  		cout<<endl;
		break;}
		case 2:{int newpassenger;
			  	cout<<"       <<-----Please enter your information----->>"<<endl;
			  	cout<<"   enter number of passengers  "<<endl;
			  	cin>>newpassenger;
			  	string name;int train_id;int Ticketnumber;string from;string to;
			  		for(int i=0;i<newpassenger;i++)
			  	{
				  cout<<"---enter the name--"<<i+1<<":";
				  cin.ignore();
			  	getline(cin,name);
			  	cout<<"--enter the  train_id--"<<i+1<<":";
			  	cin>>train_id;
			  	cout<<"---enter the Ticket number--"<<i+1<<":";
			  	cin>>Ticketnumber;
			  	cout<<"--from--"<<i+1<<":";
			  	cin.ignore();
			  	getline(cin,from);
			  	cout<<"--to--"<<i+1<<":";
			  	cin.ignore();
			  	getline(cin,to);
				  addpassenger(name, train_id, Ticketnumber,from,to);
				 passenger* newpassenger=new passenger;
				  displaypassenger();}
				  break;}
			case 3:{
				int searchnumber;
		     cout<<"<<--------Enter the ticket number of passnger \n";
		     cin>>searchnumber;
			searchPassenger(searchnumber);    
			goto s;
			break;}
			case 4:{
			int ticketnumber;
			cout<<"<<-------Enter the ticket number you wish to delete------>>"<<endl;
			cin>>ticketnumber;
		deletepassenger( ticketnumber);
			displaypassenger();
			goto s;
			break;}
			case 5:{ int Ticketnumber;
			cout<<"<-----enter Ticketnumber------>>";
			cin>>Ticketnumber;
				Modificationofpassengers( Ticketnumber);
				  goto s;
				break;}
		
			case 6:{
				goto up;
				break;
			}
			case 7:{
				cout<<"exit";
				break;
			}
				default:
			cout<<"Incorrect option, try again.....! ";		
			}}
			else
			{
			}}	while(ch!=7&&ch!=5);
}


