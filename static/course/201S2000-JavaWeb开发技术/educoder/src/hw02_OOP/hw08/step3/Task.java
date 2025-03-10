package hw02_OOP.hw08.step3;

import java.io.File;

public class Task {

    /********** Begin **********/
    public void showDirStructure(File file) {
        showDirStructure(file, 0);
    }

    void showDirStructure(File file, int x){
        for (int i = 0; i < x; i++) {
            System.out.print("  ");
        }
        System.out.println("+--"+file.getName());

        File[] files = file.listFiles();
        for(File f : files){
            if(f.isDirectory()){
                showDirStructure(f, x+1);
            } else {
                for (int i = 0; i < x+1; i++) {
                    System.out.print("  ");
                }
                System.out.println("--"+f.getName());
            }
        }
    }
    /********** End **********/
}
