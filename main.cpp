#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

vector<string> linie;
void wczytaj( string nazwa ) {
	ifstream plik;
	plik.open( nazwa );
	while ( !plik.eof( ) ) {
		string x = "";
		plik >> x;
		linie.push_back( x );
		}
	}

void zad4_1( ) {
	for ( auto slowo : linie ) {
		int k = 0;
		int w = 0;
		for ( auto znak : slowo ) {
			if ( znak == 'k' ) k++;
			if ( znak == 'w' ) w++;
			}
		if ( w == k ) cout << slowo << endl;
		}
	}

void zad4_2( ) {
	for ( auto slowo : linie ) {
		//wakacje
		int znaki [ 6 ] = {0,0,0,0,0,0};
		//int w = 0, a = 0, k = 0, c = 0, j = 0, e = 0;
		for ( auto znak : slowo ) {
			if ( znak == 'w' ) znaki [ 0 ]++;
			if ( znak == 'a' ) znaki [ 1 ]++;
			if ( znak == 'k' ) znaki [ 2 ]++;
			if ( znak == 'c' ) znaki [ 3 ]++;
			if ( znak == 'j' ) znaki [ 4 ]++;
			if ( znak == 'e' ) znaki [ 5 ]++;
			}
		// w 2a k c j e
		int licznik = 0;
		for ( int i = 0; i < 6; i++ ) {
			if ( i != 1 ) { znaki [ i ] -= 1; if ( znaki [ i ] < 0 ) break; }
			if ( i == 1 ) { znaki [ i ] -= 2;  if ( znaki [ i ] < 0 ) break; }
			if ( i == 5 ) {
				licznik++;
				i = 0;
				}
			}
		cout << licznik << " ";
		}
	}

void zad4_4( ) {
	for ( auto slowo : linie ) {
		int licznik = 0;
		string wakacje = "wakacje";
		int temp = 0;
		int liczba_wakacje = 0;
		for ( int i = 0; i < slowo.length( ); i++ ) {
			if ( slowo [ i ] == wakacje [ temp ] ) {
				temp++;
				if ( temp == 7 ) { temp = 0; liczba_wakacje++; }
				}
			else {
				slowo [ i ] = '-';
				licznik++;
				}
			}

		if ( temp != 0 ) licznik += temp;
		if ( slowo.length( ) - liczba_wakacje * 7 > licznik ) cout << slowo.length( ) << endl;
		else cout << licznik << endl;
		}
	}

int main( ) {
	wczytaj( "przyklad.txt" );
	zad4_1( );
	zad4_2( );
	zad4_4( );
	return 0;
	}
