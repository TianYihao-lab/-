部署说明 - 将当前项目作为 JSP Web 应用部署到 Tomcat

目录结构（已创建基本骨架）：

jsp_app/
  WEB-INF/
    web.xml
    users.json   (由Servlet首次运行自动创建)
  src/
    com/example/AuthServlet.java
  README.md

说明与目标
- 我已实现 `AuthServlet`，提供如下 HTTP 接口：
  - POST /auth?action=login  (参数: name, pwd) -> 登录，成功在 session 中写入 user
  - POST /auth?action=register (参数: name, pwd) -> 注册并自动登录
  - POST /auth?action=logout -> 注销
  - GET  /auth?action=status -> 返回当前 session 中 user（或 null）
- Servlet 将用户列表保存在 web 应用的 `WEB-INF/users.json` 中（明文密码 —— 仅演示用，生产请使用哈希与后端数据库）。

前端集成建议
- 将你现有的前端文件（例如 `前端/皮影商店管理系统.html`）复制到 `jsp_app/index.jsp`，或把它改名为 `index.jsp` 并放入 `jsp_app/` 下。这样 Tomcat 启动时会以 `index.jsp` 作为欢迎页。
- 需要修改前端的注册/登录/登出相关 JS，改为调用上面的 `/auth` 接口（通过相对路径 `/yourAppName/auth`）。示例已经在 README 下方给出几个 fetch 请求示例。

依赖
- 需要 gson 用于 JSON 处理：下载 `gson-2.8.9.jar`（或较新）。把 jar 放入 `jsp_app/WEB-INF/lib/` 下（如果不存在就创建）。

在 Windows（PowerShell）下手动构建并部署到本地 Tomcat（示例）

1) 安装 Tomcat（已假设安装在 `C:\apache-tomcat-9.0.XX`）
2) 把 `gson-*.jar` 放入 `jsp_app/WEB-INF/lib/`
3) 编译 Servlet

# 进入 src 根目录
cd "d:\Files\codingFiles\VScodeFiles\jsp_app\src"

# 创建 classes 输出目录
mkdir ..\classes

# 编译（请根据 gson jar 名称调整 classpath）
javac -cp ".;..\WEB-INF\lib\gson-2.8.9.jar" -d ..\classes com\example\AuthServlet.java

4) 打包 WAR（或者直接把文件夹复制到 Tomcat webapps）

# 在 jsp_app 目录下运行
cd "d:\Files\codingFiles\VScodeFiles\jsp_app"

# 创建 WEB-INF/classes 目录并复制编译产物
mkdir -Force WEB-INF\classes
xcopy /E /I "src\\com" "WEB-INF\\classes\\com\\example"

# 把 gson jar 复制到 WEB-INF/lib（如果还没放）
# 手动复制：将 gson-2.8.9.jar 放入 WEB-INF\lib

# 创建 war（可选）
jar -cvf shadowshop.war *

5) 部署到 Tomcat

# 方法 A: 直接复制文件夹到 Tomcat webapps
Copy-Item -Recurse . "C:\apache-tomcat-9.0.xx\webapps\shadowshop"

# 方法 B: 将 war 拷贝到 webapps
Copy-Item .\shadowshop.war "C:\apache-tomcat-9.0.xx\webapps\"

6) 启动 Tomcat（如果尚未启动）
& "C:\apache-tomcat-9.0.xx\bin\startup.bat"

7) 访问
浏览器打开: http://localhost:8080/shadowshop/

示例：前端调用登录接口（fetch）

fetch('/shadowshop/auth?action=login', {
  method: 'POST',
  headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
  body: new URLSearchParams({ name: 'test', pwd: '1234' })
}).then(r => r.json()).then(console.log);

示例：查询登录状态
fetch('/shadowshop/auth?action=status').then(r => r.json()).then(console.log);

安全提醒
- 当前实现将用户和密码以明文形式写入 `WEB-INF/users.json`，仅用于演示。
- 生产环境请使用 HTTPS、后端数据库、服务器端密码哈希（bcrypt 等）与 CSRF 防护。

我已经创建了 Servlet 源代码和 `web.xml`。下一步我可以：
- 1) 把当前前端全部转换成 `index.jsp` 并替换原有本地存储逻辑为调用 `/auth` 接口（自动完成）；
- 2) 或者仅提供示例前端改动片段，指导你如何集成现有前端到该 JSP 应用中。

请选择你要我继续做哪一项（1 或 2），或告诉我 Tomcat 的安装路径，我可以给出更精确的一键部署命令。