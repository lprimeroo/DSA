import java.util.Scanner;

public class Fmm{
    
    private long binaryExponentiation(long base, long power, long modulo){
        long result = 1;
        while(power > 0){
            if(power & 1){
                result = (result * base) % modulo;
            }
            base = (base * base) % modulo;
            power = power / 2;
        }
        return result;
    }

    public static void main(String []args){
        long base,power,modulo;
        Scanner sc = new Scanner(System.in);
        base = sc.nextInt();
        power = sc.nextInt();
        modulo = sc.nextInt();
        System.out.println(binaryExponentiation(base,power,modulo));
    }
}