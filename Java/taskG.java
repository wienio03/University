/*Program opiera siÄ na zaprezentowanym na wykĹadzie algorytmie magicznych piÄtek i selekcji.
GĹĂłwna metoda jest rekurencyjna (selectPivot) i sluzy ona do wybrania mediany median jako pivota wzgledem ktorego
dokonywany jest podzial tablicy, na podstawie ktorego metoda findElement zwraca k-ty co do wielkosci element tablicy
podanej na wejsciu programu. Zlozonosc pesymistyczna wzgledem rozmiaru danych jest liniowa, co jest gwarantowane przez uzycie algorytmu magicznych
piatek. Grupy piecioelementowe sa sortowane sortowaniem przez wstawianie, koszt to n/5.
 */
import java.util.Scanner;
public class Source {
    //metoda zwracajaca k-ty co do wielkosci element tablicy
    public static int findElement(int[] array, int k) {
        int left = 0;
        int right = array.length - 1;

        while (left < right) {
            int pivotIndex = partition(array, left, right);

            if (k == pivotIndex + 1) {
                return array[pivotIndex];
            } else if (k < pivotIndex + 1) {
                right = pivotIndex - 1;
            } else {
                left = pivotIndex + 1;
            }
        }

        return array[left];
    }
    //metoda partycji wg. Lomuto (jak na wykladzie)
    public static int partition(int[] array, int left, int right) {
        int pivotIndex = selectPivot(array, left, right);
        int pivotValue = array[pivotIndex];

        swap(array, pivotIndex, right);

        int i = left;

        for (int j = left; j < right; j++) {
            if (array[j] <= pivotValue) {
                swap(array, i, j);
                i++;
            }
        }

        swap(array, i, right);

        return i;
    }
    //metoda zawierajaca algorytm magicznych piatek i wybierajaca element dzielacy (pivot)
    public static int selectPivot(int[] array, int left, int right) {
        int numGroups = (right - left + 1) / 5;
        if ((right - left + 1) % 5 != 0) {
            numGroups++;
        }
        for (int i = 0; i < numGroups; i++) {
            int groupLeft = left + i * 5;
            int groupRight = groupLeft + 4 < right ? groupLeft + 4 : right;
            int medianIndex = findMedianIndex(array, groupLeft, groupRight);
            swap(array, medianIndex, left + i);
        }

        if (numGroups == 1) {
            return left;
        } else {
            return selectPivot(array, left, left + numGroups - 1);
        }
    }
    //metoda zwracajaca indeks mediany z grup 5 elementowych, korzystajaca z sortowania przez wstawianie
    public static int findMedianIndex(int[] array, int left, int right) {
        insertionSort(array, left, right);
        return (left + right) / 2;
    }
    //sortowanie przez wstawianie
    public static void insertionSort(int[] array, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int key = array[i];
            int j = i - 1;

            while (j >= left && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }

            array[j + 1] = key;
        }
    }

    public static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    public static void main(String[] args) {
        //zmienne
        Scanner scanner = new Scanner(System.in);
        int array[];
        int sets;
        int inquiries;
        int arraySize;
        int k;
        //glowny program
        sets = scanner.nextInt();
        for (int i = 0; i < sets; i++) {
            arraySize = scanner.nextInt();
            array = new int[arraySize];
            for (int j = 0; j < array.length; j++)
                array[j] = scanner.nextInt();
            inquiries = scanner.nextInt();
            for (int j = 0; j < inquiries; j++) {
                k = scanner.nextInt();
                if (k > 0 && k <= array.length)
                    System.out.println(k + " " + findElement(array, k));
                else
                    System.out.println(k + " brak");
            }
        }
        scanner.close();

    }
}
