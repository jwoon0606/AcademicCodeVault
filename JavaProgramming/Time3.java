import java.util.Scanner;

public class Time3 {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        int hrs;
        int min;
        int target_j = 60;
        int count = 0;

        hrs = s.nextInt();
        min = s.nextInt();

        for (int i = 0; i <= hrs; i++) {
            if (i == hrs) target_j = min;
            for (int j = 0; j <= target_j; j++) {
                if (i / 10 == 3 || i % 10 == 3 || j / 10 == 3 || j % 10 == 3) count++;
            }
        }

        System.out.println(count);

        s.close();
    }
}
