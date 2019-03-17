#include "CPrzycisk.hpp"
#include <string>

CPrzycisk::CPrzycisk(int iRozmiar_czc, int iR, int iG, int iB, float iX_czc, float iY_czc,  std::string sTekst, std::string sPrzycisk, float iX_butt, float iY_butt)
{
	fCzcionka.loadFromFile("Multimedia/jaapokki-regular.ttf");
	txTekst.setFont(fCzcionka);
	txTekst.setString(sTekst);
	txTekst.setCharacterSize(iRozmiar_czc); // in pixels, not points!
	txTekst.setColor(sf::Color(iR, iG, iB));
	txTekst.setPosition(iX_czc, iY_czc);

	tButton.loadFromFile(sPrzycisk);
	sButton.setTexture(tButton);
	sButton.setPosition(iX_butt, iY_butt);
}

CPrzycisk::~CPrzycisk(){}

void CPrzycisk::rysuj(sf::RenderWindow* Okno)
{
	Okno->draw(sButton);
	Okno->draw(txTekst);
}

sf::FloatRect CPrzycisk::daj_gloabal_bounds()
{
	return sButton.getGlobalBounds();
}