using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_giu : MonoBehaviour
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
                        testo.text = "Dio lo ha colpito per mano di donna. Così Giuditta, giovane ebrea di Betulia, commenta nella Bibbia\nil suo atto eroico che portò Israele alla liberazione del suo popolo dall’assedio dell’esercito di Nabucodonosor.\nGiuditta si era presentata all’accampamento del crudele Oloferne, capo dell’esercito nemico, vestita nei suoi \nabiti migliori, fingendo di volersi alleare con lui. Il generale assiro, colpito dalla bellezza di lei, la invita \nad un ricco banchetto nella sua tenda. Dopo aver mangiato e bevuto, Oloferne, ubriaco, cade \naddormentato nel suo letto, dando occasione a Giuditta di sottrargli la scimitarra e infierirgli il colpo mortale.\nNell’imponente dipinto degli Uffizi(1620 circa), Artemisia Gentileschi affronta il momento dell’uccisione di \nOloferne per mano di una determinata e vigorosa Giuditta. L’effetto d’insieme è potente e spaventoso: il corpulento\ngenerale è ubriaco e riverso sul letto, la testa afferrata per la chioma, la spada che affonda nel collo. Artemisia\nnon esita ad esibire un dettaglio cruento come il sangue che schizza copiosamente fino a macchiare il petto della\nstessa Giuditta.Il quadro era stato terminato a Roma dove Artemisia era tornata dopo sette anni di \npermanenza a Firenze e dove aveva potuto rinverdire il contatto con le opere caravaggesche.La naturalistica\nvirilità della rappresentazione produsse severe reazioni al suo invio a Firenze e negò al dipinto l’onore di\nun’esposizione privilegiata in Galleria, anzi a fatica la pittrice, e solo per intervento dell’amico Galileo Galilei,\nriuscì a farsi corrispondere con grande ritardo il compenso a suo tempo pattuito dal Granduca Cosimo II de’ Medici,\nscomparso nel 1621, appena dopo l’esecuzione della grande tela. Questo dipinto oggi ci parla anche\ndell'avventura umana e professionale di una donna che scelse di essere artista in un'epoca dominata dagli \nuomini: e vi riuscì, lavorando per le corti di Roma, Firenze, Napoli, spingendosi in Inghilterra e infine\nentrando, prima donna in assoluto, nell'Accademia delle Arti e del Disegno di Firenze.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "God hit him by the hand of a woman. So Judith, a young Jew from Bethlehem, comments in the Bible on \nher heroic act that brought Israel to the liberation of its people from the siege of Nebuchadnezzar's army. Judith \nhad come to the camp of the cruel Holofernes, head of the enemy army, dressed in her best clothes, pretending \nto want to ally with him. The Assyrian general, struck by her beauty, invites her to a rich banquet in her tent. \nAfter eating and drinking, Holofernes, drunk, falls asleep in his bed, giving Judith the \nopportunity to take away his scimitar and give him the death blow. In the imposing painting of the Uffizi (about 1620), \nArtemisia Gentileschi faces the moment of the killing of Holofernes by a determined and vigorous Judith. \nThe overall effect is powerful and frightening: the corpulent general is drunk and leaning back on the bed, his head \ngrasped by his hair, the sword sinking into his neck. Artemisia does not hesitate to exhibit a bloody detail such \nas the blood that splashes copiously until it stains the chest of the same Judith.the painting had been finished \nin Rome where Artemisia had returned after seven years of stay in Florence and where he had been \nable to revive contact with the works of Caravaggio. The naturalistic virility of the representation produced \nsevere reactions to its sending to Florence and denied the painting the honour of a privileged exhibition \nin the Gallery, indeed with difficulty the painter, and only by the intervention of his friend Galileo Galilei, managed \nto make correspond with great delay the compensation agreed at the time by the Grand Duke Cosimo II de 'Medici, \nwho died in 1621, just after the execution of the large canvas. Today this painting also speaks to \nus of the human and professional adventure of a woman who chose to be an artist in an age dominated by men: \nand she succeeded, working for the courts of Rome, Florence, Naples, going to England and finally \nentering, first woman ever, the Academy of Arts and Design in Florence";
                    }
                }
            }
        }
    }
}
