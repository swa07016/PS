import java.util.*;

public class Main
{
    
    public static long solve(long n) {
        long r = 1%n, r_sum = r;
        if(r_sum%n == 0) return 1;
        /*
         (A+B)%C = (A%C + B%C)%C
         (A*B)%C = (A%C * B%C)%C 
         위 나머지 연산자의 성질을 이용하여
         나머지의 합을 구한 후 주어진 n의 배수인지 판별
        */
        for(int i=2; ; i++) {
            r = (r*(10%n))%n;
            r_sum += r;
            if(r_sum%n == 0) return i;
        }
    }
    
	public static void main(String[] args) {
        long n;
        Scanner sc = new Scanner(System.in);

        while(sc.hasNextInt()) {
            n = sc.nextInt();
            System.out.printf("%d\n", solve(n));
        }
	}
}