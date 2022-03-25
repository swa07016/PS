import java.util.*;

public class Main
{
    /*
        1) [1, N]구간의 자연수들의 약수들을 각각 나열해보자
            1 : 1
            2 : 1 2
            3 : 1 3
            4 : 1 2 4
            5 : 1 5
            6 : 1 2 3 6
        2) 임의의 약수 i가 [1, N]구간에서 N/i번 등장함
        3) (등장 횟수)*i 들의 합을 구해주기
    */
    public static long g(long N) {
        long sum = 0;
        for(long i=1; i<=N; i++) sum += (N/i)*i;
        return sum;
    }
    
	public static void main(String[] args) {
        long N;
        Scanner sc = new Scanner(System.in);
    
        N = sc.nextInt();
        System.out.printf("%d\n", g(N));
      
	}
}
