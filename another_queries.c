//Niculici Mihai-Daniel 315CA - another_queries
//Sper ca e bine, doamne ajuta.
#include <stdio.h>

void operatie_tip_1(int sudoku[][400], int N)
{
	//Iau un vector pe care il initializez cu 1.
	int linie, v_freq[401];
	for (int i = 1; i <= N * N; i++)
		v_freq[i] = 1;
	scanf("%d", &linie);
	//Scad linia pentru ca liniile incep de la 0
	linie--;
	//Daca gasesc un numar, inseamna ca nu pot sa-l folosesc
	//si il notez cu 0 in vector
	for (int i = 0; i < N * N; i++)
		v_freq[sudoku[linie][i]] = 0;
	//Apoi afisez pentru fiecare numar de la 1 la N*N
	//daca pot sa il pun sau nu pe linia respectiva
	for (int i = 1; i <= N * N; i++)
		printf("%d ", v_freq[i]);
	printf("\n");
}

void operatie_tip_2(int sudoku[][400], int N)
{
	//Iau un vector pe care il initializez cu 1.
	int coloana, v_freq[401];
	for (int i = 1; i <= N * N; i++)
		v_freq[i] = 1;
	scanf("%d", &coloana);
	//Scad coloana pentru ca coloanele incep de la 0
	coloana--;
	//Daca gasesc un numar, inseamna ca nu pot sa-l folosesc
	//si il notez cu 0 in vector
	for (int i = 0; i < N * N; i++)
		v_freq[sudoku[i][coloana]] = 0;
	//Apoi afisez pentru fiecare numar de la 1 la N*N
	//daca pot sa il pun sau nu pe coloana respectiva
	for (int i = 1; i <= N * N; i++)
		printf("%d ", v_freq[i]);
	printf("\n");
}

void operatie_tip_3(int sudoku[][400], int N)
{
	//Iau un vector pe care il initializez cu 1.
	int careu, l_careu, c_careu, v_freq[401];
	for (int i = 1; i <= N * N; i++)
		v_freq[i] = 1;
	scanf("%d", &careu);
	//Scad careul pentru ca careurile incep de la 0
	careu--;
	//Calculez unde incepe careul respectiv
	l_careu = (careu / N) * N;
	c_careu = (careu % N) * N;
	//Daca gasesc un numar, inseamna ca nu pot sa-l folosesc
	//si il notez cu 0 in vector
	for (int i = l_careu; i < l_careu + N; i++)
		for (int j = c_careu; j < c_careu + N; j++)
			v_freq[sudoku[i][j]] = 0;
	//Apoi afisez pentru fiecare numar de la 1 la N*N
	//daca pot sa il pun sau nu in careul respectiv
	for (int i = 1; i <= N * N; i++)
		printf("%d ", v_freq[i]);
	printf("\n");
}

void operatie_tip_4(int sudoku[][400], int N)
{
	int x, y, v_freq[401];
	scanf("%d %d", &x, &y);
	//Scad coordonatele pentru ca numaratoarea liniilor,
	//coloanelor si careurilor incepe de la 0.
	x--;
	y--;
	//Verific daca am un numar la coordonatele date
	if (sudoku[x][y] == 0) {
		//Iau un vector pe care il initializez cu 1.
		for (int i = 1; i <= N * N; i++)
			v_freq[i] = 1;
		//Daca gasesc un numar, inseamna ca nu pot sa-l folosesc
		//si il notez cu 0 in vector
		for (int j = 0; j < N * N; j++)
			v_freq[sudoku[x][j]] = 0;
		//Daca gasesc un numar, inseamna ca nu pot sa-l folosesc
		//si il notez cu 0 in vector
		for (int i = 0; i < N * N; i++)
			v_freq[sudoku[i][y]] = 0;
		//Calculez unde incepe careul in care se
		//afla coordonatele date
		int careu_x, careu_y;
		careu_x = x - (x % N);
		careu_y = y - (y % N);
		//Daca gasesc un numar, inseamna ca nu pot sa-l folosesc
		//si il notez cu 0 in vector
		for (int i = careu_x; i < careu_x + N; i++)
			for (int j = careu_y; j < careu_y + N; j++)
				v_freq[sudoku[i][j]] = 0;
		//Apoi afisez pentru fiecare numar de la 1 la N*N
		//daca pot sa il pun sau nu la coordonatele date.
		for (int i = 1; i <= N * N; i++)
			printf("%d ", v_freq[i]);
	} else {
		//Daca am un numar la coordonatele date, afisez 0 peste tot.
		for (int i = 1; i <= N * N; i++)
			printf("0 ");
	}
	printf("\n");
}

