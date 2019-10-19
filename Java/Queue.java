import java.util.ArrayList;

public class Queue <T>{
    private ArrayList <T> queue;
    Queue() {
        queue = new ArrayList<T>();
    }

    public void enqueue(T element){
        queue.add(element); 
    }
    
    public boolean isEmpty(){
        return (queue.size() < 1);
    }

    public T dequeue() throws EmptyQueueException{
        if(isEmpty()){
            throw new EmptyQueueException("Dequeue");
        }
        else{
            T element = queue.get(0);
            queue.remove(0);
            return element;
        }
    }

}

class EmptyQueueException extends Exception{
    
    public EmptyQueueException(String action){
        super("Queue is empty. Underflow.Cannot perform action " + action);
    }
}
