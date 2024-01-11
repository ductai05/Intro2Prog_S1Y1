#ifndef _PHANSO_H_
#define _PHANSO_H_

#include <iostream>
void show();
using namespace std;
PHANSO operator+ (PHANSO p, PHANSO q);
PHANSO operator- (PHANSO p, PHANSO q);
PHANSO operator* (PHANSO p, PHANSO q);
PHANSO operator/ (PHANSO p, PHANSO q);
void Cong(PHANSO p, PHANSO q);
void Tru(PHANSO p, PHANSO q);
void Nhan(PHANSO p, PHANSO q);
void Chia(PHANSO p, PHANSO q);
ll GCD(ll a, ll b);
PHANSO rutgon(PHANSO t);

#endif

