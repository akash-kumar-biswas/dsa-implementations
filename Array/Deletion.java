public class Deletion {
    static int n = 5;
    static void display(int []arr, int n){
        for(int i = 0; i < n; i++){
            System.out.print(arr[i]+ " ");
        }
    }

    static void delete(int[] arr, int idx){
        for(int i = idx; i < n-1; i++){
            arr[i] = arr[i+1];
        }
    }

    static void deletion(int[] arr, int val){
        for(int i = 0; i < n; i++){
            if(arr[i] == val){
                delete(arr, i);
                n--;
                break;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[100];
        int[] values = {1,2,3,4,5};
        for(int i = 0; i < n; i++){
            arr[i] = values[i];
        }
        display(arr, n);
        deletion(arr, 2);  // delete the first occurence of an element 
        System.out.println();
        display(arr, n);
    }
}
