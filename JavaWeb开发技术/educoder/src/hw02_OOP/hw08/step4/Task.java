package hw02_OOP.hw08.step4;

import java.io.File;
import java.io.FileFilter;

public class Task {

    FileFilter imageFilter = file -> {
        if(file.isFile()){
            String filename = file.getName().toLowerCase();
            if(filename.endsWith(".png") ||
                    filename.endsWith(".jpg") ||
                    filename.endsWith(".jpeg") ||
                    filename.endsWith(".gif") ||
                    filename.endsWith(".bmp")
                    ){
                return true;
            }
        } else if(file.isDirectory()){
            return true;
        }
        return false;
    };

    public void showDirStructure(File file) {
        showDirStructure(file, 0);
    }

    void showDirStructure(File file, int x){
        for (int i = 0; i < x; i++) {
            System.out.print("  ");
        }
        System.out.println("+--"+file.getName());

        File[] files = file.listFiles(imageFilter);
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
}
