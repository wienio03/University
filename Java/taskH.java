/* Program opiera sie na odtwarzaniu przebiegu drzewa binarnego korzystajac z dwoch tablic. Jedna z nich to tablica inorder, a druga to w zaleznosci 
od wejscia postorder lub preorder (tylko tak jestesmy w stanie jednoznacznie odtworzyc przebieg drzewa). Metody sluzace do odtwarzania przebiegu drzewa sa rekurencyjne
i polegaja na budowaniu poddrzew az do momentu dojscia do konca calego drzewa, wtedy do zmiennej root przypisywany jest korzen calego drzewa. Wypisywanie rowniez jest rekurencyjne, poza
wypisywaniem w porzadku levelorder, ktore jest iteracyjne i opiera sie na implementacji kolejki, z klasycznymi dla tej struktury metodami
 */
import java.util.Scanner;
//skladowa kolejki i jednoczesnie pojedynczy skladnik drzewa
class TreeNode {
    TreeNode left;
    int value;
    TreeNode right;
    // pole next potrzebne do kolejki
    TreeNode next;

    // konstruktor wierzchoĹka drzewa
    public TreeNode(int value) {
        left = null;
        this.value = value;
        right = null;
        next = null;
    }
}
//kolejka z metodami enqueue(), dequeue() i isempty()
class TreeNodeQueue {
    TreeNode front;
    TreeNode rear;

    public TreeNodeQueue() {
        front = null;
        rear = null;
    }

    public void enqueue(TreeNode node) {
        if (front == null) {
            front = node;
            rear = node;
        } else {
            rear.next = node;
            rear = rear.next;
        }
    }

    public TreeNode dequeue() {
        if (front == null)
            return null;

        TreeNode returnedNode = front;
        front = front.next;

        if (front == null)
            rear = null;

        return returnedNode;
    }

    public boolean isEmpty() {
        return front == null;
    }
}

