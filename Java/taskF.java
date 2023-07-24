import java.util.Scanner;
//program wykorzystuje klase Index ktora jest zbiorem wartosci calkowitych (w moim przypadku 1), ktora sluzy
//do opisanego na wykladzie markowania indeksow podzadan w celu zredukowania zlozonosci pamieciowej do stalej
//poza tym w programie uzywane sa metody partycji (taka jak uzywana na wykladzie) oraz sortowanie szybkie (jego modyfikacja w formie iteracyjnej)

//opisana klasa Index
class Index{
    int[] arr;
    Index(int cols){
        arr = new int[cols];
        for(int i = 0; i < arr.length; i++)
            arr[i] = 1;
    }
}
public class Source {
    //sprawdzenie czy porownywane elementy beda liczbami
    public static boolean isInteger(String arg){
        boolean isNum = true;
        try{
            Integer.parseInt(arg);
        }
        catch(NumberFormatException error){
            isNum = false;
        }
        return isNum;
    }
    //metoda umozliwiajaca szukanie nastepnego pivota
    public static int findNegativeIndex(int length, int L, Index index){
        for(int i = L; i < length; i++)
            if(index.arr[i] < 0)
                return i;
        return -1;

    }
    //partycja w przypadku sortowania niemalejacego (na wejsciu 1)
    //z rozdzialem na przypadki dla liczb i ciagow znakowych
    public static int partitionAscending(String[][] arr, int L, int R, int C){
        String pivot = arr[(L + R) / 2][C];
        if(isInteger(pivot)){
            while(L <= R){
                while(Integer.parseInt(arr[R][C]) > Integer.parseInt(pivot))
                    R--;
                while(Integer.parseInt(arr[L][C]) < Integer.parseInt(pivot))
                    L++;
                if(L <= R){
                    String[] tmp = arr[R];
                    arr[R] = arr[L];
                    arr[L] = tmp;
                    L++;
                    R--;
                }
            }
        }
        else{
            while(L <= R){
                while(arr[R][C].compareTo(pivot) > 0)
                    R--;
                while(arr[L][C].compareTo(pivot) < 0)
                    L++;
                if(L <= R){
                    String[] tmp = arr[R];
                    arr[R] = arr[L];
                    arr[L] = tmp;
                    L++;
                    R--;
                }
            }
        }
        return L;
    }
    //partycja w przypadku sortowania malejacego (na wejsciu 1)
    //z rozdzialem na przypadki dla liczb i ciagow znakowych
    public static int partitionDescending(String[][] arr, int L, int R, int C){
        String pivot = arr[(L + R) / 2][C];
        if(isInteger(pivot)){
            while(L <= R){
                while(Integer.parseInt(arr[R][C]) < Integer.parseInt(pivot))
                    R--;
                while(Integer.parseInt(arr[L][C]) > Integer.parseInt(pivot))
                    L++;
                if(L <= R){
                    String[] tmp = arr[R];
                    arr[R] = arr[L];
                    arr[L] = tmp;
                    L++;
                    R--;
                }
            }
        }
        else{
            while(L <= R){
                while(arr[R][C].compareTo(pivot) < 0)
                    R--;
                while(arr[L][C].compareTo(pivot) > 0)
                    L++;
                if(L <= R){
                    String[] tmp = arr[R];
                    arr[R] = arr[L];
                    arr[L] = tmp;
                    L++;
                    R--;
                }
            }
        }
        return L;
    }
    //metoda sortowania szybkiego ze zlozonoscia pamieciowa zredukowana do O(1)
    //przypadek gdy sortowanie jest malejace
    //rozdzial na przypadki gdy jest liczba calkowita lub ciagiem znakowym
    public static void quickSortAscending(String[][] arr, int C){
        int iter = 0;
        int L = 0;
        int R = arr.length - 1;
        int pivot;
        int tmpRight = R;
        Index indexes = new Index(arr.length);
        if(isInteger(arr[0][C])){
            while(true){
                iter--;
                while(L < tmpRight){
                    pivot = partitionAscending(arr, L, tmpRight, C);
                    if(tmpRight - pivot + 1 <= 5){
                        selectionSortAscending(arr, pivot, tmpRight, C);
                    }
                    if(pivot - L <= 5){
                        selectionSortAscending(arr, L, pivot - 1, C);
                    }
                    if(tmpRight - pivot + 1 <= 5 && pivot - L <= 5){
                        L = pivot + 1;
                    }
                    else if(pivot - L <= 5){
                        L = pivot;
                        iter++;
                    }
                    else if(tmpRight - pivot + 1 <= 5){
                        tmpRight = pivot - 1;
                        indexes.arr[tmpRight] = -indexes.arr[tmpRight];
                        iter++;
                    }
                    else{
                        indexes.arr[tmpRight] = -indexes.arr[tmpRight];
                        tmpRight = pivot - 1;
                        iter++;
                    }
                }
                if(iter < 0)
                    break;
                tmpRight = findNegativeIndex(arr.length, L, indexes);
                if(tmpRight != -1){
                    indexes.arr[tmpRight] = -indexes.arr[tmpRight];
                }
            }
        }
        else{
            while(true){
                iter--;
                while(L < tmpRight){
                    pivot = partitionAscending(arr, L, tmpRight, C);
                    if(tmpRight - pivot + 1 <= 5){
                        selectionSortAscending(arr, pivot, tmpRight, C);
                    }
                    if(pivot - L <= 5){
                        selectionSortAscending(arr, L, pivot - 1, C);
                    }
                    if(tmpRight - pivot + 1 <= 5 && pivot - L <= 5){
                        L = pivot + 1;
                    }
                    else if(pivot - L <= 5){
                        L = pivot;
                        iter++;
                    }
                    else if(tmpRight - pivot + 1 <= 5){
                        tmpRight = pivot - 1;
                        indexes.arr[tmpRight] = -indexes.arr[tmpRight];
                        iter++;
                    }
                    else{
                        indexes.arr[tmpRight] = -indexes.arr[tmpRight];
                        tmpRight = pivot - 1;
                        iter++;
                    }
                }
                if(iter < 0)
                    break;
                tmpRight = findNegativeIndex(arr.length, L, indexes);
                if(tmpRight != -1){
                    indexes.arr[tmpRight] = -indexes.arr[tmpRight];
                }
            }
        }
    }
    //metoda sortowania szybkiego ze zlozonoscia pamieciowa zredukowana do O(1)
    //przypadek gdy sortowanie jest malejace
    //rozdzial na przypadki gdy jest liczba calkowita lub ciagiem znakowym
    public static void quickSortDescending(String[][] arr, int C){
        int iter = 0;
        int L = 0;
        int R = arr.length - 1;
        int pivot;
        int tmpRight = R;
        Index indexes = new Index(arr.length);
        if(isInteger(arr[0][C])){
            while(true){
                iter--;
                while(L < tmpRight){
                    pivot = partitionDescending(arr, L, tmpRight, C);
                    if(tmpRight - pivot + 1 <= 5){
                        selectionSortDescending(arr, pivot, tmpRight, C);
                    }
                    if(pivot - L <= 5){
                        selectionSortDescending(arr, L, pivot - 1, C);
                    }
                    if(tmpRight - pivot + 1 <= 5 && pivot - L <= 5){
                        L = pivot + 1;
                    }
                    else if(pivot - L <= 5){
                        L = pivot;
                        iter++;
                    }
                    else if(tmpRight - pivot + 1 <= 5){
                        tmpRight = pivot - 1;
                        indexes.arr[tmpRight] = -indexes.arr[tmpRight];
                        iter++;
                    }
                    else{
                        indexes.arr[tmpRight] = -indexes.arr[tmpRight];
                        tmpRight = pivot - 1;
                        iter++;
                    }
                }
                if(iter < 0)
                    break;
                tmpRight = findNegativeIndex(arr.length, L, indexes);
                if(tmpRight != -1){
                    indexes.arr[tmpRight] = -indexes.arr[tmpRight];
                }
            }
        }
        else{
            while(true){
                iter--;
                while(L < tmpRight){
                    pivot = partitionDescending(arr, L, tmpRight, C);
                    if(tmpRight - pivot + 1 <= 5){
                        selectionSortDescending(arr, pivot, tmpRight, C);
                    }
                    if(pivot - L <= 5){
                        selectionSortDescending(arr, L, pivot - 1, C);
                    }
                    if(tmpRight - pivot + 1 <= 5 && pivot - L <= 5){
                        L = pivot + 1;
                    }
                    else if(pivot - L <= 5){
                        L = pivot;
                        iter++;
                    }
                    else if(tmpRight - pivot + 1 <= 5){
                        tmpRight = pivot - 1;
                        indexes.arr[tmpRight] = -indexes.arr[tmpRight];
                        iter++;
                    }
                    else{
                        indexes.arr[tmpRight] = -indexes.arr[tmpRight];
                        tmpRight = pivot - 1;
                        iter++;
                    }
                }
                if(iter < 0)
                    break;
                tmpRight = findNegativeIndex(arr.length, L, indexes);
                if(tmpRight != -1){
                    indexes.arr[tmpRight] = -indexes.arr[tmpRight];
                }
            }
        }
    }
    //metoda sortowania przez selekcje dla podzadan o dlugosci <= 5 oraz rozdzielajaca przyypadki
    //gdy porownywane elementy to liczby oraz gdy porowynwane elementy to ciagi znakowe
    public static void selectionSortAscending(String[][] arr, int L, int R, int C){

        if(!isInteger(arr[0][C])){
            for(int i = L; i < R; i++){
                int min = i;
                for(int j = i + 1; j <= R; j++){
                    if(arr[j][C].compareTo(arr[min][C]) < 0)
                        min = j;
                }
                String[] tmp = arr[i];
                arr[i] = arr[min];
                arr[min] = tmp;
            }
        }
        else{
            for(int i = L; i < R; i++){
                int min = i;
                for(int j = i + 1; j <= R; j++){
                    if(Integer.parseInt(arr[j][C]) < Integer.parseInt(arr[min][C]))
                        min = j;
                }
                String[] tmp = arr[i];
                arr[i] = arr[min];
                arr[min] = tmp;
            }
        }
    }
    //metoda sortowania przez selekcje dla podzadan o dlugosci <= 5 oraz rozdzielajaca przyypadki
    //gdy porownywane elementy to liczby oraz gdy porowynwane elementy to ciagi znakowe
    public static void selectionSortDescending(String[][] arr, int L, int R, int C){
        if(!isInteger(arr[0][C])){
            for(int i = L; i < R; i++){
                int min = i;
                for(int j = i + 1; j <= R; j++){
                    if(arr[j][C].compareTo(arr[min][C]) > 0)
                        min = j;
                }
                String[] tmp = arr[i];
                arr[i] = arr[min];
                arr[min] = tmp;
            }
        }
        else{
            for(int i = L; i < R; i++){
                int min = i;
                for(int j = i + 1; j <= R; j++){
                    if(Integer.parseInt(arr[j][C]) > Integer.parseInt(arr[min][C]))
                        min = j;
                }
                String[] tmp = arr[i];
                arr[i] = arr[min];
                arr[min] = tmp;
            }
        }
    }
    //w efekcie srednia zlozonosc czasowa to O(n*log2(n)) oraz zlozonosc pamieciowa jest stala, poniewaz nie tworzymy zadnych dodatkowych tablic
    //jedynie tworzony jest obiekt typu Index potrzebny do markowania indeksow
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int sets;
        String numbers[];
        String headers[];
        String[][] array;
        sets = sc.nextInt();
        sc.nextLine();
        for(int i = 0; i < sets; i++){
            numbers = sc.nextLine().split(",");
            headers = sc.nextLine().split(",");
            array = new String[Integer.parseInt(numbers[0])][headers.length];
            for(int j = 0; j < array.length; j++)
                array[j] = sc.nextLine().split(",");
            if(Integer.parseInt(numbers[2]) == 1)
                quickSortAscending(array, Integer.parseInt(numbers[1]) - 1);
            else if(Integer.parseInt(numbers[2]) == -1)
                quickSortDescending(array, Integer.parseInt(numbers[1]) - 1);
            for(int j = Integer.parseInt(numbers[1]) - 1; j > 0; j--){
                String aux = headers[j];
                headers[j] = headers[j - 1];
                headers[j - 1] = aux;
            }
            for(int j = 0; j < array.length; j++){
                for(int k = Integer.parseInt(numbers[1]) - 1; k > 0; k--){
                    String aux = array[j][k];
                    array[j][k] = array[j][k - 1];
                    array[j][k - 1] = aux;
                }
            }
            for(int j = 0; j < array[0].length; j++){
                System.out.print(headers[j]);
                if(j + 1 != array[0].length)
                    System.out.print(",");
            }
            System.out.print("\n");
            for(int j = 0; j < array.length; j++){
                for(int k = 0; k < array[0].length; k++){
                    System.out.print(array[j][k]);
                    if(k + 1 != array[0].length)
                        System.out.print(",");
                }
                System.out.print("\n");
            }
            System.out.print("\n");
        }
        sc.close();
    }
}
