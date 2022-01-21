using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class cambiaImmagine : MonoBehaviour
{
    private Texture[] vettore = new Texture[31];
    public int indice = 0;
    public int memoria = 0;

    // Start is called before the first frame update
    void Start()
    {
        vettore[0] = Resources.Load("Adorazione dei magi") as Texture;
        vettore[1] = Resources.Load("Allegoria sacra") as Texture;
        vettore[2] = Resources.Load("Angelo musicante") as Texture;
        vettore[3] = Resources.Load("annunciazione") as Texture;
        vettore[4] = Resources.Load("Annunciazione Botticelli") as Texture;
        vettore[5] = Resources.Load("bacco") as Texture;
        vettore[6] = Resources.Load("Battaglia di San Romano") as Texture;
        vettore[7] = Resources.Load("Battesimo di Cristo") as Texture;
        vettore[8] = Resources.Load("Compianto su Cristo Morto") as Texture;
        vettore[9] = Resources.Load("flora") as Texture;
        vettore[10] = Resources.Load("gattamelata") as Texture;
        vettore[11] = Resources.Load("Giuditta decapita Oloferne") as Texture;
        vettore[12] = Resources.Load("I duchi di Urbino Federico da Montefeltro e Battista Sforza") as Texture;
        vettore[13] = Resources.Load("L'adorazione dei magi") as Texture;
        vettore[14] = Resources.Load("La fiera di Poggia a Caiano") as Texture;
        vettore[15] = Resources.Load("Primavera") as Texture;
        vettore[16] = Resources.Load("Madonna col Bambino e due angeli") as Texture;
        vettore[17] = Resources.Load("Madonna col Bambino e otto Santi") as Texture;
        vettore[18] = Resources.Load("Madonna col Bambino e San Giovannino") as Texture;
        vettore[19] = Resources.Load("Madonna col Bambino in trono") as Texture;
        vettore[20] = Resources.Load("madonna del cardellino") as Texture;
        vettore[21] = Resources.Load("Natura morta") as Texture;
        vettore[22] = Resources.Load("Pallade e il Centauro") as Texture;
        vettore[23] = Resources.Load("Rinaldo impedisce il suicidio di Armida") as Texture;
        vettore[24] = Resources.Load("Ritratto di Francesco Maria della Rovere") as Texture;
        vettore[25] = Resources.Load("Sacra Famiglia con San Giovannino") as Texture;
        vettore[26] = Resources.Load("Sacra famiglia con San Girolamo") as Texture;
        vettore[27] = Resources.Load("Sacrificio di Isacco") as Texture;
        vettore[28] = Resources.Load("Susanna e i vecchioni") as Texture;
        vettore[29] = Resources.Load("tebaide") as Texture;
        vettore[30] = Resources.Load("Venere di Urbino") as Texture;





        this.GetComponent<RawImage>().texture = vettore[0];
        //Resources.Load<Texture>("bellini");
    }

    // Update is called once per frame
    void Update()
    {
        if (indice < 0 || indice > 30)
        {
            indice = 0;
        }

        if (indice != memoria)
        {
            aggiornaImg();
        }
    }

    void aggiornaImg()
    {
        this.GetComponent<RawImage>().texture = vettore[indice];
        
        memoria = indice;
    }
}
