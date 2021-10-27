class Tir{
    private int nrRemorci;
    private static final int NUMAR_MAXIM_REMORCI = 5;
    private Remorca[] remorci = new Remorca[NUMAR_MAXIM_REMORCI];

    public boolean adaugaRemorca(int nrCutii, String nrInmatriculare) {
        return this.adaugaRemorca(new Remorca(nrCutii,nrInmatriculare));
    }

    public boolean adaugaRemorca(Remorca x) {
        if(nrRemorci >= NUMAR_MAXIM_REMORCI) {
            return false;
        } else {
            remorci[nrRemorci] = x;
            nrRemorci++;
            return true;
        }
    }

    public Remorca stergeRemorca(String nrInmatriculare) {
        for(int i=0; i<nrRemorci; i++) {

            if(remorci[i].hasSameNumber(nrInmatriculare)) {
                Remorca remorcaGasita = remorci[i];

                for(int j=i; j<nrRemorci-1; j++) {
                    remorci[j]=remorci[j+1];
                }
                remorci[nrRemorci-1]=null;
                nrRemorci--;

                return remorcaGasita;
            }
        }
        return null;
    }

    private int calculeazaCapacitate() {
        return Remorca.calculeazaSumaElementelor(remorci,nrRemorci);
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Tir) {
            int numarCutii1 = this.calculeazaCapacitate();
            int numarCutii2 = ((Tir) obj).calculeazaCapacitate();
            return numarCutii1 == numarCutii2;
        }
        return false;
    }

    @Override
    public String toString() {
        String afisare = "T -> ";
        for(int i=0; i<nrRemorci-1; i++) {
            afisare = afisare.concat(remorci[i].toString());
            afisare = afisare.concat(" -> ");
        }
        afisare = afisare.concat(remorci[nrRemorci-1].toString());
        return afisare;
    }
}

class Remorca{
    private int nrCutii;
    private String nrInmatriculare;
    private static int nrCutiiGenerator = 10;

    public Remorca(int nrCutii, String nrInmatriculare) {
        this.nrCutii = nrCutii;
        this.nrInmatriculare = nrInmatriculare;
        nrCutiiGenerator = nrCutii+1;
    }

    public Remorca(String nrInmatriculare) {
        this(nrCutiiGenerator,nrInmatriculare);
    }

    public boolean hasSameNumber(String nrCautat) {
        return this.nrInmatriculare.equals(nrCautat);
    }

    public String toString() {
        return "R(" + this.nrInmatriculare + ", " + this.nrCutii  + ")";
    }

    public static int calculeazaSumaElementelor(Remorca[] vecRemorci, int nrElem) {
        int sum = 0;
        for(int i=0; i<nrElem; i++) {
            sum += vecRemorci[i].nrCutii;
        }
        return sum;
    }
}

public class Main {

    public static void main(String[] args) {
        Tir myTir = new Tir();
        Remorca myRemorca = new Remorca("TM 55 STV");
        myTir.adaugaRemorca(myRemorca);

        Boolean x = myTir.adaugaRemorca(234,"TM 21 BVOMB");
        myTir.adaugaRemorca(new Remorca("TM 22 HAISA"));
        myTir.adaugaRemorca(22,"TM 99 YESS");
        myTir.adaugaRemorca(25,"TM wow");
        myTir.adaugaRemorca(345,"MH 27 WOW");

        System.out.println(myTir);

        myTir.stergeRemorca("TM 22 HAISA");

        System.out.println(myTir);

        Remorca wow = myTir.stergeRemorca("TM wow");

        System.out.println(myTir);
        System.out.println(wow);

        Tir estee = new Tir();
        estee.adaugaRemorca(263,"BESTIE");

        System.out.println(estee.equals(myTir));
    }
}
