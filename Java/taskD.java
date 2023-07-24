import java.util.Scanner;
//program sklada sie z trzech klas Carriage(klasa wagonu), Train(klasa pociagu) oraz TrainsList(klasa listy pociagow)
//klasy zawieraja konstruktory i metody np. wstawiania usuwania elementow oraz odnajdywania ich w liscie
//metody wymagajace dzialania w czasie O(n) takie jak np. Display() lub TrainsList() dzialaja w czasie O(n), natomiast pozostale operacje
//wykonywane sa w czasie O(1) wymagajac jedynie tworzenia obiektu danej klasy tworzenia nowego obiektu danej klasy

//klasa wagonu
class Carriage{
    Carriage prev;
    String name;
    Carriage next;
    //konstruktor wagonu
    public Carriage(String name){
        this.name = name;
        next = null;
        prev = null;
    }
}
//klasa pociagu(listy wagonow)
class Train {
    Carriage first;
    Carriage last;
    String name;
    Train next;
    boolean rev;

    //konstruktor pociagu czyli listy wagonow
    public Train(String trainName, String firstName) {
        first = new Carriage(firstName);
        last = first;
        name = trainName;
        next = null;
        rev = false;
    }

    public void Reverse() {
        rev = !rev;
        Carriage tmp = first;
        first = last;
        last = tmp;

    }

    public void Display() {
        Carriage tmp = first;
        Carriage tmpPrev = tmp;
        System.out.print(this.name + ": ");
        while (tmp != null) {
            System.out.print(tmp.name + " ");
            if(tmpPrev == tmp.prev) {
                tmpPrev = tmp;
                tmp = tmp.next;
            }
            else if(tmpPrev == tmp.next) {
                tmpPrev = tmp;
                tmp = tmp.prev;
            }
            else{
                if(this.rev){
                    tmpPrev = tmp;
                    tmp = tmp.prev;
                }
                else {
                    tmpPrev = tmp;
                    tmp = tmp.next;
                }
            }
        }
        System.out.print("\n");
    }

    public void InsertLast(String key){
        Carriage newLast = new Carriage(key);
        if(!rev){
            last.next = newLast;
            newLast.prev = last;
            last = last.next;
        }
        else{
            last.prev = newLast;
            newLast.next = last;
            last = last.prev;
        }
    }
    public void InsertFirst(String key){
        Carriage newFirst = new Carriage(key);
        if(!rev){
            first.prev = newFirst;
            newFirst.next = first;
            first = first.prev;
        }
        else{
            first.next = newFirst;
            newFirst.prev = first;
            first = first.next;
        }
    }
}

//klasa listy pociagow (TrainsList)
class Trains{
    Train first;
    //konstruktor listy pociagow
    public Trains(){
        first = null;
    }

    public void append(String trName, String crName){
        Train train = new Train(trName, crName);
        train.next = first;
        first = train;
    }
    public Train locate(String key){
        Train tmp = first;
        while(tmp != null && !tmp.name.equals(key))
            tmp = tmp.next;
        return tmp;
    }

