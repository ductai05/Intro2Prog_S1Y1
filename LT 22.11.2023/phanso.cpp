#include "phanso.h"
typedef long long ll;
struct phanso {
	ll tu;
	ll mau;
};
typedef struct phanso PHANSO;

PHANSO operator+ (PHANSO p, PHANSO q) {
	PHANSO t;
	t.tu = p.tu * q.mau + p.mau * q.tu;
	t.mau = p.mau * q.mau;
	return rutgon(t);
}

PHANSO operator- (PHANSO p, PHANSO q) {
	q.mau = -q.mau;
	return rutgon(p + q);
}

PHANSO operator* (PHANSO p, PHANSO q) {
	PHANSO t;
	t.tu = p.tu * q.tu;
	t.mau = p.mau * q.mau;
	return rutgon(t);
}

PHANSO operator/ (PHANSO p, PHANSO q) {
	ll temp;
	temp = q.tu;
	q.tu = q.mau;
	q.mau = temp;
	return rutgon(p*q);
}

PHANSO rutgon(PHANSO t) {
	ll x = GCD(t.tu, t.mau);
	t.tu /= x; t.mau /= x;
	return t;
}

ll GCD(ll a, ll b) {
	if (b > a) {
		swap(a, b);
	}

	while (b != 0) {
		ll ans = a % b;
		a = b;
		b = ans;
	}
	return a;
}

void Cong(PHANSO p, PHANSO q) {
	cout << "\n";
	PHANSO t = p + q;
	cout << p.tu << " / " << p.mau << " + " << q.tu << " / " << q.mau
		<< " = " << t.tu << " / " << t.mau;
}
void Tru(PHANSO p, PHANSO q) {
	cout << "\n";
	PHANSO t = p - q;
	cout << p.tu << " / " << p.mau << " - " << q.tu << " / " << q.mau
		<< " = " << t.tu << " / " << t.mau;
}
void Nhan(PHANSO p, PHANSO q) {
	cout << "\n";
	PHANSO t = p * q;
	cout << p.tu << " / " << p.mau << " * " << q.tu << " / " << q.mau
		<< " = " << t.tu << " / " << t.mau;
}
void Chia(PHANSO p, PHANSO q) {
	cout << "\n";
	PHANSO t = p / q;
	cout << p.tu << " / " << p.mau << " / " << q.tu << " / " << q.mau
		<< " = " << t.tu << " / " << t.mau;
}

void show() {
	PHANSO p = { 3,4 }, q = { 6, 13 };
	Cong(p, q);
	Tru(p, q);
	Nhan(p, q);
	Chia(p, q);
	return;
}