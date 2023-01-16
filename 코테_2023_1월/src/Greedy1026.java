import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Greedy1026 {

    public static void main(String[] args){

        int n; // 개수
        int min = 0; // 최소값
        int a[];
        Integer b[]; // 내림차순으로 정렬하려고 Integer로 선언함.

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        a = new int[n];
        b = new Integer[n];

        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        for(int i=0; i<n; i++){
            b[i] = sc.nextInt();
        }
        // 입력값 처리 완료

        Arrays.sort(a); //오름차순 정렬
        Arrays.sort(b, Collections.reverseOrder()); //내림차순 정렬

        // 가장 큰 값과 가장 작은 값을 곱해주면 됨.
        for(int i=0; i<n; i++){
            min += a[i] * b[i];
        }

        System.out.println(min);
    }
}
