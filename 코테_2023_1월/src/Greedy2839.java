import java.util.Scanner;

public class Greedy2839 {

    public static void main(String[] args){
        int sugar = 0;
        int count = 0;

        Scanner sc = new Scanner(System.in);
        sugar = sc.nextInt();

        /*
        while(sugar >= 3){ // 뺄 수 있는동안
            if((sugar-5)%5 == 0 || (sugar-5)%3 == 0){ // 5를 뺐을 때 그 다음에도 5나 3을 뺄 수 있는 상황이면
                sugar -= 5;
                count++;
            }
            else{
                sugar -= 3;
                count++;
            }
        }
        */

        while(sugar%5 != 0){ // 5를 못빼는 상황이면 어차면 3을 빼야하기에
            sugar -= 3;
            count++;
        }

        if(sugar > 0 && sugar%5 == 0){ // 뺄게 있고, 5로 나눠지면 다 5로 빼면 됨.
            count += (sugar/5);
            sugar %= 5;
        }

        if(sugar != 0){
            System.out.println("-1");
            return;
        }

        System.out.println(count);
    }
}
