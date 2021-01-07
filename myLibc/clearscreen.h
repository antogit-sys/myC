/*
 * Fuck System();
 * 
 * compile linux:
 * gcc namefile.c -o namefile -ltinfo
 * 
*/
#ifdef _WIN32
#	include <windows.h>
#	include <stdio.h>

void clrscr(void)
{
	HANDLE                     hStdOut;		//handle cmd
	CONSOLE_SCREEN_BUFFER_INFO csbi;		//specifiche HANDLE
	DWORD                      count;		//numero operazioni
	DWORD                      cellCount;	//numero celle
	COORD                      homeCoords = { 0, 0 }; //cordinate iniziali
	
	//HANDLE=riferimento astratto ad una risorsa
	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE ); //CMD
    	if (hStdOut == INVALID_HANDLE_VALUE) return; //se l'handle non è valido(cmd)esc | INVALID_HANDLE_VALUE=FFFFFFFF -->F8
	
	/*Ottieni il numero di celle del buffer corrente*/
	//1WORD=16 bit
	//DWORD=DOUBLE WORD --> 32 bit
	//se non ottieni informazioni sul buffer dello schermo della console allora esci
	if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
	//altrimenti:
	cellCount = csbi.dwSize.X *csbi.dwSize.Y; //mi trovo numero di celle
	
	/*Riempie l'intero buffer con spazi */
	if (!FillConsoleOutputCharacter(
		hStdOut,	//cmd
		(TCHAR) ' ',//spazi
		cellCount,	//numero di celle
		homeCoords,	//cordinate cursore per portarlo sopra
		&count		//numero operazioni
	)) return;	//esci quando il buffer è finito
	
	/* Riempi l'intero buffer con i colori e gli attributi correnti */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,//colori
		cellCount,
		homeCoords,
		&count
	)) return;	//esci quando ha finito
	
	/*Sposta il curosore in {0,0}*/
	SetConsoleCursorPosition( hStdOut, homeCoords );
}
#elif __linux__ || __APPLE__ // !_WIN32
#	include <unistd.h>
#	include <term.h>

void clrscr(void)
{
	if (!cur_term)	//se il file cur_term non contiene i dati che descrivono 
	{				//il terminale corrente,allora
		int result;
		
		/*restituisce un errore se non è in grado di 
		 * allocare memoria sufficiente, oppure creare 
		 * le finestre iniziali --> (stdscr, curscr,newscr)
		 * */
		 //setupterm(scren attuale,cursore,nuovo screen);
		setupterm( NULL, STDOUT_FILENO, &result );
		if (result <= 0) return; //se il nuovo schermo è minore o uguale a 0 esco
	}
	putp(tigetstr("clear")); //putp ==(puts di linux senza newline) }----> ==fputs(<>,stdout)
	//tigetstr -->interrupt per pulire lo shcermo
	//putp --> realizza pulizia
}
#endif
