#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class CPole
{
private:
	sf::Sprite sGrafika;
	bool bMina;
	bool bKlikniety;
	bool bFlaga;
	int iLiczba_Sasiadnich_Min;
	int iWspolrzedna_X;
	int iWspolrzedna_Y;
public:
	CPole();
	CPole(bool bCzy_Mina, int iIle_Sasiednich_Min, sf::Texture* tTekstura, int iX, int iY); //iCzy_Mina == true => to jest mina
	int zmien_grafike(sf::Texture* tNowa_Grafika);
	void zmien_liczbe_sasiednich_min(int iTemp_Liczba_Min);
	void zmien_na_mine();
	void zmien_bKlikniety();
	void zmien_bFlaga();
	bool access_bMina();
	bool access_bKlikniety();
	bool access_bFlaga();
	int access_iLiczba_Sasiadnich_Min();
	sf::Sprite access_sprite();
};