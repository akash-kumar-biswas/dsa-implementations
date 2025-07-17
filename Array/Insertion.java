public class Insertion{
    static int n = 5;
    static void display(int []arr, int n){
        for(int i = 0; i < n; i++){
            System.out.print(arr[i]+ " ");
        }
    }

    static void insertion(int []arr, int pos, int val){
        for(int i = n; i > pos; i--){
            arr[i] = arr[i-1];
        }
        arr[pos] = val;
        n++;
    }

    public static void main(String[] args) {
        int[] arr = new int[100];
        int[] values = {1,2,3,4,5};
        for(int i = 0; i < n; i++){
            arr[i] = values[i];
        }
        display(arr, n);
        insertion(arr, 2, 5); // insert at index 2 (0 - based)
        System.out.println();
        display(arr, n);
    }
}