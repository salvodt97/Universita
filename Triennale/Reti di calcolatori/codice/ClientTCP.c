// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Client TCP
// Sintassi: ClientTCP [host] [port]
//			host: nome/indirizzo del computer sul quale il server 
//				e' in esecuzione
//			port: numero di port da utilizzare
//
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// Librerie
#include <sys/socket.h>
#include <netinet/in.h> // struct sockaddr_in
#include <netdb.h>	// gethostbyname()

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 	// atoi()
#include <unistd.h> 	// close()

// Costanti
#define PORTserver 5194 
#define PORTclient 5195

int main(int argc, char *argv[])
{
	struct sockaddr_in sad;		// SERVER
	struct hostent *ptrh;		// struttura per memorizzare la risoluzione del nome del server
	int    sd;			// descrittore della socket
	unsigned short port;		// numero di port del servizio
	char   buf[1000];		// buffer in cui memorizzare la stringa
	
	char localhost[] = "localhost";
	char *host;
	
	// Lettura delle opzioni a riga di comando
	// Numero di port
	if (argc > 2) {
		port = atoi(argv[2]);
		if (port == 0) {
			fprintf(stderr, "numero di port non valido\n");
			return 1;
		}
	} else {
		port = PORTserver;
	}

	// Indirizzo del server
	if (argc > 1)
		host = argv[1];
	else
		host = localhost; //localhost parola chiave definita nelle librerie

	// Conversione del nome in indirizzo IP
	if ((ptrh = gethostbyname(host)) == NULL) { //la funzione gethostbyname() legge nel file host del sistema operativo e da un IP al parametro host
		fprintf(stderr, "host non valido %s\n", host);
		return 1;
	}

	// Inzializzazione della struttura sad (Server)
	memset((char *)&sad, 0, sizeof(sad));
	sad.sin_family = AF_INET;
	memcpy(&sad.sin_addr, ptrh->h_addr, ptrh->h_length);	// copia dell'indirizzo nel campo sin_addr della struttura sad
	sad.sin_port = htons(port);
	
	// Creazione di una socket di tipo SOCK_STREAM - TCP
	if ((sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		fprintf(stderr, "socket creation failed\n");
		return 1;
	}
	
	// Connessione al server (three-way handshake TCP)
	if (connect(sd, (struct sockaddr *)&sad, sizeof(sad)) < 0) {
		fprintf(stderr, "connect fallita\n");
		return 1;
	}
	
	// Ciclo infinito
	while (1) {													//Con questo while faccio si che il client fa la stessa connect pi� volte
		// Richiesta di una stringa all'utente					fa cos� pi� richieste di connessioni
		memset(buf, 0, sizeof(buf));
		printf("Scrivi una stringa da spedire al server: ");
		gets(buf);

		// Invio della stringa al server
		write(sd, buf, strlen(buf));							//devo scrivere sulla connessione cos� invio la richiesta

		// Chiusura della connessione con la stringa "quit"
		if (!strncmp(buf, "quit", 4)) {
			break;
		} 
		
		// Ricezione della risposta dal server
		memset(buf, 0, sizeof(buf));
		read(sd, buf, sizeof(buf));
		printf("Ricevuto dal server: %s\n", buf);
	}
	
	// Chiusura della socket in ascolto
	close(sd);
	
	return 0;
}


