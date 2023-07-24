import java.util.Scanner;
/*
Program wykorzystuje algorytm sortowania przez scalanie. Zlozonosc pamieciowa jest zredukowana poprzez zapewnienie
uzycia tablicy pomocniczej o rozmiarze (n/2)+1, gdzie n jest dlugoscia tablicy glownej. Program wywoluje w metodzie Inversion rekurencyjnie sama siebie.
 */
public class Source {
    public static long Inversion(long[] array, int L, int R, long[] tmp) {
        //base case dla rekurencji
        if (L >= R)
            return 0;
        else {
            long inversions = 0;
            int M = ((L + R) / 2);
            //merge sort dla tablicy lewej i prawej oraz zliczanie inwersji
            inversions += Inversion(array, L, M, tmp);
            inversions += Inversion(array, M + 1, R, tmp);
            inversions += merge(array, L, M, R, tmp);
            return inversions;
        }
    }
    public static long merge(long[] array, int L, int M, int R, long[] tmp) {
        long inversions = 0;
        int i = L;
        int j = M + 1;
        int k = L;
        int tmpIter = 0;
        //kopiujemy lewa czesc tablicy aby moc ja nadpisywac
        for(int l = L, n = 0; n < tmp.length && l <= M; l++, n++)
            tmp[n] = array[l];
        //algorytm sortowania i scalania dla tablicy dlugosci (n/2) + 1
        while(i <= M && j <= R){
            if(tmp[tmpIter] <= array[j]) {
                array[k++] = tmp[tmpIter++];
                i++;
            }
            else{
                array[k++] = array[j++];
                //dodajemy do inwersji M - i + 1 poniewaz scalane tablice sa posortowane i w tej sytuacji
                //wszystkie elementy pomiedzy tymi dwoma sa inwerjsami
                inversions += (M - i + 1);
            }
        }
        //scalanie
        while(i <= M){
            array[k++] = tmp[tmpIter++];
            i++;
        }
        while(j <= R)
            array[k++] = array[j++];
        return inversions;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int sets = scanner.nextInt();
        int size;
        long[] tmp;
        for(int i = 0; i < sets; i++){
            size = scanner.nextInt();
            long[] array = new long[size];
            for(int j = 0; j < size; j++)
                array[j] = scanner.nextLong();
            tmp = new long[(array.length / 2) + 1];
            long x = Inversion(array, 0, array.length - 1, tmp);
            System.out.println(x);
        }
    }
}
