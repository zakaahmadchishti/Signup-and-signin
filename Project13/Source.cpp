#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class design;
class signup;
class bank;
bool maincontrol(string userchoice);


class design
{
public:
	void maindesign() { cout << "1. Sign in" << endl; cout << "2. Sign up" << endl; cout << "3. Total Registered users" << endl; }
	void username() { cout << "Enter Username :"; }
	void passsword() { cout << "Enter Password :"; }
	void conformpasssword() { cout << "Enter Password Again :"; }
	void fullname() { cout << "Enter Full Name :"; }
	void fullnamewe() { cout << "Enter Name we say :"; }
	void address() { cout << "Enter Address :"; }
	void balancecheck() { cout << "Your Current Balance (R.S): "; }
	void accountnumber() { cout << "Your Account Number :"; }
	void transationamount() { cout << "Transatation amount: "; }
	void menu()
	{
		cout << "1. Balance Check" << endl;
		cout << "2. Transation" << endl;
		cout << "3. History" << endl;
		cout << "0. Log out" << endl;
	}

};





design d;













string user;


class bank
{
	int balance;

public:

	bool bankmain()
	{
		while (input() == true)
		{
			autocheck();
			d.menu();
			input();
		}


		return input();
	}

	bool input()
	{
		string choice;
		cin >> choice;
		if (choice == "1")
		{
			return balancecheck();
		}
		else if (choice == "2")
		{
			return transation();
		}
		else if (choice == "3")
		{
			return history();
		}
		else if (choice == "0")
		{
			return logout();
		}
	}



	bool autocheck()
	{
		fstream dfile;
		string line;
		dfile.open(user + ".txt", ios::out | ios::in | ios::app | ios::binary);
		int u = 0;
		while (!dfile.eof())
		{
			getline(dfile, line);
		}
		balance = atoi(line.c_str());
		return true;
	}
	bool balancecheck()
	{
		system("cls");
		cout << "Dear " << user << endl;
		cout << "your Current Balance :" << balance << endl;
		return true;
	}




	/////////////////////////////////////////////////////////////////////////////////////Transatition

	bool transation()
	{
		string suser;
		autocheck();
		cout << "Destination" << endl;
		d.username();
		cin >> suser;
		string user; char al, a;
		for (int i = 0; i < suser.size(); i++)
		{
			al = suser[i];
			a = toupper(al);
			user += a;
		}
		suser = user;

		fstream kfile; int offset; bool suserstatus = false;
		kfile.open("name.txt", ios::out | ios::in | ios::app | ios::binary);
		string line;
		while (!kfile.eof())
		{
			getline(kfile, line);

			if ((offset = line.find(user, 0)) != string::npos)
			{
				suserstatus = true;
			}
		}

		if (suserstatus == true)
		{
			fstream gfile;
			gfile.open(suser + ".txt", ios::out | ios::in | ios::app | ios::binary);
			while (!gfile.eof())
			{
				getline(gfile, line);
			}
			int addinthis; int amount;
			addinthis = atoi(line.c_str());
			cout << "Enter Tansfer Amount :";
			cin >> amount;
			if (amount <= balance)
			{
				addinthis = addinthis + amount;
				balance = balance - amount;
				fstream jfile;
				jfile.open(suser + ".txt", ios::app | ios::in | ios::out);
				jfile << endl << addinthis;
				jfile.close();
				fstream kfile;
				kfile.open(user + ".txt", ios::app | ios::in | ios::out);
				kfile << endl << balance;
				cout << "Sussfully Transatition completed (Admin: Zaka Ahmed Chishti)" << endl;
				cout << "Your Money Totally safe " << endl;
				return true;
			}

			else
			{
				cout << "low balance" << endl;
				cout << "Unusal Actions" << endl;
			}

		}
		else
		{
			cout << "User not found !" << endl;
			bank k;
			k.transation();
		}
	}


	struct userdata
	{
		userdata *link;
		string data;
	}*first, *last;



	bool history()
	{
		fstream dfile;
		dfile.open(user + ".txt", ios::out | ios::in | ios::app | ios::binary);
		string line; int a = 0;
		while (!dfile.eof())
		{
			getline(dfile, line);
			a++;

			if (a >= 3)
			{
				userdata *p = new userdata;
				p->data = line;
				p->link = NULL;
				if (first == NULL)
				{
					cout << "*****************************" << endl;
					first = p;
					last = p;
				}
				else
				{

					last->link = p;
					last = p;
				}
			}
		}

		userdata *q;
		q = first;
		while (q != NULL)
		{
			cout << endl << q->data << endl;
			q = q->link;
		}
		cout << "******************************" << endl;
		return true;
	}


	bool logout()
	{
		return false;
	}




};




































//////////////////////////////////////////////////////////////////////////////////////Sign up

class signup
{
	string username;

public:
	void signupmain()
	{
		signupenterdata();
		if (symbolcheckusername() == true)
		{
			capitalusername();
			if (check() == true)
			{
				password();


			}
			else
				cout << "Enter user name error" << endl;
			signupmain();
		}
		else
			signupmain();

	}




	//////////////////////////////////////////////////////////////////////////////////username detailing
	string signupenterdata()
	{
		d.username();
		cin >> username;
		return username;
	}

