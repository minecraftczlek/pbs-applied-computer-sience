package lab.Intro;

public class Main {
    public static void main(String[] args){
//        test();

        testDziedziczenia();
    }

    private static void test() {
        System.out.println("żegnaj świecie!");

        double[] tab = new double[] {3.5, 5.5, 13, 3, 6.6};
        System.out.println("Wynik: " + srednia(tab));
    }

    private static void testDziedziczenia() {
        Pojazd samBMW = new Pojazd("BMW", TypSilnikaEnum.SPALINOWY, 4, true);
        Segway segwayI = new Segway("SegwayI", TypSilnikaEnum.ELEKTRYCZNY, 2, true, 1);

        boolean zgodna = samBMW.isZgodnaKategoria(segwayI);
        System.out.printf("BMW -> SegwayI: %b %n", zgodna);

        Segway segwayII = new Segway("segwayII", TypSilnikaEnum.ELEKTRYCZNY, 2, true, 2);
        zgodna = segwayI.isZgodnaKategoria(segwayII);
        System.out.printf("SegwayI -> SegwayII: %b %n", zgodna);

        Segway segwayIIDeluxe = new Segway("segwayIIDeluxe", TypSilnikaEnum.ELEKTRYCZNY, 2, true, 2);
        zgodna = segwayII.isZgodnaKategoria(segwayIIDeluxe);
        System.out.printf("SegwayII -> SegwayIIDeluxe: %b %n", zgodna);
    }

    public static double srednia(double[] tab){
        double wynik = 0 ;

        for(int i=0; i < tab.length; i++)wynik += tab[i];

        return wynik / tab.length;
    }
}

