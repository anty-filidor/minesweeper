#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "CPole.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

class CPlansza
{
private:
	sf::Texture tJedna;
	sf::Texture tDwie;
	sf::Texture tTrzy;
	sf::Texture tCztery;
	sf::Texture tPiec;
	sf::Texture tSzesc;
	sf::Texture tSiedem;
	sf::Texture tOsiem;
	sf::Texture tMina;
	sf::Texture tPusta;
	sf::Texture tZakryta;
	sf::Texture tFlaga;
	int iLiczba_Odkrytych;
	CPole pPlansza[20][20];
	bool Upadek;
public:
	CPlansza(int iLiczba_Min);
	void klikniecie(int i, int j, bool parametr_rekurencji, bool parametr_przycisku); // parametr_przycisku == true (prawy); == false (lewy)
	void odslon_pole(int i, int j);
	void pokaz_cala_plansze();
	bool access_upadek();
	sf::Sprite pokaz_pole(int i, int j);
	int liczba_wykrytych_pustych_pol();
};

