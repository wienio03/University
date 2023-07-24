import java.util.Scanner;
//program wykorzystuje metode BinSearchFirst o zlozonosci O(logn) do wyszukania pierwszego wystapienia lewego kresu przedzialu
//oraz do wyszukania pierwszego wystapienia elementu wiekszego od prawego kresu przedzialu
//nastepnie obliczam dlugosc fragmentu spelniajacego warunek odejmujac indeksy wyszukanych elementow
//metoda FindDistinctElements dla posortowanej tablicy ma zlozonosc O(n) i znajduje ilosc rozroznialnych elementow
class Source {

    long[] array;
    int BinSearchFirst(long x) {
        int lower = 0, upper = this.array.length - 1, current, index = -1; // ograniczenie dolne tablicy, ograniczenie gorne tablicy, obecny indeks, zwracany indeks
        //inicjujemy pojedyncze zmienne wiec zlozonosc pamieciowa pozostaje jako O(1)
        while (lower <= upper) {
            current = (lower + upper) / 2;
            //jezeli znajdziemy szukany element, to moze byc to pierwsze wystapienie, zapisujemy indeks w zmiennej index
            //ale kontynuujemy szukanie na lewo od elementu, poniewaz tylko tam moze wystapic domniemane pierwsze wystapienie
            //na koncu zwracamy indeks
            if (this.array[current] >= x) {
                index = current;
                upper = current - 1;
            }
            else
                lower = current + 1;
        }
        //jesli nie ma elementu zwracamy lower
        if(index == -1)
            return lower;
        else
            return index;
    }
    int FindDistinctElements(){
        //inicjujemy licznik rozroznialnych elementow(zlozonosc pamieciowa O(1))
        int distinctCounter = 0;
        //przechodzimy przez cala tablice
        for(int i = this.array.length -1 ; i >= 1 ; i--){
            //przechodzimy po calej tablicy i sprawdzamy czy elementy sa od siebie rozne, jesli tak to dodajemy do licznika
            //zwracamy licznik powiekszony o 1 aby wziac pod uwage ostatni porownywany prawy element z pary
            if(this.array[i] != this.array[i-1])
                distinctCounter++;
        }
        return distinctCounter + 1;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Source source = new Source();
        //zmienne
        int dataSets;
        int arraySize;
        int inquiryAmount;
        long leftBound;
        long rightBound;
        int people;
        //wczytywanie wejscia
        dataSets = scanner.nextInt();
        while(dataSets > 0){
            arraySize = scanner.nextInt();
            source.array = new long[arraySize];
            for(int i = 0; i < source.array.length ; i++)
                source.array[i] = scanner.nextInt();
            inquiryAmount = scanner.nextInt();
            for(int i = 0; i < inquiryAmount ; i++){
                leftBound = scanner.nextInt();
                rightBound = scanner.nextInt();
                //jezeli lewy kres jest wiekszy niz prawy, to wypisujemy 0
                if(leftBound > rightBound)
                    System.out.println(0);
                else{
                    //szukamy pierwszego wystapienia lewego kresu i pierwszego wystapienia liczby o jeden wiekszej od prawego kresu(liczb >= tym kresom)
                    people = source.BinSearchFirst(rightBound+1) - source.BinSearchFirst(leftBound);
                    System.out.println(people);
                }
            }
            System.out.println(source.FindDistinctElements());
            dataSets--;
        }

    }
}
