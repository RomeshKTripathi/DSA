public class MyLinkedList<type> {

    public node head;
    public node ptr;

    class node{
        type data;
        node next;
        public node(type data){
            this.data = data;
            next = null;
        }
    }


    MyLinkedList(){
        head = null;
        ptr = null;
    }

    MyLinkedList(type data){
        head = new node(data);
        ptr = head;
    }

    MyLinkedList(type[] list){
        for(type data : list){
            addAtEnd(data);
        }
    }


    /**
     * Adds element at the end of the list
     * @param data value of the node.
     */
    public void addAtEnd(type data){
        if(head == null){
            head = new node(data);
            ptr = head;
        }else {
            ptr.next = new node(data);
            ptr = ptr.next;
        }
    }


    /**
     * Adds element at the beginning of the list
     * @param data value of the node.
     */
    public void addAtHead(type data){
        if(head == null) {
            head = new node(data);
            ptr = head;
        }else{
            node temp = new node(data);
            temp.next = head;
            head = temp;
        }
    }


    /**
     * print the list
     */
    public void printList(){
        if (head == null) return;

        node temp = head;
        while(temp != null) {
            System.out.print(temp.data + ", ");
            temp = temp.next;
        }
        System.out.print("\n");
    }


    /**
     * reverse the list
     */
    public void reverse(){
        if(head == null || head.next == null) return;
        node tail = null;
        node curr;

        while(head != null){
            curr = head;
            head = head.next;
            curr.next = tail;
            tail = curr; // now curr became head of the reversed list.
        }
        head = tail;
        curr = head;

        while(curr.next != null){
            curr = curr.next;
        }
        ptr = curr;
    }


    /**
     * returns last element of the list
     * @return
     */
    public type getEnd(){
        if(head == null) return null;
        return ptr.data;
    }


    /**
     * returns first element of the list
     * @return
     */
    public type getFirst(){
        if(head == null) return null;
        return head.data;
    }


    /**
     * removes the first element
     * @return returns the deleted value
     */
    public type removeFirst(){
        if(head == null) return null;
        type data = head.data;
        head = head.next;
        System.gc();
        return data;
    }


    /**
     * removes the last element of the list
     * @return
     */
    public type removeLast(){
        if(head == null) return null;
        else if(head.next == null) {
            type data = head.data;
            head = null;
            ptr = null;
            return data;
        }else{
            node temp = head;

            while(temp.next.next != null){
                temp = temp.next;
            }
            type data = temp.next.data;
            temp.next = null;
            ptr = temp;
            return data;

        }
    }
}
