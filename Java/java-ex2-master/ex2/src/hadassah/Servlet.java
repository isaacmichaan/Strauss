package hadassah;

import javax.servlet.*;
import javax.servlet.annotation.WebInitParam;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.*;
import java.util.*;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

@WebServlet(name = "Servlet",
        urlPatterns = "/welcome",
        initParams = { @WebInitParam(name = "filename", value = "/WEB-INF/votesystem.txt") })
public class Servlet extends HttpServlet {
    /**
     * This is the init function to start the file only once
     * @throws ServletException
     */
    @Override
    public void init() throws ServletException {
        ServletContext context = getServletContext();

        BufferedReader br = null;
        String question = null;
        try {
            InputStream is = context.getResourceAsStream(getInitParameter("filename"));
            br = new BufferedReader(new InputStreamReader(is));
            question = br.readLine();
        } catch (NullPointerException | IOException e) {
            e.printStackTrace();
            System.exit(0);
        }

        Map<String, Integer> multimap = new TreeMap<String, Integer>();
        String line = null;

        while (true) {
            try {
                if (!((line = br.readLine())!= null && line.trim().length()>0)) break;
            } catch (IOException e) {
                e.printStackTrace();
                System.exit(0);
            }
            multimap.put(line, 0);
        }
        context.setAttribute("question", question);
        context.setAttribute("multimap", multimap);
    }

    /**
     * This is the doPost function where the main functionality happens, adding votes
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");

        PrintWriter toClient = response.getWriter();
        ServletContext context = getServletContext();
        Map<String, Integer> multimap = (Map<String, Integer>) context.getAttribute("multimap");

        // if we have only 2 lines in file -- exit()
        if (multimap.size() < 2) {
            toClient.println("<html>\n"
                    + "<head><title>" + "title" + "</title></head>\n"
                    + "<body bgcolor=\"#fdf5e6\">\n"
                    + "<h1 align=\"center\">" + "Survey not available now, please visit later\n" + "</h1>\n");
            toClient.close();
            System.exit(0);
        }

        Cookie[] cookies = request.getCookies();
        String opt = request.getParameter("opt");

        // if we did not vote yet
        if(opt!=null  && cookies==null) {
            // Thread
            Thread t = new Thread(() -> multimap.put(opt, multimap.get(opt) + 1));

            // And Execute
            ExecutorService executor = Executors.newSingleThreadExecutor();
            executor.execute(t);
            executor.shutdown();
            try {
                executor.awaitTermination(24L, TimeUnit.HOURS);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            // Create cookies
            Cookie cookie = new Cookie("isaac", "michaan");
            response.addCookie(cookie);
        }

        toClient.println("<html>\n" +
                "<head>\n" +
                "<title>Vote For</title>\n" +
                "</head>\n" +
                "<body bgcolor=\\\"#fdf5e6\\>\n" +
                "</body>" +
                "<h1 align=\"center\"> Voting System </h1>\n");

        // if we did vote
        if(opt!=null  && cookies!=null) {
            toClient.println("<h3 style=\"color:blue\" align=\"center\">Sorry you already voted! (Tip: Clean Your Cookies)</h3>");
        }

        toClient.println("<form method=\"get\" action=\"welcome\">\n" +
                "<table border=1 align=\"center\">\n" +
                "<tr bgcolor=\"#ffad00\">\n" +
                "<th>Available Options\n" +
                "<th>Number of Votes\n" +
                "<tr> <h2 align=\"center\">" +
                (String) context.getAttribute("question") +
                "</h2>\n");

        for (Map.Entry<String, Integer> entry : multimap.entrySet()) {
                toClient.println("<tr>\n" +
                        "<td> <input type=radio name=opt value=\"" + entry.getKey() + "\">" + entry.getKey() + "<br/>\n" +
                        "<td>" + entry.getValue());
        }

        toClient.println("</table>\n" +
                "</br>\n" +
                "<div align=\"center\">\n" +
                "<input type=\"submit\" value=\"Vote\">\n" +
                "</div>\n" +
                "</form>" +
                "</body>\n" +
                "</html>\n");
        toClient.close();
    }

    /**
     * This is the doGet function, just redirect to doPost
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}