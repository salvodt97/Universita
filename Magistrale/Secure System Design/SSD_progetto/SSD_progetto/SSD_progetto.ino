const char *password = "3005199813";    //password memorizzata
const int LED_PIN = 13;                 //led da accendere

void setup() {
  Serial.begin(9600);                   //apre la porta seriale e setta il data rate a 9600 bit al secondo
  pinMode(LED_PIN, OUTPUT);             //il pin 13 è impostato su output
  digitalWrite(LED_PIN, LOW);           //setta il valore del PIN a 0 volt
}
/*************DEFINIZIONE FUNZIONE CHECK***************/
bool check_password(char* pwd){
  int i;
  for(i = 0; i < strlen(password); i++)           //controllo che i singoli caratteri inseriti coincidano con quelli della password memorizzata
    if(pwd[i] != password[i])
      return false;                         //se l'i-esimo carattere è diverso esco dal ciclo e ritorno 0
  
  return true;                             //ritorno 1 se il ciclo termina correttamente
}

void loop() {
  char buffer_1[32];
  int n_bytes;
  bool controllo;
  
  Serial.setTimeout(10);              //setto il tempo massimo (in millisecondi) da attendere per l'input seriale
  while(!Serial.available())      //la funzione Serial.available() restituisce il numero di caratteri disponibili per la lettura 
    delay(1);                        //se non sono disponibili caratteri la funzione delay() mette in pausa il programma per 10 ms
  n_bytes = (Serial.readBytesUntil('\n',buffer_1, 31));  //la funzione Serial.readBytes() legge i caratteri dalla porta seriale e li inserisce in un buffer; la funzione termina  
                                                //se la lunghezza fornita come parametro è stata letta e restituisce il numero di caratteri posizionati nel buffer
  buffer_1[n_bytes] = 0;                     //azzera il primo carattere dopo quello della password
  //if(strlen(buffer_1) == strlen(password)){
    digitalWrite(LED_PIN, HIGH);         //accendo il led per attivare un segnale per usare l'oscilloscopio
    controllo = check_password(buffer_1);   //chiama la funzione check per il carattere
    //delay(2000);
    digitalWrite(LED_PIN, LOW);         //spengo il led

    if(controllo)
      Serial.println("PASSWORD CONFERMATA");
    else Serial.println("PASSWORD ERRATA");
  }
  //else Serial.println("LA PASSWORD INSERITA HA DIMENSIONI ERRATE");
//}




/*FUNZIONAMENTO BREADBOARD:
 * La corrente passa verticalmente, ad eccezione delle due strisce alle estremità in cui è 
 * distribuita orizzontalmente. Nei LED il gambo più lungo è il negativo, il più corto è il positivo (il positivo va sempre a destra).
 * Per diminuire la tensione (3.3V per un led è tanta) ho usato una resistenza da 330 Ohm per creare un ponte tra le due sezioni.
 */
