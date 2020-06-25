#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <array>
#include <vector>

using namespace std;

// announcement of function

int main();
void main_menu_interface();
void main_menu_switch();
void user_menu_switch();
void user_interface();
void admin_interface();
void user_buy();
void user_balance();
void user_interface();
void operator_interface();
void tickets_info();
void cash_info();
void ticket_info_switch();
void cash_info_switch();
void print_tickets_info();
void print_cash_info();
void add_user();
void is_user_print_ticket();
void print_ticket();
void change_fare();
void go_back_cash();

// GLOBAL VARIABLES & ARRAYS

int c_o_t;

int sum;

string acc;

int bal;

int urr;

int count_of_tickets = 0;

float rate[] = { 8, 7.5, 7.2 };

vector<string> id_user = { "Артеменко В.", "Маудза О.", "Паплiнський В.", "Летич А.", "Жидков Д.", "Кисiль Т.М." };

int balance[] = { 898, 315, 391, 213, 781, 1251 };

int c_bal = sizeof(balance)/sizeof(balance[0]);

int sum_bal;

time_t seconds = time(NULL);
tm* timeinfo = localtime(&seconds);

int vneseno = 5000;
int reshta = 1305;

// FILES TO PRINT

void print_sys() {
	ofstream sys_prt("D:\\system_test.txt");
	sys_prt << "	  	" << " ---------------------------------- " << endl;
	sys_prt << "		   Поточна характеристика системи: " << endl;
	sys_prt << "	  	" << " ---------------------------------- " << endl << endl;
	sys_prt << "	  		" << " ------------------ " << endl;
	sys_prt << "			  CPU - Процесор: " << endl;
	sys_prt << "	  		" << " ------------------ " << endl << endl;
	sys_prt << "	Поточна швидкiсть: 2.71 ГГц	" << endl;
	sys_prt << "	Кiлькiсть сокетiв: 1	" << endl;
	sys_prt << "	Ядра: 2	" << endl;
	sys_prt << "	Логiчнi процеси: 4	" << endl;
	sys_prt << "	Вiзуалiзацiя: увiмкнено	" << endl;
	sys_prt << "	Кеш L1: 128 kB	" << endl;
	sys_prt << "	Кеш L2: 512 kB	" << endl;
	sys_prt << "	Кеш L3: 3.0 MB	" << endl;
	sys_prt << "	  	  " << " -------------------------- " << endl;
	sys_prt << "		    RAM - Оперативна пам'ять: " << endl;
	sys_prt << "	  	  " << " -------------------------- " << endl << endl;
	sys_prt << "	Загальна швидкiсть: 2133 MHz	" << endl;
	sys_prt << "	Форм-фактор: SODIMM	" << endl;
	sys_prt << "	Зарезервовано: 90.8 Mb	" << endl;
	sys_prt << "	Використано на даний момент: 3.7/64 Gb	" << endl;
	sys_prt << "	  		" << " ------------------ " << endl;
	sys_prt << "			  Drive C: - Диск С: " << endl;
	sys_prt << "	  		" << " ------------------ " << endl << endl;
	sys_prt << "	Ємнiсть: 512 Gb	" << endl;
	sys_prt << "	Системний: Yes	" << endl;
	sys_prt << "	Файл пiдкачки: Увiмкнено	" << endl;
	sys_prt << "	Швидкiсть зчитування даних: 302 kb/s	" << endl;
	sys_prt << "	Швидкiсть запису даних: 61.6 kb/s	" << endl << endl;

	if (sys_prt.is_open())
		cout << endl << "Файл збережено!" << endl;
	else
		cout << endl << "Неможливо зберегти файл!" << endl;
}

void print_network() {
	ofstream netw_prt("D:\\network_test.txt");
	netw_prt << "	  	" << " --------------------------------------------- " << endl;
	netw_prt << "		   Поточна характеристика пiдєднаної мережi: " << endl;
	netw_prt << "	  	" << " --------------------------------------------- " << endl << endl;
	netw_prt << "	Швидкiсть з'єднання: 320 kb/s	" << endl;
	netw_prt << "	Пропускна здатнiсть: 24	" << endl;
	netw_prt << "	Вiдпралення: 4 mb/s	" << endl;
	netw_prt << "	Отримання: 120 mb/s	" << endl;
	netw_prt << "	Адаптер: Ethernet	" << endl;
	netw_prt << "	IPv4 adress: 192.168.1.1	" << endl << endl;
	if (netw_prt.is_open())
		cout << endl << "Файл збережено!" << endl;
	else
		cout << endl << "Неможливо зберегти файл!" << endl;

}

