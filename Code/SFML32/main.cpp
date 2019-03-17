#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <locale>
#include "CPole.hpp"
#include "CPlansza.hpp"
#include "CPrzycisk.hpp"

int main()
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	double iWysokosc = desktop.height / 768.0;
	double iSzerokosc = desktop.width / 1366.0;
	sf::RenderWindow window(sf::VideoMode(), "SAPER", sf::Style::Fullscreen);
	setlocale(LC_ALL, "polish");
	
	/************************************************************///USTAWIENIE T£A
	/****/sf::Texture tBackground;
	/****/tBackground.loadFromFile("Multimedia/Chateauwood.jpg");
	/****/sf::Sprite sBackground;
	/****/sBackground.setTexture(tBackground);
	/****/sBackground.setScale((float)(iSzerokosc * 1), (float)(iWysokosc  * 0.8));
	/************************************************************/
	
	/************************************************************///USTAWIENIE DèWI KU
	/****/sf::SoundBuffer sbAudio;
	/****/sbAudio.loadFromFile("Multimedia/Elba.ogg");
	/****/sf::Sound sAudio;
	/****/sAudio.setBuffer(sbAudio);
	/****/sAudio.play();
	/****/sAudio.setVolume(4);
	/************************************************************/
	
	/************************************************************///USTAWIENIE TEKSTU
	/****/sf::Font font;
	/****/font.loadFromFile("Multimedia/jaapokki-regular.ttf");
	/****/
	/****/sf::Text Tytul;
	/****/Tytul.setFont(font);
	/****/Tytul.setString("S A P E R");
	/****/Tytul.setCharacterSize((int)(iWysokosc * 200));
	/****/Tytul.setColor(sf::Color(107, 80, 80));
	/****/Tytul.setPosition((window.getSize().x / 2) - Tytul.getLocalBounds().width / 2, 100);	
	/****/
	/****/sf::Text Tytul_poziomow;
	/****/Tytul_poziomow.setFont(font);
	/****/Tytul_poziomow.setString("WYBIERZ POZOIM");
	/****/Tytul_poziomow.setCharacterSize((int)(iWysokosc * 94));
	/****/Tytul_poziomow.setColor(sf::Color(10, 0, 0));
	/****/Tytul_poziomow.setPosition((5 + window.getSize().x / 2) - Tytul.getLocalBounds().width / 2, 280);
	/****/
	/****/sf::Text Koniec;
	/****/Koniec.setFont(font);
	/****/Koniec.setCharacterSize((int)(iWysokosc * 94));
	/****/Koniec.setColor(sf::Color(10, 0, 0));
	/************************************************************/
	
	/************************************************************///USTAWIENIE PRZYCISK”W
	/****/CPrzycisk NowaGra((int)(iWysokosc * 24), 0, 0, 0, (float)(iSzerokosc * 90), float(iWysokosc * 683), "Nowa Gra", "Multimedia/button.png", (float)(iSzerokosc * 50), (float)(iWysokosc * 670));
	/****/sf::FloatRect bbNowaGra = NowaGra.daj_gloabal_bounds();
	/****/CPrzycisk NowaGra_Pressed((int)(iWysokosc * 24), 0, 0, 0, (float)(iSzerokosc * 90), float(iWysokosc * 683), "Nowa Gra", "Multimedia/button_pressed.png", (float)(iSzerokosc * 50), (float)(iWysokosc * 670));
	/****/sf::FloatRect bbNowaGra_Pressed = NowaGra_Pressed.daj_gloabal_bounds();
	/****/
	/****/CPrzycisk Wyjscie((int)(iWysokosc * 24), 0, 0, 0, (float)(iSzerokosc * 465), float(iWysokosc * 683), "Koniec", "Multimedia/button.png", (float)(iSzerokosc * 400), (float)(iWysokosc * 670));
	/****/sf::FloatRect bbWyjscie = Wyjscie.daj_gloabal_bounds();
	/****/CPrzycisk Wyjscie_Pressed((int)(iWysokosc * 24), 0, 0, 0, (float)(iSzerokosc * 465), float(iWysokosc * 683), "Koniec", "Multimedia/button_pressed.png", (float)(iSzerokosc * 400), (float)(iWysokosc * 670));
	/****/sf::FloatRect bbWyjscie_Pressed = Wyjscie_Pressed.daj_gloabal_bounds();
	/****/
	/****/CPrzycisk Volume(0, 0, 0, 0, 0, 0, "", "Multimedia/volume.png", (float)(iSzerokosc * 50), (float)(iWysokosc * 50));
	/****/sf::FloatRect bbVolume = Volume.daj_gloabal_bounds();
	/****/CPrzycisk Volume_Active(0, 0, 0, 0, 0, 0, "", "Multimedia/volume_active.png", (float)(iSzerokosc * 50), (float)(iWysokosc * 50));
	/****/sf::FloatRect bbVolume_Active = Volume_Active.daj_gloabal_bounds();
	/****/
	/****/CPrzycisk Mute(0, 0, 0, 0, 0, 0, "", "Multimedia/mute.png", (float)(iSzerokosc * 50), (float)(iWysokosc * 161));
	/****/sf::FloatRect bbMute = Mute.daj_gloabal_bounds();
	/****/CPrzycisk Mute_Active(0, 0, 0, 0, 0, 0, "", "Multimedia/mute_active.png", (float)(iSzerokosc * 50), (float)(iWysokosc * 161));
	/****/sf::FloatRect bbMute_Active = Mute_Active.daj_gloabal_bounds();
	/****/
	/****/CPrzycisk Latwy((int)(iWysokosc * 30), 0, 0, 0, (float)(iSzerokosc * 315), float(iWysokosc * 435), "PROSTY", "Multimedia/button.png", (float)(iSzerokosc * 269), (float)(iWysokosc * 425));
	/****/sf::FloatRect bbLatwy = Latwy.daj_gloabal_bounds();
	/****/CPrzycisk Latwy_Pressed((int)(iWysokosc * 30), 0, 0, 0, (float)(iSzerokosc * 315), float(iWysokosc * 435), "PROSTY", "Multimedia/button_pressed.png", (float)(iSzerokosc * 269), (float)(iWysokosc * 425));
	/****/sf::FloatRect bbLatwy_Pressed = Latwy_Pressed.daj_gloabal_bounds();
	/****/
	/****/CPrzycisk Sredni((int)(iWysokosc * 30), 0, 0, 0, (float)(iSzerokosc * 636), float(iWysokosc * 435), "TRUDNY", "Multimedia/button.png", (float)(iSzerokosc * 590), (float)(iWysokosc * 425));
	/****/sf::FloatRect bbSredni = Sredni.daj_gloabal_bounds();
	/****/CPrzycisk Sredni_Pressed((int)(iWysokosc * 30), 0, 0, 0, (float)(iSzerokosc * 636), float(iWysokosc * 435), "TRUDNY", "Multimedia/button_pressed.png", (float)(iSzerokosc * 590), (float)(iWysokosc * 425));
	/****/sf::FloatRect bbSredni_Pressed = Sredni_Pressed.daj_gloabal_bounds();
	/****/
	/****/CPrzycisk Hard((int)(iWysokosc * 30), 0, 0, 0, (float)(iSzerokosc * 929), float(iWysokosc * 435), "HARDCORE", "Multimedia/button.png", (float)(iSzerokosc * 912), (float)(iWysokosc * 425));
	/****/sf::FloatRect bbHard = Hard.daj_gloabal_bounds();
	/****/CPrzycisk Hard_Pressed((int)(iWysokosc * 30), 0, 0, 0, (float)(iSzerokosc * 929), float(iWysokosc * 435), "HARDCORE", "Multimedia/button_pressed.png", (float)(iSzerokosc * 912), (float)(iWysokosc * 425));
	/****/sf::FloatRect bbHard_Pressed = Hard_Pressed.daj_gloabal_bounds();
	/****/
	/************************************************************/
	
	sf::Vector2i localPosition = sf::Mouse::getPosition(window); // wskazuje na pozycje myszy
	sf::Vector2f flocalPosition((float)localPosition.x, (float)localPosition.y); // konwersjw w.w. potrzebna do boundboxÛw
	bool bParametr_Ukonczenia_Gry = false;
	int iParametrWyjscia = 0; // gdy == 0 program siÍ zamyka
	int iParametr_Wcisniecia_Wyjscia = 0;
	int iParametr_Wcisniecia_Nowej_Gry = 0;
	int iParametr_Aktywnego_Dzwieku = 0;
	int iParametr_Poziomu = 0; // ≥atwy = 1, úrendi = 2, trudny = 3
	int iParametr_Wycisniecia_Poziomu = 0;
	int i = 0;
	int j = 0;
	int iParametr_Przesuniecia_Tutulu = 0;
	int iLiczba_min = 0;


	/************************************************************///INICJALIZACJA WSKAèNIKA NA OBIEKT KLASY CPLANSZA
	/****/ i = 0;
	/****/ j = 0;
	/****/CPlansza* plPlansza = NULL;
	/****/std::vector<sf::FloatRect> BoundBoxyPunktow;
	/************************************************************/


	while (window.isOpen())
	{
		sf::Event zdarzenie;
		localPosition = sf::Mouse::getPosition(window);
		flocalPosition.x = (float)localPosition.x;
		flocalPosition.y = (float)localPosition.y;
		while (window.pollEvent(zdarzenie))
		{
			if (bParametr_Ukonczenia_Gry && zdarzenie.type == sf::Event::MouseButtonPressed)
			{
				bParametr_Ukonczenia_Gry = !bParametr_Ukonczenia_Gry;
				delete plPlansza;
				plPlansza = NULL;
			}
			if (plPlansza != NULL)
			{
				if (zdarzenie.type == sf::Event::MouseButtonPressed && localPosition.x >= (400 * iSzerokosc) && localPosition.x <= ((400 + 20 * 30)*iSzerokosc) && localPosition.y >= (50 * iWysokosc) && localPosition.y <= ((50 + 20 * 30) * iWysokosc))
				{
					for (i = 0; i < 400; i++)
					{
						if (BoundBoxyPunktow[i].contains(flocalPosition) && zdarzenie.mouseButton.button == sf::Mouse::Left)
						{
							plPlansza->klikniecie((int)i / 20, i % 20, false, false);
						}
						else if (BoundBoxyPunktow[i].contains(flocalPosition) && zdarzenie.mouseButton.button == sf::Mouse::Right)
						{
							plPlansza->klikniecie((int)i / 20, i % 20, false, true);
						}
					}
				}
			}
			/************************************************************///OBS£UGA PRZYCISKU WYJåCIE
			/****/if (zdarzenie.type == sf::Event::Closed || (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape))
			/****/{
			/****/	iParametrWyjscia = 1;
			/****/}
			/****/if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left && bbWyjscie.contains(flocalPosition))
			/****/{
			/****/	iParametr_Wcisniecia_Wyjscia = 1;
			/****/}
			/****/if (zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left && bbWyjscie_Pressed.contains(flocalPosition) && iParametr_Wcisniecia_Wyjscia == 1)
			/****/{
			/****/	iParametrWyjscia = 1;
			/****/	iParametr_Wcisniecia_Wyjscia = 1;
			/****/}
			/****/else if (zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left && !bbWyjscie_Pressed.contains(flocalPosition) && iParametr_Wcisniecia_Wyjscia == 1)
			/****/{
			/****/	iParametr_Wcisniecia_Wyjscia = 0;
			/****/}
			/************************************************************/

			/************************************************************///OBS£UGA PRZYCISK”W POZIOM”W
			/****/if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left && bbLatwy.contains(flocalPosition) && iParametr_Wcisniecia_Nowej_Gry == 1)
			/****/{
			/****/	iParametr_Poziomu = 1;
			/****/}
			/****/if (zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left && bbLatwy_Pressed.contains(flocalPosition) && iParametr_Wcisniecia_Nowej_Gry == 1)
			/****/{
			/****/	iParametr_Wycisniecia_Poziomu = 1;
			/****/}
			/****/else if (zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left && !bbLatwy_Pressed.contains(flocalPosition) && iParametr_Wcisniecia_Nowej_Gry == 1)
			/****/{
			/****/	if (iParametr_Poziomu == 1)
			/****/	{
			/****/		iParametr_Wycisniecia_Poziomu = 0;
			/****/		iParametr_Poziomu = 0;
			/****/		iParametr_Wcisniecia_Nowej_Gry = 0;
			/****/	}
			/****/}
			/************************************************************/
			/****/if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left && bbSredni.contains(flocalPosition) && iParametr_Wcisniecia_Nowej_Gry == 1)
			/****/{
			/****/	iParametr_Poziomu = 2;
			/****/}
			/****/if (zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left && bbSredni_Pressed.contains(flocalPosition) && iParametr_Wcisniecia_Nowej_Gry == 1)
			/****/{
			/****/	iParametr_Wycisniecia_Poziomu = 1;
			/****/}
			/****/else if (zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left && !bbSredni_Pressed.contains(flocalPosition) && iParametr_Wcisniecia_Nowej_Gry == 1)
			/****/{
			/****/	if (iParametr_Poziomu == 2)
			/****/	{
			/****/		iParametr_Wycisniecia_Poziomu = 0;
			/****/		iParametr_Poziomu = 0;
			/****/		iParametr_Wcisniecia_Nowej_Gry = 0;
			/****/	}
			/****/}
			/************************************************************/
			/****/if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left && bbHard.contains(flocalPosition) && iParametr_Wcisniecia_Nowej_Gry == 1)
			/****/{
			/****/	iParametr_Poziomu = 3;
			/****/}
			/****/if (zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left && bbHard_Pressed.contains(flocalPosition) && iParametr_Wcisniecia_Nowej_Gry == 1)
			/****/{
			/****/	iParametr_Wycisniecia_Poziomu = 1;
			/****/}	
			/****/else if (zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left && !bbHard_Pressed.contains(flocalPosition) && iParametr_Wcisniecia_Nowej_Gry == 1)
			/****/{
			/****/	if (iParametr_Poziomu == 3)
			/****/	{
			/****/		iParametr_Wycisniecia_Poziomu = 0;
			/****/		iParametr_Poziomu = 0;
			/****/		iParametr_Wcisniecia_Nowej_Gry = 0;
			/****/	}
			/****/}
			/************************************************************/

			/************************************************************///OBS£UGA PRZYCISKU NOWA GRA
			/****/if (plPlansza == NULL && zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left && bbNowaGra.contains(flocalPosition))
			/****/{
			/****/	iParametr_Wcisniecia_Nowej_Gry = 1;
			/****/}
			/****/if (plPlansza == NULL &&zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left && bbNowaGra_Pressed.contains(flocalPosition) && iParametr_Wcisniecia_Nowej_Gry == 1)
			/****/{
			/****/	iParametr_Wcisniecia_Nowej_Gry = 1;
			/****/}
			/****/else if (plPlansza == NULL && zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left && !bbNowaGra_Pressed.contains(flocalPosition) && iParametr_Wcisniecia_Nowej_Gry == 1)
			/****/{
			/****/	if (bbVolume.contains(flocalPosition) || bbVolume_Active.contains(flocalPosition) || bbMute.contains(flocalPosition) || bbMute_Active.contains(flocalPosition))
			/****/	{
			/****/		iParametr_Wcisniecia_Nowej_Gry = 1;
			/****/	}
			/****/	else if (iParametr_Poziomu != 0)
			/****/	{
			/***/		iParametr_Wcisniecia_Nowej_Gry = 1;
			/****/	}
			/****/	else
			/****/		iParametr_Wcisniecia_Nowej_Gry = 0;
			/****/}
			/************************************************************/

			/************************************************************///OBS£UGA PRZYCISK”W G£OåNOåCI
			/****/if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left && (bbVolume.contains(flocalPosition) || bbVolume_Active.contains(flocalPosition)))
			/****/{
			/****/	iParametr_Aktywnego_Dzwieku = 1;
			/****/}
			/****/if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left && (bbMute.contains(flocalPosition) || bbMute_Active.contains(flocalPosition)))
			/****/{	
			/****/	iParametr_Aktywnego_Dzwieku = 0;
			/****/}
			/************************************************************/

		}
		if (iParametrWyjscia == 0)
		{
			window.clear(sf::Color(100, 100, 100));
			window.draw(sBackground);
			
			/************************************************************///OBS£UGA PRZYCISKU WYJåCIE
			/****/if (iParametr_Wcisniecia_Wyjscia == 0)
			/****/{
			/****/	Wyjscie.rysuj(&window);
			/****/}
			/****/else if (iParametr_Wcisniecia_Wyjscia == 1)
			/****/{
			/****/	Wyjscie_Pressed.rysuj(&window);
			/****/}
			/************************************************************/

			/************************************************************///OBS£UGA PRZYCISKU NOWA GRA
			/****/if (iParametr_Wcisniecia_Nowej_Gry == 0)
			/****/{
			/****/	if (iParametr_Przesuniecia_Tutulu != 0)
			/****/	{
			/****/		Tytul.setPosition((window.getSize().x / 2) - Tytul.getLocalBounds().width / 2, 100);
			/****/	}
			/****/	iParametr_Przesuniecia_Tutulu = 0;
			/****/	if (plPlansza == NULL)
			/****/	{
			/****/		window.draw(Tytul);
			/****/	}
			/****/	NowaGra.rysuj(&window);
			/****/}
			/****/else if (iParametr_Wcisniecia_Nowej_Gry == 1)
			/****/{
			/****/	NowaGra_Pressed.rysuj(&window);
			/****/	Tytul.setPosition(((window.getSize().x / 2) - Tytul.getLocalBounds().width / 2) + iParametr_Przesuniecia_Tutulu, 100);
			/****/	if (((window.getSize().x / 2) - Tytul.getLocalBounds().width / 2) + iParametr_Przesuniecia_Tutulu <= window.getSize().x)
			/****/	{
			/****/		iParametr_Przesuniecia_Tutulu++;
			/****/		window.draw(Tytul);
			/****/	}
			/****/	Latwy.rysuj(&window);
			/****/	Sredni.rysuj(&window);
			/****/	Hard.rysuj(&window);
			/****/	window.draw(Tytul_poziomow);
			/****/}
			/************************************************************/

			/************************************************************///OBS£UGA PRZYCISK”W G£OåNOåCI
			/****/if (iParametr_Aktywnego_Dzwieku == 0)
			/****/{
			/****/	sAudio.setVolume(0);
			/****/	Volume.rysuj(&window);
			/****/	Mute_Active.rysuj(&window);
			/****/}
			/****/else if (iParametr_Aktywnego_Dzwieku == 1)
			/****/{
			/****/	sAudio.setVolume(4);
			/****/	Volume_Active.rysuj(&window);
			/****/	Mute.rysuj(&window);
			/****/}
			/************************************************************/

			/************************************************************///OBS£UGA PRZYCISK”W POZIOMU
			/****/if (iParametr_Poziomu != 0 && plPlansza == NULL)
			/****/{
			/****/	if (iParametr_Poziomu == 1)
			/****/	{
			/****/		Latwy_Pressed.rysuj(&window);
			/***/		if (iParametr_Wycisniecia_Poziomu == 1)
			/****/		{
			/****/			plPlansza = new CPlansza(5);
			/****/			iLiczba_min = 5;
			/****/		}
			/****/	}
			/****/	else if (iParametr_Poziomu == 2)
			/****/	{
			/****/		Sredni_Pressed.rysuj(&window);
			/****/		if (iParametr_Wycisniecia_Poziomu == 1)
			/****/		{
			/****/			plPlansza = new CPlansza(50);
			/****/			iLiczba_min = 50;
			/****/		}
			/****/	}
			/****/	else if (iParametr_Poziomu == 3)
			/****/	{
			/****/		Hard_Pressed.rysuj(&window);
			/****/		if (iParametr_Wycisniecia_Poziomu == 1)
			/****/		{
			/****/			plPlansza = new CPlansza(80);
			/****/			iLiczba_min = 80;
			/****/		}
			/****/	}
			/****/	if (iParametr_Wycisniecia_Poziomu == 1)
			/****/	{
			/****/		for (i = 0; i < 20; i++)
			/****/		{
			/****/			for (j = 0; j < 20; j++)
			/****/			{
			/****/				BoundBoxyPunktow.push_back(plPlansza->pokaz_pole(i, j).getGlobalBounds());
			/****/			}
			/****/		}
			/****/		iParametr_Wcisniecia_Nowej_Gry = 0;
			/****/		iParametr_Poziomu = 0;
			/****/		iParametr_Wycisniecia_Poziomu = 0;
			/***/	}
			/****/}
			/************************************************************/

			if (plPlansza != NULL)
			{
				for (i = 0; i < 20; i++)
				{
					for (j = 0; j < 20; j++)
					{
						window.draw(plPlansza->pokaz_pole(i, j));
					}
				}
				
				if (plPlansza->liczba_wykrytych_pustych_pol() == 400 - iLiczba_min)
				{
					Koniec.setString("WYGARNA");
					Koniec.setPosition((window.getSize().x / 2) - Koniec.getLocalBounds().width / 2, 280);
					window.draw(Koniec);
					bParametr_Ukonczenia_Gry = true;
					//delete plPlansza;
					//plPlansza = NULL;					
				}
				if (plPlansza->access_upadek())
				{
					Koniec.setString("KONIEC GRY");
					Koniec.setPosition((window.getSize().x / 2)+12 - Koniec.getLocalBounds().width / 2, 280);
					window.draw(Koniec);
					bParametr_Ukonczenia_Gry = true;
					//delete plPlansza;
					//plPlansza = NULL;
				}
			}
			window.display();
		}
		else if (iParametrWyjscia == 1)
		{
			window.close();
		}
	}
	return 0;
}