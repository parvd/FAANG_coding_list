import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class PascalTriangle {

    static List<List<Integer>> generatePascalNumber(int rows) {
        List<List<Integer>> triangle = new ArrayList<>();
        if(rows == 0) return triangle;
        generate(triangle, rows);
        return triangle;
    }

    static void generate(List<List<Integer>> list, int rows) {
        if(rows == 1) {
            list.add(Arrays.asList(1));
        } else {
            generate(list, rows - 1);
            List<Integer> previousList = list.get(rows-2);
            List<Integer> currentList = new ArrayList<>();

            for(int i = 0; i < previousList.size(); i++) {
                if(i == 0) currentList.add(1);
                if(i > 0) currentList.add(previousList.get(i) + previousList.get(i-1));
                if(i == previousList.size()-1) currentList.add(1);
            }
            list.add(currentList);

        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numRows;

        numRows = sc.nextInt();

        List<List<Integer>> result = new ArrayList<>();

        result = generatePascalNumber(numRows);

//        for(int i = 0; i < result.size(); i++) {
//            for(int j = 0; j < result.get(i).size(); j++) {
//                System.out.print(result.get(i).get(j)+" ");
//            }
//            System.out.println();
//        }
        System.out.println(result);
    }
}
