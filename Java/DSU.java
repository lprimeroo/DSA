import java.util.*;


public class DSU{
    int []size,parent;
    int n;
    
    void makeset(){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    void find_set(int v){
        if(v == parent[v]){
            return v;
        }
        return v = find_set(parent[v]);
    }

    void union_set(int x,int y){
        if(find_set(x) = find_set(y)){
            return;
        }
        if(size[x] < size[y]){
            parent[x] = y;
            size[y] += size[x];   
        }
        else{
            parent[y] = x;
            size[x] += size[y];
        }
    }

    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        n = 6;
        size = new int[n];
        parent = new int[n];
        makeset();
        union_set(1,2);
        for(int i = 0; i < n; i++)
            System.out.print(find_set(i) + " ");
    }
}