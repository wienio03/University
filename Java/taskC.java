import java.util.Scanner;
//program uzywa przedstawiony na wykladzie algorytm zamiany INF->ONP oraz algorytm zamiany ONP->INF zapewniajacy minimalna ilosc nawiasow
//wykorzystujacy dwa stosy dla wyrazen i priorytetow operatorow i operandow (operandy maja zawsze maksymalny priorytet)
//klasa stosu dla tablicy charow(INF->ONP) i klasy stosu dla tablicy stringow i intow(ONP->INF) w celu zaimplementowania
//osobnego stosu priorytetow i wyrazen
//klasa source zawiera metody sluzace zwracaniu odpowiednich priorytetow operatorow i operandow, prawo/lewostronnego wiazania oraz krotnosci
//metody INFOutput oraz ONPOutput sluza tworzeniu lancuchow wyjsciowych wyrazen
//metody stateMachine oraz ONPValidation sluza weryfikacji poprawnosci wyrazen, przy czym stateMachine sprawdza rowniez nawiasy
//w notacji infikowej w jednej petli z dzialaniem automatu skonczonego
//metody createInputINF , createInputONP sluza do tworzenia poprawnego inputu pomijajac niepozadane znaki, nastepnie powstale lancuchy
//podlegaja weryfikacji przez wyzej wymienione metody walidacji
//metoda addSpaces dodaje do outputu spacje
class Stack {
    int capacity;
    char[] stackArray;
    int topIndex;


    //konstruktor dla stosu konwertera INF->ONP
    public Stack(int capacity){
        this.capacity = capacity;
        stackArray = new char[capacity];
        topIndex = -1;
    }
    //metody isEmpty, isFull, pop, push, peek
    public boolean isEmpty(){
        return topIndex == -1;
    }
    public boolean isFull(){
        return topIndex == capacity - 1;
    }
    public void push(char x){
        if(isFull())
            return;
        else
            stackArray[++topIndex] = x;
    }
    public char pop(){
        if(isEmpty())
            return '\0';
        else
            return stackArray[topIndex--];
    }
    public char peek(){
        if(isEmpty())
            return '\0';
        else
            return stackArray[topIndex];
    }

};
class stackINT {
    int capacity;
    int[] stackArray;
    int topIndex;
    public stackINT(int capacity){
        this.capacity = capacity;
        topIndex = -1;
        stackArray = new int[256];

    }
    public boolean isEmpty(){
        return topIndex == -1;
    }
    public boolean isFull(){
        return topIndex == capacity - 1;
    }
    public void push(int x){
        if(isFull())
            return;
        else
            stackArray[++topIndex] = x;
    }
    public int pop(){
        if(isEmpty())
            return '\0';
        else
            return stackArray[topIndex--];
    }
    public int peek(){
        if(isEmpty())
            return '\0';
        else
            return stackArray[topIndex];
    }

};
class stackSTR {
    int capacity;
    String[] stackArray;
    int topIndex;