void print_ticket() {
	ofstream ticket_print("D:\\ticket_0.txt");
	// c_o_t - кiлькiсть квиткiв
	// sum - сума грошей
	// acc - аккаунт

	ticket_print << "------------------------------" << endl;
	ticket_print << "| КП Київський метрополiтен  |" << endl;
	ticket_print << "------------------------------" << endl;
	ticket_print << "|         Квитанцiя          |" << endl;
	ticket_print << "------------------------------" << endl;
	ticket_print << " " << asctime(timeinfo) << endl << endl;
	ticket_print << "Акаунт: " << acc << endl;
	ticket_print << "Ви придбали " << c_o_t << " квиткiв" << endl << endl;
	ticket_print << "Загальна сума покупки: " << sum << " грн." << endl << endl;
	ticket_print << "Дякуємо за вiзит." << endl << "Щасливої поїздки!" << endl;

	if (ticket_print.is_open())
		cout << endl << "Файл збережено!" << endl;
	else
		cout << endl << "Неможливо зберегти файл!" << endl;
};

void print_tickets_info() {
	ofstream tick_prt("D:\\tickets_info.txt");
	tick_prt << "	  	 ------------------------------------------ " << endl;
	tick_prt << "		   Загальна iнформацiя про купленi квитки: " << endl;
	tick_prt << "	  	 ------------------------------------------ " << endl << endl;
	tick_prt << "		" << endl;
	tick_prt << "	Кiлькiсть проданих квиткiв: 	" << c_o_t << endl;
	if (tick_prt.is_open())
		cout << endl << "Файл збережено!" << endl << endl;
	else
		cout << endl << "Неможливо зберегти файл!" << endl << endl;
};

void print_cash_info() {
	ofstream cash_prt("D:\\cash_info.txt");
	cash_prt << "	  	 ---------------------------------------------- " << endl;
	cash_prt << "		   Загальна iнформацiя про наявнiсть готiвки: " << endl;
	cash_prt << "	  	 ---------------------------------------------- " << endl << endl;
	cash_prt << "		" << endl;
	cash_prt << "	Внесено персоналом готiвки в термiнал: " << vneseno << " грн." << endl;
	cash_prt << "	Внесено користувачами готiвки в термiнал: " << sum_bal << " грн." << endl;
	cash_prt << "	Видано як решта: " << reshta << " грн." << endl << endl;
	if (cash_prt.is_open())
		cout << endl << "Файл збережено!" << endl << endl;
	else
		cout << endl << "Неможливо зберегти файл!" << endl << endl;
};

// TESTS OF SYSTEM & NETWORK

void sys_test() {
	system("cls");
	cout << "	  	" << " ---------------------------------- " << endl;
	cout << "		   Поточна характеристика системи: " << endl;
	cout << "	  	" << " ---------------------------------- " << endl << endl;
	cout << "	  		" << " ------------------ " << endl;
	cout << "			  CPU - Процесор: " << endl;
	cout << "	  		" << " ------------------ " << endl << endl;
	cout << "	Поточна швидкiсть: 2.71 ГГц	" << endl;
	cout << "	Кiлькiсть сокетiв: 1	" << endl;
	cout << "	Ядра: 2	" << endl;
	cout << "	Логiчнi процеси: 4	" << endl;
	cout << "	Вiзуалiзацiя: увiмкнено	" << endl;
	cout << "	Кеш L1: 128 kB	" << endl;
	cout << "	Кеш L2: 512 kB	" << endl;
	cout << "	Кеш L3: 3.0 MB	" << endl;
	cout << "	  	  " << " -------------------------- " << endl;
	cout << "		    RAM - Оперативна пам'ять: " << endl;
	cout << "	  	  " << " -------------------------- " << endl << endl;
	cout << "	Загальна швидкiсть: 2133 MHz	" << endl;
	cout << "	Форм-фактор: SODIMM	" << endl;
	cout << "	Зарезервовано: 90.8 Mb	" << endl;
	cout << "	Використано на даний момент: 3.7/64 Gb	" << endl;
	cout << "	  		" << " ------------------ " << endl;
	cout << "			  Drive C: - Диск С: " << endl;
	cout << "	  		" << " ------------------ " << endl << endl;
	cout << "	Ємнiсть: 512 Gb	" << endl;
	cout << "	Системний: Yes	" << endl;
	cout << "	Файл пiдкачки: Увiмкнено	" << endl;
	cout << "	Швидкiсть зчитування даних: 302 kb/s	" << endl;
	cout << "	Швидкiсть запису даних: 61.6 kb/s	" << endl << endl;

	cout << "РОЗДРУКУВАТИ ДАНI ПРО СИСТЕМУ?" << endl << endl;
	cout << "1 - Так, 2 - Нi; Повернутися до попереднього меню" << endl << endl;
	int menu_answer = 0, again_menu = 0;
	bool var = true, var1 = true;
	do {
		cout << " >> ";
		cin >> menu_answer;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		switch (menu_answer)
		{
		case 1:
			print_sys();
			break;
		case 2:
			admin_interface();
			break;
		default:
			cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
		}
		if (menu_answer >= 1 && menu_answer <= 2) {
			var = false;
		}
	} while (var);
}

