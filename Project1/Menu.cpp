#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::firstM()
{
	ConsoleCursorVisible(false, 100);
	char ch;
	string str[] = { "Sign In","Sign Up" };

	int activeMenu = 0;


	


	system("CLS");
	for (int j=1;j>0;) {
		int x = 50, y = 13;
		GoToXY(x, y);

		for (int i = 0; i < size(str); i++) {
			if (i == activeMenu)SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
			else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			GoToXY(x, y++);
			cout << str[i] << endl;
		}
		cout << _getch() << endl;
		switch (_getch()) {
		case 27:break;
		case 72:
			if(activeMenu>0)--activeMenu;
			break;
		case 80:
			if (activeMenu < size(str))++activeMenu;
			break;
		case 13:j=-1 ;
			break;
		}
	}
	system("CLS");
	if (activeMenu == 1) {
		string a, b, c, d;
		cout << "Hello new user!!!\n Enter your telephone number: "; cin >> a;
		cout << "Okay. What is your name: "; cin >> b;
		cout << "YOur addresse: "; cin >> c;
		cout << "Create your password: "; cin >> d;
		User* A=new User(b,a,c,d);
		base.push_back(A);
		(* A).SignUp();
		secondM(*A);
	}
	else if (activeMenu == 0) {
		string p, n;
		User A;
		cout << "Enter number: "; cin >> n;
		cout << "\nEnter password: "; cin >> p;
		for (ind = base.begin(); ind != base.end(); ind++) {
			if ((*ind)->getNumber() == n) {

				if ((*ind)->SignIn(n, p))secondM(A);
				else firstM();
			}
		}
		if (ind == base.end()) {
			cout << "Wrong number";
			firstM();
		}
	}
}

void Menu::secondM(User A)
{
	ConsoleCursorVisible(false, 100);
	char ch;
	string str[] = { "TopUp","WithDraw","Donate","Create card","Delete card","Buy/Sold currency","Credit","Deposit","CashBack settings","Insurance","Upgrade","Show info","ChangePin"};

	int activeMenu = 0;





	system("CLS");
	for (int j = 1; j > 0;) {
		int x = 50, y = 13;
		GoToXY(x, y);

		for (int i = 0; i < size(str); i++) {
			if (i == activeMenu)SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
			else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			GoToXY(x, y++);
			cout << str[i] << endl;
		}
		cout << _getch() << endl;
		switch (_getch()) {
		case 27:firstM();
		case 72:
			if (activeMenu > 0)--activeMenu;
			break;
		case 80:
			if (activeMenu < size(str))++activeMenu;
			break;
		case 13:j = -1;
			break;
		}
	}
	system("CLS");
	if (activeMenu == 0) {
		A.Top();
		system("pause");
		secondM(A);
	}
	else if (activeMenu == 1) {
		A.With();
		system("pause");
		secondM(A);
	}
	else if (activeMenu == 2) {
		A.Don();
		system("pause");
		secondM(A);
	}
	else if (activeMenu == 3) {
		A.Creat();
		system("pause");
		secondM(A);
	}
	else if (activeMenu == 4) {
		A.DEl();
		system("pause");
		secondM(A);
	}
	else if (activeMenu == 5) {
		cout << "Dollar\tEuro";
		if (_getch() == 77)A.EU();
		else if (_getch() == 75)A.USA();
		system("pause");
		secondM(A);
	}
	else if (activeMenu == 6) {
		A.Credit();
		system("pause");
		secondM(A);
	}
	else if (activeMenu == 7) {
		A.Deposit();
		system("pause");
		secondM(A);
	}
	else if (activeMenu == 8) {
		A.cashBack();
		system("pause");
		secondM(A);
	}
	else if (activeMenu == 9) {
		A.Ins();
		system("pause");
		secondM(A);
	}
	else if (activeMenu == 10) {
		A.Upgrade();
		system("pause");
		secondM(A);
	}
	else if (activeMenu == 11) {
		A.show();
		system("pause");
		secondM(A);
	}
	else if (activeMenu == 12) {
		A.ChangeP();
		system("pause");
		secondM(A);
	}
}


