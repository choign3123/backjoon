import java.util.Scanner;
import java.util.Stack;

public class Stack10828 {

    public static void main(String[] args){

        int n, arg;
        String comd;
        Stack<Integer> st = new Stack<>();

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        for(int i=0; i<n; i++){
            comd = sc.nextLine();

            if(comd.contains("push")){
                String[] strs = comd.split(" ");
                st.push(Integer.parseInt(strs[1]));
            }
            else if(comd.equals("pop")){
                if(st.empty()){
                    System.out.println("-1");
                }
                else{
                    int temp;
                    temp = st.pop();
                    System.out.println(temp);
                }
            }
            else if(comd.equals("size")){
                System.out.println(st.size());
            }
            else if(comd.equals("empty")){
                System.out.println(st.empty() ? "1" : "0");
            }
            else if(comd.equals("top")){
                if(st.empty()){
                    System.out.println("-1");
                }
                else {
                    System.out.println(st.peek());
                }
            }
        }

    }
}
