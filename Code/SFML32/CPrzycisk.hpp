#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class CPrzycisk
{
private:
	sf::Text txTekst;
	sf::Texture tButton;
	sf::Sprite sButton;
	sf::Font fCzcionka;
public:
	CPrzycisk(int iRozmiar_czc, int iR, int iG, int iB, float iX_czc, float iY_czc, std::string sTekst, std::string sPrzycisk, float iX_butt, float iY_butt);
	~CPrzycisk();
	void rysuj(sf::RenderWindow* Okno);
	sf::FloatRect daj_gloabal_bounds();
};