public class Source {
    //budowanie drzewa z porzadku preorder
    public static TreeNode buildFromPreOrder(int[] inOrder, int[] preOrder) {

        // dla porzÄdku preorder korzeĹ drzewa znajduje siÄ na poczÄtku tablicy preorder
        if (inOrder.length == 0 || preOrder.length == 0)
            return null;
        if (inOrder.length == 1 || preOrder.length == 1)
            return new TreeNode(inOrder[0]);

        TreeNode root = new TreeNode(preOrder[0]);
        int indexOfRoot = -1;

        for (int i = 0; i < inOrder.length; i++)
            if (inOrder[i] == root.value) {
                indexOfRoot = i;
                break;
            }

        // dzielimy tablicÄ inorder na podtablice
        int[] leftSubTreeInOrder = new int[indexOfRoot];
        int[] rightSubTreeInOrder = new int[inOrder.length - indexOfRoot - 1];

        System.arraycopy(inOrder, 0, leftSubTreeInOrder, 0, leftSubTreeInOrder.length);
        System.arraycopy(inOrder, indexOfRoot + 1, rightSubTreeInOrder, 0, rightSubTreeInOrder.length);

        // dzielimy tablicÄ preorder na podtablice
        int[] leftSubTreePreOrder = new int[indexOfRoot];
        int[] rightSubTreePreOrder = new int[inOrder.length - indexOfRoot - 1];

        System.arraycopy(preOrder, 1, leftSubTreePreOrder, 0, leftSubTreePreOrder.length);
        System.arraycopy(preOrder, indexOfRoot + 1, rightSubTreePreOrder, 0, rightSubTreePreOrder.length);

        root.left = buildFromPreOrder(leftSubTreeInOrder, leftSubTreePreOrder);
        root.right = buildFromPreOrder(rightSubTreeInOrder, rightSubTreePreOrder);

        return root;
    }
    //budowanie drzewa z porzadku postorder
    public static TreeNode buildFromPostOrder(int[] inOrder, int[] postOrder) {
        // W porzÄdku preorder na poczÄtku ostatni element tablicy to korzeĹ drzewa (root)
        if (inOrder.length == 0 || postOrder.length == 0)
            return null;
        if (inOrder.length == 1 || postOrder.length == 1)
            return new TreeNode(inOrder[0]);
        TreeNode root = new TreeNode(postOrder[postOrder.length - 1]);
        // szukamy naszego korzenia w tablicy inorder
        int indexOfRoot = -1;
        for (int i = 0; i < inOrder.length; i++) {
            if (inOrder[i] == root.value) {
                indexOfRoot = i;
                break;
            }
        }
        // dzielimy tablicÄ na prawe i lewe poddrzewo dla porzÄdku inorder
        int[] leftSubTreeInOrder = new int[indexOfRoot];
        int[] rightSubTreeInOrder = new int[inOrder.length - indexOfRoot - 1];
    
        System.arraycopy(inOrder, 0, leftSubTreeInOrder, 0, indexOfRoot);
        System.arraycopy(inOrder, indexOfRoot + 1, rightSubTreeInOrder, 0, inOrder.length - indexOfRoot - 1);
    
        // dzielimy tablicÄ na prawe i lewe poddrzewo dla porzÄdku postorder
        int[] leftSubTreePostOrder = new int[indexOfRoot];
        int[] rightSubTreePostOrder = new int[postOrder.length - indexOfRoot - 1];
    
        System.arraycopy(postOrder, 0, leftSubTreePostOrder, 0, indexOfRoot);
        System.arraycopy(postOrder, indexOfRoot, rightSubTreePostOrder, 0, postOrder.length - indexOfRoot - 1);
    
        root.left = buildFromPostOrder(leftSubTreeInOrder, leftSubTreePostOrder);
        root.right = buildFromPostOrder(rightSubTreeInOrder, rightSubTreePostOrder);
    
        return root;
    }
    //wyswietlanie w przadku preorder
    public static void displayPreOrder(TreeNode root) {
        if (root != null) {
            System.out.print(root.value + " ");
            displayPreOrder(root.left);
            displayPreOrder(root.right);
        }
    }
    //wyswietlanie w porzadku postorder
    public static void displayPostOrder(TreeNode root) {
        if (root != null) {
            displayPostOrder(root.left);
            displayPostOrder(root.right);
            System.out.print(root.value + " ");
        }
    }
    //wyswietlanie w porzadku levelorder
    public static void displayLevelOrder(TreeNode root) {
        TreeNodeQueue queue = new TreeNodeQueue();
        queue.enqueue(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.dequeue();
            System.out.print(node.value + " ");
            if (node.left != null)
                queue.enqueue(node.left);
            if (node.right != null)
                queue.enqueue(node.right);
        }    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        byte sets;
        int nodesAmount;
        String order;
        sets = scanner.nextByte();
        int[] inOrderArray;
        int[] secondOrderArray;
        scanner.nextLine();
        for (int i = 0; i < sets; i++) {
            nodesAmount = scanner.nextInt();
            scanner.nextLine();
            order = scanner.nextLine();
            inOrderArray = new int[nodesAmount];
            secondOrderArray = new int[nodesAmount];
            if (order.equals("POSTORDER"))
                for (int j = 0; j < nodesAmount; j++)
                    secondOrderArray[j] = scanner.nextInt();
            else if (order.equals("PREORDER"))
                for (int j = 0; j < nodesAmount; j++)
                    secondOrderArray[j] = scanner.nextInt();

            scanner.nextLine();
            scanner.nextLine();

            for (int j = 0; j < nodesAmount; j++)
                inOrderArray[j] = scanner.nextInt();
            System.out.println("ZESTAW " + (i + 1));
            if (order.equals("POSTORDER")) {
                TreeNode tree = buildFromPostOrder(inOrderArray, secondOrderArray);
                System.out.println("PREORDER");
                displayPreOrder(tree);
                System.out.print('\n');
                System.out.println("LEVELORDER");
                displayLevelOrder(tree);
            } else if (order.equals("PREORDER")) {
                TreeNode tree = buildFromPreOrder(inOrderArray, secondOrderArray);
                System.out.println("POSTORDER");
                displayPostOrder(tree);
                System.out.print('\n');
                System.out.println("LEVELORDER");
                displayLevelOrder(tree);
            }
            System.out.print('\n');
        }
        scanner.close();
    }
}
