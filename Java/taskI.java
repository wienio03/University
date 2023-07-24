import java.util.Scanner;
//Zadanie korzysta ze struktury kopca omawianej na wykladzie. W zadaniu uzylem obiektow klasy HeapObject ktore skladaja sie z klucza i //liczby wystapien w kopcu. W klasie kopca zaimplementowane sa metody wstawiania, usuwania elementu na gorze, zmniejszania liczby //wystapien, metoda toString(), metoda heapSort() sortujaca kopiec o zlozonosci pamieciowej O(1), metoda findElement() znajdujaca element //w kopcu. Metoda insert dziala zgodnie z zalozeniami zadania odnosnie pojemnosci rzeczywistej i pojemnosci elementow rozroznialnych.

//klasa obiektu skladowego kopca przechowujaca klucz i ilosc wystapien (priorytet)
class HeapObject {
    int key;
    int frequency;
    //konstruktor
    HeapObject(int key, int frequency) {
        this.key = key;
        this.frequency = frequency;
    }
    //metoda toString()
    @Override
    public String toString() {
        return key + " " + frequency;
    }
}
//klas astosu z metodami szukania elementu, kopcowania w gore siftUp(...), kopcowania w dol siftDown(...), insert(...) wstawiajaca element do kopca, getMax(...) zwracajaca element na gorze kopca i usuwajaca ilosc wystapien, extractMax(...) usuwajaca element na gorze kopca , heapSort(...) dzialajaca w miejscu (zlozonosc pamieciowa O(1))
class Heap {
    int maxDistinct;
    int maxTotal;
    int elementCount;
    HeapObject[] heapArray;
    //konstruktor kopca
    Heap(int maxDistinct, int maxTotal) {
        this.maxDistinct = maxDistinct;
        this.maxTotal = maxTotal;
        heapArray = new HeapObject[maxDistinct];
        elementCount = 0;
    }
    //szukanie elementu
    public HeapObject findElement(int key) {
        for (int i = 0; i < elementCount; i++) {
            if (heapArray[i].key == key) {
                return heapArray[i];
            }
        }
        return null;
    }
    //kopcowanie w gore zgodnie z zalozeniami zadania
    public void siftUp(HeapObject[] arr, HeapObject object) {
        int index = -1;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == object) {
                index = i;
                break;
            }
        }
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            HeapObject parent = arr[parentIndex];
            if (parent.frequency > object.frequency ||
                    (parent.frequency == object.frequency && parent.key > object.key)) {
                break;
            }
            arr[index] = parent;
            index = parentIndex;
        }
        if (index >= 0) {
            arr[index] = object;
        }
    }
    //kopcowanie w dol zgodnie z zalozeniami zadania
    public void siftDown(HeapObject[] arr, int index, int size) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        while (leftChild < size) {
            if (arr[leftChild].frequency > arr[largest].frequency ||
                    (arr[leftChild].frequency == arr[largest].frequency && arr[leftChild].key > arr[largest].key)) {
                largest = leftChild;
            }

            if (rightChild < size && (arr[rightChild].frequency > arr[largest].frequency ||
                    (arr[rightChild].frequency == arr[largest].frequency && arr[rightChild].key > arr[largest].key))) {
                largest = rightChild;
            }

            if (largest == index) {
                break;
            }

            HeapObject tmp = arr[index];
            arr[index] = arr[largest];
            arr[largest] = tmp;

            index = largest;
            leftChild = 2 * index + 1;
            rightChild = 2 * index + 2;
        }
    }
    //usuniecie elementu z kopca, zmnieszenie liczby elementow, kopcowanie w dol
    public void extractMax() {
        if (elementCount == 0) {
            return;
        }
        heapArray[0] = heapArray[elementCount - 1];
        heapArray[elementCount - 1] = null;
        elementCount--;
        siftDown(heapArray, 0, elementCount);
    }
    //metoda zwrocenia elementu na gorze kopca i usunieca liczby wystapien
    public HeapObject getMax(int deletedFrequency) {
        if (elementCount == 0) {
            return new HeapObject(0, 0);
        }
        HeapObject returnedObject = new HeapObject(heapArray[0].key, heapArray[0].frequency);
        if (deletedFrequency >= returnedObject.frequency) {
            extractMax();
        } else {
            returnedObject.frequency = deletedFrequency;
            heapArray[0].frequency -= deletedFrequency;
            siftDown(heapArray, 0, elementCount);
        }

        return returnedObject;
    }
    //metoda zwracajaca aktualna sume elementow na kopcu
    public int getSum() {
        int sum = 0;
        for (int i = 0; i < elementCount; i++) {
            sum += heapArray[i].frequency;
        }
        return sum;
    }
    //metoda wstawiania do kopca w zaleznosci od tego czy element jest juz w kopcu lub jeszcze nie
    public void insert(int[] elements) {
        for (int element : elements) {
            HeapObject obj = findElement(element);
            if (getSum() == maxTotal)
                break;

            if (obj != null) {
                obj.frequency++;
                siftUp(heapArray, obj);
            } else if (elementCount < maxDistinct) {
                HeapObject newObject = new HeapObject(element, 1);
                heapArray[elementCount] = newObject;
                elementCount++;
                siftUp(heapArray, newObject);
            }
        }
    }
    //metoda heapsort korzystajaca z metody kopcowania w dol, dzialajaca pamieciowo w O(1)
    public void heapSort() {
        for (int i = elementCount / 2 - 1; i >= 0; i--) {
            siftDown(heapArray, i, elementCount);
        }

        for (int i = elementCount - 1; i > 0; i--) {
            HeapObject tmp = heapArray[0];
            heapArray[0] = heapArray[i];
            heapArray[i] = tmp;

            siftDown(heapArray, 0, i);
        }
    }
    //metoda toString()
    @Override
    public String toString() {
        if (elementCount == 0) {
            return "0 0";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < elementCount; i++) {
            sb.append(heapArray[i]);
            sb.append(" ");
        }
        return sb.toString();
    }
}

public class Source {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int sets;
        String operation;
        int N;
        int P;

        sets = scanner.nextInt();

        for (int i = 0; i < sets; i++) {
            N = scanner.nextInt();
            P = scanner.nextInt();
            Heap heap = new Heap(N, P);
            while (true) {
                operation = scanner.next();
                if (operation.equals("i")) {
                    int k = scanner.nextInt();
                    int[] arr = new int[k];
                    for (int j = 0; j < arr.length; j++) {
                        arr[j] = scanner.nextInt();
                    }
                    heap.insert(arr);
                } else if (operation.equals("g")) {
                    int k = scanner.nextInt();
                    System.out.println(heap.getMax(k));
                } else if (operation.equals("s")) {
                    heap.heapSort();
                    if(heap.elementCount != 0)
                        System.out.println(heap);
                    else
                        System.out.println();
                    break;
                }
            }
        }
        scanner.close();
    }
}
