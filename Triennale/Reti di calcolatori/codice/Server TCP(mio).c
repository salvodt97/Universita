// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// SERVER TCP iterativo
// Sintassi: ServerTCP [port]
//			 port: numero di port da utilizzare
//
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// Librerie
#include <sys/socket.h>
#include <netinet/in.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 	// atoi()
#include <unistd.h> 	// close()

// Costanti
#define PORT 5194
#define QLEN 6

int main(int argc, char *argv[])
{
	struct sockaddr_in sad;		// SERVER
	int    sd;			// descrittore della socket
	unsigned short port;		// numero di port del servizio
	char   buf[1000];		// buffer in cui memorizzare la stringa

	// Lettura delle opzioni a riga di comando
	if (argc > 1) {
		port = atoi(argv[1]);  //la funzione atoi prende un dato che sta in argv[], in questo caso il numero di porta
		if (port == 0) {
			fprintf(stderr, "numero di port non valido\n");
			return 1;
		}
	} else {
		port = PORT;
	}

	// Inzializzazione della struttura sad
	memset((char *)&sad, 0, sizeof(sad)); //copia dei valori in una locazione di memoria, che � iniziallizata inizialmente tutta a 0
	sad.sin_family = AF_INET;
	sad.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY � una macro che mette tutto a 0
	sad.sin_port = htons(port);		// conversione di port da "host byte order" a "TCP/IP network order"
	//htons prende una variabile e la adatta alla convenzione usata in internet, cio� converte perch� la variabile deve essere
	//indipendente dal tipo di architettura che uso, per esempio in alcune architetture il bye pi� significativo � il primo, in altre � l'ultimo
	
	// Creazione di una socket di tipo SOCK_STREAM - TCP
	if ((sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {//questi sono valori interi che si riferisce a una macro
		fprintf(stderr, "creazione della socket fallita\n");
		return 1;
	}

	// Configurazione dell'endpoint locale della socket utilizzando 
	// i parametri della struttura sockaddr_in sad
	if (bind(sd, (struct sockaddr *)&sad, sizeof(sad)) < 0) {//io passo un sad, cio� un socckaddr_in, ovvero un indirizzi di internet, e tramite un cast lo
		fprintf(stderr, "bind fallito\n");					 // lo traduco come una sockaddr normale, che la bind vuole in ingresso, perch� non mi serve
		return 1;											 // un indirizzo specifico, bens� uno generico
	}

	// Avvio dell'ascolto sulla socket sd
	if (listen(sd, QLEN) < 0) {
		fprintf(stderr, "listen fallito\n");
		exit(1);
	}
	printf("Server in ascolto sul port TCP %d\n", port);
	
	// Ciclo infinito
	while (1) {
		int nsd;	// nuova socket relativa all'ultima connessione
		char src[1000]; // buffer per la stringa modificata
		int i;
		
		// Attesa di una connessione TCP
		if ((nsd = accept(sd, NULL, NULL)) < 0) {//gli altri 2 parametri sono a NULL perch� dopo ci metto IP e porto del client di cui accetto la connesione
			fprintf(stderr, "accept fallito\n");
			return 1;
		}

		// Ricezione della stringa inviata dal client
		memset(buf, 0, sizeof(buf)); //inizializzo a 0 l'area di memoria che mi serve dopo
		read(nsd, &buf, sizeof(buf)); //qua passo nsd, ovvero la socket di servizio: questa la uso in maniera uguae a come la uso per un file, cio�
		printf("Ricevuto dal client: %s\n", buf); //gli passo il buffer da leggere, e la dimensione di ci� che leggo

		// Operazione di conversione sulla stringa ricevuta
		printf("Elaborazione in corso...\n");
		for (i = 0; buf[i] != 0; i++)
			src[i] = (buf[i] >= 97 && buf[i] <= 122) ? (buf[i] - 32) : buf[i];//� un if-tehn-else complesso: la prima paentesi � if, il ? indica il then
		src[i] = '\0';														  //i : indicano l'else, e cos� dico di copiare solo le lettere, non altri caratteri,
																			  //di buff[i] dentro src[i];
		// Simulazione del tempo di elaborazione
		sleep(3);

		// Invio della stringa convertita al client
		write(nsd, &src, strlen(src));
		printf("Inviata al client: %s\n", src);
		
		// Chiusura della socket relativa alla connessione
		close(nsd);
	}

	// Chiusura della socket in ascolto
 	close(sd); //cos� il server i ascolto non pu� pi� rivecere richieste da parte dei client
}

