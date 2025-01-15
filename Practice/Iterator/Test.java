import java.util.Stack;

// Iterator interface
interface Iterator<E> {
    // Returns true if the iteration has more elements. 
    public boolean hasNext(); 

    // Returns the next element.
    public E next(); 
}

class StringArrayIterator implements Iterator<String> {
    private String[] strs;
    private int index;

    public StringArrayIterator(String[] strs) {
        this.strs = strs;
        this.index = 0;
    }

    public boolean hasNext() {
        return index < strs.length;
    }

    public String next() {
        if (!hasNext()) {
            throw new java.util.NoSuchElementException();
        }
        return strs[index++];
    }
}
class Node{
    public int val;
    public Node left;
    public Node right;
    public Node(int val, Node left, Node right){
        this.val = val;
        this.left = left;
        this.right = right;
    }
    public Node(int val){
        this.val = val;
    }
}
class BSTIterator implements Iterator<Node>{
    private Stack<Node> s = new Stack<>();    

    public BSTIterator(Node root) {
        push_left(root);
    }

    private void push_left(Node n){
        while(n != null){
            s.push(n);
            n = n.left;
        }
    }

    public boolean hasNext() {
        return !s.isEmpty();
    }

    public Node next() {
        if (!hasNext()) {
            throw new java.util.NoSuchElementException();
        }
        Node next = s.pop();
        if(next.right != null){
            push_left(next.right);
        }
        return next;
    }
}

// Usage:
public class Test {
    public static void main(String[] args) {
        // Test StringArrayIterator
        System.out.println("Testing StringArrayIterator");
        String[] cars = {"Volvo", "BMW", "Ford", "Mazda"};
        Iterator<String> stringIterator = new StringArrayIterator(cars);
        while (stringIterator.hasNext()) {
            System.out.println(stringIterator.next());
        }
        
        System.out.println("Testing IntArrayIterator");
        int[] numbers = {1, 2, 3, 4, 5};
        Iterator<Integer> intIterator = new IntArrayIterator(numbers);
        while (intIterator.hasNext()) {
            System.out.println(intIterator.next());
        }

        System.out.println("Testing FibonacciIterator");
        System.out.println("This will start at the second 1 by nature of the 'next' method");
        int maxFibonacci = 10;
        Iterator<Integer> fibonacciIterator = new FibonacciIterator(maxFibonacci);
        while (fibonacciIterator.hasNext()) {
            System.out.println(fibonacciIterator.next());
        }

        System.out.println("Testing BST Iterator");
        Node A = new Node(8);
        Node B = new Node(3);
        Node C = new Node(10);
        Node D = new Node(1);
        Node E = new Node(6);
        Node F = new Node(14);
        Node G = new Node(4);
        Node H = new Node(7);
        Node I = new Node(13);
        A.left = B;
        A.right = C;
        B.left = D;
        B.right = E;
        C.right = F;
        E.left = G;
        E.right = H;
        F.left = I;
        Iterator<Node> BIterator = new BSTIterator(A);
        while(BIterator.hasNext()){
            System.out.println(BIterator.next().val);
        }
    }
}

class IntArrayIterator implements Iterator<Integer> {
    private int[] integers;
    private int index;

    public IntArrayIterator(int[] integers) {
        this.integers = integers;
        this.index = 0;
    }

    public boolean hasNext() {
        return index < integers.length;
    }

    public Integer next() {
        if (!hasNext()) {
            throw new java.util.NoSuchElementException();
        }
        return integers[index++];
    }
}

class FibonacciIterator implements Iterator<Integer> {
    private int prev;
    private int curr;
    private int maxCount;
    private int index;

    public FibonacciIterator(int maxCount) {
        this.prev = 0;
        this.curr = 1;
        this.maxCount = maxCount;
        this.index = 0;
    }

    public boolean hasNext() {
        return this.index < this.maxCount;
    }

    public Integer next() {
        if (!hasNext()) {
            throw new java.util.NoSuchElementException();
        }
        // We can make the counter start at 0, 1, 1 ... by returning temp instead of curr
        int temp = prev;
        prev = curr;
        curr += temp;
        index++;
        return curr;
    }
}