    public stackSTR(int capacity){
        this.capacity = capacity;
        stackArray = new String[256];
        topIndex = -1;
    }
    public boolean isEmpty(){
        return topIndex == -1;
    }
    public boolean isFull(){
        return topIndex == capacity - 1;
    }
    public void push(String x){
        if(isFull())
            return;
        else
            stackArray[++topIndex] = x;
    }
    public String pop(){
        if(isEmpty())
            return "0";
        else
            return stackArray[topIndex--];
    }
    public String peek(){
        if(isEmpty())
            return "0";
        else
            return stackArray[topIndex];
    }

}
public class Source {
    //automat sprawdzajacy poprawnosc wyrazen w postaci infiksowej
    static boolean isUrnary(char x){
      if(x == '!' || x == '~')
          return true;
      return false;
    }
    static boolean isBinary(char x){
      char[] binary = new char[]{'^','*','/','%','+','-','<','>','?','&','|','='};
      for(int i = 0; i < binary.length; i++)
          if(binary[i] == x)
              return true;
      return false;
    }
    static boolean stateMachine(char[] array){
        boolean q0 = true;
        boolean q1 = false;
        boolean q2 = false;
        int opCounter = 0;
        int brCounter = 0;
        char[] op1 = new char[]{'~','!'};//operatory jednoargumentowe
        char[] op2 = new char[]{'^','*','/','%','+','-','<','>','?','&','|','='};//operatory dwuargumentowe
        for(int i = 0; i < array.length; i++){
            if(q0) {
                if(isUrnary(array[i])){
                    q0 = false;
                    q2 = true;
                    q1 = false;
                }
                if(isOperand(array[i])){
                    q0 = false;
                    q1 = true;
                    q2 = false;
                    opCounter++;
                }
                if(array[i] == '(')
                    brCounter++;
                if(array[i] == ')')
                    return false;
                if(isBinary(array[i]))
                    return false;
            }
            else if(q1) {
                if(isOperand(array[i]))
                    return false;
                if(isBinary(array[i])) {
                    q0 = true;
                    q1 = false;
                    q2 = false;
                    opCounter--;
                }
                if(array[i] == ')')
                    brCounter--;
                if(array[i] == '(')
                    return false;
                if(isUrnary(array[i]))
                    return false;
            }
            else if(q2) {
                if(isOperand(array[i])){
                    q0 = false;
                    q1 = true;
                    q2 = false;
                    opCounter++;
                }
                if(array[i] == '('){
                    q0 = true;
                    q1 = false;
                    q2 = false;
                    brCounter++;
                }
                if(isBinary(array[i]))
                    return false;
                if(array[i] == ')')
                    return false;
            }
            if(brCounter < 0)
                return false;
        }
    if(brCounter != 0 || opCounter != 1)
            return false;
    if(q1)
            return true;
    return false;
    }
    static boolean ONPValidation(char[] input){
        int operandCounter = 0;
        int operatorCounter = 0;
        for(int i = 0; i < input.length; i++) {
            if( i == 0 && (input[i] == '!' || input[i] == '~'))
                operatorCounter++;
            if (isBinary(input[i]))
                operatorCounter++;
            if (isOperand(input[i]))
                operandCounter++;
            if(operatorCounter >= operandCounter)
                return false;
        }
        if(operandCounter - operatorCounter != 1)
            return false;
        return true;
    }
    static boolean isOperator(char x){
        char[] operatorArray = new char[]{'^','*','/','%','+','-','<','>','?','&','|','=','~','!','(',')'};
        for(int i = 0; i < operatorArray.length; i++){
            if(x == operatorArray[i])
                return true;
        }
        return false;
    }
    static boolean isOperand(char x){
        if(x >= 97 && x <= 122)
            return true;
        return false;
    }
    static int operatorPriority(char x){
        if(isOperand(x))
            return 10;
        if(x == '!' || x == '~')
            return 9;
        if(x == '^')
            return 8;
        if(x == '*' || x == '/' || x == '%')
            return 7;
        if(x == '+' || x == '-')
            return 6;
        if(x == '<' || x == '>')
            return 5;
        if(x == '?')
            return 4;
        if(x == '&')
            return 3;
        if(x == '|')
            return 2;
        if(x == '=')
            return 1;
        return 0;
    }
    static char operatorAssociation(char x){
        char[] right = new char[]{'!','~','^','='};
        char[] left = new char[]{'*','/','%','+','-','<','>','?','&','|'};
        for(int i = 0; i < left.length; i++){
            if(i <= 3){
                if(x == right[i])
                    return 'R';
                if(x == left[i])
                    return 'L';
            }
            else{
                if(x == left[i])
                    return 'L';
            }
        }
        return '\0';
    }
    static String ONPOutput(char[] input, Stack stack){
        StringBuilder sb = new StringBuilder();
        char buffer = '\0';
        for(int i = 0; i < input.length; i++){
            if(input[i] != ' ' && input[i] != ',') {
                if (isOperand(input[i]))
                    sb.append(input[i]);
                else if (isOperator(input[i])) {
                    if (input[i] == '(')
                        stack.push(input[i]);
                    if (operatorAssociation(input[i]) == 'L') {
                        while (operatorPriority(stack.peek()) >= operatorPriority(input[i]))
                            sb.append(stack.pop());
                        stack.push(input[i]);
                    }
                    if (operatorAssociation(input[i]) == 'R') {
                        while (operatorPriority(stack.peek()) > operatorPriority(input[i]))
                            sb.append(stack.pop());
                        stack.push(input[i]);
                    }
                    if (input[i] == ')') {
                        while (stack.peek() != '(')
                            sb.append(stack.pop());
                        buffer = stack.pop();
                    }
                }
            }
        }
        while(!stack.isEmpty())
            sb.append(stack.pop());
        return sb.toString();
    }
    static String INFOutput(char[] input){
        String outputBuild = "";
        stackINT stackPriority = new stackINT(256);
        stackSTR stackExpr = new stackSTR(256);
        for(int i = 0; i < input.length; i++){
            if(isOperand(input[i])){
                stackExpr.push(""+input[i]);
                stackPriority.push(operatorPriority(input[i]));
            }
            else{
                if(!isUrnary(input[i])){
                    if(operatorAssociation(input[i]) == 'L') {
                        if (stackPriority.peek() <= operatorPriority(input[i]))
                            outputBuild = "(" + stackExpr.pop() + ")";
                        else
                            outputBuild = stackExpr.pop();
                        stackPriority.pop();
                        if (stackPriority.peek() < operatorPriority(input[i]))
                            outputBuild = "(" + stackExpr.pop() + ")" + input[i] + outputBuild;
                        else
                            outputBuild = stackExpr.pop() + input[i] + outputBuild;
                        stackPriority.pop();
                    }
                    else if(operatorAssociation(input[i]) == 'R'){
                        if (stackPriority.peek() < operatorPriority(input[i]))
                            outputBuild = "(" + stackExpr.pop() + ")";
                        else
                            outputBuild = stackExpr.pop();
                        stackPriority.pop();
                        if (stackPriority.peek() < operatorPriority(input[i]))
                            outputBuild = "(" + stackExpr.pop() + ")" + input[i] + outputBuild;
                        else
                            outputBuild = stackExpr.pop() + input[i] + outputBuild;
                        stackPriority.pop();
                    }
                }
                else {
                        if(stackPriority.peek() < operatorPriority(input[i]))
                            outputBuild = input[i] + "(" + stackExpr.pop() + ")";
                        else
                            outputBuild = input[i] + stackExpr.pop();
                        stackPriority.pop();
                }
                stackExpr.push(outputBuild);
                stackPriority.push(operatorPriority(input[i]));
            }
        }
        return stackExpr.pop();
    }
    static String createInputINF(char[] input){
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < input.length; i++){
            if(input[i] != 'N' && input[i] != 'I' && input[i] != 'F' && (isOperator(input[i]) || isOperand(input[i])))
                sb.append(input[i]);
        }
        return sb.toString();
    }
    static String createInputONP(char[] input){
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < input.length; i++){
            if(input[i] != 'O' && input[i] != 'N' && input[i] != 'P' && input[i] != '(' && input[i] != ')' && (isOperator(input[i]) || isOperand(input[i])))
                sb.append(input[i]);
        }
        return sb.toString();
    }
    static String addSpaces(char[] input){
        StringBuilder finalOutput = new StringBuilder();
        for(char c: input){
            finalOutput.append(c).append(" ");
        }
        return finalOutput.toString().trim();
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        Stack stackRPN = new Stack(256);
        String input;
        char bufferChar;
        int sets = scanner.nextInt();
        scanner.nextLine();
        for(int i = 0; i < sets; i++){
            //rozroznienie inputu infiksowego i postfiksowego
            input = scanner.nextLine();
            if(input.charAt(0) == 'I'){
                input = createInputINF(input.toCharArray());
                if(stateMachine(input.toCharArray()))
                    System.out.println("ONP: " + addSpaces(ONPOutput(input.toCharArray(),stackRPN).toCharArray()));
                else
                    System.out.println("ONP: error");
            }
            if(input.charAt(0) == 'O'){
                input = createInputONP(input.toCharArray());
                if(ONPValidation(input.toCharArray()))
                    System.out.println("INF: " + addSpaces(INFOutput(input.toCharArray()).toCharArray()));
                else
                    System.out.println("INF: error");
            }
        }
    }
}
