package hw02_OOP.hw08.step2;

import java.io.File;
import java.io.IOException;
import java.util.Arrays;

public class Task {
    public static void dcFile() throws IOException {
        /********* Begin *********/
        File outputDir2 = new File("./src/test2/");
        if(!outputDir2.exists()) {
            outputDir2.mkdir();
        }

        File todelete = new File("./src/output/test2.txt");
        todelete.delete();

        new File("./src/test2/helloworld.txt").createNewFile();
        new File("./src/test2/step2.txt").createNewFile();

        File outputDir = new File("./src/output/");
        File[] outputDirFiles = outputDir.listFiles();
        Arrays.sort(outputDirFiles);
        System.out.println("output目录结构为：");
        for(File f : outputDirFiles) {
            System.out.println(f.getName());
        }

        File[] outputDirFiles2 = outputDir2.listFiles();
        Arrays.sort(outputDirFiles2);
        System.out.println("test2目录结构为：");
        for(File f : outputDirFiles2) {
            System.out.println(f.getName());
        }

        /********* End *********/
    }
}
