#include "CPole.hpp"
#include <iostream>

CPole::CPole()
{
	bMina = false;
	bKlikniety = false;
	bFlaga = false;
	iLiczba_Sasiadnich_Min = 0;
	iWspolrzedna_X = 0;
	iWspolrzedna_Y = 0;
}

CPole::CPole(bool bCzy_Mina, int iIle_Sasiednich_Min, sf::Texture* tTekstura, int iX, int iY)
{
	if (bCzy_Mina)
	{
		iLiczba_Sasiadnich_Min = -1;
		bMina = true;
	}
	else
	{
		iLiczba_Sasiadnich_Min = iIle_Sasiednich_Min;
		bMina = false;
	}
	bKlikniety = false;
	bFlaga = false;
	sGrafika.setTexture(*tTekstura);
	iWspolrzedna_X = iX;
	iWspolrzedna_Y = iY;
	sGrafika.setPosition((float)(sf::VideoMode::getDesktopMode().width / 1366.0) * iWspolrzedna_X, (float)(sf::VideoMode::getDesktopMode().height / 768.0) * iWspolrzedna_Y);
}

int CPole::zmien_grafike(sf::Texture* tNowa_Grafika)
{
	sGrafika.setTexture(*tNowa_Grafika);
	return 1;
}

void CPole::zmien_liczbe_sasiednich_min(int iTemp_Liczba_Min)
{
	iLiczba_Sasiadnich_Min = iTemp_Liczba_Min;
}

void CPole::zmien_na_mine()
{
	iLiczba_Sasiadnich_Min = -1;
	bMina = true;
}

void CPole::zmien_bKlikniety()
{
	if (!bFlaga)
	{
		bKlikniety = true;
	}
	else if (bFlaga)
		bKlikniety = !bKlikniety;
}

void CPole::zmien_bFlaga()
{
	bFlaga = !bFlaga;
}

bool CPole::access_bMina()
{
	return bMina;
}

bool CPole::access_bKlikniety()
{
	return bKlikniety;
}

bool CPole::access_bFlaga()
{
	return bFlaga;
}

int CPole::access_iLiczba_Sasiadnich_Min()
{
	return iLiczba_Sasiadnich_Min;
}

sf::Sprite CPole::access_sprite()
{
	return sGrafika;
}