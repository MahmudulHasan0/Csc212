#include<iostream>
#include <queue> 
using namespace std;


int oneDollar = 0;
int fiveDollar = 0;
int tenDollar = 0;
int twentyDollar = 0;
double total_revenue = 0.00;
int Xavier_stock = 100;


double sold_product_avg(int n) {
	return (100 - Xavier_stock) / n;
}
double revenue_avg(int n) {
	return total_revenue / n;
}

bool make_change(int currency){
	if (currency == 2) {
		oneDollar += 2;
		Xavier_stock--;
	}
	else if (currency == 5) {
		if (oneDollar >= 3) {
			oneDollar -= 3;
			fiveDollar++;
			Xavier_stock--;
		}
		else {
			return false; 
		}
	}
	else if (currency == 10) {
		if (oneDollar >= 3 && fiveDollar > 0) {
			oneDollar -= 3;
			fiveDollar--;
			tenDollar++;
			Xavier_stock--;
		}
		else {
			return false;
		}
	} 
	else {
		if (oneDollar >= 3 && fiveDollar > 0 && tenDollar > 0) {
			oneDollar -= 3;
			fiveDollar--;
			tenDollar--;
			twentyDollar++;
			Xavier_stock--;
		}
		else if (oneDollar >= 3 && fiveDollar >= 3) {
			oneDollar -= 3;
			fiveDollar -= 3;
			twentyDollar++;
			Xavier_stock--;
		}
		else {
			return false;
		}
	}
	return true;
}
bool make_change_Modified(int currency, int amount){
	double total_bill = amount * 2;
	if (currency >= total_bill) {
		if (currency == 5) {
			if (oneDollar >= 1) {
				oneDollar--;
				fiveDollar++;
				Xavier_stock -= 2;
			}
			else {
				return false;
			}
		}
		else if (currency == 10) {
			tenDollar++;
			Xavier_stock -= 5;
		}
		else {
			twentyDollar++;
			Xavier_stock -= 10;
		}
	}
	return true;
}

int main() { 
	initializer_list<int> amountBuy = { 1, 1, 1, 1, 2, 1, 1, 5,  4, 1, 1, 6, 20, 5 };
	initializer_list<int> currency = { 20, 2, 2, 2, 5, 2, 2, 10, 10, 5, 10, 20, 20, 20 };
	queue <int> quantity(amountBuy); 
	queue <int> note(currency); 
	int i = 0;
	while (!note.empty()) {
		int amt = quantity.front();
		int cur = note.front();
		if (amt == 1) { 
			if (make_change(cur)) {
				cout << "Will Customer " << i << " have change? YES" << endl;
				cout << "***Cash Register***" << endl;
				cout << "OneDollar: " << oneDollar << endl;
				cout << "fiveDollar: " << fiveDollar << endl;
				cout << "tenDollar: " << tenDollar << endl;
				cout << "twentyDollar: " << twentyDollar << endl;
				total_revenue = 1 * (oneDollar)+5 * (fiveDollar)+10 * (tenDollar)+20 * (twentyDollar);
			}
			else {
				cout << "Will Customer " << i << " have change? NO" << endl;
				cout << "***Cash Register***" << endl;
				cout << "OneDollar: " << oneDollar << endl;
				cout << "fiveDollar: " << fiveDollar << endl;
				cout << "tenDollar: " << tenDollar << endl;
				cout << "twentyDollar: " << twentyDollar << endl;
				total_revenue = 1 * (oneDollar)+5 * (fiveDollar)+10 * (tenDollar)+20 * (twentyDollar);
			}
		}
		else {
			if (make_change_Modified(cur, amt)) {
				cout << "Will Customer " << i << " have change? YES" << endl;
				cout << "***Cash Register***" << endl;
				cout << "OneDollar: " << oneDollar << endl;
				cout << "fiveDollar: " << fiveDollar << endl;
				cout << "tenDollar: " << tenDollar << endl;
				cout << "twentyDollar: " << twentyDollar << endl;
				total_revenue = 1 * (oneDollar)+5 * (fiveDollar)+10 * (tenDollar)+20 * (twentyDollar);
			}
			else {
				cout << "Will Customer " << i << " have change? NO" << endl;
				cout << "***Cash Register***" << endl;
				cout << "OneDollar: " << oneDollar << endl;
				cout << "fiveDollar: " << fiveDollar << endl;
				cout << "tenDollar: " << tenDollar << endl;
				cout << "twentyDollar: " << twentyDollar << endl;
				total_revenue = 1 * (oneDollar)+5 * (fiveDollar)+10 * (tenDollar)+20 * (twentyDollar);
			}
		}
		quantity.pop();
		note.pop();
		i++;
	}
	cout << endl << endl << endl;
	cout << "Total Revenue: " << total_revenue << endl;
	cout << "Remaing Stock: " << Xavier_stock << endl;
	cout << "Average Revenue per Customer: " << revenue_avg(10) << endl;
	cout << "Average ice-cream per Sale: " << sold_product_avg(10) << endl;
	system("pause");
	return 0;
}