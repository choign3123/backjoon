import java.util.*;

public class Greedy1541 {

    public static void main(String[] args){
        int result = 0;
        String str;

        Scanner sc = new Scanner(System.in);
        str = sc.next();

        String n = "";
        Queue<Integer> arrN = new LinkedList<>();
        Queue<Character> arrOp = new LinkedList<>();
        for(int i=0; i<str.length(); i++){
            if(Character.isDigit(str.charAt(i))){
                n += str.charAt(i);
            }
            else{
                arrOp.add(str.charAt(i));
                arrN.add(Integer.parseInt(n));
                n = "";
            }
        }
        arrN.add(Integer.parseInt(n));

//        for(char c : arrOp){
//            System.out.println(c);
//        }
//        for(int t : arrN){
//            System.out.println(t);
//        }

        int first = 0;
        while(!arrOp.isEmpty()){
            char op = arrOp.poll();
            if(op == '+'){
                first += arrN.poll() + arrN.poll();
            }
            else if(op == '-'){

            }
        }
    }
}
