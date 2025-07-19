

class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }
}

public class Insertion{
    static Node insertAtBeginning(Node head, int val){
        if(head==null){
            head = new Node(val);
            return head;
        }
        Node newNode = new Node(val);
        newNode.next = head;
        return newNode;
    }

    static Node insertAtEnd(Node head, int val){
        if(head == null){
            head = new Node(val);
            return head;
        }

        Node curr = head;
        while(curr.next != null){
            curr = curr.next;
        }
        curr.next = new Node(val);
        return  head;
    }

    static void display(Node head){
        Node curr = head;

        while(curr!=null){
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
    }

    public static void main(String[] args) {
        Node head = new Node(4);
        head.next = new Node(5);
        System.out.print("Original List: ");
        display(head);
        System.out.println("");
        head = insertAtBeginning(head, 6);
        System.out.print("Insert at the beginning: ");
        display(head);
        System.out.println("");
        head = insertAtEnd(head, 8);
        System.out.print("Insert at the end: ");
        display(head);
    }
}