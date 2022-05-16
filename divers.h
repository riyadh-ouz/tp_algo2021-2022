#pragma once


template <typename T>
void permuter(T& a, T& b) {
	T x = a;
	a = b;
	b = x;
};

void tri_tri_couleur(int T[], int n);