void network_test() {
	system("cls");
	cout << "	  	" << " --------------------------------------------- " << endl;
	cout << "		   Поточна характеристика пiдєднаної мережi: " << endl;
	cout << "	  	" << " --------------------------------------------- " << endl << endl;
	cout << "	Швидкiсть з'єднання: 320 kb/s	" << endl;
	cout << "	Пропускна здатнiсть: 24	" << endl;
	cout << "	Вiдпралення: 4 mb/s	" << endl;
	cout << "	Отримання: 120 mb/s	" << endl;
	cout << "	Адаптер: Ethernet	" << endl;
	cout << "	IPv4 adress: 192.168.1.1	" << endl << endl;

	cout << "РОЗДРУКУВАТИ ДАНI ПРО МЕРЕЖУ?" << endl << endl;
	cout << "1 - Так, 2 - Нi; Повернутися до попереднього меню" << endl << endl;
	int menu_answer = 0, again_menu = 0;
	bool var = true, var1 = true;
	do {
		cout << " >> ";
		cin >> menu_answer;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		switch (menu_answer)
		{
		case 1:
			print_network();
			break;
		case 2:
			admin_interface();
			break;
		default:
			cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
		}
		if (menu_answer >= 1 && menu_answer <= 2) {
			var = false;
		}
	} while (var);


}


// FOR OPERATOR

void tickets_info() {
	system("cls");
	cout << "	  	 ------------------------------------------ " << endl;
	cout << "		   Загальна iнформацiя про купленi квитки: " << endl;
	cout << "	  	 ------------------------------------------ " << endl << endl;
	cout << "		" << endl;
	cout << "	Кiлькiсть проданих квиткiв: 	" << c_o_t << endl << endl;

	ticket_info_switch();
};

void cash_info() {
	system("cls");
	for (int i = 0; i < 6; i++) {
		sum_bal += balance[i];
	}
	cout << "	  	 ---------------------------------------------- " << endl;
	cout << "		   Загальна iнформацiя про наявнiсть готiвки: " << endl;
	cout << "	  	 ---------------------------------------------- " << endl << endl;
	cout << "		" << endl;
	cout << "	Внесено персоналом готiвки в термiнал: " << vneseno << " грн." << endl;
	cout << "	Внесено користувачами готiвки в термiнал: " << sum_bal << " грн." << endl;
	cout << "	Видано як решта: " << reshta << " грн." << endl << endl;

	cash_info_switch();
}

void change_fare() {
	int num_t;
	float new_price_t;
	system("cls");
	cout << "	  	 --------------------------------------------------------------- " << endl;
	cout << "		   Щоб змiнити вартiсть квитка введiть його порядковий номер : " << endl;
	cout << "	  	 --------------------------------------------------------------- " << endl << endl;
	cout << " >> ";
	cin >> num_t;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		change_fare();
		return;
	}
	// ПРОЦЕДУРУ ПЕРЕВiРКИ ВiРНОСТi НОМЕРУ БУДЕ ДОДАНО ЗГОДОМ
	cout << endl;
	cout << "Зараз квитку пiд номером " << num_t << " назначена цiна " << rate[num_t] << " грн." << endl << endl;
	cout << "Введiть нову цiну: ";
	cin >> new_price_t;
	cout << endl;
	rate[num_t] = new_price_t;
	cout << "Цiну змiнено успiшно!" << endl << endl;
	cout << "Натиснiть 1 щоб повернутися до попереднього меню: " << endl;

	int menu_answer = 0, again_menu = 0;
	bool var = true, var1 = true;
	do {
		cout << " >> ";
		cin >> menu_answer;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		switch (menu_answer)
		{
		case 1:
			operator_interface();
		/*case 2:
			change_fare();*/
		default:
			cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
		}
		if (menu_answer >= 1 && menu_answer <= 1) {
			var = false;
		}
	} while (var);
}

