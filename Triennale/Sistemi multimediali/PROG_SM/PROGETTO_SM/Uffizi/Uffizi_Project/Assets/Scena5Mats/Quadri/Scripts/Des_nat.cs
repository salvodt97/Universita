using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_nat : MonoBehaviour
{
    public Text testo;
    private bool pressione = false;
    private int contatore;
    // Start is called before the first frame update
    void Start()
    {
        pressione = true;
        contatore = 0;
        testo = GetComponent<Text>();
        if (testo)
        {
            testo.text = " ";
        }
    }

    public void ApriDescrizione()
    {

        if (pressione)
        {
            contatore = contatore + 1;
            if (contatore % 2 != 1)
            {
                if (testo)
                {
                    testo.text = "";
                }
            }
            else
            {
                if (testo)
                {
                    if(variabile.italiano)
                    {
                        testo.text = "Una luce limpida cesella con nitidezza fotografica i dettagli della composizione. Tutto è studiato \ncon millimetrica attenzione, come rivela anche il pentimento nel disegno del melone, rimpicciolito \nper non risultare invadente.L’inquadratura ha taglio diagonale e pone lo spigolo della cassa in \nprimo piano, i due libri negli angoli opposti e il panno in velluto con borchie dorate a condurre \nl’occhio verso ulteriori profondità, dove il fondo è piatto e scuro come pietra di paragone. Il pittore \nsceglie oggetti eterogenei: frutta matura di stagione su un piatto d’argento, gli agrumi corrispondenti \nalle preferenze botaniche dei Medici, i cristalli sottilissimi, le lucide e fini porcellane bianche e blu e i libri \nche alludono al piacere costante della lettura. Di questi, , quello su cui poggia l’alzata con i savoiardi, ha \ncome segnalibro una pergamena con la firma dell’autore: un disinvolto ed efficace gioco di trompe - l’oeil, \nsua riconosciuta specialità, che si ripete nel limone sbucciato debordante dal piano. Cristoforo Munari è \nartista di decantata eleganza che, formatosi in ambiente emiliano, raffinò il proprio repertorio a Roma \nfrequentando quello dei naturamortisti nordici tra i quali spiccava il tedesco Christian Berentz, \ndistinguendosene tuttavia per un’adesione più diretta alla realtà anche nella resa pittorica differenziata e \nmimetica, modulata sulla verità dei materiali. Entrò in contatto con il Gran Principe Ferdinando de’ Medici,\ndapprima da Roma in forma epistolare, in seguito a Firenze, dove nel 1706 si immatricolò all’Accademia\nfiorentina del Disegno a riprova di una attività nel Granducato che lo vide al servizio della famiglia medicea,\nma anche di altri collezionisti. Con la precoce morte di Ferdinando la sua fortuna gradualmente andò \nesaurendosi tanto da finire i suoi giorni in ristrettezze economiche e dedicandosi soprattutto all’attività \ndi restauratore.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "A clear light chisels with photographic sharpness the details of the composition. Everything is \nstudied with millimetric attention, as also revealed by the repentance in the drawing of the melon, which \nhas been reduced in size so as not to be intrusive. the framing has a diagonal cut and places \nthe edge of the case in the foreground, the two books in opposite corners and the velvet cloth with \ngolden studs to lead the eye to further depths, where the bottom is flat and dark as a comparison stone. \nThe painter chooses heterogeneous objects: ripe seasonal fruit on a silver plate, citrus fruits corresponding \nto the botanical preferences of the Medici, very fine crystals, glossy and fine blue and white porcelain \nand books alluding to the constant pleasure of reading. Of these, the one on which the riser with the Savoyards \nrests, has as its bookmark a parchment with the author's signature: a casual and effective game of trompe l'oeil, \nhis recognized specialty, which is repeated in the peeled lemon overflowing from the plane. Cristoforo \nMunari is an artist of exalted elegance who, formed in Emilia, refined his repertoire in Rome attending \nthat of the Nordic naturemortists among whom stood out the German Christian Berentz, however \ndistinguishing himself for a more direct adherence to reality even in the pictorial rendering differentiated and\nmimetic, modulated on the truth of the materials. He came into contact with the Grand Prince Ferdinando de' \nMedici, first from Rome in letter form, then in Florence, where in 1706 he enrolled at the Florentine \nAcademy of Drawing as proof of an activity in the Grand Duchy that saw him at the service of the Medici family, \nbut also of other collectors. With the early death of Ferdinand his fortune gradually went exhausting \nso much to end his days in financial straits and devoting himself above all to the activity of restorer";
                    }
                }
            }
        }
    }
}
