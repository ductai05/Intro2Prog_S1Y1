//ciel_23122013 23TNT1 FIT@HCMUS
// TH NMLT 22.11.2023
#include "23122013.h"

void section_a(ll n) {
	stack<int> s;
	int temp = 0;
	while (n != 0) {
		temp = n % 10;
		if (temp != 0 && temp != 5) {
			s.push(temp);
		}
		n -= temp;
		n /= 10;
	}
	cout << "\na/ M = ";
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << "\n\n";
	return;
}

void section_b(ll n) {
	cout << "b/ N duoc phan tich thanh cac thua so nguyen to la: \n";
	cout << n << " = ";
	vector<int> a;
	ll temp_luythua = 0;
	find_all_prime(n, a);
	ll t = n;
	ll i = 0;
	while (t != 1) {
		if (t % a[i] == 0) {
			cout << a[i] << "^";
			while (t % a[i] == 0) {
				t /= a[i];
				temp_luythua += 1;
			}
			i++;
			cout << temp_luythua;
			if (t == 1) {
				break;
			}
			else {
				cout << " * ";
			}
			temp_luythua = 0;
		}
		else {
			i++;
		}
	}
	cout << "\n\n";
}

void find_all_prime(ll n, vector<int>& a) {
	for (ll i = 2; i <= n; i++) {
		if (is_prime(i)) {
			a.push_back(i);
		}
	}
}
bool is_prime(ll x) {
	if (x < 2) {
		return false;
	}
	else if (x == 2) {
		return true;
	}
	else {
		for (ll i = 2; i < x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
	}
}

void section_cd(ll n) {
	if (is_palindrom(n)) {
		cout << "c/ N la so Palindrom\n\n";
	}
	else {
		cout << "c/ N khong phai la so Palindrom\n\n";
	}
	cout << "d/ ";
	for (int i = 11; i < 100; i++) {
		if (is_palindrom(i) && is_palindrom(i * i)) {
			cout << "So " << i << " la so palindrom va binh phuong cua no cung la so palindrom\n";
		}
	}
}

bool is_palindrom(ll x) {
	string s = to_string(x);
	ll s_size = s.size();
	for (int i = 0; i < s_size; i++) {
		if (s[i] != s[s_size - i - 1]) {
			return false;
		}
	}
	return true;
}

void section_e(ll n) {
	cout << "\n";
	ll re = 0;
	while (!is_palindrom(n)) {
		re = 0;
		re = rev(n);
		n += re;
	}
	cout << "e/ So Palindrom thu duoc la: " << n << "\n";
}

ll rev(ll n) {
	string s = to_string(n);
	reverse(s.begin(), s.end());
	return stoll(s);
}