// FOR USER

void add_user() {
	// НЕ ПРАЦЮЄ
	string add_nm;
	int add_bal;
	cout << "Введіть ім'я: ";
	cin >> add_nm;
	cout << endl;
	cout << "Введіть баланс: ";
	cin >> add_bal;
	cout << endl;
	id_user[c_bal+1] += add_nm;
	balance[c_bal+1] = add_bal;
}

void buy_again() {
	int menu_answer = 0, again_menu = 0;
	bool var = true, var1 = true;
	do {
		cout << " >> ";
		cin >> menu_answer;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		switch (menu_answer)
		{
		case 1:
			user_buy();
			break;
		case 2:
			main();
			break;
		default:
			cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
		}
		if (menu_answer >= 1 && menu_answer <= 2) {
			var = false;
		}
	} while (var);
}

void buy_1_ticket() {
	int cot1;
	int var = 1 * rate[0];
	if (bal >= var) {
		cot1 = 1;
		cout << "Куплено 1 квиток за " << var << " грн. Роздрукувати квитанцiю?" << endl;
		count_of_tickets += cot1;
		sum += var;
		c_o_t += cot1;
		bal -= var;
		cout << "1 - Так; 2 - Hi" << endl << endl;
		is_user_print_ticket();
		balance[urr] = bal;
		cout << endl << "Залишок на Вашому рахунку = " << bal << " грн." << endl << endl;
	}
	else {
		cout << "Недостатньо коштiв на рахунку!" << endl << endl;
	}
}

void buy_2_5_tickets() {
	int cot2;
	cout << "Введiть кiлькiсть квиткiв (2-9): " << endl;
	cin >> cot2;
	cout << endl;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		buy_2_5_tickets();
		return;
	}
	int var = cot2 * rate[1];
	if (bal >= var) {
		if (cot2 >= 2 && cot2 <= 9) {
			count_of_tickets += cot2;
			c_o_t += cot2;
			sum += var;
			bal -= var;
			cout << "Куплено " << cot2 << " квиткiв за " << var << " грн. Роздрукувати квитанцiю?" << endl;
			cout << "1 - Так; 2 - Hi" << endl << endl;
			is_user_print_ticket();
			balance[urr] = bal;
			cout << endl << "Залишок на Вашому рахунку = " << bal << " грн." << endl << endl;
		}
		else {
			cout << "Невiрна кiлькiсть! Введiть кiлькiсть вiд 2 до 9: " << endl;
			buy_2_5_tickets();
		}
	}
	else {
		cout << "Недостатньо коштiв на рахунку!" << endl << endl;
	}
};

void buy_10_more_tickets() {
	int cot3;
	cout << "Введiть кiлькiсть квиткiв (10+): " << endl;
	cin >> cot3;
	cout << endl;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		buy_10_more_tickets();
		return;
	}
	int var = cot3 * rate[2];
	if (bal >= var) {
		if (cot3 >= 10) {
			count_of_tickets += cot3;
			c_o_t += cot3;

			sum += var;
			bal -= var;
			cout << "Куплено " << cot3 << " квиткiв за " << var << " грн. Роздрукувати квитанцiю?" << endl;
			cout << "1 - Так; 2 - Hi" << endl << endl;
			is_user_print_ticket();
			balance[urr] = bal;
			cout << endl << "Залишок на Вашому рахунку = " << bal << " грн." << endl << endl;
		}
		else {
			cout << "Невiрна кiлькiсть! " << endl;
			buy_10_more_tickets();
		}
	}
	else {
		cout << "Недостатньо коштiв на рахунку!" << endl << endl;
	}
}

// SWITCHES

