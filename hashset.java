import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class hashset<T> {
    private Object[] items;
    private int currentSize;
    private float loadFactor;

    public hashset(int initialSize,float loadFactor) {
        int base2Size = roundBase2(initialSize);
        this.items = new Object[base2Size];
        this.currentSize = base2Size;
        this.loadFactor = loadFactor;
    }

    public hashset(int initialSize) {
        int base2Size = roundBase2(initialSize);
        this.items = new Object[base2Size];
        this.currentSize = base2Size;
        this.loadFactor = .75f;
    }


    public hashset() {
        this.items = new Object[0];
        this.currentSize = 0;
    }

    public boolean Contains(T item) {
        int hash = item.hashCode();
        int index = hash % currentSize;
        return this.items[index] != null;
    }

    public void add(T item) {
        int hash = item.hashCode();
        int index = hash % currentSize;
        System.out.println("Item: " + item.toString());
        System.out.println("Index: " + index);
        boolean isFilled = this.items[index] != null;
        if (!isFilled) {
            items[index] = item;
        }

        checkFilled(items);
    }

    public void remove(T item) {
        int hash = item.hashCode();
        int index = hash % currentSize;
        this.items[index] = null;

    }

    public void clear() {
        for (int i = 0; i < currentSize; i++) {
            this.items[i] = null;
        }
    }

    public boolean isEmpty() {
        return getFilledSlots(this.items) == 0;
    }

    public int getSize(boolean onlyFilledSlots) {
        if (onlyFilledSlots) {
            return getFilledSlots(this.items);
        } else {
            return currentSize;
        }
    }

    public int getSize() {
        return currentSize;
    }

    public Object[] getItems() {
        // will not maintain order!!!
        Object[] filtered = Arrays.stream(items).filter(O -> O != null).toArray();
        return filtered;
    }

    private void checkFilled(Object[] items) {
        if ((float) getFilledSlots(items) > items.length*loadFactor) {
            // need to double array
            doubleSpace(items);
        }
    }

    private void doubleSpace(Object[] items) {
        System.out.println("Doubling");
        currentSize *= 2;
        Object[] largeritems = new Object[currentSize];
        for (Object o : items) {
            if(o != null){
                int hash = o.hashCode();
                int index = hash % currentSize;
                largeritems[index] = o;
            }
            

        }
        this.items = largeritems;
    }

    private int getFilledSlots(Object[] items) {
        // uneccesary streams use
        return (int) Arrays.stream(items).filter(O -> O != null).count();
    }

    private int roundBase2(int num) {
        double exp = Math.log(num) / Math.log(2);
        int ceiling = ((int) exp) + 1;
        return (int) Math.pow(2, ceiling);
    }
}

class bMain {
    public static void main(String[] args) {
        hashset<Character> s = new hashset<Character>(4,.5f);
        String sentence = "Hello nice to meet you, this is java a programming language...  in this language you can create programs";
        for (Character c : sentence.toCharArray()) {
            s.add(c);
        }
        Character g = '.';
        System.out.println(g.hashCode()%s.getSize());
        // character 'n' and '.' have a hash collision when wrapped around by set size
        Object[] items = s.getItems();
        for (Object c : items) {
            System.out.print((Character) c + " ");
        }
    }
}