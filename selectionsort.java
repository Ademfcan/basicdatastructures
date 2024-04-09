public class selectionsort {
    public selectionsort(){

    }

    public <T extends Comparable<? super T>> void sort(T[] array){
        for(int i =0; i<array.length;i++){
            int smallestIndex = i;
            T smallestValue = array[i];

            for(int j = i;j<array.length;j++){
                if(array[j].compareTo(smallestValue) < 0){
                    smallestIndex = j;
                    smallestValue = array[j];
                }
            }
            if(smallestIndex != i){
                //need a switch
                array[smallestIndex] = array[i];
                array[i] = smallestValue; 

            }

        }
    }
}

class Main{
    public static void main(String[] args) {
        selectionsort s = new selectionsort();
        Integer[] arr = new Integer[]{9,8,7,6,5,4,3,2,1};
        PrintArr(arr, "Unsorted");
        s.sort(arr);
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
