//program wykorzystuje algorytm Kadane dla tablicy jednowymiarowej
//sumujemy kolejne wiersze zaczynajac od pierwszej kolumny, przechodzimy do nastepnych kolumn, kiedy przejdziemy cala tablice
//przechodzimy do kolumny drugiej i ponownie sumujemy wiersze zaczynajac od drugiej kolumny az do konca itd.
//sprawdzamy takze ujemnosc calej tablicy lub czy jest zapelniona samymi zerami, jesli tak to konczymy dzialanie programu
//na koncu sprawdzam czy znaleziona suma moze byc wyrazona pojedynczym elementem tablicy
import java.util.Scanner;
class Source {
    public static void maxSum2DArray(int[][] array, int dataIndex){
        int negativeCounter = 0;
        int zeroCounter = 0;
        //sprawdzamy czy tablica sklada sie z samych zer lub elementow ujemnych
        //jesli tak, to konczymy dzialanie programu zwracajac wartosci zgodne z trescia
        for(int i = 0; i < array.length; i++) {
            for (int j = 0; j < array[0].length; j++) {
                if (array[i][j] < 0)
                    negativeCounter++;
                if (array[i][j] == 0)
                    zeroCounter++;
            }
        }
        if (zeroCounter == ((array[0].length) * (array.length))) {
            System.out.printf("%d: n = %d m = %d, ms = 0, mst = a[0..0][0..0]\n", dataIndex, array.length, array[0].length);
            return;
        }
        if(negativeCounter == ((array[0].length) * (array.length))){
            System.out.printf("%d: n = %d m = %d, ms = 0, mst is empty\n", dataIndex, array.length, array[0].length);
            return;
        }
        //wykorzystujac algorytm Kadane obliczamy spojny fragment tablicy o maksymalnej sumie
        int maxSum = 0;
        int currentSum;
        int maxLeft = 0;
        int maxRight = 0;
        int maxUp = 0;
        int maxDown = 0;
        int currentStart = 0;
        //zaczepiamy sie w pierwszej kolumnie
        for (int i = 0; i < array[0].length; i++) {
            //gdy przesuwamy sie o jeden w prawo zerujemy tablice
            int[] maxSumArray = new int[array.length];
            for (int j = i; j < array[0].length; j++) {
                for (int k = 0; k < array.length; k++) {
                    //tablica przechowuje aktualne sumy wierszy, kolejne indeksy odpowiadaja kolejnym wierszom
                    maxSumArray[k] += array[k][j];
                }
                //algorytm Kadane dla tablicy jednowymierowej, ktorej indeksy odpowiadaja kolejnym wierszom
                currentSum = 0;
                currentStart = 0;
                for (int l = 0; l < maxSumArray.length; l++) {
                    currentSum = currentSum + maxSumArray[l];
                    if(currentSum <= 0){
                        currentSum = 0;
                        currentStart = l+1;
                    }
                    if (currentSum > maxSum) {
                        maxSum = currentSum;
                        maxLeft = i;
                        maxRight = j;
                        maxUp = currentStart;
                        maxDown = l;
                    }
                    else if(currentSum == maxSum){
                        if((currentStart*1000+l*100+i*10+j) < (maxUp*1000+maxDown*100+maxLeft*10+maxRight) || ((l-currentStart+1)*(j-i+1) < (maxDown-maxUp+1)*(maxRight-maxLeft+1) )){
                            maxLeft = i;
                            maxRight = j;
                            maxUp = currentStart;
                            maxDown = l;
                        }
                    }
                }
            }
        }
        boolean wasFound = false;
        //sprawdzenie czy maksymalna suma jest taka sama jak maksymalny element tablicy
        for(int i=0; i < array.length; i++){
            for(int j=0; j<array[0].length; j++){
                if(array[i][j] == maxSum){
                    maxLeft = j;
                    maxRight = j;
                    maxUp = i;
                    maxDown = i;
                    wasFound = true;
                    break;
                }
            }
            if(wasFound)
                break;
        }
        System.out.printf("%d: n = %d m = %d, ms = %d, mst = a[%d..%d][%d..%d]\n",dataIndex,array.length, array[0].length,maxSum,maxUp,maxDown,maxLeft,maxRight);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input;
        int dataAmount = scanner.nextInt();
        int counter = 1;
        int rows;
        int columns;
        while(counter <= dataAmount){
            if(scanner.hasNextInt())
                scanner.next();
            if(!scanner.hasNextInt())
                scanner.next();
            rows = scanner.nextInt();
            columns = scanner.nextInt();
            int[][] inputArray = new int[rows][columns];
            for(int i=0; i<inputArray.length; i++){
                for(int j=0; j<inputArray[0].length; j++){
                    inputArray[i][j] = scanner.nextInt();
                }
            }
            maxSum2DArray(inputArray,counter);
            counter++;
        }
    }
}
