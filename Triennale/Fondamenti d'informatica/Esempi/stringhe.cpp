// Prototipi

int  strlen(const char []);
int  strcmp(const char [], const char []);
void strcpy(char [], const char []);
void strrev(char []);

void scambia(char [], int i, int j);


// Definizione delle Funzioni 

int strlen(const char s[]){
  int i=0;
  while (s[i]!='\0') // equivale a:
    i++;             //  while (s[i++]!='\0');
  
  return i;
}


int strcmp(const char s[], const char t[]){
  int i=0;
  while (s[i]==t[i] && s[i]!='\0')
    i++;
  return s[i]-t[i];
}


void strcpy(char s[], const char t[]){
  int i=0;
  while (t[i]!='\0'){
    s[i]=t[i];
    i++;
  }
  s[i]='\0';
}


void strrev(char s[]){
  int i;
  int k=strlen(s);
  for(i=0;i<k/2;i++)
    scambia(s,i,k-i-1);
}

void scambia(char s[], int i, int j){
  char temp=s[i];
  s[i]=s[j];
  s[j]=temp;
}


int main(){

  // main vuoto inserito solo per permettere la compilazione

}