void is_user_print_ticket() {
	int menu_answer = 0, again_menu = 0;
	bool var = true, var1 = true;
	do {
		cout << " >> ";
		cin >> menu_answer;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		switch (menu_answer)
		{
		case 1:
			print_ticket();
			break;
		case 2:

			break;
		default:
			cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
		}
		if (menu_answer >= 1 && menu_answer <= 2) {
			var = false;
		}
	} while (var);
}

void user_buy_switch() {

	int menu_answer = 0, again_menu = 0;
	bool var = true, var1 = true;
	do {
		cout << " >> ";
		cin >> menu_answer;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		switch (menu_answer)
		{
		case 1:
			buy_1_ticket();
			cout << "Купити ще?" << endl;
			cout << "1 - Так; 2 - Hi, вийти до головного меню" << endl << endl;
			buy_again();
			break;
		case 2:
			buy_2_5_tickets();
			cout << "Купити ще?" << endl;
			cout << "1 - Так; 2 - Hi, вийти до головного меню" << endl << endl;
			buy_again();
			break;
		case 3:
			buy_10_more_tickets();
			cout << "Купити ще?" << endl;
			cout << "1 - Так; 2 - Hi, вийти до головного меню" << endl << endl;
			buy_again();
		case 4:
			user_interface();
			//user_menu_switch();
		default:
			cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
		}
		if (menu_answer >= 1 && menu_answer <= 4) {
			var = false;
		}
	} while (var);
};

void user_menu_switch() {


	int menu_answer = 0, again_menu = 0;
	bool var = true, var1 = true;
	do {
		cout << " >> ";
		cin >> menu_answer;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		switch (menu_answer)
		{
		case 1:
			
			user_buy();
			break;
		case 2:
			user_balance();
			break;
		case 3:
			cout << "Ця функцiя буде доступна у найближчих оновленнях програми. Чекайте!" << endl << endl;
			user_menu_switch();
			//add_user();
			break;
		case 4:
			main();
		default:
			cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
		}
		if (menu_answer >= 1 && menu_answer <= 3) {
			var = false;
		}
	} while (var);
}

void main_menu_switch() {

	system("color 06");

	int menu_answer = 0, again_menu = 0;
	bool var = true, var1 = true;
	do {
		cout << " >> ";
		cin >> menu_answer;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		switch (menu_answer)
		{
		case 1:
			user_interface();
			break;
		case 2:
			operator_interface();
			break;
		case 3:
			admin_interface();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
		}
		if (menu_answer >= 1 && menu_answer <= 3) {
			var = false;
		}
	} while (var);
}

void go_back_ticket() {
	cout << "Натиснiть 1 щоб повернутися до попереднього меню: " << endl << endl;
	int menu_answer = 0, again_menu = 0;
	bool var = true, var1 = true;
	do {
		cout << " >> ";
		cin >> menu_answer;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		switch (menu_answer)
		{
		case 1:
			operator_interface();
			break;
		default:
			cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
		}
		if (menu_answer >= 1 && menu_answer <= 2) {
			var = false;
		}
	} while (var);
}

void ticket_info_switch() {
	cout << "РОЗДРУКУВАТИ ДАНI ПРО КУПЛЕНI КВИТКИ?" << endl << endl;
	cout << "1 - Так, 2 - Нi; Повернутися до попереднього меню" << endl << endl;
	int menu_answer = 0, again_menu = 0;
	bool var = true, var1 = true;
	do {
		cout << " >> ";
		cin >> menu_answer;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		switch (menu_answer)
		{
		case 1:
			print_tickets_info();
			go_back_ticket();
			break;
		case 2:
			operator_interface();
			break;
		default:
			cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
		}
		if (menu_answer >= 1 && menu_answer <= 2) {
			var = false;
		}
	} while (var);
}

void go_back_cash() {
	cout << "Натиснiть 1 щоб повернутися до попереднього меню: " << endl << endl;
	int menu_answer = 0, again_menu = 0;
	bool var = true, var1 = true;
	do {
		cout << " >> ";
		cin >> menu_answer;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		switch (menu_answer)
		{
		case 1:
			operator_interface();
			break;
		default:
			cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
		}
		if (menu_answer >= 1 && menu_answer <= 2) {
			var = false;
		}
	} while (var);
}

