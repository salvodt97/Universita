using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class applica : MonoBehaviour
{
    public GameObject prefabbr;
    public GameObject daSostituire;
    public GameObject padre;
    public int index;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    public void applicaImg()
    {
        index=GameObject.Find("cambiaImg").GetComponent<cambiaImmagine>().indice;
        daSostituire = GameObject.Find("Editare").GetComponent<editareScript>().obj.transform.parent.gameObject;
        switch (index)
        {
            case 0:
                prefabbr = GameObject.Find("P.Adorazione_dei_magi");
                break;
            case 1:
                prefabbr = GameObject.Find("P.Allegoria_sacra");
                break;
            case 2:
                prefabbr = GameObject.Find("P.Angelo_musicante");
                break;
            case 3:
                prefabbr = GameObject.Find("P.Annunciazione");
                break;
            case 4:
                prefabbr = GameObject.Find("P.Annunciazione_Botticelli");
                break;
            case 5:
                prefabbr = GameObject.Find("P.Bacco");
                break;
            case 6:
                prefabbr = GameObject.Find("P.Battaglia_di_San_Romano");
                break;
            case 7:
                prefabbr = GameObject.Find("P.Battesimo_di_Cristo");
                break;
            case 8:
                prefabbr = GameObject.Find("P.Compianto_su_Cristo_morto");
                break;
            case 9:
                prefabbr = GameObject.Find("P.Flora");
                break;
            case 10:
                prefabbr = GameObject.Find("P.Gattamelata");
                break;
            case 11:
                prefabbr = GameObject.Find("P.Giuditta_decapita_Oloferne");
                break;
            case 12:
                prefabbr = GameObject.Find("P.I_duchi_di_Urbino_Federico_da_Montefeltro_e_Battista_Sforza");
                break;
            case 13:
                prefabbr = GameObject.Find("P.L_adorazione_dei_magi");
                break;
            case 14:
                prefabbr = GameObject.Find("P.La_fiera_di_Poggia_a_Caiano");
                break;
            case 15:
                prefabbr = GameObject.Find("P.La_Primavera");
                break;
            case 16:
                prefabbr = GameObject.Find("P.Madonna_col_Bambino_e_due_angeli");
                break;
            case 17:
                prefabbr = GameObject.Find("P.Madonna_col_bambino_e_otto_Santi");
                break;
            case 18:
                prefabbr = GameObject.Find("P.Madonna_col_Bambino_e_San_Giovannino");
                break;
            case 19:
                prefabbr = GameObject.Find("P.Madonna_col_Bambino_in_trono");
                break;
            case 20:
                prefabbr = GameObject.Find("P.Madonna_del_Cardellino");
                break;
            case 21:
                prefabbr = GameObject.Find("P.Natura_morta");
                break;
            case 22:
                prefabbr = GameObject.Find("P.Pallade_e_il_Centauro");
                break;
            case 23:
                prefabbr = GameObject.Find("P.Rinaldo_impedisce_il_suicidio_di_Armida");
                break;
            case 24:
                prefabbr = GameObject.Find("P.Ritratto_di_Francesco_Maria_della_Rovere");
                break;
            case 25:
                prefabbr = GameObject.Find("P.Sacra_Famiglia_con_San_Giovannino");
                break;
            case 26:
                prefabbr = GameObject.Find("P.Sacra_Famiglia_con_San_Girolamo");
                break;
            case 27:
                prefabbr = GameObject.Find("P.Sacrificio_di_Isacco");
                break;
            case 28:
                prefabbr = GameObject.Find("P.Susanna_e_i_vecchioni");
                break;
            case 29:
                prefabbr = GameObject.Find("P.Tebaide");
                break;
            case 30:
                prefabbr = GameObject.Find("P.Venere_di_Urbino");
                break;

        }
        Instantiate(prefabbr, daSostituire.transform.position, daSostituire.transform.rotation).transform.parent=padre.transform;

        Destroy(daSostituire);
    }
}
