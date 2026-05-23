package com.example;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

public class AuthServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private File usersFile;
    private List<User> users = Collections.synchronizedList(new ArrayList<>());
    private Gson gson = new Gson();

    @Override
    public void init() throws ServletException {
        super.init();
        String path = getServletContext().getRealPath("/WEB-INF/users.json");
        usersFile = new File(path);
        if (!usersFile.exists()) {
            try {
                usersFile.getParentFile().mkdirs();
                usersFile.createNewFile();
                // create empty array
                try (Writer w = new OutputStreamWriter(new FileOutputStream(usersFile), StandardCharsets.UTF_8)) {
                    w.write("[]");
                }
            } catch (IOException e) {
                throw new ServletException(e);
            }
        }
        loadUsersFromFile();
        ensureAdmin();
    }

    private void loadUsersFromFile() {
        try (Reader r = new InputStreamReader(new FileInputStream(usersFile), StandardCharsets.UTF_8)) {
            users = gson.fromJson(r, new TypeToken<List<User>>(){}.getType());
            if (users == null) users = Collections.synchronizedList(new ArrayList<>());
        } catch (Exception e) {
            users = Collections.synchronizedList(new ArrayList<>());
        }
    }

    private void saveUsersToFile() {
        try (Writer w = new OutputStreamWriter(new FileOutputStream(usersFile), StandardCharsets.UTF_8)) {
            w.write(gson.toJson(users));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void ensureAdmin() {
        boolean found = false;
        for (User u : users) {
            if ("admin".equals(u.name)) { found = true; break; }
        }
        if (!found) {
            users.add(new User("admin", "0817", "admin", new Date().toString()));
            saveUsersToFile();
        }
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String action = req.getParameter("action");
        resp.setContentType("application/json;charset=UTF-8");
        Map<String, Object> result = new HashMap<>();
        if ("status".equals(action)) {
            HttpSession session = req.getSession(false);
            if (session != null && session.getAttribute("user") != null) {
                User u = (User) session.getAttribute("user");
                result.put("ok", true);
                result.put("user", u);
            } else {
                result.put("ok", true);
                result.put("user", null);
            }
            resp.getWriter().write(gson.toJson(result));
            return;
        }
        resp.getWriter().write(gson.toJson(Collections.singletonMap("ok", false)));
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("UTF-8");
        String action = req.getParameter("action");
        resp.setContentType("application/json;charset=UTF-8");
        Map<String, Object> result = new HashMap<>();

        if ("login".equals(action)) {
            String name = req.getParameter("name");
            String pwd = req.getParameter("pwd");
            User found = null;
            for (User u : users) {
                if (u.name.equals(name)) { found = u; break; }
            }
            if (found == null) {
                result.put("ok", false);
                result.put("msg", "用户不存在");
            } else if (!found.pwd.equals(pwd)) {
                result.put("ok", false);
                result.put("msg", "密码错误");
            } else {
                HttpSession session = req.getSession(true);
                session.setAttribute("user", found);
                result.put("ok", true);
                result.put("user", found);
            }
            resp.getWriter().write(gson.toJson(result));
            return;
        }

        if ("register".equals(action)) {
            String name = req.getParameter("name");
            String pwd = req.getParameter("pwd");
            if (name == null || name.isEmpty() || pwd == null || pwd.length() < 4) {
                result.put("ok", false);
                result.put("msg", "用户名不能为空且密码至少4位");
                resp.getWriter().write(gson.toJson(result));
                return;
            }
            for (User u : users) {
                if (u.name.equals(name)) {
                    result.put("ok", false);
                    result.put("msg", "用户名已存在");
                    resp.getWriter().write(gson.toJson(result));
                    return;
                }
            }
            if ("admin".equalsIgnoreCase(name)) {
                result.put("ok", false);
                result.put("msg", "不能注册 admin 用户名");
                resp.getWriter().write(gson.toJson(result));
                return;
            }
            User nu = new User(name, pwd, "user", new Date().toString());
            users.add(nu);
            saveUsersToFile();
            HttpSession session = req.getSession(true);
            session.setAttribute("user", nu);
            result.put("ok", true);
            result.put("user", nu);
            resp.getWriter().write(gson.toJson(result));
            return;
        }

        if ("logout".equals(action)) {
            HttpSession session = req.getSession(false);
            if (session != null) session.invalidate();
            result.put("ok", true);
            resp.getWriter().write(gson.toJson(result));
            return;
        }

        resp.getWriter().write(gson.toJson(Collections.singletonMap("ok", false)));
    }

    static class User implements Serializable {
        private static final long serialVersionUID = 1L;
        public String name;
        public String pwd;
        public String role;
        public String created;
        public User() {}
        public User(String name, String pwd, String role, String created) {
            this.name = name; this.pwd = pwd; this.role = role; this.created = created;
        }
    }
}
