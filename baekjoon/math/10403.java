import java.util.*;

public class Main
{
	public static void main(String[] args) {
        int A, B, C;
        Scanner sc = new Scanner(System.in);
        A = sc.nextInt(); B = sc.nextInt(); C = sc.nextInt();
        
        System.out.printf("%d\n%d\n%d\n%d", 
         (A+B)%C, ((A%C) + (B%C))%C, 
         (A*B)%C, ((A%C) * (B%C))%C
        );

	}
}