    public void TrainsList(){
        Train tmp = first;
        System.out.print("Trains: ");
        while(tmp != null){
            System.out.print(tmp.name + " ");
            tmp = tmp.next;
        }
        System.out.print("\n");
    }
    public void DelFirst(String key1, String key2){
        Train tmp = first;
        Train aux = null;
        while(!tmp.name.equals(key1)){
            aux = tmp;
            tmp = tmp.next;
        }
        String auxName;
        if(!tmp.rev){
            if(tmp.first.next != null) {
                append(key2, tmp.first.name);
                tmp.first = tmp.first.next;
                tmp.first.prev = null;
            }
            else{
                auxName = tmp.first.name;
                tmp.last = null;
                tmp.first = null;
                if (aux == null)
                    first = tmp.next;
                else
                    aux.next = tmp.next;
                append(key2, auxName);
            }
        }
        else{
            if(tmp.first.prev != null) {
                append(key2, tmp.first.name);
                tmp.first = tmp.first.prev;
                tmp.first.next = null;
            }
            else{
                auxName = tmp.first.name;
                tmp.last = null;
                tmp.first = null;
                if (aux == null)
                    first = tmp.next;
                else
                    aux.next = tmp.next;
                append(key2, auxName);
            }
        }
    }
    public void DelLast(String key1, String key2){
        Train tmp = first;
        Train aux = null;
        while(!tmp.name.equals(key1)){
            aux = tmp;
            tmp = tmp.next;
        }
        String auxName;
        if(!tmp.rev){
            if(tmp.last.prev != null) {
                append(key2, tmp.last.name);
                tmp.last = tmp.last.prev;
                tmp.last.next = null;
            }
            else{
                auxName = tmp.last.name;
                tmp.last = null;
                tmp.first = null;
                if (aux == null)
                    first = tmp.next;
                else {
                    aux.next = tmp.next;
                }
                append(key2, auxName);
            }
        }
        else{
            if(tmp.last.next != null) {
                append(key2, tmp.last.name);
                tmp.last = tmp.last.next;
                tmp.last.prev = null;
            }
            else{
                auxName = tmp.last.name;
                tmp.last = null;
                tmp.first = null;
                if (aux == null)
                    first = tmp.next;
                else {
                    aux.next = tmp.next;
                }
                append(key2, auxName);
            }
        }
    }
    public void Union(String key1, String key2){
        Train train1 = locate(key1);
        Train train2 = first;
        Train train2Prev = null;
        while(!train2.name.equals(key2)){
            train2Prev = train2;
            train2 = train2.next;
        }
        if(!train1.rev){
            if (!train2.rev){
                train1.last.next = train2.first;
                train2.first.prev = train1.last;
                train1.last = train2.last;
            }
            else{
                train1.last.next = train2.first;
                train2.first.next = train1.last;
                train1.last = train2.last;
                Carriage tmp = train1.last.next;
                train1.last.next = train1.last.prev;
                train1.last.prev = tmp;
            }
        }
        else{
            if (!train2.rev) {
                train1.last.prev = train2.first;
                train2.first.prev = train1.last;
                train1.last = train2.last;
                Carriage tmp = train1.last.next;
                train1.last.next = train1.last.prev;
                train1.last.prev = tmp;
            }
            else{
                train1.last.prev = train2.first;
                train2.first.next = train1.last;
                train1.last = train2.last;
            }
        }
        if(train2Prev == null)
            first = first.next;
        else{
            train2Prev.next = train2.next;
        }
    }
}
public class Source {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int sets = scanner.nextInt();
        scanner.nextLine();
        int commands;
        String command;
        String trainID1;
        String trainID2;
        String trainID;
        String carriageID;
        for(int j = 0; j < sets; j++) {
            commands = scanner.nextInt();
            Trains trList = new Trains();
            for (int i = 0; i < commands; i++) {
                command = scanner.next();
                switch (command) {
                    case "New":
                        trainID = scanner.next();
                        carriageID = scanner.next();
                        trList.append(trainID, carriageID);
                        break;
                    case "InsertFirst":
                        trainID = scanner.next();
                        carriageID = scanner.next();
                        Train aux = trList.locate(trainID);
                        aux.InsertFirst(carriageID);
                        break;
                    case "InsertLast":
                        trainID = scanner.next();
                        carriageID = scanner.next();
                        Train aux1 = trList.locate(trainID);
                        aux1.InsertLast(carriageID);
                        break;
                    case "Display":
                        trainID = scanner.next();
                        Train aux2 = trList.locate(trainID);
                        aux2.Display();
                        break;
                    case "TrainsList":
                        trList.TrainsList();
                        break;
                    case "Reverse":
                        trainID = scanner.next();
                        Train aux3 = trList.locate(trainID);
                        aux3.Reverse();
                        break;
                    case "Union":
                        trainID1 = scanner.next();
                        trainID2 = scanner.next();
                        trList.Union(trainID1, trainID2);
                        break;
                    case "DelFirst":
                        trainID1 = scanner.next();
                        trainID2 = scanner.next();
                        trList.DelFirst(trainID1, trainID2);
                        break;
                    case "DelLast":
                        trainID1 = scanner.next();
                        trainID2 = scanner.next();
                        trList.DelLast(trainID1, trainID2);
                        break;
                }
            }
        }
    }
}
