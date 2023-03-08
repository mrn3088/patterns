#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool fun(T t) {
	return true;
}

template <typename T>
T fun(T* t) {
	return true;
}

template <typename T>
size_t sizeOf(T anArray[], int aCount) {
	return sizeof(T) * aCount;
}

template <>
size_t sizeOf<const char>(const char anArray[], int aCount) {
	cout << "const char" << endl;
	return aCount;
}

// template <>
// size_t sizeOf<char>(char anArray[], int aCount) {
// 	cout << "char" << endl;
// 	return aCount;
// }


int main() {
	// cout << fun(1) << endl;
	int a = 1;
	int *b = &a;
	cout << fun(b) << endl;
	// cout << fun(a) << endl;
	// char arr[10] = "abc";
	// cout << sizeOf("a", 2) << endl;
	// cout << sizeOf("a", 2) << endl;
	// cout << sizeOf(arr, 10) << endl;
}

/**
 * https://docs.google.com/spreadsheets/d/1zabGMPArd7d_n0448bZ2eqWp1baOCbQQ3PUXUHuNzhU/edit#gid=1417469107 
 * https://forms.gle/6Tuey4BrKdDJmS5t5 
 * https://classroom.github.com/a/DG4MsCgR 
 * https://classroom.github.com/a/5BiRY8rp 
 */