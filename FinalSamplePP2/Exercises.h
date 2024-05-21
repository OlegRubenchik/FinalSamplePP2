#pragma once
#include <iostream>
using namespace std;




//EX1
enum MilkType { FullFat, SemiSkimmed, Skimmed };
class date {
public:
	int day, month; // Only Day and Month
};
class MilkBottle {
public:
	MilkBottle(MilkType t, int d, int m);
	bool Serve(); //removes only one glass of milk
	void Insert(int N);
	int Amount() const;
	bool Expired(date today) const;
private:
	MilkType type; // type of milk – FullFat or SemiSkimmed or Skimmed
	int NoOfGlasses; // FULL bottle = 4 glasses of milk
	date expiredDate;
};
MilkBottle::MilkBottle(MilkType t, int d, int m) {
	type = t;
	expiredDate.day = d;
	expiredDate.month = m;
	NoOfGlasses = 4;
}
/*bool Serve() – a function that will serve a glass of milk to a customer if the bottle is
not empty, thus the data member NoOfGlasses will be reduced by one. The function
will return true if the customer has been served and false otherwise.
*/
bool MilkBottle::Serve() {
	if (NoOfGlasses > 0) {
		NoOfGlasses--;
		return true;
	}
	return false;

}
/*void Insert(int N) – a function that adds N glasses of milk to the bottle. Note that
the maximum amount of classes a bottle can have is 4.
*/
void MilkBottle::Insert(int N) {
	NoOfGlasses += N;
	if (NoOfGlasses > 4) NoOfGlasses = 4;
}
/*int Amount() const – a function that returns the number of glasses that a bottle has.*/
int MilkBottle::Amount() const {
	return NoOfGlasses;
}
/*bool Expired(date today) const – a function that returns true if the milk has
expired and false if not.*/
bool MilkBottle::Expired(date today) const {
	if (today.month > expiredDate.month) return true;
	else if (today.day > expiredDate.day and today.month == expiredDate.month) return true;
	return false;
}
/*Write a function Add (does not belong to the class) that takes a date (today) and two milk
bottles M1 and M2, and puts milk from M2 to M1 until M1 is full or M2 is empty. This should only
happened if the two bottles are not expired, and the function should return true, otherwise it
should return false.
*/
bool Add(date today, MilkBottle M1, MilkBottle M2) {
	if (!(M1.Expired(today) and M2.Expired(today))) {
		while (M1.Amount() < 4 and M2.Amount() > 0) {
			M1.Insert(1);
			M2.Serve();
		}
		return true;
	}
	else return false;
}

/* Write the main program and declare two objects of the class MilkBottle, called Bottle1 and
Bottle2. Both bottles will contain skimmed milk and their expiration date will be on the 25th
of January. Then the program will ask the user to enter today’s day (declare an object of type
date called today). Hence write the code to add milk from Bottle2 to Bottle1. If this is
done successfully give a message “DONE” else “NOT DONE”.*/
void EX1() {
	MilkBottle Bottle1(Skimmed,25,1), Bottle2(Skimmed, 25, 1);
	Bottle1.Serve();
	date today;
	cout << "What day is today(number): ";
	cin >> today.day;
	cout << "What month is today(number): ";
	cin >> today.month;
	if (Add(today, Bottle1, Bottle2)) cout << "DONE\n";
	else cout << "NOT DONE\n";

}
//EX2 (a)
int	Fibonacci(int a,int b,int n) {
	if (n == 1) return a;
	if (n == 2) return b;
	if (n > 2) return Fibonacci(a, b, n - 1) + Fibonacci(a, b, n - 2);
}
void EX2_c() {
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (j > i) {

				for (int n = 1; n <= 10; n++) {
					cout << Fibonacci(i, j, n) << ' ';
				}
				cout << '\n';
			}
		}
	}
}

void EX4() {
		int a = 32;
		int* p = &a;
		*p = 123;
		cout << a << endl;
		int nums[10];
		for (a = 0; a < 10; a++)
			nums[a] = a + 2;
		p = nums;
		cout << *p << endl;
		*(p + 6) = 21;
		p += 3;
		*p = 15;
		--p;
		*p = -12;
		int k = 0;
		for (a = 0; a < 10; a++) {
			cout << nums[a] << " < ";
			k += nums[a];
		}
		cout << endl << k << endl;
		for (a = 0; a < 4; a++)
			cout << *(p + a - 1) << " ? ";
}
int addAfter(char str[], char ch1, char ch2) {
	if (ch1 == ch2) return -1;
	int size,counter = 0;
	for (size = 0; str[size] != '\0'; size++);
	for (int i = 0; i < size; i++) {
		if (str[i] == ch1) {
			counter++;
			for (int j = size; j > i; j--) {
				str[j] = str[j-1];
			}
			str[i + 1] = ch2;
		}
	}
	return counter;

}
int addAfter2(char str[], char ch1, char ch2)
{
	if (ch1 == ch2) return -1;
	int len, i, j, counter = 0;
	for (len = 0; str[len] != '\0'; len++);
	for (i = 0; i < len; i++)
		if (str[i] == ch1)
		{
			len++;
			i++;
			for (j = len; j > i; j--)
				str[j] = str[j - 1];
			str[i] = ch2;
			counter++;
		}
	return counter;
}

void EX3() {
	char str[7] = { 'h','i', ' ', 'm', 'a', 'n','\0'};
	cout << addAfter(str, 'i', '@') << '\n';
	for (int i = 0; i < 6; i++) {
		cout << str[i];
	}
}
