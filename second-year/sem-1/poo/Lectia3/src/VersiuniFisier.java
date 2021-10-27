public class VersiuniFisier {
    private String name;
    private String content;
    private static int id_counter;
    private final int id;
    private VersiuniFisier previousVersion;
    private int nrCon;

    public VersiuniFisier(String name, String content) {
        this.name = name;
        this.content = content;
        id = id_counter;
        id_counter++;
    }

    public void salveazaVersiune() {
        VersiuniFisier transObject = new VersiuniFisier(this.name+"bak",this.content);
        transObject.previousVersion = this.previousVersion;
        this.previousVersion = transObject;
    }

    public void concateneaza(VersiuniFisier fisier) {
        salveazaVersiune();
        this.content += fisier.content;
        nrCon++;
    }

    @Override
    public String toString() {
        String fstStr = this.id + " " + this.name + " [" + this.content + "] ";
        String sndStr = "<No previous version>";
        if(previousVersion != null) {
            sndStr = "<" + previousVersion.id + " " + previousVersion.name +
                    " [" + previousVersion.content + "]>";
        }
        return fstStr + sndStr;
    }

    public int numarConcatenari() {
        return nrCon;
    }
}
