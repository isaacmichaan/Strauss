package com.hadassah;

import java.io.*;
import java.util.*;

//MultiMap
public class Run {

    /**
     *
     * @param args receives two files (Read, Write).
     *             The Read file contains URL.
     *             The Write will contain the sorted URL with Bytes
     */
    public static void main(String[] args) {

        // If user insert less than two files
        if (args.length < 2) {
            System.out.println("[-] Bad Usage");
            System.exit(0);
        }

        // Read file (args[0])
        Scanner myReader = Reader.readerFile(args[0]);

        // Create Map (Url, Bytes) for sorting
        Map<Integer, List<String>> multimap = Reader.urlValidation(myReader);

        // Close read file
        myReader.close();

        // Write file (args[1])
        FileWriter myWriter = Writer.writerFile(args[1]);

        // Write to file
        Writer.writeToFile(myWriter, multimap);

        // Close write file
        try {
            myWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
