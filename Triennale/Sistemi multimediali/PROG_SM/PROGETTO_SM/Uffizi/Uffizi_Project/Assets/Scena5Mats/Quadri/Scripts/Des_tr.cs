using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_tr : MonoBehaviour
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
                        testo.text = "Al centro di un portico, davanti ad architettura marmorea oltre la quale svettano fronde di aranci, \nsiede la Vergine col Bambino, circondata da quattro santi fra i quali figurano i patroni di Firenze Giovanni \nBattista e il vescovo Zanobi. Le figure, disposte con agio e naturalezza, compongono una Sacra conversazione,\nuna reinterpretazione del tradizionale tema dalla Madonna col Bambino e santi raffigurato nei polittici gotici, che \nsi afferma nel XV secolo con la diffusione di pale d’altare di formato quadrato o rettangolare.L’opera è firmata in\nbasso, nel gradino della pedana su cui sta la Vergine, da Domenico Veneziano, uno dei maggiori interpreti e\ninnovatori del Rinascimento fiorentino, nonostante che nei documenti il maestro sia sempre detto originario \ndi Venezia.Il maestro dimostra di padroneggiare l’uso della prospettiva lineare con punto di fuga centrale ideata \nda Filippo Brunelleschi; la luce nitida e tersa, proveniente da destra, esalta la gamma cromatica dai prevalenti \ntoni chiari e tornisce i volumi dei corpi, che proiettano a terra le ombre correttamente orientate. Al candore degli\nincarnati e alla bellezza idealizzata delle figure della Vergine col Bambino e di santa Lucia-quest’ultima ritratta\nnell’atto di portare il piatto gli occhi cavatile durante il martirio - si contrappongono le carnagioni ambrate e i volti\nsegnati dai patimenti e dal tempo dei tre santi, rispettando i modelli iconografici e i canoni estetici in voga nel\nQuattrocento.Nell’ambientazione sono presenti alcuni elementi ancora legati alla tradizione gotica, come \ngli archi a sesto acuto del porticato.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "In the middle of a portico, in front of the marble architecture, beyond which orange branches stand out, \nsits the Virgin and Child, surrounded by four saints, including the patron saints of Florence, Giovanni \nBattista, and Bishop Zanobi. The figures, arranged with ease and naturalness, make up a sacred conversation, a \nreinterpretation of the traditional theme of the Madonna and Child with Saints depicted in the Gothic polyptychs, \nwhich became established in the fifteenth century with the spread of altarpieces in square or rectangular format, \nsigned in lower, on the step of the platform on which stands the Virgin, by Domenico Veneziano, one of the \ngreatest interpreters and innovators of the Florentine Renaissance, despite the fact that in documents the master \nis always said to be a native of Venice.The master demonstrates his mastery of the use of linear perspective \nwith a central vanishing point designed by Filippo Brunelleschi; the clear, clear light, coming from the right, \nenhances the chromatic range of the prevailing light tones and returns the volumes of the bodies, which project the \ncorrectly oriented shadows to the ground. The whiteness of the incarnate and the idealised beauty of the figures of the \nVirgin and Child and Saint Lucy - this last one portrayed in the act of carrying the flat cavatile eyes during martyrdom \n- are contrasted by the amber-coloured complexions and the faces marked by the suffering and time of the three \nsaints, respecting the iconographic models and aesthetic canons in vogue in the 15th century. In the setting \nthere are some elements still linked to the Gothic tradition, such as the pointed arches of the portico";
                    }
                }
            }
        }
    }
}
