import java.util.HashMap;

public class calcfibonaci {
    public calcfibonaci(){
        
    }
    HashMap<Integer,Integer> map;

    public int getNthFibonacci(int n){
        if(n < 1){
            // handle incorrect function calls
            return -1;
        }
        else{
            map = new HashMap<>(n);
            return fibRecursive(n);
        }
    }


    private int fibRecursive(int n){
        if(n < 2){
            // recursive base case #1
            return n;
        }
        Integer val = map.get(n);
        if(val != null){
            // recursive base case #2
            return val;
        }
        int res = fibRecursive(n-1) + fibRecursive(n-2); 
        map.put(n, res);
        return res;
        
    }


}

class Main{
    public static void main(String[] args) {
        calcfibonaci c = new calcfibonaci();
        System.out.println(c.getNthFibonacci(10));
    }
}