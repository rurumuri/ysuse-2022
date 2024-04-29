package hw02_OOP.hw08.step1;

import java.io.File;
import java.io.IOException;

public class Task {
    /********* Begin *********/
    public void solution() throws IOException {
        File file = new File("./src/output/test.txt");
        file.createNewFile();
        File file2 = new File("./src/output/hello.txt");
        file2.createNewFile();

        /********* End *********/
    }
}
