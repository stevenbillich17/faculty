public class Main {

    public static void main(String[] args) {
        VersiuniFisier first = new VersiuniFisier("f1","steven");
        VersiuniFisier second = new VersiuniFisier("f2","Wow");
        System.out.println(first);
        first.concateneaza(second);
        System.out.println(first);
        System.out.println(first.numarConcatenari());

        second.salveazaVersiune();
        second.salveazaVersiune();
        second.salveazaVersiune();
        System.out.println(second);
        System.out.println(second.numarConcatenari());
    }
}