void operatie_tip_5(int sudoku[][400])
{
	int x, y, val;
	scanf("%d %d %d", &x, &y, &val);
	//Scad coordonatele pentru ca numaratoarea liniilor,
	//coloanelor si careurilor incepe de la 0.
	x--;
	y--;
	//Daca nu am valoare pusa la acele coordonate, pun
	//valoarea data
	if (sudoku[x][y] == 0)
		sudoku[x][y] = val;
}

int operatie_tip_6(int sudoku[][400], int N)
{
	//Intializez o variabila care initial marcheaza
	//ca jocul este complet.
	int complet = 2;
	for (int i = 0; i < N * N; i++) {
		//Iau un vector pe care il initializez cu 0.
		//Pentru fiecare linie in parte.
		int v_freq[401] = {0};
		//Cresc contorul la fiecare numar pe care in intalnesc
		//Daca linia/coloana/careul este completat corect
		//Trebuie sa am 1 la toate numerele de la 1 la N * N.
		for (int j = 0; j < N * N; j++)
			v_freq[sudoku[i][j]]++;
		for (int k = 1; k <= N * N; k++) {
			//Daca un numar apare pe o linie/coloana/careu
			//de mai mult de 1 data, returnez 1, adica
			//este configuratie invalida
			if (v_freq[k] > 1)
				return	1;
			//Daca nu numar nu apare deloc, inseamna ca
			// jocul nu este terminat.
			if (v_freq[k] != 1)
				complet = 0;
		}
	}
	for (int j = 0; j < N * N; j++) {
		//Iau un vector pe care il initializez cu 0.
		//Pentru fiecare coloana in parte.
		int v_freq[401] = {0};
		//Cresc contorul la fiecare numar pe care in intalnesc
		//Daca linia/coloana/careul este completat corect
		//Trebuie sa am 1 la toate numerele de la 1 la N * N.
		for (int i = 0; i < N * N; i++)
			v_freq[sudoku[i][j]]++;
		for (int k = 1; k <= N * N; k++) {
			//Daca un numar apare pe o linie/coloana/careu
			//de mai mult de 1 data, returnez 1, adica
			//este configuratie invalida
			if (v_freq[k] > 1)
				return	1;
			//Daca nu numar nu apare deloc, inseamna ca
			// jocul nu este terminat.
			if (v_freq[k] != 1)
				complet = 0;
		}
	}
	//Iau fiecare careu in parte si il verific
	int l_careu = 0, c_careu = 0;
	for (int i = 0; i < N * N; i++) {
		//Iau un vector pe care il initializez cu 0.
		//Pentru fiecare careu in parte.
		int v_freq[401] = {0};
		//Cresc contorul la fiecare numar pe care in intalnesc
		//Daca linia/coloana/careul este completat corect
		//Trebuie sa am 1 la toate numerele de la 1 la N * N.
		for (int i = l_careu; i < l_careu + N; i++)
			for (int j = c_careu; j < c_careu + N; j++)
				v_freq[sudoku[i][j]]++;
		for (int k = 1; k <= N * N; k++) {
			//Daca un numar apare pe o linie/coloana/careu
			//de mai mult de 1 data, returnez 1, adica
			//este configuratie invalida
			if (v_freq[k] > 1)
				return	1;
			//Daca nu numar nu apare deloc, inseamna ca
			// jocul nu este terminat.
			if (v_freq[k] != 1)
				complet = 0;
		}
		//Ma mut pe urmatorul careu
		c_careu += N;
		//Verific daca este am ajuns la ultimul careu de
		//pe linia respectiva, si trec la urmatorul
		if (c_careu == N * N) {
			l_careu += N;
			c_careu = 0;
		}
	}
	//Returnez starea jocului
	return complet;
}

void citire_sudoku(int N, int sudoku[][400])
{
	//Citesc tabelul de sudoku
	for (int i = 0; i < N * N; i++)
		for (int j = 0; j < N * N; j++)
			scanf("%d", &sudoku[i][j]);
}

int main(void)
{
	//Nu cred ca am ce sa explic la variabile :)
	int N, M, sudoku[400][400];
	scanf("%d %d", &N, &M);
	citire_sudoku(N, sudoku);
	//Dupa ce citesc tabelul de sudoku, citesc M operatii
	//si le execut cu ajutorul functiilor de mai sus
	for (int i = 1; i <= M; i++) {
		int operatie;
		scanf("%d", &operatie);
		if (operatie == 1)
			operatie_tip_1(sudoku, N);
		else if (operatie == 2)
			operatie_tip_2(sudoku, N);
		else if (operatie == 3)
			operatie_tip_3(sudoku, N);
		else if (operatie == 4)
			operatie_tip_4(sudoku, N);
		else if (operatie == 5)
			operatie_tip_5(sudoku);
		else if (operatie == 6)
			printf("%d\n", operatie_tip_6(sudoku, N));
	}
	return 0;
}