void cash_info_switch() {
	cout << "РОЗДРУКУВАТИ ДАНI ПРО НАЯВНIСТЬ ГОТIВКИ?" << endl << endl;
	cout << "1 - Так, 2 - Нi; Повернутися до попереднього меню" << endl << endl;
	int menu_answer = 0, again_menu = 0;
	bool var = true, var1 = true;
	do {
		cout << " >> ";
		cin >> menu_answer;
		cout << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		switch (menu_answer)
		{
		case 1:
			print_cash_info();
			go_back_cash();
			break;
		case 2:
			operator_interface();
			break;
		default:
			cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
		}
		if (menu_answer >= 1 && menu_answer <= 2) {
			var = false;
		}
	} while (var);
}

void acc_sw() {
	int acc_idd;
	cout << "Введiть iдентифiкатор користувача: ";
	cin >> acc_idd;
	cout << endl;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		acc_sw();
		return;
	}
	if (acc_idd < c_bal) {
		acc = id_user[acc_idd];
		cout << "Вiтаю, " << id_user[acc_idd] << endl;
		bal = balance[acc_idd];
		cout << "Ваш баланс = " << bal << " грн." << endl;
		urr = acc_idd;
	}
	else {
		cout << "Такого користувача не iснує!" << endl << endl;
		acc_sw();
	}
}

// INTERFACES

// USER

void user_buy() {

	system("color 02");
	system("cls");
	acc_sw();
	cout << "	  	 --------------------------------------------------------- " << endl;
	cout << "		Виберiть кiлькiсть поїздок, на яку бажаєте придбати квиток: " << endl;
	cout << "	  	 --------------------------------------------------------- " << endl << endl;
	cout << "  -------------  -----------------  ------------------------  ------------------------------------ " << endl;
	cout << "  1)  1 поїздка  2)  2 - 9 поїздок  3)  10 та бiльше поїздок  4)  Повернутися до попереднього меню" << endl;
	cout << "  -------------  -----------------  ------------------------  ------------------------------------ " << endl << endl;

	user_buy_switch();
}

void user_balance() {

	system("color 06");
	system("cls");

	int usr_id;

	cout << "	------------------------------" << endl;
	cout << "	  Введiть свiй iдентифiкатор: " << endl;
	cout << "	------------------------------" << endl << endl;
	cout << " >> ";
	cin >> usr_id;
	cout << endl;
	cout << "Баланс користувача " << id_user[usr_id] << " = " << balance[usr_id] << " грн." << endl << endl;
	cout << " Натснiть 1 щоб повернутися до головного меню: " << endl;
	int menu_answer = 0, again_menu = 0;
	bool var = true, var1 = true;
	do {
		cout << " >> ";
		cin >> menu_answer;
		cout << endl;
		switch (menu_answer)
		{
		case 1:
			user_interface();
			break;
		default:
			cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
		}
		if (menu_answer >= 1 && menu_answer <= 1) {
			var = false;
		}
	} while (var);
}

void user_interface() {

	system("cls");
	cout << "	  	" << " --------------------------------- " << endl;
	cout << "			 Вiтаю, користувач!" << endl;
	cout << "	  	" << " --------------------------------- " << endl << endl;
	cout << "  ---------------------  ----------------------------  ------------------------   ---------------------------- " << endl;
	cout << "  1) - Придбати квиток	 2) - Дiзнатись баланс картки   3) - Додати користувача  4) - Вийти до головного меню" << endl;
	cout << "  ---------------------  ----------------------------  ------------------------   ---------------------------- " << endl << endl;

	user_menu_switch();
};

// OPERATOR

void operator_interface() {
	string operator_password;
	string opw = "oper";
	bool opwp = true;
	system("cls");
	do {
		cout << endl << "Введiть пароль оператора: ";
		cin >> operator_password;
		cout << endl;

		if (operator_password == opw) {
			system("cls");
			cout << "	  	 --------------------------------- " << endl;
			cout << "			 Вiтаю, операторе!" << endl;
			cout << "	  	 --------------------------------- " << endl << endl;
			cout << "  ---------------------------------------------  ---------------------------------------------------  ------------------------------  ----------------------------" << endl;
			cout << "  1) - Дiзнатися iнформацiю про проданi квитки    2) - Дiзнатися iнформацiю про готiвку в термiналi   3) - Змiнити вартiсть поїздок   4) - Вийти до головного меню" << endl;
			cout << "  ---------------------------------------------  ---------------------------------------------------  ------------------------------  ----------------------------" << endl << endl;

			int menu_answer = 0, again_menu = 0;
			bool var = true, var1 = true;
			do {
				cout << " >> ";
				cin >> menu_answer;
				cout << endl;
				switch (menu_answer)
				{
				case 1:
					tickets_info();
					break;
				case 2:
					cash_info();
					break;
				case 3:
					change_fare();
					break;
				case 4:
					main();
				/*case 5:
					add_user();*/
				default:
					cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
				}
				if (menu_answer >= 1 && menu_answer <= 4) {
					var = false;
				}
			} while (var);
		}
		else {
			cout << " Невiрний пароль! Перевiрте правильнiсть вводу. " << endl;
		}
		if (operator_password == opw) {
			opwp = false;
		}

	} while (opwp);
}

