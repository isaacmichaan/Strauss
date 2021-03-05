package com.hadassah;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.util.*;

/**
 * Reader class is responsible to handle the read file
 */
public class Reader {

    /**
     *
     * @param s is the args[0]/read file
     * @return the Scanner which contains the read the file
     */
    public static Scanner readerFile(String s) {
        File myObj = new File(s);
        Scanner myReader = null;
        try {
            myReader = new Scanner(myObj);
        } catch (
                FileNotFoundException e) {
            System.out.println("[-] Read File - Not Found");
            System.exit(0);
        }
        return myReader;
    }

    /**
     *
     * @param myReader is the Scanner which contains the read file
     * @return a Map containing a dictionary (Key: URL, Value: Bytes)
     */
    public static Map<Integer, List<String>> urlValidation(Scanner myReader) {
        Map<Integer, List<String>> multimap = new TreeMap<Integer, List<String>>();
        while (Objects.requireNonNull(myReader).hasNextLine()) {
            try {
                String data = myReader.nextLine();
                if (data.equals(""))
                    continue;
                URL url = null;
                url = new URL(data);
                InputStream in = null;
                in = Objects.requireNonNull(url).openStream();
                byte[] bytes = in.readAllBytes();
                String str = new String(bytes, StandardCharsets.UTF_8);
                List<String> size = multimap.computeIfAbsent(str.length(), k -> new ArrayList<String>());
                size.add(data);
            } catch (IllegalArgumentException | IOException e) {
                System.out.println("[-] Bad Input " + e.getMessage());
            }
        }
        return multimap;
    }

}
