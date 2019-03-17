#include "CPlansza.hpp"

CPlansza::CPlansza(int iLiczba_Min)
{
	tJedna.loadFromFile("Multimedia/1.png");
	tDwie.loadFromFile("Multimedia/2.png");
	tTrzy.loadFromFile("Multimedia/3.png");
	tCztery.loadFromFile("Multimedia/4.png");
	tPiec.loadFromFile("Multimedia/5.png");
	tSzesc.loadFromFile("Multimedia/6.png");
	tSiedem.loadFromFile("Multimedia/7.png");
	tOsiem.loadFromFile("Multimedia/8.png");
	tMina.loadFromFile("Multimedia/mina.png");
	tPusta.loadFromFile("Multimedia/pusta.png");
	tZakryta.loadFromFile("Multimedia/zakryta.png");
	tFlaga.loadFromFile("Multimedia/flaga.png");
	iLiczba_Odkrytych = 0;
	Upadek = false;
	
	int i = 0;
	int j = 0;
	int temp_wiersz = 0;
	int temp_kolumna = 0;
	int iLicznik_Sasiednich_Min = 0;
	////////////////////////////////////////////////////////*INICJALIZACJA POLA MIN*/
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			pPlansza[i][j] = CPole(false, 0, &tZakryta, (i * 30) + 400, (j * 30) + 50);
		}
	}
	////////////////////////////////////////////////////////*UMIESZCZANIE MIN NA PLANSZY*/
	std::random_device rd;
	std::mt19937 g(rd());
	std::uniform_int_distribution<> dist(0, 19);
	i = 0;
	while (i < iLiczba_Min)
	{
		temp_wiersz = dist(g);
		temp_kolumna = dist(g);
		if (!pPlansza[temp_wiersz][temp_kolumna].access_bMina())
		{
			pPlansza[temp_wiersz][temp_kolumna].zmien_na_mine();
			//pPlansza[temp_wiersz][temp_kolumna].zmien_grafike(&tMina);
			i++;
		}

	}
	////////////////////////////////////////////////////////*UMIESZCZANIE ZNACZNIKÓW MIN*/
	//Mina (0, 0)
	iLicznik_Sasiednich_Min = 0;
	if (!pPlansza[0][0].access_bMina())
	{
		if (pPlansza[0][1].access_bMina())
		{
			iLicznik_Sasiednich_Min++;
		}
		if (pPlansza[1][1].access_bMina())
		{
			iLicznik_Sasiednich_Min++;
		}
		if (pPlansza[1][0].access_bMina())
		{
			iLicznik_Sasiednich_Min++;
		}
		pPlansza[0][0].zmien_liczbe_sasiednich_min(iLicznik_Sasiednich_Min);
	}
	//Mina (0, 19)
	iLicznik_Sasiednich_Min = 0;
	if (!pPlansza[0][0].access_bMina())
	{
		if (pPlansza[0][18].access_bMina())
		{
			iLicznik_Sasiednich_Min++;
		}
		if (pPlansza[1][18].access_bMina())
		{
			iLicznik_Sasiednich_Min++;
		}
		if (pPlansza[1][19].access_bMina())
		{
			iLicznik_Sasiednich_Min++;
		}
		pPlansza[0][19].zmien_liczbe_sasiednich_min(iLicznik_Sasiednich_Min);
	}
	//Mina (19, 0)
	iLicznik_Sasiednich_Min = 0;
	if (!pPlansza[19][0].access_bMina())
	{
		if (pPlansza[18][0].access_bMina())
		{
			iLicznik_Sasiednich_Min++;
		}
		if (pPlansza[18][1].access_bMina())
		{
			iLicznik_Sasiednich_Min++;
		}
		if (pPlansza[19][1].access_bMina())
		{
			iLicznik_Sasiednich_Min++;
		}
		pPlansza[19][0].zmien_liczbe_sasiednich_min(iLicznik_Sasiednich_Min);
	}
	//Mina (19, 19)
	iLicznik_Sasiednich_Min = 0;
	if (!pPlansza[19][19].access_bMina())
	{
		if (pPlansza[19][18].access_bMina())
		{
			iLicznik_Sasiednich_Min++;
		}
		if (pPlansza[18][18].access_bMina())
		{
			iLicznik_Sasiednich_Min++;
		}
		if (pPlansza[18][19].access_bMina())
		{
			iLicznik_Sasiednich_Min++;
		}
		pPlansza[19][19].zmien_liczbe_sasiednich_min(iLicznik_Sasiednich_Min);
	}
	//górna kolumna --- w rzeczywistoœci lewa
	i = 1;
	iLicznik_Sasiednich_Min = 0;
	while (i < 19) //warunek brzegowy dla górnej kolumny
	{
		if (pPlansza[0][i].access_bMina())
		{
			i++;
		}
		else
		{
			iLicznik_Sasiednich_Min = 0;
			if (pPlansza[0][i - 1].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[1][i - 1].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[1][i].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[1][i + 1].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[0][i + 1].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			pPlansza[0][i].zmien_liczbe_sasiednich_min(iLicznik_Sasiednich_Min);
			i++;
		}
	}
	//dolna kolumna --- w rzeczywistoœci prawa
	i = 1;
	iLicznik_Sasiednich_Min = 0;
	while (i < 19) //warunek brzegowy dla dolnej kolumny
	{
		if (pPlansza[19][i].access_bMina())
		{
			i++;
		}
		else
		{
			iLicznik_Sasiednich_Min = 0;
			if (pPlansza[19][i - 1].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[18][i - 1].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[18][i].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[18][i + 1].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[19][i + 1].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			pPlansza[19][i].zmien_liczbe_sasiednich_min(iLicznik_Sasiednich_Min);
			i++;
		}	
	}
	//lewa kolumna --- w rzeczywistoœci gorna
	i = 1;
	iLicznik_Sasiednich_Min = 0;
	while (i < 19) //warunek brzegowy dla lewej kolumny
	{
		if (pPlansza[i][19].access_bMina())
		{
			i++;
		}
		else
		{
			iLicznik_Sasiednich_Min = 0;
			if (pPlansza[i - 1][19].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[i - 1][18].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[i][18].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[i + 1][18].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[i + 1][19].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			pPlansza[i][19].zmien_liczbe_sasiednich_min(iLicznik_Sasiednich_Min);
			i++;
		}
	}
	//prawa kolumna --- w rzeczywistoœci dolna
	i = 1;
	iLicznik_Sasiednich_Min = 0;
	while (i < 19) //warunek brzegowy dla prawej kolumny
	{
		if (pPlansza[i][0].access_bMina())
		{
			i++;
		}
		else
		{
			iLicznik_Sasiednich_Min = 0;
			if (pPlansza[i - 1][0].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[i - 1][1].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[i][1].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[i + 1][1].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			if (pPlansza[i + 1][0].access_bMina())
			{
				iLicznik_Sasiednich_Min++;
			}
			pPlansza[i][0].zmien_liczbe_sasiednich_min(iLicznik_Sasiednich_Min);
			i++;
		}
	}
	//wszystkie nie brzegowe punkty
	i = 1;
	j = 1;
	iLicznik_Sasiednich_Min = 0;
	for (i = 1; i < 19; i++)
	{
		for (j = 1; j < 19; j++)
		{
			if (!pPlansza[i][j].access_bMina())
			{
				iLicznik_Sasiednich_Min = 0;
				if (pPlansza[i - 1][j].access_bMina())
				{
					iLicznik_Sasiednich_Min++;
				}
				if (pPlansza[i - 1][j + 1].access_bMina())
				{
					iLicznik_Sasiednich_Min++;
				}
				if (pPlansza[i][j + 1].access_bMina())
				{
					iLicznik_Sasiednich_Min++;
				}
				if (pPlansza[i + 1][j + 1].access_bMina())
				{
					iLicznik_Sasiednich_Min++;
				}
				if (pPlansza[i + 1][j].access_bMina())
				{
					iLicznik_Sasiednich_Min++;
				}
				if (pPlansza[i + 1][j - 1].access_bMina())
				{
					iLicznik_Sasiednich_Min++;
				}
				if (pPlansza[i][j - 1].access_bMina())
				{
					iLicznik_Sasiednich_Min++;
				}
				if (pPlansza[i - 1][j - 1].access_bMina())
				{
					iLicznik_Sasiednich_Min++;
				}
				pPlansza[i][j].zmien_liczbe_sasiednich_min(iLicznik_Sasiednich_Min);
			}
		}
	}
	//pokaz_cala_plansze();
}

void CPlansza::klikniecie(int i, int j, bool parametr_rekurencji, bool parametr_przyciksu)
{
	if (!pPlansza[i][j].access_bKlikniety())
	{
		if (!pPlansza[i][j].access_bMina() && !parametr_przyciksu)
		{
			odslon_pole(i, j);
			pPlansza[i][j].zmien_bKlikniety();
			if (pPlansza[i][j].access_iLiczba_Sasiadnich_Min() == 0)
			{
				if (i >= 0 && j >= 0)
				{
					if (i - 1 >= 0)
					{
						klikniecie(i - 1, j, true, false);
					}
					if (i + 1 <= 19)
					{
						klikniecie(i + 1, j, true, false);
					}
					if (j + 1 <= 19)
					{
						klikniecie(i, j + 1, true, false);
					}
					if (j - 1 >= 0)
					{
						klikniecie(i, j - 1, true, false);
					}
					if (i - 1 >= 0 && j + 1 <= 19)
					{
						klikniecie(i - 1, j + 1, true, false);
					}
					if (i - 1 >= 0 && j - 1 >= 0)
					{
						klikniecie(i - 1, j - 1, true, false);
					}
					if (i + 1 <= 19 && j - 1 >= 0)
					{
						klikniecie(i + 1, j - 1, true, false);
					}
					if (i + 1 <= 19 && j + 1 <= 19)
					{
						klikniecie(i + 1, j + 1, true, false);
					}
				}
			}
		}
		else if (pPlansza[i][j].access_bMina() && !parametr_rekurencji && !parametr_przyciksu)
		{
			pokaz_cala_plansze();
			Upadek = true;
		}
		if (!parametr_rekurencji && parametr_przyciksu)
		{
			pPlansza[i][j].zmien_grafike(&tFlaga);
			pPlansza[i][j].zmien_bKlikniety();
			pPlansza[i][j].zmien_bFlaga();
		}
	}
	else if (pPlansza[i][j].access_bKlikniety() && parametr_przyciksu && !parametr_rekurencji && pPlansza[i][j].access_bFlaga())
	{
		pPlansza[i][j].zmien_grafike(&tZakryta);
		pPlansza[i][j].zmien_bKlikniety();
		pPlansza[i][j].zmien_bFlaga();

	}
}

void CPlansza::odslon_pole(int i, int j)
{
	if (!pPlansza[i][j].access_bMina())
	{
		if (pPlansza[i][j].access_iLiczba_Sasiadnich_Min() == 0)
		{
			pPlansza[i][j].zmien_grafike(&tPusta);
		}
		if (pPlansza[i][j].access_iLiczba_Sasiadnich_Min() == 1)
		{
			pPlansza[i][j].zmien_grafike(&tJedna);
		}
		if (pPlansza[i][j].access_iLiczba_Sasiadnich_Min() == 2)
		{
			pPlansza[i][j].zmien_grafike(&tDwie);
		}
		if (pPlansza[i][j].access_iLiczba_Sasiadnich_Min() == 3)
		{
			pPlansza[i][j].zmien_grafike(&tTrzy);
		}
		if (pPlansza[i][j].access_iLiczba_Sasiadnich_Min() == 4)
		{
			pPlansza[i][j].zmien_grafike(&tCztery);
		}
		if (pPlansza[i][j].access_iLiczba_Sasiadnich_Min() == 5)
		{
			pPlansza[i][j].zmien_grafike(&tPiec);
		}
		if (pPlansza[i][j].access_iLiczba_Sasiadnich_Min() == 6)
		{
			pPlansza[i][j].zmien_grafike(&tSzesc);
		}
		if (pPlansza[i][j].access_iLiczba_Sasiadnich_Min() == 7)
		{
			pPlansza[i][j].zmien_grafike(&tSiedem);
		}
		if (pPlansza[i][j].access_iLiczba_Sasiadnich_Min() == 8)
		{
			pPlansza[i][j].zmien_grafike(&tOsiem);
		}
	}
	else if (pPlansza[i][j].access_bMina())
	{
		pPlansza[i][j].zmien_grafike(&tMina);
	}
}

void CPlansza::pokaz_cala_plansze()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			odslon_pole(i, j);
		}
	}
	
}

bool CPlansza::access_upadek()
{
	return Upadek;
}

sf::Sprite CPlansza::pokaz_pole(int i, int j)
{
	return pPlansza[i][j].access_sprite();
}

int CPlansza::liczba_wykrytych_pustych_pol()
{
	int i = 0;
	int j = 0;
	int iLiczba_odkr = 0;
	int iLiczba_flag = 0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (pPlansza[i][j].access_bKlikniety())
			{
				iLiczba_odkr++;
			}
			if (pPlansza[i][j].access_bFlaga())
			{
				iLiczba_flag++;
			}
		}		
	}
	return iLiczba_odkr - iLiczba_flag;
}