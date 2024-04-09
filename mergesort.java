import java.util.Arrays;


public class mergesort{
    public mergesort(){

    }
    public <T extends Comparable<? super T>> void Sort(T[] array){
        Sort(array,0,array.length-1);
    }
    private <T extends Comparable<? super T>> void Sort(T[] array,int L,int R){
        if(L<R){
            int M = L+(R-L)/2;
            Sort(array,L,M);
            Sort(array,M+1,R);

            Merge(array,L,M,R);
        }
    }
    
   
    private <T extends Comparable<? super T>> void Merge(T[] array,int L, int M, int R){
        int Lsize = M - L + 1;
        int Rsize = R - M;
        T[] left = Arrays.copyOfRange(array, L,M+1);
        T[] right = Arrays.copyOfRange(array, M+1,R+1);
        int i= 0,j = 0;
        int k = L;
        while(i<Lsize && j < Rsize){
            if (left[i].compareTo(right[j]) <= 0) {
                array[k++] = left[i++];
            } else {
                array[k++] = right[j++];
            }

        }
        while (i < Lsize) {
            array[k++] = left[i++];
        }

        while (j < Rsize) {
            array[k++] = right[j++];
        }

    }

    

}

class Main{
    public static void main(String[] args) {
        mergesort m = new mergesort();
        Integer[] arr = new Integer[]{2,4,6,1,2,3,8,9,6,4,7};
        PrintArr(arr,"Unsorted array:");
        m.Sort(arr);
        PrintArr(arr,"Sorted array:");

    }

    public static <T> void PrintArr(T[] arr, String message){
        System.out.println(message);
        for(T t: arr){
            System.out.print(t.toString());
        }
        System.out.println("\nEnd of array:");
    }
}