	bool symbolcheckusername()
	{

		bool b = true;
		char albatichalder;
		for (int i = 0; i < username.size(); i++)
		{
			albatichalder = username[i];// pick letter from string one by one
			if (albatichalder == '!' || albatichalder == '@' || albatichalder == '#' || albatichalder == '$' || albatichalder == '%' || albatichalder == '^' || albatichalder == '&' || albatichalder == '*' || albatichalder == '(' || albatichalder == ')' || albatichalder == '+' || albatichalder == '=' || albatichalder == ';' || albatichalder == ':' || albatichalder == '<' || albatichalder == '>' || albatichalder == ',' || albatichalder == '?' || albatichalder == '/' || albatichalder == ' ')
			{
				cout << "User Don't consist of Sysmbols ! Error " << endl;
				cout << "Again !" << endl;
				b = false;
			}
		}
		return b;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////capital signup
	void capitalusername()
	{

		int y = username.size(); char albatichalder, a; string user;
		for (int i = 0; i < y; i++)
		{
			albatichalder = username[i];
			a = toupper(albatichalder);
			user += a;
		}
		username = user;
	}
	bool check()
	{
		fstream Myfile;
		string line;
		int offset;
		Myfile.open("name.txt", ios::out | ios::in | ios::app | ios::binary);
		while (!Myfile.eof())
		{
			getline(Myfile, line);

			if ((offset = line.find(username, 0)) != string::npos)
			{
				return false;
			}
		}
		return true;
	}

	/////////////////////////////////////////////////////////////////////////////////////password detailded

	void password()
	{
		d.passsword();
		string pass, passa;
		cin >> pass;
		d.conformpasssword();
		cin >> passa;
		if (pass == passa)
		{
			ofstream hfile;
			hfile.open("name.txt", ios::app | ios::in | ios::out);
			hfile << username << endl;
			ofstream gfile(username + ".txt");
			gfile << username << endl;
			gfile << pass << endl;
			gfile << "500";
		}
		else
		{
			cout << "Both password not Matched Please Re-Enter" << endl;
			password();
		}
		cout << "Sussfully Sign-up process Completed Now Log In " << endl;


	}



};

bank b;
signup s;

////////////////////////////////////////////////////////////////////////////////////////////////login


class login
{
	string username;

public:
	void loginmain()
	{
		enterlogin();
		capitalusername();
		if (finduser() == true)
		{
			if (password() != true)
			{
				cout << "Enter Again!" << endl;
				loginmain();
			}
			else
			{
				forward_username();
				while (b.bankmain() == true)
				{

				}
			}
		}
		else
		{
			cout << "Username not find" << endl;
			loginmain();
		}
	}

	void enterlogin()
	{
		d.username();
		cin >> username;
	}


	void capitalusername()
	{

		int y = username.size(); char albatichalder, a; string user;
		for (int i = 0; i < y; i++)
		{
			albatichalder = username[i];
			a = toupper(albatichalder);
			user += a;
		}
		username = user;
	}




	bool finduser()
	{
		fstream Myfile; string line; int offset;
		Myfile.open("name.txt", ios::out | ios::in | ios::app | ios::binary);
		while (!Myfile.eof())
		{
			getline(Myfile, line);

			if ((offset = line.find(username, 0)) != string::npos)
			{
				return true;
			}
		}

		return false;
	}
	//////////////////////////////////////////////////////////////////////////////////password-signin
	bool password()
	{
		d.passsword(); string password;
		cin >> password; string lina; int off;
		fstream gfile;
		gfile.open(username + ".txt", ios::out | ios::in | ios::app | ios::binary);
		while (!gfile.eof())
		{
			getline(gfile, lina);
			if ((off = lina.find(password, 0)) != string::npos)
			{
				cout << "Sussfully login !" << endl;
				return true;
			}

		}
		return false;

	}

	void forward_username()
	{
		user = username;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////

};

login l;



class addon
{

public:
	struct user
	{
		user *link;
		string name;
	}*first, *last;

	struct revenu
	{
		revenu *link;
		int money;

	}*first2, *last2;






	void totalrevenue()
	{

		fstream Myfile; string line; int offset; user *p;
		Myfile.open("name.txt", ios::out | ios::in | ios::app | ios::binary);
		while (!Myfile.eof())
		{

			getline(Myfile, line);
			p = new user;
			p->name = line;
			p->link = NULL;
			if (first == NULL)
			{
				first = p;
				last = p;
			}
			else
			{
				last->link = p;
				last = p;
			}
		}
	}


	void totalrevenueb()
	{

		user *q = first; string line;
		cout << "******************************" << endl;
		while (q != NULL)
		{

			cout << q->name << endl;

			q = q->link;
		}
		cout << "******************************" << endl;
	}


};



























addon a;






















bool maincontrol(string userchoice)
{

	if (userchoice == "1")
	{
		l.loginmain();

	}
	else if (userchoice == "2")
	{
		s.signupmain();
	}
	else if (userchoice == "3")
	{
		a.totalrevenue();
		a.totalrevenueb();
	}
	else
	{
		cout << "Choice not Exist! Enter Again" << endl;
		return false;
	}
}




void main()
{

	d.maindesign();
	string userchoice;
	cin >> userchoice;
	maincontrol(userchoice);


	main();
	system("pause");
}









