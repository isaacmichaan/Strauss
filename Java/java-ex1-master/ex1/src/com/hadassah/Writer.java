package com.hadassah;

import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
import java.util.Map;

/**
 * Writer class is responsible to handle the write file
 */
public class Writer {

    /**
     *
     * @param s is the args[1]/write file
     * @return the pointer to write into the file
     */
    public static FileWriter writerFile(String s) {
        FileWriter myWriter = null;
        try {
            myWriter = new FileWriter(s);
        } catch (IOException e) {
            System.out.println("[-] Write File - Something went wrong.");
            System.exit(0);
        }
        return myWriter;
    }

    /**
     *
     * @param myWriter is the pointer to write into the file
     * @param map holds a dictionary of key: URL and value: Bytes
     */
    public static void writeToFile(FileWriter myWriter, Map<Integer, List<String>> map) {
        for (Map.Entry<Integer, List<String>> entry : map.entrySet()) {
            try {
                for (String url : entry.getValue())
                    myWriter.write( url + " " + entry.getKey() + "\n");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}
