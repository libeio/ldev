
WWW 定义了3个重要的概念，它们分别是访问信息的手段与位置(URI, Uniform Resource Identifier)、信息的表现形式(HTML, HyperText Markup Language)以及信息转发(HTTP, HyperText Transfer Protocol)等操作。

通过 JavaScript 可以在浏览器端和服务端执行特定的程序以实现更加精彩、多样的内容。


### URI

URI (统一资源标识符)是一种可以用于 WWW 之外的高效识别码，它被用于主页地址、电子邮件、电话号码等各种组合中。

与 URI 相比，更常用的是 URL(Uniform Resource Locator)，它表示使用 Web 浏览器等访问 Web 页面时需要输入的网页地址。

表示指定的 URI，要使用涵盖全部必要信息的绝对 URI、绝对 URL 以及相对 URL。相对 URL 是指从浏览器中基本 URI 处指定的 URL，比如 `/image/logo.gif` 。

以绝对 URI 为例来看一下其格式，如下:
```shell
    http://user:pass@www.example.com:80/dir/index/html?uid=1#ch1
```
* `http://`: 使用 http: 或 https: 等协议方案名获取访问资源时要指定协议类型。
* `user:pass`: 登录信息(认证)。指定用户名和密码作为从服务器端获取资源时必要的登录信息(身份认证)。此项是可选项。
* `www.example.com`: 服务器地址。使用绝对 URI 必须指定等访问的服务器地址。地址可以是 DNS 可解析的域名，也可以是 IP 形式的数字字符串。
* `80`: 服务器端口号: 指定服务器连接的网络端口号。此项为可选项，省略时使用协议缺省端口号。
* `dir/index/html`: 带层次的文件路径。指定服务器上的文件路径来定位特指的资源。
* `uid=1`: 查询字符串。针对已指定的文件路径内的资源，可以使用查询字符串传入任意参数。此项可选。
* `ch1`: 片段标识符。使用片段标识符通常可标记出已获取资源中的子资源(文档内的某个位置)。此项为可选项。

- 每个万维网页面都分配有一个唯一的标识符，即统一资源定位符(URL)。URL 的绝对形式包含完整的说
  明，而 URL 的相对形式则省略了服务器的地址。只有在已知服务器时，相对形式才有用。如下示例:
URL 示例，如下:
```shell
    http://hostname[:port]/path[;parameters][?query]
```
斜体字部分表示提供的项，方括号代表可选项。
* `hostname`: 指明作为服务器的计算机的域名或IP地址
* `:port`: 是可选的协议端口号
* `path`: 标识了服务器上某个具体文档的字符串
* `;parameters`: 指明由客户提供的可选参数
* `?query`: 是当浏览器发送询问时使用的可选字符串

用户未必能直接看到或使用其中的可选部分。事实上，用户输入的 URL 只包含 hostname 和 path。

URL 常被用来表示互联网中资源(文件)的具体位置。但是 URI 不局限于标识互联网资源，它可以作为所有资源的识别码。URI 可以用于除了 WWW 之外的其他应用协议中。


### HTML

HTML 是 WWW 的一种数据表现格式，可以在 Web 页中展现文件、图像、链接等内容。


### HTTP

当用户在浏览器的地址栏里输入所要访问 Web 页的 URI 以后，HITP 的处理即会开始。HTTP 默认使用 80 端口。它的工作机制，首先是客户端向服务器的 80 端口建立一个 TCP 连接，然后在这个 TCP 连接上进行请求和应答以及数据报文的发送。

HTTP 中常用的有两个版本，一个是 HTTP1.0，另一个是 HTTP1.1。两者的主要区别是在 1.0 版本中每一个请求和响应都会触发一次 TCP 连接的建立和断开，而从 1.1 开始，允许在一个 TCP 连接上进行多个请求和响应(keep-alive, 长连接)。由此，大大地减少了 TCP 连接的建立和断开操作，从而提高了传输效率。


### JavaScript

Javascript 是一种嵌入在 HTML 中的编程语言，作为客户端程序它可以运行于多种类型的浏览器中。这些浏览器将嵌入 JavaScript 的 HTML 加载后，其对应的 JavaScript 程序就可以在客户端得到执行。

JavaScript 程序可用于验证客户端输入字符串是否过长、是否填写或选择了页面中的必须选项等功能。还可以用于操作 HTML 或 XML 的逻辑结构(DOM, Document Object Model)以及动态显示 Web 页的内容和页面风格。

现在，通过 Ajax(Asynchronous JavaScript and XML)技术可以使服务端不需要读取整个页面而是通过 JavaScript 操作 DOM 来实现更为生动的 Web 页面技术。


### CGI

CCI(Common Gateway Interface)是 Web 服务器调用外部程序时所使用的一种服务端应用的规范。

一般的 Web 通信中．只是按照客户端请求将保存在 Web 服务器硬盘中的数据进行转发，这种情况下客户端每次收获的信息是同样(静态)的内容。而引入 CGI 以后客户端端请求会触发 Web 服务器端运行另一个程序，客户端所输人的数据也会传给这个外部程序。该程序运行结束后会将生成的 HTML 和其他数据再返回给客户端。

利用 CGI 可以针对用户的操作给客户端返回各种各样变化(动态)的信息。论坛和网上购物系统中就经常使用 CCI 调用外部程序或访问数据库。


### Cookie

Web 应用中为了获取用户信息使用一个叫做 Cookie 的机制。Web服务器用 Cookie 在客户端保存信息(多为"用户名"和"登录名"等信息)。Cookie 也常被用于保存登录信息或网络购物中放入购物车的商品信息。

从 Web 服务器检查 Cookie 可以确认是否为同一对端的通信。