// ADMIN

void admin_interface() {
	string admin_password;
	string apw = "admin";
	bool apwp = true;
	system("cls");
	do {
		cout << endl << "Введiть пароль адмiнiстратора: ";
		cin >> admin_password;
		cout << endl;

		if (admin_password == apw) {
			system("cls");
			cout << "	  	" << " --------------------------------- " << endl;
			cout << "		   Вiтаю, адмiнiстраторе!" << endl;
			cout << "	  	" << " --------------------------------- " << endl << endl;
			cout << "" << "  -------------------------------- " << " ----------------------------- " << " ---------------------------- " << endl;
			cout << "" << "  1) - Тест продуктивностi системи" << "  2) - Тест з'єднання з мережею" << "  3) - Вийти до головного меню" << endl;
			cout << "" << "  -------------------------------- " << " ----------------------------- " << " ---------------------------- " << endl << endl;

			int menu_answer = 0, again_menu = 0;
			bool var = true, var1 = true;
			do {
				cout << " >> ";
				cin >> menu_answer;
				cout << endl;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				switch (menu_answer)
				{
				case 1:
					sys_test();
					break;
				case 2:
					network_test();
					break;
				case 3:
					main();
				default:
					cout << endl << "Невiрно вибраний " << menu_answer << "-й пункт!" << endl << endl;
				}
				if (menu_answer >= 1 && menu_answer <= 3) {
					var = false;
				}
			} while (var);
		}
		else {
			cout << " Невiрний пароль! " << endl;
		}
		if (admin_password == apw) {
			apwp = false;
		}

	} while (apwp);
}

//MENU

void main_menu_interface() {
	system("cls");
	system("color 06");

	cout << "	------------------------------------------------------------------ " << endl << endl;
	cout << "	|                  Головне меню системи PassWay -                 | " << endl << endl;
	cout << "	| система надшвидкої оплати проїзду в КП 'Київський метрополiтен' | " << endl << endl;
	cout << "	|      тут ви зможете придбати проїзний чи поповнити iснуючий     | " << endl << endl;
	cout << "	------------------------------------------------------------------ " << endl << endl << endl;
	cout << " ------------------------   ---------------------------   --------------------------------   ------------------------ " << endl << endl;
	cout << " | 1) - Придбати квиток |   | 2) - Увiйти як оператор |   | 3) - Увiйти як адмiнiстратор |   | 4) - Вийти з програми |" << endl << endl;
	cout << " ------------------------   ---------------------------   --------------------------------   ------------------------ " << endl << endl << endl;
	cout << "                        Щоб здiйснити вибiр мiж пунктами меню введiть цифру та натиснiть Enter " << endl << endl;

	cout << "  -----------------------------------------------" << endl;
	cout << " | Кiлькiсть поїздок | Цiна за одну поїздку, грн |" << endl;
	cout << "  -----------------------------------------------" << endl;
	cout << " |        1-9        |             8             |" << endl;
	cout << "  -----------------------------------------------" << endl;
	cout << " |       10-19       |             7.5	         |" << endl;
	cout << "  -----------------------------------------------" << endl;
	cout << " |       20-29       |             7.2	         |" << endl;
	cout << "  -----------------------------------------------" << endl;
	cout << " |       30-39       |             7             |" << endl;
	cout << "  -----------------------------------------------" << endl;
	cout << " |       40-49       |             6.5           |" << endl;
	cout << "  -----------------------------------------------" << endl;
	cout << " |       50+         |             6.2           |" << endl;
	cout << "  -----------------------------------------------" << endl;
}

int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	system("cls");
	setlocale(0, "ukr");
	main_menu_interface();
	main_menu_switch();

	return 0;
}