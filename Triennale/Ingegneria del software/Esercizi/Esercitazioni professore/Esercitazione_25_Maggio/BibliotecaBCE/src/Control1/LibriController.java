package Control1;

public class LibriController {
	 static public int cercaLibroInScaffale(String Titolo, int NumScaffale) {
		return Entity1.Biblioteca.cercaLibro(Titolo, NumScaffale);
	}
}
