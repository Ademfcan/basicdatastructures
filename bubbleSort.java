public class bubbleSort {
    public bubbleSort(){

    }

    public <T extends Comparable<? super T>> void sort(T[] array){
        boolean hasChanged = true;
        while(hasChanged){
            hasChanged = false;
            for(int i =0; i<array.length-1;i++){
                if(array[i+1].compareTo(array[i]) < 0){
                    // second is smaller
                    T temp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = temp;
                    hasChanged = true;
                }

            }
        }
        
    }
}

class cMain{
    public static void main(String[] args) {
        bubbleSort b = new bubbleSort();
        Integer[] arr = new Integer[]{9,8,7,6,5,4,3,2,1,0};
        PrintArr(arr, "Unsorted");
        b.sort(arr);
        PrintArr(arr, "Sorted");
    }

    public static <T> void PrintArr(T[] arr, String message){
        System.out.println(message);
        for(T t: arr){
            System.out.print(t.toString());
        }
        System.out.println("\nEnd of array:");
    }
}
