import java.util.Scanner;

public class Greedy2839 {

    public static void main(String[] args){
        int sugar = 0;
        int count = 0;

        Scanner sc = new Scanner(System.in);
        sugar = sc.nextInt();

        while(sugar >= 3){
            if((sugar-5)%5 == 0 || (sugar-5)%3 == 0){
                sugar -= 5;
                count++;
            }
            else{
                sugar -= 3;
                count++;
            }
        }

        if(sugar != 0){
            System.out.println("-1");
            return;
        }

        System.out.println(count);
    }
}
