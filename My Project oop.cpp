#include <iostream>
using namespace std;

class Person{
	public:
	string name;
	string ID;
	string address;
	double balance;
	int contact;
};

class Bank{
	private:
		
    Person person[100];
	int	Total;
	string id;

	
	public:
	Bank(){
		Total = 0;
	}
	
	void choice();
	void PerData();
	void Show();
	void Update();
	void Transictions();
	void Delete();
	
};

int main(){
	Bank bank;
	bank.choice();
	
	return 0;
}

void Bank::choice(){
	start:
	int input;
	while (true){
		
	cout<<"\n*****WELCOME TO BANK MANAGMENT SYSTEM*****"<<endl;
	cout<<endl;
	cout<<"Please enter your choice"<<endl;
	cout<<endl;
	cout<<"Press 1 for creat new account"<<endl;
	cout<<"Press 2 for show account list"<<endl;
	cout<<"Press 3 for update specific account"<<endl;
	cout<<"Press 4 for Transactions"<<endl;
	cout<<"Press 5 for Remove existing account"<<endl;
	cout<<"Press 6 to Exit"<<endl;
	
	cin>>input;
	cin.clear();
	cin.ignore(1000,'\n');
	system ("CLS");

	
	switch(input){
		
		case 1:
			Bank::PerData();
			break;
		
		case 2:
			if(Total == 0){
				cout<<"No Data Avalible"<<endl;
			}
			else{
				Bank::Show();
			}
			break;
			
			case 3:
				if(Total == 0){
					cout<<"No Data Avalible"<<endl;;
				}
				else{
					Bank::Update();
				}
				break;
				
				case 4:
					if (Total == 0){
						cout<<"No Data Avalible"<<endl;
					}
			else {
				Bank::Transictions();
			}
			break;
			
			case 5:
				if(Total == 0){
					cout<<"No Data Avalible"<<endl;
				}
				else {
					Bank::Delete();
				}
				break;
				
				case 6:
					exit(0);
					break;
					
				default:
				cout<<"Invalid Entry"<<endl;
				break;
	}
	
	
}
}
void Bank::PerData(){
	
	cout<<"Please enter data for Coustomer "<<Total+1<<endl;
	cout<<"Please enter name: ";
	cin>>person[Total].name;
	cout<<"please enter ID: ";
	cin>>person[Total].ID;
	cout<<"Please enter contact: ";
	cin>>person[Total].contact;
	cout<<"please enter address: ";
	cin>>person[Total].address;
	cout<<"Please enter initial Balance: ";
	cin>>person[Total].balance;
	Total++;
	
	
}
void Bank::Show(){
	
	for(int i=0; i<Total; i++){
	cout<<"Data of coustomer "<<i+1<<endl;
	cout<<"Name: "<<person[i].name<<endl;
	cout<<"ID: "<<person[i].ID<<endl;
	cout<<"Contact: "<<person[i].contact<<endl;
	cout<<"Address: "<<person[i].address<<endl;
	cout<<"Balance: "<<person[i].balance<<endl;	
	
	}
	
}
void Bank::Update(){
	
	cout<<"Please enter the ID wher you want to make changes "<<endl;
	cin>>id;
	for(int i=0; i<Total; i++){
		
		if(id==person[i].ID){
			
	cout<<"Previous Data: "<<endl;
	cout<<"Name: "<<person[i].name<<endl;
	cout<<"ID: "<<person[i].ID<<endl;
	cout<<"Contact: "<<person[i].contact<<endl;
	cout<<"Address: "<<person[i].address<<endl;
	cout<<"Balance: "<<person[i].balance<<endl;
			
			cout<<"Enter New Data: "<<endl;
            cout<<"Please enter name: ";
	        cin>>person[i].name;
	        cout<<"please enter ID: ";
	        cin>>person[i].ID;
	        cout<<"Please enter contact: ";
	        cin>>person[i].contact;
	        cout<<"please enter address: ";
	        cin>>person[i].address;
	        cout<<"Please enter initial Balance: ";
	        cin>>person[i].balance;
			
		}if(i==Total-1){
			cout<<"No Record Found "<<endl;
	}
}
}
void Bank::Transictions(){
	double cash;
	int input;
	cout<<"Please enter the ID where you want to make Transiction"<<endl;
	cin>>id;
	for(int i=0; i<Total; i++){
		
		if(id == person[i].ID){
			cout<<"Name: "<<person[i].name<<endl;
			cout<<"Address: "<<person[i].address<<endl;
			cout<<"Avalible Cash: "<<person[i].balance<<endl;
			again:
			cout<<"Press 1 for Deposit"<<endl;
			cout<<"Press 2 for Widtraw"<<endl;
			cin>>input;
			
			cin.clear();
	        cin.ignore(1000,'\n');
	        
			switch(input){
	        
				case 1:
					cout<<"Please enter Amount to Deposit: "<<endl;
					cin>>cash;
					if(cash > 0){
					person[i].balance += cash;
					cout<<"Amount been added your new balance is: "<<person[i].balance<<endl;
					}
					else {
						cout<<"Invalid Amount";
					}
					break;
					
					case 2:
						cout<<"Please enter Amount to Widtraw"<<endl;
						cin>>cash;
						if(cash > person[i].balance || cash < 0){
							cout<<"Your amount is just: "<<person[i].balance<<endl;
						}
						else {
							person[i].balance -= cash;
							cout<<"Widtraw Succesfull Remaining Balance: "<<person[i].balance<<endl;
						}
						break;
						default:
							cout<<"Invalid choice!"<<endl;
							goto again;
			}
			
			
			
		}else{
			cout<<"No Such Record Found "<<endl;
		}
	}
}
void Bank::Delete(){
	int input;
	cout<<"Press 1 to delete specific Account "<<endl;
	cout<<"Press 2 to clear all Data "<<endl;
	cin>>input;
	
	switch (input){
		
		case 1:
			cout<<"Please enter ID to delete the account: ";
			cin>>id;
			for(int i=0; i<Total; i++){
				
				if(id == person[i].ID){
					
					for(int j=i; j<Total; j++){
						
						person[j].name = person[j+1].name;
						person[j].address = person[j+1].address;
						person[j].contact = person[j+1].contact;
						person[j].ID = person[j+1].ID;
						person[j].balance = person[j+1].balance;
						Total--;
						cout<<"Your Required is Deleted "<<endl;
						break;
					}
				}else{
					cout<<"No Such Record Found "<<endl;
				}
			}
			
			case 2:
				Total = 0;
				cout<<"All Record Deleted !";
				break;
				
				default:
					cout<<"Invalid Input "<<endl;
					break;
	}
	
}



